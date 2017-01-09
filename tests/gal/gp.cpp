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
			//printf( "found the block line\n" );
			break;
		}
	}
	
	//get the headings
	data = split( line, ' ' );
	
	//sort the data
	printf( "sorting the data\n" );
	sort( &data );
	
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
		//printf( "%d\n", i );
		strchar = s[i];
		//printf( "looking at <%c>\n", strchar );
		if( !isspace( strchar )  )
		{
			//printf( "appending to elem\n" );
			elem.append( 1, strchar );
		}
		else
		{
			//printf( "adding elem to vector\n" );
			data.push_back( strip( elem, '"') );
			elem.clear();
		}
		//std::cout<<"elem is now:<" <<elem <<">" <<std::endl;
		//printf("---------\n" );
		i++;
	}
	return data;
}

std::string strip( std::string s, char c )
{
	std::string strp_str;
	char strchar;
	
	int i = 0;
	while( s[i] )
	{
		strchar = s[i];
		
		if( strchar != c )
		{
			strp_str.append( 1, strchar );
		}
		//std::cout <<strp_str <<std::endl;
		i++;
	}
	return strp_str;
}


void sort( cv::vector< std::string >* v )
{
	//sort by there first letter
	int size = v->size();
	int sorted_size;
	printf( "size: %d\n", size );
	cv::vector< std::string >* sorted = new cv::vector< std::string >;
	sorted->push_back( (*v)[0] );
	
	std::string first, second;
	
	//printf("begining sort\n" );
	char current;
	for( int i = 1; i < size ; i++ )
	{
		first = (*v)[i];
		//std::cout <<"First: " <<first;
		current  = first[0];
		sorted_size = sorted->size();
		for( int j = 0; j <= sorted_size; j++ )
		{
			if( j == sorted_size )
			{
				//printf( "adding to end \n" );
				sorted->push_back( first );
				break;
			}
			
			
			second = (*sorted)[j];
			//std::cout <<", Second: " <<second <<std::endl;
			//printf( "%c < %c?\n", current, second[0] );
			if( current < second[0] )
			{
				//printf( "adding at %d\n", j	 );
				sorted->insert( sorted->begin() + j, first );
				break;
			}
		}
	}
	
	//printf( "finished sorting\n" );
	//printf( "sorted size: %d\n", sorted->size() );
	//copy the sorted array to the argument
	for( int i = 0; i < size; i++ )
	{
		//std::cout<< (*sorted)[i] <<std::endl;
		(*v)[i] = (*sorted)[i];
	}
	delete sorted;
	
	return;
}
