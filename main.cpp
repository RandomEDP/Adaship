#include <iostream>
#define MINI_CASE_SENSITIVE
#include "src/mini/ini.h"
using namespace std;

void computerGame(){
  // first, create a file instance
  mINI::INIFile file("adaship_config.ini");

  // next, create a structure that will hold data
  mINI::INIStructure ini;

  // now we can read the file
  file.read(ini);

  int x = stoi(ini["Board"]["x"]);
  int y = stoi(ini["Board"]["y"]);

  class Ship{
    private:
	    //Ship name
	    string name;
	    //Total points on the grid
  	  int length;
	    //Coordinates of those points
      int x;
      int y;
      string direction;

      public:
        void setName(string n){
          name = n;
        }
        void setLength(int l){
          length = l;
        }

  };
  cout << "You have choosen a computer game\n";
  int board[x][y]; // Two-dimensional array for gameboard.
  int counter = 0;
  for (auto const& it : ini){
	  auto const& collection = it.second;
	  for (auto const& it2 : collection){
		  auto const& key = it2.first;
      Ship ship[counter];
      ship[counter].setName(key);
      // string length = ini["Boats"][key];
      // int test = stoi(length);
      // ship[counter].setLength(test);
      cout << "Where would you like to place your " << key;
	  }
  }
}

void menu(){
  int value;
  cout << "Welcome to Adaship!\n";
  cout << "1. One player v computer game\n";
  cout << "2. Quit\n";
  cin >> value;
  if(value==1){
    computerGame();
  }
  else if(value==2){
    quick_exit(1);
  }
  else{
    cout << "Please type 1 or 2";
    menu();
  }
}

int main() {
  menu();
}