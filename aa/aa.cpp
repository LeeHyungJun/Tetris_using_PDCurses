#include <curses.h>
#include <iostream>
#include <fstream>
#include <cstring>
int main()
{ 
char userName[8];
initscr();
keypad(stdscr, TRUE); 
curs_set(0); 
noecho();

		//int key=0;
		int k;
		//instream.open("input.txt");
		//if(instream.fail())	{key=getch();}
		//else
		//{
		//	instream >> k;
		//	if(k=='r')
		//		key=KEY_RIGHT;
		//}

		int key;
		key=getch();
		std::cout<<key;
refresh(); 
getch();
clear();
refresh(); 
getch(); 
endwin();
return 0; }