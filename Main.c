#include <stdio.h>
#include <stdlib.h>
#include "Main.h"
#include "MakeMapT.h"
#include "LinkedList.h"


int main(int argc, char *argv[])
{
    int ROWS;
    int COLUMNS;
    int ReadParam;
    FILE* f;
    char *FileName;

    if (argc != 2) /*checks if arguments are more than 2, if they are then an error will be printed*/
    {
        printf("Invalid number of arguments, please input only 1 arguments\n");

    }
    else{

        FileName = argv[1]; /*stores the first argument in a variable called filename*/

        f = fopen(FileName, "r"); /*opens and reads the file with error handling*/
        if (f == NULL)
        {
            perror("Error Opening file!/File does not Exist!");
        }
        else {
            ReadParam = fscanf(f, "%d %d", &ROWS, &COLUMNS); /*scans the first 2 integers and stores them inside a variable*/
            if (ReadParam != 2)
            {
                perror("Error Reading file or End of File");
            }
            else{
                
                printMap(ROWS, COLUMNS, FileName, f); /*passes all variables into printmap*/
            }

            
        }

        fclose(f);
    }

    return 0;
}