
#define MAX_ARGS 2
#define MAX_FLAGS 5

typedef struct {
  int flags_count;
  char *flags[MAX_FLAGS];
  int args_count;
  char *args[MAX_ARGS];
} Options;

Options get_options(int argc, char **argv) {
  Options option = {0, {0}, 0, {0}};

  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      option.flags[option.flags_count++] = argv[i];
    } else {
      option.args[option.args_count++] = argv[i];
    }
  }

  return option;
}
