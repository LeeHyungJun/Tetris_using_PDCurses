/***********************************************
*   Hyungjun Lee
*	Kookmin University (South, Korea)
*   hjlee1765@gmail.com
*
***********************************************/
#include <curses.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include "Window_name.h"

window_name::window_name(int nlines, int ncols, int begy, int begx, char* username)
{
	name = newwin(nlines, ncols, begy, begx);
	wborder(name, '|', '|', '-', '-', '+', '+', '+', '+');
	wattron(name, COLOR_PAIR(12));
	mvwprintw(name, 1, 1, "!:");
	mvwprintw(name, 2, 1, username);
	wattroff(name, COLOR_PAIR(12));
	wrefresh(name);
}