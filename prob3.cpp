/*
 HNR CSCE 121-200, Fall 2016, Assignment 6, Problem 1
 Author: Josiah Coad
 CODE DESCRIPTION: This code displays a picture on a window
*/

#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"



void disp_pic(int corner_x, int corner_y, string pic_name){
  // display a picture of friends with a title and caption
  int win_w = 1000;
  int win_h = 1000;
  Simple_window win(Point(corner_x,corner_y), win_w, win_h, "My Friends Are Great");
  int img_inset = 20;
  Image pic(Point(img_inset, img_inset), pic_name);
  win.attach(pic);
  
  // Make a caption and instert it
  ostringstream caption;
  caption << "What Great Memories!\n"
          << " (This window is: X=" << win.x_max() 
          << " Y=" << win.y_max() << ")";
  Text win_caption(Point(100, 20), caption.str());
  win_caption.set_font_size(20);
  win_caption.set_color(Color::cyan);
  win_caption.set_font(Graph_lib::Font::times_bold);
  win.attach(win_caption);

  win.wait_for_button();
}
/*
int main(){
try {
  disp_pic(100, 100, "friends.jpg");
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