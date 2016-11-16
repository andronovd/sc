#ifndef spot_h
#define spot_h


#include "opencv2/imgproc/imgproc.hpp"
using namespace cv;

class spot
{
	public:
	//--data members
		Point center;
		vector<Point> edge;
		
		double circScore;
		double avg_height;
		double surfScore;
		double volume;
		
		
	//--function members	
		spot();
		spot( Point );
		~spot();
};

#endif
