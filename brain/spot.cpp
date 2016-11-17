#include "spot.h"
#include <stdio.h>

int spot::numCirc = 0;

spot::spot()
{}

spot::spot( int x, int y )
{
	this->numCirc++;
	this->c_x = x;
	this->c_y = y;
}

spot::~spot()
{
	this->numCirc--;
	printf( "spot destroyed" );
}
