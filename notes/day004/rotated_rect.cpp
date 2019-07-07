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
// ��ȯ�� ����ؼ� ���� �н� �����͸� ���� �ø���.
// ��ǻ���� ���忡���� ��ü �̹����� �̵��ϰ� ȸ���ϸ�, �ٸ� �̹������� �ȴ�.
// ���� �̹������� �н����Ѿ� �Ѵ�!
// keras���� �����Ǿ� ���� ����...
void rot_rect()
{
	cv::RotatedRect rr1(cv::Point2f(40, 30), cv::Size2f(40, 20), 30.f);
	// 30�� �ð�ݴ�������� ȸ��, ������ �ð����

	cv::Point2f pts[4];
	rr1.points(pts);
	// ȸ����ȯ �������� ��ǥ ����

	for (int i = 0; i < 4; ++i)
		cout << "pts[" << i << "]: " << pts[i] << endl;

	cv::Rect br = rr1.boundingRect();
	cout << "br: " << br << endl;
}