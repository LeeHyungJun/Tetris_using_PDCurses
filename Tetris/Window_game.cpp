/***********************************************
*   Hyungjun Lee
*	Kookmin University (South, Korea)
*   hjlee1765@gmail.com
*
***********************************************/
#include <curses.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include "Window_game.h"

#define height 18
#define width 10

int window_game::score_up = 0;
int window_game::stop = 0;
int window_game::q_cnt = 0;

window_game::window_game(int nlines, int ncols, int begy, int begx, int x, int y, int stop, int _seed)
{
	seed = _seed;
	game = newwin(nlines, ncols, begy, begx);
	wattron(game, COLOR_PAIR(10));
	for (int i = 1; i <= height; ++i)
	{
		for (int k = 1; k <= width; ++k)		//10번반복한다
		{
			mvwprintw(game, i, k * 2 - 1, "□");	//j는 좌표이므로 좌표값+2씩증가.
		}
	}
	wattroff(game, COLOR_PAIR(10));
	wborder(game, '|', '|', '-', '-', '+', '+', '+', '+');
	mvprintw(2, 10, "Tetris");
	wrefresh(game);

	//delwin(game);
}

void window_game::board_init()
{
	pos_init();		//x,y좌표 초기화
	memset(board, 0, sizeof(int) * 100 * 100);		//배열초기화
}
void window_game::pos_init()
{// x,y좌표 초기화
	x = 8;
	y = 0;
}

bool window_game::game_over()		//게임오버되면 1반환 아니면 0반환
{
	int cnt = 0;
	int sum = 0;
	for (int j = 1; j <= 19; ++j)		// j는 19부터 된다. 왜냐하면 n*2-1 해준값을 그대로 배열에넣어줬기때문에
	{
		sum = sum + board[1][j];		//한줄에 ■의 총 개수 나타내준다.
	}
	if (sum > 0)
		return true;
	else
		return false;
}
bool window_game::q_click()
{//q눌리면 true반환
	if (q_cnt != 0)
		return true;
	else
		return false;
}
void window_game::q()
{
	q_cnt++;
	q_click();
}

void window_game::init()
{

	block_Kind();
	stop = 0;				// stop을 0으로 해줌으로서 계속해서 땅에닿는지 안닿는지 체크
	wattron(game, COLOR_PAIR(aa + 1));
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			if (box->square_block[i - 1][j - 1] == 1)
			{
				if (board[i + y][(j * 2 - 1) + x] == 1)
				{
					stop++;
				}
				mvwprintw(game, i + y, (j * 2 - 1) + x, "■");
			}
		}
	}
	wattroff(game, COLOR_PAIR(aa + 1));
	wrefresh(game);
}
void window_game::block_Kind()
{
	aa = rand() % 7;
	switch (aa + 1)
	{
	case O_Yellow: box = new O_Block(); break;
	case L_Blue: box = new L_Block(); break;
	case J_Green: box = new J_Block(); break;
	case S_Magenta: box = new S_Block(); break;
	case Z_Red: box = new Z_Block(); break;
	case T_Cyan: box = new T_Block(); break;
	case I_White: box = new I_Block(); break;
	}
	box->draw();
}

void window_game::update(char cur_key)
{
	switch (cur_key)
	{
	case 'r': right(); break;
	case 'l': left(); break;
	case 'g': down(); break;
	case 'd': space_bar(); break;
	case 'q': q(); break;
	case 't': rotate(); break;
	default:		0;
	}

}
void window_game::right()
{
	x = x + 2;
	if (right_crash_test() || other_blok_crash_test())	//충돌생기면 다시 좌표 복귀
	{
		x = x - 2;
	}
	clear();							// 전에 mvwprintw해준것을 지워준다
	wattron(game, COLOR_PAIR(aa + 1));
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			if (box->square_block[i - 1][j - 1] == 1)
				mvwprintw(game, i + y, (j * 2 - 1) + x, "■");
		}
	}
	wattroff(game, COLOR_PAIR(aa + 1));
	wrefresh(game);

	//delwin(game);
}
void window_game::left()
{
	clear();
	x = x - 2;
	if (left_crash_test() || other_blok_crash_test())	//충돌생기면 다시 좌표 복귀
	{
		x = x + 2;
	}
	wattron(game, COLOR_PAIR(aa + 1));
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			if (box->square_block[i - 1][j - 1] == 1)
				mvwprintw(game, i + y, (j * 2 - 1) + x, "■");
		}
	}
	wattroff(game, COLOR_PAIR(aa + 1));
	wrefresh(game);
	//delwin(game);
}
void window_game::down()
{
	y = y + 1;
	if (down_crash_test() || other_blok_crash_test())		//충돌생기면 다시 좌표 복귀
	{
		y = y - 1; stop++;
	}
	clear();
	wattron(game, COLOR_PAIR(aa + 1));
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			if (box->square_block[i - 1][j - 1] == 1)
				mvwprintw(game, i + y, (j * 2 - 1) + x, "■");
		}
	}
	wattroff(game, COLOR_PAIR(aa + 1));
	wrefresh(game);
}
void window_game::space_bar()
{
	wattron(game, COLOR_PAIR(aa + 1));
	while (1)
	{
		y = y + 1;
		if (down_crash_test() || other_blok_crash_test())
		{
			y = y - 1; stop++; break;
		}		//바닥에 도착하면
	}

	clear();
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			if (box->square_block[i - 1][j - 1] == 1)
				mvwprintw(game, i + y, (j * 2 - 1) + x, "■");
		}
	}
	wattroff(game, COLOR_PAIR(aa + 1));
	wrefresh(game);
	//delwin(game);
}
void window_game::rotate()
{
	++(box->rotateNum);
	box->rotate();
	if (left_crash_test() || right_crash_test() || down_crash_test() || other_blok_crash_test())
	{
		--(box->rotateNum);
		box->rotate();
	}
	clear();
	wattron(game, COLOR_PAIR(aa + 1));
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			if (box->square_block[i - 1][j - 1] == 1)
				mvwprintw(game, i + y, (j * 2 - 1) + x, "■");
		}
	}
	wattroff(game, COLOR_PAIR(aa + 1));
	wrefresh(game);
}

bool window_game::right_crash_test()		//벽에 부디치면 true 안부디치면 false 반환
{
	int cnt = 0;
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			if (box->square_block[i - 1][j - 1] == 1 && (j * 2 - 1) + x > 19)
				cnt++;
		}
	}
	if (cnt > 0)		//4*4행렬안에 하나라도 부디치면 ture 반환
		return true;
	else
		return false;
}
bool window_game::left_crash_test()		//벽에 부디치면 true 안부디치면 false 반환
{
	int cnt = 0;
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			if (box->square_block[i - 1][j - 1] == 1 && (j * 2 - 1) + x < 1)
				cnt++;
		}
	}
	if (cnt > 0)		//4*4행렬안에 하나라도 부디치면 ture 반환
		return true;
	else
		return false;
}
bool window_game::down_crash_test()
{
	int cnt = 0;
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			if (box->square_block[i - 1][j - 1] == 1 && i + y > 18)
				cnt++;
		}
	}
	if (cnt > 0)		//4*4행렬안에 하나라도 부디치면 ture 반환
		return true;
	else
		return false;
}
bool window_game::other_blok_crash_test()		//다른블럭이랑 부딪히면 트루 리턴
{
	int cnt = 0;
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)			//보드판이랑 비교를 하는거다!!
		{
			if (box->square_block[i - 1][j - 1] == 1 && (board[i + y][(j * 2 - 1) + x] == 1 || board[i + y][(j * 2 - 1) + x] == 2
				|| board[i + y][(j * 2 - 1) + x] == 3 || board[i + y][(j * 2 - 1) + x] == 4 || board[i + y][(j * 2 - 1) + x] == 5
				|| board[i + y][(j * 2 - 1) + x] == 6 || board[i + y][(j * 2 - 1) + x] == 7))
				cnt++;
		}
	}
	if (cnt > 0)		//4*4행렬안에 하나라도 부디치면 ture 반환
		return true;
	else
		return false;
}

void window_game::clear()
{
	wattron(game, COLOR_PAIR(10));
	for (int i = 1; i <= height; ++i)
	{
		for (int k = 1; k <= width; ++k)		//10번반복한다
		{
			mvwprintw(game, i, k * 2 - 1, "□");	//j는 좌표이므로 좌표값+2씩증가.
		}
	}
	wattroff(game, COLOR_PAIR(10));

	for (int i = 1; i <= 100; ++i)
	{
		for (int j = 1; j <= 100; ++j)
			colorPrint(i, j);
	}
	wrefresh(game);
}

void window_game::display()
{
	arr_insert();		//출력값을 배열에 1로 대입하는 함수
	line_del();
	pos_init();
}
void window_game::arr_insert()
{
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			if (box->square_block[i - 1][j - 1] == 1)
			{
				switch (aa + 1)
				{
				case O_Yellow: board[i + y][(j * 2 - 1) + x] = O_Yellow; break;
				case L_Blue: board[i + y][(j * 2 - 1) + x] = L_Blue; break;
				case J_Green: board[i + y][(j * 2 - 1) + x] = J_Green; break;
				case S_Magenta: board[i + y][(j * 2 - 1) + x] = S_Magenta; break;
				case Z_Red: board[i + y][(j * 2 - 1) + x] = Z_Red; break;
				case T_Cyan: board[i + y][(j * 2 - 1) + x] = T_Cyan; break;
				case I_White: board[i + y][(j * 2 - 1) + x] = I_White; break;
				}
			}
		}
	}
	for (int i = 1; i <= 100; ++i)
	{
		for (int j = 1; j <= 100; ++j)
			colorPrint(i, j);
		wrefresh(game);
	}
}
void window_game::line_del()			//줄 가운데에서 없어질시 땡기는거어케하냐??
{
	int temp_board[100][100] = { 0 };
	int i_cnt = 0;						//사라진 줄의 개수를 센다
	int aa[100] = { 0 }, bb, t, cc;
	int cnt = 0;

	for (int i = 1; i <= 18; ++i)		// 행 단위로 ■가 모두 차있는지 검사한다.
	{
		int sum = 0;					//■ 개수의 합을 나타내는 변수	
		for (int j = 1; j <= 19; ++j)		// j는 19부터 된다. 왜냐하면 n*2-1 해준값을 그대로 배열에넣어줬기때문에
		{
			if (board[i][j] == 1 || board[i][j] == 2 || board[i][j] == 3 || board[i][j] == 4 || board[i][j] == 5 || board[i][j] == 6 || board[i][j] == 7)		//줄이 꽉찼을때..
				sum = sum + 1;
		}

		if (sum == 10)			//가로줄이 ■10개로 꽉차면...
		{
			for (int j = 1; j <= 100; ++j)
			{
				board[i][j] = 0;
				for (int m = i; m >= 1; --m)
					board[m][j] = board[m - 1][j];
			}
			window_game::score_up++;
			cc = i;
			i_cnt++;		//줄몇번사라졌는지 세주고
		}
		clear();
	}
}

void window_game::colorPrint(int i, int j) const
{
	if (board[i][j] == O_Yellow)
	{
		wattron(game, COLOR_PAIR(O_Yellow));
		mvwprintw(game, i, j, "■");
		wattroff(game, COLOR_PAIR(O_Yellow));
	}
	else if (board[i][j] == L_Blue)
	{
		wattron(game, COLOR_PAIR(L_Blue));
		mvwprintw(game, i, j, "■");
		wattroff(game, COLOR_PAIR(L_Blue));
	}
	else if (board[i][j] == J_Green)
	{
		wattron(game, COLOR_PAIR(J_Green));
		mvwprintw(game, i, j, "■");
		wattroff(game, COLOR_PAIR(J_Green));
	}
	else if (board[i][j] == S_Magenta)
	{
		wattron(game, COLOR_PAIR(S_Magenta));
		mvwprintw(game, i, j, "■");
		wattroff(game, COLOR_PAIR(S_Magenta));
	}
	else if (board[i][j] == Z_Red)
	{
		wattron(game, COLOR_PAIR(Z_Red));
		mvwprintw(game, i, j, "■");
		wattroff(game, COLOR_PAIR(Z_Red));
	}
	else if (board[i][j] == T_Cyan)
	{
		wattron(game, COLOR_PAIR(T_Cyan));
		mvwprintw(game, i, j, "■");
		wattroff(game, COLOR_PAIR(T_Cyan));
	}
	else if (board[i][j] == I_White)
	{
		wattron(game, COLOR_PAIR(I_White));
		mvwprintw(game, i, j, "■");
		wattroff(game, COLOR_PAIR(I_White));
	}
}