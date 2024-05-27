#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


void update_map(int &ind, Mat &map_x, Mat &map_y)
{
    for (int i = 0; i < map_x.rows; i++)
    {
        for (int j = 0; j < map_x.cols; j++)
        {
            switch (ind)
            {
            case 0:
                if (j > map_x.cols * 0.25 && j < map_x.cols * 0.75 && i > map_x.rows * 0.25 && i < map_x.rows * 0.75)
                {
                    map_x.at<float>(i, j) = 2 * (j - map_x.cols * 0.25f) + 0.5f;
                    map_y.at<float>(i, j) = 2 * (i - map_x.rows * 0.25f) + 0.5f;
                }
                else
                {
                    map_x.at<float>(i, j) = 0;
                    map_y.at<float>(i, j) = 0;
                }
                break;
            case 1:
                map_x.at<float>(i, j) = (float)j;
                map_y.at<float>(i, j) = (float)(map_x.rows - i);
                break;
            case 2:
                map_x.at<float>(i, j) = (float)(map_x.cols - j);
                map_y.at<float>(i, j) = (float)i;
                break;
            case 3:
                map_x.at<float>(i, j) = (float)(map_x.cols - j);
                map_y.at<float>(i, j) = (float)(map_x.rows - i);
                break;
            default:
                break;
            } // end of switch
        }
    }
    ind = (ind + 1) % 4;
}
 
int main()
{
 
    Mat src = imread("/home/kpit/opencv/samples/data/lena.jpg", IMREAD_COLOR);
 
    Mat dst(src.size(), src.type());
    Mat map_x(src.size(), CV_32FC1);
    Mat map_y(src.size(), CV_32FC1);
 
    namedWindow("Remap demo", WINDOW_AUTOSIZE);
 
    int ind = 0;
    while (true)
    {
        update_map(ind, map_x, map_y);
        remap(src, dst, map_x, map_y, INTER_LINEAR, BORDER_REFLECT, Scalar(0, 255, 255));
 
        imshow("Remap demo", dst);
 
        if (waitKey(1000) == 27)
        {
            break;
        }
    }
    return 0;
}