/***********************************************
*                                              *
*	학번 : 20113315		                       *
*	이름 : 이형준                              *
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
	int aa;					//블럭구분...
	int seed;
public:
	window_game(const int nlines, const int ncols, const int begy, const int begx, int x, int y, int stop, int _seed);		// game판 window을 초기 생성합니다.
	void board_init();		//게임 판의 배열을 0으로 초기화
	void pos_init();		//x,y좌표를 초기화시켜준다.

	bool game_over();				//꽉차면 종료
	bool q_click();

	void init();			//처음 네모칸이 상단에 출력하는 함수
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

	void clear();			// 키를 입력받아서 테트노미트가 움직일때, 전에 있던 게임판을 초기화해줍니다.

	void display();			// board배열에 출력된 사각형을 그대로 1로 넣어주고 display하는 함수
	void arr_insert();
	void line_del();				//라인 제거

	void colorPrint(int i, int j) const;

	~window_game(){}
public:
	static int score_up;
	static int q_cnt;
	static int stop;
};
#endif