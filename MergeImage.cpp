#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
int main()
{

    cv::String fileLocation = "/home/kpit/opencv/samples/data/baboon.jpg";
    Mat image = imread(fileLocation, IMREAD_UNCHANGED);
    Mat channels[3];
    split(image, channels);
    Mat blue_image = channels[0];
    Mat green_image = channels[1];
    Mat red_image = channels[2];

    imshow("Blue Image", blue_image);
    imshow("Green Image", green_image);
    imshow("Red Image", red_image);

    Mat color_image_new;
    merge(std::vector<Mat>{blue_image, green_image, red_image}, color_image_new);
    imshow("Color Image", color_image_new);
    waitKey(0);
}