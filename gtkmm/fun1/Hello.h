//
// Created by Oleksiy Grechnyev on 12/19/17.
//

#pragma once

#include <iostream>
#include <gtkmm/box.h>
#include <gtkmm/adjustment.h>
#include <gtkmm/scrollbar.h>
#include <gtkmm/scale.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/window.h>
#include <gtkmm/treemodel.h>
#include <gtkmm/combobox.h>
#include <gtkmm/liststore.h>
#include <gtkmm/separator.h>

class Hello : public Gtk::Window {
protected:
    struct ModelColumns : public Gtk::TreeModel::ColumnRecord{
        ModelColumns(){
            add(posType);
            add(colTitle);
        }

        Gtk::TreeModelColumn<Gtk::PositionType> posType;
        Gtk::TreeModelColumn<Glib::ustring> colTitle;
    };


public:
    Hello();

protected:


// Layout
// Major boxes
    Gtk::Box boxV1{Gtk::ORIENTATION_VERTICAL, 10};
    Gtk::Box boxV2{Gtk::ORIENTATION_VERTICAL, 10};
    Gtk::Separator sep;
    Gtk::Button btnQuit{"Quit"};

//  Scales: upper panel
    Glib::RefPtr<Gtk::Adjustment> adjMain = Gtk::Adjustment::create(0., 0., 101., 0.1, 1.0, 1.0);
    Gtk::Box boxHScales{Gtk::ORIENTATION_HORIZONTAL, 10};
    Gtk::Box boxVHScale{Gtk::ORIENTATION_VERTICAL, 10};
    Gtk::Scale scaleV{adjMain, Gtk::ORIENTATION_VERTICAL};
    Gtk::Scale scaleH{adjMain, Gtk::ORIENTATION_HORIZONTAL};
    Gtk::Scrollbar scroll{adjMain};

// Check button
    Gtk::CheckButton chbu{"Display value on scale widgets", 0};

// Combo
    Gtk::Box boxHCombo{Gtk::ORIENTATION_HORIZONTAL, 10};
    ModelColumns modCol;
    Gtk::ComboBox comboPos;
    Glib::RefPtr<Gtk::ListStore> treeMod = Gtk::ListStore::create(modCol);

// Digits
    Gtk::Box boxHDig{Gtk::ORIENTATION_HORIZONTAL, 10};
    Glib::RefPtr<Gtk::Adjustment> adjDig = Gtk::Adjustment::create(1.0, 0.0, 5.0, 1.0, 2.0);
    Gtk::Scale scaleDig{adjDig};

// Page size
    Gtk::Box boxHPag{Gtk::ORIENTATION_HORIZONTAL, 10};
    Glib::RefPtr<Gtk::Adjustment> adjPag = Gtk::Adjustment::create(1.0, 1.0, 101.0);
    Gtk::Scale scalePag{adjPag};
};
