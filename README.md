# pixmap-ops

Image manipulation demos based on the PPM image format.

TODO: Add a representative image for your project here

Representative Image - TV Buffering Colors on Earth:
![Image_1](images/earth-tv-colors.png)

## How to build

*Windows*

Open git bash to the directory containing this repository.

```
pixmap-ops $ mkdir build
pixmap-ops $ cd build
pixmap-ops/build $ cmake -G "Visual Studio 17 2022" ..
pixmap-ops/build $ start pixmap-ops.sln
```

Your solution file should contain two projects: `pixmap_art` and `pixmap_test`.
To run from the git bash command shell, 

```
pixmap-ops/build $ ../bin/Debug/pixmap_test
pixmap-ops/build $ ../bin/Debug/pixmap_art
```

*macOS*

Open terminal to the directory containing this repository.

```
pixmap-ops $ mkdir build
pixmap-ops $ cd build
pixmap-ops/build $ cmake ..
pixmap-ops/build $ make
```

To run each program from build, you would type

```
pixmap-ops/build $ ../bin/pixmap_test
pixmap-ops/build $ ../bin/pixmap_art
```

## Image operators

TODO: Document the features of your png image class here. Include example images.

Features:
1. resize - resizes the image:                                
![Image_1](images/earth-200-300.png)

2. flipHorizontal - flips the image along the horizontal line:  
![Image_2](images/earth-flip.png)

3. flipVertical - flips the image along the vertical line:  
![Image_3](images/earth-vertical-flip.png)

4. rotate90 - rotates the image 90 degrees to the left:  
![Image_4](images/earth-rotate90.png)

5. subimage - returns subimage of image at specified location:  
![Image_5](images/earth-subimage.png)

6. replace - replaces the image at specified spot with another image:  
![Image_6](images/earth-blend-0.5.png)

7. swirl - swirls the pixel colors in an image:     
![Image_7](images/bear-swirl.png)

8. add - adds the pixel colors of two images:                                 
![Image_8](images/feep-add.png)

9. subtract - subtracts the pixel colors of two images:                         
![Image_9](images/feep-subtract.png)

10. multiply - multiplies the pixel colors of two images:                              
![Image_10](images/feep-subtract.png)

11. difference - find the abs difference of the pixel colors of two images:                          
![Image_11](images/feep-difference.png)

12. lightest - gets the max pixel colors of two images:                            
![Image_12](images/feep-lightest.png)

13. darkest - gets the min pixel colors of two images:                            
![Image_13](images/feep-darkest.png)

14. gammaCorrect - gammaCorrection is applied to the image:
![Image_14.1](images/earth-gamma-0.6.png)
![Image_14.2](images/earth-gamma-2.2.png)  

15. alphaBlend - blends image with another image by an alpha factor:
![Image_15](images/earth-blend-0.5.png)  

16. invert - inverts the colors of the image:
![Image_16](images/bear-invert.png)

17. grayscale - grayscales the image's pixel colors:
![Image_17](images/earth-grayscale.png)

18. exrtractRed - extracts only the red color channel:
![Image_18](images/friends-extract-red.png)

19. exrtractGreen - extracts only the green color channel:
![Image_19](images/friends-extract-green.png)

20. exrtractBlue - extracts only the blue color channel:
![Image_20](images/friends-extract-blue.png)

21. onlyRed - keeps only the red color channel:
![Image_21](images/friends-only-red.png)

22. onlyGreen - keeps only the green color channel:
![Image_22](images/friends-only-green.png)

23. onlyBlue - keeps only the blue color channel:
![Image_23](images/friends-only-blue.png)

24. border - creates a border around the image:
![Image_24](images/flowers-border.png)

25. grainyEffect - creates a texturized image (made specifically for brick image):  
![Image_25](images/brick-texturized.png)

26. tvcolors - overlays tv buffering colors onto the image:
![Image_26.1](images/earth-tv-colors.png)
![Image_26.2](images/squishy-tv-colors.png)

## Results 

TODO: Show artworks using your class

