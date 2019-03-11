//
// Created by Oleksiy Grechnyev on 3/11/19.
//

#include <iostream>

#include "./MainWindow.h"

MainWindow::MainWindow(const Glib::RefPtr<Gtk::Builder> &builder) :
        builder(builder) {
    using namespace std;

    // Find the main window
    builder->get_widget("elfWin", window);
    if (!window)
        throw runtime_error("Cannot find Main Window elfWin !!!");

    // Set up radio buttons
    for (int i = 0; i < 3; ++i) {
        string id = "elfRB" + to_string(i + 1);
        builder->get_widget(id, radioBtns[i]);
        if (!radioBtns[i])
            throw runtime_error("Cannot find Radio Button " + id + " !!!");
    }

    // Find the button and give it a callback
    Gtk::Button *pElfBtn = nullptr;
    builder->get_widget("elfBtn", pElfBtn);
    if (!pElfBtn)
        throw std::runtime_error("Cannot find Button elfBtn !!!");
    pElfBtn->signal_clicked().connect([this]() -> void {
        for (int i = 0; i < 3; ++i) {
            if (radioBtns[i]->get_active()) {
                cout << "Active radio button : " << i + 1 << endl;
                break;
            }
        }
    });
}
