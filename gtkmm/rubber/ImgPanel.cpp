#include <iostream>

#include <opencv2/opencv.hpp>

#include "ImgPanel.h"

ImgPanel::ImgPanel(){
    using namespace std;
    zFrame.fromFile("elves.jpg");
    zFrame.setScale(2.5);

    img.set(zFrame.createPixbuf());
    img.queue_draw();

    //    cout << "has_window() = " << get_has_window() << endl;

    //    set_events(Gdk::ALL_EVENTS_MASK);
    signal_button_press_event().connect([this](GdkEventButton* e)->bool{
        if (e->button != 1)  // Only lelf button
            return false;
        isPressed = true;
        img.get_pointer(x1, y1);
        zFrame.removeRubber();  // Remove any rubber
        img.set(zFrame.createPixbuf());
        return true;  // No more propagation !
    });

    signal_motion_notify_event().connect([this](GdkEventMotion* e)->bool{
        if (!isPressed)
            return false;  // Do nothing
        int x2,y2;
        img.get_pointer(x2, y2);
        if (x1!=x2 || y1!=y2) {
            zFrame.drawRubber(x1, y1, x2, y2);
            img.set(zFrame.createPixbuf());
        }
        return true;
    });

    signal_button_release_event().connect([this](GdkEventButton* e)->bool{
        if (e->button != 1)  // Only lelf button
            return false;
        isPressed = false;
        int x2,y2;
        img.get_pointer(x2, y2);
        if (x1!=x2 || y1!=y2) {
            zFrame.drawRubber(x1, y1, x2, y2);
            img.set(zFrame.createPixbuf());
            // Get subimage defined by the rubber
            cv::Mat m = zFrame.getSubImage();
            if (m.data) {
                // Not very good within gtkmm, but a quick solution
                cv::imshow("subImage", m);
                cv::waitKey(0);
            }
        } else { // A click with no drag removes the rubber
            zFrame.removeRubber();  // Remove any rubber
            img.set(zFrame.createPixbuf());
        }
        return true;  // No more propagation !
    });

    add(img);
    show_all_children();
}
