   #      Object Oriented Data Structures in C++
   ##                                                                   MP1: Image Transform
   ##                                                      Object-Oriented Data Structures in C++ — Week 4
   ##                                                                   University of Illinois
   
   ## Introduction
By now you've had a chance to learn about basic program structure, classes, and functions in C++. You've also
had a chance to try compiling a few programs and experimenting on the command line. Now it's time to try out
a more free-form coding project in your IDE. At the University of Illinois, programming assignments are fondly
referred to as MPs, although there's some debate about whether that stands for "machine-processed" or
"machine problem." Perhaps a reminder of the days when students had to work out programs on paper and
submit them on punch cards for batch processing by a mainframe in a separate building. You could say this is
your MP1. Coincidentally, you might also prefer to use the Cloud9 IDE to work on your assignment.
In this assignment, you will begin with foundational work that will be used for several future assignments in
this course. Specifically, in Part 1 you will create a simple C++ class that represents a colored pixel; you are
also provided with a PNG image class that encapsulates the loading and saving of image files. (You do not need
to implement the PNG class yourself, but you'll find it enlightening to study the code provided.) In Part 2, you
will use the pixel and PNG classes from Part 1 to transform an image in several different ways

## C++ Environment Setup
Provided with these instructions is a zip file, image-transform-given-files.zip. This file contains everything you
need to get started. However, you need to have your IDE or compiler and terminal pre-configured to begin
work. If you've been following the previous reading lessons, you should already have access to a Linuxcompatible C++ work environment regardless of what your operating system is. If not, please go back and
check out the readings!
Supposing that you are trying out the Cloud9 IDE, we'll show you how to load the files into the workspace. In
the Cloud9 environment you were able to create following the Week 1 readings, make sure you've updated the
compiler first, by typing this command in the terminal:
   ### sudo yum install -y gcc72 gcc72-c++
With that finished, you'll be ready to load the
provided files for this project. In the Cloud9 ![](img.pdf)
interface, if you click **File > Upload Local
Files**, you will see a popup appear that accepts
uploads from your personal computer. You can use this to upload the image-transform-given-files.zip file to
your Cloud9 workspace. After you do so, you'll see that the zip file appears in the environment file listing on the
left of the screen.

        
