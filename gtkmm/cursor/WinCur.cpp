//
// Created by Oleksiy Grechnyev on 12/29/17.
//

#include <iostream>

#include <gdkmm/cursor.h>

#include "WinCur.h"

WinCur::WinCur() {
    using namespace std;
    set_title("FUN with CURSOR !!!");
//    set_border_width(5);
    set_default_size(400, 100);
//    set_size_request(400, 100);

    // GUI
    add(boxV);

    // Cursors
    pCursorNormal = Gdk::Cursor::create(Gdk::ARROW);
    pCursorWatch = Gdk::Cursor::create(Gdk::WATCH);
    pCursorFleur = Gdk::Cursor::create(Gdk::FLEUR);

    // Cursor buttons
    /// Important !!! get_window() should be called on a Gtk::Window object, not on some widget!
    /// And the window must be realized (don't call get_window() in constructor !)
    btnNormal.signal_clicked().connect([this]() -> void {
        get_window()->set_cursor(pCursorNormal);
    });
    boxV.pack_start(btnNormal);

    btnWatch.signal_clicked().connect([this]() -> void {
        get_window()->set_cursor(pCursorWatch);
    });
    boxV.pack_start(btnWatch);

    btnFleur.signal_clicked().connect([this]() -> void {
        get_window()->set_cursor(pCursorFleur);
    });
    boxV.pack_start(btnFleur);

    // Close
    btnClose.signal_clicked().connect([this]() -> void {
        hide();
    });
    boxV.pack_start(btnClose);

    btnClose.set_can_default();
    btnClose.grab_default();
    show_all_children();


}

