#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <unistd.h>
#include <fcntl.h>

using std::cout;
using std::endl;

int main(const int argc, const char * argv []) {
  const char * filename;
  int fd;
  const int BUFF_SIZE = 1024;
  char buffer [BUFF_SIZE];
  int n = 0;
  int num = 1;

  if (argc == 1) {
    while ((n = read(STDIN_FILENO, buffer, BUFF_SIZE)) > 0 && num <10) {
      if (write(STDOUT_FILENO, buffer, n) == -1)
        perror("write");
      num++;
    }
  }


for (int i = 1; i < argc; i++) {
  filename = argv[i];
  fd = open(filename,O_RDONLY);

  if (strcmp(argv[i],"-") == 0) {
    while ((n = read(STDIN_FILENO, buffer, BUFF_SIZE)) > 0 && num < 10) {
      if (write(STDOUT_FILENO, buffer, n) == -1)
        perror("write");
      num++;
    }
  }
  else if (fd != -1) {
    while ((n = read(fd, buffer, BUFF_SIZE)) > 0) {
      if (write(STDOUT_FILENO,buffer,n) == -1)
        perror("write");
    }
  }
 }
}
