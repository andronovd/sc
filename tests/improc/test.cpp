#include <iostream>
#include <cstdio>

using namespace std;

double* f( int );

int main ( int argc, char** argv )
{

	int n = 100;
	double* ans = f ( n );
	
	for( int i = 0; i < n; i++ )
	{
		printf( "%f\n", *( ans + i ) );
	}
	
	return 0;
	
}

double* f( int n )
{
	double* ans = new double[ n ];
	for( int i = 0; i < n; i++ )
	{
		*(ans + i ) = (double) i ;
	}
	return ans;
}
