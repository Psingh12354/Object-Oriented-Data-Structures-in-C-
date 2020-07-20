/**
 * @file HSLAPixel.cpp
 * Implementation of the HSLAPixel class for use in with the PNG library.
 *
 * @author University of Illinois CS 225 Course Staff
 * @version 2018r1-lab1 - Updated for CS 400
 */

#include <cmath>
#include <iostream>
#include "HSLAPixel.h"
using namespace std;

namespace uiuc {
  HSLAPixel::HSLAPixel() {
    h = 0;
    s = 0;
    l = 1.0;
    a = 1.0;
  }

  HSLAPixel::HSLAPixel(double hue, double saturation, double luminance) {
    h = hue;
    s = saturation;
    l = luminance;
    a = 1.0;
  }

  HSLAPixel::HSLAPixel(double hue, double saturation, double luminance, double alpha) {
    h = hue;
    s = saturation;
    l = luminance;
    a = alpha;
  }

  HSLAPixel & HSLAPixel::operator=(HSLAPixel const & other) {
    this->h = other.h;
    this->s = other.s;
    this->l = other.l;
    this->a = other.a;
    return *this;
  }

  bool HSLAPixel::operator== (HSLAPixel const & other) const {
    // thank/blame Wade for the following function
    if (fabs(a - other.a) > 0.01) { return false; }
    if ( a == 0 ) { return true; }

    if (fabs(l - other.l) > 0.01) { return false; }
    if (l == 0 || l == 1) { return true; }

    if (fabs(s - other.s) > 0.01) { return false; }
    if (s == 0) { return true; }

    if (fabs(h - other.h) < 0.5 || fabs(h - other.h) > 359.5 ) { return true; }
    else { return false; }
}

  bool HSLAPixel::operator!= (HSLAPixel const & other) const {
    return !(*this == other);
  }

  bool HSLAPixel::operator<  (HSLAPixel const & other) const {
      if (*this == other) { return false; }

      if (l < other.l)
          return true;
      else if (l > other.l)
          return false;
      // == lumininance

      if (s < other.s)
          return true;
      else if (s > other.s)
          return false;
      // == saturation

      if (h < other.h)
          return true;
      else if (h > other.h)
          return false;
      // == hue

      if (a < other.a)
          return true;
      else if (a > other.a)
          return false;
      // == alpha

      // same pixel
      return false;
  }

  std::ostream & operator<<(std::ostream & out, HSLAPixel const & pixel) {
    out << "(" << pixel.h << ", " << pixel.s << ", " << pixel.l << (pixel.a != 1 ? ", " + std::to_string(pixel.a) : "") << ")";

    return out;
  }


}
