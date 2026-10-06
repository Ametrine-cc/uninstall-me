use uninstall_me::*;

mod common;

#[test]
fn basic() {
    common::setup();

    let uninstall_files: Vec<String> = vec![String::from("example.txt")];

    uninstall_me(Some(uninstall_files));
}
