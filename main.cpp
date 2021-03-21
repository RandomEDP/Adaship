#include <iostream>
#define MINI_CASE_SENSITIVE
#include "src/mini/ini.h"
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
#include <iomanip>
using namespace std;

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
      int getY(){
        return y;
      }
      int getX(){
        return x;
      }
      string getName(){
        return name;
      }
      string getDirection(){
        return direction;
      }
  };
int boardDraw(int x, int y,vector<Ship> ships){
  cout << "\n";
  int maxX = 0;
  for (int z = 0; z < y; z++){
    for (int i = 0; i < x+1; i++){
      if ((y == 0) && (i != 0)) {
        cout << "-----";
        if (maxX < i){
          maxX = i;
        }
      }
      if (y != 0){
        for(int n = 0; n< ships.size(); n++){
          if(ships[n].getX()==i){
            if(ships[n].getY()==z){
              cout << "X";
            }
          }
        }
        if (i == 0){
          cout << "|";
        }else{
          cout <<setw(5) << "|";
        }
      }
    }
    cout << "\n";
  }
  for (int i = 0; i < maxX; i++){
    cout << "-----";
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


  cout << "You have choosen a computer game\n";
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
    cin.ignore();
    cout << "What direction would you like (right,left,down,up): ";
    // getline(cin,inputDirection);
    cin >> (inputDirection);
    if(inputDirection=="right"){
      temp.setDirection(inputDirection);
    }
    else if(inputDirection=="left"){
      temp.setDirection(inputDirection);
    }
    else if(inputDirection=="down"){
      temp.setDirection(inputDirection);
    }
    else if(inputDirection=="up"){
      temp.setDirection(inputDirection);
    }
    else{
      cout << "Please type right left down or up: ";
      cin >> inputDirection;
      }
    ships.push_back(temp);
    counter++;
    temp.getName();
    temp.getDirection();
    
  }
  boardDraw(x,y,ships);

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