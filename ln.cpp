#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(const int argc, const char * argv[]) {

  const char * myargs[3];

  if (strcmp(argv[1],"-s") == 0) {

  myargs[0] = argv[2];
  myargs[1] = argv[3];
  symlink(myargs[0],myargs[1]);

  } else {

    myargs[0] = argv[1];
    myargs[1] = argv[2];
    link(myargs[0],myargs[1]);

  }
}
