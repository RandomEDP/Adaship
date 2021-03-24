# The Problem
As part of this course I was assigned the prokect of creating the popular game battleships in c++. There was many game modes listed in the inital spec sheet so I knew I needed to make a ship class which would allow easy inheritance. This allowed me to store and access lots of infomation using getters and setters. It was at this point where I ran into issues with replit and my different files because of this I merged all of the files into a single C++ file, this fixed that issue. 

# Plan
I sat down and decided the first thing I needed to do was make a ship class and a vector to contain the ship class. This allowed me to use the same class for the enemy ships. This also allowed me to run simple checks to see if the ship was hit/destroyed and therefore see if the player had won. I then decided to find a libary which allowed easy reading of .ini files. I made and put this in the src file and it is reference at the top of all the files

#



# Task Lists
Create a main-menu system <br />
Pull in data from .ini file, as a cofiguration for the whole game <br />
Create a number input system that verifies the users response (check validation)<br />
Create a character input system for further validation<br />
Create new ship based on the users input coordinates<br />
Create a random x and y chooser for the computer player / auto place function<br />
Implement the auto-place function for the AI player<br />
Create new menu system now with turn based prompts<br />
Print both the board to attack, and my own board<br />
Collect another coordinate from the users<br />
Notify if this is a hit or a miss, printing this within the of the other players board (where you're shooting) <br />
  (Shows on the board as specific icon with colors)<br />
Have an auto-fire option using the auto-select function<br />
Validate again to ensure shots are not wasted on the same already shot at location<br />
Notify where the user has been shot, through their board<br />
Have options to "quit game" and "end turn".<br />
After every turn check if all ships have been destroyed<br />
Go back to main-menu when game is complete.<br />

# UML
https://docs.google.com/document/d/1qoILyG0YUlslBbqGbWmLkhv-bbJsZQtBMIt_64IM1hs/edit?usp=sharing