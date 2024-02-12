
//Libraries
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

//TADS
#include "menu.c"


//Main
int main(void)
{
    
    //Screen Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "UNOs");
    SetTargetFPS(60);  
    
    //Menu Inicialization
    Menu* menu = InitMenu(); 
    
    // Main game loop
    while (!WindowShouldClose()) //While Esc or leave window(x) arent pressed 
    {
        ProcessMenuInput(menu);
        
        BeginDrawing(); //Drawing
        
            ClearBackground(RAYWHITE);
            
            DrawMenu(menu); //Menu Drawing
            
            

        EndDrawing(); //End Drawing
        
    } //Left Game loop

    CloseWindow();  //Close the Windown
    
    //Free in the memory spaces
    free(menu);
    
    return 0;
}