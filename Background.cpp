#include <opencv2/opencv.hpp>

int main() {
    // Create a white image
    cv::Mat image(300, 400, CV_8UC3, cv::Scalar(127, 0, 255)); // 300x400 white image

    // Define the rectangle parameters
    cv::Point pt1(100, 100); // Top-left corner
    cv::Point pt2(300, 200); // Bottom-right corner
    cv::Scalar color(255, 0, 0); // Blue color
    int thickness = -1; // Fill the rectangle

    // Draw the rectangle on the image
    cv::rectangle(image, pt1, pt2, color, thickness);

    // Display the image
    cv::imshow("Generated Image", image);
    cv::waitKey(0);

    return 0;
}
