/*********************************************************
				Heisanbug OpenCV Test
				2020.07.04
				Mat �Լ��� �̿��� �̹��� �ҷ����� ����ϱ�
				Alta software developer
**********************************************************/

//C++ header file 
#include <iostream>

//opencv header file include
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"


#define IMAGE_PATH "opencv_test_image.jpg"
#define COLOR_IMAGE_WINDOW_NAME "color image"
#define GRAY_IMAGE_WINDOW_NAME "gray image"

//project main function
int main(int argc, char** argv) {

	//OpenCV Mat class
	cv::Mat imageColor;
	cv::Mat imageGray;

	//����� �̹����� image ������ �о�ɴϴ�.
	//imread flag ���� ���� color �̹��� Ȥ�� 
	//gray scale �̹����� �ҷ��ɴϴ�.
	imageColor = cv::imread(IMAGE_PATH, cv::IMREAD_COLOR);
	imageGray = cv::imread(IMAGE_PATH, cv::IMREAD_GRAYSCALE);

	//�̹����� ���������� �о�Դ��� Ȯ��
	if (imageColor.empty() || imageGray.empty()) {
		std::cout << IMAGE_PATH
			<< " �̹����� �ҷ����� �� ������ ������ϴ�." << std::endl;
		return -1;
	}

	//�̹����� window�� �����Ͽ� �����ݴϴ�.
	cv::namedWindow(COLOR_IMAGE_WINDOW_NAME, cv::WINDOW_NORMAL);
	cv::namedWindow(COLOR_IMAGE_WINDOW_NAME, cv::WINDOW_AUTOSIZE);
	cv::imshow(COLOR_IMAGE_WINDOW_NAME, imageColor);
	cv::imshow(GRAY_IMAGE_WINDOW_NAME, imageGray);

	//Ű �Է��� ���� �� ���� ��ٸ��ϴ�.
	cv::waitKey(0);

	//�����Ͽ��� �����츦 �����մϴ�.
	cv::destroyWindow(COLOR_IMAGE_WINDOW_NAME);
	cv::destroyWindow(GRAY_IMAGE_WINDOW_NAME);

	//�Ʒ��� �Լ��� ����ϸ�, ����ϰ� �ִ� ������ ���θ� �����մϴ�.
	//cv::destroyAllWindows();

	return 0;
}