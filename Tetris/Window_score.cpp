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
#include "Window_score.h"
#include "Window_game.h"

window_score::window_score(int nlines, int ncols, int begy, int begx)
{
	score = newwin(nlines, ncols, begy, begx);
	wborder(score, '|', '|', '-', '-', '+', '+', '+', '+');
	wattron(score, COLOR_PAIR(12));
	mvwprintw(score, 1, 1, "score:");
	mvwprintw(score, 2, 1, "0");
	wattroff(score, COLOR_PAIR(12));
	wrefresh(score);
}

void window_score::score_print()
{
	wattron(score, COLOR_PAIR(12));
	mvwprintw(score, 2, 1, "%d", window_game::score_up);
	wattroff(score, COLOR_PAIR(12));
	wrefresh(score);
}

