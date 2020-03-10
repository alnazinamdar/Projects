#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>

char colorArr[4] = {'O', 'R', 'G', 'B'};
char colorRes[10];
int t = rand()% 4;

void Randomizer(int x)
{
  int i;
  for(i = 0; i < x; i++)
  //applying random color to each peice of arr
  {
    colorRes[i] = colorArr[rand() % 4];
    cout << colorRes[i] << " ";
    //display colors to make sure its correct
    

  }
}

void startCheck(int x2)
{
  int grape = 0;
  int i;
  for(i = 0; i < x2; i++)
  {
    if(i >= 3 && (colorRes[i] == colorRes[i - 1]) && (colorRes[i - 1] == colorRes[i - 2]))
    {
      // int c = i - 2 + rand()% 4;
      // t = (t + rand()% 3 +1) % 4;
      // colorRes[i] = colorArr[rand()% 3];
      colorRes[i] = colorArr[rand()% 4];
      
      grape = grape + 1;

    }

    cout << colorRes[i] << " ";
  }
  cout << endl;
  cout << "Times swapped: " << grape;
}

void pattFinder(int x3)
{
  int counter = 0;
  int i;
  for(i = 0; i < x3 - 3; i++)
  {
    if(colorRes[i] == colorRes[i + 1] && colorRes[i] == colorRes[i + 3])
    {
      counter = counter + 1;

    //cout << endl << "Position: " << i + 1 << ", Combo: " << colorRes[i];
    cout << endl << "Position: " << i + 1 << ", Combo: ";
      for(int combo = 0; combo < 4; combo++)
      {
        cout << colorRes[i + combo] << " ";
      }
    
    }
  }

  for(i = x3 - 1; i > 3; i--)
  {
    if(colorRes[i] == colorRes[i - 1] && colorRes[i] == colorRes[i - 3])
    {
      counter = counter + 1;

     // cout << endl << "Position Reverse: " << i + 1 << ", Combo: " << colorRes[i] << " ";
     cout << endl << "Position Reverse: " << i + 1 << ", Combo: ";
      for(int combo2 = 0; combo2 < 4; combo2++)
      {
        cout << colorRes[(i - 3) + combo2] << " ";
      }
      
    }
  }
  cout << endl;
  cout << "Hint: ";
  cout << counter << " ";
  
}


int main()
{
  srand(time(NULL));
  int x = 12;

  cout << "Before Swap: ";
  Randomizer(x);
  cout << endl;


  cout << endl;
  
  cout << "After swap:  ";
  startCheck(x);

  cout << endl;
  
  pattFinder(x);

  return 0;
}

