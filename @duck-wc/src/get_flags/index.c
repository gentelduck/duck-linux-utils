#include "../get_options/index.h"
#include <string.h>

typedef struct {
  int w;
  int c;
  int l;
  int t;
  int s;
  int a;
  int b;
  int h;
} Flags;

// Function to check if a flag exists
Flags has_flags(Options *options) {
  Flags flags = {0, 0, 0, 0, 0, 0, 0, 0};

  // Check if a flag exists and set the corresponding flag.
  for (int i = 0; i < options->flags_count; i++) {
    if (strstr(options->flags[i], "-w") || strstr(options->flags[i], "--word"))
      flags.w = 1;
    if (strstr(options->flags[i], "-c") || strstr(options->flags[i], "--char"))
      flags.c = 1;
    if (strstr(options->flags[i], "-b") || strstr(options->flags[i], "--byte"))
      flags.b = 1;
    if (strstr(options->flags[i], "-l") || strstr(options->flags[i], "--line"))
      flags.l = 1;
    if (strstr(options->flags[i], "-t") || strstr(options->flags[i], "--tab"))
      flags.t = 1;
    if (strstr(options->flags[i], "-s") || strstr(options->flags[i], "--show"))
      flags.s = 1;
    if (strstr(options->flags[i], "-a") || strstr(options->flags[i], "--all"))
      flags.a = 1;
    if (strstr(options->flags[i], "-h") || strstr(options->flags[i], "--help"))
      flags.h = 1;
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
