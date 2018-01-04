//
// Created by Oleksiy Grechnyev on 12/29/17.
//

#pragma once

#include <map>

#include <gtkmm.h>

class Fun2Win : public Gtk:: Window {
public:
    Fun2Win();

protected:
    // Tree model
    struct ModelColumns : public Gtk::TreeModel::ColumnRecord{
        ModelColumns(){
            add(id);
            add(name);
        }

        Gtk::TreeModelColumn<unsigned> id;
        Gtk::TreeModelColumn<Glib::ustring> name;
    };

    using TypeActionMap = std::map<int, Glib::ustring>;

    ModelColumns mCols;
    TypeActionMap cmplActions{{0, "Use Wizard"}, {1, "Browse for filename"}};

    // Gui
    Gtk::Box boxV{Gtk::ORIENTATION_VERTICAL};

    Gtk::Entry ent;
    Gtk::Label lbl;

    Gtk::Button btnClose{"Close"};

protected: //========Methods
    bool onMatch(const Glib::ustring & key, const Gtk::TreeModel::const_iterator & iter);
};
