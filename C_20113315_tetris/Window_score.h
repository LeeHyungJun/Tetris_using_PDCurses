/***********************************************
*                                              *
*	학번 : 20113315		                       *
*	이름 : 이형준                              *
*                                              *
***********************************************/
#ifndef __WINDOW_SCORE_H_
#define __WINDOW_SCORE_H_

class window_score
{
private:
	WINDOW *score;
public:
	window_score(int nlines, int ncols, int begy, int begx);	//score window 초기생성
	void score_print();
	~window_score(){}
};

#endif