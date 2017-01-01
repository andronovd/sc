#include <stdio.h>
#include <stdlib.h>

//add binary display function
typedef char data_t;

void printBin( char* s, short d )
{
	short i = 0;
	for(; i < 7; i++ )
	{
		if( (d & 1) == 1 )
		{
			s[7-i] = '1';
		}
		else
		{
			s[7-i] = '0';
		}
		d = d>>1;
	}
}

int main( int argc, char* argv[] )
{
	char s[] = "00000000\0";

	if( argc != 2 )
	{
		printf( "Not enough arguments given. Must give valid filename." );
		return 1;
	}
	
	char* filename = argv[1];
	FILE *fp;
	fp = fopen( filename, "r" );
	
	short buffer;
	int count = 0;
	while( !feof( fp ) )
	{
		fread( &buffer, 1 , 1, fp );
		printBin( s, (short)buffer );
		printf( "%i|%s, %i\n", count, s, buffer );
		count++;
	}
	
	return 0;
}
