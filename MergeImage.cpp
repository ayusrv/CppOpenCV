#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
int main()
{

    cv::String fileLocation = "/home/kpit/opencv/samples/data/baboon.jpg";
    Mat image = imread(fileLocation, IMREAD_UNCHANGED);
    Mat channels[3];
    split(image, channels);
    Mat blue_image = imread("/home/kpit/opencv/samples/data/baboon.jpg",IMREAD_COLOR);
    Mat green_image = imread("/home/kpit/opencv/samples/data/baboon.jpg",IMREAD_COLOR);
    Mat red_image = imread("/home/kpit/opencv/samples/data/baboon.jpg",IMREAD_COLOR);

    imshow("Blue Image", blue_image);
    imshow("Green Image", green_image);
    imshow("Red Image", red_image);

    Mat color_image_new;
    merge(std::vector<Mat>{blue_image, green_image, red_image}, color_image_new);
    imshow("Color Image", color_image_new);
    waitKey(0);
}