#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>


using namespace std;

const char * get_timestamp() {
  time_t now = time (NULL);

  return asctime(localtime (&now));
}

int main(const int argc, const char * argv[]) {
  char buffer [1024];

  if (argc == 2) {

    time_t now = time(NULL);
    struct tm * timeinfo;
    time(&now);
    timeinfo = localtime(&now);
    strftime(buffer,80,argv[1],timeinfo);
    puts(buffer);

  } else {
    const char * timestamp = get_timestamp();

  write(STDOUT_FILENO,timestamp ,50);
  }
}
