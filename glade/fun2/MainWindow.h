//
// Created by Oleksiy Grechnyev on 3/11/19.
//

#pragma once

#include <string>
#include <vector>

#include <gtkmm/window.h>
#include <gtkmm/builder.h>
#include <gtkmm/button.h>
#include <gtkmm/radiobutton.h>



/** @brief Main window for fun2
 *
 * Note: When using glade you don't create gtkmm objects (They are all created by Gtk::Builder)
 * and you don't inherit gtkmm classes.
 * But you can wrap objects as shown here
 *
 * Note: do not create more than 1 object of this class (any way to do this nicely ?)
 * All glade objects are managed, do not try to delete them or anything!
 *
 * I am just having fun with glade, not sure if this class is optimal!
 *
 */
class MainWindow {
public: //===== Methods
    /// Ctor
    MainWindow(const Glib::RefPtr<Gtk::Builder> &builder);

    Gtk::Window *getWindow() const {
        return window;
    }

    Gtk::Window *getWindow() {
        return window;
    }

private: //==== Fields
    Glib::RefPtr<Gtk::Builder> builder;
    /// Pointer to window object to wrap
    Gtk::Window *window = nullptr;
    /// Radio buttons
    std::vector< Gtk::RadioButton *>  radioBtns = std::vector< Gtk::RadioButton *>(3, nullptr);
};


