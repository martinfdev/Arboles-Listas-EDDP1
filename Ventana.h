/* 
 * File:   Ventana.h
 * Author: pedro
 *
 * Created on February 18, 2020, 5:09 PM
 */

#ifndef VENTANA_H
#define VENTANA_H
#include "LinkedDoubleList.h"
#include <ncurses.h>

class Ventana
{
public:
    Ventana(LinkedDoubleList *);
    void menu();
    WINDOW *create_newwin(int height, int width, int starty, int startx);
    void destroy_win(WINDOW *local_win);
    void crearArchivo();
    void abrirArchivo();
    void initHeadCurses();
    void archivosRecientes();
    ~Ventana();

private: 
    int ch;
    WINDOW *my_win;
    int width, height;
    LinkedDoubleList *listaText;
};

#endif /* VENTANA_H */
