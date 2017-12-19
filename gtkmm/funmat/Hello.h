//
// Created by Oleksiy Grechnyev on 12/19/17.
//

#pragma once

#include <iostream>
#include <gtkmm/image.h>
#include <gtkmm/window.h>
#include <opencv2/opencv.hpp>

class Hello : public Gtk::Window {
public:
    Hello() {
//        cv::Mat frame = cv::imread("elves.jpg");
        set_border_width(10);
        set_title("OpenCV + gtkmm elves");
        cv::cvtColor(frame , frame , cv::COLOR_BGR2RGB);
        auto pb = Gdk::Pixbuf::create_from_data(
                frame.data, Gdk::COLORSPACE_RGB, frame.channels() == 4, 8,
                frame.cols, frame.rows, (int) frame.step
        );
        img.set(pb);
        add(img);
        show_all_children();
    }

protected:
    cv::Mat frame = cv::imread("elves.jpg");
    Gtk::Image img;
};