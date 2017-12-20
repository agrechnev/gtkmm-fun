//
// Created by Oleksiy Grechnyev on 12/19/17.
//

#pragma once

#include <gtkmm/window.h>

#include "./ImgPanel.h"

class Hello : public Gtk::Window {
public:
    Hello() {
        set_border_width(10);
        set_title("Rubber band");

        add(iPanel);
        show_all_children();
    }

private:
    ImgPanel iPanel;
};
