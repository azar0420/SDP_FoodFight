#include "FEHLCD.h"

#define X_MAX 319
#define Y_MAX 239

void MenuStartUp();
void DisplayStats(); //this function will be rewritten such that it's suitable for a class variable
void DisplayCredits();
void DisplayInstructions();
void PlayGame();

int main() {
    int x, y;
    LCD.Clear();

    PlayGame();
    while (!LCD.Touch(&x, &y)) {
        // Run forever
    }
    return 0;
}


//this function displays the options in the menu
void MenuStartUp() {
    
    //play game option
    LCD.DrawRectangle(100,20, 150, 40);
    LCD.WriteAt("Play Game", 110, 25);

    //view stats option
    LCD.DrawRectangle(100,70,150,40);
    LCD.WriteAt("View Statistics", 110, 75);

    //view instructions option
    LCD.DrawRectangle(100,120,150,40);
    LCD.WriteAt("View Instructions", 110, 125);

    //view credits option
    LCD.DrawRectangle(100,170, 150,40);
    LCD.WriteAt("View Credits", 110, 175);
}

void PlayGame() {
    LCD.Clear();

    LCD.WriteAt("I lost the game", 150, 150);
}

//this function displays the stats of the player
void DisplayStats() {
    //clears the screen
    LCD.Clear();

    LCD.WriteAt("Stats TBD", (X_MAX/2),(Y_MAX/2));

    //drawing a back button for the player to go back to the menu
    LCD.DrawRectangle(0,(Y_MAX-20),50,20);
    LCD.WriteAt("BACK",5,(Y_MAX-15));
}

void DisplayInstructions() {
    //clearing the screen
    LCD.Clear();

    LCD.WriteAt("1: Use keys to move around", 0,0);
    LCD.WriteAt("2: Battle bosses to advance levels", 0 ,30);
    LCD.WriteAt("3: Don't let your HP go to zero!", 0, 60);
    LCD.WriteAt("4: HAVE FUN!", 0,90);

    //drawing a back button for the player to go back to the menu
    LCD.DrawRectangle(0,(Y_MAX-20),50,20);
    LCD.WriteAt("BACK",5,(Y_MAX-15));
}

//this function displays credits if user selects 4th option
void DisplayCredits() {
    
    //clearing the screen
    LCD.Clear();

    //writing the credits to the screen
    LCD.WriteLine("Thanks to OSU's FEH Department");
    LCD.WriteAt("Developer: Nelly Azar", 0,50);
    LCD.WriteAt("Developer: Kalpak Duddella", 0,70);
    LCD.WriteAt("Developer: Phillip Becker", 0,90);

    //drawing a back button for the player to go back to the menu
    LCD.DrawRectangle(0,(Y_MAX-20),50,20);
    LCD.WriteAt("BACK",5,(Y_MAX-15));
}
