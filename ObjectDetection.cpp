#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;

int main()
{
    // load source image and grayscale template
    cv::String fileLocation1 = "/home/kpit/opencv/samples/data/messi5.jpg";
    cv::String fileLocation2 = "/home/kpit/opencv/samples/data/messiface.jpg";

    Mat image = imread(fileLocation1);
    Mat templ = imread(fileLocation2, IMREAD_GRAYSCALE);

    // create grayscale image
    Mat grayImage;
    cvtColor(image, grayImage, COLOR_RGB2GRAY);

    // create variable for location, scale and rotation of detected templates
    vector<Vec4f> positionBallard, positionGuil;

    // template width and height
    int w = templ.cols;
    int h = templ.rows;

    // create ballard and set options

    //This function creates an instance of the GeneralizedHoughBallard class, which is used for detecting shapes using the Ballard GHT method.
    Ptr<GeneralizedHoughBallard> ballard = createGeneralizedHoughBallard();

    // If multiple shapes are detected close to each other, this parameter ensures that they are considered separate detections only if they are at least 10 pixels apart.
    ballard->setMinDist(10);

    //More levels allow finer granularity in the detection of shapes, potentially increasing accuracy but also increasing computation time.
    ballard->setLevels(360);

    //If dp=2, the accumulator resolution is half of the image resolution. A higher dp value reduces the resolution of the accumulator, which can speed up processing but may reduce accuracy.
    ballard->setDp(2);

    //A larger buffer size can handle more intermediate results, which might be useful for images with many potential shapes to detect.
    ballard->setMaxBufferSize(1000);

    //Only shapes with votes equal to or greater than this threshold will be considered as valid detections. A higher threshold reduces false positives but might miss some valid shapes.
    ballard->setVotesThreshold(40);

    // If the threshold value sis less than the provided it will ignore that edge
    ballard->setCannyLowThresh(30);

    //It will make sure those value whose threshold is greater than passed it will be counted as strong edges
    ballard->setCannyHighThresh(110);

    //This will set the template that I want to search
    ballard->setTemplate(templ);

    // create guil and set options
    Ptr<GeneralizedHoughGuil> guil = createGeneralizedHoughGuil();
    guil->setMinDist(10);
    guil->setLevels(360);
    guil->setDp(3);
    guil->setMaxBufferSize(1000);

    guil->setMinAngle(0);
    guil->setMaxAngle(360);
    guil->setAngleStep(1);
    guil->setAngleThresh(1500);

    guil->setMinScale(0.5);
    guil->setMaxScale(2.0);
    guil->setScaleStep(0.05);
    guil->setScaleThresh(50);

    guil->setPosThresh(10);

    guil->setCannyLowThresh(30);
    guil->setCannyHighThresh(110);

    guil->setTemplate(templ);

    // execute ballard detection
    ballard->detect(grayImage, positionBallard);
    // execute guil detection
    guil->detect(grayImage, positionGuil);

    // draw ballard
    for (vector<Vec4f>::iterator iter = positionBallard.begin(); iter != positionBallard.end(); ++iter)
    {
        RotatedRect rRect = RotatedRect(Point2f((*iter)[0], (*iter)[1]),
                                        Size2f(w * (*iter)[2], h * (*iter)[2]),
                                        (*iter)[3]);
        Point2f vertices[4];
        rRect.points(vertices);
        for (int i = 0; i < 4; i++)
            line(image, vertices[i], vertices[(i + 1) % 4], Scalar(255, 0, 0), 6);
    }

    // draw guil
    for (vector<Vec4f>::iterator iter = positionGuil.begin(); iter != positionGuil.end(); ++iter)
    {
        RotatedRect rRect = RotatedRect(Point2f((*iter)[0], (*iter)[1]),
                                        Size2f(w * (*iter)[2], h * (*iter)[2]),
                                        (*iter)[3]);
        Point2f vertices[4];
        rRect.points(vertices);
        for (int i = 0; i < 4; i++)
            line(image, vertices[i], vertices[(i + 1) % 4], Scalar(0, 255, 0), 2);
    }

    imshow("result_img", image);
    waitKey();

    return EXIT_SUCCESS;
}