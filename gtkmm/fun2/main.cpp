#include <iostream>
#include <gtkmm/application.h>

#include "Fun2Win.h"

int main(int argc, char **argv){
    auto app = Gtk::Application::create(argc, argv, "org.brianna.love");

    Fun2Win hw;

    int result = app->run(hw);
    std::cout << "result = " << result << std::endl;
    return result;
}