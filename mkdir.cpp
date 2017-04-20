#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include <dirent.h>
#include <sys/stat.h>
#include <malloc.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <unistd.h>
#include <cstdlib>




using namespace std;

enum
  {
    PERM = S_IRWXU | S_IRWXG | S_IRWXO | S_ISUID | S_ISGID | S_ISVTX,
    //sets all the permission bits to equal 0777                              
  };


static void mkdr(const char *dir)
{

  size_t length;
  char *ptr = NULL;
  char temp[256];
  //initialize and declare variables                                          

  snprintf(temp, sizeof(temp),"%s",dir);
  //Write formatted output to sized buffer                                    

  length = strlen(temp);
  //set string length to temp array                                           

  if(temp[length - 1] == '/')
    {
      temp[length - 1] = 0;
    }
  //end if                                                                    

  for(ptr = temp + 1; *ptr; ptr++)
    {
      if(*ptr == '/')
    {
      if(*ptr == '/')
        {
          *ptr = 0;
          mkdir(temp, 0777);
          *ptr = '/';
        }
      //end if                                                                

    }
  //end for                                                                   

  mkdir(temp, 0777);
}
//end mkdr                                                                    


int main(int argc, char *argv[])
{
  bool pflag;
  bool mflag;
  char *endpt;
  struct stat sb;
  int opt;
  char file[30];
  char o[30];
  long val;
  //declare all variables and pointers                                        
    extern char *optarg;
  //found this online                                                         
  //internal linkage                                                          




  if (argc == 1)
    //if no parameters                                                        
    {
      cout << "mkdir: missing operand" << endl;
      //shows error message if input is incorrect                             
    }
  //end if                                                                    

  if (argc >= 2)
    //if one input                                                            
    {
      strcpy(o, argv[1]);

      //the rest of the if-else's check how many args                         

      if (argc == 2)
        {
          strcpy(file, argv[1]);
        }
      //end if                                                                

      else if (argc == 3)
        {
          strcpy(file, argv[2]);
        }
      //end elseif                                                            

      else if (argc == 4)
        {
          strcpy(file, argv[3]);
        }
      //end elseif                                                            

      stat(file, &sb);
      //stat on file and sb                                                   

      if ((sb.st_mode & S_IFMT) == S_IFDIR)
        {

          cout << "mkdir: cannot create directory `" <<  file << "': File exi\
sts" << endl;
          //prints when incorrect permissions are present                     

        }
      //end if                                                                

           while ((opt = getopt(argc, argv, "m:")) != -1)
        {
          switch (opt)
            {
            case 'p':
              pflag = true;
              break;

            case 'm':
              val = strtol(optarg, &endpt, 8);
              mflag = true;
              break;

            default:
              fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n", argv[0]);
              //prints error                                                  

              exit(EXIT_FAILURE);
              //exit status                                                   

            }
          //end switch                                                        

        }
      //end while                                                             

    }
  //end if                                                                    


  if (mflag == true)
    {
      //checks for m                                                          
      mkdr(file);
      chmod(file, val);

    }
  //end if                                                                    

  else if (pflag == true)
    {
      //checks for p                                                          
      //mkdr(file);                                                           
      //chmod(file, val);                                                     
      //something else needs to go here, but what...                          
    }
  //end else if                                                               

  else
    {
     //if neither                                                                        
      mkdr(file);

    }
  //end else                                                                              

}
//end main                                                                                