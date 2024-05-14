#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    String fileLocation = "/home/kpit/opencv/samples/data/ayush.jpeg";

    Mat image = imread(fileLocation);
    resize(image, image, Size(500, 500), 10, 10);
    Mat result1, result2;
    std::vector<Mat> channels;
    split(image, channels);
    imshow("Before", image);
    // imshow("After", result1);

    float range[] = {0,256};
    const float* histRange = {range};
    Mat histOut;
    const int histSize = 256;
    const int histSize1 = 120;
    bool uniform = true;
    bool accumulate = false;
    Mat channelRed, channelGreen, channelBlue;
    calcHist(&channels[0], 1, nullptr, Mat(), channelRed, 1, &histSize, &histRange, uniform, accumulate);
    calcHist(&channels[1], 1, nullptr, Mat(), channelGreen, 1, &histSize, &histRange);
    calcHist(&channels[2], 1, nullptr, Mat(), channelBlue, 1, &histSize, &histRange);

    int histWidth = 512, histHeight = 400;
    int binWidth = cvRound((double)histWidth/histSize);

    Mat histImage(histHeight, histWidth, CV_8UC3, Scalar(0,0,0));

    // Normalize histograms to the height of the image
    normalize(channelRed, channelRed, 0, histImage.rows, NORM_MINMAX, -1, Mat());
    normalize(channelGreen, channelGreen, 0, histImage.rows, NORM_MINMAX, -1, Mat());
    normalize(channelBlue, channelBlue, 0, histImage.rows, NORM_MINMAX, -1, Mat());

    // Draw histograms for each channel
    for(int i=1;i<histSize;i++)
    {
        line(histImage, Point(binWidth * (i - 1), histHeight - cvRound(channelBlue.at<float>(i - 1))),
             Point(binWidth * (i), histHeight - cvRound(channelBlue.at<float>(i))),
             Scalar(255, 0, 0), 2, LINE_AA, 0);

        line(histImage, Point(binWidth * (i - 1), histHeight - cvRound(channelGreen.at<float>(i - 1))),
             Point(binWidth * (i), histHeight - cvRound(channelGreen.at<float>(i))),
             Scalar(0, 255, 0), 2, LINE_AA, 0);

        line(histImage, Point(binWidth * (i - 1), histHeight - cvRound(channelRed.at<float>(i - 1))),
             Point(binWidth * (i), histHeight - cvRound(channelRed.at<float>(i))),
             Scalar(0, 0, 255), 2, LINE_AA, 0);
    }

    equalizeHist(channels[0], channels[0]);
    equalizeHist(channels[1], channels[1]);
    equalizeHist(channels[2], channels[2]);
    merge(channels,result1);

    calcHist(&channels[0], 1, nullptr, Mat(), channelRed, 1, &histSize, &histRange, uniform, accumulate);
    calcHist(&channels[1], 1, nullptr, Mat(), channelGreen, 1, &histSize, &histRange);
    calcHist(&channels[2], 1, nullptr, Mat(), channelBlue, 1, &histSize, &histRange);

     Mat histImage2(histHeight, histWidth, CV_8UC3, Scalar(0,0,0));

    // Normalize histograms to the height of the image
    normalize(channelRed, channelRed, 0, histImage2.rows, NORM_MINMAX, -1, Mat());
    normalize(channelGreen, channelGreen, 0, histImage2.rows, NORM_MINMAX, -1, Mat());
    normalize(channelBlue, channelBlue, 0, histImage2.rows, NORM_MINMAX, -1, Mat());

    // Draw histograms for each channel
    for(int i=1;i<histSize;i++)
    {
        line(histImage2, Point(binWidth * (i - 1), histHeight - cvRound(channelBlue.at<float>(i - 1))),
             Point(binWidth * (i), histHeight - cvRound(channelBlue.at<float>(i))),
             Scalar(255, 0, 0), 2, LINE_AA, 0);

        line(histImage2, Point(binWidth * (i - 1), histHeight - cvRound(channelGreen.at<float>(i - 1))),
             Point(binWidth * (i), histHeight - cvRound(channelGreen.at<float>(i))),
             Scalar(0, 255, 0), 2, LINE_AA, 0);

        line(histImage2, Point(binWidth * (i - 1), histHeight - cvRound(channelRed.at<float>(i - 1))),
             Point(binWidth * (i), histHeight - cvRound(channelRed.at<float>(i))),
             Scalar(0, 0, 255), 2, LINE_AA, 0);
    }
    
    imshow("Original image", result1);

    imshow("Histogram image", histImage);
    imshow("Histogram image2", histImage2);

    waitKey(0);

    return 0;
}