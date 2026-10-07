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

use uninstall_me::*;

mod common;

#[test]
fn multiple() {
    common::setup();

    // Getting the process name
    println!("Printing the current process name");
    println!("process_name: {}", get_process_name());

    // Pass files to be uninstalled into uninstall_them()
    // instead of one file into uninstall_me()
    let uninstall_files: Vec<String> = vec![String::from("example.txt")];
    uninstall_them(&uninstall_files);
}
