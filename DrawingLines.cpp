#include <opencv2/opencv.hpp>
using namespace cv;

int main() {
    // Create a black image
    Mat img = Mat::zeros(800, 1800, CV_8UC3);

    // Define color (BGR format) and thickness
    Scalar color(0, 255, 0); // Green color
    int thickness = 2;

    // K Printing
    Point k_start1(50, 50);
    Point k_end1(50, 750);
    line(img, k_start1, k_end1, color, thickness);

    Point k_start2(50, 400);
    Point k_end2(400, 50);
    line(img, k_start2, k_end2, color, thickness);

    Point k_start3(50, 400);
    Point k_end3(400, 750);
    line(img, k_start3, k_end3, color, thickness);

    // P Printing
    Point p_start1(450, 50);
    Point p_end1(450, 750);
    line(img, p_start1, p_end1, color, thickness);

    Point p_start2(450, 50);
    Point p_end2(850, 50);
    line(img, p_start2, p_end2, color, thickness);

    Point p_start3(850, 50);
    Point p_end3(850, 400);
    line(img, p_start3, p_end3, color, thickness);

    Point p_start4(850, 400);
    Point p_end4(450, 400);
    line(img, p_start4, p_end4, color, thickness);

    // I Printing
    Point i_start1(900, 50);
    Point i_end1(900, 750);
    line(img, i_start1, i_end1, color, thickness);

    // T Printing
    Point t_start1(1000, 50);
    Point t_end1(1400, 50);
    line(img, t_start1, t_end1, color, thickness);

    Point t_start2(1200, 50);
    Point t_end2(1200, 750);
    line(img, t_start2, t_end2, color, thickness);

    // Display the image with multiple lines
    imshow("KPIT", img);
    waitKey(0);
    return 0;
}
