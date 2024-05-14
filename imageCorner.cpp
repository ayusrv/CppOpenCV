#include <opencv2/opencv.hpp>
#include <iostream>
 
using namespace cv;
using namespace std;
 
int main()
{
    // Load the image
    Mat srcImage = imread("/home/kpit/opencv/samples/data/ayush.jpeg");
    resize(srcImage, srcImage, Size(500,500));
 
    // Check if the image was loaded successfully
    if (srcImage.empty())
    {
        cout << "Error: Failed to load the image." << endl;
        return -1;
    }
 
    // Get the size of the original image
    Size imageSize = srcImage.size();
 
    // Create a copy of the original image
    Mat blurredImage1 = srcImage.clone();
    Mat blurredImage2 = srcImage.clone();
 
    // Resize the copied images to half the size
    resize(blurredImage1, blurredImage1, Size(imageSize.width / 2, imageSize.height));
    resize(blurredImage2, blurredImage2, Size(imageSize.width / 2, imageSize.height));
 
    // Apply Gaussian blur to the resized images
    bilateralFilter(blurredImage1, blurredImage1, 15, 95, 45);
    bilateralFilter(blurredImage2, blurredImage2, 15, 95, 45);
    // boxFilter(blurredImage1, blurredImage1, -1, Size(5, 5), Point(-1, -1), true, BORDER_REPLICATE);
    // boxFilter(blurredImage2, blurredImage2, -1, Size(5, 5), Point(-1, -1), true, BORDER_REPLICATE);
 
    // Create a blank canvas to hold all three images
    Mat canvas(imageSize.height, imageSize.width + blurredImage1.cols * 2, CV_8UC3, Scalar(0, 0, 0));
 
    // Copy the blurred images to the left and right sides of the canvas
    Mat roi1(canvas, Rect(0, 0, blurredImage1.cols, blurredImage1.rows));
    blurredImage1.copyTo(roi1);
 
    Mat roi2(canvas, Rect(canvas.cols - blurredImage2.cols, 0, blurredImage2.cols, blurredImage2.rows));
    blurredImage2.copyTo(roi2);
 
    // Copy the original image to the center of the canvas
    Mat roi3(canvas, Rect(blurredImage1.cols, 0, imageSize.width, imageSize.height));
    srcImage.copyTo(roi3);
 
    // Display the canvas
    imshow("Image with Blurred Sides", canvas);
    waitKey(0);
 
    return 0;
}