//
// Created by Oleksiy Grechnyev on 12/20/17.
//
#include <opencv2/opencv.hpp>
#include <gdkmm/pixbuf.h>

#include "ZoomedMat.h"


void ZoomedMat::rescale() {
    if (1.0==scale)
        scaledImg = origImg.clone();  // No scaling
    else if (scale < 1.0)
        cv::resize(origImg, scaledImg, cv::Size(), scale, scale, cv::INTER_AREA);  // Scale down
    else // Scale up (change to slower INTER_CUBIC)
        cv::resize(origImg, scaledImg, cv::Size(), scale, scale, cv::INTER_LINEAR);  // Scale up

    // Convert scaledImg from BGR to RGB for GTK
    cv::cvtColor(scaledImg, scaledImg, cv::COLOR_BGR2RGB);
}

void ZoomedMat::fromFile(const std::string &fileName) {
    origImg = cv::imread(fileName);
    rescale();
}

Glib::RefPtr<Gdk::Pixbuf> ZoomedMat::createPixbuf() {
    return Gdk::Pixbuf::create_from_data(
            scaledImg.data, Gdk::COLORSPACE_RGB, scaledImg.channels() == 4, 8,
            scaledImg.cols, scaledImg.rows, (int) scaledImg.step
    );
}
