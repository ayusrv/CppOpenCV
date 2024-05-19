#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    String fileLocation = "/home/kpit/opencv/samples/data/ayush.jpeg";
    Mat image = imread(fileLocation, IMREAD_UNCHANGED);
    resize(image, image, Size(400, 400));

    Mat result_default, result_reflect, result_replicate;

    // Apply box filter with different border types
    boxFilter(image, result_default, -1, Size(5, 5), Point(-1, -1), true, BORDER_DEFAULT);
    boxFilter(image, result_reflect, -1, Size(5, 5), Point(-1, -1), true, BORDER_REFLECT);
    boxFilter(image, result_replicate, -1, Size(5, 5), Point(-1, -1), true, BORDER_REPLICATE);
    resize(result_reflect, result_reflect, Size(600, 400));

    Mat gaussianImage;
    cv::GaussianBlur(image, gaussianImage, cv::Size(11, 11), 5, 5);

    Mat medianImage;
    cv::medianBlur(image, medianImage, 5);

    Mat filterImage;
    Mat kernal = (Mat_<char>(3,3) << 1, 1, 1, 
                                     1, 2, 1, 
                                     1, 1, 1);
    cv::filter2D(image, filterImage, -1,kernal);

    // Display the results
    // imshow("Default Border", result_default);
    imshow("Default Image", image);
    imshow("Reflect Border", result_reflect);
    imshow("Gaussian Blur", gaussianImage);
    imshow("Median Blur", medianImage);
    imshow("Filter 2d", filterImage);
    // imshow("Replicate Border", result_replicate);

    // Mat result(500, 500, image.type(), Scalar(0,0,0));
    // Mat roi(result, Rect(100,100, result_reflect.cols, result_reflect.rows));
    // result_reflect.copyTo(roi);

    // add(result, image, result);
    // imshow("Image 1", image);
    // imshow("Image 2", result_reflect);
    // imshow("Image 3", result);

    waitKey(0);

    return 0;
}
