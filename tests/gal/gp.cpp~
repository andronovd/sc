#include "gp.h"
#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>

//---galPoint definitions---//
galPoint::galPoint( int block, int row, int col, std::string id, std::string name )
{
	this->block = block;
	this->row = row;
	this->col = col;
	this->id = id;
	this->name = name;
}

galPoint::~galPoint()
{
}

//---gp definitions---//
gp::gp( char* filename )
{
	printf( "creating gp\n" );
	this->filename = filename;
}

gp::~gp()
{
	printf( "deleting gp\n" );
}

void gp::analyze()
{
	//open file
	std::ifstream f( this->filename );
	std::string line;
	cv::vector< std::string > data;
	
	while( std::getline( f, line) )
	{
		if( line.substr(0, 7)  == "\"Block\"" )
		{
			printf( "found the block line\n" );
			break;
		}
	}
	
	//get the headings
	data = split( line, ' ' );
	
	printf("elements in data:\n" );
	int j = 0;
	for( std::vector< std::string >::iterator i = data.begin(); i != data.end(); i++ )
	{
		std::cout <<j <<":"<<*i <<std::endl;
		j++;
	}
	return;
}

//---string functions---//
cv::vector< std::string > split( std::string s, char c )
{
	cv::vector< std::string > data;
	
	int i = 0;
	char strchar;
	std::string elem;
	while( s[i] )
	{
		printf( "%d\n", i );
		strchar = s[i];
		printf( "looking at <%c>\n", strchar );
		if( !isspace( strchar)  )
		{
			printf( "appending to elem\n" );
			elem.append( 1, strchar );
		}
		else
		{
			printf( "adding elem to vector\n" );
			data.push_back( elem );
			elem.clear();
		}
		std::cout<<"elem is now:<" <<elem <<">" <<std::endl;
		printf("---------\n" );
		i++;
	}
	return data;
}

void strip( std::string s, char c )
{
	return;
}
