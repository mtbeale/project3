#include <iostream>
#include <vector>
#include <string.h>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>
#include <fstream>
#include <getopt.h>
#include <stdio.h>

using namespace std;

int main(int argc, char * argv[]) {

  vector <string> lines;
  ifstream in;

  int num = 10;
  int opt;

  while ((opt = getopt(argc,argv,"fc:n:")) != -1) {
      switch(opt) {
      case 'f':
        break;
      case 'c':
        break;
      case 'n':
        num= atoi(optarg);
        break;
      }
    }
  for (int i = optind; i < argc; i++) {
    in.open(argv[i]);
    for (string line; getline(in,line);) {
          lines.push_back(line);
    }
  }
 for (size_t i = min(lines.size(),size_t(10));  i <lines.size();  i++) {
    cout << lines[i] << endl;
    }
  }

