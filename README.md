# AdaShip
Adaship is a game of battleships made in C++.

# UML Diagram
![UML Diagram](diagrams/uml.png)

# Breakdown of Tasks to complete
Create a main-menu system
Pull in data from .ini file, as a cofiguration for the whole game
Create a number input system that verifies the users response (check validation)
Create a character input system for further validation
Create new ship based on the users input coordinates
Create a random x and y chooser for the computer player / auto place function
Implement the auto-place function for the AI player
Create new menu system now with turn based prompts
Print both the board to attack, and my own board
Collect another coordinate from the users
Notify if this is a hit or a miss, printing this within the of the other players board (where you're shooting) 
  (Shows on the board as specific icon with colors)
Have an auto-fire option using the auto-select function
Validate again to ensure shots are not wasted on the same already shot at location
Notify where the user has been shot, through their board
Have options to "quit game" and "end turn".
After every turn check if all ships have been destroyed
Go back to main-menu when game is complete.

# Housekeeping
- [x] Refactor code, ensuring there is no duplicate.
    - [x] If there is duplicate, see where it is best to be stored, and use OOP functionality.
- [x] Remove any "code smells", ensuring code is easy and efficient
- [x] Ensure the code is well commented, explaining what classes/functions/code does within the software. Make it readable, as if a document were to be made from it and you can understand the whole project through this C++ comment doc.
