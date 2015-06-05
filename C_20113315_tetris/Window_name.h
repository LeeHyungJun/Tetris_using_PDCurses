/***********************************************
*                                              *
*	학번 : 20113315		                       *
*	이름 : 이형준                              *
*                                              *
***********************************************/
#ifndef __WINDOW_NAME_H_
#define __WINDOW_NAME_H_

class window_name
{
private:
	WINDOW *name;
public:
	window_name(int nlines, int ncols, int begy, int begx, char* username);
	~window_name(){}
};

#endif