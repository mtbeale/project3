#include <cstdlib>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

unsigned int q = 0x04C11DB7;
unsigned int s = 0;
//declaring variables

int d;
int length = 0;
//declare variables

void f(char g) 
//takes in parameters
{
    for(int j = 7; j >= 0; j--) 
    {
       int ms = s & (1 << 31);
       s <<= 1;
       //appending

       if (ms)
       { 
        s = s ^ q;
        }
        //end if
    }
    //end for
    
    s ^= d;
}
//end void f(char g)

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        while(EOF != (d = getchar())) 
        {
            length++;
            f(d);
            //iterates through until the file ends
        
        }
        //end while

        int l = length;
        //length variable is set

        do 
        {
            f(l & 0xff);
            l >>= 8;
        }
        //end do
        while(l);

        f(0), f(0), f(0), f(0);
        printf("%u %u\n", ~s, length);
        return EXIT_SUCCESS;
    }
    // end if

    else
    {
        for (int j = 1; j < argc; j++)
        { 
            s = 0;
            length = 0;
            FILE *fp;
            fp = fopen(argv[j], "rb");
            //declaring variables

            if (fp)
            {   
                fseek(fp, 0, SEEK_END);
                long k = 0;
                long fs = 0 ;
                //fsize

                fs = ftell(fp);
                rewind(fp);

                while(k < fs)
                {
                    int first = fgetc(fp);
                    k++;
                    length++;
                    f(first); 
                }
                //end while

                int l = length;
                do 
                {
                    f(l & 0xff);
                    l >>= 8;
                    //append
                }
                while(l);
                //end while

                f(0), f(0), f(0), f(0);
                printf("%u %u %s\n", ~s, length, argv[j]);
                //print variables
            }
            //end if

            else
            {

                fprintf(stderr, "cksum: %s: No such file or directory\n", argv[j]);
                //prints out error message
            }
            //end else
        }
        //end for
    }
    //end else

    return EXIT_SUCCESS;
    //return exit status
}
//end main
