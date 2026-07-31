#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 2048
char process_name_buffer[MAX_BUFFER_SIZE];

const char *get_process_name() {
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

void uninstall(char *uninstall_files[], int size) {
  printf("Uninstalling %s\n", get_process_name());

  for (int i = 0; i < size; i++) {
    printf("%s\n", uninstall_files[i]);
    remove(uninstall_files[i]);
  }

  return;
}

void uninstall_me(int argc, char *argv[], char *uninstall_files[], int size) {

  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], "--uninstall") == 0) {
      if (geteuid() != 0) {
        printf("--uninstall needs to be run as root please use sudo/doas\n");
      } else {
        // printf("found!\n");
        uninstall(uninstall_files, size);
      }
    } else {
      continue;
    }
  }
}
