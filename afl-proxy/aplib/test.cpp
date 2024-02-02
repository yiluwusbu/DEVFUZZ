#include "aplib.h"
#include "logutil.h"

char dest[4];

int main() {
  outs() << "starting test loop, press ^C to exit";
  ap_init();
  ap_attach_pt();
  while (1) {
    ap_get_fuzz_data(dest, 0, 4);
  }
  return 0;
}
