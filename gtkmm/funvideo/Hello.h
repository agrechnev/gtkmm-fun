//
// Created by Oleksiy Grechnyev on 12/19/17.
//

#pragma once

#include <iostream>
#include <thread>

#include <gtkmm/image.h>
#include <gtkmm/window.h>
#include <opencv2/opencv.hpp>
#include <giomm.h>

class Hello : public Gtk::Window {
public:
    Hello() {
//        cv::Mat frame = cv::imread("elves.jpg");
        set_border_width(10);
        set_title("OpenCV + gtkmm elves");

        ///  Set dispatcher handler
        dispatcher.connect([this]()->void{
            mut.lock();
            cv::cvtColor(frame , frame , cv::COLOR_BGR2RGB);
            img.set(Gdk::Pixbuf::create_from_data(
                    frame.data, Gdk::COLORSPACE_RGB, false, 8,
                    frame.cols, frame.rows, (int) frame.step
            ));
            img.queue_draw();
            mut.unlock();
        });

        add(img);
        show_all_children();
    }

protected:
    // Video related fields
    cv::VideoCapture camera{0};
    cv::Mat frame;
    std::mutex mut; // Mutex protecting frame

    /// Video-capturing thread
    std::thread runThread{[this]()->void{
        cv::Mat tmp;
        for (;;) {
            camera >> tmp;
            mut.lock();
            frame = tmp.clone();
            mut.unlock();
//            std::cout << "EMIT !!!" << std::endl;
            dispatcher.emit();
        }
    }};

    /// The Image widget
    Gtk::Image img;

    /// The dispatcher
    Glib::Dispatcher dispatcher;
};