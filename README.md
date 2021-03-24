# The Problem
As part of this course I was assigned the prokect of creating the popular game battleships in c++. There was many game modes listed in the inital spec sheet so I knew I needed to make a ship class which would allow easy inheritance. This allowed me to store and access lots of infomation using getters and setters. It was at this point where I ran into issues with replit and my different files because of this I merged all of the files into a single C++ file, this fixed that issue. 

# Plan
I sat down and decided the first thing I needed to do was make a ship class and a vector to contain the ship class. This allowed me to use the same class for the enemy ships. This also allowed me to run simple checks to see if the ship was hit/destroyed and therefore see if the player had won. I then decided to find a libary which allowed easy reading of .ini files. I made and put this in the src file and it is reference at the top of all the files

# Devlopment
During devlopment in decided to make one autoplace function to and then used that for both the enemy auto place but it also served as a way to allow the user to autoplace if they did not want to place them manually. I used a sprint board and each few hours would check how many tasks I had done and see if I was on track. Partly the way through I saw I would not have time to finish the other games so I decieded to focus more of my time on the valdation and general bug fixes on the main game mode. Each time I pushed changes I would throughly test to make sure it worked and if I had a  challenging bug I would use cout statments to find the issue and then work from there because replit does not have a debugger tool. 

# Evaluation
In evaluation I could of worked on refactoring my code more as it all ended up in a single file because of a bug from replit and I transferred it from my IDE although this wasn't the most elegant it worked well and was efficent of my time. I used ‘advanced’ programming principles by using basing it all on the ship class and thus allowing me to use this many times which shorted the code. Although I run out of time and as such the ship placement can be a little buggy and if I had more time I would of fixed this, however as it still works I decided to work on more pressing issues.

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