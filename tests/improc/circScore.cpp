#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>

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

double* circScore( char* );

/** @function main */
int main( int argc, char** argv )
{
  /// Load an image
  char* filename = argv[1];
	
	double* cScores = circScore( filename );
	double numCirc = cScores[0];
	printf("results--------\n");
	printf( "%f\n", numCirc ); 
  for( int i = 0; i < numCirc; i++ )
  {
  	printf( "%f\n", cScores[i+1] );
  }
  
  return 0;
}


double* circScore( char* filename )
{
	src = imread( filename );

  if( !src.data )
  { 
  	printf( "couldn't open file\n");
  	double* ans = new double[1];
  	ans[0] = -1;
  	return ans;
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
  
  //do a Hough transform to find the places where the dots are
  vector<Vec3f> circles;
	Mat tmp;
  GaussianBlur( edges, tmp, Size(9, 9), 2, 2 );
  HoughCircles( tmp, circles, CV_HOUGH_GRADIENT, 1, tmp.rows/8, thresh, thresh, 0, 0 );

	//now that we know the number of circles found, we can allocate the output array
	//the first element will be the number of circles found, so we can use 
	//that info later
	int numCirc = circles.size();
	double* ans = new double[ numCirc + 1];
	ans[0] = numCirc;
	
	
  //creating a copy to put the cirlces that the Hough trans find 
  Mat h_out;
  cvtColor( edges, h_out, CV_GRAY2RGB );
  int j, k, x, y, r, count;
  
  //these doubles will hold the centers and average distance from the edge
  //to the Hough center
  double xbar = 0;
	double ybar = 0;
	double dbar = 0;
  for( size_t i = 0; i < numCirc; i++ )
  {
  	//circle centers & radius
		x = cvRound(circles[i][0]);
		y = cvRound(circles[i][1]);
		r = cvRound(circles[i][2]) + rad_pad;
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
					//printf( "%d\n", i.val[0] );
					//get the distance of the point from the center
					count++;
					dbar += sqrt( pow( col - x, 2 ) + pow( row - y, 2 ) );
					xbar += col;
					ybar += row;
				}
			}
		}
		xbar /= count;
		ybar /= count;
		dbar /= count;
		
		if( PRINT )
		{
			printf( "cbar: (%f, %f), dbar = %f\n", xbar, ybar, dbar);
			printf( "%d non-black pixels found\n", count );
		}
		//calculate circle score
		//the Hough centers are pretty close to xbar and ybar
		//but i decided to use them for extra accuracy
		//though the improvement is marginal and can be taken out later
		double e = 1;
		for( int row = y - r; row < (y + r); row++ )
		{
			for( int col = x - r; col < (x + r); col++ )
			{

				Scalar i = edges.at<unsigned char>(row, col );
				if( i.val[0] == 255 )
				{
					//for each point, find it ratio to the average distace
					//the score is the product for all points
					e *= sqrt( pow( col - xbar, 2 ) + pow( row - ybar, 2 ) );
					e /=dbar;
				}
			}
		} 
		if( PRINT )
		{
			printf( "e: %f\n", e );
		}
		ans[ i+1 ] = e;
		
		Point center(x, y);	
		//draw the circles on h_out
		circle( h_out, center, 3, Scalar(0,255,0), -1, 8, 0 );
		circle( h_out, center, r, Scalar(255, 0 , 0), 3, 8, 0 );
		
		//draw the circle score on the output image
		//convert e to a string
		char buff[50];
		int n = sprintf( buff, "%f", e );
		std::string s( buff );
		putText( h_out, s, center, FONT_HERSHEY_SIMPLEX, 0.5, Scalar( 0, 0, 255 ), 1, 8 );
		//rectangle( h_out, start, end, Scalar( 0, 0, 255), 3, 8, 0 );
   }

  /// Show your results
  namedWindow( "Final Result", CV_WINDOW_AUTOSIZE );
  imshow( "Final Result", h_out );
  imwrite( "circScores.jpg", h_out );

  waitKey(0);
  return ans;
}
