#pragma once

#include <iostream>

#include <gtkmm.h>

class HelloWorld : public Gtk::Window {
public: //===== Classes
    struct ModelColumn : public Gtk::TreeModel::ColumnRecord{

        Gtk::TreeModelColumn<Gtk::PositionType> posT;
        Gtk::TreeModelColumn<Glib::ustring> title;
    };

public: //====== Methods
    /// Ctor
    HelloWorld() {
        set_title("Goblin Range Controls !");
        set_default_size(300, 350);

        //scaleV
        scaleV.set_digits(1);
        scaleV.set_value_pos(Gtk::POS_TOP);
        scaleV.set_draw_value();
        scaleV.set_inverted();

        //scaleH
        scaleH.set_digits(1);
        scaleH.set_value_pos(Gtk::POS_TOP);
        scaleH.set_draw_value();

        add(boxVT);
        boxVT.pack_start(boxV2);
        boxV2.set_border_width(10);
        boxV2.pack_start(boxHS);

        // Put scaleV, scaleH side by side
        boxHS.pack_start(scaleV);
        boxHS.pack_start(boxVHS);

        boxVHS.pack_start(scaleH);

        // Scrollbar
        boxVHS.pack_start(scrollB);

        // CheckButton
        checkB.set_active();
        checkB.signal_toggled().connect(sigc::mem_fun(*this, &HelloWorld::onCheckBT));
        boxV2.pack_start(checkB, Gtk::PACK_SHRINK);

        //-----------------
        // Position combobox
        // Create tree model



        show_all_children();
    }
    
    /// Dtor
    virtual ~HelloWorld() {}
    
protected: //==== Signal handlers
    void onCheckBT(){
        scaleV.set_draw_value(checkB.get_active());
        scaleH.set_draw_value(checkB.get_active());
    }


protected: //=== Children

    Gtk::Box boxVT{Gtk::ORIENTATION_VERTICAL, 0};
    Gtk::Box boxV2{Gtk::ORIENTATION_VERTICAL, 20};
    Gtk::Box boxVHS{Gtk::ORIENTATION_VERTICAL, 10};

    Gtk::Box boxHS{Gtk::ORIENTATION_HORIZONTAL, 10};
    Gtk::Box boxHC{Gtk::ORIENTATION_HORIZONTAL, 10};
    Gtk::Box boxHD{Gtk::ORIENTATION_HORIZONTAL, 10};
    Gtk::Box boxHP{Gtk::ORIENTATION_HORIZONTAL, 10};

    Glib::RefPtr<Gtk::Adjustment> adj = Gtk::Adjustment::create(0.0, 0.0, 101.0, 0.1, 1.0, 1.0);
    Glib::RefPtr<Gtk::Adjustment> adjD = Gtk::Adjustment::create(1.0, 0.0, 5.0, 1.0, 2.0);
    Glib::RefPtr<Gtk::Adjustment> adjP = Gtk::Adjustment::create(1.0, 1.0, 101.0);

    Gtk::Scale scaleV{adj, Gtk::ORIENTATION_VERTICAL};
    Gtk::Scale scaleH{adj, Gtk::ORIENTATION_HORIZONTAL};
    Gtk::Scale scaleD{adjD};
    Gtk::Scale scaleP{adjP};

    Gtk::CheckButton checkB{"Display value on scale widgets", 0};

    Gtk::Scrollbar scrollB{adj};
    Gtk::Button butQ{"Quit"};

    Gtk::Separator separ;

protected: //==== Tree model stuff

};
