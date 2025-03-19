#include "../get_options/index.h"
#include "../get_flags/index.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int char_count;
  int word_count;
  int line_count;
  int tab_count;
} Counts;

void print_count(Options *options, Counts *counts, Flags *flags) {

  for (int i = 0; i < options->flags_count; i++) {
    char *flag = options->flags[i];

    if (flags->w) {
      printf("%6d", counts->word_count);
    } else if (flags->c) {
      printf("%6d", counts->char_count);
    } else if (flags->l) {
      printf("%6d", counts->line_count);
    } else if (flags->t) {
      printf("%6d", counts->tab_count);
    } else if (flags->b) {
      printf("%6d", counts->char_count / 2);
    } else if (flags->a) {
      // If "-a" is present, print all counts in order
      printf("%6d %6d %6d %6d", counts->word_count, counts->char_count,
             counts->line_count, counts->tab_count);
      break; // "-a" includes all counts, so we stop further checks
    }
  }

  printf("\n");
}

void count(Counts *counts, char ch, Flags *flags, int *in_word) {
  // count chars
  if (flags->c || flags->a || flags->b) {
    counts->char_count++;
  }

  // count tabs
  if (ch == '\t' && (flags->t || flags->a)) {
    counts->tab_count++;
  }

  // count lines
  if (ch == '\n' && (flags->l || flags->a)) {
    counts->line_count++;
  }

  // count words
  if (isspace(ch) && (flags->w || flags->a)) {
    if (*in_word) { // If we were inside a word
      counts->word_count++;
      *in_word = 0; // Mark that we've exited a word
    }
  } else {
    if (!(*in_word)) { // If we were not in a word before
      *in_word = 1;    // Mark that we've entered a word
    }
  }

  if (flags->s) {
    printf("%c", ch);
  }
}

void get_counts_file(Options *options, Flags *flags, int *in_word, char *ch,
                     Counts *counts) {
  // check if no file was provided.
  if (options->args_count == 0) {
    perror("NO FILE provided.");
    exit(0);
  }

  for (int i = 0; i < options->args_count; i++) {
    // printf("-----------------------------------------------\n");
    // printf("\n -- file_name [ %s ]  \n", options->args[i]);

    // init the file stream and check if it's a valid file.
    FILE *file = fopen(options->args[i], "r");
    if (file == NULL) {
      perror("\nTHE PATH YOUR PROVIDED FOR THE FILE IS NOT CORRECT.\n");
      exit(0);
    }

    while ((*ch = getc(file)) != EOF) {
      count(counts, *ch, flags, in_word);
    }
  }
}

void get_count_pipe(Flags *flags, int *in_word, char ch, Counts *counts) {
  while ((ch = getc(stdin)) != EOF) {
    count(counts, ch, flags, in_word);
  }
}

Counts get_counts(Options *options, Flags *flags) {
  Counts counts = {0, 0, 0, 0};

  int in_word = 0;
  char ch = '\0';

  // check if there's no args, if so, read from stdin.
  if (options->args_count) {
    get_counts_file(options, flags, &in_word, &ch, &counts);
  } else if ((ch = getc(stdin)) != EOF) {
    get_count_pipe(flags, &in_word, ch, &counts);
  }

  print_count(options, &counts, flags);

  return counts;
}
