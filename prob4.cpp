/*
 HNR CSCE 121-200, Fall 2016, Assignment 6, Problem 4
 Author: Josiah Coad
 CODE DESCRIPTION: This code displays a honeycomb grid made of hexagons
*/

#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"


class RegHex : public Closed_polyline {
  private:
    Point center;
    int rad;
  public:
    RegHex(Point c, int r) {
      rad = r; 
      center = c;
      if (rad <= 0) cerr << "Error: radius cannot be negative.\n";
      const double pi = 3.1415926535897;
      const double angle = pi / 3;

      for (int i = 0; i < 6; ++i) {
        int x = (center.x + rad * sin(i*angle));
        int y = (center.y + rad * cos(i*angle));
        add(Point(x, y));
      }
    }
};


int main(){
  const double pi = 3.1415926535897;
  try {
    int rad = 50;
    int dist_step = (rad*2) * sin(pi/3);
    Simple_window win1(Point(100, 100), 600, 300, "Hexagon Grid");
    int top_y = 80;
    int bottom_y = 155;
    int init_dist = 50;
    int dist = init_dist;

    RegHex H1(Point(dist, top_y), rad); win1.attach(H1);
    dist += dist_step;
    RegHex H2(Point(dist, top_y), rad); win1.attach(H2);
    dist += dist_step;
    RegHex H3(Point(dist, top_y), rad); win1.attach(H3);
    dist += dist_step;
    RegHex H4(Point(dist, top_y), rad); win1.attach(H4);
    
    dist = init_dist + 45;
    RegHex H5(Point(dist, bottom_y), rad); win1.attach(H5);
    dist += dist_step;
    RegHex H6(Point(dist, bottom_y), rad); win1.attach(H6);
    dist += dist_step;
    RegHex H7(Point(dist, bottom_y), rad); win1.attach(H7);
    dist += dist_step;
    RegHex H8(Point(dist, bottom_y), rad); win1.attach(H8);
    win1.wait_for_button();
    return 0;
  }
  catch (exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
  }
  catch (...) {
    cerr << "Some exception\n";
    return 2;
  }
}
