/***********************************************
*                                              *
*	�й� : 20113315		                       *
*	�̸� : ������                              *
*                                              *
***********************************************/
#ifndef __WINDOW_GAME_H_
#define __WINDOW_GAME_H_
#define height 18
#define width 10


class block
{
public:
	int square_block[4][4];
	int rotateNum;
public:
	block()
	{
		rotateNum=0;
	}
	virtual void draw()=0;
	virtual void rotate()=0;
};
class O_Block : public block
{
public:
	virtual void draw();
	virtual void rotate();
};
class L_Block : public block
{
public:
	virtual void draw();
	virtual void rotate();
};
class J_Block : public block
{
public:
	virtual void draw();
	virtual void rotate();
};
class S_Block : public block
{
public:
	virtual void draw();
	virtual void rotate();
};
class Z_Block : public block
{
public:
	virtual void draw();
	virtual void rotate();
};
class T_Block : public block
{
public:
	virtual void draw();
	virtual void rotate();
};
class I_Block : public block
{
public:
	virtual void draw();
	virtual void rotate();
};

typedef enum _color
{
	O_Yellow=1, L_Blue=2, J_Green=3, S_Magenta=4, Z_Red=5, T_Cyan=6, I_White=7
}color;

class window_game
{
private:
	WINDOW *game;
	int x, y;
	int board[100][100];
	block* box;			
	int aa;					//������...
	int seed;
public:
	window_game(const int nlines, const int ncols, const int begy, const int begx, int x, int y, int stop, int _seed);		// game�� window�� �ʱ� �����մϴ�.
	void board_init();		//���� ���� �迭�� 0���� �ʱ�ȭ
	void pos_init();		//x,y��ǥ�� �ʱ�ȭ�����ش�.

	bool game_over();				//������ ����
	bool q_click();

	void init();			//ó�� �׸�ĭ�� ��ܿ� ����ϴ� �Լ�
	void block_Kind();

	void update(char cur_key);			
	void right();
	void left();
	void down();
	void space_bar();
	void q();
	void rotate();

	bool right_crash_test();
	bool left_crash_test();
	bool down_crash_test();
	bool other_blok_crash_test();

	void clear();			// Ű�� �Է¹޾Ƽ� ��Ʈ���Ʈ�� �����϶�, ���� �ִ� �������� �ʱ�ȭ���ݴϴ�.

	void display();			// board�迭�� ��µ� �簢���� �״�� 1�� �־��ְ� display�ϴ� �Լ�
	void arr_insert();
	void line_del();				//���� ����

	void colorPrint(int i, int j) const;

	~window_game(){}
public:
	static int score_up;
	static int q_cnt;
	static int stop;
};
#endif