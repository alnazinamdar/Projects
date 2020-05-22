#include <iostream>
#include <stdlib.h>
#include "Person.h" //Connecting players to the class
#include <time.h>
#include <cmath> // MATH!!!
using namespace std;

//Bookmark: Completed turn changing and coordinate inputs. Finished making sure all elements can move or have invalid inputs, all thats left is to create winning parameters and movement limiters.

//Base Grid Generation
  const int Rows = 9;
  const int Columns = 9;
  char Room[Rows][Columns];
  



void visualGrid()
{
  //Some visual rules, can be ignored by coder.
  cout << "_______________________________________" << endl << endl;
  cout << "Human has to reach X! If Z reaches H, its game over for the human!"
  << endl << "Humans spawns at one end of the room and can move 3 spaces while zombies" << endl << "spawn randomly and can only move 2 spaces!" << endl; 
  cout << "_______________________________________" << endl << endl << endl;

  srand (time(NULL));


//Setting all of the elements in the grid to ' ' first so I can make sure nothing goes off grid
  for(size_t i = 0; i < Rows; i++)
  {
    for(size_t k = 0; k < Columns; k++)
    {
      Room[i][k] = ' ';
    }
  }
//Initial zombie location generators
  Person zombie;
  zombie.x = rand() % 7;
  zombie.y = rand() % 7;

  int rowNum = zombie.x;
  int colNum = zombie.y;

  Person zombie2;
  zombie2.x = rand() % 7;
  zombie2.y = rand() % 7;

  int rowNum2 = zombie2.x;
  int colNum2 = zombie2.y;

  //This makes it so that zombies will never be in the same block as the exit or the human upon spawn
  while((rowNum == rowNum2 && colNum == colNum2) || (rowNum == 0) || (rowNum2 == 0) || (colNum == 0) || (colNum2 == 0))
  {
    srand (time(NULL));
    zombie.x = rand() % 7;
    zombie.y = rand() % 7;

    zombie2.x = rand() % 7;
    zombie2.y = rand() % 7;

    colNum = zombie.y;
    rowNum = zombie.x;

    colNum2 = zombie2.y;
    rowNum2 = zombie2.x;

  }


//Zombie 1 spawner

  Room[rowNum][colNum] = 'z';

//Zombie 2 spawner

  Room[rowNum2][colNum2] = 'Z';

//Exit Spawner
  Room[0][0] = 'X';

//Human Spawner
  Room[8][8] = 'H';


  int currentPlayer = 3; // When the round starts with player 3, the while code starts current player to 1
  
  int banana = 0; //banana is just a true, false statement to end the while loop
  int turn = 0; //also a true false statement to end loops within the game

  while(banana == 0)
  {

    int inputx;
    int inputy;

    int outputx;
    int outputy;

//MAIN VISUAL CODE: Shows players what the grid looks like.

  cout << " 0  1  2  3  4  5  6  7  8" << endl
  << "    ________________________" << endl;


  for(size_t i = 0; i < Rows; i++)
  {
    cout << "| ";
    for(size_t k = 0; k < Columns; k++)
    {
      if(Room[i][k] == 'Z' || Room[i][k] == 'z' || Room[i][k] == 'X' || Room[i][k] == 'H')
      {
      cout << Room[i][k] << "| ";
      }

      else
      {
        cout << Room[i][k] << "| ";
      }
      if(k == 8)
      {
        cout << i;
      }
    }
    if(i != 8)
    {
      cout << endl;
    }
  

  }
  cout << endl << " ---------------------------" << endl;

  cout << "test: " << Room[8][8] << endl; 


//Find the location of z for movement calculation, not really that important so don't touch.

  for(size_t i = 0; i < Rows; i++)
  {
    for (size_t k = 0; k < Columns; k++)
    {
      if(Room[i][k] == 'z')
      {
        cout << "z location(x,y): " << k << ", " << i;
      }
    }
  }

      cout << endl;

  for(size_t i = 0; i < Rows; i++)
  {
    for (size_t k = 0; k < Columns; k++)
    {
      if(Room[i][k] == 'Z')
      {
        cout << "Z location(x,y): " << k << ", " << i;
      }
    }
  }
  cout << endl;

 //MAIN MOVEMENT CODE: Keeping track of player turns and creating movement options.

    if (currentPlayer == 3)
    {
      cout << "Human move" ;
      cout << endl;

  
      while(turn == 0)
      {

      cout << "input x: "; cin >> inputx;
      cout << "input y: "; cin >> inputy; cout << endl;

      cout << "Designated x: "; cin >> outputx; 
      cout << "Designated y: "; cin >> outputy; cout << endl;


        if(Room[inputx][inputy] != 'H')
        {
          cout << "invalid input!" << endl;
          turn = 0;
        }

        if(Room[outputx][outputy] != ' ')
        {
          cout << "You're trying to move through a wall!" << endl;
          turn = 0;
        }

        else if(Room[inputx][inputy] == 'H')
        {
          Room[inputx][inputy] = 0;
          Room[outputx][outputy] = 'H';
          turn = 1;
        }

      }
      currentPlayer = 1;
    }

    turn = 0; // reset turn to 0 so it doesnt re-loop the same while statement.
  
    if(currentPlayer == 1)
    {
      cout << "Zombie 1 move";
      cout << endl ;

      while(turn == 0)
      {

      cout << "input x: "; cin >> inputx;
      cout << "input y: "; cin >> inputy; cout << endl;

      cout << "Designated x: "; cin >> outputx; 
      cout << "Designated y: "; cin >> outputy; cout << endl;


        if(Room[inputx][inputy] != 'Z')
        {
          cout << "invalid input!" << endl;
          turn = 0;
        }

        if(Room[outputx][outputy] != ' ')
        {
          cout << "You're trying to move through a wall!" << endl;
          turn = 0;
        }

        else if(Room[inputx][inputy] == 'Z')
        {
          Room[inputx][inputy] = 0;
          Room[outputx][outputy] = 'Z';
          turn = 1;
        }

      }
      currentPlayer = 2;
    }

  turn = 0; // reset turn to 0 so it doesnt re-loop the same while statement.
    
   if(currentPlayer == 2)
    {
      cout << "Zombie 2 move";
      cout << endl;

      while(turn == 0)
      {

      cout << "input x: "; cin >> inputx;
      cout << "input y: "; cin >> inputy; cout << endl;

      cout << "Designated x: "; cin >> outputx; 
      cout << "Designated y: "; cin >> outputy; cout << endl;


        if(Room[inputx][inputy] != 'z')
        {
          cout << "invalid input!" << endl;
          turn = 0;
        }

        if(Room[outputx][outputy] != ' ')
        {
          cout << "You're trying to move through a wall!" << endl;
          turn = 0;
        }

        else if(Room[inputx][inputy] == 'z')
        {
          Room[inputx][inputy] = 0;
          Room[outputx][outputy] = 'z';
          turn = 1;
        }
      }

      currentPlayer = 3;
    }
    turn = 0; // reset turn to 0 so it doesnt re-loop the same while statement.
  }
}


int main()
{

  visualGrid();
  return 0;

}
