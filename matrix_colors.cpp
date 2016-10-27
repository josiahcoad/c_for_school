/**
  Sample code from Chapter 13, section 13.10 page 461
  Allows to use loops to draw shapes on the window,
  in this case the program will display a 16 by 16 color matrix,
  where squares have length 20.

  For more details refer to page 461 of textbook.
**/

#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities_4.h"
/*
int main()
try {
  //  if(H112 != 201401L)error("Error: incorrect std_lib_facilities_4.h version ",H112);
  Simple_window win1(Point(100,100),600,600,"16*16 color matrix");

  Vector_ref<Rectangle> vr;
  
  for (int i = 0; i < 16; ++i)
  {
  	for (int j = 0; j < 16; ++j)
  	{
  		vr.push_back(new Rectangle(Point(i*20,j*20),20,20)); 
      cout << "i: " << i << ", j: " << j << ", ";

		  vr[vr.size()-1].set_fill_color(i*16+j); //we can also use numbers from 0 to 255 for colors
		  cout << "fill color: " << i*16+j << "\n";
      win1.attach(vr[vr.size()-1]); //attach to window the current Rectangle object we add to the vector
  	}
  }

  win1.wait_for_button();
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
*/