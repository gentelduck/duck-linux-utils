#include "../styler/styler.h"
#include <pthread.h>
#include <stdatomic.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COLOR_TEXT 256
#define SPINNER_DELAY 100000 // 100ms

// Global atomic flag to control spinner
atomic_int spinner_running = 1;

// Spinner thread function
void *spinner_thread(void *arg) {
  const char *circle[] = {"⠋", "⠙", "⠹", "⠸", "⠼", "⠴", "⠦", "⠧", "⠇", "⠏"};
  int i = 0;

  while (atomic_load(&spinner_running)) {
    printf("\r%s Loading... ", circle[i++ % 10]);
    fflush(stdout);
    usleep(SPINNER_DELAY);
  }

  return NULL;
}

// Function to stop the spinner and print success message
void success_message(const char *message) {
  atomic_store(&spinner_running, 0);
  usleep(SPINNER_DELAY); // Small delay to ensure spinner stops
  printf("\r%s %s\n", get_colored_text("green", "✔ SUCCESS:"), message);
}

// Function to stop the spinner and print error message
void error_message(const char *message) {
  atomic_store(&spinner_running, 0);
  usleep(SPINNER_DELAY); // Small delay to ensure spinner stops
  printf("\r%s %s\n", get_colored_text("red", "✖ ERROR:"), message);
}

// Define struct with function pointers
typedef struct {
  void (*success)(const char *);
  void (*error)(const char *);
} Spinner;

// Create the spinner object
Spinner spinner = {.success = success_message, .error = error_message};

// Main function
int main() {
  pthread_t spinnerThread;

  // Start spinner thread
  pthread_create(&spinnerThread, NULL, spinner_thread, NULL);

  // Simulate a long-running process (sleep for 5 seconds)
  sleep(5);

  // Stop spinner and print success or error
  spinner.error(get_colored_text("red", "GOD damn it you're a moron.!!!"));
  // spinner.error("Something went wrong.");

  // Wait for spinner thread to terminate
  pthread_join(spinnerThread, NULL);

  return 0;
}
