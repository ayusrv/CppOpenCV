#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int gammaValue = 0.0;

Mat GammaCorrectin(Mat image, int gammaVal)
{
    Mat finalImage = image.clone();
    Mat lutFilter(1, 256, CV_8U);
    uchar *ptr = lutFilter.ptr();
    for (int i = 0; i < 256; i++)
    {
        ptr[i] = saturate_cast<uchar>(pow(i / 255.0, gammaVal) * 255.0);
    }
    LUT(image, lutFilter, finalImage);
    return finalImage;
}

Mat Histography(Mat image)
{
    int histSize = 256, histHeight = 300, histWidth = 256;
    float range[] = {0, 256};
    const float *histRange[] = {range};
    Mat histImage(histHeight, histWidth, CV_8UC3, Scalar(0, 0, 0));

    if (image.channels() == 3)
    {
        vector<Mat> channels;
        split(image, channels);
        Mat b_hist, g_hist, r_hist;
        calcHist(&channels[0], 1, 0, Mat(), b_hist, 1, &histSize, histRange);
        calcHist(&channels[1], 1, 0, Mat(), g_hist, 1, &histSize, histRange);
        calcHist(&channels[2], 1, 0, Mat(), r_hist, 1, &histSize, histRange);

        normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX);
        normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX);
        normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX);

        for (int i = 1; i < 256; i++)
        {
            line(histImage, Point((i - 1), histHeight - (b_hist.at<float>(i - 1))), Point((i), histHeight - (b_hist.at<float>(i))), Scalar(255, 0, 0));

            line(histImage, Point((i - 1), histHeight - (g_hist.at<float>(i - 1))), Point((i), histHeight - (g_hist.at<float>(i))), Scalar(0, 255, 0));

            line(histImage, Point((i - 1), histHeight - (r_hist.at<float>(i - 1))), Point((i), histHeight - (r_hist.at<float>(i))), Scalar(0, 0, 255));
        }
    }
    else
    {
        Mat hist;
        calcHist(&image, 1, 0, Mat(), hist, 1, &histSize, histRange);
        normalize(hist, hist, 0, histImage.rows, NORM_MINMAX);
        for (int i = 1; i < 256; i++)
        {
            line(histImage, Point((i - 1), histHeight - (hist.at<float>(i - 1))), Point((i), histHeight - (hist.at<float>(i))), Scalar(255, 0, 0));
        }
    }
    return histImage;
}

int main()
{
    Mat frame;
    VideoCapture cap(0);
    while (true)
    {
        cap >> frame;
        imshow("Live Stream", frame);

        // Mat res = GammaCorrectin(frame, 1.5);
        // imshow("Gamma Corrected", res);

        // boxFilter(frame, frame, -1, Size(5, 5), Point(-1, -1), true, BORDER_DEFAULT);
        // imshow("FRAME", frame);

        imshow("Histogram", Histography(frame));

        // calcHist(frame, )

        if (waitKey(5) == 27)
        {
            break;
        }
    }
}