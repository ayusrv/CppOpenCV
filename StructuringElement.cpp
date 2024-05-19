#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
    Mat img = imread("j.png", IMREAD_UNCHANGED);
    resize(img, img, Size(50, 50));
    Mat kernel = getStructuringElement(MORPH_CROSS, Size(3, 3));
    Mat newImg = (Mat_<uchar>(5, 5) << 0, 0, 0, 0, 0,
                  0, 0, 255, 0, 0,
                  0, 255, 255, 255, 0,
                  0, 0, 255, 0, 0,
                  255, 0, 0, 0, 0);
    std::cout<<newImg<<"\n";
    Mat naya;
    dilate(newImg, naya, kernel);
    std::cout<<naya<<"\n";
    Mat erodedImage, morphologyImage, dilateImage;
    morphologyEx(img, morphologyImage, MORPH_GRADIENT, kernel);
    erode(img, erodedImage, kernel);
    dilate(img, dilateImage, kernel);
    imshow("Before", img);
    imshow("Morpho Image", morphologyImage);
    imshow("Erode Image", erodedImage);
    imshow("Dilate Image", dilateImage);
    waitKey(0);
}