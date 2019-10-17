#!/usr/bin/python3
""" Binarize Image

DESCRIPTION/CONTEXT
-------------------
My friend didn't have a scanner so I helped him grayscale and apply
thresholding to a camera picture of his document to give it the apperance of
a scanned image.

Written in python2.7
- Dependecies - OpenCV

INPUTS
-----
image path

OUTPUTS
-------
b/w images in ./temp-[IMAGENAME]

RUN
---
    $ ls
    binarize_image.py  image1.jpg image2.JPH
    $ python binarize_image.py image1.JPG image2.JPG

TO DO
-----
This script still adds a little bit of noise to the final image.

"""
import os
import sys
import numpy as np
import cv2

def binarize_image(paths):
    images = [cv2.imread(path, 0) for path in paths]
    R1 = np.arange(3, 13, 2)
    R2 = np.arange(3, 11, 1)
    ii = 0

    for ii, img in enumerate(images):
        temp_dir_path = "./temp-"+str(img)
        os.mkdir(temp_dir_path)
        for r1 in R1:
            for r2 in R2:
                bin_img = cv2.adaptiveThreshold(img, 255,
                                                cv2.ADAPTIVE_THRESH_GAUSSIAN_C,
                                                cv2.THRESH_BINARY, r1, r2)
                filename = str(ii)+"-"+str(r1)+"-"+str(r2)+".png"
                filepath = os.path.join(temp_dir_path, filename)
                cv2.imwrite(filepath, bin_img)

if __name__ == "__main__":
    paths = ["./"+str(x) for x in sys.argv if x != "binarize_image.py"]
    binarize_image(paths)
