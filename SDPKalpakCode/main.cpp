#include "FEHLCD.h"

#include "FEHRandom.h"
#include <stdlib.h>

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
        LCD.SetDrawColor(LCD.Black);
        LCD.DrawRectangle(x,y,11,11);

        LCD.SetDrawColor(LCD.Green);

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
    else if (charactername == 'P') {
        //Pizza character
        LCD.SetDrawColor(LCD.Black);
        LCD.FillRectangle(x,y,11,11);

        LCD.SetDrawColor(LCD.Green);
        LCD.DrawPixel((x+1), (y+5));
        LCD.DrawPixel((x+9), y+2);
        LCD.DrawPixel((x+5), (y+5));
        LCD.DrawPixel((x+8), y+7);
    }
    else if (charactername == 'C') {
        //chipotle character
        LCD.SetDrawColor(LCD.Black);

        LCD.FillRectangle(x,y,11,11);

        LCD.SetDrawColor(LCD.Green);
        LCD.DrawLine((x+3),(y+3),(x+3),(y+7));
        LCD.DrawLine((x+5), (y+1), (x+7), (y+1));
        LCD.DrawLine((x+5),(y+9),(x+7),(y+9));
        LCD.DrawPixel((x+4),(y+2));
        LCD.DrawPixel((x+4),(y+8));
    }
}

int BossFight(int level, HealthBar hb, char charname){

    int randint;
    HealthBar bosshp;
    int xb, yb, t;
    int xc, yc;
    int xtempboundary;

    int flag = 0, flag2 - 0;//flag 0 is up, flag 1 is down movement, flag2 = 0 is left, flag2 = 1 is right movement

    int flag3 = 0; //flag3 = 0 is vertical movement, flag3 = 1 is horizontal movement

    xb = 269;
    yb = 168;

    xtempboundary = 319;

    hb.health = 90;
    bosshp.health = 200;

    int a,b;

    if (level == 1){
        LCD.Clear();
        LCD.SetDrawColor(LCD.White);
        LCD.FillRectangle(0,0,319,178);

        LCD.SetDrawColor(LCD.Black);
        LCD.FillRectangle(0,179,319,50);

        DrawCharacter(charname, 50, 168);

        DrawBoss('M', 269, 168);
        
        //boss movement is simplified to one move here
        
            while ((hb.health > 0) && (bosshp.health > 0)){
               
               //character touch-movement detection here
            while (!LCD.Touch(&a, &b)) {
             }

             xc = a;//Convert a,b touch on controls to character coordinate increment
             yc = b;

                if (yb >= 168){
                    flag = 0;
                    flag3 = 1;

                    if (flag2 == 0){   
                        xtempboundary -= 90; 
                    } else if (flag2 == 1){
                        xtempboundary += 90;
                    } 
                }

                if (yb <= 148){
                    flag = 1;
                    flag3 = 1;

                    if (flag2 == 0){   
                        xtempboundary -= 90; 
                    } else if (flag2 == 1){
                        xtempboundary += 90;
                    } 
                }

                if (((flag2 == 1) && xb >= (xtempboundary)) || ((flag2 == 0) && xb <= (xtempboundary))){
                    flag3 = 0;
                }

                if (xb <= 0){
                    flag2 = 1;
                }

                if (xb >= 319){
                    flag2 = 0;
                }
               
               if (flag3 == 0){
                   if (flag == 0){
                       yb += 20;
                   } else if (flag == 1){
                       yb -= 20;
                   }
               } else if (flag3 == 1){
                   if (flag2 == 0){
                       xb -= 30;
                   } else if (flag2 == 1){
                       xb += 30;
                   }
               }

                if ((abs(xb - xc) <= 11) || (abs(yb-yc) <= 11)){
                    hb.DamageTaken(30); //30 damage per boss hit level 1? modify as seen fit
                } 
                
                LCD.Clear();
                LCD.SetDrawColor(LCD.White);
                LCD.FillRectangle(0,0,319,178);

                LCD.SetDrawColor(LCD.Black);
                LCD.FillRectangle(0,179,319,50);

                DrawCharacter(charname, xc, yc);
                DrawBoss('M', xb, yb);
                
               
            } 
    

    } 

    if (bosshp.health <= 0){
        return 1;
    } else if (hb.health <= 0){
        return 0;
    }

    

}