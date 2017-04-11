#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

int main(const int argc, const char * argv[], const char * env[]) {
  
  for (int i = 0; env[i] != NULL; i++)
    printf("%s\n",env[i]);
  
  return 0;
}
