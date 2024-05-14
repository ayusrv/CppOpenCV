#include <opencv4/opencv2/opencv.hpp>

int main() {
    // Read the image from file
    cv::Mat image = cv::imread("kali.jpg", cv::IMREAD_COLOR);

    // Check if the image was loaded successfully
    if (image.empty()) {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }
    // Display the image properties
    std::cout << "Image dimensions: " << image.rows << " x " << image.cols << std::endl;
    std::cout << "Number of channels: " << image.channels() << std::endl;

    // // Display pixel intensity values
    // for (int i = 0; i < image.rows; ++i) {
    //     for (int j = 0; j < image.cols; ++j) {
    //         std::cout << (int)image.at<uchar>(i, j) << " ";
    //     }
    //     std::cout << std::endl;
    // }

    //resizing the image
    cv::resize(image, image, cv::Size(600,600));
    // cv::colorChange(image, image, image, 60,60,60);

    // Display the image in a window
    cv::imshow("Image", image);

    // Wait for a keystroke in the window
    cv::waitKey(0);

    return 0;
}