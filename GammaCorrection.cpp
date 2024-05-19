#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/video.hpp>
#include <opencv2/core.hpp>

using namespace cv;

int brightnessValueRed = 0.0;
int brightnessValueBlue = 0.0;
int brightnessValueGreen = 0.0;
int gammaValue = 0.0;

void onTrackBar(int, void *) {}

Mat GammaCorrection(Mat image)
{
    Mat temp = image.clone();
    Mat lutFilter(1, 256, CV_8U);
    uchar *ptr = lutFilter.ptr();
    for (int i = 0; i < 256; i++)
    {
        ptr[i] = saturate_cast<uchar>(std::pow(i / 255.0, gammaValue)) * 255.0;
    }
    LUT(image, lutFilter, temp);
    return temp;
}

Mat HistoGramImage(Mat image)
{
    Mat finalImage = image.clone();
    int histSize = 256;
    float range[] = {0, 256};
    const float *histRange[] = {range};
    int histWidth = 256, histHeight = 400;
    if (finalImage.channels() < 3)
    {
        Mat hist;
        calcHist(&finalImage, 1, nullptr, Mat(), hist, 1, &histSize, histRange);
        Mat histImage(histHeight, histWidth, CV_8U, Scalar(0, 0, 0));
        normalize(histImage, histImage, 1, NORM_MINMAX);
        for (int i = 1; i < 256; i++)
        {
            line(histImage, Point((i - 1), histHeight - (hist.at<float>(i - 1))), Point((i)-histHeight - (hist.at<float>(i))), Scalar(255, 255, 255));
        }
        return histImage;
    }
    else
    {
    }
    return finalImage;
}

int main()
{
    VideoCapture vid;
    vid.open(0, cv::CAP_ANY);
    if (!vid.isOpened())
    {
        std::cerr << "Error!\n";
        return -1;
    }
    // String fileLocation = "/home/kpit/opencv/samples/data/pic2.png";
    Mat image;

    // Check if image was loaded successfully
    // if (image.empty())
    // {
    //     std::cerr << "Error: Unable to load image from file." << std::endl;
    //     return -1;
    // }

    namedWindow("Before", WINDOW_AUTOSIZE);

    // Gamma Correction
    //  for(int i=0;i<image.rows;i++)
    //  {
    //      for(int j=0;j<image.cols;j++){
    //          Vec3b& channels = image.at<Vec3b>(i,j);
    //          channels[0] = saturate_cast<uchar>(std::pow(image.at<Vec3b>(i,j)[0]/255.0, 0.8)*255.0);
    //          channels[1] = saturate_cast<uchar>(std::pow(image.at<Vec3b>(i,j)[1]/255.0, 1.4)*255.0);
    //          channels[2] = saturate_cast<uchar>(std::pow(image.at<Vec3b>(i,j)[2]/255.0, 0.8)*255.0);
    //      }
    //  }

    createTrackbar("BrightnessRed", "Before", &brightnessValueRed, 150, onTrackBar);
    createTrackbar("BrightnessBlue", "Before", &brightnessValueBlue, 150, onTrackBar);
    createTrackbar("BrightnessGreen", "Before", &brightnessValueGreen, 150, onTrackBar);
    createTrackbar("Gamma Factor", "Before", &gammaValue, 20, onTrackBar);

    // Look UP Table

    while (true)
    {
        vid.read(image);
        Mat res = image.clone();
        for (int i = 0; i < res.rows; i++)
        {
            for (int j = 0; j < res.cols; j++)
            {
                cv::Vec3b &channel = res.at<cv::Vec3b>(i, j);
                res.at<cv::Vec3b>(i, j)[0] = cv::saturate_cast<uchar>(res.at<cv::Vec3b>(i, j)[0] + brightnessValueBlue);
                res.at<cv::Vec3b>(i, j)[1] = cv::saturate_cast<uchar>(brightnessValueGreen + res.at<cv::Vec3b>(i, j)[1]);
                res.at<cv::Vec3b>(i, j)[2] = cv::saturate_cast<uchar>(brightnessValueRed + res.at<cv::Vec3b>(i, j)[2]);
            }
        }
        res = GammaCorrection(res);

        imshow("Before", res);
        if (waitKey(5) == 27)
        {
            break;
        }
    }
}