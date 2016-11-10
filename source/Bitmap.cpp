#include "../include/Bitmap.hpp"
#define COLORS_RGB 3
namespace caveofprogramming {

Bitmap::Bitmap(int width, int height): m_width(width), m_height(height), m_pixels(new uint8_t[width*height*COLORS_RGB]) {

}

bool Bitmap::write(string filename) {
  return false;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {

}

Bitmap::~Bitmap() {
  // descructor
}






} /* namespace caveofprogramming*/
