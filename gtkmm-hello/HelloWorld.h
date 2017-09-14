#pragma once

#include <iostream>

#include <gtkmm/button.h>
#include <gtkmm/window.h>

class HelloWorld : public Gtk::Window {
public:
    /// Ctor
    HelloWorld() : mButton("Handmaiden's War !") {
        set_border_width(10);
        set_title("Handmaiden's Love");
        mButton.signal_clicked().connect(sigc::mem_fun(*this, &HelloWorld::onClick));
        add(mButton);
        mButton.show();
    }
    
    /// Dtor
    virtual ~HelloWorld() {}
    
protected:

    void onClick() {
        std::cout << "Brianna The Handmaiden !!!" << std::endl;
    }
    
    Gtk::Button mButton;
};