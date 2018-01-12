//
// Created by Oleksiy Grechnyev on 12/29/17.
//

#include <iostream>

#include "Fun2Win.h"

Fun2Win::Fun2Win() {
    set_title("FUN : Gtk::Entry");
//    set_border_width(5);
//    set_default_size(400, 100);
    set_size_request(400, 100);

    // GUI
    add(boxV);

    // Entry
    ent.set_max_length(40);
    ent.set_text("Goblins WON !!!");
    boxV.pack_start(ent, Gtk::PACK_SHRINK);

    ent.set_icon_from_icon_name("edit-find");
    ent.signal_icon_press().connect([this](Gtk::EntryIconPosition /* icon_pos */,
                                    const GdkEventButton* /* event */)->void{
        std::cout << "Icon pressed !!!" << std::endl;
    });

    // Close
    boxV.pack_start(btnClose);
    btnClose.signal_clicked().connect([this]()->void{
                                          hide();
                                      });
    btnClose.set_can_default();
    btnClose.grab_default();
    show_all_children();


}

