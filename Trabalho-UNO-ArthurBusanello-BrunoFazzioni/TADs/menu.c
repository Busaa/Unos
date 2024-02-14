//Arquivo com a implementações das funções do TAD menu menu.c
//TAD functions for Menu

#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"


//InitMenu initializes the menu with the play option selected, also loads all textures and audios for the game
Menu* InitMenu(void) { 
        
    //Screen Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "UNOs");
    SetTargetFPS(60);


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
            case BOSS:
                //star boss yugi battle
                break;
            case LOAD:
                //LOAD last save
                break;
            case LEADERBOARD:
                //show table leaderboard
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
void DrawMenu(Menu* menu, Audio* menuMusic, Texture2D audioIcon, Texture2D redX) {
    
    //Background
    //desenha aui o background
    
    //Options
    DrawText("PLAY", 400, 50, 40, menu->currentOption == PLAY ? RED : BLACK);
    DrawText("BOSS", 400, 100, 40, menu->currentOption == BOSS ? RED : BLACK);
    DrawText("LOAD", 400, 150, 40, menu->currentOption == LOAD ? RED : BLACK);
    DrawText("LEADERBOARD", 400, 200, 40, menu->currentOption == LEADERBOARD ? RED : BLACK);
    DrawText("CONFIGURATION", 400, 250, 40, menu->currentOption == CONFIGURATION ? RED : BLACK);
    DrawText("EXIT", 400, 300, 40, menu->currentOption == EXIT ? RED : BLACK);
    
    
    
    
    //Icons
    DrawTexture(audioIcon, 30, 380, BLACK);
    if (menuMusic->muted == true)
        DrawTexture(redX, 30, 380, WHITE);
    
}

//Processes the Menu Inputs
void ProcessMenuInput(Menu* menu, Audio* menuMusic) {
    
    // Handle input events to change menu selection
    if (IsKeyPressed(KEY_UP)) {
        switch(menu->currentOption) {
            case PLAY:
                menu->currentOption = EXIT;
                break;
            case BOSS:
                menu->currentOption = PLAY;
                break;
            case LOAD:
                menu->currentOption = BOSS;
                break;
            case LEADERBOARD:
                menu->currentOption = LOAD;
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
                menu->currentOption = BOSS;
                break;
            case BOSS:
                menu->currentOption = LOAD;
                break;
            case LOAD:
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
    } else if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) { //ENTER
        // Execute selected option
        switch(menu->currentOption) {
            case PLAY:
                // Start gameplay
                break;
            case LOAD:
                //Load last save
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
    }else if (IsKeyPressed(KEY_M)){ //Mutando e desmutando o som
        if (menuMusic->muted == true){
            ResumeSound(menuMusic->sound);
            menuMusic->muted = false;
        }
        else {
            PauseSound(menuMusic->sound);
            menuMusic->muted = true;
        }
    }
    //After moving the options the player can choose one
    MenuKeysInputs(menu);
}

//Sound Desing Things

//Initialize a Music/Song/Sound with an file, initialize unMuted 0.5 volume
Audio* InitAudio(const char* filename) {
    Audio* audio = (Audio*)malloc(sizeof(Audio));
    if (!audio) {
        //Memory alocation error
        return NULL;
    }
    audio->muted = false; //ta un-mutado
    audio->volume = 0.5f; 
    audio->sound = LoadSound(filename); 

    return audio;
}

void UnloadAudio(Audio* audio) {
    if (audio) {
        UnloadSound(audio->sound);
        free(audio);
    }
}



void PlayAudio(Audio* audio){ //Playing Music
    SetSoundVolume(audio->sound, audio->volume);
    if(audio->muted != true)
        PlaySound(audio->sound);
}
