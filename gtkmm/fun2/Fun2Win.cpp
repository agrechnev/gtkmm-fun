//
// Created by Oleksiy Grechnyev on 12/29/17.
//

#include <iostream>

#include "Fun2Win.h"

Fun2Win::Fun2Win() {
    set_title("FUN : Gtk::Entry");
//    set_border_width(5);
//    set_default_size(400, 100);

    // GUI
    add(boxV);
    boxV.pack_start(ent, Gtk::PACK_SHRINK);
    boxV.pack_start(lbl, Gtk::PACK_EXPAND_WIDGET);

    // Close
    boxV.pack_start(btnClose);
    btnClose.signal_clicked().connect([this]()->void{
                                          hide();
                                      });
    btnClose.set_can_default();
    btnClose.grab_default();
    show_all_children();

    // Model
    Glib::RefPtr<Gtk::EntryCompletion> cmpl = Gtk::EntryCompletion::create();
    ent.set_completion(cmpl);
    auto cmplModel = Gtk::ListStore::create(mCols);
    cmpl->set_model(cmplModel);

    cmpl->set_match_func(sigc::mem_fun(*this, &Fun2Win::onMatch));

    // Fill the model
    Gtk::TreeModel::Row row;
    row = *(cmplModel->append());
    row[mCols.id] = 1;
    row[mCols.name] = "Alan Zebedee";

    row = *(cmplModel->append());
    row[mCols.id] = 2;
    row[mCols.name] = "Adrian Boo";

    row = *(cmplModel->append());
    row[mCols.id] = 3;
    row[mCols.name] = "Bob McRoberts";

    row = *(cmplModel->append());
    row[mCols.id] = 4;
    row[mCols.name] = "Bob McBob";

    cmpl->set_text_column(mCols.name);

    // Add extra choices, it seems
    for (const auto & p: cmplActions) {
        cmpl->insert_action_text(p.second, p.first);
    }

    cmpl->signal_action_activated().connect([](int i)->void{
        std::cout << "signal_action_activated index = " << i << std::endl;
    });

    cmpl->signal_insert_prefix().connect([](const Glib::ustring& prefix)->bool{
        std::cout << "signal_insert_prefix prefix = " << prefix << std::endl;
        return false;
    }, false);

    cmpl->signal_match_selected().connect([this](const Gtk::TreeModel::iterator& iter)->bool{
        const Gtk::TreeModel::Row & row = *iter;
        std::cout << "signal_match_selected name = " << row[mCols.name] << std::endl;
        return false;
    }, false);


}

bool Fun2Win::onMatch(const Glib::ustring &key, const Gtk::TreeModel::const_iterator &iter){
    std::cout << " onMatch()  " << key << std::endl;

    if (iter) {
        Gtk::TreeModel::Row row = *iter;
        Glib::ustring::size_type keySize = key.size();
        Glib::ustring filterStr = row[mCols.name];
        Glib::ustring fSStart = filterStr.substr(0, keySize);
        std::cout << filterStr << " " << fSStart << std::endl;
        fSStart = fSStart.lowercase();

        if (key == fSStart) {
            std::cout << "TRUE !!!" << std::endl;
            return true;
        }
    }
    std::cout << "FALSE !!!" << std::endl;
    return false; // No match

}
