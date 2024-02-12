
//Libraries
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TADS
#include "menu.c"
#include "Uno.h"
#include "pilha_enc.h"
#include "fila_enc.h"
#include "lista_enc_dupla.h"
#include "lista_circ_enc_dupla.h"
#include "deque_enc.h"


//Main
int main(void)
{
    // Iniciando variáveis
    PilhaEnc baralho;
    PilhaEnc mesa;
    ListaCirc2 ordem_jogadores;
    
    
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
