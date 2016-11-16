#include "spot.h"
#include <stdio.h>

spot::spot()
{
	center = 0.0;
}

spot::~spot()
{
	printf( "spot destroyed" );
}
