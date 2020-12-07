//BOSS FIGHT C3
int BossFight(int level, HealthBar hb, char charname /* user character name*/){

    int randint;
    HealthBar bosshp;

    string usermove, bossmove;

    int a,b;

    if (level == 1){

        //declaring health bars for user and opponent
        hb.health = 100;
        bosshp.health = 100;

        //drawing the sprite
        LCD.Clear();
        DrawCharacter(charname,70,80);
        
        //drawing the opponent
        DrawBoss('M',200,80);

        LCD.SetDrawColor(LCD.Red);
        LCD.FillRectangle(70,50,20,10);
        LCD.FillRectangle(200,50,20,10);

        //moveset for each character
        if (charname == 'M'){
             //drawing and displaying boxes to display moves
            LCD.DrawRectangle(0,100, 100, 50);
            LCD.SetFontColor(LCD.White);
            LCD.WriteAt("Burger", 10, 105);
            LCD.WriteAt("Blast", 10, 125);

            LCD.DrawRectangle(110,100,100,50);
            LCD.WriteAt("McNugget",120,105);
            LCD.WriteAt("Grenade",120,125);

            LCD.DrawRectangle(0,160,100,50);
            LCD.WriteAt("Big", 10, 165);
            LCD.WriteAt("Mac", 10, 185);

            LCD.DrawRectangle(110,160,100,50);
            LCD.WriteAt("McFlurry", 120, 165);
            LCD.WriteAt("Blizzard", 120, 185);
        
    } else if (charname == 'P') {
        LCD.DrawRectangle(0,100, 100, 50);
        LCD.WriteAt("Pepperoni", 10, 105);
        LCD.WriteAt("Razor", 10, 125);

        LCD.DrawRectangle(110,100,100,50);
        LCD.WriteAt("Cheese",120,105);
        LCD.WriteAt("Cannon",120,125);

        LCD.DrawRectangle(0,160,100,50);
        LCD.WriteAt("Pizza", 10, 165);
        LCD.WriteAt("Sauce", 10, 185);

        LCD.DrawRectangle(110,160,100,50);
        LCD.WriteAt("Crust", 120, 165);
        LCD.WriteAt("Whip", 120, 185);

    } else if (charname == 'C'){
        LCD.DrawRectangle(0,100, 100, 50);
        LCD.WriteAt("Burrito", 10, 105);
        LCD.WriteAt("Rocket", 10, 125);

        LCD.DrawRectangle(110,100,100,50);
        LCD.WriteAt("Taco",120,105);
        LCD.WriteAt("Blade",120,125);

        LCD.DrawRectangle(0,160,100,50);
        LCD.WriteAt("Guac", 10, 165);
        LCD.WriteAt("Gun", 10, 185);
       

        LCD.DrawRectangle(110,160,100,50);
        LCD.WriteAt("Salsa", 120, 165);
        LCD.WriteAt("Sword", 120, 185);

    }


    while (hb.health > 0 && bosshp.health > 0){

        //character touch-movement detection here
        while (!LCD.Touch(&a, &b)) {
        }
            //computer randomly moves
            randint = RandInt() % 4;
            //damage values

            if (charname == 'M'){
                //if a move is selected
                if ((a >= 0 && a <= 100) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(15);

                    if (randint == 0){
                        hb.DamageTaken(15);
                        
                    } else if (randint == 1){
                        hb.DamageTaken(15);
                        
                    } else if (randint == 2){
                        hb.DamageTaken(15);
                        bossmove = "Big Mac";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(15);
    
                    }
                
                //if a separate move is selected
                } else if ((a >= 0 && a <= 100) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(15);
                    
                    usermove = "Big Mac";

                    if (randint == 0){
                        hb.DamageTaken(15);
                        bossmove = "Burger Blast";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(15);
                        bossmove = "McNugget Grenade";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(15);
                        bossmove = "Big Mac";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(15);
                        bossmove = "McFlurry Blizzard";
    
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(60);
                    usermove = "McNugget Grenade";
                        
                    if (randint == 0){
                        hb.DamageTaken(15);
                        bossmove = "Burger Blast";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(15);
                        bossmove = "McNugget Grenade";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(15);
                        bossmove = "Big Mac";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(15);
                        bossmove = "McFlurry Blizzard";
    
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(15);
                    usermove = "McFlurry Blizzard";

                    if (randint == 0){
                        hb.DamageTaken(15);
                        bossmove = "Burger Blast";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(15);
                        bossmove = "McNugget Grenade";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(15);
                        bossmove = "Big Mac";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(15);
                        bossmove = "McFlurry Blizzard";
    
                    }
                }
            } else if (charname == 'P'){
                if ((a >= 0 && a <= 100) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(15);
                    usermove = "Pepperoni Razor";
                        
                    if (randint == 0){
                        hb.DamageTaken(15);
                        bossmove = "Burger Blast";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(30);
                        bossmove = "McNugget Grenade";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(30);
                        bossmove = "Big Mac";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(15);
                        bossmove = "McFlurry Blizzard";
    
                    }
                } else if ((a >= 0 && a <= 100) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(15);
                    usermove = "Pizza Sauce";

                    if (randint == 0){
                        hb.DamageTaken(15);
                        bossmove = "Burger Blast";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(30);
                        bossmove = "McNugget Grenade";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(30);
                        bossmove = "Big Mac";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(15);
                        bossmove = "McFlurry Blizzard";
    
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(60);

                    if (randint == 0){
                        hb.DamageTaken(15);
                        
                    } else if (randint == 1){
                        hb.DamageTaken(30);
                        
                    } else if (randint == 2){
                        hb.DamageTaken(30);
                    
                    } else if (randint == 3){
                        hb.DamageTaken(15);
    
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(60);
                    usermove = "Crust Whip";

                    if (randint == 0){
                        hb.DamageTaken(15);
                        bossmove = "Burger Blast";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(30);
                        bossmove = "McNugget Grenade";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(30);
                        bossmove = "Big Mac";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(15);
                        bossmove = "McFlurry Blizzard";
    
                    }

                }
            } else if (charname == 'C'){
                if ((a >= 0 && a <= 100) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(60);
                    usermove = "Burrito Rocket";
                    
                    if (randint == 0){
                        hb.DamageTaken(30);
                        bossmove = "Burger Blast";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(30);
                        bossmove = "McNugget Grenade";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(15);
                        bossmove = "Big Mac";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(15);
                        bossmove = "McFlurry Blizzard";
    
                    }

                } else if ((a >= 0 && a <= 100) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(60);
                    usermove = "Guac Gun";

                    if (randint == 0){
                        hb.DamageTaken(30);
                        bossmove = "Burger Blast";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(30);
                        bossmove = "McNugget Grenade";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(15);
                        bossmove = "Big Mac";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(15);
                        bossmove = "McFlurry Blizzard";
    
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(15);

                    if (randint == 0){
                        hb.DamageTaken(30);
                        bossmove = "Burger Blast";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(30);
                        bossmove = "McNugget Grenade";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(15);
                        bossmove = "Big Mac";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(15);
                        bossmove = "McFlurry Blizzard";
    
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(15);
                    usermove = "Salsa Sword";

                    if (randint == 0){
                        hb.DamageTaken(30);
                        bossmove = "Burger Blast";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(30);
                        bossmove = "McNugget Grenade";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(15);
                        bossmove = "Big Mac";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(15);
                        bossmove = "McFlurry Blizzard";
    
                    }

                }

            }
            LCD.SetDrawColor(LCD.Red);
            LCD.FillRectangle(70,50,(0.2) * hb.health,10);

            LCD.FillRectangle(200,50,(0.2) * bosshp.health,10);
          /*  
            LCD.Clear();
            DrawCharacter(charname,70,80);
        
            DrawBoss('M',200,80);

            LCD.SetDrawColor(LCD.Red);
            LCD.FillRectangle(70,50,(0.2) * hb.health,10);

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
      */
      
            /*LCD.WriteAt("User move:",230,80);
            LCD.WriteAt(usermove,230,100);
            
            LCD.WriteAt("Boss move:",230,120);
            //LCD.WriteAt(bossmove,230,140);*/
            
            
    //}//end of while not touch


    }//end of level 1 movement       

    
    //level 2 boss fight
    } else if (level == 2){
        hb.health = 100;
        bosshp.health = 200;

        LCD.Clear();
        DrawCharacter(charname,70,80);
        
        DrawBoss('C',200,80);

        LCD.SetDrawColor(LCD.Red);
        LCD.FillRectangle(70,50,20,10);
        LCD.FillRectangle(200,50,20,10);

        if (charname == 'M'){
            LCD.DrawRectangle(0,100, 100, 50);
            LCD.SetFontColor(LCD.White);
            LCD.WriteAt("Burger", 10, 105);
            LCD.WriteAt("Blast", 20, 105);

            LCD.DrawRectangle(110,100,100,50);
            LCD.WriteAt("McNugget",120,105);
            LCD.WriteAt("Grenade",130,105);

            LCD.DrawRectangle(0,160,100,50);
            LCD.WriteAt("Big", 10, 165);
            LCD.WriteAt("Mac", 20, 165);

            LCD.DrawRectangle(110,160,100,50);
            LCD.WriteAt("McFlurry", 120, 165);
            LCD.WriteAt("Blizzard", 130, 165);
        
        } else if (charname == 'P'){
            LCD.DrawRectangle(0,100, 100, 50);
            LCD.WriteAt("Pepperoni", 10, 105);
            LCD.WriteAt("Razor", 20, 105);

            LCD.DrawRectangle(110,100,100,50);
            LCD.WriteAt("Cheese",120,105);
            LCD.WriteAt("Cannon",130,105);

            LCD.DrawRectangle(0,160,100,50);
            LCD.WriteAt("Pizza", 10, 165);
            LCD.WriteAt("Sauce", 20, 165);

            LCD.DrawRectangle(110,160,100,50);
            LCD.WriteAt("Crust", 120, 165);
            LCD.WriteAt("Whip", 130, 165);

        } else if (charname == 'C'){
            LCD.DrawRectangle(0,100, 100, 50);
            LCD.WriteAt("Burrito", 10, 105);
            LCD.WriteAt("Rocket", 20, 105);

            LCD.DrawRectangle(110,100,100,50);
            LCD.WriteAt("Taco",120,105);
            LCD.WriteAt("Blade",130,105);

            LCD.DrawRectangle(0,160,100,50);
            LCD.WriteAt("Guac", 10, 165);
            LCD.WriteAt("Gun", 20, 165);
       

            LCD.DrawRectangle(110,160,100,50);
            LCD.WriteAt("Salsa", 120, 165);
            LCD.WriteAt("Sword", 130, 165);

    }


    while (hb.health > 0 && bosshp.health > 0){

        
        //character touch-movement detection here
        while (!LCD.Touch(&a, &b)) {
        }//end while not touch
            randint = RandInt() % 4;

            if (charname == 'M'){
                if ((a >= 0 && a <= 100) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(30);
                    
                    usermove = "Burger Blast";

                    if (randint == 0){
                        hb.DamageTaken(15);
                        bossmove = "Burrito Rocket";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(40);
                        bossmove = "Taco Blade";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(30);
                        bossmove = "Guac Gun";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(15);
                        bossmove = "Salsa Sword";
    
                    }
                   
                   

                } else if ((a >= 0 && a <= 100) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(60);
                    
                    usermove = "Big Mac";

                    if (randint == 0){
                        hb.DamageTaken(15);
                        bossmove = "Burrito Rocket";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(40);
                        bossmove = "Taco Blade";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(30);
                        bossmove = "Guac Gun";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(15);
                        bossmove = "Salsa Sword";
    
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(60);
                    usermove = "McNugget Grenade";
                        
                    if (randint == 0){
                        hb.DamageTaken(15);
                        bossmove = "Burrito Rocket";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(40);
                        bossmove = "Taco Blade";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(30);
                        bossmove = "Guac Gun";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(15);
                        bossmove = "Salsa Sword";
    
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(15);
                    usermove = "McFlurry Blizzard";

                    if (randint == 0){
                        hb.DamageTaken(15);
                        bossmove = "Burrito Rocket";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(40);
                        bossmove = "Taco Blade";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(30);
                        bossmove = "Guac Gun";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(15);
                        bossmove = "Salsa Sword";
    
                    }

                }
            } else if (charname == 'P'){
                if ((a >= 0 && a <= 100) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(15);
                    usermove = "Pepperoni Razor";
                        
                    if (randint == 0){
                        hb.DamageTaken(15);
                        bossmove = "Burrito Rocket";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(30);
                        bossmove = "Taco Blade";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(30);
                        bossmove = "Guac Gun";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(15);
                        bossmove = "Salsa Sword";
    
                    }

                } else if ((a >= 0 && a <= 100) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(15);
                    usermove = "Pizza Sauce";

                    if (randint == 0){
                        hb.DamageTaken(15);
                        bossmove = "Burrito Rocket";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(30);
                        bossmove = "Taco Blade";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(30);
                        bossmove = "Guac Gun";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(15);
                        bossmove = "Salsa Sword";
    
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(60);
                    usermove = "Cheese Cannon";
                        
                    if (randint == 0){
                        hb.DamageTaken(15);
                        bossmove = "Burrito Rocket";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(30);
                        bossmove = "Taco Blade";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(30);
                        bossmove = "Guac Gun";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(15);
                        bossmove = "Salsa Sword";
    
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(60);
                    usermove = "Crust Whip";

                    if (randint == 0){
                        hb.DamageTaken(15);
                        bossmove = "Burrito Rocket";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(30);
                        bossmove = "Taco Blade";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(30);
                        bossmove = "Guac Gun";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(15);
                        bossmove = "Salsa Sword";
    
                    }

                }
            } else if (charname == 'C'){
                if ((a >= 0 && a <= 100) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(40);
                    usermove = "Burrito Rocket";
                    
 
                    if (randint == 0){
                        hb.DamageTaken(30);
                        bossmove = "Burrito Rocket";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(30);
                        bossmove = "Taco Blade";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(30);
                        bossmove = "Guac Gun";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(30);
                        bossmove = "Salsa Sword";
    
                    }

                } else if ((a >= 0 && a <= 100) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(40);
                    usermove = "Guac Gun";


                    if (randint == 0){
                        hb.DamageTaken(30);
                        bossmove = "Burrito Rocket";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(30);
                        bossmove = "Taco Blade";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(30);
                        bossmove = "Guac Gun";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(30);
                        bossmove = "Salsa Sword";
    
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(40);
                    usermove = "Taco Blade";

                    if (randint == 0){
                        hb.DamageTaken(30);
                        bossmove = "Burrito Rocket";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(30);
                        bossmove = "Taco Blade";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(30);
                        bossmove = "Guac Gun";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(30);
                        bossmove = "Salsa Sword";
    
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(40);
                    usermove = "Salsa Sword";

                    if (randint == 0){
                        hb.DamageTaken(30);
                        bossmove = "Burrito Rocket";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(30);
                        bossmove = "Taco Blade";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(30);
                        bossmove = "Guac Gun";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(30);
                        bossmove = "Salsa Sword";
    
                    }

                }

            }
            LCD.SetDrawColor(LCD.Red);
            LCD.FillRectangle(70,50,(0.2) * hb.health,10);

        

            LCD.SetDrawColor(LCD.Red);
            LCD.FillRectangle(200,50,(0.2) * bosshp.health,10);
            /*
             LCD.Clear();
             DrawCharacter(charname,70,80);
        
            DrawBoss('C',200,80);

            LCD.SetDrawColor(LCD.Red);
            LCD.FillRectangle(70,50,(0.2) * hb.health,10);

        

            LCD.SetDrawColor(LCD.Red);
            LCD.FillRectangle(200,50,(0.2) * bosshp.health,10);

     

    if (charname == 'M'){
        LCD.DrawRectangle(0,100, 100, 50);
        LCD.WriteAt("Burger", 10, 105);
        LCD.WriteAt("Blast", 20, 105);

        LCD.DrawRectangle(110,100,100,50);
        LCD.WriteAt("McNugget",120,105);
        LCD.WriteAt("Grenade",130,105);

        LCD.DrawRectangle(0,160,100,50);
        LCD.WriteAt("Big", 10, 165);
        LCD.WriteAt("Mac", 20, 165);

        LCD.DrawRectangle(110,160,100,50);
        LCD.WriteAt("McFlurry", 120, 165);
        LCD.WriteAt("Blizzard", 130, 165);
        
    } else if (charname == 'P'){
        LCD.DrawRectangle(0,100, 100, 50);
        LCD.WriteAt("Pepperoni", 10, 105);
        LCD.WriteAt("Razor", 20, 105);

        LCD.DrawRectangle(110,100,100,50);
        LCD.WriteAt("Cheese",120,105);
        LCD.WriteAt("Cannon",130,105);

        LCD.DrawRectangle(0,160,100,50);
        LCD.WriteAt("Pizza", 10, 165);
        LCD.WriteAt("Sauce", 20, 165);

        LCD.DrawRectangle(110,160,100,50);
        LCD.WriteAt("Crust", 120, 165);
        LCD.WriteAt("Whip", 130, 165);

    } else if (charname == 'C'){
        LCD.DrawRectangle(0,100, 100, 50);
        LCD.WriteAt("Burrito", 10, 105);
        LCD.WriteAt("Rocket", 20, 105);

        LCD.DrawRectangle(110,100,100,50);
        LCD.WriteAt("Taco",120,105);
        LCD.WriteAt("Blade",130,105);

        LCD.DrawRectangle(0,160,100,50);
        LCD.WriteAt("Guac", 10, 165);
        LCD.WriteAt("Gun", 20, 165);
       

        LCD.DrawRectangle(110,160,100,50);
        LCD.WriteAt("Salsa", 120, 165);
        LCD.WriteAt("Sword", 130, 165);

    } 

            */
    }//end of while not touch

         
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
        LCD.WriteAt("Burger", 10, 105);
        LCD.WriteAt("Blast", 10, 125);

        LCD.DrawRectangle(110,100,100,50);
        LCD.WriteAt("McNugget",120,105);
        LCD.WriteAt("Grenade",120,125);

        LCD.DrawRectangle(0,160,100,50);
        LCD.WriteAt("Big", 10, 165);
        LCD.WriteAt("Mac", 21, 185);

        LCD.DrawRectangle(110,160,100,50);
        LCD.WriteAt("McFlurry", 120, 165);
        LCD.WriteAt("Blizzard", 120, 185);
        
    } else if (charname == 'P'){
        LCD.DrawRectangle(0,100, 100, 50);
        LCD.WriteAt("Pepperoni", 10, 105);
        LCD.WriteAt("Razor", 10, 125);

        LCD.DrawRectangle(110,100,100,50);
        LCD.WriteAt("Cheese",120,105);
        LCD.WriteAt("Cannon",120,125);

        LCD.DrawRectangle(0,160,100,50);
        LCD.WriteAt("Pizza", 10, 165);
        LCD.WriteAt("Sauce", 10, 185);

        LCD.DrawRectangle(110,160,100,50);
        LCD.WriteAt("Crust", 120, 165);
        LCD.WriteAt("Whip", 120, 185);

    } else if (charname == 'C'){
        LCD.DrawRectangle(0,100, 100, 50);
        LCD.WriteAt("Burrito", 10, 105);
        LCD.WriteAt("Rocket", 20, 125);

        LCD.DrawRectangle(110,100,100,50);
        LCD.WriteAt("Taco",120,105);
        LCD.WriteAt("Blade",120,125);

        LCD.DrawRectangle(0,160,100,50);
        LCD.WriteAt("Guac", 10, 165);
        LCD.WriteAt("Gun", 10, 185);
       

        LCD.DrawRectangle(110,160,100,50);
        LCD.WriteAt("Salsa", 120, 165);
        LCD.WriteAt("Sword", 120, 185);

    }


    while (hb.health > 0 && bosshp.health > 0){

        
        //character touch-movement detection here
        while (!LCD.Touch(&a, &b)) {
        }
            randint = RandInt() % 4;

            if (charname == 'M'){
                if ((a >= 0 && a <= 100) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(30);
                    
                    usermove = "Burger Blast";

                    if (randint == 0){
                        hb.DamageTaken(15);
                        bossmove = "Pepperoni Razor";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(40);
                        bossmove = "Cheese Cannon";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(30);
                        bossmove = "Pizza Sauce";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(15);
                        bossmove = "Crust Whip";
    
                    }
                   
                   

                } else if ((a >= 0 && a <= 100) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(60);
                    
                    usermove = "Big Mac";

                    if (randint == 0){
                        hb.DamageTaken(15);
                        bossmove = "Pepperoni Razor";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(40);
                        bossmove = "Cheese Cannon";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(30);
                        bossmove = "Pizza Sauce";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(15);
                        bossmove = "Crust Whip";
    
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(60);
                    usermove = "McNugget Grenade";
                        
                    if (randint == 0){
                        hb.DamageTaken(15);
                        bossmove = "Pepperoni Razor";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(40);
                        bossmove = "Cheese Cannon";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(30);
                        bossmove = "Pizza Sauce";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(15);
                        bossmove = "Crust Whip";
    
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(15);
                    usermove = "McFlurry Blizzard";

                    if (randint == 0){
                        hb.DamageTaken(15);
                        bossmove = "Pepperoni Razor";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(40);
                        bossmove = "Cheese Cannon";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(30);
                        bossmove = "Pizza Sauce";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(15);
                        bossmove = "Crust Whip";
    
                    }

                }
            } else if (charname == 'P'){
                if ((a >= 0 && a <= 100) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(15);
                    usermove = "Pepperoni Razor";
                        
                    if (randint == 0){
                        hb.DamageTaken(15);
                        bossmove = "Pepperoni Razor";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(30);
                        bossmove = "Cheese Cannon";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(30);
                        bossmove = "Pizza Sauce";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(15);
                        bossmove = "Crust Whip";
    
                    }

                } else if ((a >= 0 && a <= 100) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(15);
                    usermove = "Pizza Sauce";

                    if (randint == 0){
                        hb.DamageTaken(15);
                        bossmove = "Pepperoni Razor";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(30);
                        bossmove = "Cheese Cannon";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(30);
                        bossmove = "Pizza Sauce";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(15);
                        bossmove = "Crust Whip";
    
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(60);
                    usermove = "Cheese Cannon";
                        
                    if (randint == 0){
                        hb.DamageTaken(15);
                        bossmove = "Pepperoni Razor";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(30);
                        bossmove = "Cheese Cannon";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(30);
                        bossmove = "Pizza Sauce";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(15);
                        bossmove = "Crust Whip";
    
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(60);
                    usermove = "Crust Whip";

                    if (randint == 0){
                        hb.DamageTaken(15);
                        bossmove = "Pepperoni Razor";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(30);
                        bossmove = "Cheese Cannon";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(30);
                        bossmove = "Pizza Sauce";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(15);
                        bossmove = "Crust Whip";
    
                    }

                }
            } else if (charname == 'C'){
                 if ((a >= 0 && a <= 100) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(20);
                    usermove = "Burrito Rocket";
                    
 
                    if (randint == 0){
                        hb.DamageTaken(30);
                        bossmove = "Pepperoni Razor";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(40);
                        bossmove = "Cheese Cannon";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(30);
                        bossmove = "Pizza Sauce";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(60);
                        bossmove = "Crust Whip";
    
                    }

                } else if ((a >= 0 && a <= 100) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(60);
                    usermove = "Guac Gun";


                    if (randint == 0){
                        hb.DamageTaken(30);
                        bossmove = "Pepperoni Razor";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(40);
                        bossmove = "Cheese Cannon";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(30);
                        bossmove = "Pizza Sauce";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(60);
                        bossmove = "Crust Whip";
    
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(40);
                    usermove = "Taco Blade";

                    if (randint == 0){
                        hb.DamageTaken(30);
                        bossmove = "Pepperoni Razor";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(40);
                        bossmove = "Cheese Cannon";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(30);
                        bossmove = "Pizza Sauce";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(60);
                        bossmove = "Crust Whip";
    
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(30);
                    usermove = "Salsa Sword";

                      if (randint == 0){
                        hb.DamageTaken(30);
                        bossmove = "Pepperoni Razor";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(40);
                        bossmove = "Cheese Cannon";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(30);
                        bossmove = "Pizza Sauce";
                    
                    } else if (randint == 3){
                        hb.DamageTaken(60);
                        bossmove = "Crust Whip";
    
                    }

                }

            }
             //LCD.Clear();
             DrawCharacter(charname,70,80);
        
            DrawBoss('P',200,80);

            LCD.SetDrawColor(LCD.Red);
            LCD.FillRectangle(70,50,(0.2) * hb.health,10);

        

            LCD.SetDrawColor(LCD.Red);
            LCD.FillRectangle(200,50,(0.2) * bosshp.health,10);

     
    /*

    if (charname == 'M'){
        LCD.DrawRectangle(0,100, 100, 50);
        LCD.WriteAt("Burger", 10, 105);
        LCD.WriteAt("Blast", 20, 105);

        LCD.DrawRectangle(110,100,100,50);
        LCD.WriteAt("McNugget",120,105);
        LCD.WriteAt("Grenade",130,105);

        LCD.DrawRectangle(0,160,100,50);
        LCD.WriteAt("Big", 10, 165);
        LCD.WriteAt("Mac", 20, 165);

        LCD.DrawRectangle(110,160,100,50);
        LCD.WriteAt("McFlurry", 120, 165);
        LCD.WriteAt("Blizzard", 130, 165);
        
    } else if (charname == 'P'){
        LCD.DrawRectangle(0,100, 100, 50);
        LCD.WriteAt("Pepperoni", 10, 105);
        LCD.WriteAt("Razor", 20, 105);

        LCD.DrawRectangle(110,100,100,50);
        LCD.WriteAt("Cheese",120,105);
        LCD.WriteAt("Cannon",130,105);

        LCD.DrawRectangle(0,160,100,50);
        LCD.WriteAt("Pizza", 10, 165);
        LCD.WriteAt("Sauce", 20, 165);

        LCD.DrawRectangle(110,160,100,50);
        LCD.WriteAt("Crust", 120, 165);
        LCD.WriteAt("Whip", 130, 165);

    } else if (charname == 'C'){
        LCD.DrawRectangle(0,100, 100, 50);
        LCD.WriteAt("Burrito", 10, 105);
        LCD.WriteAt("Rocket", 20, 105);

        LCD.DrawRectangle(110,100,100,50);
        LCD.WriteAt("Taco",120,105);
        LCD.WriteAt("Blade",130,105);

        LCD.DrawRectangle(0,160,100,50);
        LCD.WriteAt("Guac", 10, 165);
        LCD.WriteAt("Gun", 20, 165);
       

        LCD.DrawRectangle(110,160,100,50);
        LCD.WriteAt("Salsa", 120, 165);
        LCD.WriteAt("Sword", 130, 165);

    }
            /*LCD.WriteAt("User move:",230,80);
            LCD.WriteAt(usermove,230,100);
            
            LCD.WriteAt("Boss move:",230,120);
            LCD.WriteAt(bossmove,230,140);*/
           
            
    }//end of while not touch v1

 
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
        LCD.WriteAt("Burger", 10, 105);
        LCD.WriteAt("Blast", 20, 105);

        LCD.DrawRectangle(110,100,100,50);
        LCD.WriteAt("McNugget",120,105);
        LCD.WriteAt("Grenade",130,105);

        LCD.DrawRectangle(0,160,100,50);
        LCD.WriteAt("Big", 10, 165);
        LCD.WriteAt("Mac", 20, 165);

        LCD.DrawRectangle(110,160,100,50);
        LCD.WriteAt("McFlurry", 120, 165);
        LCD.WriteAt("Blizzard", 130, 165);
        
    } else if (charname == 'P'){
        LCD.DrawRectangle(0,100, 100, 50);
        LCD.WriteAt("Pepperoni", 10, 105);
        LCD.WriteAt("Razor", 20, 105);

        LCD.DrawRectangle(110,100,100,50);
        LCD.WriteAt("Cheese",120,105);
        LCD.WriteAt("Cannon",130,105);

        LCD.DrawRectangle(0,160,100,50);
        LCD.WriteAt("Pizza", 10, 165);
        LCD.WriteAt("Sauce", 20, 165);

        LCD.DrawRectangle(110,160,100,50);
        LCD.WriteAt("Crust", 120, 165);
        LCD.WriteAt("Whip", 130, 165);

    } else if (charname == 'C'){
        LCD.DrawRectangle(0,100, 100, 50);
        LCD.WriteAt("Burrito", 10, 105);
        LCD.WriteAt("Rocket", 20, 105);

        LCD.DrawRectangle(110,100,100,50);
        LCD.WriteAt("Taco",120,105);
        LCD.WriteAt("Blade",130,105);

        LCD.DrawRectangle(0,160,100,50);
        LCD.WriteAt("Guac", 10, 165);
        LCD.WriteAt("Gun", 20, 165);
       

        LCD.DrawRectangle(110,160,100,50);
        LCD.WriteAt("Salsa", 120, 165);
        LCD.WriteAt("Sword", 130, 165);

    }


    while (hb.health > 0 && bosshp.health > 0){

        
        //character touch-movement detection here
        while (!LCD.Touch(&a, &b)) {
        }//end of while not touch
            randint = RandInt() % 4;

            if (charname == 'M'){
                 if ((a >= 0 && a <= 100) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(50);
                    
                    usermove = "Burger Blast";

                    if (randint == 0){
                        hb.DamageTaken(20);
                        bossmove = "Rain of Chips";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(20);
                        bossmove = "Coke+Mentos";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(20);
                        bossmove = "Ultimate Pepsi";
                    
                    } else if (randint == 3){
                        bosshp.HealthPotion(10);
                        bossmove = "Gatorade Powerup";
    
                    }
                   
                 }

                else if ((a >= 0 && a <= 100) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(50);
                    
                    usermove = "Big Mac";

                    if (randint == 0){
                        hb.DamageTaken(20);
                        bossmove = "Rain of Chips";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(20);
                        bossmove = "Coke+Mentos";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(20);
                        bossmove = "Ultimate Pepsi";
                    
                    } else if (randint == 3){
                        bosshp.HealthPotion(10);
                        bossmove = "Gatorade Powerup";
    
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(50);
                    usermove = "McNugget Grenade";
                        

                    if (randint == 0){
                        hb.DamageTaken(20);
                        bossmove = "Rain of Chips";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(20);
                        bossmove = "Coke+Mentos";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(20);
                        bossmove = "Ultimate Pepsi";
                    
                    } else if (randint == 3){
                        bosshp.HealthPotion(10);
                        bossmove = "Gatorade Powerup";
    
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(50);
                    usermove = "McFlurry Blizzard";


                    if (randint == 0){
                        hb.DamageTaken(20);
                        bossmove = "Rain of Chips";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(20);
                        bossmove = "Coke+Mentos";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(20);
                        bossmove = "Ultimate Pepsi";
                    
                    } else if (randint == 3){
                        bosshp.HealthPotion(10);
                        bossmove = "Gatorade Powerup";
    
                    }

                }
            } else if (charname == 'P'){
                if ((a >= 0 && a <= 100) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(50);
                    usermove = "Pepperoni Razor";
                        
                    if (randint == 0){
                        hb.DamageTaken(20);
                        bossmove = "Rain of Chips";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(20);
                        bossmove = "Coke+Mentos";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(20);
                        bossmove = "Ultimate Pepsi";
                    
                    } else if (randint == 3){
                        bosshp.HealthPotion(10);
                        bossmove = "Gatorade Powerup";
    
                    }

                } else if ((a >= 0 && a <= 100) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(50);
                    usermove = "Pizza Sauce";

                    if (randint == 0){
                        hb.DamageTaken(20);
                        bossmove = "Rain of Chips";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(20);
                        bossmove = "Coke+Mentos";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(20);
                        bossmove = "Ultimate Pepsi";
                    
                    } else if (randint == 3){
                        bosshp.HealthPotion(10);
                        bossmove = "Gatorade Powerup";
    
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(50);
                    usermove = "Cheese Cannon";
                        
                    if (randint == 0){
                        hb.DamageTaken(20);
                        bossmove = "Rain of Chips";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(20);
                        bossmove = "Coke+Mentos";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(20);
                        bossmove = "Ultimate Pepsi";
                    
                    } else if (randint == 3){
                        bosshp.HealthPotion(10);
                        bossmove = "Gatorade Powerup";
    
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(50);
                    usermove = "Crust Whip";

                    if (randint == 0){
                        hb.DamageTaken(20);
                        bossmove = "Rain of Chips";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(20);
                        bossmove = "Coke+Mentos";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(20);
                        bossmove = "Ultimate Pepsi";
                    
                    } else if (randint == 3){
                        bosshp.HealthPotion(10);
                        bossmove = "Gatorade Powerup";
    
                    }

                }
            } else if (charname == 'C'){
                 if ((a >= 0 && a <= 100) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(20);
                    usermove = "Burrito Rocket";
                    
 
                    if (randint == 0){
                        hb.DamageTaken(20);
                        bossmove = "Rain of Chips";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(20);
                        bossmove = "Coke+Mentos";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(20);
                        bossmove = "Ultimate Pepsi";
                    
                    } else if (randint == 3){
                        bosshp.HealthPotion(10);
                        bossmove = "Gatorade Powerup";
    
                    }

                } else if ((a >= 0 && a <= 100) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(60);
                    usermove = "Guac Gun";



                    if (randint == 0){
                        hb.DamageTaken(20);
                        bossmove = "Rain of Chips";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(20);
                        bossmove = "Coke+Mentos";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(20);
                        bossmove = "Ultimate Pepsi";
                    
                    } else if (randint == 3){
                        bosshp.HealthPotion(10);
                        bossmove = "Gatorade Powerup";
    
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 100 && b <= 150)){

                    bosshp.DamageTaken(40);
                    usermove = "Taco Blade";


                    if (randint == 0){
                        hb.DamageTaken(20);
                        bossmove = "Rain of Chips";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(20);
                        bossmove = "Coke+Mentos";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(20);
                        bossmove = "Ultimate Pepsi";
                    
                    } else if (randint == 3){
                        bosshp.HealthPotion(10);
                        bossmove = "Gatorade Powerup";
    
                    }

                } else if ((a >= 110 && a <= 210) && (b >= 160 && b <= 210)){

                    bosshp.DamageTaken(30);
                    usermove = "Salsa Sword";


                    if (randint == 0){
                        hb.DamageTaken(20);
                        bossmove = "Rain of Chips";
                        
                    } else if (randint == 1){
                        hb.DamageTaken(20);
                        bossmove = "Coke+Mentos";
                        
                    } else if (randint == 2){
                        hb.DamageTaken(20);
                        bossmove = "Ultimate Pepsi";
                    
                    } else if (randint == 3){
                        bosshp.HealthPotion(10);
                        bossmove = "Gatorade Powerup";
    
                    }

                }

            }
            // LCD.Clear();
             //DrawCharacter(charname,70,80);
        
            //DrawBoss('Pe',200,80);

            LCD.SetDrawColor(LCD.Red);
            LCD.FillRectangle(70,50,(0.2) * hb.health,10);

        

            LCD.SetDrawColor(LCD.Red);
            LCD.FillRectangle(200,50,(0.2) * bosshp.health,10);
        //}//end of while not touch
     /*


    if (charname == 'M'){
        LCD.DrawRectangle(0,100, 100, 50);
        LCD.WriteAt("Burger", 10, 105);
        LCD.WriteAt("Blast", 20, 105);

        LCD.DrawRectangle(110,100,100,50);
        LCD.WriteAt("McNugget",120,105);
        LCD.WriteAt("Grenade",130,105);

        LCD.DrawRectangle(0,160,100,50);
        LCD.WriteAt("Big", 10, 165);
        LCD.WriteAt("Mac", 20, 165);

        LCD.DrawRectangle(110,160,100,50);
        LCD.WriteAt("McFlurry", 120, 165);
        LCD.WriteAt("Blizzard", 130, 165);
        
    } else if (charname == 'P'){
        LCD.DrawRectangle(0,100, 100, 50);
        LCD.WriteAt("Pepperoni", 10, 105);
        LCD.WriteAt("Razor", 20, 105);

        LCD.DrawRectangle(110,100,100,50);
        LCD.WriteAt("Cheese",120,105);
        LCD.WriteAt("Cannon",130,105);

        LCD.DrawRectangle(0,160,100,50);
        LCD.WriteAt("Pizza", 10, 165);
        LCD.WriteAt("Sauce", 20, 165);

        LCD.DrawRectangle(110,160,100,50);
        LCD.WriteAt("Crust", 120, 165);
        LCD.WriteAt("Whip", 130, 165);

     }
    
    else if (charname == 'C'){
        LCD.DrawRectangle(0,100, 100, 50);
        LCD.WriteAt("Burrito", 10, 105);
        LCD.WriteAt("Rocket", 20, 105);

        LCD.DrawRectangle(110,100,100,50);
        LCD.WriteAt("Taco",120,105);
        LCD.WriteAt("Blade",130,105);

        LCD.DrawRectangle(0,160,100,50);
        LCD.WriteAt("Guac", 10, 165);
        LCD.WriteAt("Gun", 20, 165);
       

        LCD.DrawRectangle(110,160,100,50);
        LCD.WriteAt("Salsa", 120, 165);
        LCD.WriteAt("Sword", 130, 165);
    }
    */

            /*LCD.WriteAt("User move:",230,80);
            LCD.WriteAt(usermove,230,100);
            
            LCD.WriteAt("Boss move:",230,120);
            LCD.WriteAt(bossmove,230,140);  */      

    if (bosshp.health <= 0){
        return 1;
    } else if (hb.health <= 0){
        return 0;
    }
    }//end of while loop
    }//end of level 4

}//end of the boss function