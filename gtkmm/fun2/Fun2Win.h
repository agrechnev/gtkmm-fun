//
// Created by Oleksiy Grechnyev on 12/29/17.
//

#pragma once

#include <gtkmm/window.h>
#include <gtkmm/label.h>

class Fun2Win : public Gtk:: Window {
public:
    Fun2Win();

protected:
    Gtk::Label label{"Brianna the Gorgeous !!! \n ... again ..."};
};



