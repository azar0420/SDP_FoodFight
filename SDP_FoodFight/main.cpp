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
void Intro();
void DrawCharacter(char, int, int);

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

void Intro() {
    int x, y;
    LCD.Clear();

    LCD.SetDrawColor(LCD.Blue);
    LCD.DrawRectangle(0,0,X_MAX,50);
    LCD.WriteAt("Click anywhere to advance", 2,225);

    LCD.WriteAt("Long ago, fast food restaurants lived in", 5,10);
    LCD.WriteAt("harmony", 130,30);

    while (!LCD.Touch(&x,&y)) {
    }

    LCD.Clear();
    LCD.DrawRectangle(0,0,X_MAX,50);
    LCD.WriteAt("Click anywhere to advance", 2,225);

    LCD.WriteAt("And we enjoyed everything we could eat", 5, 25);

    while(!LCD.Touch(&x,&y)); {
        //runs until touched
    }

    LCD.Clear();
    LCD.DrawRectangle(0,0,X_MAX,50);
    LCD.WriteAt("Click anywhere to advance", 2,225);

    LCD.WriteAt("But ever since the revolution", 5,25);
    
    while(!LCD.Touch(&x,&y)); {
        //run until touched
    }

    LCD.Clear();
    LCD.DrawRectangle(0,0,X_MAX,50);
    LCD.WriteAt("Click anywhere to advance", 2,225);

    LCD.WriteAt("monsters have been poisoning our food", 5, 25);

    while(!LCD.Touch(&x,&y)); {
        //run until touched
    }

    LCD.Clear();
    LCD.DrawRectangle(0,0,X_MAX,50);
    LCD.WriteAt("Click anywhere to advance", 2,225);

    LCD.WriteAt("It's been hard for me, as Pepsiman, to", 5,2);
    LCD.WriteAt("fight them all", 125,30);

    while(!LCD.Touch(&x,&y)); {
        //run until touched
    }

    LCD.Clear();
    LCD.DrawRectangle(0,0,X_MAX,50);
    LCD.WriteAt("Click anywhere to advance", 2,225);

    LCD.WriteAt("and I need YOUR help to go to every", 5, 2);
    LCD.WriteAt("single restaurant", 125, 30);

    while(!LCD.Touch(&x,&y)); {
        //run until touched
    }

    LCD.Clear();
    LCD.DrawRectangle(0,0,X_MAX,50);
    LCD.WriteAt("Click anywhere to advance", 2,225);

    LCD.WriteAt("to defeat them all", 5, 2);

    while(!LCD.Touch(&x,&y)); {
        //run until touched
    }

    LCD.Clear();
    LCD.DrawRectangle(0,0,X_MAX,50);
    LCD.WriteAt("Click anywhere to advance", 2,225);

    LCD.WriteAt("What do you say? Can you help me out?", 5, 2);

    while(!LCD.Touch(&x,&y)); {
        //run until touched
    }

    LCD.Clear();
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
    LCD.Clear();
    //making a switch case to determine background based on level

    switch (level) {
        case 4:
            //pepsiman level

            //drawing wall outlines
            LCD.SetDrawColor(LCD.Blue);
            LCD.DrawLine(120,0,15,Y_MAX);
            LCD.DrawLine(X_MAX,0,297,50);
            LCD.DrawLine(100,50,297,50);
            LCD.DrawLine(297,50,297,Y_MAX);

            //drawing logo onto first wall
            LCD.SetDrawColor(LCD.Red);
            LCD.DrawLine(34,74,28,98);
            LCD.DrawLine(34,74,50,0);
            LCD.DrawLine(28,98,0,150);
            LCD.FillRectangle(0,0,28,98);

            //drawing entrance
            LCD.SetDrawColor(LCD.White);
            for (int y = 130; y <= 163; y++) {
                LCD.DrawLine(309,y,X_MAX,(y-14));
            }


            break;
        case 3:
            //pizza level

            //drawing italian flag
            LCD.SetDrawColor(LCD.Green);
            LCD.FillRectangle(200,0,10,30);
            LCD.SetDrawColor(LCD.White);
            LCD.FillRectangle(211,0,10,30);
            LCD.SetDrawColor(LCD.Red);
            LCD.FillRectangle(222,0,10,30);

            //drawing table
            LCD.SetDrawColor(LCD.Gray);
            LCD.FillRectangle(0,50,X_MAX,30);

            LCD.SetDrawColor(LCD.Blue);
            LCD.FillRectangle(30,0,100,34); //drawing menu

            //drawing everything that's white
            LCD.SetDrawColor(LCD.White);

            LCD.FillRectangle(0,35,X_MAX,20); //countertop

            //drawing the exit
            for (int y = 202; y <= 235; y++) {
                LCD.DrawLine(309,y,X_MAX,(y-14));
            }

            //drawing the entrance
            for (int y = 108; y <= 141; y++) {
                LCD.DrawLine(0,(y-14),(X_MAX - 309), y);
            }

            LCD.SetDrawColor(LCD.Black);
            LCD.DrawLine(0,54,X_MAX,54); //outline
            LCD.DrawLine(0,35,X_MAX,35); //outline

            //drawing pizza box
            LCD.DrawRectangle(180, 45, 50,10);
            LCD.DrawHorizontalLine(39,170,220);
            LCD.DrawLine(180,45,170,39);
            LCD.DrawLine(230,45,220,39);
            LCD.DrawVerticalLine(170,39,50);
            LCD.DrawLine(170,50,180,55);

            LCD.SetFontColor(LCD.White);
            LCD.WriteAt("CHEESE", 32, 5);
            LCD.WriteAt("PEPPERONI", 32, 20);

            break;
        case 2:
            //Mexican grill level

            //drawing wall
            LCD.SetDrawColor(LCD.Red);
            LCD.FillRectangle(25,0,100,39);
            LCD.FillRectangle(150,0,100,39);

            LCD.SetDrawColor(LCD.Green);
            LCD.FillCircle(260,20,6);
            LCD.FillRectangle(260,10,20,25);
            LCD.FillCircle(280,22,8);
            LCD.FillCircle(270,10,10);

            //drawing entrance
            LCD.SetDrawColor(LCD.White);
            for (int y = 90; y <= 123; y++) {
                LCD.DrawLine(309,y,X_MAX, (y-14));
            }
            //drawing exit
            LCD.SetDrawColor(LCD.White);
            for (int y = (Y_MAX - 34); y < Y_MAX; y++) {
                LCD.DrawLine(0,(y-14), (X_MAX - 309), y);
            }

            LCD.FillRectangle(0,35,X_MAX,20); //countertop where food is ordered from

            for (int i = 5; i < (X_MAX - 21); i += 50) {
                LCD.SetDrawColor(LCD.Black);
                LCD.DrawRectangle(i,38,20,10);
                if (i == 5) {
                    LCD.SetDrawColor(LCD.Green);
                }
                else if (i==55) {
                    LCD.SetDrawColor(LCD.Scarlet);
                }
                else if (i==105) {
                    LCD.SetDrawColor(LCD.White);
                }
                else if (i==155) {
                    LCD.SetDrawColor(LCD.Red);
                }

                LCD.FillRectangle((i+1), 39,19,9);
            }

            //drawing counter
            LCD.SetDrawColor(LCD.Gray);
            LCD.FillRectangle(0,50,X_MAX,30);
            LCD.SetDrawColor(LCD.Black);
            LCD.DrawLine(0,50,X_MAX,50); //outline
            LCD.DrawLine(0,35,X_MAX,35); //outline

            //Writing menu
            LCD.SetFontColor(LCD.Black);
            LCD.WriteAt("BURRITO", 30,2);
            LCD.WriteAt("TACO", 30,20);
            LCD.WriteAt("GUAC", 155, 2);
            LCD.WriteAt("SALSA", 155, 20);
            break;
        case 1:
            //american traiditional level
            LCD.SetDrawColor(LCD.Scarlet);
            LCD.FillRectangle(0,0,X_MAX,50);

            LCD.SetDrawColor(LCD.White);
            LCD.FillCircle(159,10,25);
            LCD.FillRectangle(20,0,70,40);

            //drawing the exit
            for (int y = 202; y <= 235; y++) {
                LCD.DrawLine(309,y,X_MAX,(y-14));
            }

            //drawing the entrance
            for (int y = 75; y <= 108; y++) {
                LCD.DrawLine(0,(y-14),(X_MAX - 309), y);
            }

            //drawing logo
            LCD.SetDrawColor(LCD.Blue);
            LCD.DrawVerticalLine(140,35,20); //end
            LCD.DrawLine(140,20,141,17); //m = 3
            LCD.DrawLine(141,17,143,14); //m = 3/2
            LCD.DrawLine(143,14,145,12); //m = 1
            LCD.DrawLine(145,12,149,10); //m = 1/2
            LCD.DrawHorizontalLine(10,149,151); //peak
            LCD.DrawLine(151,10,155,12); //m = 1/2
            LCD.DrawLine(155,12,157,14); //m = 1
            LCD.DrawLine(157,14,159,17); //m = 3/2
            LCD.DrawLine(159,17,160,20); //m = 3
            LCD.DrawVerticalLine(160,35,20); //midpoint
            LCD.DrawLine(160,20,161,17); //m = 3
            LCD.DrawLine(161,17,163,14); //m = 3/2
            LCD.DrawLine(163,14,165,12); //m = 1
            LCD.DrawLine(165,12,169,10); //m = 1/2
            LCD.DrawHorizontalLine(10,169,171); //peak
            LCD.DrawLine(171,10,175,12); //m = 1/2
            LCD.DrawLine(175,12,177,14); //m = 1
            LCD.DrawLine(177,14,179,17); //m = 3/2
            LCD.DrawLine(179,17,180,20); //m = 3
            LCD.DrawVerticalLine(180,35,20); //end

            //writing in menu
            LCD.SetFontColor(LCD.Black);
            LCD.WriteAt("~~~~ $1", 25,5);
            LCD.WriteAt("~~~~ $1", 25,25);

            break;
    }
}
void DrawCharacter(char characterselect, int x, int y) {
    if (characterselect == 'M') {
        LCD.SetDrawColor(LCD.Blue);
        LCD.DrawRectangle(x,y,11,11);

        LCD.SetDrawColor(LCD.Red);

        for (int i = x+1; i < x+10; i++){
            if (i == (x+1)|| i == (x+9)) {
                LCD.DrawLine(i,(y+10),i,(y+5));
                continue;
            }

            if (i == (x+3)|| i == (x+7)) {
                LCD.DrawLine(i,(y+1),i,(y+5));
                continue;
            }
            if (i == (x+5)) {
                LCD.DrawLine(i,(y+4), i, (y+9));
            }
            else {
                LCD.DrawLine(i,(y+2),i,(y+7));
                continue;
            }
        }


    }
    else if (characterselect == 'P') {
        //Pizza character
        LCD.SetDrawColor(LCD.White);
        LCD.FillRectangle(x,y,11,11);

        LCD.SetDrawColor(LCD.Red);
        LCD.DrawPixel((x+1), (y+5));
        LCD.DrawPixel((x+9), y+2);
        LCD.DrawPixel((x+5), (y+5));
        LCD.DrawPixel((x+8), y+7);
    }
    else if (characterselect == 'C') {
        //chipotle character
        LCD.SetDrawColor(LCD.Scarlet);

        LCD.FillRectangle(x,y,11,11);

        LCD.SetDrawColor(LCD.White);
        LCD.DrawLine((x+3),(y+3),(x+3),(y+7));
        LCD.DrawLine((x+5), (y+1), (x+7), (y+1));
        LCD.DrawLine((x+5),(y+9),(x+7),(y+9));
        LCD.DrawPixel((x+4),(y+2));
        LCD.DrawPixel((x+4),(y+8));
    }
}
