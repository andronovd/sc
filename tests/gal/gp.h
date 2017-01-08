#ifndef __GP_H
#define __GP_H


#include "opencv2/imgproc/imgproc.hpp"
#include <string>
#include <stdio.h>

//points from gal file
//i.e. one row from the gal file
class galPoint
{

	public:
		//--data members--//
		int block;
		int row;
		int col;
		
		std::string name;
		std::string id;
		
		//--function members--//
		//--constructor--//
		galPoint( int, int, int, std::string, std::string );
		~galPoint();
};

//Gal Parser (gp)
//reads the gal file and creats the galPoints
class gp
{

	public:
		//--data memebers--//
		char* filename;
		cv::vector< galPoint > entries;
		
		//--function members--//
		
		//contructors
		gp( char* ); //takes a file name to read;
		~gp();
		
		//--work functions--//
		void analyze(); //read and anlyze the gal file
};

//string splitter
//splits the given string by the given character
cv::vector< std::string > split( std::string, char );

//string stripper
//removes all instances of the given character from the string
void strip( std::string, char );


#endif
