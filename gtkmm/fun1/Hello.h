//
// Created by Oleksiy Grechnyev on 12/19/17.
//

#pragma once

#include <iostream>
#include <gtkmm/radiobutton.h>
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/separator.h>

class Hello : public Gtk::Window {
public:
    Hello() {
        set_border_width(10);
        set_title("Handmaiden's Love !!!");

        rb2.join_group(rb1);
        rb3.join_group(rb1);
        box1.pack_start(rb1);
        box1.pack_start(rb2);
        box1.pack_start(rb3);
        add(box1);

        show_all_children();
    }

protected:
    Gtk::RadioButton rb1{"Nel"};
    Gtk::RadioButton rb2{"Maria"};
    Gtk::RadioButton rb3{"Sophia"};

    Gtk::Button buClose{"Close"};

    Gtk::Box box0{Gtk::ORIENTATION_VERTICAL};
    Gtk::Box box1{Gtk::ORIENTATION_VERTICAL, 10};
    Gtk::Box box2{Gtk::ORIENTATION_VERTICAL, 10};
};