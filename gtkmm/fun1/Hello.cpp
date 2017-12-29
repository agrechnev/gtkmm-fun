#include "gtkmm/label.h"

#include "./Hello.h"


Hello::Hello() {
    set_title("Handmaiden's Love !!!");
    set_default_size(300, 350);

    // --------- Layout-----------
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
    chbu.signal_toggled().connect([this]()->void{
                                      bool v=chbu.get_active();
                                      scaleV.set_draw_value(v);
                                      scaleH.set_draw_value(v);
                                  });
    boxV2.pack_start(chbu, Gtk::PACK_SHRINK);
    //---------- Combo -----------------
    boxV2.pack_start(*Gtk::manage(new Gtk::Label("Scale Value Position:", 0)));
    boxV2.pack_start(boxHCombo, Gtk::PACK_SHRINK);
    // ----------------
    add(boxV2);

    show_all_children();
}
