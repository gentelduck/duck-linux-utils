#include "get_counts/index.h"
#include "get_options/index.h"
#include <stdio.h>

int main(int argc, char **argv) {

  Options options = get_options(argc, argv);
  Counts counts = get_counts(&options);

  printf("\nTotal words count: %d\n", counts.word_count);
  return 0;
}

// printf("Flags:\n");
// for (int i = 0; i < options.flags_count; i++) {
//   printf("%s\n", options.flags[i]);
// }
//
// printf("Arguments:\n");
// for (int i = 0; i < options.args_count; i++) {
//   printf("%s\n", options.args[i]);
// }
