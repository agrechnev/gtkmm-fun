//
// Created by Oleksiy Grechnyev on 12/19/17.
//

#pragma once

#include <iostream>
#include <gtkmm/image.h>
#include <gtkmm/window.h>

class Hello : public Gtk::Window {
public:
    Hello() {
        set_border_width(10);
        set_title("Handmaiden's Love !!!");
        add(img);
        img.show();
    }

protected:
//    Gtk::Image img{"elves.jpg"};
    Gtk::Image img{Gdk::Pixbuf::create_from_file("elves.jpg")};
};