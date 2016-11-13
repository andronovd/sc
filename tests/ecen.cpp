#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/core/core.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "ecen.h"

void ecen( char* filename )
{
	src = imread( filename );

  if( !src.data )
  { 
  	printf( "couldn't open file\n");
  	return;
  }
  for( int i = 0; i < 2; i++ )
	{
		pyrDown( src, src, Size( src.cols/SCALE, src.rows/SCALE ) );
	}
	

  //imshow( "Original image", src );
  
  
  //convert to grayscale
  cvtColor( src, src_gray, CV_BGR2GRAY );
  //imshow( "Grayscale Image", src_gray );
  
  
  
  //threshold & blur the image
  threshold( src_gray, src_gray, 41, 255, 0 );
  //imshow( "Thresholded Image", src_gray );
  
  GaussianBlur( src_gray, src_gray, Size( SIZE, SIZE), 0, 0 );
  //imshow( "Blurred Image", src_gray );
  

  /// Canny detector
  Canny( src_gray, edges, 100, 300, kernel_size );
  //imshow( "Canny Results", edges );

	//put a threshold on the canny results to improve the search later
	threshold( edges, edges, 6, 255, 0 );
  imwrite( "smoothed.jpg", edges);
  
  //do a Hough transform to find the places where the dots are
  vector<Vec3f> circles;

  /// Apply the Hough Transform to find the circles
	Mat tmp;
//	cvtColor( edges, edges, CV_BGR2GRAY );
  GaussianBlur( edges, tmp, Size(9, 9), 2, 2 );
  HoughCircles( tmp, circles, CV_HOUGH_GRADIENT, 1, tmp.rows/8, thresh, thresh, 0, 0 );

  /// Draw the circles detected
  Mat h_out;
  cvtColor( edges, h_out, CV_GRAY2RGB );
  int j, k, x, y, sum;
 
  for( size_t i = 0; i < circles.size(); i++ )
  {
		x = cvRound(circles[i][0]);
		y = cvRound(circles[i][1]);
		
		int r = cvRound(circles[i][2]) + rad_pad;
		printf( "(%d, %d), r = %d\n", x, y, r );

		double xbar = 0;
		double ybar = 0;
		double dbar = 0;
		int count = 0;
		for( int row = y - r; row < (y + r); row++ )
		{
			for( int col = x - r; col < (x + r); col++ )
			{

				Scalar i = edges.at<unsigned char>(row, col );
				if( i.val[0] == 255 )
				{
					count++;
					//printf( "(%d, %d): ", row, col );
					//std::cout<< i.val[0];
					//get the distance of the point from the center
					dbar += sqrt( pow( col - x, 2 ) + pow( row - y, 2 ) );
					xbar += col;
					ybar += row;
				}
			}
		}
		xbar /= count;
		ybar /= count;
		dbar /= count;
		
		printf( "cbar: (%f, %f), dbar = %f\n", xbar, ybar, dbar);
		printf( "%d non-black pixels found\n", count );
		
		//calculate eccentricity
		double e = 1;
		for( int row = y - r; row < (y + r); row++ )
		{
			for( int col = x - r; col < (x + r); col++ )
			{

				Scalar i = edges.at<unsigned char>(row, col );
				if( i.val[0] == 255 )
				{
					e *= sqrt( pow( col - x, 2 ) + pow( row - y, 2 ) );
					e /=dbar;
				}
			}
		}
		printf( "e: %f\n", e );
			
		Point center(x, y);	
		//draw the circles on h_out
		circle( h_out, center, 3, Scalar(0,255,0), -1, 8, 0 );
		circle( h_out, center, r, Scalar(255, 0 , 0), 3, 8, 0 );
		
		//draw the ecentricity
		//convert e to a string
		char buff[50];
		int n = sprintf( buff, "%f", e );
		std::string s( buff );
		putText( h_out, s, center, FONT_HERSHEY_SIMPLEX, 0.5, Scalar( 0, 0, 255 ), 1, 8 );
		//rectangle( h_out, start, end, Scalar( 0, 0, 255), 3, 8, 0 );
   }

  /// Show your results
  namedWindow( "Hough Circle Transform", CV_WINDOW_AUTOSIZE );
  imshow( "Hough Circle Transform", h_out );
  imwrite( "hough_result.jpg", h_out );

  waitKey(0);
  return;
}

