#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;

void size_op();

int main()
{
	size_op();

	return 0;
}

void size_op()
{
	// 가로 x 세로
	// Point와 Size로 정사각형 정의 가능
	cv::Size sz1, sz2(10, 20);			// sz1 = [0 x 0], sz2 = [10 x 20]
	sz1.width = 5; sz1.height = 10;		// sz1 = [5 x 10]
	cout << "sz1: " << sz1 << endl;
	cout << "sz2: " << sz2 << endl;

	cv::Size sz3 = sz1 + sz2;			// sz3 = [15 x 30]
	cv::Size sz4 = sz1 * 2;				// sz4 = [10 x 20]
	// 2 * sz1은 불가능
	
	cout << "sz3: " << sz3 << endl;
	cout << "sz4: " << sz4 << endl;

	int area1 = sz4.area();				// area1 = 200
}