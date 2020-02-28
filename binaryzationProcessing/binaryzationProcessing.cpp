#include <iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	cv::Mat M1 = cv::imread("D:\\Files\\2.jpg");//读取图片
	uchar threshold = 100;//设定阈值
	int height = M1.rows;
	int width = M1.cols;
	for (int i = 0; i < height; i++)//遍历像素
	{
		for (int j = 0; j < width; j++)
		{
			uchar average = (M1.at<Vec3b>(i, j)[0] + M1.at<Vec3b>(i, j)[1] + M1.at<Vec3b>(i, j)[2]) / 3;//计算RGB平均值
			if (average > threshold)//与阈值比较，进行二值化
			{
				average = 255;
			}
			else
			{
				average = 0;
			}
			M1.at<Vec3b>(i, j)[0] = average;//赋值
			M1.at<Vec3b>(i, j)[1] = average;//赋值
			M1.at<Vec3b>(i, j)[2] = average;//赋值
		}
	}
	cv::imshow("M1", M1);
	waitKey(0);
}