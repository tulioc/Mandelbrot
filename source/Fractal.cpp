#include <iostream>
#include "../include/Bitmap.hpp"
using namespace std;
using namespace caveofprogramming;

int main () {
  Bitmap bitmap(800,600);
  bitmap.write("test.bmp");
  cout << "Initial" << endl;
  return 0;
}
