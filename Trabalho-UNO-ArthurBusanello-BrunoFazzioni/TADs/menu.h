//Implementação do TAD para o MENU menu.h
//TAD Menu

#ifndef MENU_H
#define MENU_H

#include "raylib.h"

//Structures

typedef enum MenuOption { //Defines the possible options the menu 
    PLAY,
    CONFIGURATION,
    LOAD,
    LEADERBOARD,
    EXIT
}MenuOption;

typedef struct Menu { //Define the structure menu, that will always have one of the menus options chossen
    MenuOption currentOption;
}Menu;

typedef struct Audio{ //For Music, background ost etc
    bool muted;
    float volume;
    Sound sound;
}Audio;

//Functions

Menu* InitMenu(void); //function to Inicializate the menu 
void UpdateMenu(Menu* menu); //Updates the Menu
void DrawMenu(Menu* menu);
void ProcessMenuInput(Menu* menu);
void PlayAudio(Audio* audio);
Audio* InitAudio(const char* filename);
void UnloadAudio(Audio* audio);

#endif // MENU_H end
