#include "hash_functions.h"

/** Given a sequence of images, and a Sp size of the desired patches,
 *  computes all possible SpxSpxSp patches of the video and stores them in the S vector of vectors (Mx(Sp^3));
 *
 *  VIDEO is the video sequence of frames to be analized.
 *  sizePatch is the chosen size of the patch( typically 3, 3x3x3)
 *  
 *  
 *
 * 	retuns S, a vector of vectors where each vector contains the data of a patch stored in a vector 1xSp^3 format.
 */
Mat create_random_image(int x, int y);
Mat create_random_matrix(int x, int y, int range, int init);
Mat compute_thresholds(Mat P, vector<vector<int> > S);

Mat createPivots(vector<vector<int> > S, int c, Mat thr, float em, float ev){

	int dim=S[0].size();

	Mat P=create_random_image(dim,c);			
	Mat thr;				

	// c random vectors of S have to be used to create P

	//

	t=compute_thresholds(P,S);





	return P;
}

Mat compute_thresholds(Mat P, vector<vector<int> > S){


	return Thr;
}

Mat create_random_image(int x,int y) {
 Mat A(x,y,CV_8UC1);
 int i1, i2;

 for (i1 = 0; i1 < x; i1++) {
  for (i2 = 0; i2 < y; i2++) {
	A.at<uchar>(i1,i2)=int( rand() % 255);
	//cout << int(A.at<uchar>(i1,i2)) << endl;
  }
 }


 return A;
}

Mat create_random_matrix(int x,int y, int range, int init) {
 Mat A(x,y,CV_32FC1);
 int i1, i2;

 for (i1 = 0; i1 < x; i1++) {
  for (i2 = 0; i2 < y; i2++) {
	A.at<float>(i1,i2)=int( rand() % range + init );
	//cout << float(A.at<float>(i1,i2)) << endl;
  }
 }


 return A;
}

