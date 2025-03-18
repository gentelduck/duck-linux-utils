#include "../get_options/index.h"

#ifndef GET_COUNT_H
#define GET_COUNT_H

typedef struct {
  int char_count;
  int word_count;
  int line_count;
  int tab_count;
} Counts;

Counts get_counts(Options *options);

#endif // GET_COUNT_H
