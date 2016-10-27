/*
 HNR CSCE 121-200, Fall 2016, Assignment 6, Problem 1
 Author: Josiah Coad
 CODE DESCRIPTION: This code makes a simple 3X3 checkerboard
*/

#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"


void make_checkerboard(int corner_x, int corner_y, int win_size){
  //makes a 3X3 checkerboard with black and red alternating squares
  //corner_x is the pixels count to the window left top corner from left of screen
  //corner_y is the pixels from top of screen to window left top corner
  //win_size is the window height/width in pixels
  if (win_size + corner_x > x_max()) error("Window can not fit on screen");
  if (win_size + corner_y > y_max()) error("Window can not fit on screen");
  int boxes_inline = 3; // number of boxes verticle/horizontal
  int ppb = win_size / boxes_inline; // pixels per box depends on size of window
  Simple_window win1(Point(corner_x,corner_y),win_size, win_size,"Checker Board");
  
  Vector_ref<Rectangle> vr;
  
  for (int i = 0; i < boxes_inline; ++i){
    for (int j = 0; j < boxes_inline; ++j){
      vr.push_back(new Rectangle(Point(i*ppb,j*ppb),ppb,ppb)); 
      bool isRed = j % 2 == 0;        // box is red on even boxes 
      if (i % 2 == 0) isRed = !isRed; // inverses pattern every row to create checkers pattern
      vr[vr.size()-1].set_fill_color(isRed ? Color::red : Color::black);
      win1.attach(vr[vr.size()-1]); // attatch the box to the window
    }
  }
  win1.wait_for_button();
}
/*
int main(){
try {
  make_checkerboard(100, 100, 500);
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