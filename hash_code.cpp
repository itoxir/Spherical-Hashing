#include "hash_code.h"
#include <cstdlib>
/** Given a patch m, the refined Pivot Matrix P and the Threshold Vector Thr of the Spherical Hashing
 *  computes the code (index) of the given patch for the Hash Table using the spherical hashing distances
 *
 *  vector<int> m is the given patch of length "dim"(=27). 
 *  Mat P is the refined Pivot Matrix (dim x c) of the Spherical Hashing Computed for a certain data set.
 *  Mat Thr is the refined Threshold Matrix (1 x c) of the Spherical Hashing computed for a certain data set.
 *  
 *
 * 	retuns bin2dec: the decimal value of the code, index for the hash table.
 */
Mat create_random_image(int x, int y);
Mat create_random_matrix(int x, int y, int range, int init);

int create_hash_code(vector<int> m, Mat P, Mat thr){
	
	int c=P.cols;
	int dim=P.rows;
	Mat mdata(m);
	
	vector<int> b_temp;								
	int bin2dec=0;

	Mat mExtend;	
	Mat paddMat=Mat::ones(1,c,CV_32FC1);
	mdata.convertTo(mdata,CV_32FC1);
	gemm(mdata,paddMat,1,NULL,NULL,mExtend);
	mExtend.convertTo(mExtend,CV_8UC1);

	Mat Dif=mExtend-P;
	pow(Dif,2,Dif);
	pow(thr,2,thr);
	for (int i=0; i<c; i++){
		b_temp.push_back(0);
		for (int j=0; j<dim; j++){
			b_temp[i]+=int(Dif.at<uchar>(j,i));
		}
		if(b_temp[i]<=int(thr.at<float>(0,i))){
			b_temp[i]=1;
			bin2dec+=pow(2.0,double(i));
		}
		else
			b_temp[i]=0;
			
		
	}
	
	cout << "bucket: " << bin2dec << endl;
	return bin2dec;
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
