#include <iostream>
#include "../include/Bitmap.hpp"
using namespace std;
using namespace caveofprogramming;

int main () {
  int const WIDTH = 800;
  int const HEIGHT = 600;

  Bitmap bitmap(WIDTH,HEIGHT);

  double min = 999999;
  double max = -999999;

  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      double x_fractal = (x - WIDTH/2) * 2.0/WIDTH;
      double y_fractal = (y - HEIGHT/2) * 2.0/HEIGHT;

      if(x_fractal < min) min = x_fractal;
      if(x_fractal > max) max = x_fractal;


      //bitmap.setPixel(x, y, 255,0,0); // RED
    }
  }
  cout << min << "," << max << endl;
  bitmap.write("test.bmp");
  cout << "Initial" << endl;
  return 0;
}
