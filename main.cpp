#include <iostream>
#define MINI_CASE_SENSITIVE
#include "src/mini/ini.h"
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
#include <iomanip>
using namespace std;
#include <stdlib.h>
#include <map>
#include <random>

vector<int> shots;

int generateNumber(int maxValue){
    random_device rdev;
    mt19937 rgen(rdev());
    uniform_int_distribution<int> idist(1, maxValue); //(inclusive, inclusive)
    return idist(rgen);
}

int swapNumber(string letter){
  return (int)letter[0] - 96;
}

void fire(){
  cin.ignore();
  cout << "Where would you like to fire (eg a2 lowercase): ";
  string temp;
  getline(cin,temp);
  shots.push_back(swapNumber(temp));
}

class Ship{
  private:
	  //Ship name
     string name;
	  //Total points on the grid
  	int length;
	  //Coordinates of those points
    int x;
    int y;
    vector <int> posX;
    vector <int> posY;
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
      vector<int> getPosX(){
        if(direction=="right"){
          for(int n = 0; length > n; n++){
            int temp = x+n;
            posX.push_back(temp);
          }
        }
        if(direction=="up"){
          for(int n = 0; length > n; n++){
            int temp = x;
            posX.push_back(temp);
          }
        }
        if(direction=="down"){
          for(int n = 0; length > n; n++){
            int temp = x;
            posX.push_back(temp);
          }
        }
        if(direction=="left"){
          for(int n = 0; length > n; n++){
            int temp = x-n;
            posX.push_back(temp);
          }
        }
        return posX; 
      }
      vector<int> getPosY(){
        if(direction=="up"){
          for(int n = 0; length > n; n++){
            int temp = y-n;
            posY.push_back(temp);
          }
        }
        if(direction=="down"){
          for(int n = 0; length > n; n++){
            int temp = y+n;
            posY.push_back(temp);
          }
        }
        if(direction=="left"){
          for(int n = 0; length > n; n++){
            int temp = y;
            posY.push_back(temp);
          }
        }
        if(direction=="right"){
          for(int n = 0; length > n; n++){
            int temp = y;
            posY.push_back(temp);
          }
        }
        return posY; 
      }
  };
int boardDraw(int x, int y,vector<Ship> ships){
  cout << "\n";
  int maxX = 0;
  int tempX;
  int tempY;
  cout << "A    B    C    D    E    F    G    H    I    J    K\n";
  for (int z = 0; z < y; z++){
    for (int i = 0; i < x+1; i++){
      if ((y == 0) && (i != 0)) {
        cout << "-----";
        if (maxX < i){
          maxX = i;
        }
      }
      if (y != 0){
        for(int p = 0; p<ships.size(); p++){
          vector<int> posX = ships[p].getPosX();
          vector<int> posY = ships[p].getPosY();
          for(int k = 0; k<posX.size(); k++){
            for(int b = 0; b<posY.size(); b++){
              tempX = posX[k];
              tempY = posY[b]-1;
              if(tempX==i){
                if(tempY==z){
                  cout << ships[p].getName().at(0);
                  cout <<setw(4) << "|";
                  i++;
                }
              }
            }
          }
        }
          // tempY = ships[n].getY()-1;
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
  string input;
  string inputDirection;
  vector <Ship> ships;
  cout << "Would you like to autoplace your ships(y/n): ";
  cin >> input;
  if(input=="n"){
    for(auto read : ini["Boats"]){
      cin.ignore();
      Ship temp;
      temp.setName(read.first);
      temp.setLength(stoi(read.second));
      cout << "Where would you like to put your " << read.first << " \nX: ";
      cin >> inputX; 
      cout << "Y: ";
      cin >> inputY;
      for(int n = 0; n<ships.size(); n++){
        if(ships[n].getX()==inputX){
          if(ships[n].getY()==inputY){
            cout << "That postion is taken please try again\nX :";
            cin >> inputX; 
            cout << "Y: ";
            cin >> inputY;
          }
        }
      }
      temp.setY(inputY);
      temp.setX(inputX);
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
  if(input=="y"){
    for(auto read : ini["Boats"]){
      Ship temp;
      int tempX = generateNumber(9);
      int tempY = generateNumber(9);
      temp.setName(read.first);
      temp.setLength(stoi(read.second));
      temp.setX(tempX);
      temp.setY(tempY);
      if(tempX>5){
        temp.setDirection("left");
      }
      else if(tempY>5){
        temp.setDirection("up");
      }
      else{
        temp.setDirection("down");
      }
      vector<int> tempXVector = temp.getPosX();
      for(int i = 0; i<ships.size(); i++){
        vector<int> posXVector = ships[i].getPosX();
        for(int k = 0; k<tempXVector.size(); k++){
          for(int h = 0; h<posXVector.size(); h++){
            if(posXVector[h]==tempXVector[k]){
              // cout << "\n";
              // cout << temp.getName() << " Spawned on " << ships[i].getName();
                int tempX = generateNumber(9);
                int tempY = generateNumber(9);
            }
          }
        }
      }
      ships.push_back(temp);
      counter++;
      cout << "\nShip : " << temp.getName() << " placed at " << temp.getX() << temp.getY() << "\n";
  }
  boardDraw(x,y,ships);
  cout << "Are you happy with these placement?(y/n): ";
  string tempInput;
  cin >> tempInput;
  if(tempInput=="y"){
    fire();
  }
  if(tempInput=="n"){
    computerGame();
  }
  else{
    fire();
  }
  }
  else{
    cout << "Please enter either Y or N: ";
    computerGame();
  }
}
vector <Ship> enemyShips;
void enemyShips(){

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