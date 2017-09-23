#include <iostream>

#include <gtkmm/application.h>

#include "./HelloWorld.h"

int main(int argc, char** argv)
{
        auto app = Gtk::Application::create(argc, argv, "org.brianna.love");
        
        HelloWorld hw;
        
        int result = app->run(hw);

        std::cout << "result = " << result << std::endl;

        return result;
}
