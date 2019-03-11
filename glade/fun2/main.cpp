#include <iostream>

#include <gtkmm/application.h>
#include <gtkmm/builder.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>

#include "./MainWindow.h"

int main(int argc, char **argv){
    auto app = Gtk::Application::create(argc, argv);
    // Load layout via builder and create objects
    auto builder = Gtk::Builder::create_from_file("fun2.glade");

    MainWindow mainWindow(builder);

    // Run the app
    app->run(*mainWindow.getWindow());

    return 0;
}