#include "gp.h"
#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <map>

//show debug statements
#define PRINT 0

//---galPoint definitions---//
galPoint::galPoint( int block, int col, std::string id, std::string name, int row )
{
	this->block = block;
	this->row = row;
	this->col = col;
	this->id = id;
	this->name = name;
}

galPoint::~galPoint()
{
	//delete the point
}

//---gp definitions---//
gp::gp( char* filename )
{
	if( PRINT )
	{
		printf( "creating gp\n" );
	}
	this->filename = filename;
	this->entryCount = 0;
}

gp::~gp()
{
	if( PRINT )
	{
		printf( "deleting gp\n" );
	}
}

void gp::analyze()
{
	
	int j = 0;
	//open file
	std::ifstream f( this->filename );
	std::string line;
	cv::vector< std::string > data;
	
	//find the line starting with <"Block">
	while( std::getline( f, line) )
	{
		if( line.substr(0, 7)  == "\"Block\"" )
		{
			if( PRINT )
			{
				printf( "found the block line\n" );
			}
			break;
		}
	}
	
	//get the headings
	data = split( line, ' ' );
	if( PRINT )
	{
		printf("elements in data:\n" );
		for( std::vector< std::string >::iterator i = data.begin(); i != data.end(); i++ )
		{
			std::cout <<j <<":"<<*i <<std::endl;
			j++;
		}
	}
	
	//create map
	std::map< std::string, int > mapping;
	//fill out the map
	int size = data.size();
	for( int i = 0; i < size; i++ )
	{
		mapping[ data[i] ] = i;
	}
	
	
	
	//sort the headings
	if( PRINT )
	{
		printf( "sorting the data\n" );
	}
	sort( &data );
	
	if( PRINT )
	{
		printf("elements in sorted data:\n" );
		j = 0;
		for( std::vector< std::string >::iterator i = data.begin(); i != data.end(); i++ )
		{
			std::cout <<j <<":"<<*i <<std::endl;
			j++;
		}
	}
	
	
	//generate the translation array
	int* trans = new int[ size ];
	for( int i = 0; i < size; i++ )
	{
		if(	PRINT )
		{
			std::cout << mapping[ data[i] ] << std::endl;
		}
		trans[i]  = mapping[ data[i] ];
	}
	
	if( PRINT )
	{
		printf("Translation array: \n" );
		for( int i = 0 ; i < size; i++ )
		{
			printf( "%d ", trans[i] );
		}
		printf( "\n" );
	}
		
	//now finish reading the file and fill out the entries vector
	while( std::getline( f, line ) )
	{
		data = split( line, ' ' );
		this->entries.push_back( galPoint( atoi( data[ trans[0] ].c_str() ), atoi( data[ trans[1] ].c_str() ), data[ trans[2] ], data[ trans[3] ], atoi( data[ trans[4] ].c_str() ) ) );
		this->entryCount++;
	}
	
	if( PRINT )
	{
		int a = 0;
		//view entries
		for( std::vector< galPoint >::iterator i = this->entries.begin(); i != this->entries.end(); i++ )
		{
			std::cout <<a <<" " <<(*i).block <<" " <<(*i).row <<" " <<(*i).col <<" " <<(*i).id <<" " <<(*i).name <<" " <<std::endl;
			a++;
		}		
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
		strchar = s[i];
		if( !isspace( strchar )  )
		{
			elem.append( 1, strchar );
		}
		else
		{
			//printf( "adding elem to vector\n" );
			data.push_back( strip( elem, '"') );
			elem.clear();
		}
		i++;
	}
	return data;
}

std::string strip( std::string s, char c )
{
	std::string strp_str;
	char strchar;
	
	int i = 0;
	//for each character in the string, if its the character
	//being striped, don't copy it.
	while( s[i] )
	{
		strchar = s[i];
		
		if( strchar != c )
		{
			strp_str.append( 1, strchar );
		}
		i++;
	}
	return strp_str;
}


void sort( cv::vector< std::string >* v )
{
	//basic insertion sort
	//sort by there first letter
	int size = v->size();
	int sorted_size;
	cv::vector< std::string >* sorted = new cv::vector< std::string >;
	sorted->push_back( (*v)[0] );
	
	std::string first, second;
	char current;
	for( int i = 1; i < size ; i++ )
	{
		first = (*v)[i];
		current  = first[0];
		sorted_size = sorted->size();
		for( int j = 0; j <= sorted_size; j++ )
		{
			if( j == sorted_size )
			{
				sorted->push_back( first );
				break;
			}
			
			
			second = (*sorted)[j];
			if( current < second[0] )
			{
				sorted->insert( sorted->begin() + j, first );
				break;
			}
		}
	}
	//copy the sorted array to the argument
	for( int i = 0; i < size; i++ )
	{
		(*v)[i] = (*sorted)[i];
	}
	delete sorted;
	return;
}
