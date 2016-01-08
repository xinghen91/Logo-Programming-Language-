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

#include "Structs.h"
#include "Moving.h"

//Moves the x position and y position of the turtle forward
void forward (turtleProperties * tempTurtle, moving * dir)
{
    int maxX;
    int maxY;
    
    getmaxyx(stdscr, maxY, maxX);
    maxY --;
    maxX --;
    
    /*Using the cast rule and trig, i approimated the distances for the turtle
     to move in the x and y direction depending on the angle*/
    if (tempTurtle->theta == 0)
    {
        tempTurtle->xpos = tempTurtle->xpos + tempTurtle->move;
        *dir = right;
    }
    else if (tempTurtle->theta == M_PI / 2)
    {
        tempTurtle->ypos = tempTurtle->ypos - tempTurtle->move;
        *dir = up;
    }
    else if (tempTurtle->theta == M_PI)
    {
        tempTurtle->xpos = tempTurtle->xpos - tempTurtle->move;
        *dir = left;
    }
    else if (tempTurtle->theta == 3 * M_PI / 2)
    {
        tempTurtle->ypos = tempTurtle->ypos + tempTurtle->move;
        *dir = down;
    }
    else if (tempTurtle->theta == M_PI / 4)
    {
        tempTurtle->ypos = tempTurtle->ypos - tempTurtle->move * sin(M_PI / 4);
        tempTurtle->xpos = tempTurtle->xpos + tempTurtle->move * sin(M_PI / 4);
        *dir = upRight;
    }
    else if (tempTurtle->theta == 5 * M_PI / 4)
    {
        tempTurtle->ypos = tempTurtle->ypos + tempTurtle->move * sin(M_PI / 4);
        tempTurtle->xpos = tempTurtle->xpos - tempTurtle->move * sin(M_PI / 4);
        *dir = downLeft;
    }
    else if (tempTurtle->theta == 3 * M_PI / 4)
    {
        tempTurtle->ypos = tempTurtle->ypos - tempTurtle->move * sin(M_PI / 4);
        tempTurtle->xpos = tempTurtle->xpos - tempTurtle->move * sin(M_PI / 4);
        *dir = upLeft;
    }
    else if (tempTurtle->theta == 7 * M_PI / 4)
    {
        tempTurtle->ypos = tempTurtle->ypos + tempTurtle->move * sin(M_PI / 4);
        tempTurtle->xpos = tempTurtle->xpos + tempTurtle->move * sin(M_PI / 4);
        *dir = downRight;
    }
    else if (tempTurtle->theta > 0 && tempTurtle->theta < M_PI / 4)
    {
        tempTurtle->ypos = tempTurtle->ypos - tempTurtle->move * sin(tempTurtle->theta);
        tempTurtle->xpos = tempTurtle->xpos + tempTurtle->move * cos(tempTurtle->theta);
        *dir = upRight;
    }
    else if (tempTurtle->theta > 3 * M_PI / 4 && tempTurtle->theta < M_PI)
    {
        tempTurtle->ypos = tempTurtle->ypos - tempTurtle->move * sin(tempTurtle->theta);
        tempTurtle->xpos = tempTurtle->xpos + tempTurtle->move * cos(tempTurtle->theta);
        *dir = upLeft;
    }
    else if (tempTurtle->theta > M_PI && tempTurtle->theta < 5 * M_PI / 4)
    {
        tempTurtle->ypos = tempTurtle->ypos - tempTurtle->move * sin(tempTurtle->theta);
        tempTurtle->xpos = tempTurtle->xpos + tempTurtle->move * cos(tempTurtle->theta);
        *dir = downLeft;
    }
    else if (tempTurtle->theta > 7 * M_PI/4 && tempTurtle->theta < 2 * M_PI)
    {
        tempTurtle->ypos = tempTurtle->ypos - tempTurtle->move * sin(tempTurtle->theta);
        tempTurtle->xpos = tempTurtle->xpos + tempTurtle->move * cos(tempTurtle->theta);
        *dir = downRight;
    }
    else if (tempTurtle->theta > M_PI / 4 && tempTurtle->theta < M_PI / 2)
    {
        tempTurtle->ypos = tempTurtle->ypos - tempTurtle->move * cos(tempTurtle->theta);
        tempTurtle->xpos = tempTurtle->xpos + tempTurtle->move * sin(tempTurtle->theta);
        *dir = upRight;
    }
    else if (tempTurtle->theta > 5 * M_PI / 4 && tempTurtle->theta < 3 * M_PI / 2)
    {
        tempTurtle->ypos = tempTurtle->ypos - tempTurtle->move * cos(tempTurtle->theta);
        tempTurtle->xpos = tempTurtle->xpos + tempTurtle->move * sin(tempTurtle->theta);
        *dir = downRight;
    }
    else if (tempTurtle->theta > M_PI / 2 && tempTurtle->theta < 3 * M_PI / 4)
    {
        tempTurtle->ypos = tempTurtle->ypos + tempTurtle->move * cos(tempTurtle->theta);
        tempTurtle->xpos = tempTurtle->xpos - tempTurtle->move * sin(tempTurtle->theta);
        *dir = upLeft;
    }
    else if (tempTurtle->theta > 3 * M_PI  /2 && tempTurtle->theta <= 7 * M_PI / 4)
    {
        tempTurtle->ypos = tempTurtle->ypos + tempTurtle->move * cos(tempTurtle->theta);
        tempTurtle->xpos = tempTurtle->xpos - tempTurtle->move * sin(tempTurtle->theta);
        *dir = downRight;
    }
    //Boundries
    else if (tempTurtle->ypos < 7 || tempTurtle->ypos > maxY-2 || tempTurtle->xpos < 3 || tempTurtle->xpos > maxX - 3)
    {
        mvprintw(1, 0, "You have reached the boundry");
        
        if (*dir == up)
        {
            tempTurtle->ypos = 7;
        }
        else if (*dir == down)
        {
            tempTurtle->ypos = maxY - 2;
        }
        else if (*dir == right)
        {
            tempTurtle->xpos = maxX - 3;
        }
        else if (*dir == left)
        {
            tempTurtle->xpos = 3;
        }
        else if (*dir == upRight)
        {
            tempTurtle->ypos = tempTurtle->ypos + 1;
        }
        else if (*dir == upLeft)
        {
            tempTurtle->ypos = tempTurtle->ypos + 1;
        }
        else if (*dir == downRight)
        {
            tempTurtle->xpos = tempTurtle->xpos - 1;
        }
        else if (*dir == downLeft)
        {
            tempTurtle->xpos = tempTurtle->xpos - 1;
        }
    }
}

//Moves the x position and y position of the turtle backward
void backward (turtleProperties * tempTurtle, moving * dir)
{
    int maxX;
    int maxY;
    
    getmaxyx(stdscr, maxY, maxX);
    maxY --;
    maxX --;
    
    if (tempTurtle->theta == 0)
    {
        tempTurtle->xpos = tempTurtle->xpos - tempTurtle->move;
        *dir = left;
    }
    else if (tempTurtle->theta == M_PI / 2)
    {
        tempTurtle->ypos = tempTurtle->ypos + tempTurtle->move;
        *dir = down;
    }
    else if (tempTurtle->theta == M_PI)
    {
        tempTurtle->xpos = tempTurtle->xpos + tempTurtle->move;
        *dir = right;
    }
    else if (tempTurtle->theta == 3 * M_PI / 2)
    {
        tempTurtle->ypos = tempTurtle->ypos - tempTurtle->move;
        *dir = up;
    }
    else if (tempTurtle->theta == M_PI / 4)
    {
        tempTurtle->ypos = tempTurtle->ypos + tempTurtle->move * sin(M_PI / 4);
        tempTurtle->xpos = tempTurtle->xpos - tempTurtle->move * sin(M_PI / 4);
        *dir = downLeft;
    }
    else if (tempTurtle->theta == 5 * M_PI / 4)
    {
        tempTurtle->ypos = tempTurtle->ypos - tempTurtle->move * sin(M_PI / 4);
        tempTurtle->xpos = tempTurtle->xpos + tempTurtle->move * sin(M_PI / 4);
        *dir = upRight;
    }
    else if (tempTurtle->theta == 3 * M_PI / 4)
    {
        tempTurtle->ypos = tempTurtle->ypos + tempTurtle->move * sin(M_PI/4);
        tempTurtle->xpos = tempTurtle->xpos + tempTurtle->move * sin(M_PI/4);
        *dir = downRight;
    }
    else if (tempTurtle->theta == 7 * M_PI / 4)
    {
        tempTurtle->ypos = tempTurtle->ypos - tempTurtle->move * sin(M_PI / 4);
        tempTurtle->xpos = tempTurtle->xpos - tempTurtle->move * sin(M_PI / 4);
        *dir = upLeft;
    }
    else if (tempTurtle->theta > 0 && tempTurtle->theta < M_PI / 4)
    {
        tempTurtle->ypos = tempTurtle->ypos + tempTurtle->move * sin(tempTurtle->theta);
        tempTurtle->xpos = tempTurtle->xpos - tempTurtle->move * cos(tempTurtle->theta);
        *dir = downLeft;
    }
    else if (tempTurtle->theta > 3 * M_PI / 4 && tempTurtle->theta < M_PI)
    {
        tempTurtle->ypos = tempTurtle->ypos + tempTurtle->move * sin(tempTurtle->theta);
        tempTurtle->xpos = tempTurtle->xpos - tempTurtle->move * cos(tempTurtle->theta);
        *dir = downRight;
    }
    else if (tempTurtle->theta > M_PI && tempTurtle->theta < 5 * M_PI/4)
    {
        tempTurtle->ypos = tempTurtle->ypos - tempTurtle->move * sin(tempTurtle->theta);
        tempTurtle->xpos = tempTurtle->xpos + tempTurtle->move * cos(tempTurtle->theta);
        *dir = upRight;
    }
    else if (tempTurtle->theta > 7 * M_PI / 4 && tempTurtle->theta < 2 * M_PI)
    {
        tempTurtle->ypos = tempTurtle->ypos + tempTurtle->move * sin(tempTurtle->theta);
        tempTurtle->xpos = tempTurtle->xpos - tempTurtle->move * cos(tempTurtle->theta);
        *dir = upLeft;
    }
    else if (tempTurtle->theta > M_PI / 4 && tempTurtle->theta < M_PI / 2)
    {
        tempTurtle->ypos = tempTurtle->ypos + tempTurtle->move * cos(tempTurtle->theta);
        tempTurtle->xpos = tempTurtle->xpos - tempTurtle->move * sin(tempTurtle->theta);
        *dir = downLeft;
    }
    else if (tempTurtle->theta > 5 * M_PI / 4 && tempTurtle->theta < 3 * M_PI / 2)
    {
        tempTurtle->ypos = tempTurtle->ypos + tempTurtle->move * cos(tempTurtle->theta);
        tempTurtle->xpos = tempTurtle->xpos - tempTurtle->move * sin(tempTurtle->theta);
        *dir = upLeft;
    }
    else if (tempTurtle->theta > M_PI / 2 && tempTurtle->theta < 3 * M_PI / 4)
    {
        tempTurtle->ypos = tempTurtle->ypos - tempTurtle->move * cos(tempTurtle->theta);
        tempTurtle->xpos = tempTurtle->xpos + tempTurtle->move * sin(tempTurtle->theta);
        *dir = downRight;
    }
    else if (tempTurtle->theta > 3 * M_PI / 2 && tempTurtle->theta <= 7 * M_PI / 4)
    {
        tempTurtle->ypos = tempTurtle->ypos - tempTurtle->move * cos(tempTurtle->theta);
        tempTurtle->xpos = tempTurtle->xpos + tempTurtle->move * sin(tempTurtle->theta);
        *dir = upLeft;
    }
    //Boundries
    else if (tempTurtle->ypos < 7 || tempTurtle->ypos > maxY-2 || tempTurtle->xpos < 3 || tempTurtle->xpos > maxX - 3)
    {
        mvprintw(1, 0, "You have reached the boundry");
        
        if (*dir == up)
        {
            tempTurtle->ypos = 7;
        }
        else if (*dir == down)
        {
            tempTurtle->ypos = maxY - 2;
        }
        else if (*dir == right)
        {
            tempTurtle->xpos = maxX - 3;
        }
        else if (*dir == left)
        {
            tempTurtle->xpos = 3;
        }
        else if (*dir == upRight)
        {
            tempTurtle->ypos = tempTurtle->ypos + 1;
        }
        else if (*dir == upLeft)
        {
            tempTurtle->ypos = tempTurtle->ypos + 1;
        }
        else if (*dir == downRight)
        {
            tempTurtle->xpos = tempTurtle->xpos - 1;
        }
        else if (*dir == downLeft)
        {
            tempTurtle->xpos = tempTurtle->xpos - 1;
        }
    }
}

//Rotates the current angle clockwise around the unit circle
void Right (double * angle)
{
    clearInput();
    
    if (*angle == 360)
    {
        *angle = 0;
    }
    else if (*angle < 0)
    {
        *angle = 360 + *angle;
    }
    else if (*angle > 360)
    {
        *angle = *angle - 360;
    }
    
    *angle = *angle * M_PI / 180;
}

//Rotates the current angle counter-clockwise around the unit circle
void Left (double * angle)
{
    clearInput();
    
    if (*angle == 360)
    {
        *angle = 0;
    }
    else if (*angle > 360)
    {
        *angle = *angle - 360;
    }
    else if (*angle < 0)
    {
        *angle = 360 - *angle;
    }
    
    *angle = *angle * M_PI / 180;
}
