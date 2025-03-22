#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "MakeMapT.h"
#include "Traffic.h"
#include "LinkedList.h"
#include "terminal.h"

void printMap(int rows, int columns, char *FileName, FILE* f)
{
    char **mapArray; /*initialization of variables in the beginning*/
    int i, j;
    int ch;
    int gameFinished = FALSE;
    char userInput;
    char nextChar;
    char eaten;
    int xPlayerLocation;
    int yPlayerLocation;
    int goalFirst;
    int goalLast;
    int CarNotPresent = FALSE;
    int LoseCondition = FALSE;
    int WinCondition = FALSE;
    List* playerPositions;
    Player * getVal;
    Player* player;

    

    eaten=' ';
    nextChar=' ';
    

    f = fopen(FileName, "r"); /*opens the file again then seeks to the second row*/
    fseek(f, 6, SEEK_SET);

    mapArray = (char **)malloc(rows * sizeof(char *));      /*mallocing the 2D array to the heap memory*/
    for (i = 0; i < rows; i++)
    {
        
        mapArray[i] = (char *)malloc(columns * sizeof(char));
        for(j = 0; j < columns; j++)
        {
        
            if (i == 0 || i == rows - 1 || j == 0 || j == columns - 1)  /*populating the array with * for the border, '.'
            for the roads (on every even line) and  ' ' for the areas between the roads*/
            {
                mapArray[i][j] = '*';
            }
        }
    }
   

    i = 0;
    j = 0;
    ch = fgetc(f);
                
    while (ch != EOF) /*reads 1 integer at a  time from the second row until the end of the file has been reached, depending on what number is inside the file, a different char will be populated intot he array*/

    {
        ch = fgetc(f);

        if(ch == '0')
        {
            mapArray[i][j] = ' ';
            j++;
        }
        else if (ch == '1')
        {
            mapArray[i][j] = '.';
            j++;
        }
        else if(ch == '2')
        {
            mapArray[i][j] = '>';
            j++;
        }
        else if(ch == '3')
        {
            mapArray[i][j] = 'P';
            j++;
        }
        else if(ch == '4')
        {
            mapArray[i][j] = 'G';
            j++;
        }
        else if (ch == '\n')
        {
            i++;
            j = 0;
        }
     

                    
    }
    
    i = 0;
    j = 0;

    for (i = 0; i < rows; i++)
    {
        for(j = 0; j < columns; j++)
        {
            if (i == 0 || i == rows - 1 || j == 0 || j == columns - 1)  /*populating the array with * for the border, '.' for
             the roads (on every even line) and  ' ' for the areas between the roadS*/
            {
                mapArray[i][j] = '*';
            }
        }
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            if (mapArray[i][j] == 'P') {
                xPlayerLocation=i;  /*looks throughout the array to find the P char, when it is found, it stores the index/location of the P char into variables that can be later used*/
                yPlayerLocation=j;
            }
            if(mapArray[i][j]=='G'){
                goalFirst=i;    /*looks throughout the array to find the G char, when it is found, it stores the index/location of the G char into variables that can be later used*/
                goalLast=j;
            }
        }
    }
    playerPositions = generateList(); /*Creates the linked list that will be used for the undo feature*/
    


    do{ /*do-while loop to keep the function running as long as the player hasnt won or lost*/
        system("cls");

         player = (Player*)malloc(sizeof(Player)); /*Allocates the Player struct to the head memory*/
       



        for(i = 0; i < rows; i++)
        {
            for(j = 0; j < columns; j++)
            {
                printf("%c", mapArray[i][j]);
            }
        printf("\n");
        } /*Prints the map*/
        
        printf("Press W to go up\nPress S to go down\nPress A to go left\nPress D to go right\nPress U to undo a move ");

        userInput = getch();


        if(userInput=='d'){ /*if the user inputs d, it moves right*/
            if(mapArray[xPlayerLocation][yPlayerLocation+1] == '*') /*this makes sure that the player cannot replace or pass the border*/
            {
                mapArray[xPlayerLocation][yPlayerLocation] = 'P';
            }
            else
            {
                eaten=mapArray[xPlayerLocation][yPlayerLocation+1]; /*stores the char in the next index to eaten and the current location of the player to nextchar, moves the p char 1 index to the right*/
                mapArray[xPlayerLocation][yPlayerLocation]=nextChar;
                mapArray[xPlayerLocation][yPlayerLocation+1]='P';
                player->xPlay=xPlayerLocation; /*xplayerlocation, yplayerlocation and eaten are stored in variables inside the struct*/
                player->yPlay=yPlayerLocation;
                player->replace=eaten;
                player->xCur=xPlayerLocation;
                player->yCur=yPlayerLocation+1;
                insert(playerPositions,player); /*inserts the location into the linked list so that it cana be used later for undo*/
                yPlayerLocation++; /*increments the location of the player and makes nextchar equal eaten*/
                nextChar=eaten;

            }
        }
        else if(userInput == 'a'){ /*everything  here is the same thing as case d except this moves the P char left*/
            if(mapArray[xPlayerLocation][yPlayerLocation-1] == '*')
            {
                mapArray[xPlayerLocation][yPlayerLocation] = 'P';
            }
            else
            {
                eaten=mapArray[xPlayerLocation][yPlayerLocation-1];
                mapArray[xPlayerLocation][yPlayerLocation]=nextChar;
                mapArray[xPlayerLocation][yPlayerLocation-1]='P';
                player->xPlay=xPlayerLocation;
                player->yPlay=yPlayerLocation;
                player->replace=eaten;
                player->xCur=xPlayerLocation;
                player->yCur=yPlayerLocation-1;
                insert(playerPositions,player);
                yPlayerLocation--;
                nextChar=eaten;
            }
        }
        else if(userInput == 's'){ /*everything  here is the same thing as case d except this moves the P char down*/
            if(mapArray[xPlayerLocation+1][yPlayerLocation] == '*')
            {
                mapArray[xPlayerLocation][yPlayerLocation] = 'P';
            }
            else
            {
                eaten=mapArray[xPlayerLocation+1][yPlayerLocation];
                mapArray[xPlayerLocation][yPlayerLocation]=nextChar;
                mapArray[xPlayerLocation+1][yPlayerLocation]='P';
                player->xPlay=xPlayerLocation;
                player->yPlay=yPlayerLocation;
                player->replace=eaten;
                player->xCur=xPlayerLocation+1;
                player->yCur=yPlayerLocation;
                insert(playerPositions,player);
                xPlayerLocation++;
                nextChar=eaten;
            }
        }
        else if(userInput == 'w'){  /*everything  here is the same thing as case d except this moves the P char up*/
            if(mapArray[xPlayerLocation-1][yPlayerLocation] == '*')
            {
                mapArray[xPlayerLocation][yPlayerLocation] = 'P';
            }
            else
            {
                eaten=mapArray[xPlayerLocation-1][yPlayerLocation];
                mapArray[xPlayerLocation][yPlayerLocation]=nextChar;
                mapArray[xPlayerLocation-1][yPlayerLocation]='P';
                player->xPlay=xPlayerLocation;
                player->yPlay=yPlayerLocation;
                player->replace=eaten;
                player->xCur=xPlayerLocation-1;
                player->yCur=yPlayerLocation;
                insert(playerPositions,player);
                xPlayerLocation--;
                nextChar=eaten;
            }
        }
        else if (userInput == 'u') /*if u is pressed then the player moves back one space by deleting a listnode*/
        {
            if(playerPositions->head!=NULL)
            {
                getVal=(Player*)(removeNode(playerPositions)); /*calls the function that removes the node*/
                mapArray[getVal->xPlay][getVal->yPlay]='P';
                mapArray[getVal->xCur][getVal->yCur]=getVal->replace;
            }
        }

        if(goalFirst==xPlayerLocation&&goalLast==yPlayerLocation) /*If the stored location of goal is equal to the stored location of the P char, the flags are set to true and the game ends on this iteration of the do-while loop*/
        {
            
            gameFinished=TRUE; /*flag for ending the loop*/
            WinCondition=TRUE; /*flag for printing the win statement*/
        }
        

        MoveCarsUp(mapArray, rows, columns); /*function in Traffic.c that moves cars to the up*/
        MoveCarsRight(mapArray, rows, columns); /*function in Traffic.c that moves cars to the right */
        MoveCarsLeft(mapArray, rows, columns); /*function in Traffic.c that moves cars to the left*/
        MoveCarsDown(mapArray, rows, columns); /*function in Traffic.c that moves cars to the down*/
        


        CarNotPresent = FALSE; /*checks if any of the car chars exist within the map, if they do then the flag is set to true and the do-while ends on this iteration*/
        for (i = 0; i < rows && !CarNotPresent; i++)
        {
            for (j = 0; j < columns && !CarNotPresent; j++)
            {
                if (mapArray[i][j] == '>' || mapArray[i][j] == '<' || mapArray[i][j] == 'V' || mapArray[i][j] == '^')
                {
                    CarNotPresent = TRUE;
                }
            }
        }

    if (!CarNotPresent)
    {
        gameFinished = TRUE; /*flag for ending the loop*/
        LoseCondition = TRUE; /*flag for printing the lose condition*/
    }

    

    }while(!gameFinished); /*continues looping until gamefinished is set to TRUE*/

    system("cls"); /*clears the screen and prints the map one last time*/

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < columns; j++)
        {
            printf("%c", mapArray[i][j]);
        }
        printf("\n");
    }

    if(gameFinished == TRUE && WinCondition == TRUE) /*print statement for win condition*/
    {
    printf("You Win!\n");
    }

    if(gameFinished == TRUE && LoseCondition == TRUE) /*print statement for lose condition*/
    {
        printf("\nYou Lose!\n");
    }


    for (i = 0; i < rows; i++) /*frees the 2d Array*/
    {
        free(mapArray[i]);
    }
    free(mapArray);
    free(player);
    freeList(playerPositions);
}


            
