
/*
#include<opencv2/imgcodecs.hpp>

#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>

#include<iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat img = imread("./img1.jpg");
	if (img.empty())
	{
		cout << "Error" << endl;
		return -1;
	}
	else
	{
		imshow("image", img);
		Mat img1 = imread("./img1.jpg",IMREAD_GRAYSCALE);
		imshow("Grayscale Image", img1);
		waitKey(0);
		return 0;

	}
}
*/


#include <opencv2/highgui/highgui.hpp>


#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat rotate(Mat src, double angle)   //rotate function returning mat object with parametres imagefile and angle    
{
	Mat dst;      //Mat object for output image file
	Point2f pt(src.cols / 2., src.rows / 2.);          //point from where to rotate    
	Mat r = getRotationMatrix2D(pt, angle, 1.0);      //Mat object for storing after rotation
	warpAffine(src, dst, r, Size(src.cols, src.rows));  ///applie an affine transforation to image.
	return dst;         //returning Mat object for output image file
}

int main()
{
	Mat src = imread("images/img1.jpg");           //reading image file in mat object

	Mat dst;      //Mat object for output image file
	dst = rotate(src, 90);       //rotating image with 30 degree angle

	imshow("src", src);          //displaying input image file
	imshow("dst", dst);         //displaying output image file
	waitKey(0);                     //to exit press escape
	return 0;
}
















