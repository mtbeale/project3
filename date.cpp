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
  return asctime (localtime (&now));
}

int main(const int argc, const char * argv[]) {

  const char * timestamp = get_timestamp();
  size_t length = strlen(timestamp);

  write(STDOUT_FILENO,timestamp ,50);

}
