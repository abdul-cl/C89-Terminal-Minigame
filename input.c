#include <stdio.h>
#include <stdlib.h>
#include "input.h"



void playerInput(char **mapArray, int rows, int columns) {
    int i;
    int j;
    char userInput;
    char nextChar;
    int xPlayerLocation;
    int yPlayerLocation;

        printf("Enter WASD to move the player: ");
        scanf(" %c", &userInput);

    // Update the position based on the direction
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            if (mapArray[i][j] == 'P') {
                xPlayerLocation=i;
                yPlayerLocation=j;
            }
        }
    }
   

    int gameState=0;
    //while(gameState!=1){
       // printf("Enter WASD to move the player: ");
        //scanf(" %c", &userInput);
        if(userInput=='d'){
            mapArray[xPlayerLocation][yPlayerLocation+1]='P';
            mapArray[xPlayerLocation][yPlayerLocation]='.';
            yPlayerLocation++;
            
            //mapArray[xPlayerLocation][yPlayerLocation-1]='.';
            
        }
    }
            
           // }
        
    

