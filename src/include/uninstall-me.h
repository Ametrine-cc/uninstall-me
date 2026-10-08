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

#ifndef UNINSTALL_ME_H
#define UNINSTALL_ME_H

#include <stddef.h>
#include <stdlib.h>

char *get_process_name();
int check_root();

int uninstall_me(const char *uninstall_file);
int uninstall_them(const char *uninstall_file[]);

#endif // UNINSTALL_ME_H
