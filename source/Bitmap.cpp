#include <fstream>
#include "../include/Bitmap.hpp"
#include "../include/BitmapInfoHeader.hpp"
#include "../include/BitmapFileHeader.hpp"

using namespace caveofprogramming;
using namespace std;

#define RGB_COLORS 3

namespace caveofprogramming {

Bitmap::Bitmap(int width, int height) :
		m_width(width), m_height(height), m_pixels(
				new uint8_t[width * height * RGB_COLORS] { }) {

}

bool Bitmap::write(string filename) {

	BitmapFileHeader file_header;
	BitmapInfoHeader info_header;

	file_header.file_size = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height * RGB_COLORS;
	file_header.data_offset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

	info_header.width = m_width;
	info_header.height = m_height;

	ofstream file;
	file.open(filename, ios::out | ios::binary);

	if (!file) {
		return false;
	}

	file.write((char *)&file_header, sizeof(file_header));
	file.write((char *)&info_header, sizeof(info_header));
	file.write((char *)m_pixels.get(), m_width*m_height*RGB_COLORS);

	file.close();

	if (!file) {
		return false;
	}

	return true;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {

  uint8_t *p_pixel = m_pixels.get();
	p_pixel += (y * RGB_COLORS) * m_width + (x * RGB_COLORS);

	p_pixel[0] = blue;
	p_pixel[1] = green;
	p_pixel[2] = red;
}

Bitmap::~Bitmap() {
	// TODO Auto-generated destructor stub
}

} /* namespace caveofprogramming */
