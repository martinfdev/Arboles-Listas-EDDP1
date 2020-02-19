/* 
 * File:   Ventana.cpp
 * Author: pedro
 * 
 * Created on February 18, 2020, 5:09 PM
 */
#include <ncurses.h>
#include <menu.h>
#include <string>
#include "Ventana.h"

Ventana::Ventana(LinkedDoubleList *listaText)
{
    this->listaText = listaText;
}
void Ventana::menu()
{
    /* Create the window to be associated with the menu */
    //height and width declared in private headers
    initHeadCurses();
    getmaxyx(stdscr, height, width);
    keypad(my_win, TRUE);
    //mvprintw(LINES - 3, 3, "F1 to exit");
    refresh();
    my_win = create_newwin(height - 5, width - 5, 1, 3);
    
    //set titles to menu
    mvwprintw(my_win, 1, (width/2)-20, "UNIVERSIDAD DE SAN CARLOS DE GUATEMALA");
    mvwprintw(my_win, 2, (width/2)-20, "FACULTAD DE INGENIERIA");
    mvwprintw(my_win, 3, (width/2)-20, "ESTRUCTURA DE DATOS");
    mvwprintw(my_win, 4, (width/2)-20, "PRACTICA 1");
    mvwprintw(my_win, 5, (width/2)-20, "PEDRO MARTIN FRANCISCO");
    mvwprintw(my_win, 6, (width/2)-20, "201700656");
    mvwprintw(my_win, 10, (width/2)-20, "MENU");
    mvwprintw(my_win, 11, (width/2)-20, "1. Crear Archivo");
    mvwprintw(my_win, 12, (width/2)-20, "2. Abrir Archivo");
    mvwprintw(my_win, 13, (width/2)-20, "3. Archivos Recientes");
    mvwprintw(my_win, 14, (width/2)-20, "4. Salir");
    wrefresh(my_win);

    while((ch = getch()) != 52)
	{	   
        switch(ch)
		{	case 49:
				destroy_win(my_win);
                crearArchivo();
				break;
			case 50:
				destroy_win(my_win);
			//	my_win = create_newwin(height, width, starty,++startx);
				break;
			case 51:
				destroy_win(my_win);
			//	my_win = create_newwin(height, width, --starty,startx);
				break;
			case KEY_DOWN:
				destroy_win(my_win);
			//	my_win = create_newwin(height, width, ++starty,startx);
				break;	
		}
	}
    endwin();
    listaText->show();
}

void Ventana::crearArchivo(){
   /* Create the window to be associated with the menu */
    //height and width declared in private headers
    raw();
    getmaxyx(stdscr, height, width);
    mvprintw(LINES - 3, 5, "^w  (Buscar y Reemplazar)");
    mvprintw(LINES - 3, 40, "^c  (Reportes)");
    mvprintw(LINES - 3, 70, "^s  (Guardar)");
    mvprintw(LINES - 3, 90, "F1 para  Menu");
    refresh();
   
    my_win = create_newwin(height - 5, width - 5, 1, 3);
    keypad(my_win, TRUE);
    wmove(my_win, 2, 2);
    keypad(my_win, true);
    //mvcur(height - 5, width - 5, 5, 5);
    echo();
    wclrtoeol(my_win);
    wrefresh(my_win);
    
    while ((ch = wgetch(my_win)) != KEY_F(1))
    {
       if (ch == KEY_BACKSPACE)
       {
            listaText->borrarFinal();   
       }else if(ch == 127){
           listaText->borrarFinal();
           wrefresh(my_win);
       }else{
           listaText->insertarUltimo(ch);
       }
    }
    destroy_win(my_win);
    clear();
    menu();
}

WINDOW *Ventana::create_newwin(int height, int width, int starty, int startx)
{
    WINDOW *local_win;
    local_win = newwin(height, width, starty, startx);
    box(local_win, 0, 0); /* 0, 0 gives default characters 
					 * for the vertical and horizontal
					 * lines			*/
    wrefresh(local_win);  /* Show that box 		*/
    return local_win;
}

void Ventana::destroy_win(WINDOW *local_win)
{
    /* box(local_win, ' ', ' '); : This won't produce the desired
	 * result of erasing the window. It will leave it's four corners 
	 * and so an ugly remnant of window. 
	 */
    wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    /* The parameters taken are 
	 * 1. win: the window on which to operate
	 * 2. ls: character to be used for the left side of the window 
	 * 3. rs: character to be used for the right side of the window 
	 * 4. ts: character to be used for the top side of the window 
	 * 5. bs: character to be used for the bottom side of the window 
	 * 6. tl: character to be used for the top left corner of the window 
	 * 7. tr: character to be used for the top right corner of the window 
	 * 8. bl: character to be used for the bottom left corner of the window 
	 * 9. br: character to be used for the bottom right corner of the window
	 */
    wrefresh(local_win);
    delwin(local_win);
}

void Ventana::initHeadCurses(){
    initscr();
    cbreak();
   // raw();
    noecho();
    keypad(stdscr, true);
}


Ventana::~Ventana()
{   
}
