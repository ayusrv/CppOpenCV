#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
    String fileLocation1 = "/home/kpit/opencv/samples/data/HappyFish.jpg";
    String fileLocation2 = "/home/kpit/opencv/samples/data/ml.png";
    Mat image1 = imread(fileLocation1, IMREAD_UNCHANGED);
    resize(image1, image1, Size(500,600), 10, 10);
    Mat image2 = imread(fileLocation2, IMREAD_UNCHANGED);
    resize(image2, image2, Size(500,600), 10, 10);
    Mat result;
    std::cout<<image1.channels()<<" "<<image2.channels()<<"\n";
    bitwise_and(image1, image2, result);
    imshow("And Result", result);
    bitwise_or(image1, image2, result);
    imshow("OR Result", result);
    bitwise_not(image1, result);
    imshow("Nor Result", result);
    bitwise_xor(image1, image2, result);
    imshow("XOR Result", result);

    waitKey(0);

}