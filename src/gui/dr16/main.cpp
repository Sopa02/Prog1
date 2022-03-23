// g++ ./dr16/main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ./dr16/main `fltk-config --ldflags --use-images` && ./dr16/main

#include "../Simple_window.h"
#include "../Graph.h"
#include "../GUI.h"

// STRUCT


struct Lines_window : Window {
    Lines_window(Point xy, int w, int h, const string& title);
    
private:
    Open_polyline lines;
    Button next_button;
    Button quit_button;
    Button menu_button;
    Button ls_menu_button;
    Menu color_menu;
    Menu line_style_menu;
    In_box next_x;
    In_box next_y;
    Out_box xy_out;

    static void cb_red(Address, Address);
    static void cb_blue(Address, Address);
    static void cb_black(Address, Address);
    static void cb_menu(Address, Address);
    static void cb_ls_menu(Address, Address);
    static void cb_dash(Address, Address);
    static void cb_solid(Address, Address);
    // COLOR MENU
    void red_pressed() { change(Color::red); hide_menu(); }
    void blue_pressed() { change(Color::blue); hide_menu(); }
    void black_pressed() { change(Color::black); hide_menu(); }
    void change(Color c) { lines.set_color(c); redraw(); }
    void menu_pressed() {menu_button.hide(); color_menu.show();}
    void hide_menu(){color_menu.hide(); menu_button.show();}
    // STYLE MENU
    void ls_menu_pressed() {ls_menu_button.hide(); line_style_menu.show();}
    void hide_ls_menu(){ls_menu_button.show(); line_style_menu.hide();}
    void dash_pressed() {change_style(Line_style::dash); hide_ls_menu();}
    void solid_pressed() {change_style(Line_style::solid); hide_ls_menu();}
    void change_style(Line_style s) {lines.set_style(s); redraw();}

    void next();
    void quit();
};

// CONSTRUCTOR ----------------------------------

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    next_button{Point{x_max()-150,0},70,20,"Next point",
        [](Address, Address pw){reference_to<Lines_window>(pw).next();}},
    quit_button{Point{x_max()-70,0}, 70, 20, "Quit",
        [](Address, Address pw){reference_to<Lines_window>(pw).quit();}},
    next_x{Point{x_max()-310,0}, 50, 20, "next x:"},
    next_y{Point{x_max()-210,0}, 50, 20, "next y:"},
    xy_out{Point{100,0}, 100, 20, "current (x,y):"},
    color_menu{Point{x_max()-70,40},70,20,Menu::vertical,"color"},
    menu_button{Point{x_max()-80,30},80,20,"color menu", cb_menu},
    ls_menu_button{Point{x_max()-80,130},80,20,"style menu",cb_ls_menu},
    line_style_menu{Point{x_max()-70,140},70,20,Menu::vertical,"style"}
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    xy_out.put("no point");

    //COLOR MENU
    color_menu.attach(new Button{Point{0,0},0,0,"red",cb_red});
    color_menu.attach(new Button{Point{0,0},0,0,"blue",cb_blue});
    color_menu.attach(new Button{Point{0,0},0,0,"black",cb_black});
    attach(color_menu);
    color_menu.hide();
    attach(menu_button);

    //STYLE MENU
    line_style_menu.attach(new Button{Point{0,0},0,0,"dash",cb_dash});
    line_style_menu.attach(new Button{Point{0,0},0,0,"solid",cb_solid});
    attach(line_style_menu);
    line_style_menu.hide();
    attach(ls_menu_button);
    attach(lines);
}

// CALLBACKS

void Lines_window::cb_red(Address, Address pw){
    reference_to<Lines_window>(pw).red_pressed();
}
void Lines_window::cb_blue(Address, Address pw){
    reference_to<Lines_window>(pw).blue_pressed();
}
void Lines_window::cb_black(Address, Address pw){
    reference_to<Lines_window>(pw).black_pressed();
}
void Lines_window::cb_menu(Address, Address pw){
    reference_to<Lines_window>(pw).menu_pressed();
}
void Lines_window::cb_ls_menu(Address, Address pw){
    reference_to<Lines_window>(pw).ls_menu_pressed();
}
void Lines_window::cb_dash(Address, Address pw){
    reference_to<Lines_window>(pw).dash_pressed();
}
void Lines_window::cb_solid(Address, Address pw){
    reference_to<Lines_window>(pw).solid_pressed();
}

// METHODS -------------------------------------

void Lines_window::quit(){
    hide();
}

void Lines_window::next(){
    int x = next_x.get_int();
    int y = next_y.get_int();
    lines.add(Point{x,y});

    ostringstream ss;
    ss<<'('<<x<<','<<y<<')';
    xy_out.put(ss.str());
    
    redraw();
}

// MAIN -----------------------------------------

int main(){
    
    try
    {
        Lines_window win {Point{100,100},600,400,"Lines"};
        return gui_main();
    }
    catch(exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    
    
    return 0;
}