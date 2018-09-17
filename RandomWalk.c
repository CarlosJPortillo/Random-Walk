#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    //Grid
    char characters[10][10] ={'.','.','.','.','.','.','.','.','.','.',
                              '.','.','.','.','.','.','.','.','.','.',
                              '.','.','.','.','.','.','.','.','.','.',
                              '.','.','.','.','.','.','.','.','.','.',
                              '.','.','.','.','.','.','.','.','.','.',
                              '.','.','.','.','.','.','.','.','.','.',
                              '.','.','.','.','.','.','.','.','.','.',
                              '.','.','.','.','.','.','.','.','.','.',
                              '.','.','.','.','.','.','.','.','.','.',
                              '.','.','.','.','.','.','.','.','.','.',};
    //check counter to keep track if there might be a possible dead end
    int checkCounter = 0;
    int col = 0;
    int row = 0;
    int direction;
    char *characterPointer;
    srand(time(NULL));
    bool deadEnd = false;
    int i = 0;
    char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
                         'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    //loop will change dot values to actual alphabet values within grid
    while(deadEnd == false && i < 26 )
    {
        checkCounter = 0;
        characterPointer = &characters[row][col];
        *characterPointer = alphabet[i];
        //create random direction
        direction = rand() % 4;
        //scenario to move up
        if(direction == 0 && row !=9 && characters[row +1][col] == '.')
        {
            row++;
            i++;
        }
        //scenario to move down
        else if(direction == 1 && row !=0 && characters[row - 1][col] == '.')
        {
            row--;
            i++;
        }
        //scenario to move left
        else if(direction == 2 && col !=9 && characters[row][col +1] == '.')
        {
            col++;
            i++;
        }
        //scenario to move right
        else if(direction == 3 && col != 0 && characters[row][col - 1] == '.')
        {
            col--;
            i++;

        }
        //a check to see if there is a dead end in the game
        else
        {
            //check if there is available space below only if you are not in the 10th row
            if(row != 9 )
            {
                if(characters[row+1][col] != '.')
                   {
                        checkCounter++;
                   }
            }
            //10th row automatically means there is no space below
            else if(row == 9)
            {
                checkCounter++;
            }
            //--------------------------------------------------
            //check if there is available space above only if not in 1st row and check counter is 1
            if(row != 0 && checkCounter == 1)
            {
                if(characters[row -1][col] != '.')
                {
                    checkCounter++;
                }
            }
            //first row automatically means there is no space above, also check if check counter is 1
            else if(row == 0 && checkCounter == 1)
            {
                checkCounter++;
            }
            //----------------------------------------------------
            if(col!= 9 && checkCounter == 2)
            {
                if(characters[row][col + 1] != '.')
                {
                    checkCounter++;
                }
            }
            else if(col == 9 && checkCounter == 2)
            {
                checkCounter++;
            }
            //-------------------------------------------------------
            //
            if(col!= 0 && checkCounter ==3)
            {
                if(characters[row][col - 1] != '.')
                {
                    checkCounter++;
                }
            }
            else if(col == 0 && checkCounter == 3)
            {
                checkCounter++;
            }
            //------------------------------------------
            if(checkCounter == 4)
            {
                deadEnd = true;
            }

        }

    }

    //outer loop for printing
    for(row = 0; row < 10; row++)
    {
        //inner loop for printing
        for(col = 0; col < 10; col++)
        {
            printf("%c", characters[row][col]);
        }
        printf("\n");
    }

    return 0;
}
