#ifndef spot_h
#define spot_h


#include "opencv2/imgproc/imgproc.hpp"
using namespace cv;

class spot
{
	public:
	//--data members
		static int numCirc;
		
		int c_x;
		int c_y;
		
		double xbar;
		double ybar;
		
		double avg_r;
		vector<Point> edge;
		
		double circScore;
		double avg_height;
		double surfScore;
		double volume;
		
		
	//--function members	
		spot();
		spot( int, int );
		~spot();
};

#endif
