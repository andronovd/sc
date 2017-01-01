#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

/// Global variables
#define SCALE 2
#define SIZE 21

Mat src, src_gray;
Mat dst, detected_edges;
Mat tmp, tmp_gray;

int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;
char* window_name = "Edge Map";

/**
 * @function CannyThreshold
 * @brief Trackbar callback - Canny thresholds input with a ratio 1:3
 */
void CannyThreshold(int, void*)
{
  /// Reduce noise with a kernel 3x3
//  blur( tmp_gray, detected_edges, Size(3,3) );
	threshold( tmp_gray, tmp_gray, 41, 255, 0 );
	imshow( "theshold", tmp_gray );
  GaussianBlur( tmp_gray, detected_edges, Size( SIZE, SIZE), 0, 0 );
  imshow( "blurred", detected_edges );

  /// Canny detector
  Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );

  /// Using Canny's output as a mask, we display our result
  dst = Scalar::all(0);

  tmp.copyTo( dst, detected_edges);
  imshow( window_name, dst );
 }


/** @function main */
int main( int argc, char** argv )
{
  /// Load an image
  src = imread( argv[1] );

  if( !src.data )
  { return -1; }

  /// Create a matrix of the same type and size as src (for dst)
  tmp = src;
  dst = src;
  for( int i = 0; i < 2; i++ )
	{
		pyrDown( tmp, tmp, Size( tmp.cols/SCALE, tmp.rows/SCALE ) );
		pyrDown( dst, dst, Size( dst.cols/SCALE, dst.rows/SCALE ) );
	}
	//dst.create( src.size(), src.type() );

  /// Convert the image to grayscale
  cvtColor( tmp, tmp_gray, CV_BGR2GRAY );

  /// Create a window
  namedWindow( window_name, CV_WINDOW_AUTOSIZE );

  /// Create a Trackbar for user to enter threshold
  createTrackbar( "Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CannyThreshold );

  /// Show the image
  CannyThreshold(0, 0);

  /// Wait until user exit program by pressing a key
  waitKey(0);

  return 0;
}
