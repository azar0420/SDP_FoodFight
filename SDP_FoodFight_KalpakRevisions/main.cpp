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
    MenuStartUp();
    while (1){
        //stores position coordinates of click
        while (!LCD.Touch(&x, &y)) {
         }
        //Detection of user clicks on each of the 4 options: play game, view stats, view instructions, view credits
        if ((x >= 100) && (x <= 250)){
            if ((y >= 20) && (y<= 60)){
                LCD.Clear();
                //play game
                PlayGame();

            } else if ((y >= 70) && (y <= 110)){
                //displays stats
                LCD.Clear();
                DisplayStats();

                //Detects second click by user for back button
                while (!LCD.Touch(&x, &y)) {
                }
                //Returns to main menu in the event that the user clicks on back button
                if (((x >= 0) && (x <= 50)) && ((y >= (Y_MAX - 20)) && (y <= Y_MAX))){
                    LCD.Clear();
                    MenuStartUp();
                }

            } else if ((y >= 120) && (y <= 160)){
                //displays instructions for game
                DisplayInstructions();
                //Detects second click by user for back button
                while (!LCD.Touch(&x, &y)) {
                }
                //Returns to main menu in the event that the user clicks on back button
                if (((x >= 0) && (x <= 50)) && ((y >= (Y_MAX - 20)) && (y <= Y_MAX))){
                    LCD.Clear();
                    MenuStartUp();
                }

            } else if ((y >= 170) && (y <= 210)){
                //displays credits for game
                DisplayCredits();
                //Detects second click by user for back button
                while (!LCD.Touch(&x, &y)) {
                }
                //Returns to main menu in the event that the user clicks on back button
                if (((x >= 0) && (x <= 50)) && ((y >= (Y_MAX - 20)) && (y <= Y_MAX))){
                    LCD.Clear();
                    MenuStartUp();
                }
            }
        }
    }
    return 0;
}

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