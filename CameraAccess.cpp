#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/video.hpp>
#include <opencv2/core.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat frame, blueFrame, greenFrame, redFrame, filterImage;
    VideoCapture vid;
    vid.open(0, cv::CAP_ANY);
    if (!vid.isOpened())
    {
        cerr << "Error!\n";
        return -1;
    }
    while (true)
    {
        vid.read(frame);
        // Rect r(10,10,400,400);
        // Mat nayaFrame = frame(r);
        // resize(frame, nayaFrame, Size(300,300), 10, 10);
        // imshow("New Frame", nayaFrame);
        // cvtColor(frame, filterImage, COLOR_RGB2BGR);
        // imshow("fILTER iMAGE", filterImage);
        // cv::colorChange(frame, frame, blueFrame, 1, 1, 20);
        // imshow("Blue Image", blueFrame);
        // cv::colorChange(frame, frame, redFrame, 20, 1, 1);
        // imshow("Red Image", redFrame);
        // cv::colorChange(frame, frame, greenFrame, 1, 20, 1);
        // imshow("Green Image", greenFrame);
        imshow("Frame", frame);
        int brightness = 50; // Adjust this value as needed
        frame += Scalar(brightness, brightness, brightness);
        imshow("Brightness", frame);
        // Adjust contrast by scaling pixel values
        double contrast = 0.5; // Adjust this value as needed
        frame.convertTo(frame, -1, contrast, 0);
        imshow("Contrast", frame);
        int key =cv::waitKey(5);
        if(key==27 || key==32) break;
        cout<<key<<"\n";
    }
}