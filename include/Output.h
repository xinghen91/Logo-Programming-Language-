/**************************************************************************
 Student Name: Nick Major                Student Number: 0879292
 Date: 02/13/14                          Course Name: cis2500
 
 I have exclusive control over this submission via my password.
 By including this statement in this header comment, I certify that:
      1) I have read and understood the University policy on academic integrity;
      2) I have completed the Computing with Integrity Tutorial on Moodle; and
      3) I have achieved at least 80% in the Computing with Integrity Self Test.
 I assert that this work is my own. I have appropriately acknowledged any and all material
 (data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
 Furthermore, I certify that this assignment was prepared by me specifically for this course.
 ****************************************************************************/
#ifndef __Output__
#define __Output__

#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include <curses.h>
#include <math.h>

//All of the commands are dealt with
void output();

//Moves the x position and y position of the turtle forward
void forward(turtleProperties * tempTurtle, moving * dir);

//Moves the x position and y position of the turtle backward
void backward(turtleProperties * tempTurtle, moving * dir);

//Moves the angle clockwise around the unit circle
void Right(double * angle);
void Left(double * angle);

//Draws the boarder for the screen
void drawBoarder();

//Draws the turtle
void drawTurtle(turtleProperties * tempTurtle, moving * dir);

//Draws the pen lines behind the turtle
void pen(turtleProperties * tempTurtle, moving * dir, color c);

//Clears the turtle for drawing
void clearTurtle();

//Erases of the user's previous input
void clearInput();

//Erases all of the pen lines
void clean();

void commands (char command[11], char input[11], turtleProperties * turtle, moving * direction, boolean * penDown, boolean * showTurtle, color * colorPen);

#endif
