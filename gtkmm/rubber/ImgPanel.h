#pragma once
// By Oleksiy Grechnyev
#include <gtkmm/eventbox.h>
#include <gtkmm/image.h>

#include "./ZoomedMat.h"

class ImgPanel : public Gtk::EventBox{
public:
    ImgPanel();

private: // ==== fields
    ZoomedMat zFrame;
    Gtk::Image img;

    // Coordinates for drawing the rubber band
    int x1=0, y1=0;

    bool isPressed=false; // Is the L mouse button pressed ?
};

