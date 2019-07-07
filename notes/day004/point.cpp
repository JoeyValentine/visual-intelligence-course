#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;

void point_op();

int main()
{
	point_op();

	return 0;
}

void point_op()
{
	cv::Point pt1;				// pt1 = (0, 0)
	pt1.x = 5;	pt1.y = 10;		// pt1 = (5, 10)
	cv::Point pt2(10, 30);		// pt2 = (10, 30)

	cout << "pt1: " << pt1 << endl;
	cout << "pt2: " << pt2 << endl;

	cv::Point pt3 = pt1 + pt2;	// pt3 = (15, 40)
	cv::Point pt4 = 2 * pt1;	// pt2 = (10, 20)

	cout << "pt3: " << pt3 << endl;
	cout << "pt4: " << pt4 << endl;

	int d1 = pt1.dot(pt2);		// d1 = 350
	bool b1 = (pt1 == pt2);		// b1 == false

	cout << "d1: " << d1 << endl;
	cout << "b1: " << b1 << endl;
}