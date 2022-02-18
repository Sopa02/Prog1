// g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
//  DRILL 12
#include "Simple_window.h"  //Next button
#include "Graph.h"

int main(){
    using namespace Graph_lib;

    Point tl{100,100}; //Top left corner
    int width = 600;
    int height = 400;
    Simple_window win{tl,width,height,"My window"};

    Axis xa{Axis::x,Point{20,300},280,10,"x axis"};
    //Axis::x - Horizontal
    //starting at 20,300
    //280px long
    //10 notches

    win.attach(xa); //Attach the axis to the window
    win.set_label("My window 2.0"); //Rename the window

    Axis ya{Axis::y,Point{20,300},280,10,"y axis"};
    ya.set_color(Color::red); //Set the color of y axis
    ya.label.set_color(Color::dark_red); //Set the color of the label of y axis
    win.attach(ya);


    Function sine {sin,0,100,Point{20,150},1000,50,50}; //sine curve
    //plot sin() int the range 0:100 with 0,0 at 20,150
    //using 1000 points, scale x values *50, scale y values *50
    win.attach(sine);

    //Polygons

    Polygon poly;
    poly.add(Point{300,200});
    poly.add(Point{350,100});
    poly.add(Point{400,200});

    poly.set_color(Color::red);
    poly.set_style(Line_style::dash); //Set the style of the line which connects the points
    //Default: solid
    win.attach(poly);

    //Rectangles

    Rectangle r{Point{200,200},100,50};
    win.attach(r);
    
    //Rectangle with a polygon

    Closed_polyline poly_rect;
    poly_rect.add(Point{100,50});
    poly_rect.add(Point{200,50});
    poly_rect.add(Point{200,100});
    poly_rect.add(Point{100,100});
    win.attach(poly_rect);
    //Looks like a rectangle, not a rectangle in memory. ->
    poly_rect.add(Point{50,75});

    //Fill

    r.set_fill_color(Color::yellow);
    poly.set_style(Line_style(Line_style::dash,4));
    poly_rect.set_style(Line_style(Line_style::dash,2));
    poly_rect.set_fill_color(Color::green);

    //Text

    Text t {Point(150,150),"Hello, graphical world!"};
    win.attach(t);
    
    t.set_font(Font::times_bold);
    t.set_font_size(20);
    
    //Images

    //  Image ii{Point{100,50},"image.jpg"};
    //  ii.move(100,200);
    //  win.attach(ii);
    
    //Some more

    Circle c{Point{100,200},50};
    Ellipse e {Point{100,200},75,25};
    e.set_color(Color::dark_red);
    Mark m{Point{100,200},'x'};

    ostringstream oss;
    oss<<"screen size: "<<x_max()<<"*"<<y_max()<<"; window size: "<<win.x_max()<<"*"<<win.y_max();
    Text sizes{Point{100,20},oss.str()};
    Image cal{Point{225,225},"snow_cpp.jpg"};
    cal.set_mask(Point{40,40},200,150);
    win.attach(c);
    win.attach(m);
    win.attach(e);
    win.attach(sizes);
    win.attach(cal);
    


    win.wait_for_button();
    //display

}
