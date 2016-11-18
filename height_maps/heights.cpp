#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

int main( int argc, char** argv )
{
	if( argc != 2)
	{
		printf( "Error expecting .tiff image name\n" );
		return 0;
	}
	
	char* filename = argv[1];
	
	Mat src = imread( filename );
	if( !src.data )
	{
		printf( "Error: couldn't read image file\n" );
	}
	
	int rows = src.rows;
	int cols = src.cols;
	
	double minH = 100000.0;
	double maxH = 0.0;
	double avgH;
	for( int i = 0; i < rows; i++ )
	{
		for( int j = 0; j < cols; j++ )
		{
			Scalar s = src.at<unsigned char>( i, j );
			int intensity = s[0];
			double frac = (double) (intensity/255.0);
			double height = 102.223 * frac;
			
			avgH += height;
			if( height < minH )
			{
				minH = height;
			}
			else if( height > maxH )
			{
				maxH = height;
			}
		}
	}
	
	avgH /= rows*cols;
	
	printf( "min: %f, max: %f, avg: %f\n", minH, maxH, avgH );

	return 0;
}
