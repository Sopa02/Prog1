// g++ ./dr15/main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ./dr15/main `fltk-config --ldflags --use-images` && ./dr15/main

#include "../Simple_window.h"
#include "../Graph.h"
#include "math.h"
double one(double x){return 1;}
double slope(double x){return x/2;}
double square(double x){return x*x;}
double sloping_cos(double x){return cos(x)+slope(x);}
int main(){

    using namespace Graph_lib;
    Point tl{100,100};
    Simple_window window{tl,600,600,"Function graphs"};

    Axis xa {Axis::x,Point{100,300},400,20,"1 = = 20 pixels"};
    Axis ya {Axis::y,Point{300,500},400,20,"1 = = 20 pixels"};
    xa.set_color(Color::red);
    ya.set_color(Color::red);
    window.attach(xa);
    window.attach(ya);

    Function f1 {one,-10,11,Point(300,300),400,20,20};
    Function f2 {slope,-10,10,Point{300,300},400,20,20};
    Text label_f2{Point{100,420},"x/2"};
    Function f3 {square,-10,10,Point{300,300},400,20,20};
    Function f4 {cos,-10,10,Point{300,300},400,20,20};
    f4.set_color(Color::blue);
    Function f5 {sloping_cos,-10,10,Point{300,300},400,20,20};


    window.attach(f1);
    window.attach(f2);
    window.attach(label_f2);
    window.attach(f3);
    window.attach(f4);
    window.attach(f5);
    window.wait_for_button();


    return 0;
}