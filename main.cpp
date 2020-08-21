#include <iostream>
#include <vector>
#include <limits>
#include <locale>
using namespace std;

void displayBoard (string b [][4]);
void shuffleArray (string x [][4]);
void userSelect (string b [][4]);

int main() 
{
   srand(time(0));
  string board [][4] = {{"aa","ab","ac","ad"},
                        {"ba","bb","bc","bd"},
                        {"ca","cb","empty","cd"},
                        {"da","db","dc","dd"}
                      };

  displayBoard(board);
  shuffleArray(board);
  cout << "The board after shuffle :\n";
  displayBoard(board);

  userSelect (board);

}

void displayBoard (string b [][4])
{
  int counter = 1;
  for (int i=0; i<4; i++)
  {
    for (int j=0; j<4; j++)
    {
      if (b[i][j]=="empty")
      {
        cout << "Empty\t ";
        counter++;
      }
      else
      {
        cout << counter << "\t\t ";
        counter++;
      }
      
    }
    cout << endl;
  }
}

void shuffleArray (string x [][4])
{
  vector<string> board;
  board = {"aa", "ab", "ac", "ad","ba", "bb", "bc", "bd","ca", "cb", "empty", "cd", "da", "db", "dc", "dd"};
  
  for (int i=0; i<4; i++)
  {
    for (int j=0; j<4; j++)
    {
      int randomIndex = rand()%board.size();
      x[i][j] = board[randomIndex];
      board.erase(board.begin()+randomIndex);
    }
  }
}

void userSelect (string b [][4])
{
  cout << "Select a number from the board :\n";
  int num;
  cin >> num; // getting the number from the user - the number is displayed on the board

  while (cin.fail()||num>16||num<1) // checking the validity of the input
  {
    cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Wrong input. Select a number from the board :\n";
    cin >> num;
  }
  int x,y; //local variables for the coordinates
  if (num>=1 && num<=4) //first row
  {
    x=0;
    y = num-1;
  }
  else if(num>=5 && num<=8) //2nd row
  {
    x=1;
    y = num-5;
  }
  else if(num>=9 && num<=12) //3rd row
  {
    x=2;
    y=num-9;
  }
  else if(num>=13 && num<=16) //4th row
  {
    x=3;
    y=num-13;
  }

  //information for the coordinate of the number input by the user
  cout << "You have selected : " << num << endl;
  cout << "The coordinate is : " << x << " " << y << endl;


  //checking adjacent
  if (x>0 && b[x-1][y]=="empty") //when the empty is on the left
  {
    cout << num << " is adjacent to the empty space";
  }
  else if (x<4 && b[x+1][y]=="empty") //when the empty is on the right
  {
    cout << num << " is adjacent to the empty space";
  }
   else if (y>0 && b[x][y-1]=="empty") //when the empty is on the top
  {
    cout << num << " is adjacent to the empty space";
  }
   else if (y<4 && b[x][y+1]=="empty") //when the empty is on the bottom
  {
    cout << num << " is adjacent to the empty space";
  }
  else if (b[x][y]=="empty") //when the number input is the empty space
  {
    cout << "You have selected the empty space";
  }
  else //except the above conditions - no adjacent to the empty space
  {
    cout << "The number that you selected is not adjacent to the empty space!";
  }
}

