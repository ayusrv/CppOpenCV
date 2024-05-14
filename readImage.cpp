#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{

    cv::String fileLocation = "/home/kpit/opencv/samples/data/apple.jpg";
    cv::Mat image = cv::imread(fileLocation, cv::IMREAD_UNCHANGED);
    if (image.empty())
    {
        std::cerr << "Image file not path or image is invalid\n";
        return -1;
    }

    // Setting window name
    // cv::String windowName = "LenaImage";

    // // Displaing the image
    // cv::imshow(windowName, image);

    // // Resizing the image to 500x500
    // cv::resize(image, image, cv::Size(500, 500));

    // // Changing the color to Grey
    // cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
    // // std::cout<<"Image is: "<<image;
    // // cv::imshow("New Window", image);

    cv::Mat bilateralImage, gaussianImage;

    // // Creating the bilateralFilter to blur the image
    // cv::bilateralFilter(image, bilateralImage, 15, 95, 45);

    // // Creating the Gaussin Blur
    cv::GaussianBlur(image, gaussianImage, cv::Size(11, 11), 5, 5);

    // cv::imshow("BIlateral Image", bilateralImage);
    cv::imshow("Image", image);
    cv::imshow("Gaussian Image", gaussianImage);

    // cv::imwrite("output_image.jpg", image);

    // for (int i = 0; i < image.rows; i++)
    // {
    //     for (int j = 0; j < image.cols; j++)
    //     {
    //         cv::Vec3b &colorPixel = image.at<cv::Vec3b>(i, j);
    //         float avg = (colorPixel[0] + colorPixel[1] + colorPixel[2]) / 3;
    //         if (avg > 127.5)
    //         {
    //             colorPixel[0] = 255;
    //             colorPixel[1] = 255;
    //             colorPixel[2] = 255;
    //         }
    //         else
    //         {
    //             colorPixel[0] = 0;
    //             colorPixel[1] = 0;
    //             colorPixel[2] = 0;
    //         }
    //     }
    // }

    // cv::Mat grayImage;
    // cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
    // cv::imshow("Before bright", grayImage);
    // for (int i = 0; i < image.rows; i++)
    // {
    //     for (int j = 0; j < image.cols; j++)
    //     {
    //         uchar intensity = grayImage.at<uchar>(i, j);
    //         grayImage.at<uchar>(i, j) =cv::saturate_cast<uchar>(50+ grayImage.at<uchar>(i, j)*1.5);
    //     }
    // }

    // for(int i=0;i<image.rows;i++){
    //     for(int j=0;j<image.cols;j++){
    //         cv::Vec3b& channel = image.at<cv::Vec3b>(i,j);
    //         channel[0] = cv::saturate_cast<uchar>(50+channel[0]*1.5);
    //         channel[1] = cv::saturate_cast<uchar>(50+channel[1]*1.5);
    //         channel[2] = cv::saturate_cast<uchar>(50+channel[2]*1.5);
    //     }
    // }

    // cv::imshow("new image", image);
    // cv::imshow("Bright image", grayImage);

    cv::waitKey(0);
    return 0;
}