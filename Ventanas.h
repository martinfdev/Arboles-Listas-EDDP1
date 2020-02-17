/* 
 * File:   Ventanas.h
 * Author: pedro
 *
 * Created on February 16, 2020, 2:21 PM
 */

#ifndef VENTANAS_H
#define VENTANAS_H
#include <ncurses.h>
#include <menu.h>
#include <stdexcept>
#include <iostream>
class Ventanas
{

public:
    Ventanas();
    void menu();
    void print_in_middle(WINDOW *win, int starty, int startx, int width, char* string, chtype color);
    void nuevaVentana();
    ~Ventanas();

private:
    ITEM **my_items;
    int c;
    MENU *my_menu;
    WINDOW *my_menu_win;
    int n_choices, i;
     int width, height;
};
#endif /* VENTANAS_H */