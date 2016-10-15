/***********************************************
*   Hyungjun Lee
*	Kookmin University (South, Korea)
*   hjlee1765@gmail.com
*
***********************************************/

//현재 보드판배열은 18*19 상태이며 세로는 출력판과 동일하고 가로로는 2칸씩 있으며 각각 1,3,5,7,9,11,13,15,17,19 항에 1씩이 들어가있는 상태입니다.

#include <curses.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include "Window_game.h"
#include "Window_name.h"
#include "Window_score.h"

#define height 18
#define width 10


char input_key();
void define_init_pair();


int main(int argc, char* argv[])
{
	char cur_key, username[8];
	int seed;
	std::ifstream inStream;
	if (argc>1)
		inStream.open(argv[1]);

	if (argc>1)
		inStream >> username >> seed;
	else
	{
		std::cout << "Start Game" << std::endl << std::endl;
		std::cout << "Input your name" << std::endl << std::endl;
		std::cout << "Name : ";
		scanf("%s", username);
		seed = time(NULL);
	}
	srand(seed);

	initscr();
	resize_term(25, 50);
	curs_set(0);
	start_color();
	define_init_pair();											//빠레트 정의해주는 함수

	border('|', '|', '-', '-', '+', '+', '+', '+');
	attron(COLOR_PAIR(11));
	mvprintw(1, 1, "Welcome To the Tetris Game");
	attroff(COLOR_PAIR(11));
	refresh();

	window_game game(20, 22, 2, 2, 0, 0, 0, seed);
	window_score score(4, 10, 4, 30);
	window_name name(4, 10, 10, 30, username);

	game.board_init();											//보드판 행렬 초기화, 초기 x,y좌표 초기화
	while (!game.game_over())									//블럭이 맨 윗줄에 도착시 gameover
	{
		game.init();											// 처음위에 네모칸 등장	
		while (!game.q_click() && window_game::stop == 0)			//q눌리면 gameover && 블록이 바닥에 도착하면 stop++
		{
			if (argc > 1)
				inStream >> cur_key;
			else
				cur_key = input_key();
			game.update(cur_key);					//키를 입력받아서 움직임
		}
		if (game.q_click())							// q 눌렸을때 스탑.
			break;
		else										//q 버튼이 안눌렸을때. 일반적 진행
		{
			game.display();							// display 함과 동시에 보드 배열에 네모있으면 1박아준다. x.y좌표 초기화
			score.score_print();					//점수표시
		}
	}

	mvprintw(22, 10, "score is %d", window_game::score_up);
	mvprintw(23, 10, "Press any key to exit Tetris");
	refresh();

	getch();
	endwin();
	return 0;
}

char input_key()
{
	int key;
	char a;
	keypad(stdscr, TRUE);
	curs_set(0);
	noecho();
	key = getch();
	if (key == 261)	//오른쪽
		a = 'r';
	else if (key == 260)		//왼쪽
		a = 'l';
	else if (key == 258)		//밑
		a = 'g';
	else if (key == 32)		//스페이스바
		a = 'd';
	else if (key == 113)		//q
		a = 'q';
	else if (key == 259)			//위
		a = 't';
	else
		a = 'a';
	return a;
}
void define_init_pair()
{
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_RED, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(10, COLOR_GREEN, COLOR_BLACK);
	init_pair(11, COLOR_RED, COLOR_BLACK);
	init_pair(12, COLOR_YELLOW, COLOR_BLACK);
	init_pair(20, COLOR_YELLOW, COLOR_BLACK);
}