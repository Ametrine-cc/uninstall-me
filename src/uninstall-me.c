/*
 * uninstall-me: uninstalling apps with --uninstall made easy
 * Copyright (C) 2026 Ametine Foundation

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "include/uninstall-me.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char process_name_buffer[MAX_BUFFER_SIZE];

char *get_process_name() {
  FILE *processfilePtr;

  processfilePtr = fopen("/proc/self/comm", "r");

  if (processfilePtr != NULL) {
    fgets(process_name_buffer, MAX_BUFFER_SIZE, processfilePtr);
  } else {
    printf("error");
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

int uninstall_me(const char *uninstall_files[], size_t length) {
  // for (int i = 0; i < argc; i++) {
  // if (strcmp(argv[i], "--uninstall") == 0) {
  // if (geteuid() != 0) {
  // printf("--uninstall needs to be run as root please use sudo/doas\n");
  // exit(1);
  // } else {
  // uninstall(uninstall_files, size);
  // }
  // } else {
  // continue;
  // }

  for (size_t i = 0; i < length; i++) {
    printf("%s\n", uninstall_files[i]);
  }

  return 0;
}
