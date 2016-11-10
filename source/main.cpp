#include <iostream>
#include "../include/Bitmap.hpp"
#include "../include/Mandelbrot.hpp"
#include <cstdint>
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

      int iterations = Mandelbrot::getIterations(x_fractal, y_fractal);

      uint8_t red = (uint8_t)(256*(double)iterations/Mandelbrot::MAX_ITERATIONS);
      bitmap.setPixel(x, y, red,red,red); // RED
      if(red < min) min = red;
      if(red > max) max = red;
    }
  }
  cout << min << "," << max << endl;
  bitmap.write("test.bmp");
  cout << "Finished" << endl;
  return 0;
}
