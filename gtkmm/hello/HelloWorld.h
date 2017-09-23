#pragma once

#include <iostream>

#include <gtkmm/button.h>
#include <gtkmm/window.h>

class HelloWorld : public Gtk::Window {
public:
    /// Ctor
    HelloWorld() {
        set_border_width(10);
        set_title("Handmaiden's Love");

        mButton1.signal_clicked().connect(sigc::mem_fun(*this, &HelloWorld::onClick1));
        add(mButton1);
        mButton1.show();
    }
    
    /// Dtor
    virtual ~HelloWorld() {}
    
protected:

    void onClick1() {
        std::cout << "Brianna The Handmaiden !!!" << std::endl;
    }
    
    Gtk::Button mButton1{"Handmaiden's War !"};
};
