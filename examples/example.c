#include <stdio.h>

__attribute__((weak)) void uninstall_me(int arc, char *argv[]);

// To compile either of the following work:
//
// clang examples/example.c -u uninstall libuninstallmelib.a -o example
// clang examples/example.c -u uninstall -l uninstallmelib -o example
//
// inplementation of using uninstall code

int main(int argc, char *argv[]) {
  if (uninstall_me) {
    uninstall_me(argc, argv);
  } else {
    printf("running without uninstall()\n");
  }

  return 0;
}
