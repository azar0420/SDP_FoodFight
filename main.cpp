#include "FEHLCD.h"
#include "FEHRandom.h"
//definitions and functions
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>

//functions definitions will need to be removed when this is combined in main function

#include <thread>
#include <chrono>
#define block 10
#define leftborder 35
#define rightborder 284
#define topborder 35
#define downborder 35









//MAIN FUNCTION C1



#define X_MAX 319
#define Y_MAX 239
#define block 10
#define leftborder 35
#define rightborder 284
#define topborder 35
#define downborder 35
using namespace std;

void MenuStartUp();
void DisplayCredits();
void DisplayInstructions();
void PlayGame();
int RunLevel(int a, char m, HealthBar userhealth);
void DrawLevel(int a);
int Bossfight(int l);
void DrawCharacter(char m,int x, int y);
void HealthPotion(int num);

int* itemfunction(int L, int randitem)
char CharacterSelect();
int BossFight(int, HealthBar, char);//returns 1 for win and 0 for loss
void DrawBoss(char,int,int);
void Intro();
void PepsiBackstory();


class Stats {
    public:
        int battle, death;
        Stats();
        void DisplayStats();

};

int main() {

    //declaring variables
    int x, y;
    Stats s;

    //clearing screen
    LCD.Clear();

    //calling menu function to display menu
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
                PlayGame(s);

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

//this is where gameplay would go
//c15
void PlayGame(Stats st) {
    LCD.Clear();
    char character=CharacterSelect();
    int level=1;
    HealthBar uh;
    
    Intro();
    //running the levels
    level=RunLevel(level,character,uh));
    if(level!=0){
        st.battle++;
    }//end if statment
    level=RunLevel(level,character,uh));
    if(level!=0){
        st.battle++;
    }//end if statment
    level=RunLevel(level,character,uh));
    if(level!=0){
        st.battle++;
    }//end if statment
    level=RunLevel(level,character,uh));
    if(level!=0){
        st.battle++;
    }//end if statment

    //win lose
    if(level==5){
        LCD.WriteLine("You Won");
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    }
    if(level==0){
        LCD.WriteLine("You Lose");
        st.death++;
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
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











//run level C2

//function definitions soley here to help reduce errors


//various ints that will change

//function start


int RunLevel(int a, char m, HealthBar userhealth){
    //define variables
        int randitem= (rand() % 4) +1;
        
        //various int definition
        int level=a;
        int button=0;
        int userinput;
        int userinputx,userinputy;
        int hatchlocx,hatchlocy;
        char character=m;
    //randomly generates the location of the health potion. Health potion changes based on the level
    int *buttonarray;
    buttonarray=itemfunction(level,randitem);
    int buttonlocx=buttonarray[0];
    int buttonlocy=buttonarray[1];
    int characterlocx=160,characterlocy=120;
//conditional statement to skip if the level is zero
if(level!=0){

    //define hatch locations
     switch (level){

        case(1):
            hatchlocx=309;
            hatchlocy=188;
            characterlocx=10;
            characterlocy=80;
            break;
        case(2):
            hatchlocx=0;
            hatchlocy=191;
            characterlocx=310;
            characterlocy=80;
            break;
        case(3):
           hatchlocx=309;
           hatchlocy=188;
           characterlocx=10;
            characterlocy=100;
            break;
        case 4:
            hatchlocx=309;
            hatchlocy=116;
            characterlocx=309;
            characterlocy=116;
            break;
    }//end switch
    
    //start of the loop
    while(level==a){
        //has to redraw the level every click due to character movement
        DrawLevel(level);
        DrawCharacter(character,characterlocx,characterlocy);
        if (button!=1){
            LCD.SetDrawColor(LCD.Red);
            LCD.DrawCircle(buttonarray[0],buttonarray[1],5);
        }//draw button
        while (!LCD.Touch(&userinputx, &userinputy)) {
         }
        
         
        //begin movement button functions
        //moves character based on the edge of the screen the user clicks on
        if(userinputx<leftborder){
            if(characterlocx>(0+block)){
                characterlocx=characterlocx-block;
            }//left border
        }//left button
        if(userinputx>rightborder){
            if((characterlocx+10)<(X_MAX-block)){
                characterlocx=characterlocx+block;
            }//right border
        }//right button
        if(userinputy>downborder){
            if((characterlocy+10)<(Y_MAX-block)){
                characterlocy=characterlocy+block;
            }//down border
        }//down button
        if(userinput>topborder){
            if((characterlocy)>(0+block)){
                characterlocy=characterlocy-block;
            }//top border
        }//top button

        //end of character movement checks
        //health potion check
        if(((buttonlocx<characterlocx<buttonlocx+15)||(buttonlocx<characterlocx+10<buttonlocx+15))){
            if(((buttonlocy<characterlocy<buttonlocy+15)||(buttonlocy<characterlocy+10<buttonlocy+15))){
                if(button!=1){
                    button=1;
                    /*switch statement that will call 
                    the health potion function to add health based on the level*/
                    switch (level){
                        case 1:
                            userhealth.HealthPotion(15);
                             break;
                        case 2:
                            userhealth.HealthPotion(20);
                        case 3:
                            userhealth.HealthPotion(35);
                            break;
                        case 4:
                            userhealth.HealthPotion(45);
                            break;

                        default:
                             break;
                    }//end level check    
                }//buton check
            }//locy check
        }//locx check
        //hatch to end of level check
        if((hatchlocx<characterlocx<hatchlocx+15)||(hatchlocx<characterlocx+10<hatchlocx+15)){
            if((hatchlocy<characterlocy<hatchlocy+49)||(hatchlocy<characterlocy+10<hatchlocy+49)){
                int win;
                win=BossFight(level,userhealth, character);
                if(win==1){
                    level=level+1;
                    return level;
                }///end win
                else{
                    level=0;
                }//end lose
            }//end locy check
        }//end locx check
        if(level==4){
            std::this_thread::sleep_for(std::chrono::milliseconds(4000));
            PepsiBackstory();
            win=BossFight(level,userhealth, character);
                if(win==1){
                    level=level+1;
                    return level;
                }///end win
                else{
                    level=0;
                }//end lose
        }

    }//while level
}//end if level
}//end runlevel function


//item function C2
int* itemfunction(int L, int randitem){
    int arr[2];
    switch (randitem){

        case(1):
            arr[0]=50;
            arr[1]=100;
            LCD.DrawCircle(arr[0],arr[1],5);
            break;
        case(2):
            arr[0]=90;
            arr[1]=190;
            LCD.DrawCircle(arr[0],arr[1],5);
            break;
        case(3):
            arr[0]=200;
            arr[1]=100;
            LCD.DrawCircle(arr[0],arr[1],5);
            break;
        case 4:
            arr[0]=150;
            arr[1]-200;
            LCD.DrawCircle(arr[0],arr[1],5);
            break;
    }//end switch
    

}//end item function


//CHARACTER SELECT C3


char CharacterSelect(){

    //coordinates
    int a;
    int b;

    LCD.Clear();

    LCD.WriteAt("Choose starting character", 100, 20);

    LCD.DrawRectangle(100,70, 150, 40);
    LCD.WriteAt("McDonald's", 110, 75);

    
    LCD.DrawRectangle(100,120,150,40);
    LCD.WriteAt("Papa John's", 110, 125);

    
    LCD.DrawRectangle(100,170,150,40);
    LCD.WriteAt("Chipotle", 110, 175);

    while (!LCD.Touch(&a, &b)) {
     }

    if ((a >= 100)&&(a <= 250)){

        if ((b >= 70)&&(b <= 110)){

        //McDonald's character here

        return 'M';

        } else if ((b >= 120)&&(b <= 160)){
        
        //Pizza character here

        return 'P';

        } else if ((b >= 170)&&(b <= 210)){

        //Chipotle character here

        return 'C';

        }
    }
}

class HealthBar {
    public:
        int health;
        HealthBar();
        void DamageTaken(int dec);
        void HealthPotion(int inc);
};

HealthBar::HealthBar(){
    health = 0;

}

void HealthBar::DamageTaken(int dec){
    health -= dec;
}

void HealthBar::HealthPotion(int inc){
    health += inc;
}

void DrawBoss(char charactername, int x, int y){
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
    else if (charactername == 'Pe') {
        //Pepsi character
        LCD.SetDrawColor(LCD.White);
        LCD.FillRectangle(x,y,10,10);

        LCD.SetDrawColor(LCD.Red);
        LCD.DrawLine(x,y,x+10,y);
        LCD.DrawLine(x,y+1,x+9,y+1);
        LCD.DrawLine(x,y+2,x+7,y+2);
        LCD.DrawLine(x,y+3,x+6,y+3);
        LCD.DrawLine(x,y+4,x+5,y+4);
        LCD.DrawLine(x,y+5,x+4,y+5);
        LCD.DrawPixel(x,y+6);


       LCD.SetDrawColor(LCD.Blue);
       LCD.DrawLine(x,y+10,x+10,y+10);
       LCD.DrawLine(x+1,y+9,x+10,y+9);
       LCD.DrawLine(x+5,y+8,x+10,y+8);
       LCD.DrawLine(x+6,y+7,x+10,y+7);
       LCD.DrawLine(x+7,y+6,x+10,y+6);
       LCD.DrawPixel(x+10,y+5);



    }
    else if (charactername == 'C') {
        //chipotle character
        LCD.SetDrawColor(LCD.Scarlet);

        LCD.FillRectangle(x,y,11,11);

        LCD.SetDrawColor(LCD.White);
        LCD.DrawLine((x+3),(y+3),(x+3),(y+7));
        LCD.DrawLine((x+5), (y+1), (x+7), (y+1));
        LCD.DrawLine((x+5),(y+9),(x+7),(y+9));
        LCD.DrawPixel((x+4),(y+2));
        LCD.DrawPixel((x+4),(y+8));
    } else if (charactername == 'P'){
        //pizza character
        LCD.SetDrawColor(LCD.White);
        LCD.FillRectangle(x,y,11,11);

        LCD.SetDrawColor(LCD.Red);
        LCD.DrawPixel((x+1), (y+5));
        LCD.DrawPixel((x+9), y+2);
        LCD.DrawPixel((x+5), (y+5));
        LCD.DrawPixel((x+8), y+7);

    }
}
//BOSS FIGHT C3
int BossFight(int level, HealthBar hb, char charname /* user character name*/){

    int randint;
    HealthBar bosshp;

 

    int a,b;

    if (level == 1){
           hb.health = 100;
    bosshp.health = 100;

    //redraw
        LCD.Clear();
        DrawCharacter(charname,70,80);
        
        DrawBoss('M',200,80);

        LCD.SetDrawColor(LCD.Red);
        LCD.FillRectangle(70,50,20,10);

        

        LCD.SetDrawColor(LCD.Red);
        LCD.FillRectangle(200,50,20,10);

     

//moveset for each character
    if (charname == 'M'){
        LCD.DrawRectangle(0,100, 100, 50);
        LCD.WriteAt("Burger Blast", 10, 105);

        LCD.DrawRectangle(110,100,100,50);
        LCD.WriteAt("McNugget Grenade",120,105);

        LCD.DrawRectangle(0,160,100,50);
        LCD.WriteAt("Big Mac", 10, 165);

        LCD.DrawRectangle(110,160,100,50);
        LCD.WriteAt("McFlurry Blizzard", 120, 165);

    } else if (charname == 'P'){
        LCD.DrawRectangle(0,100, 100, 50);
        LCD.WriteAt("Pepperoni Razor", 10, 105);

        LCD.DrawRectangle(110,100,100,50);
        LCD.WriteAt("Cheese Cannon",120,105);

        LCD.DrawRectangle(0,160,100,50);
        LCD.WriteAt("Pizza Sauce", 10, 165);

        LCD.DrawRectangle(110,160,100,50);
        LCD.WriteAt("Crust Whip", 120, 165);

    } else if (charname == 'C'){
        LCD.DrawRectangle(0,100, 100, 50);
        LCD.WriteAt("Burrito Rocket", 10, 105);

        LCD.DrawRectangle(110,100,100,50);
        LCD.WriteAt("Taco Blade",120,105);

        LCD.DrawRectangle(0,160,100,50);
        LCD.WriteAt("Guac Gun", 10, 165);

        LCD.DrawRectangle(110,160,100,50);
        LCD.WriteAt("Salsa Sword", 120, 165);

    }


    while (hb.health > 0 && bosshp.health > 0){

        
        //character touch-movement detection here
        while (!LCD.Touch(&a, &b)) {

            //computer randomly moves
            randint = RandInt() % 4;
                //damagae values

            if (charname == 'M'){
                if ((a >= 0 && a <= 100) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(15);

                    if (randint == 0){
                        hb.DamageTaken(15);
                    }

                } else if ((a >= 0 && a <= 100) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(15);

                    if (randint == 1){
                        hb.DamageTaken(15);
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 100 && b <= 150){

                    bosshp.DamageTaken(60);

                    if (randint == 2){
                        hb.DamageTaken(15);
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 160 && b <= 210){

                    bosshp.DamageTaken(15);

                    if (randint == 3){
                        hb.DamageTaken(15);
                    }

                }
            } else if (charname == 'P'){
                if ((a >= 0 && a <= 100) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(15);

                    if (randint == 0){
                        hb.DamageTaken(15);
                    }

                } else if ((a >= 0 && a <= 100) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(15);

                    if (randint == 1){
                        hb.DamageTaken(30);
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 100 && b <= 150){

                    bosshp.DamageTaken(60);

                    if (randint == 2){
                        hb.DamageTaken(30);
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 160 && b <= 210){

                    bosshp.DamageTaken(60);

                    if (randint == 3){
                        hb.DamageTaken(15);
                    }

                }
            } else if (charname == 'C'){
                if ((a >= 0 && a <= 100) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(60);

                    if (randint == 0){
                        hb.DamageTaken(15);
                    }

                } else if ((a >= 0 && a <= 100) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(60);

                    if (randint == 1){
                        hb.DamageTaken(30);
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 100 && b <= 150){

                    bosshp.DamageTaken(15);

                    if (randint == 2){
                        hb.DamageTaken(30);
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 160 && b <= 210){

                    bosshp.DamageTaken(15);

                    if (randint == 3){
                        hb.DamageTaken(15);
                    }

                }

            }
             LCD.Clear();
             DrawCharacter(charname,70,80);
        
            DrawBoss('M',200,80);

            LCD.SetDrawColor(LCD.Red);
            LCD.FillRectangle(70,50,(0.2) * hb.health,10);

        

            LCD.SetDrawColor(LCD.Red);
            LCD.FillRectangle(200,50,(0.2) * bosshp.health,10);

     


            if (charname == 'M'){
                LCD.DrawRectangle(0,100, 100, 50);
                LCD.WriteAt("Burger Blast", 10, 105);

                 LCD.DrawRectangle(110,100,100,50);
                 LCD.WriteAt("McNugget Grenade",120,105);

                LCD.DrawRectangle(0,160,100,50);
                LCD.WriteAt("Big Mac", 10, 165);

                LCD.DrawRectangle(110,160,100,50);
                LCD.WriteAt("McFlurry Blizzard", 120, 165);

                } else if (charname == 'P'){
                LCD.DrawRectangle(0,100, 100, 50);
                LCD.WriteAt("Pepperoni Razor", 10, 105);

                LCD.DrawRectangle(110,100,100,50);
                LCD.WriteAt("Cheese Cannon",120,105);

                LCD.DrawRectangle(0,160,100,50);
             LCD.WriteAt("Pizza Sauce", 10, 165);

             LCD.DrawRectangle(110,160,100,50);
                LCD.WriteAt("Crust Whip", 120, 165);

                } else if (charname == 'C'){
                LCD.DrawRectangle(0,100, 100, 50);
                 LCD.WriteAt("Burrito Rocket", 10, 105);

                 LCD.DrawRectangle(110,100,100,50);
             LCD.WriteAt("Taco Blade",120,105);

                LCD.DrawRectangle(0,160,100,50);
                LCD.WriteAt("Guac Gun", 10, 165);

                LCD.DrawRectangle(110,160,100,50);
                LCD.WriteAt("Salsa Sword", 120, 165);

        }
           
            
    }


    }         

    
    //level 2 boss fight
    } else if (level == 2){
           hb.health = 100;
    bosshp.health = 200;

         LCD.Clear();
        DrawCharacter(charname,70,80);
        
        DrawBoss('C',200,80);

        LCD.SetDrawColor(LCD.Red);
        LCD.FillRectangle(70,50,20,10);

        

        LCD.SetDrawColor(LCD.Red);
        LCD.FillRectangle(200,50,20,10);

     


    if (charname == 'M'){
        LCD.DrawRectangle(0,100, 100, 50);
        LCD.WriteAt("Burger Blast", 10, 105);

        LCD.DrawRectangle(110,100,100,50);
        LCD.WriteAt("McNugget Grenade",120,105);

        LCD.DrawRectangle(0,160,100,50);
        LCD.WriteAt("Big Mac", 10, 165);

        LCD.DrawRectangle(110,160,100,50);
        LCD.WriteAt("McFlurry Blizzard", 120, 165);

    } else if (charname == 'P'){
        LCD.DrawRectangle(0,100, 100, 50);
        LCD.WriteAt("Pepperoni Razor", 10, 105);

        LCD.DrawRectangle(110,100,100,50);
        LCD.WriteAt("Cheese Cannon",120,105);

        LCD.DrawRectangle(0,160,100,50);
        LCD.WriteAt("Pizza Sauce", 10, 165);

        LCD.DrawRectangle(110,160,100,50);
        LCD.WriteAt("Crust Whip", 120, 165);

    } else if (charname == 'C'){
        LCD.DrawRectangle(0,100, 100, 50);
        LCD.WriteAt("Burrito Rocket", 10, 105);

        LCD.DrawRectangle(110,100,100,50);
        LCD.WriteAt("Taco Blade",120,105);

        LCD.DrawRectangle(0,160,100,50);
        LCD.WriteAt("Guac Gun", 10, 165);

        LCD.DrawRectangle(110,160,100,50);
        LCD.WriteAt("Salsa Sword", 120, 165);

    }


    while (hb.health > 0 && bosshp.health > 0){

        
        //character touch-movement detection here
        while (!LCD.Touch(&a, &b)) {
            randint = RandInt() % 4;

            if (charname == 'M'){
                if ((a >= 0 && a <= 100) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(30);

                    if (randint == 0){
                        hb.DamageTaken(15);
                    }

                } else if ((a >= 0 && a <= 100) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(60);

                    if (randint == 1){
                        hb.DamageTaken(40);
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 100 && b <= 150){

                    bosshp.DamageTaken(60);

                    if (randint == 2){
                        hb.DamageTaken(30);
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 160 && b <= 210){

                    bosshp.DamageTaken(15);

                    if (randint == 3){
                        hb.DamageTaken(15);
                    }

                }
            } else if (charname == 'P'){
                if ((a >= 0 && a <= 100) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(15);

                    if (randint == 0){
                        hb.DamageTaken(15);
                    }

                } else if ((a >= 0 && a <= 100) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(15);

                    if (randint == 1){
                        hb.DamageTaken(30);
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 100 && b <= 150){

                    bosshp.DamageTaken(60);

                    if (randint == 2){
                        hb.DamageTaken(30);
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 160 && b <= 210){

                    bosshp.DamageTaken(60);

                    if (randint == 3){
                        hb.DamageTaken(15);
                    }

                }
            } else if (charname == 'C'){
                if ((a >= 0 && a <= 100) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(30);

                    if (randint == 0){
                        hb.DamageTaken(30);
                    }

                } else if ((a >= 0 && a <= 100) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(30);

                    if (randint == 1){
                        hb.DamageTaken(30);
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 100 && b <= 150){

                    bosshp.DamageTaken(30);

                    if (randint == 2){
                        hb.DamageTaken(30);
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 160 && b <= 210){

                    bosshp.DamageTaken(30);

                    if (randint == 3){
                        hb.DamageTaken(30);
                    }

                }

            }
             LCD.Clear();
             DrawCharacter(charname,70,80);
        
            DrawBoss('C',200,80);

            LCD.SetDrawColor(LCD.Red);
            LCD.FillRectangle(70,50,(0.2) * hb.health,10);

        

            LCD.SetDrawColor(LCD.Red);
            LCD.FillRectangle(200,50,(0.2) * bosshp.health,10);

     


            if (charname == 'M'){
                LCD.DrawRectangle(0,100, 100, 50);
                LCD.WriteAt("Burger Blast", 10, 105);

                 LCD.DrawRectangle(110,100,100,50);
                 LCD.WriteAt("McNugget Grenade",120,105);

                LCD.DrawRectangle(0,160,100,50);
                LCD.WriteAt("Big Mac", 10, 165);

                LCD.DrawRectangle(110,160,100,50);
                LCD.WriteAt("McFlurry Blizzard", 120, 165);

                } else if (charname == 'P'){
                LCD.DrawRectangle(0,100, 100, 50);
                LCD.WriteAt("Pepperoni Razor", 10, 105);

                LCD.DrawRectangle(110,100,100,50);
                LCD.WriteAt("Cheese Cannon",120,105);

                LCD.DrawRectangle(0,160,100,50);
             LCD.WriteAt("Pizza Sauce", 10, 165);

             LCD.DrawRectangle(110,160,100,50);
                LCD.WriteAt("Crust Whip", 120, 165);

                } else if (charname == 'C'){
                LCD.DrawRectangle(0,100, 100, 50);
                 LCD.WriteAt("Burrito Rocket", 10, 105);

                 LCD.DrawRectangle(110,100,100,50);
             LCD.WriteAt("Taco Blade",120,105);

                LCD.DrawRectangle(0,160,100,50);
                LCD.WriteAt("Guac Gun", 10, 165);

                LCD.DrawRectangle(110,160,100,50);
                LCD.WriteAt("Salsa Sword", 120, 165);

        }
           
            
    }


    }         
    //level 3 boss fight
    } else if (level == 3){

           hb.health = 100;
    bosshp.health = 300;

                 LCD.Clear();
        DrawCharacter(charname,70,80);
        
        DrawBoss('P',200,80);

        LCD.SetDrawColor(LCD.Red);
        LCD.FillRectangle(70,50,20,10);

        

        LCD.SetDrawColor(LCD.Red);
        LCD.FillRectangle(200,50,20,10);

     


    if (charname == 'M'){
        LCD.DrawRectangle(0,100, 100, 50);
        LCD.WriteAt("Burger Blast", 10, 105);

        LCD.DrawRectangle(110,100,100,50);
        LCD.WriteAt("McNugget Grenade",120,105);

        LCD.DrawRectangle(0,160,100,50);
        LCD.WriteAt("Big Mac", 10, 165);

        LCD.DrawRectangle(110,160,100,50);
        LCD.WriteAt("McFlurry Blizzard", 120, 165);

    } else if (charname == 'P'){
        LCD.DrawRectangle(0,100, 100, 50);
        LCD.WriteAt("Pepperoni Razor", 10, 105);

        LCD.DrawRectangle(110,100,100,50);
        LCD.WriteAt("Cheese Cannon",120,105);

        LCD.DrawRectangle(0,160,100,50);
        LCD.WriteAt("Pizza Sauce", 10, 165);

        LCD.DrawRectangle(110,160,100,50);
        LCD.WriteAt("Crust Whip", 120, 165);

    } else if (charname == 'C'){
        LCD.DrawRectangle(0,100, 100, 50);
        LCD.WriteAt("Burrito Rocket", 10, 105);

        LCD.DrawRectangle(110,100,100,50);
        LCD.WriteAt("Taco Blade",120,105);

        LCD.DrawRectangle(0,160,100,50);
        LCD.WriteAt("Guac Gun", 10, 165);

        LCD.DrawRectangle(110,160,100,50);
        LCD.WriteAt("Salsa Sword", 120, 165);

    }


    while (hb.health > 0 && bosshp.health > 0){

        
        //character touch-movement detection here
        while (!LCD.Touch(&a, &b)) {
            randint = RandInt() % 4;

            if (charname == 'M'){
                if ((a >= 0 && a <= 100) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(30);

                    if (randint == 0){
                        hb.DamageTaken(15);
                    }

                } else if ((a >= 0 && a <= 100) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(60);

                    if (randint == 1){
                        hb.DamageTaken(40);
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 100 && b <= 150){

                    bosshp.DamageTaken(60);

                    if (randint == 2){
                        hb.DamageTaken(30);
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 160 && b <= 210){

                    bosshp.DamageTaken(15);

                    if (randint == 3){
                        hb.DamageTaken(15);
                    }

                }
            } else if (charname == 'P'){
                if ((a >= 0 && a <= 100) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(15);

                    if (randint == 0){
                        hb.DamageTaken(15);
                    }

                } else if ((a >= 0 && a <= 100) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(15);

                    if (randint == 1){
                        hb.DamageTaken(30);
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 100 && b <= 150){

                    bosshp.DamageTaken(60);

                    if (randint == 2){
                        hb.DamageTaken(30);
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 160 && b <= 210){

                    bosshp.DamageTaken(60);

                    if (randint == 3){
                        hb.DamageTaken(15);
                    }

                }
            } else if (charname == 'C'){
                if ((a >= 0 && a <= 100) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(20);

                    if (randint == 0){
                        hb.DamageTaken(30);
                    }

                } else if ((a >= 0 && a <= 100) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(60);

                    if (randint == 1){
                        hb.DamageTaken(40);
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 100 && b <= 150){

                    bosshp.DamageTaken(40);

                    if (randint == 2){
                        hb.DamageTaken(30);
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 160 && b <= 210){

                    bosshp.DamageTaken(30);

                    if (randint == 3){
                        hb.DamageTaken(60);
                    }

                }

            }
             LCD.Clear();
             DrawCharacter(charname,70,80);
        
            DrawBoss('P',200,80);

            LCD.SetDrawColor(LCD.Red);
            LCD.FillRectangle(70,50,(0.2) * hb.health,10);

        

            LCD.SetDrawColor(LCD.Red);
            LCD.FillRectangle(200,50,(0.2) * bosshp.health,10);

     


            if (charname == 'M'){
                LCD.DrawRectangle(0,100, 100, 50);
                LCD.WriteAt("Burger Blast", 10, 105);

                 LCD.DrawRectangle(110,100,100,50);
                 LCD.WriteAt("McNugget Grenade",120,105);

                LCD.DrawRectangle(0,160,100,50);
                LCD.WriteAt("Big Mac", 10, 165);

                LCD.DrawRectangle(110,160,100,50);
                LCD.WriteAt("McFlurry Blizzard", 120, 165);

                } else if (charname == 'P'){
                LCD.DrawRectangle(0,100, 100, 50);
                LCD.WriteAt("Pepperoni Razor", 10, 105);

                LCD.DrawRectangle(110,100,100,50);
                LCD.WriteAt("Cheese Cannon",120,105);

                LCD.DrawRectangle(0,160,100,50);
             LCD.WriteAt("Pizza Sauce", 10, 165);

             LCD.DrawRectangle(110,160,100,50);
                LCD.WriteAt("Crust Whip", 120, 165);

                } else if (charname == 'C'){
                LCD.DrawRectangle(0,100, 100, 50);
                 LCD.WriteAt("Burrito Rocket", 10, 105);

                 LCD.DrawRectangle(110,100,100,50);
             LCD.WriteAt("Taco Blade",120,105);

                LCD.DrawRectangle(0,160,100,50);
                LCD.WriteAt("Guac Gun", 10, 165);

                LCD.DrawRectangle(110,160,100,50);
                LCD.WriteAt("Salsa Sword", 120, 165);

        }
           
            
    }


    } 
    //Pepsi final boss fight
    } else if (level == 4){
         hb.health = 100;
    bosshp.health = 300;

        LCD.Clear();
        DrawCharacter(charname,70,80);
        
        DrawBoss('Pe',200,80);

        LCD.SetDrawColor(LCD.Red);
        LCD.FillRectangle(70,50,20,10);

        

        LCD.SetDrawColor(LCD.Red);
        LCD.FillRectangle(200,50,20,10);

     


    if (charname == 'M'){
        LCD.DrawRectangle(0,100, 100, 50);
        LCD.WriteAt("Burger Blast", 10, 105);

        LCD.DrawRectangle(110,100,100,50);
        LCD.WriteAt("McNugget Grenade",120,105);

        LCD.DrawRectangle(0,160,100,50);
        LCD.WriteAt("Big Mac", 10, 165);

        LCD.DrawRectangle(110,160,100,50);
        LCD.WriteAt("McFlurry Blizzard", 120, 165);

    } else if (charname == 'P'){
        LCD.DrawRectangle(0,100, 100, 50);
        LCD.WriteAt("Pepperoni Razor", 10, 105);

        LCD.DrawRectangle(110,100,100,50);
        LCD.WriteAt("Cheese Cannon",120,105);

        LCD.DrawRectangle(0,160,100,50);
        LCD.WriteAt("Pizza Sauce", 10, 165);

        LCD.DrawRectangle(110,160,100,50);
        LCD.WriteAt("Crust Whip", 120, 165);

    } else if (charname == 'C'){
        LCD.DrawRectangle(0,100, 100, 50);
        LCD.WriteAt("Burrito Rocket", 10, 105);

        LCD.DrawRectangle(110,100,100,50);
        LCD.WriteAt("Taco Blade",120,105);

        LCD.DrawRectangle(0,160,100,50);
        LCD.WriteAt("Guac Gun", 10, 165);

        LCD.DrawRectangle(110,160,100,50);
        LCD.WriteAt("Salsa Sword", 120, 165);

    }


    while (hb.health > 0 && bosshp.health > 0){

        
        //character touch-movement detection here
        while (!LCD.Touch(&a, &b)) {
            randint = RandInt() % 4;

            if (charname == 'M'){
                if ((a >= 0 && a <= 100) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(50);

                    if (randint == 0){
                        hb.DamageTaken(20);
                    }

                } else if ((a >= 0 && a <= 100) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(50);

                    if (randint == 1){
                        hb.DamageTaken(20);
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 100 && b <= 150){

                    bosshp.DamageTaken(50);

                    if (randint == 2){
                        hb.DamageTaken(20);
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 160 && b <= 210){

                    bosshp.DamageTaken(50);

                    if (randint == 3){
                        hb.DamageTaken(20);
                    }

                }
            } else if (charname == 'P'){
                if ((a >= 0 && a <= 100) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(50);

                    if (randint == 0){
                        hb.DamageTaken(20);
                    }

                } else if ((a >= 0 && a <= 100) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(50);

                    if (randint == 1){
                        hb.DamageTaken(20);
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 100 && b <= 150){

                    bosshp.DamageTaken(50);

                    if (randint == 2){
                        hb.DamageTaken(20);
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 160 && b <= 210){

                    bosshp.DamageTaken(50);

                    if (randint == 3){
                        hb.DamageTaken(20);
                    }

                }
            } else if (charname == 'C'){
                if ((a >= 0 && a <= 100) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(50);

                    if (randint == 0){
                        hb.DamageTaken(20);
                    }

                } else if ((a >= 0 && a <= 100) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(50);

                    if (randint == 1){
                        hb.DamageTaken(20);
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 100 && b <= 150){

                    bosshp.DamageTaken(50);

                    if (randint == 2){
                        hb.DamageTaken(20);
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 160 && b <= 210){

                    bosshp.DamageTaken(50);

                    if (randint == 3){
                        hb.DamageTaken(20);
                    }

                }

            }
             LCD.Clear();
             DrawCharacter(charname,70,80);
        
            DrawBoss('Pe',200,80);

            LCD.SetDrawColor(LCD.Red);
            LCD.FillRectangle(70,50,(0.2) * hb.health,10);

        

            LCD.SetDrawColor(LCD.Red);
            LCD.FillRectangle(200,50,(0.2) * bosshp.health,10);

     


            if (charname == 'M'){
                LCD.DrawRectangle(0,100, 100, 50);
                LCD.WriteAt("Burger Blast", 10, 105);

                 LCD.DrawRectangle(110,100,100,50);
                 LCD.WriteAt("McNugget Grenade",120,105);

                LCD.DrawRectangle(0,160,100,50);
                LCD.WriteAt("Big Mac", 10, 165);

                LCD.DrawRectangle(110,160,100,50);
                LCD.WriteAt("McFlurry Blizzard", 120, 165);

                } else if (charname == 'P'){
                LCD.DrawRectangle(0,100, 100, 50);
                LCD.WriteAt("Pepperoni Razor", 10, 105);

                LCD.DrawRectangle(110,100,100,50);
                LCD.WriteAt("Cheese Cannon",120,105);

                LCD.DrawRectangle(0,160,100,50);
             LCD.WriteAt("Pizza Sauce", 10, 165);

             LCD.DrawRectangle(110,160,100,50);
                LCD.WriteAt("Crust Whip", 120, 165);

                } else if (charname == 'C'){
                LCD.DrawRectangle(0,100, 100, 50);
                 LCD.WriteAt("Burrito Rocket", 10, 105);

                 LCD.DrawRectangle(110,100,100,50);
             LCD.WriteAt("Taco Blade",120,105);

                LCD.DrawRectangle(0,160,100,50);
                LCD.WriteAt("Guac Gun", 10, 165);

                LCD.DrawRectangle(110,160,100,50);
                LCD.WriteAt("Salsa Sword", 120, 165);

        }
           
            
    }


    }         

    }

    if (bosshp.health <= 0){
        return 1;
    } else if (hb.health <= 0){
        return 0;
    }

    

}





//INTRO C4
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
}//end Intro Function


//DISPLAY CREDITS C5
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


//DRAW LEVEL C6
void DrawLevel(int level) {
    LCD.Clear();
    //making a switch case to determine background based on level

    switch (level) {
        case 4:
            //pepsiman level

            //drawing wall outlines
            LCD.SetDrawColor(LCD.Blue);
            LCD.DrawLine(X_MAX,0,297,50);
            LCD.FillRectangle(0,50,297,Y_MAX-50);
            LCD.DrawLine(297,50,297,Y_MAX);

            LCD.SetDrawColor(LCD.Red);
            LCD.FillRectangle(0,0,297,49);
            
            for (int i = 0; i < 50; i++) {
                LCD.DrawHorizontalLine(i,297,(X_MAX-0.5*i));
            }

            //drawing entrance
            LCD.SetDrawColor(LCD.White);
            for (int y = 130; y <= 163; y++) {
                LCD.DrawLine(309,y,X_MAX,(y-14));
            }

            LCD.FillCircle(150,150,50);

            //writing the letter P on the floor
            LCD.SetDrawColor(LCD.Scarlet);
            LCD.DrawVerticalLine(130,110,190);
            LCD.DrawHorizontalLine(111,130,160);
            LCD.DrawHorizontalLine(150,130,160);
            LCD.DrawVerticalLine(170,130,135);
            LCD.DrawLine(160,111,170,130);
            LCD.DrawLine(170,135,160,150);

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


//DRAW CHARACTER C7
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


//PEPSIMAN BACKSTORY C8


//gray represents user while blue represents pepsiman
void PepsiBackstory() {
    int x, y;
    LCD.SetFontColor(LCD.White);

    LCD.SetDrawColor(LCD.Gray); 
    LCD.FillRectangle(0,0,X_MAX,30);

    LCD.WriteAt("!!!", 100,10);
    
    while(!LCD.Touch(&x, &y)) {
        //runs until touched
    }

    LCD.FillRectangle(0,0,X_MAX,30);
    LCD.WriteAt("Pepsiman, what are you doing here?!", 20,10);

    while(!LCD.Touch(&x, &y)) {
        //runs until touched
    }

    LCD.SetDrawColor(LCD.Blue);
    LCD.FillRectangle(0,0,X_MAX,30);
    LCD.WriteAt("So the time has come hasn't it?", 20,10);

    while(!LCD.Touch(&x, &y)) {
        //runs until touched
    }
    LCD.SetDrawColor(LCD.Gray);
    LCD.FillRectangle(0,0,X_MAX,30);
    LCD.WriteAt("For us to defeat a monster together?", 10, 10);

    while(!LCD.Touch(&x,&y)) {
        //runs until touched
    }

    LCD.SetDrawColor(LCD.Blue);
    LCD.FillRectangle(0,0,X_MAX,30);
    LCD.WriteAt("Gosh, you're such a nincompoop", 20,10);

    while(!LCD.Touch(&x,&y)) {
        //runs until touched
    }
    LCD.FillRectangle(0,0,X_MAX,30);
    LCD.WriteAt("Where do you think these creatures",0,0);
    LCD.WriteAt("come from?", 100,15);

    while(!LCD.Touch(&x,&y)) {
        //runs until touched
    }

    LCD.SetDrawColor(LCD.Gray);
    LCD.FillRectangle(0,0,X_MAX,30);
    LCD.WriteAt("umm----", 150,0);

    while(!LCD.Touch(&x,&y)) {
        //runs until touched
    }

    LCD.FillRectangle(0,0,X_MAX,30);

    while(!LCD.Touch(&x,&y)) {
        //runs until touched
    }

    LCD.WriteAt("YOU?!", 150,10);

    while(!LCD.Touch(&x,&y)) {
        //runs until touched
    }

    LCD.SetDrawColor(LCD.Blue);
    LCD.FillRectangle(0,0,X_MAX,30);
    LCD.WriteAt("Well nice work Sherlock", 20,10);

    while(!LCD.Touch(&x,&y)) {
        //runs until touched
    }
    LCD.SetDrawColor(LCD.Gray);
    LCD.FillRectangle(0,0,X_MAX,30);
    LCD.WriteAt("How could you? And why?", 20,10);

    while(!LCD.Touch(&x,&y)) {
        //runs until touched
    }

    LCD.SetDrawColor(LCD.Blue);
    LCD.FillRectangle(0,0,X_MAX,30);
    LCD.WriteAt("It all started years ago", 20,10);

    while(!LCD.Touch(&x,&y)) {
        //runs until touched
    }

    LCD.FillRectangle(0,0,X_MAX,30);
    LCD.WriteAt("All the restaurants lived in harmony", 0,10);

    while(!LCD.Touch(&x,&y)) {
        //runs until touched
    }

    LCD.FillRectangle(0,0,X_MAX,30);
    LCD.WriteAt("And I lived in peace with them", 0,10);

    while(!LCD.Touch(&x,&y)) {
        //runs until touched
    }

    LCD.FillRectangle(0,0,X_MAX,30);
    LCD.WriteAt("Until every single restaurant switched to ", 0, 10);

    while(!LCD.Touch(&x,&y)) {
        //runs until touched
    }

    LCD.FillRectangle(0,0,X_MAX,30);
    LCD.WriteAt("COKE", 150,10);

    while(!LCD.Touch(&x,&y)) {
        //runs until touched
    }

    LCD.FillRectangle(0,0,X_MAX,30);
    LCD.WriteAt("while forgetting about me", 10,10);

    while(!LCD.Touch(&x,&y)) {
        //runs until touched
    }

    LCD.FillRectangle(0,0,X_MAX,30);
    LCD.WriteAt("I made these monsters", 10,10);

    while(!LCD.Touch(&x,&y)) {
        //runs until touched
    }

    LCD.FillRectangle(0,0,X_MAX,30);
    LCD.WriteAt("so that I could save restaurants", 0,10);

    while(!LCD.Touch(&x,&y)) {
        //runs until touched
    }

    LCD.FillRectangle(0,0,X_MAX,30);
    LCD.WriteAt("and become more than a drink again", 0,10);

    while(!LCD.Touch(&x,&y)) {
        //runs until touched
    }

    LCD.SetDrawColor(LCD.Gray);
    LCD.FillRectangle(0,0,X_MAX,30);
    LCD.WriteAt("But why ask me to help you?", 10,10);

    while(!LCD.Touch(&x,&y)) {
        //runs until touched
    }

    LCD.SetDrawColor(LCD.Blue);
    LCD.FillRectangle(0,0,X_MAX,30);
    LCD.WriteAt("I underestimated your strength", 0,10);
       
    while(!LCD.Touch(&x,&y)) {
        //runs until touched
    }

    LCD.FillRectangle(0,0,X_MAX,30);
    LCD.WriteAt("I didn't think you'd defeat all of them",0,0);

    while(!LCD.Touch(&x,&y)) {
        //runs until touched
    }

    LCD.FillRectangle(0,0,X_MAX,30);
    LCD.WriteAt("But now that you know my secret", 10,10);
        
    while(!LCD.Touch(&x,&y)) {
        //runs until touched
    }
    
    LCD.FillRectangle(0,0,X_MAX,30);
    LCD.WriteAt("It looks like I'll have to kill you myself",0,10);

    while(!LCD.Touch(&x,&y)) {
        //runs until touched
    }
}




