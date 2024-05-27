#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
    Mat img = imread("j.png", IMREAD_UNCHANGED);
    resize(img, img, Size(500, 500));
    Mat kernel = getStructuringElement(MORPH_DILATE , Size(5, 5));
    Mat erodedImage, morphologyImage, dilateImage;
    morphologyEx(img, morphologyImage, MORPH_CLOSE, kernel);
    erode(img, erodedImage, kernel);
    dilate(img, dilateImage, kernel);
    
    imshow("Before", img);
    imshow("Morpho Image", morphologyImage);
    imshow("Erode Image", erodedImage);
    imshow("Dilate Image", dilateImage);
    waitKey(0);
}