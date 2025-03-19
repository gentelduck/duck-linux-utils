#include "../get_flags/index.h"
#include "../get_options/index.h"

#ifndef GET_COUNT_H
#define GET_COUNT_H

typedef struct {
  int char_count;
  int word_count;
  int line_count;
  int tab_count;
} Counts;

void get_counts_file(Options *options, Flags *flags, int in_word, char ch,
                     Counts *counts);

void get_count_pipe(Flags *flags, int in_word, char ch, Counts *counts);
Counts get_counts(Options *options, Flags *flags);
void count(Counts *counts, char ch, Flags *flags, int in_word);
#endif // GET_COUNT_H
