#include "FEHLCD.h"
#include <stdint.h>

#define X_MAX 319
#define Y_MAX 239
#define NEW_PISKEL_FRAME_COUNT 1

using namespace std;

void MenuStartUp();
void DisplayCredits();
void DisplayInstructions();
void PlayGame();
void DrawLevel(int);

class Stats {
    private:
        int battle, death;
    public:
        Stats();
        void DisplayStats();
};

int main() {

    //clearing screen
    LCD.Clear();

    //calling menu function to display menu
    MenuStartUp();
    
    return 0;
}


//this function displays the options in the menu
void MenuStartUp() {

    LCD.Clear();

    //declaring variables
    int x,y;
    Stats s;

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
                MenuStartUp();

            } else if ((y >= 70) && (y <= 110)){
                //displays stats
                LCD.Clear();
                s.DisplayStats();

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
}

//this is where gameplay would go
void PlayGame() {
    LCD.Clear();

    int level = 1;
    DrawLevel(level);

    while(1) {
    }

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

//constructor initializes default stats
Stats::Stats() {
    death = 0;
    battle = 0;
}

void Stats:: DisplayStats() {
    //clearing screen
    LCD.Clear();

    //displaying death stats
    LCD.Write("Deaths: ");
    LCD.Write(death);

    //displaying battle stats
    LCD.Write(", Battles: ");
    LCD.Write(battle);

    //drawing a back button for the player to go back to the menu
    LCD.DrawRectangle(0,(Y_MAX-20),50,20);
    LCD.WriteAt("BACK",5,(Y_MAX-15));
}

void DrawLevel(int level) {
    //making a switch case to determine background based on level

    switch (level) {
        case 4:
            //pepsiman level
            break;
        case 3:
            //Coffee level
            break;
        case 2:
            //Mexican grill level

            //drawing wall
            LCD.SetDrawColor(LCD.Red);
            LCD.FillRectangle(0,0,X_MAX,50); //will be replaced with drawings of cacti and chipotle peppers

            //drawing entrance
            LCD.SetDrawColor(LCD.White);
            for (int y = 70; y <= 103; y++) {
                LCD.DrawLine(297,y,X_MAX, (y-14));
            }
            //drawing exit
            LCD.SetDrawColor(LCD.White);
            for (int y = (Y_MAX - 34); y < Y_MAX; y++) {
                LCD.DrawLine(0,(y-14), (X_MAX - 297), y);
            }
            
            break;
        case 1: 
            //american traiditional level
            LCD.SetDrawColor(LCD.Red);
            LCD.FillRectangle(0,0,134,50);
            LCD.FillRectangle(184,0,(X_MAX-184),50);

            int y = 24;

            //drawing the wall

            for(int x = 134; x < 185; x++) {
                LCD.DrawLine(x,0,x,y);
                if (x <= 184 && x >= 162) {
                    y++;
                }
                else if (x >= 134 && x < 159) {
                    y--;
                }   
            }

            y = 24;
            for (int x = 184; x > 133; x--) {
                LCD.DrawLine(x,(50-y),x,49);

                if (x <= 184 && x > 161) {
                    y--;
                } 
                else if (x <= 159 && x >= 134) {
                    y++;
                }
            }

            LCD.SetDrawColor(LCD.White);
            LCD.FillCircle(159,10,25);

            //drawing the exit
            for (int y = 200; y <= 233; y++) {
                LCD.DrawLine(297,y,X_MAX,(y-14));
            }

            //drawing the entrance
            for (int y = 78; y <= 111; y++) {
                LCD.DrawLine(0,(y-14),(X_MAX - 297), y);
            }

            break;
    }
}
