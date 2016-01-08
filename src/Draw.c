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
#include "Draw.h"

//Draws the turtle at the given x and y position
void drawTurtle (turtleProperties * tempTurtle, moving * dir)
{
    int maxX;
    int maxY;
    int cursorX;
    int cursorY;
    int i;
    int j;
    
    getmaxyx(stdscr, maxY, maxX);
    maxY --;
    maxX --;
    cursorX = -1;
    cursorY = -1;
    i = 0;
    j = 0;
    
    clearTurtle();
    
    /*Because of the shape of the turtle and lines I changed
     where the cursor would draw the turtle depending on the
     turtle's direction*/
    if (*dir == up)
    {
        cursorX = -1;
        cursorY = -1;
    }
    else if (*dir == down)
    {
        cursorX = -1;
        cursorY = 0;
    }
    else if (*dir == right)
    {
        cursorX = 0;
        cursorY = -1;
    }
    else if (*dir == left)
    {
        cursorX = -2;
        cursorY = -1;
    }
    else if (*dir == upRight)
    {
        cursorX = 0;
        cursorY = -1;
    }
    else if (*dir == upLeft)
    {
        cursorX = -2;
        cursorY = -1;
    }
    else if (*dir == downRight)
    {
        cursorX = 0;
        cursorY = 0;
    }
    else if (*dir == downLeft)
    {
        cursorX = -2;
        cursorY = 0;
    }
    //Boundries
    if (tempTurtle->ypos < 7 || tempTurtle->ypos > maxY-2 || tempTurtle->xpos < 3 || tempTurtle->xpos > maxX - 3)
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
    
    //Draws the turtle
    attron (COLOR_PAIR (4));
    for (i = cursorX; i <= cursorX + 2; i ++)
    {
        for (j = cursorY; j <= cursorY + 1; j ++)
        {
            mvaddch(tempTurtle->ypos + j, tempTurtle->xpos + i, 't');
        }
    }
    attroff (COLOR_PAIR (4));
    
}

//Draws the lines behind the turtle depending on the direction
void pen (turtleProperties * tempTurtle, moving * dir, color c)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    
    attron (COLOR_PAIR (c));
    if (*dir == up)
    {
        for (i = 0; i <= tempTurtle->move; i ++)
        {
            mvaddch(tempTurtle->ypos + i, tempTurtle->xpos, 'x');
        }
    }
    else if (*dir == down)
    {
        for (i = 0; i <= tempTurtle->move; i ++)
        {
            mvaddch(tempTurtle->ypos - i, tempTurtle->xpos, 'x');
        }
    }
    else if (*dir == right)
    {
        for (i = 0; i <= tempTurtle->move; i ++)
        {
            mvaddch(tempTurtle->ypos, tempTurtle->xpos - i, 'x');
        }
    }
    else if (*dir == left)
    {
        for (i = 0; i <= tempTurtle->move; i ++)
        {
            mvaddch(tempTurtle->ypos, tempTurtle->xpos + i, 'x');
        }
    }
    else if (*dir == upRight)
    {
        for (i = 0; i <= tempTurtle->move; i ++)
        {
            mvaddch(tempTurtle->ypos + i, tempTurtle->xpos - i, 'x');
        }
    }
    else if (*dir == upLeft)
    {
        for (i = 0; i <= tempTurtle->move; i ++)
        {
            mvaddch(tempTurtle->ypos + i, tempTurtle->xpos + i, 'x');
        }
    }
    else if (*dir == downRight)
    {
        for (i = 0; i <= tempTurtle->move; i ++)
        {
            mvaddch(tempTurtle->ypos - i, tempTurtle->xpos - i, 'x');
        }
    }
    else if (*dir == downLeft)
    {
        for (i = 0; i <= tempTurtle->move; i ++)
        {
            mvaddch(tempTurtle->ypos - i, tempTurtle->xpos + i, 'x');
        }
    }
    attroff (COLOR_PAIR (c));
}


//This draws the boarder for the game
void drawBoarder ()
{
    int maxX;
    int maxY;
    int i;
    int j;
    
    getmaxyx(stdscr, maxY, maxX);
    maxY --;
    maxX --;
    i = 0;
    j = 0;
    
    mvprintw(0, 0,"Command: ");
    
    attron (COLOR_PAIR (3));
    //Horizontal Rows
    for (i = 0; i <= maxX; i ++)
    {
        mvaddch (5, i, 'o');
        mvaddch (maxY, i, 'o');
    }
    
    //Vertical Coloumns
    for (j = 5; j <= maxY; j ++)
    {
        mvaddch (j, 0, 'o');
        mvaddch (j, maxX, 'o');
    }
    attroff (COLOR_PAIR (3));
    
    refresh ();
}


