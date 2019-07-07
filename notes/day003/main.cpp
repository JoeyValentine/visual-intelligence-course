#include <iostream>
#include "opencv2/opencv.hpp"

int main()
{
	std::cout << CV_VERSION << std::endl;
	
	cv::Mat img;
	img = cv::imread("lena.jpg");

	if (img.empty()) {
		std::cerr << "No such file" << std::endl;
		return -1;
	}

	cv::namedWindow("imageLoad");
	cv::imshow("imageLoad", img);

	cv::waitKey();

	cv::imwrite("lena.bmp", img);

	return 0;
}