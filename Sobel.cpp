#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    cv::String fileLocation = "/home/kpit/opencv/samples/data/messi5.jpg";
    Mat srcImg = imread(fileLocation, IMREAD_UNCHANGED);
    GaussianBlur(srcImg, srcImg, Size(3,3), 0,0, BORDER_DEFAULT);
    // cvtColor(srcImg, srcImg, COLOR_BGR2GRAY);
    Mat grad_x, grad_y;
    Mat abs_grad_x, abs_grad_y;
    Sobel(srcImg, grad_x, CV_16S, 1, 0);
    Sobel(srcImg, grad_y, CV_16S, 0, 1);
    convertScaleAbs(grad_x, abs_grad_x);
    imshow("X Grad", abs_grad_x);
    convertScaleAbs(grad_y, abs_grad_y);
    imshow("Y Grad", abs_grad_y);
    Mat grad;
    addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);
    imshow("Final image", grad);

    //SOBEL BACKGROUND 
    Mat srcImg2 = imread(fileLocation);
    GaussianBlur(srcImg2, srcImg2, Size(3,3), 0, 0);
    Mat dst1;
    Mat kernel = (Mat_<char>(3,3) << -1, 0, +1,
        -2, 0, +2,
        -1, 0, +1);
    filter2D(srcImg2, dst1, srcImg2.depth(), kernel);
    Mat dst2;
    Mat kernel2 = (Mat_<char>(3,3) << -1, -2, -1,
        0, 0, 0,
        +1, +2, +1);
    filter2D(srcImg2, dst2, srcImg2.depth(), kernel2);
    Mat ans;
    addWeighted(dst1, 0.5, dst2, 0.5, 0, ans);
    imshow("Filter Ans", ans);
    imshow("X", dst1);
    imshow("Y", dst2);
    waitKey(0);
}