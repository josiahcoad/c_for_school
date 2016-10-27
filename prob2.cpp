/*
 HNR CSCE 121-200, Fall 2016, Assignment 6, Problem 1
 Author: Josiah Coad
 CODE DESCRIPTION: This code makes an elementry 2D house
*/

#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"

/*
int main(){
  try {
  int corner_x=100;
  int corner_y=100;
  cout << "House Dimensions\n"
  << "----------------------------\n";
  int win_w = 800;
  int win_h = 500;
  int mid_x = win_w / 2;
  int mid_y = win_h / 2;
  Simple_window win(Point(corner_x,corner_y),
                    win_w, win_h, "My House");
  
  cout << "Window Height and Width = (" << win_w << " " << win_h << ")\n";
  
  // first make the house front
  int front_w = win_w - (win_w * .2);
  int front_h = win_h / 2.0;
  int bottom_offset = 10;
  int front_tl_x = mid_x - front_w/2.0; // placement of house front in x
  int front_tl_y = win_h - (bottom_offset + front_h); // placement in y
  Rectangle house_front(Point(front_tl_x, front_tl_y), front_w, front_h);
  house_front.set_fill_color(Color::dark_green);
  win.attach(house_front);
  cout << "Front Width and Height = (" << front_w << " " << front_h << ")\n";
  
  
  // then add the door
  int door_w = (1/8.0) * front_w;
  int door_h = (1/1.5) * front_h;
  int door_tl_x = mid_x - door_w/2.0;
  int door_tl_y = win_h - (bottom_offset + door_h);
  Rectangle house_door(Point(door_tl_x, door_tl_y), door_w, door_h);
  house_door.set_fill_color(Color::blue);
  win.attach(house_door);
  cout << "Door H&W = (" << door_h << ", " << door_w << ")\n";

  // make a door knob 
  int knob_center_x = door_tl_x + (door_w / 5.0);
  int knob_center_y = door_tl_y + (door_h / 2.0);
  int knob_rad      = (1/10.0) * door_w;
  Circle door_knob(Point(knob_center_x, knob_center_y), knob_rad);
  door_knob.set_fill_color(Color::dark_red);
  win.attach(door_knob);

  // make windows
  int window_size = (1/5.0) * front_w; // windows are squares and are of same size
  int W1_tl_x = front_tl_x + (1/10.0) * front_w;
  int W1_tl_y = front_tl_y + (1/5.0) * front_h;
  int W2_tl_x = front_tl_x + (7/10.0) * front_w;
  int W2_tl_y = W1_tl_y;
  Rectangle house_W1(Point(W1_tl_x, W1_tl_y), window_size, window_size);
  Rectangle house_W2(Point(W2_tl_x, W2_tl_y), window_size, window_size);
  house_W1.set_fill_color(6); // 6 is enumeration value for light blue
  house_W2.set_fill_color(6);
  win.attach(house_W1);
  win.attach(house_W2);

  // make crosshatches for window1
  Closed_polyline L1_vert;
  int L1_vert_x = W1_tl_x + (.5) * window_size;
  L1_vert.add(Point(L1_vert_x, W1_tl_y));
  L1_vert.add(Point(L1_vert_x, W1_tl_y + window_size));
  win.attach(L1_vert);
  Closed_polyline L1_horiz;
  int L1_horiz_y = W1_tl_y + (.5) * window_size;
  L1_horiz.add(Point(W1_tl_x, L1_horiz_y));
  L1_horiz.add(Point(W1_tl_x + window_size, L1_horiz_y));
  win.attach(L1_horiz);
  
  // make crosshatches for window2
  Closed_polyline L2_vert;
  int L2_vert_x = W2_tl_x + (.5) * window_size;
  L2_vert.add(Point(L2_vert_x, W2_tl_y));
  L2_vert.add(Point(L2_vert_x, W2_tl_y + window_size));
  win.attach(L2_vert);
  Closed_polyline L2_horiz;
  int L2_horiz_y = W2_tl_y + (.5) * window_size;
  L2_horiz.add(Point(W2_tl_x, L2_horiz_y));
  L2_horiz.add(Point(W2_tl_x + window_size, L2_horiz_y));
  win.attach(L2_horiz);

  // make chimney (will hide partly behind roof)
  int chim_h = (1/3.5) * front_h;
  int chim_w = (1/10.0) * front_w;
  int chim_tl_x = front_tl_x + chim_w;
  int chim_tl_y = front_tl_y - chim_h;
  Rectangle house_chimney(Point(chim_tl_x, chim_tl_y), chim_w, chim_h);
  house_chimney.set_fill_color(Color::red);
  win.attach(house_chimney);

  // make roof
  int overhang = (1/20.0) * front_w;
  int roof_h = front_h / 2.0;
  Point roof_P1(front_tl_x - overhang, front_tl_y);
  Point roof_P2(front_tl_x + front_w + overhang, front_tl_y);
  Point roof_P3(mid_x, front_tl_y - roof_h);
  Closed_polyline house_roof;
  house_roof.add(roof_P1);
  house_roof.add(roof_P2);
  house_roof.add(roof_P3);

  house_roof.set_fill_color(Color::dark_green);
  win.attach(house_roof);  
  

  // EXTRA: Make smoke cloud!
  int mid_chim = chim_tl_x + .5 * chim_w;
  int spacing = (1/3.0) * chim_h;
  Circle smoke1(Point(mid_chim, chim_tl_y - spacing), chim_w / 4.0);
  Circle smoke2(Point(mid_chim, chim_tl_y - 2 * spacing), chim_w / 6.0);
  Circle smoke3(Point(mid_chim, chim_tl_y - 3 * spacing), chim_w / 8.0);
  smoke1.set_fill_color(Color::black);
  smoke2.set_fill_color(Color::black);
  smoke3.set_fill_color(Color::black);
  win.attach(smoke1);
  win.attach(smoke2);
  win.attach(smoke3);

  win.wait_for_button();
  return 0;
  }
  catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
  }
  catch (...) {
    cerr << "Some exception\n";
    return 2;
  }
}
*/