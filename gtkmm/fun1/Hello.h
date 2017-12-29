//
// Created by Oleksiy Grechnyev on 12/19/17.
//

#pragma once

#include <iostream>
#include <gtkmm/box.h>
#include <gtkmm/adjustment.h>
#include <gtkmm/scrollbar.h>
#include <gtkmm/scale.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/window.h>

class Hello : public Gtk::Window {
public:
    Hello();

protected:
// Adjustments
    Glib::RefPtr<Gtk::Adjustment> adjMain = Gtk::Adjustment::create(0., 0., 101., 0.1, 1.0, 1.0);

// Layout
// Major boxes
    Gtk::Box boxV2{Gtk::ORIENTATION_VERTICAL, 10};

//  Scales: upper panel
    Gtk::Box boxHScales{Gtk::ORIENTATION_HORIZONTAL, 10};
    Gtk::Box boxVHScale{Gtk::ORIENTATION_VERTICAL, 10};
    Gtk::Scale scaleV{adjMain, Gtk::ORIENTATION_VERTICAL};
    Gtk::Scale scaleH{adjMain, Gtk::ORIENTATION_HORIZONTAL};
    Gtk::Scrollbar scroll{adjMain};
// Check button
    Gtk::CheckButton chbu{"Display value on scale widgets", 0};
// Combo
    Gtk::Box boxHCombo{Gtk::ORIENTATION_HORIZONTAL, 10};

};
