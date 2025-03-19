#include "../get_options/index.h"
#include <string.h>

#ifndef GET_FLAGS_H
#define GET_FLAGS_H

typedef struct {
  int w;
  int c;
  int l;
  int t;
  int s;
} Flags;

// Function to check if a flag exists
Flags has_flags(Options *options);

// Function to check if a flag is set
int no_flags(Flags flags);

#endif // !GET_FLAGS_H
