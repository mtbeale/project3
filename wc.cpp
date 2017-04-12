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

  int lines=0, words=0,bytes = 0;; //counts
  int tlines=0, twords=0, tbytes=0; //total counts
  string w, l;
  ifstream in;
  struct stat filest; //for bytes
  bool cflg = false, mflg = false, lflg=false, wflg=false;

  int o;
  while ((o = getopt(argc, argv,"cmlw")) != -1){
    switch (o) {
    case 'c':
      cflg = true;
      break;
    case 'm':
      mflg = true;
      break;
    case 'l':
      lflg = true;
      break;
    case 'w':
      wflg = true;
      break;
    }
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
 bytes = filest.st_size;

  if (lflg)
    cout << lines << " ";
   if (wflg)
    cout << words << " ";
   if (cflg)
     cout << filest.st_size << " ";

   cout << argv[i] << endl;
   twords+=words;
   tlines+=lines;
   tbytes+=bytes;
   words = 0;
   lines = 0;
   bytes = 0;
   in.close();
  }
  if (argc > 1){
    cout << tlines << " " << twords << " " << tbytes << " " << "total" << endl;
  }
   return 0;
}

