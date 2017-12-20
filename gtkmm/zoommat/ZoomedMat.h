//
// Created by Oleksiy Grechnyev on 12/20/17.
//

#pragma once

#include <opencv2/core.hpp>
#include <gdkmm/window.h>

/** @brief OpenCV Mat original and scaled version
 *
 */
class ZoomedMat {
public: //=========== Methods ================
    /// Generate scaledImg using current scale
    void rescale();

    /// Get a Pixbuf  from scaledImg (not valid after each rescale !)
    Glib::RefPtr<Gdk::Pixbuf> createPixbuf();

    /// Load origImg from file
    void fromFile(const std::string & fileName);

    const cv::Mat &getOrigImg() const {
        return origImg;
    }

    void setOrigImg(const cv::Mat &origImg) {
        ZoomedMat::origImg = origImg;
        rescale();
    }

    const cv::Mat &getScaledImg() const {
        return scaledImg;
    }


    double getScale() const {
        return scale;
    }

    void setScale(double scale) {
        ZoomedMat::scale = scale;
        rescale();
    }

private:  //========== Fields ================
    /// The original image (in BGR)
    cv::Mat origImg;

    /// The scaled image (in RGB)
    cv::Mat scaledImg;

    /// The scale
    double scale = 1.0;
};



