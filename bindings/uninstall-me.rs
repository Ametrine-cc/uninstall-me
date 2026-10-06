#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(suspicious_runtime_symbol_definitions)]

use std::ffi::CStr;
use std::os::raw::c_char;

pub mod sys {
    include!(concat!(env!("OUT_DIR"), "/bindings.rs"));
}

pub use sys::*;

pub fn uninstall_me(uninstall_file: Option<Vec<String>>) {
    println!("{:?}", uninstall_file);
}

pub fn get_process_name() -> String {
    unsafe {
        let ptr: *mut c_char = sys::get_process_name();

        if ptr.is_null() {
            return String::new();
        }

        CStr::from_ptr(ptr).to_string_lossy().into_owned()
    }
}
