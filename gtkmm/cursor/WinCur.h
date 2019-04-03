//
// Created by Oleksiy Grechnyev on 12/29/17.
//

#pragma once

#include <map>

#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/box.h>

class WinCur : public Gtk:: Window {
public:
    WinCur();

protected:
    Gtk::Box boxV{Gtk::ORIENTATION_VERTICAL};

    Gtk::Button btnNormal{"Normal"};
    Gtk::Button btnWatch{"Watch"};
    Gtk::Button btnFleur{"Fleur"};

    Gtk::Button btnClose{"Close"};

    Glib::RefPtr<Gdk::Cursor> pCursorWatch;
    Glib::RefPtr<Gdk::Cursor> pCursorNormal;
    Glib::RefPtr<Gdk::Cursor> pCursorFleur;

};
