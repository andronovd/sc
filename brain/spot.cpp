#include "spot.h"
#include <stdio.h>

spot::spot()
{}

spot::spot( Point p )
{
	this->center = p;
}

spot::~spot()
{
	printf( "spot destroyed" );
}
