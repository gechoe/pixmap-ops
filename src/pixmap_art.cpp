#include <iostream>
#include "image.h"
using namespace std;
using namespace agl;

int main(int argc, char** argv)
{
   // todo: make at least one artwork!
   Image done;
   if (!done.load("../images/angelBear.png")) {
      std::cout << "ERROR: Cannot load image! Exiting...\n";
      exit(0);
   }
   done = done.swirl();
   done.save("feep-swirl.png"); // should match original

   // test a non-trivial image
   Image image;
   if (!image.load("../images/lineFriends.png")) {
      std::cout << "ERROR: Cannot load image! Exiting...\n";
      exit(0);
   }

   // Image resize = image.swirl();
   // Image resize = image.invert();
   image.save("earth-swirl.png");

   return 0;
}