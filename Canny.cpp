#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int thresold1 = 0;
int thresold2 = 0;

int main()
{
    VideoCapture cam(0);
    cv::String fileLocation = "/home/kpit/opencv/samples/data/messi5.jpg";
    Mat srcImage;
    namedWindow("Image", WINDOW_AUTOSIZE);
    createTrackbar("Threshold1", "Image", &thresold1, 500); 
    createTrackbar("Threshold2", "Image", &thresold2, 500); 
    while (true)
    {
        cam>>srcImage;
        Mat outImage, outImage2, outImage3;
        Canny(srcImage, outImage, thresold1, thresold2);  // First value is used for edge linking, second initial segment of string edge
        // Canny(srcImage, outImage2, 80, 800); // First value is used for edge linking, second initial segment of string edge
        // Canny(srcImage, outImage3, 80, 50);  // First value is used for edge linking, second initial segment of string edge
        imshow("Source", srcImage);
        imshow("Image", outImage);
        if (waitKey(10) == 27)
        {
            break;
        }
    }
}