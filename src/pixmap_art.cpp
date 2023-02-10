#include <iostream>
#include "image.h"
using namespace std;
using namespace agl;

int main(int argc, char** argv)
{
   // todo: make at least one artwork!
   Image bear;
   if (!bear.load("../images/angelBear.png")) {
      std::cout << "ERROR: Cannot load image! Exiting...\n";
      exit(0);
   }

   Image flowers;
   if (!flowers.load("../images/cuteFlowers.png")) {
      std::cout << "ERROR: Cannot load image! Exiting...\n";
      exit(0);
   }

   Image friends;
   if (!friends.load("../images/lineFriends.png")) {
      std::cout << "ERROR: Cannot load image! Exiting...\n";
      exit(0);
   }

   Image earth;
   if (!earth.load("../images/earth.png")) {
      std::cout << "ERROR: Cannot load image! Exiting...\n";
      exit(0);
   }

   Image squishy;
   if (!squishy.load("../images/squishy.png")) {
      std::cout << "ERROR: Cannot load image! Exiting...\n";
      exit(0);
   }

   Image brick;
   if (!brick.load("../images/bricks.png")) {
      std::cout << "ERROR: Cannot load image! Exiting...\n";
      exit(0);
   }

   Image feep;
   if (!feep.load("../images/feep.png")) {
      std::cout << "ERROR: Cannot load image! Exiting...\n";
      exit(0);
   }

   bear.save("bear-original.png"); // Original bear coloring

   // #1: Inverts bear image colors
   Image bearInvert = bear.invert();
   bearInvert.save("bear-invert.png");

   // #2: Creates border on image
   Image flowerBorder = flowers.border();
   flowerBorder.save("flowers-border.png");

   // #3: Rotates image 90 degrees to the left
   Image earthRotate = earth.rotate90();
   earthRotate.save("earth-rotate90.png");

   // #4: Colors image with TV disconnection colors
   Image squishyTV = squishy.tvcolors();
   squishyTV.save("squishy-tv-colors.png");

   // #5: Swirls image's colors
   Image bearSwirl = bear.swirl();
   bearSwirl.save("bear-swirl.png");

   // #6: Texturizes bricks images
   Image brickTexture = brick.grainyEffect();
   brickTexture.save("brick-texturized.png");

   // #7: Testing colors by extracting red, blue, green
   Image friendsER = friends.extractRed();
   friendsER.save("friends-extract-red.png");
   Image friendsEG = friends.extractGreen();
   friendsEG.save("friends-extract-green.png");
   Image friendsEB = friends.extractBlue();
   friendsEB.save("friends-extract-blue.png");

   // #8: Testing colors by keeping only red, only green, only blue
   Image friendsOR = friends.onlyRed();
   friendsOR.save("friends-only-red.png");
   Image friendsOG = friends.onlyGreen();
   friendsOG.save("friends-only-green.png");
   Image friendsOB = friends.onlyBlue();
   friendsOB.save("friends-only-blue.png");

   // #9: Testing colors by dyeing image with red, green, and blue with hints of
   // other color underneath
   Image earthRedDye = earth.redDyePrint();
   earthRedDye.save("earth-red-dye.png");
   Image earthGreenDye = earth.greenDyePrint();
   earthGreenDye.save("earth-green-dye.png");
   Image earthBlueDye = earth.blueDyePrint();
   earthBlueDye.save("earth-blue-dye.png");

   // TV colors again but on earth image
   Image earthTV = earth.tvcolors();
   earthTV.save("earth-tv-colors.png");

   // #10: Applying darkest, lightest, difference, multiply, subtract, and
   // add on image onto itself
   Image feepDarkest = feep.darkest(feep);
   feepDarkest.save("feep-darkest.png");
   Image feepLightest = feep.lightest(feep);
   feepLightest.save("feep-lightest.png");
   Image feepDifference = feep.difference(feep);
   feepDifference.save("feep-difference.png");
   Image feepMultiply = feep.multiply(feep);
   feepMultiply.save("feep-multiply.png");
   Image feepSubtract = feep.subtract(feep);
   feepDifference.save("feep-subtract.png");
   Image feepAdd = feep.add(feep);
   feepAdd.save("feep-add.png");

   return 0;
}