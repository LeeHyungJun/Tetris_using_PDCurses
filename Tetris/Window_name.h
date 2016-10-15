/***********************************************
*   Hyungjun Lee
*	Kookmin University (South, Korea)
*   hjlee1765@gmail.com
*
***********************************************/
#ifndef __WINDOW_NAME_H_
#define __WINDOW_NAME_H_

class window_name
{
private:
	WINDOW *name;
public:
	window_name(int nlines, int ncols, int begy, int begx, char* username);
	~window_name() {}
};

#endif