//
// Created by Oleksiy Grechnyev on 12/29/17.
//

#pragma once

#include <map>

#include <gtkmm.h>

class Fun2Win : public Gtk:: Window {
public:
    Fun2Win();

protected:
    Gtk::Box boxV{Gtk::ORIENTATION_VERTICAL};
    Gtk::ComboBoxText cbt;
    Gtk::Button btnClose{"Close"};

};
