#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>

#include <gtkmm.h>


class TestWindow : public Gtk::Window {
protected:
    Gtk::GLArea mGlArea;

    void onRealize() {
        std::cout << "onRealize()" << std::endl;
        
        mGlArea.make_current();

        glewExperimental=true; //GLArea only support Core profile.
        if(glewInit() != GLEW_OK) {
            std::cout << "ERROR: Failed to initialize GLEW. (Maybe the OpenGL context not exist)" << std::endl;
        }

        //This point you have the context and you can use opengl methods.
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    }

    void onUnrealize() {
        //your cleanUp. Deleting Vao etc.
    }

    bool onRender(const Glib::RefPtr<Gdk::GLContext>& context) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //here comes your rendering code
    }
public:
    TestWindow() {
        set_title("Window Title");

        add(mGlArea);
        mGlArea.set_auto_render(true);
        mGlArea.set_hexpand();
        mGlArea.set_vexpand();
        mGlArea.set_halign(Gtk::ALIGN_FILL);
        mGlArea.set_valign(Gtk::ALIGN_FILL);
        mGlArea.set_size_request(800, 600);

        mGlArea.set_required_version(3, 3); //your desired gl version
        
        mGlArea.signal_realize().connect(sigc::mem_fun(this, &TestWindow::onRealize));
        mGlArea.signal_unrealize().connect(sigc::mem_fun(this, &TestWindow::onUnrealize), false);
        mGlArea.signal_render().connect(sigc::mem_fun(this, &TestWindow::onRender));
        
        mGlArea.show();
    }
};

int main(int argc, char ** argv) {
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, 
    "org.gtkmm.examples.base");

    TestWindow mainWindow;
    
    return app->run(mainWindow);
}