#include "FEHLCD.h"

#define X_MAX 319
#define Y_MAX 239

void MenuStartUp();
void DisplayStats(); //this function will be rewritten such that it's suitable for a class variable
void PlayGame(); //to be rewritten into class after menu check
void DisplayCredits();
void DisplayInstructions();

int main() {
    int x, y;
    LCD.Clear();
    //LCD.WriteLine("Hello World!");
    //MenuStartUp();
    LCD.DrawRectangle(0,(Y_MAX-20),50,20);
    LCD.WriteAt("BACK",5,(Y_MAX-15));
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
    //clears the screen
    LCD.Clear();

    LCD.WriteLine("\nI lost the game...");
}

//this function displays the stats of the player
void DisplayStats() {
    //clears the screen
    LCD.Clear();

    LCD.WriteLine("\nMean, median, and mode are pretty funky huh?");
    LCD.WriteLine("\nShoutouts to you AP Stats");
    LCD.WriteLine("\nActual stats TBD hahaha");

    //drawing a back button for the player to go back to the menu
    LCD.DrawRectangle(0,(Y_MAX-20),50,20);
    LCD.WriteAt("BACK",5,(Y_MAX-15));
}

void DisplayInstructions() {

    //clearing the screen
    LCD.Clear();

    LCD.WriteLine("\nChicken, burgers, mexican grill, asian takeout\n");
    LCD.WriteLine("\nLong ago, the four restaurants lived in harmony\n");
    LCD.WriteLine("\nThen everything changed when the ??? nation attacked\n"); //ill figure it out later
    LCD.WriteLine("\nOnly the Pepsiman, master of all restaurants, could stop them\n");
    LCD.WriteLine("\nA hundred years passed and a new pepsiman has been discovered\n");
    LCD.WriteLine("\nAnd although his Pepsi skills are great, he still has a lot to learn\n");
    LCD.WriteLine("But I believe Pepsiman can save the restaurant world");

    //drawing a back button for the player to go back to the menu
    LCD.DrawRectangle(0,(Y_MAX-20),50,20);
    LCD.WriteAt("BACK",5,(Y_MAX-15));
}

//this function displays credits if user selects 4th option
void DisplayCredits() {
    
    //clearing the screen
    LCD.Clear();

    //writing the credits to the screen
    LCD.WriteLine("In collaboration with OSU's FEH Department\n");
    LCD.WriteLine("\nDevelopers: Nelly Azar, Kalpak Duddella, Phillip Becker");

    //drawing a back button for the player to go back to the menu
    LCD.DrawRectangle(0,(Y_MAX-20),50,20);
    LCD.WriteAt("BACK",5,(Y_MAX-15));
}
