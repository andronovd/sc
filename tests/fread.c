#include <stdio.h>
#include <stdlib.h>

//add binary display function

int main( int argc, char* argv[] )
{

	if( argc != 2 )
	{
		printf( "Not enough arguments given. Must give valid filename." );
		return 1;
	}
	
	char* filename = argv[1];
	FILE *fp;
	fp = fopen( filename, "r" );
	
	char buffer;
	while( !feof( fp ) )
	{
		fread( &buffer, 1 , 1, fp );
		printf( "%i, %c\n", buffer, buffer );
	}
	
	return 0;
}
