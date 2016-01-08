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

#ifndef _Structs_
#define _Structs_

typedef enum myColors
{
    black = 0,
    red = 1,
    green = 2,
    blue = 4,
    white = 7,
    yellow = 3
}color;

typedef enum boolean
{
    True = 1,
    False = 0
}boolean;

typedef enum moving
{
    none = 0,
    up = 1,
    down = 2,
    right = 3,
    left = 4,
    upRight = 5,
    upLeft = 6,
    downRight = 7,
    downLeft = 8
}moving;

typedef struct turtleProperties
{
    int xpos;
    int ypos;
    int move;
    double theta;
}turtleProperties;

#endif
