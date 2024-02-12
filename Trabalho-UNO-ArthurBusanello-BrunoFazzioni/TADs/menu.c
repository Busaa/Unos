//Arquivo com a implementações das funções do TAD menu menu.c
//TAD functions for Menu

#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

//InitMenu initializes the menu with the play option selected
Menu* InitMenu(void) { 
    Menu* menu = (Menu*)malloc(sizeof(Menu));
    if (!menu) exit(1); // Handle memory allocation failure

    menu->currentOption = PLAY; // Start with first option selected

    return menu;
}

//Updates to take the inputs from the keyboard
void MenuKeysInputs(Menu* menu) {
    // Check if the Enter key is pressed and execute the corresponding action
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
        switch(menu->currentOption) {
            case PLAY:
                // Start gameplay
                break;
            case LEADERBOARD:
                // Show leaderboard
                break;
            case CONFIGURATION:
                // Open configuration menu
                break;
            case EXIT:
                // Close window
                CloseWindow();
                break;
            default:
                break;
        }
    }
}

//Draws the menu 
void DrawMenu(Menu* menu) {
    
    DrawText("PLAY", 400, 50, 40, menu->currentOption == PLAY ? RED : BLACK);
    DrawText("LEADEARBOARD", 400, 100, 40, menu->currentOption == LEADERBOARD ? RED : BLACK);
    DrawText("CONFIGURATION", 400, 150, 40, menu->currentOption == CONFIGURATION ? RED : BLACK);
    DrawText("EXIT", 400, 200, 40, menu->currentOption == EXIT ? RED : BLACK);
}

//Processes the Menu Inputs
void ProcessMenuInput(Menu* menu) {
    
    // Handle input events to change menu selection
    if (IsKeyPressed(KEY_UP)) {
        switch(menu->currentOption) {
            case PLAY:
                menu->currentOption = EXIT;
                break;
            case LEADERBOARD:
                menu->currentOption = PLAY;
                break;
            case CONFIGURATION:
                menu->currentOption = LEADERBOARD;
                break;
            case EXIT:
                menu->currentOption = CONFIGURATION;
                break;
            default:
                break;
        }
    } else if (IsKeyPressed(KEY_DOWN)) {
        switch(menu->currentOption) {
            case PLAY:
                menu->currentOption = LEADERBOARD;
                break;
            case LEADERBOARD:
                menu->currentOption = CONFIGURATION;
                break;
            case CONFIGURATION:
                menu->currentOption = EXIT;
                break;
            case EXIT:
                menu->currentOption = PLAY;
                break;
            default:
                break;
        }
    } else if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
        // Execute selected option
        switch(menu->currentOption) {
            case PLAY:
                // Start gameplay
                break;
            case LEADERBOARD:
                // Show leaderboard
                break;
            case CONFIGURATION:
                // Open configuration menu
                break;
            case EXIT:
                // Exit game
                break;
            default:
                break;
        }
    }
    //After moving the options the player can choose one
    MenuKeysInputs(menu);
}