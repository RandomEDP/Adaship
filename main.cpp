#include <iostream>
#define MINI_CASE_SENSITIVE
#include "src/mini/ini.h"
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
#include <iomanip>
using namespace std;

int boardDraw(int x, int y){
  int maxX = 0;
  for (int z = 0; z < y; y++){
    for (int i = 0; i < x+1; i++){
      if ((y == 0) && (i != 0)) {
        std::cout << "-----";
        if (maxX < i){
          maxX = i;
        }
      }
      if (y != 0){
        if (i == 0){
          std::cout << "|";
        }else{
          std::cout <<setw(5) << "|";
        }
      }
    }
    std::cout << "\n";
  }
  for (int i = 0; i < maxX; i++){
    std::cout << "-----";
  }
  return 1;
}

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
        void setX(int xIn){
          x = xIn;
        }
        void setY(int yIn){
          y = yIn;
        }
        void setDirection(string input){
          direction = input;
        }
        string getName(){
          return name;
        }
        
  };
  cout << "You have choosen a computer game\n";
  int board[x][y]; // Two-dimensional array for gameboard.
  int counter = 0;
  int inputX;
  int inputY;
  string inputDirection;
  vector <Ship> ships;
  for(auto read : ini["Boats"]){
    cin.ignore();
    Ship temp;
    temp.setName(read.first);
    temp.setLength(stoi(read.second));
    cout << "Where would you like to put your " << read.first << " \nX: ";
    cin >> inputX; 
    temp.setX(inputX);
    cout << "Y: ";
    cin >> inputY;
    temp.setY(inputY);
    cout << "What direction would you like (right,left,down,up): ";
    getline(cin,inputDirection);
    ships.push_back(temp);
    counter++;
  }
  boardDraw(x, y);

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
    cout << "Please type 1 or 2\n";
    menu();
  }
}

int main() {
  menu();
}