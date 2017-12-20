//
// Created by Oleksiy Grechnyev on 12/20/17.
//
#include <cmath>

#include <opencv2/opencv.hpp>
#include <gdkmm/pixbuf.h>

#include "ZoomedMat.h"

//=====================================
void ZoomedMat::rescale() {
    if (1.0==scale)
        scaledImg0 = origImg.clone();  // No scaling
    else if (scale < 1.0)
        cv::resize(origImg, scaledImg0, cv::Size(), scale, scale, cv::INTER_AREA);  // Scale down
    else // Scale up (change to slower INTER_CUBIC)
        cv::resize(origImg, scaledImg0, cv::Size(), scale, scale, cv::INTER_LINEAR);  // Scale up

    // Convert scaledImg from BGR to RGB for GTK
    cv::cvtColor(scaledImg0, scaledImg0, cv::COLOR_BGR2RGB);
    scaledImg = scaledImg0.clone(); // Restore the image with no rubber
}
//=====================================
void ZoomedMat::fromFile(const std::string &fileName) {
    origImg = cv::imread(fileName);
    rescale();
}
//=====================================
void ZoomedMat::drawRubber(int x1, int y1, int x2, int y2)
{
    using namespace cv;
    scaledImg = scaledImg0.clone(); // Restore the image with no rubber

    // Make sure x,y are within the window
    auto getPoint = [this](int x, int y)->Point{
        int w = scaledImg.cols;
        int h = scaledImg.rows;
        if (x<0)
            x=0;
        if (y<0)
            y=0;
        if (x>w-1)
            x=w-1;
        if (y>h-1)
            y=h-1;
        return Point(x,y);
    };
    p1 = getPoint(x1, y1);
    p2 = getPoint(x2, y2);
    isRubber = true;
    rectangle(scaledImg, p1, p2, Scalar(255, 0, 0), 2);  // Red in RGB
}
//=====================================
void ZoomedMat::removeRubber()
{
    isRubber = false;
    scaledImg = scaledImg0.clone(); // Restore the image with no rubber
}
//=====================================
cv::Mat ZoomedMat::getSubImage()
{
    using namespace cv;
    if (!isRubber)
        return Mat(); // Empty

    // Transform point to the original image
    auto unScale = [this](const Point &p)->Point{
        int x = std::round(p.x / scale);
        int y = std::round(p.y / scale);

        int w = origImg.cols;
        int h = origImg.rows;
        if (x<0)
            x=0;
        if (y<0)
            y=0;
        if (x>w-1)
            x=w-1;
        if (y>h-1)
            y=h-1;

        return Point(x,y);
    };

    Mat region(origImg, Rect(unScale(p1), unScale(p2)));
    return region.clone();  // Clone just to be safe !
}
//=====================================
Glib::RefPtr<Gdk::Pixbuf> ZoomedMat::createPixbuf() {
    return Gdk::Pixbuf::create_from_data(
            scaledImg.data, Gdk::COLORSPACE_RGB, scaledImg.channels() == 4, 8,
            scaledImg.cols, scaledImg.rows, (int) scaledImg.step
    );
}
//=====================================
