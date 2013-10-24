// std lib includes
#include <iostream>
#include <cstdio>
using namespace std;

// opencv includes
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;


Mat createPivots(vector<vector<int> > S, int c, Mat thr, float em, float ev){
