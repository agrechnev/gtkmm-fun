#include <gtkmm/application.h>
#include <gtkmm/builder.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <iostream>

/// This is the minimal gtkmm+glade example

int main(int argc, char **argv){
    auto app = Gtk::Application::create(argc, argv);
    // Load layout via builder and create objects
    auto builder = Gtk::Builder::create_from_file("fun1.glade");
    // Find the main window
    Gtk::Window * pElfWin = nullptr;
    builder->get_widget("elfWin", pElfWin);
    if (!pElfWin)
        throw std::runtime_error("Cannot find Main Window elfWin !!!");
    // Find the button and give it a callback
    Gtk::Button * pElfBtn = nullptr;
    builder->get_widget("elfBtn", pElfBtn);
    if (!pElfBtn)
        throw std::runtime_error("Cannot find Button elfBtn !!!");
    pElfBtn->signal_clicked().connect([]()->void{
        std::cout << "Elf Button clicked !" << std::endl;
    });

    // Run the app
    app->run(*pElfWin);

    return 0;
}