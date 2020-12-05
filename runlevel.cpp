#include "FEHLCD.h"

#define X_MAX 319
#define Y_MAX 239

using namespace std;
int RunLevel(level);
void DrawLevel();
int Bossfight(level);

int level=0;
int userinput;
int userinputx,userinputy;
void RunLevel(level){
if(level!=0){
    DrawLevel();
    While(level!=0){

        //add mouse click check/function

         while (!LCD.Touch(&userinputx, &userinputy)) {
         }
        Drawcharacter(characterlocx,characterlocy);
        if(userinputx<leftbutton){
            if(characterlocx!=leftborder){
                characterlocx=characterlocx-block;
            }//left border
        }//left button
        if(userinputx>rightbutton){
            if(characterlocx!=rightborder){
                characterlocx=characterlocx+block;
            }//right border
        }//right button
        if(userinputy<downbutton){
            if(characterlocy!=downborder){
                characterlocy=characterlocy-block;
            }//down border
        }//down button
        if(userinput>topbutton){
            if(characterlocy!=topborder){
                characterlocy=characterlocy+block;
            }//top border
        }//top button
        if(characterlocx==buttonlocx){
            if(characterloxy==buttonlocy){
                if(button!=1){
                    button=1;
                }//buton check
            }//locy check
        }//locx check
        if(characterlocx==hatchlocx){
            if(characterloxy==hatchlocy){
                int win=Bossfight(level);
                if(win==1){
                    level=level+1;
                }///end win
                else{
                    level=0;
                }//end lose

            }//end locy check
        }//end locx check

    }//while level
}//end if level


}//end runlevel