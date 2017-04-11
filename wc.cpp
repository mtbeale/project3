#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


using namespace std;

int main(const int argc, char * argv[]) {

  int lines=0, words=0, bytes = 0;
  char word[30];
  string w, l;
  ifstream in;
  struct stat filest;

  int o;
  while ((o = getopt(argc, argv,"cmlw")) != -1)
    switch (o) {
    case 'c':
      break;
    case 'm':
      break;
    case 'l':
      break;
    case 'w':
      break;
    }

  for (int i =optind; i < argc; i++) {
  in.open(argv[i]);
  stat(argv[i], &filest);
  while (in >> w){
    words++;
  }
  in.close();
  in.open(argv[i]);
  while (getline(in,l)) {
    lines++;
  }

   cout << lines << " " << words << " "
        << filest.st_size << " " <<  argv[i] << endl;

   in.close();
  }
   return 0;
}

