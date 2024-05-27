#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
 
using namespace cv;
using namespace std;
 
int main1()
{
 
    Mat frame;
    VideoCapture cap(0);
 
    while (true)
    {
        cap >> frame;
 
        imshow("Live Stream", frame);
 
        int histSize = 256;
        float range[] = {0, 256};
        const float *histRange[] = {range};
 
        vector<Mat> channels;
        split(frame, channels);
        Mat blueHist, greenHist, redHist;
        calcHist(&channels[0], 1, 0, Mat(), blueHist, 1, &histSize, histRange);
        calcHist(&channels[1], 1, 0, Mat(), greenHist, 1, &histSize, histRange);
        calcHist(&channels[2], 1, 0, Mat(), redHist, 1, &histSize, histRange);
 
        int histHeight = 300, histWidth = 256;
        Mat histImage(histHeight, histWidth, CV_8UC3, Scalar(0, 0, 0));
 
        normalize(blueHist, blueHist, 0, histImage.rows, NORM_MINMAX);
        normalize(greenHist, greenHist, 0, histImage.rows, NORM_MINMAX);
        normalize(redHist, redHist, 0, histImage.rows, NORM_MINMAX);
 
        for (int i = 1; i < histSize; i++)
        {
            line(histImage, Point(i - 1, histHeight - blueHist.at<float>(i - 1)), Point(i, histHeight - blueHist.at<float>(i)), Scalar(255, 0, 0));
            line(histImage, Point(i - 1, histHeight - greenHist.at<float>(i - 1)), Point(i, histHeight - greenHist.at<float>(i)), Scalar(0, 255, 0));
            line(histImage, Point(i - 1, histHeight - redHist.at<float>(i - 1)), Point(i, histHeight - redHist.at<float>(i)), Scalar(0, 0, 255));
        }
 
        imshow("Histogram", histImage);
 
        if (waitKey(1) == 27)
        {
            break;
        }
    }
 
    return 0;
}
 
/*
    Random Shape generator
*/
 
int main2()
{
 
    Mat canvas(600, 1000, CV_8UC3, Scalar(0, 0, 0));
 
    RNG rng(0xFFFFFFFF);
    Size textsize = getTextSize("OpenCV forever!", FONT_HERSHEY_COMPLEX, 3, 5, 0);
    Point org(100, 300);
                                                                                                                                                
    while (true)
    {
        Mat temp = canvas.clone();
 
        for (int i = 0; i < 55; i++)
        {
            Point pt1(rng.uniform(0, 1000), rng.uniform(0, 1000));
            Point pt2(rng.uniform(0, 1000), rng.uniform(0, 1000));
            line(temp, pt1, pt2, Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256)), rng.uniform(1, 10), 8);
            // circle(temp,Point(rng.uniform(100,400),rng.uniform(100,400)),rng.uniform(100,200),Scalar(rng.uniform(0,256),rng.uniform(0,256),rng.uniform(0,256)),1);
            putText(temp, "Testing text", Point(rng.uniform(0, 500), rng.uniform(100, 600)), 1, 2.1, Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256)));
 
            putText(temp, "OpenCV forever!", org, FONT_HERSHEY_COMPLEX, 3, Scalar(i, i, 255), 5);
        }
 
        imshow("Canvas", temp);
 
        if (waitKey(500) == 27)
        {
            break;
        }
    }
 
    return 0;
}
 
// Adding and blending of images
 
const double minVal = 0.0;
const double maxVal = 1.0;
const double resolution = 0.01;
const int maxTrackbar = static_cast<int>((maxVal - minVal) / resolution);
 
// Callback function for the trackbar
void on_trackbar(int val, void *userdata)
{
    double floatVal = val * resolution + minVal;
    std::cout << "Trackbar value (float): " << floatVal << std::endl;
}
int weight1 = static_cast<int>((0.5 - minVal) / resolution);
int weight2 = static_cast<int>((0.5 - minVal) / resolution);
 
int main3()
{
 
    Mat image1 = imread("./data/ml.png");
    Mat image2 = imread("./data/opencv-logo.png");
    resize(image1, image1, Size(300, 300));
    resize(image2, image2, Size(300, 300));
 
    namedWindow("Window", WINDOW_AUTOSIZE);
    createTrackbar("Wighted Image 1", "Window", &weight1, maxTrackbar, on_trackbar);
    createTrackbar("Wighted Image 2", "Window", &weight2, maxTrackbar, on_trackbar);
 
    while (true)
    {
        Mat dstImage;
        addWeighted(image1, 0.8, image2, 0.5, 1, dstImage);
        imshow("Window", dstImage);
        if (waitKey(1) == 27)
        {
            break;
        }
    }
 
    return 0;
}
 
int main4()
{
    // Load two images
    cv::Mat img1 = cv::imread("./data/messi5.jpg");
    cv::Mat img2 = cv::imread("./data/opencv-logo-white.png");
 
    imshow("Image 1", img1);
    imshow("Image 2", img2);
 
    int rows = img2.rows;
    int cols = img2.cols;
    cv::Mat roi = img1(cv::Rect(0, 0, cols, rows));
    imshow("ROI", roi);
 
    cv::Mat img2gray;
    cv::cvtColor(img2, img2gray, cv::COLOR_BGR2GRAY);
    imshow("GreyScale of logo", img2gray);
 
    cv::Mat mask;
    cv::threshold(img2gray, mask, 10, 255, cv::THRESH_BINARY);
    imshow("Masked grayscale logo", mask);
 
    cv::Mat mask_inv;
    cv::bitwise_not(mask, mask_inv);
    imshow("Inverted Mask", mask_inv);
 
    cv::Mat img1_bg;
    cv::bitwise_and(roi, roi, img1_bg, mask_inv);
    imshow("IMG 1 Backgroud", img1_bg);
 
    // Take only region of logo from logo image
    cv::Mat img2_fg;
    cv::bitwise_and(img2, img2, img2_fg, mask);
    imshow("IMG 2 foregroung", img2_fg);
 
    // Put logo in ROI and modify the main image
    cv::Mat dst;
    cv::add(img1_bg, img2_fg, dst);
    dst.copyTo(img1(cv::Rect(0, 0, cols, rows)));
    imshow("Destination", dst);
 
    // Display the result
    cv::imshow("res", img1);
    cv::waitKey(0);
    cv::destroyAllWindows();
 
    return 0;
}
// Masking practice
 
int main5()
{
    Mat sourceImage1 = imread("./data/squirrel_cls.jpg");
    Mat sourceImage2 = imread("./data/opencv-logo-white.png");
 
    int rows = sourceImage2.rows;
    int cols = sourceImage2.cols;
    Mat roi = sourceImage1(Rect(0, 0, cols, rows));
    imshow("ROI", roi);
 
    Mat greyScaleLogo;
    cvtColor(sourceImage2, greyScaleLogo, COLOR_BGR2GRAY);
    imshow("Grey Scale logo", greyScaleLogo);
 
    Mat binaryLogo;
    threshold(greyScaleLogo, binaryLogo, 0, 255, THRESH_BINARY);
    imshow("Binary Logo", binaryLogo);
 
    Mat invertedLogo;
    bitwise_not(binaryLogo, invertedLogo);
    imshow("Inverted Logo", invertedLogo);
 
    Mat imageBg;
    bitwise_and(roi, roi, imageBg, invertedLogo);
    imshow("Bg", imageBg);
    Mat imageFg;
    bitwise_and(sourceImage2, sourceImage2, imageFg, binaryLogo);
    imshow("Fg", imageFg);
 
    Mat dst;
 
    add(imageBg, imageFg, dst);
 
    dst.copyTo(sourceImage1(Rect(0, 0, cols, rows)));
 
    imshow("SouceImage 1", sourceImage1);
 
    waitKey(0);
 
    return 0;
}
// Logo on camera
 
int main6()
{
 
    Mat frame;
    VideoCapture cap(0);
 
    while (true)
    {
 
        cap >> frame;
 
        Mat logo = imread("./nnn.png");
        resize(logo, logo, Size(500, 500));
 
        int rows = logo.rows;
        int cols = logo.cols;
 
        Mat roi = frame(Rect(0, 0, cols, rows));
 
        Mat grayScaleLogo;
        cvtColor(logo, grayScaleLogo, COLOR_BGR2GRAY);
 
        Mat binaryLogo;
        threshold(grayScaleLogo, binaryLogo, 0, 255, THRESH_BINARY);
 
        Mat invertedBinaryLogo;
        bitwise_not(binaryLogo, invertedBinaryLogo);
 
        Mat imageBg;
        bitwise_and(roi, roi, imageBg, invertedBinaryLogo);
 
        Mat imageFg;
        bitwise_and(logo, logo, imageFg, binaryLogo);
 
        Mat dst;
        add(imageBg, imageFg, dst);
        dst.copyTo(frame(Rect(0, 0, cols, rows)));
 
        imshow("Live Stream with logo", frame);
 
        if (waitKey(1) == 27)
        {
            break;
        }
    }
 
    return 0;
}
 
// Hit and miss
/*
    sourceimage ---> structuring element b1 and b2;
    find the part of image that matches b1 at the same time not matching b2
 
    three steps
 
    eroding the image with b1
    eroding the image's complement with b2
    Ending the results to show final output;
*/
 
int main()
{
    Mat input_image = (Mat_<uchar>(8, 8) << 0, 0, 0, 0, 0, 0, 0, 0,
                       0, 255, 255, 255, 0, 0, 0, 255,
                       0, 255, 255, 255, 0, 0, 0, 0,
                       0, 255, 255, 255, 0, 255, 0, 0,
                       0, 0, 255, 0, 0, 0, 0, 0,
                       0, 0, 255, 0, 0, 255, 255, 0,
                       0, 255, 0, 255, 0, 0, 255, 0,
                       0, 255, 255, 255, 0, 0, 0, 0);
 
    Mat kernel = (Mat_<int>(3, 3) << 0, 1, 0,
                  1, -1, 1,
                  0, 1, 0);
 
    Mat output_image;
    morphologyEx(input_image, output_image, MORPH_HITMISS, kernel);
 
    const int rate = 50;
    kernel = (kernel + 1) * 127;
    kernel.convertTo(kernel, CV_8U);
 
    resize(kernel, kernel, Size(), rate, rate, INTER_NEAREST);
    imshow("kernel", kernel);
    moveWindow("kernel", 0, 0);
 
    resize(input_image, input_image, Size(), rate, rate, INTER_NEAREST);
    imshow("Original", input_image);
 
    resize(output_image, output_image, Size(), rate, rate, INTER_NEAREST);
    imshow("Hit or Miss", output_image);
    // moveWindow("Hit or Miss", 500, 200);
 
    waitKey(0);
    return 0;
}
// Bilateral filter
 
int diameter = 5;
int sigmaColor = 50;
int sigmaSpace = 50;
 
 
int main8()
{
    // Read input image
    cv::Mat image = cv::imread("./data/butterfly.jpg");
 
    if (image.empty())
    {
        std::cout << "Could not open or find the image!" << std::endl;
        return -1;
    }
    namedWindow("Window", WINDOW_AUTOSIZE);
    createTrackbar("diameter", "Window", &diameter, 100);
    createTrackbar("sigmaColor", "Window", &sigmaColor, 100);
    createTrackbar("sigmaSpace", "Window", &sigmaSpace, 100);
 
    // Apply bilateral filter
    while (true)
    {
        cv::Mat filtered_image;
        cv::bilateralFilter(image, filtered_image, diameter, sigmaColor, sigmaSpace);
        cv::imshow("Window", filtered_image);
 
 
        if (waitKey(100) == 27)
        {
            break;
        }
    }
 
    return 0;
}
 
 
 
int main9(){
 
    Mat sourceImage = imread("./data/squirrel_cls.jpg");
    imshow("SourceImage",sourceImage);
    Mat logo =imread("./data/opencv-logo-white.png");
 
 
    int rows=logo.rows;
    int cols =logo.cols;
    Mat cutPortion = sourceImage(Rect(0,0,cols,rows));
 
    Mat greyScaleLogo;
    cvtColor(logo,greyScaleLogo,COLOR_BGR2GRAY);
 
 
    Mat binaryLogo;
    threshold(greyScaleLogo,binaryLogo,0,255,THRESH_BINARY);
 
 
    Mat invertedLogo;
    bitwise_not(binaryLogo,invertedLogo);
 
    Mat logoBg;
    bitwise_and(cutPortion,cutPortion,logoBg,invertedLogo);
 
 
    Mat logoFg;
    bitwise_and(logo,logo,logoFg,binaryLogo);
 
 
    Mat dst;
    add(logoBg,logoFg,dst);
 
 
    dst.copyTo(sourceImage(Rect(0,0,cols,rows)));
 
    imshow("Logoed image",sourceImage);
 
    waitKey(0);
 
    return 0;
}