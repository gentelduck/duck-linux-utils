#include <stdio.h>
#include <string.h>

#define MAX_COLOR_TEXT 256 // Adjust as needed

const char *get_colored_text(const char *color, const char *text) {
  static char colored_text[MAX_COLOR_TEXT];
  const char *color_code;

  if (strcmp(color, "black") == 0)
    color_code = "30";
  else if (strcmp(color, "red") == 0)
    color_code = "31";
  else if (strcmp(color, "green") == 0)
    color_code = "32";
  else if (strcmp(color, "yellow") == 0)
    color_code = "33";
  else if (strcmp(color, "blue") == 0)
    color_code = "34";
  else if (strcmp(color, "magenta") == 0)
    color_code = "35";
  else if (strcmp(color, "cyan") == 0)
    color_code = "36";
  else if (strcmp(color, "white") == 0)
    color_code = "37";
  else
    return text; // Return original text if color is invalid

  snprintf(colored_text, MAX_COLOR_TEXT, "\033[1;%sm%s\033[0m", color_code,
           text);
  return colored_text;
}
