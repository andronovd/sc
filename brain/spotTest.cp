#include <stdio.h>
#include "dot.h"

int main()
{
	dot d = dot();
	
	printf( "this dot's center is at %f\n", d.center );
	
	return 0;
}
