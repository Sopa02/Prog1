// g++ ./dr13/main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ./dr13/main `fltk-config --ldflags --use-images` && ./dr13/main
#include "../Simple_window.h"
#include "../Graph.h"
#include <stdlib.h>
#include <ctime>

//Our own way of storing rectangles
// template<class T>class Vector_rect
// {
//         public:
//         void push_back(T&);//named
//         void push_back(T*);//unnamed
//         T& operator[](int i);
//         const T& operator[](int i) const;
//         int size() const;
// };

int main(){
    using namespace Graph_lib;
    Simple_window window{Point{200,200},800,1000,"Simple_window"};


    //800*800 grid----------------------------------------------------------------

    int size = 800; // x_size=y-size -> one variable is enough
    int gridSpace = 100; // space between the lines
    Lines grid; // all the lines in one object
    for (int i = gridSpace; i <= size; i+=gridSpace)
    {
        //Adding individual lines to the grid object
        //  point on the top - point on the bottom
        //  x:100,200... y:0(top)   x:100,200... y:800(bottom)
        //  left to right on the top - same, but on the bottom
        grid.add(   Point{i,0},    Point{i,size}    );
        //  point on the left - point on the right
        //  x:0(left) y:100,200...  x:800(right) y:100,200...
        // from top to bottom on the left - same, but on the right
        grid.add(   Point{0,i},    Point{size,i}    );
    }
    window.attach(grid);


    //8 rectangles----------------------------------------------------------------

    vector<Graph_lib::Rectangle *> rectangles;

    for (int i = 0; i < 800; i+=100)
    {
        rectangles.push_back(new Graph_lib::Rectangle(Point{i,i},Point{i+100,i+100}));
        rectangles[rectangles.size()-1]->set_fill_color(Color::red);
        window.attach(*rectangles[rectangles.size()-1]);
    }

    Image i1{Point{0,200},"rozsomak.jpg"};
    window.attach(i1);
    Image i2{Point{200,0},"rozsomak.jpg"};
    window.attach(i2);
    Image i3{Point{200,400},"rozsomak.jpg"};
    window.attach(i3);
    Image i4{Point{400,200},"rozsomak.jpg"};
    window.attach(i4);

    Image i5{Point{600,600},"smile.jpg"};
    window.attach(i5);
    window.wait_for_button();
    //  These will store where the image was moved to
    int help1=600;
    int help2=600;
    for (int i = 0; i < 10; i++)
    {
        //Setting the seed of the random generator with the time
        srand(time(NULL)*sqrt(help1)); //using the last random number to change the seed a bit
        i5.move(-help1,-help2); // Sets the image back to 0;0
        help1=(rand()%8)*100;  //  Random number between 0,100,200...700
        help2=(rand()%8)*100;  // 2 random numbers, so we get coordinates other than diagonal
        i5.move(help1,help2);  
        window.wait_for_button();
    }
    return 0;
}