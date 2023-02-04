// Copyright 2021, Aline Normoyle, alinen

#include "image.h"

#include <cassert>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

namespace agl {

// Default constructor
Image::Image() {
   widthW = 20;
   heightH = 20;
   pic = new char[widthW * heightH * num_chan];;
}

// Constructor
Image::Image(int width, int height)  {
   widthW = width;
   heightH = height;
   pic = new char[widthW * heightH * num_chan];
}

// Copy constructor
Image::Image(const Image& orig) {
   widthW = orig.widthW;
   heightH = orig.heightH;

   pic = new char[widthW * heightH * num_chan];
   for (int i = 0; i < (widthW * heightH * num_chan); i++) {
      pic[i] = orig.pic[i];
   }
}

// Assignment operator
Image& Image::operator=(const Image& orig) {
   if (&orig == this) {
      return *this;
   }

   widthW = orig.widthW;
   heightH  = orig.heightH;
   
   pic = new char[widthW * heightH * num_chan];
   for (int i = 0; i < (widthW * heightH * num_chan); i++) {
      pic[i] = orig.pic[i];
   }

   return *this;
}

// Destructor
Image::~Image() {
   delete pic;
}

// width
int Image::width() const { 
   return widthW;
}

// height
int Image::height() const {
   return heightH ;
}

// data
char* Image::data() const {
   return pic;
}

// set
void Image::set(int width, int height, unsigned char* data) {
}

// load
// Loads the file with the given name. Returns true if successful; False otherwise.
bool Image::load(const std::string& filename, bool flip) {
   stbi_set_flip_vertically_on_load(flip);

   pic = (char*)stbi_load(filename.c_str(), &widthW, &heightH, &num_chan, des_chan);
   
   if (pic == NULL) {
      printf("Error in loading the image\n");
      return false;
   }

   return true;
}

// save
// Saves the file with the given name. Returns true if successful; False otherwise.
bool Image::save(const std::string& filename, bool flip) const {
   stbi_flip_vertically_on_write(flip);
   return stbi_write_png(filename.c_str(), widthW, heightH, num_chan, pic, widthW * des_chan);
}

// get
// Gets a pixel (value range in [0,255]) at position (row, col).
Pixel Image::get(int row, int col) const {
   unsigned char red = pic[num_chan * (row * widthW + col)];
   unsigned char green =  pic[num_chan * (row * widthW + col) + 1];
   unsigned char blue = pic[num_chan * (row * widthW + col) + 2];

   // Shorthand for making a Pixel instance and adding r, g, and b colors to it.
   return Pixel{red, green, blue};
}

// set
// Sets a pixel (value range in [0,255]) at position (row, col).
void Image::set(int row, int col, const Pixel& color) {
   unsigned char red = color.r;
   unsigned char green = color.g;
   unsigned char blue = color.b;

   pic[num_chan * (row * widthW + col)] = red;
   pic[num_chan * (row * widthW + col) + 1] = green;
   pic[num_chan * (row * widthW + col) + 2] = blue;
}

Pixel Image::get(int i) const
{
   return Pixel{ 0, 0, 0 };
}

void Image::set(int i, const Pixel& c)
{
}

// resize
// Returns a copy of the imaged resized to the given width and height.
Image Image::resize(int w, int h) const {
   Image result(w, h);
   int locR, locC;
   float proportionR, proportionC;

   for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
         proportionR = (i / ((float)(h - 1))) * (float)(heightH - 1);
         proportionC = (j / ((float)(w - 1))) * (float)(widthW - 1);
         locR = floor(proportionR);
         locC = floor(proportionC);

         Pixel pix = get(locR, locC);
         result.set(i, j, pix);
      }
   }

   return result;
}

// flipHorizontal
// Returns a copy of the image flipped along the horizontal middle axis.
Image Image::flipHorizontal() const {
   Image result(widthW, heightH);
   int originalH = heightH - 1;

   for (int j = 0; j < widthW; j++) {
      for (int i = 0; i < heightH / 2; i++) {
         Pixel pix = get(i, j);
         Pixel otherPix = get(originalH, j);
         result.set(i, j, otherPix);
         result.set(originalH, j, pix);
         originalH--;
      }
      originalH = heightH - 1;
   }

   return result;
}

Image Image::flipVertical() const {
   Image result(0, 0);
   return result;
}

Image Image::rotate90() const {
   Image result(0, 0);
  
   return result;
}

// subimage
// Returns a sub-image with top,left corner at (x,y) and width and height.
Image Image::subimage(int startx, int starty, int w, int h) const {
   Image sub(w, h);
   int locX, locY;

   for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
         locX = i + startx;
         locY = j + starty;

         Pixel pix = get(locX, locY);
         sub.set(i, j, pix);
      }
   }
   
   return sub;
}

// replace
// Replaces the block of pixels starting at (row, col) with the image. Should not assume image fits on this image.
void Image::replace(const Image& image, int startx, int starty) {
   int imageWLimit = image.width() + startx;
   int imageHLimit = image.height() + starty;

   for (int i = startx; i < imageHLimit; i++) {
      for (int j = starty; j < imageWLimit; j++) {
         Pixel pix = image.get(i, j);
         set(i, j, pix);
      }
   }
}

Image Image::swirl() const {
   Image result(0, 0);
   return result;
}

Image Image::add(const Image& other) const {
   Image result(0, 0);
  
   return result;
}

Image Image::subtract(const Image& other) const {
   Image result(0, 0);
   
   return result;
}

Image Image::multiply(const Image& other) const {
   Image result(0, 0);
   
   return result;
}

Image Image::difference(const Image& other) const {
   Image result(0, 0);
  
   return result;
}

Image Image::lightest(const Image& other) const {
   Image result(0, 0);
  
   return result;
}

Image Image::darkest(const Image& other) const {
   Image result(0, 0);
  
   return result;
}

// gammaCorrect
// Returns a copy of this image with the given gamma correction factor applied to it.
Image Image::gammaCorrect(float gamma) const {
   Image result(widthW, heightH);

   for (int i = 0; i < heightH; i++) {
      for (int j = 0; j < widthW; j++) {
         Pixel pix = get(i, j);

         // Finds the gamma exponent value
         float gammaExp = 1 / gamma;

         // Uses gamma as a correction factor for red, green, and blue
         float gammaRed = pow(((float)pix.r / 255), gammaExp);
         float gammaGreen = pow(((float)pix.g / 255), gammaExp);
         float gammaBlue = pow(((float)pix.b / 255), gammaExp);

         // Scales back to pixel color range for pixel intensity by multiplying by max intensity (255)
         pix.r = gammaRed * 255;
         pix.g = gammaGreen * 255;
         pix.b = gammaBlue * 255;
         
         result.set(i, j, pix);
      }
   }
 
   return result;
}

// alphaBlend
// Returns a copy of this image with the other image blended with it by factor alpha. E.g. result.pixel = this.pixel * (1 - alpha) + other.pixel * alpha. Assumes other and this have the same dimensions.
Image Image::alphaBlend(const Image& other, float alpha) const {
   Image result(widthW, heightH);

   for (int i = 0; i < heightH; i++) {
      for (int j = 0; j < widthW; j++) {
         Pixel thisPix = get(i, j);
         Pixel otherPix = other.get(i, j);
         thisPix.r = ((float)thisPix.r * (1 - alpha)) + ((float)otherPix.r * alpha);
         thisPix.g = ((float)thisPix.g * (1 - alpha)) + ((float)otherPix.g * alpha);
         thisPix.b = ((float)thisPix.b * (1 - alpha)) + ((float)otherPix.b * alpha);

         result.set(i, j, thisPix);
      }
   }

   return result;
}

Image Image::invert() const {
   Image image(0, 0);
   
   return image;
}

// grayscale
// Returns a copy of this image as a grayscale image.
Image Image::grayscale() const {
   Image result(widthW, heightH);

   for (int i = 0; i < heightH; i++) {
      for (int j = 0; j < widthW; j++) {
         Pixel pix = get(i, j);

         float average = (pix.r * 0.3) + (pix.g * 0.59) + (pix.b * 0.11);
         pix.r = average, pix.g = average, pix.b = average;
         
         result.set(i, j, pix);
      }
   }
   
   return result;
}

Image Image::colorJitter(int size) const {
   Image image(0, 0);
  
   return image;
}

Image Image::bitmap(int size) const {
   Image image(0, 0);
   
   return image;
}

void Image::fill(const Pixel& c) {
  }

}  // namespace agl

