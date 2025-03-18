
#ifndef GET_OPTIONS_H
#define GET_OPTIONS_H

#define MAX_ARGS 2
#define MAX_FLAGS 5

typedef struct {
  int flags_count;
  char *flags[MAX_FLAGS];
  int args_count;
  char *args[MAX_ARGS];
} Options;

Options get_options(int argc, char **argv);

#endif // OPTIONS_H
