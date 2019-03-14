//
// Created by Oleksiy Grechnyev on 12/29/17.
//

#include <iostream>

#include "Fun2Win.h"

Fun2Win::Fun2Win() {
    using namespace std;
    set_title("FUN : Gtk::Entry");
//    set_border_width(5);
    set_default_size(400, 100);
//    set_size_request(400, 100);

    // GUI
    add(boxV);

    // Combo box
    cbt.append("Orc");
    cbt.append("Goblin");
    cbt.remove_all();

    cbt.append("Jessica");
    cbt.append("Mira");
    cbt.append("Brianna");
    cbt.append("Lilith");
    cbt.set_active(1);
    cbt.signal_changed().connect([this]()->void{
        cout << "CHANGED :" << cbt.get_active_row_number() << endl;
    });
    boxV.pack_start(cbt, Gtk::PACK_SHRINK);

    // Close
    boxV.pack_start(btnClose);
    btnClose.signal_clicked().connect([this]()->void{
                                          hide();
                                      });
    btnClose.set_can_default();
    btnClose.grab_default();
    show_all_children();


}

