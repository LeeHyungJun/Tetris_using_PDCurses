/***********************************************
*                                              *
*	학번 : 20113315		                       *
*	이름 : 이형준                              *
*                                              *
***********************************************/
#include <curses.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include "Window_name.h"

window_name :: window_name(int nlines, int ncols, int begy, int begx, char* username)
{
	name = newwin(nlines, ncols, begy, begx);
	wborder(name, '|', '|', '-', '-', '+', '+', '+', '+');
	wattron(name, COLOR_PAIR(12));
	mvwprintw(name, 1, 1, "name:");
	mvwprintw(name, 2, 1, username);
	wattroff(name, COLOR_PAIR(12));
	wrefresh(name);
}