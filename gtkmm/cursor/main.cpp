#include <iostream>
#include <gtkmm/application.h>

#include "WinCur.h"

int main(int argc, char **argv){
    auto app = Gtk::Application::create(argc, argv);

    WinCur hw;

    int result = app->run(hw);
    std::cout << "result = " << result << std::endl;
    return result;
}