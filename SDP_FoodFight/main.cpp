#include "FEHLCD.h"

#define X_MAX 319
#define Y_MAX 239

using namespace std;

void MenuStartUp();
void DisplayCredits();
void DisplayInstructions();
void PlayGame();

class Stats {
    private:
        int battle, death;
    public:
        Stats();
        void DisplayStats();
};

int main() {
    int x, y;
    Stats s;
    LCD.Clear();

    s.DisplayStats(); //TEST

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

    LCD.WriteAt("Play game here", 150, 150);
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

//constructor sets values to 0 by default
Stats::Stats() {
    death = 0;
    battle = 0;
}

void Stats:: DisplayStats() {
    //clearing screen
    LCD.Clear();

    //displaying death
    LCD.Write("Deaths: ");
    LCD.Write(death);

    //displaying battles
    LCD.Write(", Battles: ");
    LCD.Write(battle);
}
