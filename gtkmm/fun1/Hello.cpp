#include "gtkmm/label.h"

#include "./Hello.h"


Hello::Hello() {
    set_title("Handmaiden's Love !!!");
    set_default_size(300, 350);

    // --------- Layout-----------
    boxV1.pack_start(boxV2);
    boxV1.pack_start(sep, Gtk::PACK_SHRINK);
    boxV1.pack_start(btnQuit, Gtk::PACK_SHRINK);
    btnQuit.set_can_default(true);
    btnQuit.grab_default();
    btnQuit.signal_clicked().connect([this]()->void{
        hide();
    });


    boxV2.set_border_width(10);
    boxV2.pack_start(boxHScales);

    // ---------Upper panel-----------
    scaleV.set_digits(1);
    scaleV.set_value_pos(Gtk::POS_TOP);
    scaleV.set_draw_value(true);
    scaleV.set_inverted(true);
    scaleH.set_draw_value(true);
    boxHScales.pack_start(scaleV);
    boxHScales.pack_start(boxVHScale);
    boxVHScale.pack_start(scaleH);
    boxVHScale.pack_start(scroll);

    //-------- Check btn ------------
    chbu.set_active(true);
    chbu.signal_toggled().connect([this]()->void{
                                      bool v=chbu.get_active();
                                      scaleV.set_draw_value(v);
                                      scaleH.set_draw_value(v);
                                  });
    boxV2.pack_start(chbu, Gtk::PACK_SHRINK);
    //---------- Combo -----------------
    comboPos.set_model(treeMod);
    comboPos.pack_start(modCol.colTitle);
    Gtk::TreeModel::Row row;
    row = *(treeMod->append());
    row[modCol.posType] = Gtk::POS_TOP;
    row[modCol.colTitle] = "Top";
    row = *(treeMod->append());
    row[modCol.posType] = Gtk::POS_BOTTOM;
    row[modCol.colTitle] = "Bottom";
    row = *(treeMod->append());
    row[modCol.posType] = Gtk::POS_LEFT;
    row[modCol.colTitle] = "Left";
    row = *(treeMod->append());
    row[modCol.posType] = Gtk::POS_RIGHT;
    row[modCol.colTitle] = "Right";


    boxV2.pack_start(boxHCombo, Gtk::PACK_SHRINK);
    boxHCombo.pack_start(*Gtk::manage(new Gtk::Label("Scale Value Position:", 0)));
    boxHCombo.pack_start(comboPos);

    comboPos.set_active(0);
    comboPos.signal_changed().connect([this]()->void{
        Gtk::TreeModel::iterator iter = comboPos.get_active();
        if (!iter)
            return;
        Gtk::TreeModel::Row row = *iter;
        if (!row)
            return;

        const Gtk::PositionType postype = row[modCol.posType];

        scaleH.set_value_pos(postype);
        scaleV.set_value_pos(postype);
    });
    //---------- Digits -----------------
    boxV2.pack_start(boxHDig, Gtk::PACK_SHRINK);
    boxHDig.pack_start(*Gtk::manage(new Gtk::Label("Scale Digits:", 0)), Gtk::PACK_SHRINK);
    boxHDig.pack_start(scaleDig);
    scaleDig.set_digits(0);
    adjDig->signal_value_changed().connect([this]()->void{
        int val = (int)adjDig->get_value();
        scaleV.set_digits(val);
        scaleH.set_digits(val);
    });
    //---------- Page size -----------------
    boxV2.pack_start(boxHPag, Gtk::PACK_SHRINK);
    boxHPag.pack_start(*Gtk::manage(new Gtk::Label("Scrollbar Page Size:", 0)), Gtk::PACK_SHRINK);
    boxHPag.pack_start(scalePag);
    scalePag.set_digits(0);
    adjPag->signal_value_changed().connect([this]()-> void{
        double val = adjPag->get_value();
        adjMain->set_page_size(val);
        adjMain->set_page_increment(val);
    });

    // ----------------
    add(boxV1);
    show_all_children();
}
