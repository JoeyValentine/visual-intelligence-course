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
	// 4��и鿡�� x���� width
	// 4��и鿡�� y���� height

	cv::Rect rc1;
	cv::Rect rc2(10, 10, 60, 40);

	cv::Rect rc3 = rc1 + cv::Size(50, 40);
	// rc1(0,0,0,0) -> (0,0,50,40)

	cv::Rect rc4 = rc2 + cv::Point(10, 10);
	// rc2(10,10,60,40) -> (20,20,60,40)

	cv::Rect rc5 = rc3 & rc4;
	// �������� ������

	cv::Rect rc6 = rc3 | rc4;
	// rc6�� �� �簢���� �����ϴ� �簢��

	cout << "rc5: " << rc5 << endl;
	cout << "rc6: " << rc6 << endl;
}