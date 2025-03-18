#include "../get_options/index.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int char_count;
  int word_count;
  int line_count;
  int tab_count;
} Counts;

Counts get_counts(Options *options) {
  Counts counts = {0, 0, 0, 0};

  if (options->args_count == 0) {
    perror("NO FILE provided.");
    exit(0);
  }
  int in_word = 0;
  char ch;

  for (int i = 0; i < options->args_count; i++) {
    printf("-----------------------------------------------\n");
    printf("\n -- file_name [ %s ]  \n", options->args[i]);

    FILE *file = fopen(options->args[i], "r");
    if (file == NULL) {
      perror("\nTHE PATH YOUR PROVIDED FOR THE FILE IS NOT CORRECT.\n");
      exit(0);
    }

    while ((ch = getc(file)) != EOF) {
      if (isspace(ch)) {
        if (in_word) {
          counts.word_count++;
          in_word = 0;
        }
      } else {
        if (!in_word) {
          in_word = 1;
        }
      }

      printf("%c", ch);
    }

    printf(" -- words_count [ %d ]  \n", counts.word_count);
    if (i == options->args_count - 1) {
      printf("-----------------------------------------------\n");
    }
  }

  return counts;
}
