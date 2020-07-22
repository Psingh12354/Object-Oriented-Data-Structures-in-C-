<h1 align="center">Object-Oriented Data Structures in C++</h1>
<p><a href="https://d3c33hcgiwev3.cloudfront.net/tX6cOkWjEemnrA4AsaAhFA_bffc6c3e72284eda9820d7fca7640b46_image-transform-instructions_20190313.pdf?Expires=1595376000&Signature=dB~vI0AIX0Urw9ZNkwTxE7jd3RQXLkkI0sSLRa2iK8k2XZENBTAfuUVPtrBMYIP1vjUE9GaK1aJUCIWB92-tGDHNEfXUH6SgddX-yO7V3m56iEEQ-aQjeg3iYPY6bxNr4I0Z17jCNRJgw2OTaFfA83-Qk9PAr~j9UHPmKZyUcEI_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A">Click</a> here to get complete question</p>

# Solution

<p>Click on the <a href="https://github.com/Psingh12354/Object-Oriented-Data-Structures-in-C-/tree/master/Project "> link </a> to get your solutions</p>

<p> <b><i><u>Source Code</b></i></u></p>

```
#include <iostream>
#include <cmath>
#include <cstdlib>

#include "uiuc/PNG.h"
#include "uiuc/HSLAPixel.h"
#include "ImageTransform.h"

/* ******************
(Begin multi-line comment...)
Write your name and email address in the comment space here:
Name:Priyanshu Singh
Email:priyanshu.7068183126@gmail.com
(...end multi-line comment.)
******************** */

using uiuc::PNG;
using uiuc::HSLAPixel;
/**
 * Returns an image that has been transformed to grayscale.
 *
 * The saturation of every pixel is set to 0, removing any color.
 *
 * @return The grayscale image.
 */
PNG grayscale(PNG image) {
  /// This function is already written for you so you can see how to
  /// interact with our PNG class.
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);

      // `pixel` is a reference to the memory stored inside of the PNG `image`,
      // which means you're changing the image directly. No need to `set`
      // the pixel since you're directly changing the memory of the image.
      pixel.s = 0;
    }
  }

  return image;
}



/**
 * Returns an image with a spotlight centered at (`centerX`, `centerY`).
 *
 * A spotlight adjusts the luminance of a pixel based on the distance the pixel
 * is away from the center by decreasing the luminance by 0.5% per 1 pixel euclidean
 * distance away from the center.
 *
 * For example, a pixel 3 pixels above and 4 pixels to the right of the center
 * is a total of `sqrt((3 * 3) + (4 * 4)) = sqrt(25) = 5` pixels away and
 * its luminance is decreased by 2.5% (0.975x its original value).  At a
 * distance over 160 pixels away, the luminance will always decreased by 80%.
 * 
 * The modified PNG is then returned.
 *
 * @param image A PNG object which holds the image data to be modified.
 * @param centerX The center x coordinate of the crosshair which is to be drawn.
 * @param centerY The center y coordinate of the crosshair which is to be drawn.
 *
 * @return The image with a spotlight.
 */
 PNG createSpotlight(PNG image, int centerX, int centerY) {

   for (unsigned x = 0; x < image.width(); x++) {
     for (unsigned y = 0; y < image.height(); y++) {
       HSLAPixel & pixel = image.getPixel(x, y);
       double distance = sqrt( (x - centerX) * (x - centerX) + (y - centerY) * (y - centerY));
       if (distance < 160) {
         double keep = 1 - 0.5 * distance / 100;
         pixel.l = pixel.l * keep;
       } else {
         pixel.l = pixel.l * 0.2;
       }
     }
   }

   return image;

 }
 

/**
 * Returns a image transformed to Illini colors.
 *
 * The hue of every pixel is set to the a hue value of either orange or
 * blue, based on if the pixel's hue value is closer to orange than blue.
 *
 * @param image A PNG object which holds the image data to be modified.
 *
 * @return The illinify'd image.
**/
PNG illinify(PNG image) {
  int illini_orange_hue = 11;
  int illini_blue_hue = 216;

  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {

      HSLAPixel & pixel = image.getPixel(x, y);

      if (pixel.h < illini_blue_hue && pixel.h > illini_orange_hue) {

        if ( illini_blue_hue - pixel.h < pixel.h - illini_orange_hue ) {
          pixel.h = illini_blue_hue;
        } else {
          pixel.h = illini_orange_hue;
        }
      }

      else if (pixel.h < 360 && pixel.h > illini_blue_hue) {
        int dist_blue = pixel.h - illini_blue_hue;
        int dist_orge = 360 - pixel.h + illini_orange_hue;

        if (dist_blue < dist_orge) {
          pixel.h = illini_blue_hue;
        } else {
          pixel.h = illini_orange_hue;
        }
      }

      else {
        pixel.h = illini_orange_hue;
      }

    }
  }

  return image;
}
 
/**
* Returns an immge that has been watermarked by another image.
*
* The luminance of every pixel of the second image is checked, if that
* pixel's luminance is 1 (100%), then the pixel at the same location on
* the first image has its luminance increased by 0.2.
*
* @param firstImage  The first of the two PNGs, which is the base image.
* @param secondImage The second of the two PNGs, which acts as the stencil.
*
* @return The watermarked image.
*/
PNG watermark(PNG firstImage, PNG secondImage) {

  for (unsigned x = 0; x < firstImage.width(); x++) {
    for (unsigned y = 0; y < firstImage.height(); y++) {
      HSLAPixel & pixelFirst = firstImage.getPixel(x, y);
      HSLAPixel & pixelSecond = secondImage.getPixel(x, y);

      if (pixelSecond.l == 1) {
        if (pixelFirst.l + 0.2 <= 1) {
          pixelFirst.l = pixelFirst.l + 0.2;
        } else {
          pixelFirst.l = 1;
        }
      }

    }
  }

  return firstImage;
}
```
