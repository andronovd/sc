#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include "spot.h"

using namespace cv;

/// Global variables
#define SCALE 2
#define SIZE 21

#define PRINT 0 //show the print debug statements
#define SHOW 0 //Show the images along the way

Mat src, src_gray, edges, edges_gray;

int rad_pad = 10;
int thresh = 70;
int color_thresh = 600;
int kernel_size = 3;

void findSpots( char*, vector<spot*>* );
void circScore( vector<spot*>* );
void showCircScores( char*, vector< spot* >* );
void analyze_height( char*, vector< spot* >* );

/** @function main */
int main( int argc, char** argv )
{
  /// Load an image
  char* filename = argv[1];
	vector< spot* > spots;
	
	findSpots( filename, &spots );
	analyze_height( filename, &spots );
	/*
	circScore( &spots );
	printf( "%d\n", spots.size() );
	for( int i = 0; i < spots.size(); i++ )
	{
		printf( "%f\n", spots[i]->circScore);
	}
	*/
	//showCircScores( filename, &spots );
	
  return 0;
}


void findSpots( char* filename, vector<spot*>* spots)
{
	src = imread( filename );

  if( !src.data )
  { 
  	printf( "couldn't open file\n");
  	return;
  }
  
  //I'm scaleing down the image because the orignal was quite
  //large and didn't fit on my screen
  for( int i = 0; i < 2; i++ )
	{
		pyrDown( src, src, Size( src.cols/SCALE, src.rows/SCALE ) );
	}
	
	if(SHOW)
	{
  	imshow( "Original image", src );
  }
  
  
  //convert to grayscale
  cvtColor( src, src_gray, CV_BGR2GRAY );
  if(SHOW)
  {
  	imshow( "Grayscale Image", src_gray );
  }
  
  
  
  //threshold & blur the image
  threshold( src_gray, src_gray, 41, 255, 0 );
  if(SHOW)
  {
  	imshow( "Thresholded Image", src_gray );
  }
  
  GaussianBlur( src_gray, src_gray, Size( SIZE, SIZE), 0, 0 );
  if(SHOW)
  {
  	imshow( "Blurred Image", src_gray );
  }
  

  /// Canny detector
  Canny( src_gray, edges, 100, 300, kernel_size );
  if(SHOW)
  {
  	imshow( "Canny Results", edges );
  }

	//put a threshold on the canny results to improve the search later
	threshold( edges, edges, 6, 255, 0 );
  imwrite( "edges.jpg", edges);
  
  //do a Hough transform to find the places where the spots are
  vector<Vec3f> circles;
	Mat tmp;
  GaussianBlur( edges, tmp, Size(9, 9), 2, 2 );
  HoughCircles( tmp, circles, CV_HOUGH_GRADIENT, 1, tmp.rows/8, thresh, thresh, 0, 0 );

	//now that we know the number of circles found, we can allocate the output array
	//the first element will be the number of circles found, so we can use 
	//that info later
	
	
  //creating a copy to put the cirlces that the Hough trans find 
  Mat h_out;
  cvtColor( edges, h_out, CV_GRAY2RGB );
  int j, k, x, y, r, count;
  
  //these doubles will hold the centers and average distance from the edge
  //to the Hough center
  double xbar = 0;
	double ybar = 0;
	double dbar = 0;
	int numCirc = circles.size();
  for( size_t i = 0; i < numCirc; i++ )
  {
  	//circle centers & radius
  	x = cvRound( circles[ i ][ 0 ] );
  	y = cvRound( circles[ i ][ 1 ] );
		r = cvRound(circles[i][2]) + rad_pad;
		spot* dot = new spot( x, y );
		if( PRINT )
		{
			printf( "(%d, %d), r = %d\n", x, y, r );
		}

		xbar = 0;
		ybar = 0;
		dbar = 0;
		count = 0;
		//check all the pixels in a square 2r by 2r for the white boundry
		for( int row = y - r; row < (y + r); row++ )
		{
			for( int col = x - r; col < (x + r); col++ )
			{
				//if the pixel is white, the its the boundry found by canny
				Scalar i = edges.at<unsigned char>(row, col );
				//std::cout <<"ival " << i.val[0]<< std::endl;
				if( i.val[0] == 255 )
				{
					//get the distance of the point from the center
//					Point p( row, col );
					dot->edge.push_back( Point( col, row ) );
					count++;
					dbar += sqrt( pow( col - x, 2 ) + pow( row - y, 2 ) );
					xbar += col;
					ybar += row;
				}
			}
		}
		
		dot->xbar = xbar/count;
		dot->ybar = ybar/count;
		dot->avg_r = dbar/count;
		
		spots->push_back( dot );
		
		if( PRINT )
		{
			printf( "cbar: (%f, %f), dbar = %f\n", xbar/count, ybar/count, dbar/count);
			printf( "%d non-black pixels found\n", count );
		}
	}
	return;
}

void circScore( vector<spot*>* spots)
{
		//calculate circle score
		//the Hough centers are pretty close to xbar and ybar
		//but i decided to use them for extra accuracy
		//though the improvement is marginal and can be taken out later
		double e;
		int numCirc = spots->at( 0 )->numCirc;
		
		int numPnt;
		double xbar;
		double ybar;
		double dbar;
		for( int i = 0; i < numCirc; i++ )
		{
			numPnt = spots->at(i)->edge.size();
			
			xbar = spots->at(i)->xbar;
			ybar = spots->at(i)->ybar;
			dbar = spots->at(i)->avg_r;
			
			e = 1.0;
			for( int j = 0; j < numPnt; j++ )
			{
				e *= sqrt( pow( spots->at(i)->edge[j].x - xbar, 2 ) + pow( spots->at(i)->edge[j].y- ybar, 2 ) );
				e /=dbar;
			}
			spots->at(i)->circScore = e;
			if( PRINT )
			{
				printf( "spot No.%d, e: %f\n", i, e );
			}
			
		}
	
  return;
}

void showCircScores( char* filename, vector<spot*>* spots )
{
	src = imread( filename );

  if( !src.data )
  { 
  	printf( "couldn't open file\n");
  	return;
  }
  
  //I'm scaleing down the image because the orignal was quite
  //large and didn't fit on my screen
  for( int i = 0; i < 2; i++ )
	{
		pyrDown( src, src, Size( src.cols/SCALE, src.rows/SCALE ) );
	}
	
	if(SHOW)
	{
  	imshow( "Original image", src );
  }
  
  
  //convert to grayscale
  cvtColor( src, src_gray, CV_BGR2GRAY );
  if(SHOW)
  {
  	imshow( "Grayscale Image", src_gray );
  }
  
  
  
  //threshold & blur the image
  threshold( src_gray, src_gray, 41, 255, 0 );
  if(SHOW)
  {
  	imshow( "Thresholded Image", src_gray );
  }
  
  GaussianBlur( src_gray, src_gray, Size( SIZE, SIZE), 0, 0 );
  if(SHOW)
  {
  	imshow( "Blurred Image", src_gray );
  }
  

  /// Canny detector
  Canny( src_gray, edges, 100, 300, kernel_size );
  if(SHOW)
  {
  	imshow( "Canny Results", edges );
  }
  
  
  //convert edges back to a color image to see the text and circles
  cvtColor( edges, edges, CV_GRAY2BGR );
  int numCirc = spots->at( 0 )->numCirc;
  double e, x, y;
  int r;
  for( int i = 0 ; i < numCirc; i++ )
  {
  	e = spots->at( i )->circScore;
  	r = spots->at( i )->avg_r + rad_pad;
  	x = spots->at( i )->c_x;
  	y = spots->at( i )->c_y;
  	Point center( x, y );
  	
  	//draw the circles on h_out
		circle( edges, center, 3, Scalar(0,255,0), -1, 8, 0 );
		circle( edges, center, r, Scalar(255, 0 , 0), 3, 8, 0 );
	
		//draw the circle score on the output image
		//convert e to a string
		char buff[50];
		int n = sprintf( buff, "%f", e );
		std::string s( buff );
		putText( edges, s, center, FONT_HERSHEY_SIMPLEX, 0.5, Scalar( 0, 0, 255 ), 1, 8 );
		//rectangle( h_out, start, end, Scalar( 0, 0, 255), 3, 8, 0 );			
	}
  /// Show your results
  if( SHOW )
  {
  	namedWindow( "Final Result", CV_WINDOW_AUTOSIZE );
  	imshow( "Final Result", edges );
  	imwrite( "circScores.jpg", edges );

  	waitKey(0);
  }
  return;
}

void analyze_height( char* filename, vector< spot* >* spots )
{
	double maxHeight = 100.0;
	src = imread( filename );
	Mat src_gray, src_thresh; //greyscale
	//down size the image by 4x
	for( int i = 0; i < 2; i++ )
	{
		pyrDown( src, src, Size( src.cols/2, src.rows/2 ) );
	}
	//convert to grey scale and put a threshold over it
	cvtColor( src, src_gray, CV_BGR2GRAY );
  threshold( src_gray, src_thresh, 41, 255, 0 );
  if(	SHOW )
  {
  	imshow("thresh & grey", src_gray );
  	
  }
  
  //now iterate through all the circles and use
  //the bounding box method to look for white pixels and 
  //measure the metrics regarding the height. 
  int numCirc = spots->at( 0 )->numCirc;
  int row, col, x, y, r, count;
  double avgH, vol, stdH, height;
  for( int i = 0; i < numCirc; i++ )
  {
  	avgH = 0.0;
  	vol = 0.0;
  	stdH = 0.0;
  	height = 0.0;
  	count = 0;
  	
  	x = spots->at( i )->c_x;
  	y = spots->at( i )->c_y;
  	r = (int)spots->at( i )->avg_r;
  	
  	for(int row = y - r ; row < (y + r); row++ )
  	{
  		for(int col = x - r ; col < (x + r); col++ )
  		{
  			Scalar i = src_thresh.at<unsigned char>( row, col );
  			//printf("%d\n", i.val[0] );
  			if( i.val[0] == 255 )
  			{
	  			Scalar j = src_gray.at<unsigned char>( row, col );
  				count++;
  				//calculate height	
  				height = maxHeight * j.val[0] / 255.0;
					avgH += height;
					stdH += ( pow( height, 2 ) );
				}
  		}
  	}
  	if( PRINT )
  	{
  		printf( "Found %d white pixels", count );
  	}
  	spots->at( i )->volume = avgH;
  	avgH /= count;
  	stdH = (stdH/count) - ( pow( avgH, 2 ) ) ;
  	spots->at( i )->avg_height = avgH;
  	spots->at( i )->std_height = stdH; 	
  	
  	//show the results;
  	spots->at( i )->info();
  
  }
	
	return;
}
