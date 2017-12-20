//
// Created by Oleksiy Grechnyev on 12/19/17.
//

#pragma once

#include <iostream>
#include <gtkmm/image.h>
#include <gtkmm/window.h>

#include "./ZoomedMat.h"

class Hello : public Gtk::Window {
public:
    Hello() {
        set_border_width(10);
        set_title("OpenCV + gtkmm elves");
        zFrame.fromFile("elves.jpg");
        zFrame.setScale(2.5);

        img.set(zFrame.createPixbuf());
        img.queue_draw();
        add(img);
        show_all_children();
    }

protected:
    ZoomedMat zFrame;

    Gtk::Image img;
};