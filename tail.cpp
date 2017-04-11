#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <cerrno>


using namespace std;

int main(const int argc, const char * argv[]) {
  int num = 0;
  int cnum = 0;
  int lines = 0;
  int words = 0;
  int bytes = 0;
  int n = 0;

  const int BUFF_SIZE = 1024;
  char buffer[BUFF_SIZE];

  const char * filename;
  int fd;

  int opt;

  /*  while ((opt = getopt(argc , argv[], "fc:n:")) != -1)  {
    switch (opt) {

    case 'f':

      break;
    case 'c':
      if(optarg) cnum = atoi(optarg);
      break;
    case 'n':
      if (optarg) num = atoi(optarg);
      break;
    }
  }
  */
  for (int i = 1; i < argc; i ++) {
    filename = argv[i];
    fd = open(filename,O_RDONLY);
    if (fd != -1) {
    while ((n = read(fd, buffer, BUFF_SIZE)) > 0) {
      if (write(STDOUT_FILENO, buffer, 5) == -1) perror("write");
    }
  }
}
}
