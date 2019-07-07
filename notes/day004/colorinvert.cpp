#include <iostream>
#include "opencv2/opencv.hpp"

void color_invert(cv::Mat& image);
void grayscale_invert(cv::Mat& image);

int main()
{
	cv::Mat img;
//	img = cv::imread("lena.jpg");
	img = cv::imread("lena.jpg", cv::IMREAD_GRAYSCALE);

	if (img.empty()) {
		std::cerr << "No such file" << std::endl;
		return -1;
	}

	if (img.channels() == 3)
		color_invert(img);
	else if (img.channels() == 1)
		grayscale_invert(img);

	cv::namedWindow("image");
	cv::imshow("image", img);
	cv::waitKey();

	return 0;
}

// 색 반전함수
void color_invert(cv::Mat& image)
{
	int n_lines = image.rows;
	int n_pixels = image.cols;

	for (int r = 0; r < n_lines; ++r)
		for (int c = 0; c < n_pixels; ++c)
		{
			cv::Vec3b& vec = image.at<cv::Vec3b>(r, c);  // 특정 픽셀에서 값을 가져옴(B, G, R)
			vec[0] = 255 - vec[0];
			vec[1] = 255 - vec[1];
			vec[2] = 255 - vec[2];
		}
}

void grayscale_invert(cv::Mat& image)
{
	int n_lines = image.rows;
	int n_pixels = image.cols;

	for (int r = 0; r < n_lines; ++r)
		for (int c = 0; c < n_pixels; ++c)
		{
			uchar& value = image.at<uchar>(r, c);
			value = 255 - value;
		}
}