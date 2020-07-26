/*********************************************************
				Heisanbug OpenCV Test
				2020.07.04
				Mat 함수를 이용한 이미지 불러오고 출력하기
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

	//경로의 이미지를 image 변수에 읽어옵니다.
	//imread flag 값에 따라 color 이미지 혹은 
	//gray scale 이미지를 불러옵니다.
	imageColor = cv::imread(IMAGE_PATH, cv::IMREAD_COLOR);
	imageGray = cv::imread(IMAGE_PATH, cv::IMREAD_GRAYSCALE);

	//이미지를 정상적으로 읽어왔는지 확인
	if (imageColor.empty() || imageGray.empty()) {
		std::cout << IMAGE_PATH
			<< " 이미지를 불러오는 데 문제가 생겼습니다." << std::endl;
		return -1;
	}

	//이미지를 window를 생성하여 보여줍니다.
	cv::namedWindow(COLOR_IMAGE_WINDOW_NAME, cv::WINDOW_NORMAL);
	cv::namedWindow(COLOR_IMAGE_WINDOW_NAME, cv::WINDOW_AUTOSIZE);
	cv::imshow(COLOR_IMAGE_WINDOW_NAME, imageColor);
	cv::imshow(GRAY_IMAGE_WINDOW_NAME, imageGray);

	//키 입력이 있을 때 까지 기다립니다.
	cv::waitKey(0);

	//생성하였던 윈도우를 제거합니다.
	cv::destroyWindow(COLOR_IMAGE_WINDOW_NAME);
	cv::destroyWindow(GRAY_IMAGE_WINDOW_NAME);

	//아래의 함수를 사용하면, 사용하고 있던 윈도우 전부를 제거합니다.
	//cv::destroyAllWindows();

	return 0;
}