#include <opencv2/opencv.hpp>
#include <iostream>

int blurValue = 9;

int main()
{
    cv::VideoCapture cap(0);
 
    cv::namedWindow("WebCam", cv::WINDOW_AUTOSIZE);
 
    cv::createTrackbar("Blur", "WebCam", &blurValue, 100);
    
    while(true)
    {
        cv::Mat img;
        cap >> img;
        cv::flip(img, img, 1);
 
        int ksize;
        if(blurValue%2==0)
        {
            blurValue += 1;
        }
        ksize = blurValue;
 
        // cv::medianBlur(img, img, ksize);
        cv::GaussianBlur(img, img, cv::Size(ksize, ksize), 10, 10);
 
        cv::resize(img, img, cv::Size(1000, 800));
        cv::imshow("WebCam", img);
        char key = cv::waitKey(30);
        if (key == 27){
            break;
        }
    }
 
    return 0;
}