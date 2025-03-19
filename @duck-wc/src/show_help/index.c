#include <stdio.h>
#include <stdlib.h>

void show_help() {
  printf("\n");
  printf("============================================\n");
  printf("  @gentelduck/wc - Word Count Utility\n");
  printf("  Author: wildduck | Organization: gentelduck\n");
  printf("============================================\n\n");

  printf("Usage:\n");
  printf("  wc [OPTION] [FILE]\n\n");

  printf("Description:\n");
  printf(
      "  A lightweight and efficient word count utility inspired by GNU wc.\n");
  printf("  It processes text files or standard input and counts various "
         "elements.\n\n");

  printf("Options (Choose only one at a time):\n");
  printf("  %-15s %s\n", "-b, --bytes", "Print the byte count.");
  printf("  %-15s %s\n", "-w, --words", "Print the word count.");
  printf("  %-15s %s\n", "-l, --lines", "Print the line count.");
  printf("  %-15s %s\n", "-c, --chars", "Print the character count.");
  printf("  %-15s %s\n", "-t, --tabs", "Print the tab count.");
  printf("  %-15s %s\n", "-s, --show", "Display the file contents.");
  printf("  %-15s %s\n", "-h, --help", "Display this help message and exit.");

  printf("\nExamples:\n");
  printf("  wc -w file.txt        Count words in file.txt\n");
  printf("  wc -c file.txt        Count characters in file.txt\n");
  printf("  wc -l file.txt        Count lines in file.txt\n");
  printf("  wc -t file.txt        Count tabs in file.txt\n");
  printf("  cat file.txt | wc -w  Count words from standard input\n\n");

  printf("Notes:\n");
  printf("  - Only multiple options can be used at a time.\n");
  printf("  - If no file is provided, the program will read from standard "
         "input.\n");
  printf("  - This tool is optimized for performance and accuracy.\n");

  printf("\nReport issues at: "
         "https://github.com/gentelduck/duck-linux-utils/issues\n");
  printf("\n");

  exit(0);
}
