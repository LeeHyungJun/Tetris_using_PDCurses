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
		for (int k = 1; k <= width; ++k)		//10���ݺ��Ѵ�
		{
			mvwprintw(game, i, k * 2 - 1, "��");	//j�� ��ǥ�̹Ƿ� ��ǥ��+2������.
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
	pos_init();		//x,y��ǥ �ʱ�ȭ
	memset(board, 0, sizeof(int) * 100 * 100);		//�迭�ʱ�ȭ
}
void window_game::pos_init()
{// x,y��ǥ �ʱ�ȭ
	x = 8;
	y = 0;
}

bool window_game::game_over()		//���ӿ����Ǹ� 1��ȯ �ƴϸ� 0��ȯ
{
	int cnt = 0;
	int sum = 0;
	for (int j = 1; j <= 19; ++j)		// j�� 19���� �ȴ�. �ֳ��ϸ� n*2-1 ���ذ��� �״�� �迭���־���⶧����
	{
		sum = sum + board[1][j];		//���ٿ� ���� �� ���� ��Ÿ���ش�.
	}
	if (sum > 0)
		return true;
	else
		return false;
}
bool window_game::q_click()
{//q������ true��ȯ
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
	stop = 0;				// stop�� 0���� �������μ� ����ؼ� ��������� �ȴ���� üũ
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
				mvwprintw(game, i + y, (j * 2 - 1) + x, "��");
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
	if (right_crash_test() || other_blok_crash_test())	//�浹����� �ٽ� ��ǥ ����
	{
		x = x - 2;
	}
	clear();							// ���� mvwprintw���ذ��� �����ش�
	wattron(game, COLOR_PAIR(aa + 1));
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			if (box->square_block[i - 1][j - 1] == 1)
				mvwprintw(game, i + y, (j * 2 - 1) + x, "��");
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
	if (left_crash_test() || other_blok_crash_test())	//�浹����� �ٽ� ��ǥ ����
	{
		x = x + 2;
	}
	wattron(game, COLOR_PAIR(aa + 1));
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			if (box->square_block[i - 1][j - 1] == 1)
				mvwprintw(game, i + y, (j * 2 - 1) + x, "��");
		}
	}
	wattroff(game, COLOR_PAIR(aa + 1));
	wrefresh(game);
	//delwin(game);
}
void window_game::down()
{
	y = y + 1;
	if (down_crash_test() || other_blok_crash_test())		//�浹����� �ٽ� ��ǥ ����
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
				mvwprintw(game, i + y, (j * 2 - 1) + x, "��");
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
		}		//�ٴڿ� �����ϸ�
	}

	clear();
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			if (box->square_block[i - 1][j - 1] == 1)
				mvwprintw(game, i + y, (j * 2 - 1) + x, "��");
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
				mvwprintw(game, i + y, (j * 2 - 1) + x, "��");
		}
	}
	wattroff(game, COLOR_PAIR(aa + 1));
	wrefresh(game);
}

bool window_game::right_crash_test()		//���� �ε�ġ�� true �Ⱥε�ġ�� false ��ȯ
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
	if (cnt > 0)		//4*4��ľȿ� �ϳ��� �ε�ġ�� ture ��ȯ
		return true;
	else
		return false;
}
bool window_game::left_crash_test()		//���� �ε�ġ�� true �Ⱥε�ġ�� false ��ȯ
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
	if (cnt > 0)		//4*4��ľȿ� �ϳ��� �ε�ġ�� ture ��ȯ
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
	if (cnt > 0)		//4*4��ľȿ� �ϳ��� �ε�ġ�� ture ��ȯ
		return true;
	else
		return false;
}
bool window_game::other_blok_crash_test()		//�ٸ����̶� �ε����� Ʈ�� ����
{
	int cnt = 0;
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)			//�������̶� �񱳸� �ϴ°Ŵ�!!
		{
			if (box->square_block[i - 1][j - 1] == 1 && (board[i + y][(j * 2 - 1) + x] == 1 || board[i + y][(j * 2 - 1) + x] == 2
				|| board[i + y][(j * 2 - 1) + x] == 3 || board[i + y][(j * 2 - 1) + x] == 4 || board[i + y][(j * 2 - 1) + x] == 5
				|| board[i + y][(j * 2 - 1) + x] == 6 || board[i + y][(j * 2 - 1) + x] == 7))
				cnt++;
		}
	}
	if (cnt > 0)		//4*4��ľȿ� �ϳ��� �ε�ġ�� ture ��ȯ
		return true;
	else
		return false;
}

void window_game::clear()
{
	wattron(game, COLOR_PAIR(10));
	for (int i = 1; i <= height; ++i)
	{
		for (int k = 1; k <= width; ++k)		//10���ݺ��Ѵ�
		{
			mvwprintw(game, i, k * 2 - 1, "��");	//j�� ��ǥ�̹Ƿ� ��ǥ��+2������.
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
	arr_insert();		//��°��� �迭�� 1�� �����ϴ� �Լ�
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
void window_game::line_del()			//�� ������� �������� ����°ž����ϳ�??
{
	int temp_board[100][100] = { 0 };
	int i_cnt = 0;						//����� ���� ������ ����
	int aa[100] = { 0 }, bb, t, cc;
	int cnt = 0;

	for (int i = 1; i <= 18; ++i)		// �� ������ �ᰡ ��� ���ִ��� �˻��Ѵ�.
	{
		int sum = 0;					//�� ������ ���� ��Ÿ���� ����	
		for (int j = 1; j <= 19; ++j)		// j�� 19���� �ȴ�. �ֳ��ϸ� n*2-1 ���ذ��� �״�� �迭���־���⶧����
		{
			if (board[i][j] == 1 || board[i][j] == 2 || board[i][j] == 3 || board[i][j] == 4 || board[i][j] == 5 || board[i][j] == 6 || board[i][j] == 7)		//���� ��á����..
				sum = sum + 1;
		}

		if (sum == 10)			//�������� ��10���� ������...
		{
			for (int j = 1; j <= 100; ++j)
			{
				board[i][j] = 0;
				for (int m = i; m >= 1; --m)
					board[m][j] = board[m - 1][j];
			}
			window_game::score_up++;
			cc = i;
			i_cnt++;		//�ٸ����������� ���ְ�
		}
		clear();
	}
}

void window_game::colorPrint(int i, int j) const
{
	if (board[i][j] == O_Yellow)
	{
		wattron(game, COLOR_PAIR(O_Yellow));
		mvwprintw(game, i, j, "��");
		wattroff(game, COLOR_PAIR(O_Yellow));
	}
	else if (board[i][j] == L_Blue)
	{
		wattron(game, COLOR_PAIR(L_Blue));
		mvwprintw(game, i, j, "��");
		wattroff(game, COLOR_PAIR(L_Blue));
	}
	else if (board[i][j] == J_Green)
	{
		wattron(game, COLOR_PAIR(J_Green));
		mvwprintw(game, i, j, "��");
		wattroff(game, COLOR_PAIR(J_Green));
	}
	else if (board[i][j] == S_Magenta)
	{
		wattron(game, COLOR_PAIR(S_Magenta));
		mvwprintw(game, i, j, "��");
		wattroff(game, COLOR_PAIR(S_Magenta));
	}
	else if (board[i][j] == Z_Red)
	{
		wattron(game, COLOR_PAIR(Z_Red));
		mvwprintw(game, i, j, "��");
		wattroff(game, COLOR_PAIR(Z_Red));
	}
	else if (board[i][j] == T_Cyan)
	{
		wattron(game, COLOR_PAIR(T_Cyan));
		mvwprintw(game, i, j, "��");
		wattroff(game, COLOR_PAIR(T_Cyan));
	}
	else if (board[i][j] == I_White)
	{
		wattron(game, COLOR_PAIR(I_White));
		mvwprintw(game, i, j, "��");
		wattroff(game, COLOR_PAIR(I_White));
	}
}