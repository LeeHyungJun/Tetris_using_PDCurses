/***********************************************
*   Hyungjun Lee
*	Kookmin University (South, Korea)
*   hjlee1765@gmail.com
*
***********************************************/
#include <curses.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include "Window_game.h"

void O_Block::draw()
{
	int _square_block[4][4] = 
	{
		{ 1, 1, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	};
	memcpy(square_block, _square_block, 16*4);
}
void O_Block::rotate()
{
	if(rotateNum%4==1)
	{
		int _square_block[4][4] = 
		{
			{ 1, 1, 0, 0 },
			{ 1, 1, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 }
		};
		memcpy(square_block, _square_block, 16*4);
	}
	else if(rotateNum%4==2)
		{
			int _square_block[4][4] = 
			{
				{ 1, 1, 0, 0 }, 
				{ 1, 1, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			};
			memcpy(square_block, _square_block, 16*4);
		}
		else if(rotateNum%4==3)
		{
			int _square_block[4][4] = 
			{
				{ 1, 1, 0, 0 },
				{ 1, 1, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			};
			memcpy(square_block, _square_block, 16*4);
		}
		else if(rotateNum%4==0)
		{
			int _square_block[4][4] = 
			{
				{ 1, 1, 0, 0 },
				{ 1, 1, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			};
			memcpy(square_block, _square_block, 16*4);
		}
}
 
void L_Block::draw()
	{
			int _square_block[4][4] = 
			{
				{ 0, 1, 0, 0 },
				{ 0, 1, 0, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 0, 0, 0 }
			};
			memcpy(square_block, _square_block, 16*4);
	}
void L_Block::rotate()
	{
		if(rotateNum%4==1)
		{
			int _square_block[4][4] = 
			{
				{ 0, 0, 1, 0 },
				{ 1, 1, 1, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			};
			memcpy(square_block, _square_block, 16*4);
		}
		else if(rotateNum%4==2)
		{
			int _square_block[4][4] = 
			{
				{ 1, 1, 0, 0 },
				{ 0, 1, 0, 0 },
				{ 0, 1, 0, 0 },
				{ 0, 0, 0, 0 }
			};
			memcpy(square_block, _square_block, 16*4);
		}
		else if(rotateNum%4==3)
		{
			int _square_block[4][4] = 
			{
				{ 0, 0, 0, 0 },
				{ 1, 1, 1, 0 },
				{ 1, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			};
			memcpy(square_block, _square_block, 16*4);
		}
		else if(rotateNum%4==0)
		{
			int _square_block[4][4] = 
			{
				{ 0, 1, 0, 0 },
				{ 0, 1, 0, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 0, 0, 0 }
			};
			memcpy(square_block, _square_block, 16*4);
		}
	}

void J_Block::draw()
	{
		int _square_block[4][4] = 
		{
			{ 0, 1, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 1, 1, 0, 0 },
			{ 0, 0, 0, 0 }
		};
		memcpy(square_block, _square_block, 16*4);
	}
void J_Block::rotate()
	{
		if(rotateNum%4==1)
		{
			int _square_block[4][4] = 
			{
				{ 0, 0, 0, 0 },
				{ 1, 1, 1, 0 },
				{ 0, 0, 1, 0 },
				{ 0, 0, 0, 0 }
			};
			memcpy(square_block, _square_block, 16*4);
		}
		else if(rotateNum%4==2)
		{
			int _square_block[4][4] = 
			{
				{ 0, 1, 1, 0 },
				{ 0, 1, 0, 0 },
				{ 0, 1, 0, 0 },
				{ 0, 0, 0, 0 }
			};
			memcpy(square_block, _square_block, 16*4);
		}
		else if(rotateNum%4==3)
		{
			int _square_block[4][4] = 
			{
				{ 1, 0, 0, 0 },
				{ 1, 1, 1, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			};
			memcpy(square_block, _square_block, 16*4);
		}
		else if(rotateNum%4==0)
		{
			int _square_block[4][4] = 
			{
				{ 0, 1, 0, 0 },
				{ 0, 1, 0, 0 },
				{ 1, 1, 0, 0 },
				{ 0, 0, 0, 0 }
			};
			memcpy(square_block, _square_block, 16*4);
		}
	}

void S_Block::draw()
	{
		int _square_block[4][4] = 
		{
			{ 0, 1, 0, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 0, 0 }
		};
		memcpy(square_block, _square_block, 16*4);
	}
void S_Block::rotate()
	{
		if(rotateNum%4==1)
		{
			int _square_block[4][4] = 
			{
				{ 0, 1, 1, 0 },
				{ 1, 1, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			};
			memcpy(square_block, _square_block, 16*4);
		}
		else if(rotateNum%4==2)
		{
			int _square_block[4][4] = 
			{
				{ 0, 1, 0, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 0, 1, 0 },
				{ 0, 0, 0, 0 }
			};
			memcpy(square_block, _square_block, 16*4);
		}
		else if(rotateNum%4==3)
		{
			int _square_block[4][4] = 
			{
				{ 0, 1, 1, 0 },
				{ 1, 1, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			};
			memcpy(square_block, _square_block, 16*4);
		}
		else if(rotateNum%4==0)
		{
			int _square_block[4][4] = 
			{
				{ 0, 1, 0, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 0, 1, 0 },
				{ 0, 0, 0, 0 }
			};
			memcpy(square_block, _square_block, 16*4);
		}
	}

void Z_Block::draw()
	{
		int _square_block[4][4] = 
		{
			{ 0, 1, 0, 0 },
			{ 1, 1, 0, 0 },
			{ 1, 0, 0, 0 },
			{ 0, 0, 0, 0 }
		};
		memcpy(square_block, _square_block, 16*4);
	}
void Z_Block::rotate()
	{
		if(rotateNum%4==1)
		{
			int _square_block[4][4] = 
			{
				{ 1, 1, 0, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			};
			memcpy(square_block, _square_block, 16*4);
		}
		else if(rotateNum%4==2)
		{
			int _square_block[4][4] = 
			{
				{ 0, 1, 0, 0 },
				{ 1, 1, 0, 0 },
				{ 1, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			};
			memcpy(square_block, _square_block, 16*4);
		}
		else if(rotateNum%4==3)
		{
			int _square_block[4][4] = 
			{
				{ 1, 1, 0, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			};
			memcpy(square_block, _square_block, 16*4);
		}
		else if(rotateNum%4==0)
		{
			int _square_block[4][4] = 
			{
				{ 0, 1, 0, 0 },
				{ 1, 1, 0, 0 },
				{ 1, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			};
			memcpy(square_block, _square_block, 16*4);
		}
	}

void T_Block::draw()
	{
		int _square_block[4][4] = 
		{
			{ 0, 1, 0, 0 },
			{ 1, 1, 1, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 }
		};
		memcpy(square_block, _square_block, 16*4);
	}
void T_Block::rotate()
	{
		if(rotateNum%4==1)
		{
			int _square_block[4][4] = 
			{
				{ 0, 1, 0, 0 },
				{ 1, 1, 0, 0 },
				{ 0, 1, 0, 0 },
				{ 0, 0, 0, 0 }
			};
			memcpy(square_block, _square_block, 16*4);
		}
		else if(rotateNum%4==2)
		{
			int _square_block[4][4] = 
			{
				{ 0, 0, 0, 0 },
				{ 1, 1, 1, 0 },
				{ 0, 1, 0, 0 },
				{ 0, 0, 0, 0 }
			};
			memcpy(square_block, _square_block, 16*4);
		}
		else if(rotateNum%4==3)
		{
			int _square_block[4][4] = 
			{
				{ 0, 1, 0, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 1, 0, 0 },
				{ 0, 0, 0, 0 }
			};
			memcpy(square_block, _square_block, 16*4);
		}
		else if(rotateNum%4==0)
		{
			int _square_block[4][4] = 
			{
				{ 0, 1, 0, 0 },
				{ 1, 1, 1, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			};
			memcpy(square_block, _square_block, 16*4);
		}
	}

void I_Block::draw()
	{
		int _square_block[4][4] = 
		{
			{ 0, 1, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 1, 0, 0 }
		};
		memcpy(square_block, _square_block, 16*4);
	}
void I_Block::rotate()
	{
		if(rotateNum%4==1)
		{
			int _square_block[4][4] = 
			{
				{ 0, 0, 0, 0 },
				{ 1, 1, 1, 1 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			};
			memcpy(square_block, _square_block, 16*4);
		}
		else if(rotateNum%4==2)
		{
			int _square_block[4][4] = 
			{
				{ 0, 1, 0, 0 },
				{ 0, 1, 0, 0 },
				{ 0, 1, 0, 0 },
				{ 0, 1, 0, 0 }
			};
			memcpy(square_block, _square_block, 16*4);
		}
		else if(rotateNum%4==3)
		{
			int _square_block[4][4] = 
			{
				{ 0, 0, 0, 0 },
				{ 1, 1, 1, 1 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 }
			};
			memcpy(square_block, _square_block, 16*4);
		}
		else if(rotateNum%4==0)
		{
			int _square_block[4][4] = 
			{
				{ 0, 1, 0, 0 },
				{ 0, 1, 0, 0 },
				{ 0, 1, 0, 0 },
				{ 0, 1, 0, 0 }
			};
			memcpy(square_block, _square_block, 16*4);
		}
	}