/***********************************************
*   Hyungjun Lee
*	Kookmin University (South, Korea)
*   hjlee1765@gmail.com
*
***********************************************/

//���� �����ǹ迭�� 18*19 �����̸� ���δ� ����ǰ� �����ϰ� ���ηδ� 2ĭ�� ������ ���� 1,3,5,7,9,11,13,15,17,19 �׿� 1���� ���ִ� �����Դϴ�.

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
	define_init_pair();											//����Ʈ �������ִ� �Լ�

	border('|', '|', '-', '-', '+', '+', '+', '+');
	attron(COLOR_PAIR(11));
	mvprintw(1, 1, "Welcome To the Tetris Game");
	attroff(COLOR_PAIR(11));
	refresh();

	window_game game(20, 22, 2, 2, 0, 0, 0, seed);
	window_score score(4, 10, 4, 30);
	window_name name(4, 10, 10, 30, username);

	game.board_init();											//������ ��� �ʱ�ȭ, �ʱ� x,y��ǥ �ʱ�ȭ
	while (!game.game_over())									//���� �� ���ٿ� ������ gameover
	{
		game.init();											// ó������ �׸�ĭ ����	
		while (!game.q_click() && window_game::stop == 0)			//q������ gameover && ����� �ٴڿ� �����ϸ� stop++
		{
			if (argc > 1)
				inStream >> cur_key;
			else
				cur_key = input_key();
			game.update(cur_key);					//Ű�� �Է¹޾Ƽ� ������
		}
		if (game.q_click())							// q �������� ��ž.
			break;
		else										//q ��ư�� �ȴ�������. �Ϲ��� ����
		{
			game.display();							// display �԰� ���ÿ� ���� �迭�� �׸������� 1�ھ��ش�. x.y��ǥ �ʱ�ȭ
			score.score_print();					//����ǥ��
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
	if (key == 261)	//������
		a = 'r';
	else if (key == 260)		//����
		a = 'l';
	else if (key == 258)		//��
		a = 'g';
	else if (key == 32)		//�����̽���
		a = 'd';
	else if (key == 113)		//q
		a = 'q';
	else if (key == 259)			//��
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