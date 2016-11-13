#include <opencv2/core/core.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    if( argc != 2)
    {
     cout <<" Usage: ps ImageToLoadAndDisplay" << endl;
     return -1;
    }

    Mat image;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);   // Read the file
    cvtColor( image, image, CV_RGB2GRAY );
		
		int x = 136;
		int y = 216;
		int r = 40;
		Point start( x - r, y - r );
		Point end( x + r, y + r );
		int count = 0;
		
		for( int row = y - r; row < (y + r); row++ )
		{
			for( int col = x - r; col < (x + r); col++ )
			{
				count++;
				Scalar i = image.at<unsigned char>(row, col );
				if( i.val[0] != 0 )
				{
					printf( "(%d, %d): ", row, col );
					std::cout<< i.val[0];
					//get the distance of the point from the center
					float d = sqrt( pow( col - x, 2 ) + pow( row - y, 2 ) );
					printf( ", d = %f\n" , d );
				}
			}
		}
		printf( "%d pixels checked\n", count );		
		
		
	  rectangle( image, start, end, Scalar( 0, 0, 255), 3, 8, 0 );  
	  imshow( "test", image );
	  waitKey( 0 );
    return 0;
}
