// g++ ./gyak/olimpia.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ./gyak/olimpia `fltk-config --ldflags --use-images` && ./gyak/olimpia
#include "../Simple_window.h"
#include "../Graph.h"
#include <stdlib.h>

int main(){
    using namespace Graph_lib;

    Simple_window window{Point{200,200},800,1000,"Olimpia Karika"};

    Vector_ref<Graph_lib::Circle> circles;
    
    circles.push_back(new Graph_lib::Circle(Point{250,300},100));
    circles.push_back(new Graph_lib::Circle(Point{500,300},100));
    circles.push_back(new Graph_lib::Circle(Point{750,300},100));
    circles.push_back(new Graph_lib::Circle(Point{375,400},100));
    circles.push_back(new Graph_lib::Circle(Point{625,400},100));
    circles[0].set_color(Color::blue);
    circles[1].set_color(Color::black);
    circles[2].set_color(Color::red);
    circles[3].set_color(Color::yellow);
    circles[4].set_color(Color::green);
    for(int i = 0; i<circles.size(); i++){
        circles[i].set_style(Line_style{Line_style::solid,15});
        window.attach(circles[i]);
    }

    window.wait_for_button();
    return 0;
}