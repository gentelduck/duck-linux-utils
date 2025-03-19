#include "get_counts/index.h"
#include "get_flags/index.h"
#include "get_options/index.h"
#include "show_help/index.h"

int main(int argc, char **argv) {

  Options options = get_options(argc, argv);
  Flags flags = has_flags(&options);

  if (flags.h) {
    show_help();
  }

  Counts counts = get_counts(&options, &flags);

  return 0;
}

/*
 * TODO:
 *
 * - [ ] map the .gitignore file to exclude files.
 * - [ ] recognize files type.
 * - [ ] group files.
 * - [ ] count group ( files, lines, words, chars ).
 * - [ ] print the groups in a colorful table.
 * - [ ] show statics about the project.
 * - [ ] full support to ditch the the `npx colc` at npm.
 */

// printf("Flags:\n");
// for (int i = 0; i < options.flags_count; i++) {
//   printf("%s\n", options.flags[i]);
// }
//
// printf("Arguments:\n");
// for (int i = 0; i < options.args_count; i++) {
//   printf("%s\n", options.args[i]);
// }
