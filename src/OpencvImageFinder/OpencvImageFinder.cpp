// testOpencv.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <opencv2/opencv.hpp>

int main(int argc, char ** argv)
{
    std::cout << "Hello World!\n";

	//¼ÓÔØÔ´Í¼ÏñºÍÄ£°åÍ¼Ïñ
	cv::Mat image_source = cv::imread("test.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat image_template = cv::imread("test_sub.jpg", cv::IMREAD_GRAYSCALE);

	cv::Mat image_matched;

	//Ä£°åÆ¥Åä
	cv::matchTemplate(image_source, image_template, image_matched, cv::TM_CCOEFF_NORMED);

	double minVal, maxVal;
	cv::Point minLoc, maxLoc;
	//Ñ°ÕÒ×î¼ÑÆ¥ÅäÎ»ÖÃ
	cv::minMaxLoc(image_matched, &minVal, &maxVal, &minLoc, &maxLoc);

	cv::Mat image_color;
	cv::cvtColor(image_source, image_color, cv::COLOR_GRAY2BGR);
	cv::circle(image_color,
		cv::Point(maxLoc.x + image_template.cols / 2, maxLoc.y + image_template.rows / 2),
		20,
		cv::Scalar(0, 0, 255),
		2,
		8,
		0);

	cv::imshow("source image", image_source);
	cv::imshow("match result", image_matched);
	cv::imshow("target", image_color);
	cv::waitKey(0);
	cv::destroyAllWindows();
	std::cout << minLoc.x << " , " << minLoc.y << std::endl;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
