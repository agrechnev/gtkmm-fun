//
// Created by Oleksiy Grechnyev on 12/19/17.
//

#pragma once

#include <iostream>
#include <gtkmm/image.h>
#include <gtkmm/fixed.h>
#include <gtkmm/alignment.h>
#include <gtkmm/window.h>
#include <gtkmm/eventbox.h>

class Hello : public Gtk::Window {
public:
    Hello() {
        set_border_width(10);
        set_title("Handmaiden's Love !!!");
        e.add(image);
        e.signal_button_press_event().connect([this](GdkEventButton* ev)->bool{
            int x,y;
            image.get_pointer(x, y);
            std::cout << "x = " << x << " y = " << y << std::endl;
            return false;
        });
        f.add(e);
        add(f);
        show_all_children();
    }

protected:
//    Gtk::Fixed f;
    Gtk::Alignment f{0.5, 0.5, 0.0, 0.0};
    Gtk::EventBox e;
    Gtk::Image image{"elves.jpg"};
};
