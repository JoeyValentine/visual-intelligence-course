#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;

void rot_rect();

int main()
{
	rot_rect();

	return 0;
}

// data augmentation
// 변환을 사용해서 적은 학습 데이터를 많이 늘린다.
// 컴퓨터의 입장에서는 물체 이미지를 이동하고 회전하면, 다른 이미지인줄 안다.
// 같은 이미지임을 학습시켜야 한다!
// keras에서 구현되어 있음 오오...
void rot_rect()
{
	cv::RotatedRect rr1(cv::Point2f(40, 30), cv::Size2f(40, 20), 30.f);
	// 30도 시계반대방향으로 회전, 음수면 시계방향

	cv::Point2f pts[4];
	rr1.points(pts);
	// 회전변환 공식으로 좌표 구함

	for (int i = 0; i < 4; ++i)
		cout << "pts[" << i << "]: " << pts[i] << endl;

	cv::Rect br = rr1.boundingRect();
	cout << "br: " << br << endl;
}