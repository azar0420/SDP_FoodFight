#include "FEHLCD.h"

#include "FEHRandom.h"


/**
 * Entry point to the application.
 * 
 * @returns status code of program exit
 */
int main() {
    LCD.Clear();
    LCD.WriteLine("Hello World!");
    while (1) {
        // Run forever
    }
    return 0;
}

char CharacterSelect();
int BossFight(int, HealthBar, char);//returns 1 for win and 0 for loss
void DrawBoss(char,int,int);

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
