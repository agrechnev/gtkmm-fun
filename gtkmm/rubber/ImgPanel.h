#pragma once
// By Oleksiy Grechnyev
#include <gtkmm/eventbox.h>
#include <gtkmm/image.h>
#include <gtkmm/alignment.h>

#include "./ZoomedMat.h"

class ImgPanel : public Gtk::Alignment{
public:
    ImgPanel();

private: // ==== fields
    ZoomedMat zFrame;
    Gtk::EventBox eBox;
    Gtk::Image img;

    // Coordinates for drawing the rubber band
    int x1=0, y1=0;

    bool isPressed=false; // Is the L mouse button pressed ?
};

