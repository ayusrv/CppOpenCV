#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat img = imread("/home/kpit/opencv/samples/data/ayush.jpeg", IMREAD_COLOR);

    float range[] = {0, 256};
    const float* histRange = {range};
    int histSize = 256;   

    Mat hist;
    calcHist(&img, 1, nullptr, Mat(), hist, 1, &histSize, &histRange);

    int histWidth = 400, histHeight = 200;
    Mat histImg(histHeight, histWidth, CV_8U);
    normalize(hist, histImg, histImg.rows, NORM_MINMAX);

    for(int i=1; i<256; i++)
    {
    
    }

    return 0;
}