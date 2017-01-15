#ifndef spotcheck_H
#define spotcheck_H

void findSpots( char* filename, vector<spot*>* spots, int);
void circScore( vector<spot*>* spots);
void showCircScores( char* filename, vector<spot*>* spots );
void analyze_height( char* filename, vector< spot* >* spots );
void Hough( vector<Vec3f>*, int, Mat* );

#endif spotcheck_H
