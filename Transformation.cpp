#include <iostream>
#include <opencv2/opencv.hpp>

int a = 0;
int b = 0;
int c = 0;
int d = 0;
int e = 0;
int f = 0;

void onTrack(int, void *)
{
}

int main()
{
    cv::Mat image = cv::imread("/home/kpit/opencv/samples/data/HappyFish.jpg", cv::IMREAD_GRAYSCALE);
    cv::resize(image, image, cv::Size(700, 700));

    cv::namedWindow("Window", cv::WINDOW_AUTOSIZE);
 
    cv::createTrackbar("shear x ", "Window", &a, 10, onTrack);
    cv::createTrackbar("scale and rotate x ", "Window", &b, 10, onTrack);
    cv::createTrackbar("translate x ", "Window", &c, 100, onTrack);
    cv::createTrackbar("scale and rotate y ", "Window", &d, 10, onTrack);
    cv::createTrackbar("shear y ", "Window", &e, 10, onTrack);
    cv::createTrackbar("translate y ", "Window", &f, 100, onTrack);
 

    while (true)
    {
        cv::Mat result = image.clone();

        cv::Mat M = (cv::Mat_<float>(2, 3) << a, b, c, d, e, f); // Translation by (50, 20)

        cv::warpAffine(result, result, M, result.size());

        cv::imshow("org", image);

        cv::imshow("Window", result);

        if (cv::waitKey(1) == 27)
            break;
    }

    // std::vector<cv::Point2f> src_points = {cv::Point2f(50, 50), cv::Point2f(200, 50), cv::Point2f(50, 200), cv::Point2f(200, 200)};

    // std::vector<cv::Point2f> dst_points = {cv::Point2f(0, 0), cv::Point2f(300, 0), cv::Point2f(0, 300), cv::Point2f(300, 300)};

    // // Compute the perspective transformation matrix
    // cv::Mat M = cv::getPerspectiveTransform(src_points, dst_points);

    // // Apply the perspective transformation
    // cv::Mat result;
    // cv::warpPerspective(image, result, M, cv::Size(300, 300));
    // cv::imshow("Results", result);
    // cv::waitKey(0);

    return 0;
}