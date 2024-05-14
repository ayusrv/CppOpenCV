#include <opencv2/opencv.hpp>

int main() {
    // Read a color image from file
    cv::String fileLocation = "/home/kpit/opencv/samples/data/baboon.jpg";
    cv::Mat colorImage = cv::imread(fileLocation);

    // Check if the image was loaded successfully
    if (colorImage.empty()) {
        std::cerr << "Error: Unable to load image." << std::endl;
        return -1;
    }

    // Convert the color image to grayscale
    cv::Mat grayImage;
    cv::cvtColor(colorImage, grayImage, cv::COLOR_BGR2GRAY);

    // Convert the grayscale image back to color
    cv::Mat colorImageFromGray;
    cv::cvtColor(grayImage, colorImageFromGray, cv::COLOR_GRAY2BGR);

    // Write the grayscale and converted color images to disk
    cv::imwrite("grayscale_image.jpg", grayImage);
    cv::imwrite("color_image_from_gray.jpg", colorImageFromGray);

    std::cout << "Grayscale and color images saved successfully." << std::endl;

    return 0;
}
