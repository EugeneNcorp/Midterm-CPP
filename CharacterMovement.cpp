//Midterm Character Movement Program
//by Eugene Nazarenko
//Program supposed to move the character based on inputs.
#include <iostream>
#include <string>

using namespace std;

//Character template
struct Character
{
    //representation symbol of the character
    char symbol;
    //Doesn't matter in this project
    string name;
    int health;
    int damage;
};
//method to render the board anytime we want
void DrawBoard(char matrix[4][4])
{
    int row  = 4;
    int column = 4;
    //Double loop to render every cell
    for(int i = 0; i<row; i++)
    {
        for(int k = 0; k<column; k++)
        {
            cout<<matrix[i][k]<<"  ";
        }
        cout<<endl;
    }
}

//Function finds the current row of character on the field
int FindPlayerRow(Character character, char field[4][4])
{
    for(int i = 0; i<4; i++)
    {
        for(int k = 0; k<4; k++)
        {
            if(field[i][k] == character.symbol)
            {
                return i;
            }
        }
    }
    //if program didn't find player on board we return -1 to provoke the error in compiler and do not return false coordinates
    return -1;  
}

//Function finds the current column of character on the field
int FindPlayerColumn(Character character, char field[4][4])
{
    for(int i = 0; i<4; i++)
    {
        for(int k = 0; k<4; k++)
        {
            if(field[i][k] == character.symbol)
            {
                return k;
            }
        }
    }
    //if program didn't find player on board we return -1 to provoke the error in compiler and do not return false coordinates
    return -1;  
}

//method checks if the position is in bounds of the field
bool InBounds(int row, int col, int maxRow, int maxCol)
{
    if(row >= 0 && row < maxRow && col >= 0 && col < maxCol)
    {
        return true;
    }
    return false;
}

//Character Movement main logic
void MoveAnalysis(Character character, char field[4][4], char direction)
{
    //Set variables
    int horMoveDir = 0;
    int verMoveDir = 0;
    
    //Find current Player Vertical and Horizontal position
    int currentVertPosition = FindPlayerRow(character, field);
    int currentHorPosition = FindPlayerColumn(character, field);
    
    //Depending on the input, we use corresponding direction vector's components (x,y)
    switch(direction)
    {
        case 'w':
        horMoveDir = 0;
        verMoveDir = -1;
            break;
            
        case 'a':
        horMoveDir = -1;
        verMoveDir = 0;
            break;
            
        case 's':
        horMoveDir = 0;
        verMoveDir = 1;
            break;
        case 'd':
        horMoveDir = 1;
        verMoveDir = 0;
            break;
        //in case of incorrect input stop the method
        default:
        cout<<endl<<"You made a mistake, repeat again."<<endl<<endl;
        return;
    }
    
    //Calculate the new position based on current position and direction vector
    int newVerticalPosition = currentVertPosition + verMoveDir;
    int newHorizontalPosition = currentHorPosition + horMoveDir;
    
    //Check if the next move will be in bounds of the field
    if(!InBounds(newVerticalPosition, newHorizontalPosition, 4, 4))
    {
        return;
    }
    
    //Reset current position
    field[currentVertPosition][currentHorPosition] = '*';
    //Put the player on the new position
    field[newVerticalPosition][newHorizontalPosition] = character.symbol;
}

int main() 
{
    //Create a matrix
    char fieldMatrix[4][4];
    //Create the player
    Character player{'@', "John C++", 10, 2};
    char choice;
    
    //Initialize default field view
     for(int i = 0; i<4; i++)
    {
        for(int k = 0; k<4; k++)
        {
            fieldMatrix[i][k] = '*';
        }
    }
    
    //Put player on the board
    fieldMatrix[2][2] = player.symbol;
    
    DrawBoard(fieldMatrix);
    
    //Update loop
    while(true)
    {
        //Ask the movement direction
        cout<<"To finish the program type *EXIT*"<<endl;
        cout<<"To move in North, West, South, East type w,a,s,d respectively: ";
        
        cin>>choice;
        //If player will type EXIT, program will stop
        if(choice == 'E')
        {
            return 0;
        }
        //put the player, field and player's choice information and perform the movement
        MoveAnalysis(player, fieldMatrix, choice);
        //Render the field
        DrawBoard(fieldMatrix);
    }

    return 0;
}




