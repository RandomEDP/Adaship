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
int x;
int y;
bool win;
int counter;
//this generates a random number with a max value that is passed in
int generateNumber(int maxValue){
    random_device rdev;
    mt19937 rgen(rdev());
    uniform_int_distribution<int> idist(1, maxValue); //(inclusive, inclusive)
    return idist(rgen);
}
//this gets a char and changes it to an interger value
int swapNumber(char letter){
  // cout << (int)letter - 96;
  return (int)letter - 96;
}

char swapLetter(int number){
  return(char)number + 96;
}


//this sets up a struct to work with getters and setters
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
    int health;
    public:
      bool destroyed = false;
      bool collison = false;
      //These are getters and setters to obtain the private vars
      void setHealth(){
        health = length;
      }
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
      void setPosX(vector<int> tempPosX){
        tempPosX = posX;
      }
      void setPosY(vector<int> tempPosY){
        tempPosY = posY;
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
      int getLength(){
        return length;
      }
      void clearPosX(){
        posX.clear();
      }
      void clearPosY(){
        posY.clear();
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
vector <Ship> ships;
vector <Ship> enemyShips;
//this function draws the board using for loops
//the params 
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
//this function autoplaces the ships the commeted code is extra valadtion changes
void autoplace(){
  // first, create a file instance
  mINI::INIFile file("adaship_config.ini");
  // next, create a structure that will hold data
  mINI::INIStructure ini;
  // now we can read the file
  file.read(ini);
  int x = stoi(ini["Board"]["x"]);
  int y = stoi(ini["Board"]["y"]);
      for(auto read : ini["Boats"]){
      Ship temp;
      int tempX = generateNumber(x-1);
      int tempY = generateNumber(y-1);
      temp.setX(tempX);
      temp.setY(tempY);
      temp.setName(read.first);
      temp.setLength(stoi(read.second));
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
      vector<int> tempYVector = temp.getPosY();
      for(int i = 0; i<ships.size(); i++){
        vector<int> posXVector = ships[i].getPosX();
        vector<int> posYVector = ships[i].getPosY();
          for(int h = 0; h<posXVector.size(); h++){
            for(int o = 0; o<posYVector.size(); o++){
              for(int l=0; l<tempXVector.size();l++){
                for(int r=0; r<tempYVector.size();r++){
                if(posXVector[h]==tempXVector[l]){
                  if(posYVector[o]==tempYVector[r]){
                    // autoplace();
                    // cout<<"\nnew";
                    // return;

                }
              } 
              }
              }
           }
          }
      }
      if(tempX>5){
        temp.setDirection("left");
      }
      else if(tempY>5){
        temp.setDirection("up");
      }
      else{
        temp.setDirection("down");
      }

      ships.push_back(temp);
      // cout << "\nShip : " << temp.getName() << " placed at " << temp.getX() << temp.getY() << "\n";
      
  }
}
//this autoplaces all of the enemy ships into a vector
void enemyplace(){
  // first, create a file instance
  mINI::INIFile file("adaship_config.ini");

  // next, create a structure that will hold data
  mINI::INIStructure ini;

  // now we can read the file
  file.read(ini);
  int x = stoi(ini["Board"]["x"]);
  int y = stoi(ini["Board"]["y"]);
      for(auto read : ini["Boats"]){
      Ship temp;
      int tempX = generateNumber(x-1);
      int tempY = generateNumber(y-1);
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

     enemyShips.push_back(temp);
      // cout << "\nShip : " << temp.getName() << " placed at " << temp.getX() << temp.getY() << "\n";
  }
}
void enemyFire(){
  vector <int> xShot;
  vector <int> yShot;
  xShot.push_back(generateNumber(x-1));
  yShot.push_back(generateNumber(y-1));
  cout << "\nEnemy shot at " << swapLetter(generateNumber(y-1)) <<generateNumber(x-1) << " it missed\n";
}
//this allows the user to shot and comapres it with the enemy ships
void fire(){
  int xShot;
  int yShot;
  cout << "\nENEMY SHIPS\n";
  boardDraw(x,y,enemyShips);
  cout << "Would you like to autofire(y/n): ";
  string inputTemp;
  cin >> inputTemp;
  if(inputTemp=="y"){
    xShot =generateNumber(9);
    cout << "You shot at " << swapLetter(xShot) << generateNumber(10);
  }
  else if (inputTemp=="n"){
  cin.ignore();
  cout << "\nWhere would you like to fire (eg a2 lowercase): ";
  string temp;
  cin >> temp;
  char letter = temp[0];
  char number = temp[1];
  xShot = swapNumber(letter);
  yShot = int(number);
  }
  shots.push_back(xShot);
  for(int n = 0; n<enemyShips.size();){
    vector <int> temp = enemyShips[n].getPosX();
    for(int g = 0; g<enemyShips[n].getPosX().size(); g++){
      for(int k = 0; k<enemyShips[n].getPosY().size(); k++){
        if(xShot==enemyShips[n].getPosX()[g]){//check if shot hit enemy
          cout << "Hit";
          if(enemyShips[n].getLength()==1){
            cout<<"Entered Loop";
            enemyShips[n].setX(100);
            enemyShips[n].setY(100);
            enemyShips[n].clearPosX();
            enemyShips[n].clearPosX();
            enemyShips[n].getPosX();
            enemyShips[n].getPosY();
            cout << "\nDestroyed " << enemyShips[n].getName();
            enemyShips[n].destroyed = false;
            counter++;
          }
          if(counter==enemyShips.size()){
            cout<< "\n\n\n\nYou won\n\n";//win conditon
            win = true;
            break;
          }
          else if(enemyShips[n].getLength()>=2){
            enemyShips[n].clearPosX();
            enemyShips[n].clearPosY();
            enemyShips[n].setLength(enemyShips[n].getLength()-1);
            enemyShips[n].getPosX();       
          }   
          if(yShot==enemyShips[n].getPosY()[k]){
            cout<<"HIT";
          }
        }
        else{
        }
        n++;
      }
    }
  }
}
void computerGame(){
  // first, create a file instance
  mINI::INIFile file("adaship_config.ini");

  // next, create a structure that will hold data
  mINI::INIStructure ini;

  // now we can read the file
  file.read(ini);

  x = stoi(ini["Board"]["x"]);
  y = stoi(ini["Board"]["y"]);


  cout << "You have choosen a computer game\n";
  int counter = 0;
  int inputX;
  int inputY;
  string input;
  string inputDirection;
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
    autoplace();
    boardDraw(x,y,ships);
    cout << "Are you happy with these placement?(y/n): ";
    string tempInput;
    cin >> tempInput;
    if(tempInput=="y"){
      
    }
    if(tempInput=="n"){
      ships.clear();
      computerGame();
    }
  else{
    
    }
  }
  else{
    cout << "Please enter either Y or N: ";
    computerGame();
  }
}

void menu(){
  int value;
  cout << "Welcome to Adaship!\n";
  cout << "1. One player v computer game\n";
  cout << "2. Quit\n";
  cin >> value;
  enemyplace();
  if(value==1){
    computerGame();
    //main game loop
    while(win!=true){
      fire();
      enemyFire();
    }

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

