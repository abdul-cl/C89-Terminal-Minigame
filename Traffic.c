#include <stdio.h>
#include <stdlib.h>
#include "Traffic.h"

void MoveCarsRight(char** mapArray, int tRows, int tColumns) /*function in input.c that moves cars to the left */
{
    int i;                        /*function for cars that are facing right, they move right once everytime the player moves and turn around whehn they hit the border*/
    int j;
    for (i = 0; i < tRows; i++)
    {
        for (j = tColumns - 1; j >= 0; j--)
        {
            if (mapArray[i][j] == '>')
            {
                
                if (mapArray[i][j + 1] == '.')
                {
                   
                    mapArray[i][j + 1] = '>';
                    mapArray[i][j] = '.';
                    
                }
                else if (mapArray[i][j + 1] == ' ' && mapArray[i-1][j] == '.')
                {
                    
                    mapArray[i][j] = '^';
                
                }
                else if (mapArray[i][j + 1] == ' ' && mapArray[i+1][j] == '.')
                {
                    
                    mapArray[i][j] = 'V';
                
                }
            }
        }
    }

}
void MoveCarsLeft(char** mapArray, int tRows, int tColumns) {
    int i, j;
    for (i = 0; i < tRows; i++)
    {
        for (j = 0; j < tColumns; j++)
        {
            if (mapArray[i][j] == '<')
            {
                if (j > 0 && mapArray[i][j - 1] == '.')
                {
                    mapArray[i][j - 1] = '<'; 
                    mapArray[i][j] = '.';    
                }
                else if (j > 0 && mapArray[i][j - 1] == ' ')
                {
                    
                    if (i > 0 && mapArray[i - 1][j] == '.')
                    {
                        mapArray[i][j] = '^'; 
                    }
                    else if (i < tRows - 1 && mapArray[i + 1][j] == '.') {
                        mapArray[i][j] = 'V'; 
                    }
                }
            }
        }
    }
}
void MoveCarsUp(char** mapArray, int tRows, int tColumns)
{
    int i;                        /*function for cars that are facing right, they move right once everytime the player moves and turn around whehn they hit the border*/
    int j;
    for (i = 0; i < tRows; i++)
    {
        for (j = tColumns - 1; j >= 0; j--)
        {
            if (mapArray[i][j] == '^')
            {
                
                if (mapArray[i - 1][j] == '.')
                {
                   
                    mapArray[i-1][j] = '^';
                    mapArray[i][j] = '.';
                    
                }
                else if (mapArray[i - 1][j] == ' ' && mapArray[i][j + 1] == '.')
                {
                    mapArray[i][j] = '.';
                    mapArray[i][j] = '>';
                
                }
                else if (mapArray[i-1][j] == ' ' && mapArray[i][j-1] == '.')
                {
                    mapArray[i][j] = '.';
                    mapArray[i][j] = '<';
                
                }
            }
        }
    }
}
void MoveCarsDown(char** mapArray, int tRows, int tColumns)
{
    int i, j;
    for (i = tRows - 1; i >= 0; i--)
    {
        for (j = 0; j < tColumns; j++)
        {
            if (mapArray[i][j] == 'V')
            {
                if (i < tRows - 1 && mapArray[i + 1][j] == '.') {
                    
                    mapArray[i + 1][j] = 'V';
                    mapArray[i][j] = '.';
                } else if (i < tRows - 1 && mapArray[i + 1][j] == ' ') {
                   
                    if (j > 0 && mapArray[i][j - 1] == '.') {
                        mapArray[i][j] = '<';
                    } else if (j < tColumns - 1 && mapArray[i][j + 1] == '.') {
                        mapArray[i][j] = '>'; 
                    } else {
                        
                        mapArray[i][j] = 'V';
                    }
                }
            }
        }
    }
}

