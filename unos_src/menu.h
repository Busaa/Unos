//Implementação do TAD para o MENU menu.h
//TAD Menu

#ifndef MENU_H
#define MENU_H

#include "raylib.h"


typedef enum MenuOption { //Defines the possible options the menu 
    PLAY,
    CONFIGURATION,
    LEADERBOARD,
    EXIT
}MenuOption;

typedef struct Menu { //Define the structure menu, that will always have one of the menus options chossen
    MenuOption currentOption;
}Menu;

Menu* InitMenu(void); //function to Inicializate the menu 
void UpdateMenu(Menu* menu); //Updates the Menu
void DrawMenu(Menu* menu);
void ProcessMenuInput(Menu* menu);

#endif // MENU_H end