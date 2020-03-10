#include <iostream>
#include <ctime>
using namespace std;

//settings for the game
const int rows = 3;
const int column = 3;

int maxships = 3;

//board inputs
int board [rows][column];
int board2 [rows][column];

//Shows the results of the board once the game has concluded

void Show()
{
    cout << "--------" << endl << "Enemy board" << endl << "--------" << endl;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < column; j ++)
        {
            cout << board[i][j] << " ";  
        }
        cout << endl;
    }

cout << "--------" << endl << "Your Board" << endl << "--------" << endl;

    for(int a = 0; a < rows; a++)
    {
        for(int b = 0; b < column; b++)
        {
            cout << board2[a][b] << " ";
        }
        cout << endl;
    }
}

//the number of ships duh
int NumberOfShips()
{
    int c = 0;
    int c2 = 0;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < column; j++)
        {
            if(board[i][j] == 1)
            c++;
           
            else if(board2[i][j] == 1)
            c2++;
        }
    }
    return c;
}

//Randomly setting ship location for convinience
void SetShips()
{
    int s = 0;
    int s2 = 0;
    while(s < maxships)
    {
        int x = rand() % rows;
        int y = rand() % column;
        if (board[x][y] != 1)
        {
            s++;
            board[x][y] = 1;
        }
    }
    while (s2 < maxships)
    {
        int x = rand() % rows;
        int y = rand() % column;
        if(board2[x][y] != 1)
        {
            s2++;
            board2[x][y] = 1;
        }
    }
}

//Checking player fire
bool Fire(int x, int y)
{
    if(board[x][y] == 1)
    {
        board[x][y] = 2;
        return true;
    }
    return false;
}

bool Miss(int x, int y)
{
    if(board[x][y] == 0)
    {
        return true;
    }
    return false;
}

//Checking AI fire
bool Fire2(int x, int y)
{
    if(board2[x][y] == 1)
    {
        board2[x][y] = 2;
        return true;
    }
    return false;
}

bool Miss2(int x, int y)
{
    if(board2[x][y] == 0)
    {
        return true;
    }
    return false;
}

// Checking the board to see if either of the sides lost, also keeps while(!(Lost)) going
bool Lost()
{
    int ShipsLeft = 0;
    int ShipsLeft2 = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if(board[i][j] == 2)
            {
                ShipsLeft++;
            }
            else if (board2[i][j] == 2)
            {
                ShipsLeft2++;
            }
            else if(ShipsLeft == 3 || ShipsLeft2 == 3)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    srand(time(NULL));
    SetShips();
    char prompt;
    int pos1, pos2,/*pos3 and 4 are the bot's inputs*/ pos3, pos4;
    while(!(Lost()))
    {
        // if players dont enter a number between 0 and 2 here, they instantly lose
        cout << "Please input numbers between 0 and 2 one at a time captain! (x,y): " << endl;
        cin >> pos1; cin >> pos2;

        if(!((pos1 >= 0) && (pos1 <= 2)))
        {
            if(!((pos1 >= 0) && (pos1 <= 2)))
            {
                cout << "That is not a valid coordinate! YOU ARE NOT A TRUST WORTH CAPTAIN!" << endl;
                break;
            }
        }
        
        cout << "(" << pos1 << "," << pos2 << ")" << " ";
        
        if(Fire(pos1, pos2) == true) 
        {
            cout << "Enemy hit!" << endl;
        }
        if (Miss(pos1, pos2) == true)
        cout << "is a miss captain!" << endl;
        cout << "Surrender? (y/n): "; cin >> prompt;

        //Bot's turn
        pos3 = rand() % 2;
        pos4 = rand() % 2;

        if(Fire2(pos3, pos4) == true)
        cout << "Captain! The enemy fired and hit!" << endl;

        if(Miss2(pos3, pos4) == true)
        cout << "The enemy fired and missed! But surrender was never an option for him..." << endl;
        
        if(Lost() == true)
        {
            break;
        }

        if(prompt == 'y')
        break;
    }
    cout << "Game Over!" << endl;
    Show();
    
return 0;
}


