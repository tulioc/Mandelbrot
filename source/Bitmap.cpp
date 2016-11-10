#include <fstream>
#include "../include/Bitmap.hpp"
#include "../include/BitmapInfoHeader.hpp"
#include "../include/BitmapFileHeader.hpp"
#define COLORS_RGB 3

using namespace caveofprogramming;
using namespace std;

namespace caveofprogramming {

Bitmap::Bitmap(int width, int height): m_width(width), m_height(height), m_pixels(new uint8_t[width*height*COLORS_RGB]{}) {

}

bool Bitmap::write(string filename) {
  BitmapFileHeader bitmap_file_header;
  BitmapInfoHeader bitmap_info_header;

  bitmap_file_header.file_size = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width*m_height*COLORS_RGB;
  bitmap_file_header.data_offset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

  bitmap_info_header.width = m_width;
  bitmap_info_header.height = m_height;

  ofstream file;
  file.open(filename, ios::out|ios::binary);
  if(!file) {
    return false;
  }

  file.write((char *)&bitmap_file_header, sizeof(bitmap_file_header));
  file.write((char *)&bitmap_info_header, sizeof(bitmap_info_header));
  file.write((char *)m_pixels.get(), m_width*m_height*COLORS_RGB);

  file.close();

  if(!file) {
    return false;
  }

  return true;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {

}

Bitmap::~Bitmap() {
  // descructor
}






} /* namespace caveofprogramming*/
