/* 
 * File:   Ventanas.cpp
 * Author: pedro
 * 
 * Created on February 16, 2020, 2:21 PM
 */
#include <ncurses.h>
#include <menu.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include "Ventanas.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 4

char *choices[] = {
    "1.     Crear Archivo",
    "2.     Abrir Archivo",
    "3.     Archivos Recientes",
    "4.     Salir"};

Ventanas::Ventanas()
{   
    /* Initialize curses */
    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
}

void Ventanas::menu()
{
    /* Initialize curses */
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);

    /* Initialize items */
    n_choices = ARRAY_SIZE(choices);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    for (i = 0; i < n_choices; ++i)
        my_items[i] = new_item(choices[i], choices[i]);
    my_items[n_choices] = (ITEM *)NULL;
    //item_opts_off(my_items[1], O_SELECTABLE);
    //item_opts_off(my_items[2], O_SELECTABLE);

    /* Create menu */
    my_menu = new_menu((ITEM **)my_items);

    /* Set fore ground and back ground of the menu */
    set_menu_fore(my_menu, COLOR_PAIR(3) | A_REVERSE);
    set_menu_back(my_menu, COLOR_PAIR(4));
    set_menu_grey(my_menu, COLOR_PAIR(5));

    /* Create the window to be associated with the menu */
    //height and width declared in private headers
    getmaxyx(stdscr, height, width);
    my_menu_win = newwin(height - 5, width - 5, 1, 3);
    keypad(my_menu_win, TRUE);

    /* Set main window and sub window */
    //set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, height - 15, width - 15, 10, 2));

    /* Set menu mark to the string " * " */
    set_menu_mark(my_menu, " -> ");

    /* Print a border around the main window and print a title */
    box(my_menu_win, 0, 0);
    print_in_middle(my_menu_win, 1, width / 2, width / 2, "UNIVERSIDAD DE SAN CARLOS DE GUATEMALA", COLOR_PAIR(2));
    print_in_middle(my_menu_win, 2, width / 2, width / 2, "FACULTAD DE INGENIERIA", COLOR_PAIR(2));
    print_in_middle(my_menu_win, 3, width / 2, width / 2, "ESTRUCTURA DE DATOS", COLOR_PAIR(2));
    print_in_middle(my_menu_win, 4, width / 2, width / 2, "PRACTICA 1", COLOR_PAIR(2));
    print_in_middle(my_menu_win, 5, width / 2, width / 2, "ESTRUCTURA DE DATOS", COLOR_PAIR(2));
    print_in_middle(my_menu_win, 6, width / 2, width / 2, "PEDRO MARTIN FRANCISCO", COLOR_PAIR(2));
    print_in_middle(my_menu_win, 7, width / 2, width / 2, "201700656", COLOR_PAIR(2));

    mvwaddch(my_menu_win, 8, 0, ACS_LTEE);
    mvwhline(my_menu_win, 8, 1, ACS_HLINE, width - 7);
    mvwaddch(my_menu_win, 8, width - 6, ACS_RTEE);
    // mvprintw(LINES - 3, width / 2, "Press <ENTER> to see the option selected");
    //  mvprintw(LINES - 2, 0, "Up and Down arrow keys to naviage (F1 to Exit)");
    // mvprintw(LINES - 3, 3, "F1 to exit");
    refresh();

    /* Post the menu */
    post_menu(my_menu);
    wrefresh(my_menu_win);

    while ((c = wgetch(my_menu_win)) != KEY_F(1))
    {
        switch (c)
        {
        case KEY_DOWN:
            menu_driver(my_menu, REQ_DOWN_ITEM);
            break;
        case KEY_UP:
            menu_driver(my_menu, REQ_UP_ITEM);
            break;
        case 10: /* Enter */
            move(LINES - 6, 6);
            clrtoeol();
            mvprintw(LINES - 6, 4, "%s", item_name(current_item(my_menu)));
            const char *name = item_name(current_item(my_menu));
            char temp[strlen(name) + 1];
            strncpy(temp, name, strlen(name) + 1);
            char caracter= temp[0];
            int pos = pos_menu_cursor(my_menu);
            //mvprintw(LINES - 6, 4, "%c", cara);
            if ((int)caracter == 49)
            {
                nuevaVentana();
               
            }else if((int)caracter == 52){
                c = (int)caracter;
            }
            

            pos_menu_cursor(my_menu);
            refresh();
            break;
      
        }
        wrefresh(my_menu_win);
        refresh();
    }

    /* Unpost and free all the memory taken up */
    unpost_menu(my_menu);
    free_menu(my_menu);
    for (i = 0; i < n_choices; ++i)
        free_item(my_items[i]);
    endwin();
}

//Iprimir encabezado
void Ventanas::print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color)
{
    int length, x, y;
    float temp;

    if (win == NULL)
        win = stdscr;
    getmaxyx(win, y, x);
    if (startx != 0)
        x = startx;
    if (starty != 0)
        y = starty;
    if (width == 0)
        width = this->width;

    length = strlen(string);
    temp = (width / 2);
    x = startx + (int)temp;
    wattron(win, color);
    mvwprintw(win, y, x / 2, "%s", string);
    wattroff(win, color);
    refresh();
}

void Ventanas::nuevaVentana(){
    echo();
    getmaxyx(stdscr, height, width);
    my_menu_win = newwin(height - 5, width - 5, 1, 3);
    keypad(my_menu_win, TRUE);
    box(my_menu_win, 0, 0);
   
    mvprintw(LINES - 4, 5, "^w (Buscar y Reemplazar)");
    mvprintw(LINES - 4, 40, "^c (Reportes)");
    mvprintw(LINES - 4, 70, "^s (Guardar)");
    refresh();

}

Ventanas::~Ventanas()
{
}
