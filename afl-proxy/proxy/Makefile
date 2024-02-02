CC=gcc
CXX=g++
LINK=g++

CFLAGS=-g -I../
CXXFLAGS=-g -std=c++14 -I../
LDFLAGS= -lpthread -std=c++14
TARGET_EXEC=ap

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
  LDFLAGS += -lrt
endif
ifeq ($(UNAME_S),Darwin)
  LDFLAGS += 
endif

JUNK=dry_run_stamp*

-include ../Makefile.defaults

