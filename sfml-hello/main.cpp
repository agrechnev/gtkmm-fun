#include <SFML/Graphics.hpp>

int main(){
    using namespace sf;
    
    RenderWindow w(VideoMode(200, 200), "Goblin SFML !!!");
    CircleShape shape(100.f);
    shape.setFillColor(Color::Yellow);
    
    while (w.isOpen()) {
        Event e;
        while (w.pollEvent(e))
            if (e.type == Event::Closed)
                w.close();
            
        w.clear();
        w.draw(shape);
        w.display();
    }
    
    return 0;
}