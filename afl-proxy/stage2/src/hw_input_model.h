/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
#ifndef __HW_INPUT_MODEL_H
#define __HW_INPUT_MODEL_H
#include <stdint.h>
#include <set>
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cassert>
#define DICT_MODE 1
#define RANDOM_MODE 0

std::string to_hex(uint64_t val) {
    std::ostringstream ss;
    ss << "0x" << std::hex << val;
    return ss.str();
}

class HWInput {
public:
  HWInput() {}
  HWInput(int off, int nbytes)
    :offset(off), n_bytes(nbytes) {
  }
  
  inline int nbytes() { return n_bytes; }
  bool empty() { return bits_set.empty() && value_set.empty() && ranges.empty(); }
  void setOffset(int off) { offset = off; }
  void setSize(int nbytes) { n_bytes = nbytes; }
  inline void insertRanges(int64_t start, int64_t end) { ranges.push_back({start, end}); }
  inline void insertValue(uint64_t val) { value_set.insert(val); }
  inline void insertBits(uint64_t bits) { bits_set.insert(bits); }

  void process() {
    generateRangeValues();
  }  

  void genSpecial(int64_t start, int64_t end, std::vector<int64_t> & res) {
    res.push_back(start+1); 
    res.push_back(start);
    res.push_back(start-1);
    res.push_back(end);
    res.push_back(end+1);
  }

  void generateRangeValues() {
    if (ranges.size()) {
      for (auto & p : ranges) {
        int64_t start = p.first;
        int64_t end = p.second;
        std::vector<int64_t> res;
        genSpecial(start, end, res);
        for (auto & v : res) {
          range_special_vals.insert((uint64_t)v);
        }
      }
    }
  }

  

  std::string genModelInitCode(int base_indent) {
    std::string res;
    std::string indent = "        ";
    std::string base = std::string(base_indent, ' ');
    indent += base;
    res = base + "HWInput(" + std::to_string(offset) + ", " + std::to_string(n_bytes) + ",\n" + indent;
    // bits
    res += "{";
    for (auto & v : bits_set) {
      res += to_hex(v) + ", ";
    }
    res += "},\n" + indent;
    // magic values
    res += "{";
    for (auto & v : value_set) {
      res += to_hex(v) + ", ";
    }
    res += "},\n" + indent;
    // special range values
    res += "{";
    for (auto & v : range_special_vals) {
      res += to_hex(v) + ", ";
    }
    res += "})\n";
    return res;
  }


private:
  std::vector<std::pair<int64_t, int64_t>> ranges;
  std::set<uint64_t> value_set;
  std::set<uint64_t> bits_set;
  // uint64_t important_bits;
  std::set<uint64_t> range_special_vals;
  int offset;
  int n_bytes;
};


static std::string op_symbols[] = {
  "&&", "||", "!",
  "<", "<=", ">", ">=", "==",
  "!=", "&", "|", "^",
  "+", "*", "/", "-", "<<", ">>",
};
class ValueExpr;

class Expression {
public:
  enum class ExpType {
    AND, OR, NOT,
    LT, LE, GT, GE, EQ,
    NE, BITAND, BITOR, BITXOR,
    ADD, MUL, DIV, SUB, LSHIFT, RSHIFT,
    VALUE,
  };
  
  Expression(ExpType t) :exp_type(t) {}

  virtual std::string str()=0;
  inline ExpType getType() { return exp_type; };
  inline bool isValue() { return exp_type == ExpType::VALUE; }
  virtual inline bool isConstant() { return false; }
protected:
  ExpType exp_type;
};

class ArithExpr: public Expression {
public:
  ArithExpr(ExpType t, Expression * l, Expression * r)
    : Expression(t), lhs(l), rhs(r) {}
  std::string str() { 
    std::string res;
    if (rhs) {
      res = lhs->str() + " " + op_symbols[(int)exp_type] + " " + rhs->str();
    } else {
      res = op_symbols[(int)exp_type] + lhs->str();
    }
    res = "(" + res + ")";
    return res;
  }
  void setRHS(Expression * expr) {
    rhs = expr;
  }
  void setLHS(Expression * expr) {
    lhs = expr;
  }
  virtual inline bool isConstant() {return false;}
  Expression * getRHS() { return rhs; }
  Expression * getLHS() { return lhs; }
private:
  Expression * lhs;
  Expression * rhs;
};

class ValueExpr: public Expression {
public:
  enum class ValueType {
    HW_INPUT,
    CONSTANT,
  };
  
  ValueExpr(const std::string & name, int off, int sz) 
    :Expression(ExpType::VALUE)  
  {
    base_type_name = name;
    off = offset;
    size = sz;
    vtype = ValueType::HW_INPUT;
  }
  ValueExpr(uint64_t v) 
    :Expression(ExpType::VALUE) 
  {
    value = v;
    vtype = ValueType::CONSTANT;
  }
  virtual bool isConstant() { return vtype == ValueType::CONSTANT; }
  inline bool isHWInput() { return vtype == ValueType::HW_INPUT; }
  std::string str() {
    if (isConstant()) {
      std::ostringstream ss;
      ss << "0x" << std::hex << value;
      return ss.str();
    } else {
      return "x";
    }
  }
  uint64_t getConstant() { return value; }

private:
  std::string base_type_name;
  int offset;
  int size;
  uint64_t value;
  ValueType vtype;
};

/// x > 0xff <-> x & 0x80
///
uint64_t checkAllOneValue(uint64_t v) {
  uint8_t *bytes = (uint8_t*)&v;
  int i=0;

  for (i=0; i<8; i++) {
    if (bytes[i] == 0x0) {
      break;
    }
    if (bytes[i] != 0xff) {
      break;
    }
  }
  if (i == 8) {
    // all ones
    return 1ULL << 63;
  }
  if (i == 0 || bytes[i] != 0) {
    return 0;
  }
  // std::cerr << "All one detected: " << to_hex(v) << "\n";
  int nshift = i * 8 - 1;
  return 1ULL << nshift;
}

uint64_t getConstantInExpr(Expression * expr) {
  auto exp_type = expr->getType();
  assert(exp_type != Expression::ExpType::VALUE);
  ArithExpr * arith = (ArithExpr*)expr;
  Expression * lhs = arith->getLHS();
  Expression * rhs = arith->getRHS();
  ValueExpr * constant = nullptr;
  assert(lhs->isConstant() || rhs->isConstant());
  if (lhs->isConstant()) {
    constant = (ValueExpr *)lhs;
  } else {
    constant = (ValueExpr *)rhs;
  }
  return constant->getConstant();
}

void genHWInputConstraint(Expression * expr, HWInput & hw_input) {
  auto exp_type = expr->getType();
  if(exp_type == Expression::ExpType::VALUE) {
    std::cerr << "constraint not valid\n";
    return;
  }
  ArithExpr * arith = (ArithExpr*)expr;
  Expression * lhs = arith->getLHS();
  Expression * rhs = arith->getRHS();
  ValueExpr * constant = nullptr;
  Expression * other_expr = nullptr;
  if (!lhs->isConstant() && !rhs->isConstant()) {
    std::cerr << "constraint not valid\n";
    return;
  }
  if (lhs->isConstant()) {
    constant = (ValueExpr *)lhs;
    other_expr = rhs;
  } else {
    constant = (ValueExpr *)rhs;
    other_expr = lhs;
  }
  uint64_t const_val = constant->getConstant();
  if (exp_type == Expression::ExpType::EQ 
      || exp_type == Expression::ExpType::NE) 
  {
    // x == MAGIC
    if (other_expr->isValue()) {
      hw_input.insertValue(const_val);
    } else if (other_expr->getType() == Expression::ExpType::BITAND){  // x & 0xVVVVV == V ?
      ArithExpr * band= (ArithExpr *)other_expr;
      auto * mask = (ValueExpr*)(band->getLHS()->isConstant() ? band->getLHS() : band->getRHS());
      auto * lhs_exp = band->getLHS()->isConstant() ? band->getRHS() : band->getLHS();
      auto lhs_exp_type = lhs_exp->getType();
      
      uint64_t mask_val = mask->getConstant();
      if (lhs_exp_type == Expression::ExpType::LSHIFT) {
        uint64_t shift_val = getConstantInExpr(lhs_exp);
        mask_val = mask_val  >> shift_val;
        const_val = const_val >> shift_val;
      } else if (lhs_exp_type == Expression::ExpType::RSHIFT) {
        uint64_t shift_val = getConstantInExpr(lhs_exp);
        mask_val = mask_val  << shift_val;
        const_val = const_val << shift_val;
      }
      if (const_val == 0) {
        hw_input.insertBits(mask_val);
      } else {
        hw_input.insertBits(const_val);
      }
    } else {
      // else what?
    }
  } else if (exp_type == Expression::ExpType::LE 
          || exp_type == Expression::ExpType::LT) {
    if (const_val == 0 && exp_type == Expression::ExpType::LT) {
      uint64_t highest_set = 0;
      int size = hw_input.nbytes();
      if (size == 1) {
        highest_set = 1ULL << 7;
      } else if (size == 2) {
        highest_set = 1ULL << 15;
      } else if (size == 4) {
        highest_set = 1ULL << 31;
      } else if (size == 8) {
        highest_set = 1ULL << 63;
      }
      hw_input.insertBits(highest_set);
    } else {
      hw_input.insertRanges(0, const_val);
    }
  } else if (exp_type == Expression::ExpType::GT
            || exp_type == Expression::ExpType::GE) {
    uint64_t one_bit_set = checkAllOneValue(const_val);
    if (one_bit_set) {
      hw_input.insertBits(one_bit_set);
      return;
    }
    uint64_t max_val = 0;
    int size = hw_input.nbytes();
    if (size == 1) {
      max_val = UINT8_MAX;
    } else if (size == 2) {
      max_val = UINT16_MAX;
    } else if (size == 4) {
      max_val = UINT32_MAX;
    } else if (size == 8) {
      max_val = UINT64_MAX;
    }
    hw_input.insertRanges(const_val, max_val);
  }
}

#endif // __HW_INPUT_MODEL_H