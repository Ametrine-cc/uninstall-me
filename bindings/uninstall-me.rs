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

#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(suspicious_runtime_symbol_definitions)]

use std::ffi::{CStr, CString};
use std::os::raw::c_char;
use std::process::exit;

pub mod sys {
    include!(concat!(env!("OUT_DIR"), "/bindings.rs"));
}

// pub use sys::*;

pub fn get_process_name() -> String {
    unsafe {
        let ptr: *mut c_char = sys::get_process_name();

        if ptr.is_null() {
            return String::new();
        }

        CStr::from_ptr(ptr).to_string_lossy().into_owned()
    }
}

pub fn uninstall_me(uninstall_file: String) {
    let c_text = CString::new(uninstall_file).expect("string contains an interior NUL");
    let ptr: *const std::ffi::c_char = c_text.as_ptr();

    unsafe {
        // if sys::check_root() == 1 {
        // exit(1)
        // }

        if sys::uninstall_me(ptr) == 1 {
            exit(1)
        }
    }
}

pub fn uninstall_them(uninstall_files: &[String]) {
    let c_strings: Vec<CString> = uninstall_files
        .iter()
        .map(|s| CString::new(s.as_str()).expect("String contained an interior null byte"))
        .collect();

    let mut c_char_ptrs: Vec<*const c_char> = c_strings.iter().map(|cs| cs.as_ptr()).collect();

    let size = c_char_ptrs.len();
    let ptr_to_array = c_char_ptrs.as_mut_ptr();

    unsafe {
        sys::uninstall_them(ptr_to_array, size);
    }
}
