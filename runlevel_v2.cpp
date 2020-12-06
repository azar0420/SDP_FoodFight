#include <FEHLCD.h>
//definitions and functions
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
//functions definitions will need to be removed when this is combined in main function

#define X_MAX 319
#define Y_MAX 239
#define block 10
#define leftborder 35
#define rightborder 284
#define topborder 35
#define downborder 35
using namespace std;


//function definitions soley here to help reduce errors
int RunLevel();
void DrawLevel(int a);
int Bossfight(int l);
void HealthPotion(int num);
//various ints that will change

//function start


int RunLevel(int a){
    //define variables
        int randitem= (rand() % 4) +1;
        
        //various int definition
        int level=a;
        int button=1;
        int userinput;
        int userinputx,userinputy;
        int hatchlocx,hatchlocy;
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
            //insert hatch location level 1
            break;
        case(2):
            //insert hatch location level 2
            break;
        case(3):
           hatchlocx=314;
           hatchlocy=202;
            break;
        case 4:
            //insert hatch location level 4
            break;
    }//end switch
    
    //start of the loop
    while(level==a){
        //has to redraw the level every click due to character movement
        DrawLevel(level);
        Drawcharacter(characterlocx,characterlocy);
        if (button!=1){
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
                            HealthPotion(5);
                             break;
                        case 2:
                            HealthPotion(10);
                        case 3:
                            HealthPotion(15);
                            break;
                        case 4:
                            HealthPotion(25);
                            break;

                        default:
                             break;
                    }//end level check    
                }//buton check
            }//locy check
        }//locx check
        //hatch to end of level check
        if((hatchlocx<characterlocx<hatchlocx+15)||(hatchlocx<characterlocx+10<hatchlocx+15)){
            if((hatchlocy<characterlocy<hatchlocy+15)||(hatchlocy<characterlocy+10<hatchlocy+15)){
                int win;
                win=Bossfight(level);
                if(win==1){
                    level=level+1;
                    return level;
                }///end win
                else{
                    level=0;
                }//end lose
            }//end locy check
        }//end locx check
    }//while level
}//end if level
}//end runlevel function
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


