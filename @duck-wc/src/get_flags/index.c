#include "../get_options/index.h"
#include <string.h>

typedef struct {
  int w;
  int c;
  int l;
  int t;
  int s;
} Flags;

// Function to check if a flag exists
Flags has_flags(Options *options) {
  Flags flags = {0, 0, 0, 0, 0};

  for (int i = 0; i < options->flags_count; i++) {
    if (strchr(options->flags[i], 'w'))
      flags.w = 1;
    if (strchr(options->flags[i], 'c'))
      flags.c = 1;
    if (strchr(options->flags[i], 'l'))
      flags.l = 1;
    if (strchr(options->flags[i], 't'))
      flags.t = 1;
    if (strchr(options->flags[i], 's'))
      flags.s = 1;
  }

  return flags;
}

int no_flags(const Flags *const flags) {
  _Bool *ptr = (_Bool *)&flags; // Pointer to struct memory

  for (size_t i = 0; i < sizeof(Flags) / sizeof(_Bool); i++) {
    if (ptr[i]) { // If any flag is true
      return 0;   // Some flag is set
    }
  }

  return 1; // No flags are set
}
