#include <stdio.h>

// Must include to use the uninstall_me library
__attribute__((weak)) void uninstall_me(int argc, char *argv[],
                                        char *uninstall_files[], int size);

// To compile either of the following work:
//
// clang examples/example.c -u uninstall libuninstallmelib.a -o example
// clang examples/example.c -u uninstall -l uninstallmelib -o example
//
// inplementation of using uninstall code

int main(int argc, char *argv[]) {
  if (uninstall_me) {            // Only works when ran as root
    char *files[] = {"example"}; // 2d array of all files to be removed
    // pass argc, argv, file(files to be removed), size(number of files to be
    // removed)
    uninstall_me(argc, argv, files, 1);
  } else {
    printf("running without uninstall()\n");
  }

  return 0;
}
