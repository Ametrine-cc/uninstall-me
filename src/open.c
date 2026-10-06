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

#include "uninstall-me.h"
#include <stdio.h>
// #include <stdlib.h>

int open_file(const char *file_name) {
  printf("file: %s\n", file_name);

  FILE *fptr;
  fptr = fopen(file_name, "r");

  if (fptr == NULL) {
    perror("Error");
    return 1;
  }

  char line[256];

  while (fgets(line, sizeof line, fptr) != NULL) {
    printf("%s", line);
  }

  return 0;
}
