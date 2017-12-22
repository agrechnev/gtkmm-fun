//
// Created by Oleksiy Grechnyev on 12/20/17.
//
#include <cmath>

#include <opencv2/opencv.hpp>
#include <gdkmm/pixbuf.h>

#include "ZoomedMat.h"

//=====================================
void ZoomedMat::rescale() {
    // All rectangles are removed upon rescale
	isRubber = false;
    regions.clear();
    regionsScaled.clear();
    if (1.0==scale)
        scaledImg0 = origImg.clone();  // No scaling
    else if (scale < 1.0)
        cv::resize(origImg, scaledImg0, cv::Size(), scale, scale, cv::INTER_AREA);  // Scale down
    else // Scale up (change to slower INTER_CUBIC)
        cv::resize(origImg, scaledImg0, cv::Size(), scale, scale, cv::INTER_LINEAR);  // Scale up

    // Convert scaledImg from BGR to RGB for GTK
    cv::cvtColor(scaledImg0, scaledImg0, cv::COLOR_BGR2RGB);
    // Create scaledImg from scaledImg0
    drawRects();
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

    // Create points with edges check
    p1 = checkEdges(Point(x1, y1), scaledImg);
    p2 = checkEdges(Point(x2, y2), scaledImg);
    isRubber = true;
    // The actual rectangle is now drawn in drawRects()
    drawRects();
}
//=====================================
void ZoomedMat::removeRubber()
{
    isRubber = false;
    drawRects();
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

        return checkEdges(Point(x,y), origImg);
    };

    Mat region(origImg, Rect(unScale(p1), unScale(p2)));
    return region.clone();  // Clone just to be safe !
}
//=====================================
void ZoomedMat::setRegions(const std::vector<cv::Rect> &regions)
{
    using namespace cv;
    ZoomedMat::regions = regions;
    // Create scaled version of all rectangles
    regionsScaled.clear();
    regionsScaled.reserve(regions.size());
    for (const Rect & r : regions) {
        Point p1 = r.tl();  // 2 corners
        Point p2 = r.br();
        p1 = checkEdges(p1*scale, scaledImg);
        p2 = checkEdges(p2*scale, scaledImg);
        regionsScaled.emplace_back(p1, p2);
    }
    // Now draw them !
    drawRects();
}
//=====================================
void ZoomedMat::drawRects(){
    using namespace cv;
    scaledImg = scaledImg0.clone(); // Restore the image with no rubber
    // Draw the rubber band (red)
    if (isRubber)
        rectangle(scaledImg, p1, p2, Scalar(255, 0, 0), 2);  // Red in RGB
    // Draw the rectangles (blue)
    for (const Rect & r : regionsScaled)
        rectangle(scaledImg, r, Scalar(0, 0, 255), 2);  // Blue in RGB
}
//=====================================
cv::Point ZoomedMat::checkEdges(const cv::Point &p, const cv::Mat &m){
    int w = m.cols;
    int h = m.rows;
    int x = p.x;
    int y = p.y;
    if (x<0)
        x=0;
    if (y<0)
        y=0;
    if (x>w-1)
        x=w-1;
    if (y>h-1)
        y=h-1;

    return cv::Point(x,y);
}
//=====================================
Glib::RefPtr<Gdk::Pixbuf> ZoomedMat::createPixbuf() {
    return Gdk::Pixbuf::create_from_data(
                scaledImg.data, Gdk::COLORSPACE_RGB, scaledImg.channels() == 4, 8,
            scaledImg.cols, scaledImg.rows, (int) scaledImg.step
    );
}
//=====================================
