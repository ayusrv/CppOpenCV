#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    cv::String fileLocation = "/home/kpit/opencv/samples/data/messi5.jpg";
    Mat srcImage = imread(fileLocation);
    Mat dst;
    GaussianBlur(srcImage, srcImage, Size(3,3), 0, 0);
    cvtColor(srcImage, srcImage, COLOR_BGR2GRAY);
    Laplacian(srcImage, dst, CV_16S, 3);
    convertScaleAbs(dst, dst, CV_8S);
    imshow("IMage", dst);
    waitKey(0);
}