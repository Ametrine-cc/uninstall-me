#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 2048
char process_name_buffer[MAX_BUFFER_SIZE];

const char *process_name() {
  FILE *processfilePtr;

  processfilePtr = fopen("/proc/self/comm", "r");

  if (processfilePtr != NULL) {
    fgets(process_name_buffer, MAX_BUFFER_SIZE, processfilePtr);
  } else {
  }

  fclose(processfilePtr);

  process_name_buffer[strcspn(process_name_buffer, "\r\n")] = 0;

  return process_name_buffer;
}

void uninstall() {
  printf("Uninstalling %s\n", process_name());
  return;
}

void uninstall_me(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    // printf("%s\n", argv[i]);

    if (strcmp(argv[i], "--uninstall") == 0) {
      printf("found!\n");
      uninstall();
    } else {
      continue;
    }
  }

  return;
}
