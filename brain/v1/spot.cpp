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

void spot::info()
{
	printf("\nCenter: (%d, %d)\ncircScore: %f\naverage radius: %f\naverage height: %f\nstd height: %f\nvolume: %f\n", c_x, c_y, circScore, avg_r, avg_height, std_height, volume );
}
