#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;

int thresh1 = 50;
int thresh2 = 50;
int rad_thresh = 10;
Mat src, src_gray;
char* window_name = "cvHough";

void test( int, void*);

/** @function main */
int main(int argc, char** argv)
{

  /// Read the image
  src = imread( argv[1], 1 );

  if( !src.data )
    { return -1; }

  /// Convert it to gray
  cvtColor( src, src_gray, CV_BGR2GRAY );
 	GaussianBlur( src_gray, src_gray, Size(9, 9), 2, 2 );
 	
	namedWindow( window_name, CV_WINDOW_AUTOSIZE );
	
	createTrackbar( "param_1", window_name, &thresh1, 500, test );
	createTrackbar( "param_2", window_name, &thresh2, 500, test );

 	test( 0 , 0 );

  waitKey(0);
  return 0;
}

void test( int, void* )
{
	Mat * src_temp = new Mat;
	*src_temp = src;

  vector<Vec3f> circles;

  /// Apply the Hough Transform to find the circles
  HoughCircles( src_gray, circles, CV_HOUGH_GRADIENT, 1, src_gray.rows/8, thresh1, thresh2, 0, 0 );

  /// Draw the circles detected
  for( size_t i = 0; i < circles.size(); i++ )
  {
      Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
      int radius = cvRound(circles[i][2]);
      // circle center
      circle( *src_temp, center, 3, Scalar(0,255,0), -1, 8, 0 );
      // circle outline
      circle( *src_temp, center, radius+rad_thresh, Scalar(0,0,255), 3, 8, 0 );
   }

  /// Show your results
  circles.clear();

  imshow( window_name, *src_temp );
  delete( src_temp );
}
