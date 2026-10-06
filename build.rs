use std::env;
use std::fs;
use std::path::PathBuf;

fn main() {
    let out_dir = PathBuf::from(env::var("OUT_DIR").unwrap());

    cc::Build::new()
        .file("src/uninstall-me.c")
        .file("src/open.c")
        .include("src/include")
        .out_dir(&out_dir)
        .compile("uninstall-me");

    println!("cargo:rerun-if-changed=src/");

    println!("cargo:rustc-link-search=native={}", out_dir.display());
    println!("cargo:rustc-link-lib=static=uninstall-me");

    println!("cargo:rerun-if-changed=Makefile");
    println!("cargo:rerun-if-changed=src/include/uninstall-me.h");

    let bindings = bindgen::Builder::default()
        .header("src/include/uninstall-me.h")
        .parse_callbacks(Box::new(bindgen::CargoCallbacks::new()))
        .default_enum_style(bindgen::EnumVariation::Rust {
            non_exhaustive: true,
        })
        .generate()
        .expect("Unable to generate bindings");

    let bindings_str = bindings.to_string();
    let patched_bindings = bindings_str.replace("extern \"C\" {", "unsafe extern \"C\" {");

    fs::write(out_dir.join("bindings.rs"), patched_bindings).expect("Couldn't write bindings!");
}
