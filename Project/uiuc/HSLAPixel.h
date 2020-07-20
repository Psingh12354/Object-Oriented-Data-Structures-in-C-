/**
 * @file HSLAPixel.h
 *
 * @author University of Illinois CS 225 Course Staff
 * @version 2018r1-lab1 - Updated for CS 400
 */


#ifndef CS225_HSLAPIXEL_H_
#define CS225_HSLAPIXEL_H_

#include <iostream>
#include <sstream>

namespace uiuc{
  class HSLAPixel {
  public:
    double h; /**< Hue of the pixel, in degrees [0, 360). */
    double s; /**< Saturation of the pixel, [0, 1]. */
    double l; /**< Luminance of the pixel, [0, 1]. */
    double a; /**< Alpha of the pixel, [0, 1]. */

    
    HSLAPixel();

  
    HSLAPixel(double hue, double saturation, double luminance);

    
    HSLAPixel(double hue, double saturation, double luminance, double alpha);

    HSLAPixel & operator=(HSLAPixel const & other);
    bool operator== (HSLAPixel const & other) const ;
    bool operator!= (HSLAPixel const & other) const ;
    bool operator<  (HSLAPixel const & other) const ;
  };

std::ostream & operator<<(std::ostream & out, HSLAPixel const & pixel);
  std::stringstream & operator<<(std::stringstream & out, HSLAPixel const & pixel);
}

#endif
