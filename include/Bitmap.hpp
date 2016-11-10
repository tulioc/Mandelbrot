#ifndef BITMAP_H_
#define BITMAP_H_

#include <string>
using namespace std;

namespace caveofprogramming {

class Bitmap {
  private:
    int m_height{0};
    int m_width{0};
  public:
      Bitmap(int width, int height);
      virtual ~Bitmap();
      bool write(string filename);
};

} /* namespace caveofprogramming*/

#endif