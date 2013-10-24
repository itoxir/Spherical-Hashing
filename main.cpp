//=======================================================================================================
// Name        : main.cpp
// Author      : Iban Torres
// Version     :
// Copyright   : 
// Description : Storing data in a Hash Table using the codes given by Spherical Hashing in shfunctions.m
//=======================================================================================================

// std lib includes
#include <iostream>
#include <cstdio>
#include <time.h>
using namespace std;

// opencv includes
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
using namespace cv;

// our includes
#include "patchcratch.h"
#include "hash_code.h"
#include "hash_functions.h"


#define C=32;
#define N=27;

class data{
public:
	data();
	vector<int> getKey();
	int getHashIndex(int Tsize, Mat P, Mat thr, vector<int> m);
	friend istream& operator>> (istream& in, data& right);
	friend ostream& operator<< (ostream& out, const data& right);
private:
	vector<int> m;						// float m ? float m[] ? float m[27]?  float m[c]?? string m?????????????????????????????? 
};

vector<int> data::getKey(){
	return m;
}


int data::getHashIndex(	int Tsize, // Tsize just in case, to make modTsize(hashindex), Tsize is 2^c.
						Mat P,	   // P is (nxc) matrix of pivots (n=dimensions of data space, tipically 3x3x3 patch =27; c=number of hyperspheres)
						Mat thr,   // thr is (1xc) vector of thresholds for each pivot corresponding to each hypersphere.	
						vector<int> m)	   // m is (nx1) vector of data corresponding to a patch
{	
	
	int b=create_hash_code(m,P,thr);   // m'ho he de currar en c++
	return b;
}

template <typename T>
class HashTable{
public:
	HashTable(int Tsize);
	void insert(T newData);
	T* find(int indexQuery);
	template <typename T>
	friend ostream& operator<<(ostream& out, const HashTable& right);
private:
	vector< vector<T> > table;
};

template <typename T>
HashTable<T>::HashTable(int Tsize){
	table.resize(Tsize);
}

template <typename T>
void HashTable<T>::insert(T newData){
	int index=newData.getHashIndex(Tsize,P,thr,m);		// ??
	table[index].push_back(newData);
}


template <typename T>
T* HashTable<T>::find(int indexQuery){
	return &table[indexQuery];
}







int main(int argc, char** argv) {

	string filename = "video.avi";
	VideoCapture capture(filename);
	Mat frame;
	Mat VIDEO;
	if( !capture.isOpened() )
	   cout << "Error when reading steam_avi" << endl;
	while(capture.get(CV_CAP_PROP_POS_FRAMES)!=0)
    {
		bool bSuccess = capture.read(frame);		// read a new frame from video
		if (!bSuccess)								//if not success, break loop
        {
			cout << "Cannot read the frame from video file" << endl;
            break;
        }
		VIDEO.push_back(frame);
	}

	int Nframes=VIDEO.size;
	int dim;
											//c=num of spheres
	int tsize=2^C;
	HashTable<data> SphHash(tsize);
	data Patch;
	Patch.m
	
	vector< vector<int> > S=patchStore(VIDEO, dim);

	P=createPivots(S,c,t,em,ev);

	for(int i=0; i<S.size(); i++){
		SphHash.insert(S[i]);
	}

	return 0;
}
