#include "FEHLCD.h"

#define X_MAX 319
#define Y_MAX 239

void MenuStartUp();
void DisplayCredits();

int main() {
    int x, y;
    LCD.Clear();
    //LCD.WriteLine("Hello World!");
    MenuStartUp();
    while (!LCD.Touch(&x, &y)) {
        // Run forever
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

void DisplayCredits() {
    LCD.Clear();

    LCD.WriteLine("In collaboration with OSU's FEH Department\n");
    LCD.WriteLine("\nDevelopers: Nelly Azar, Kalpak Duddella, Phillip Becker");
}
