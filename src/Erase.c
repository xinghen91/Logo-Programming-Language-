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
#include "Erase.h"

//Clears the space from the user input to the boarder
void clearInput ()
{
    int maxX;
    int maxY;
    int i;
    int j;
    
    getmaxyx(stdscr, maxY, maxX);
    maxX --;
    maxY --;
    i = 0;
    j = 0;
    
    attron (COLOR_PAIR (5));
    for (j = 0; j < 1; j ++)
    {
        for (i = 0; i <= maxX; i ++)
        {
            mvaddch (j, i, ' ');
        }
    }
    attroff (COLOR_PAIR (5));
    
    attron (COLOR_PAIR (5));
    for (j = 3; j < 5; j ++)
    {
        for (i = 0; i <= maxX; i ++)
        {
            mvaddch (j, i, ' ');
        }
    }
    attroff (COLOR_PAIR (5));
    
    refresh();
}

//Clears the turtle, so it moves
void clearTurtle ()
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
    
    attron (COLOR_PAIR (5));
    for (j = 5; j <= maxY; j ++)
    {
        for (i = 0; i <= maxX; i ++)
        {
            if ((mvinch(j, i)&A_CHARTEXT) == 't' && (mvinch(j,i)&A_COLOR) == COLOR_PAIR (4))
            {
                mvaddch (j, i, ' ');
            }
        }
    }
    attroff (COLOR_PAIR (5));
    
    drawBoarder();
    refresh();
}

//Erases all of the drawn lines
void clean ()
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
    
    attron (COLOR_PAIR (5));
    for (j = 5; j <= maxY; j ++)
    {
        for (i = 0; i <= maxX; i ++)
        {
            mvaddch (j, i, ' ');
        }
    }
    attroff (COLOR_PAIR (5));
    
    drawBoarder();
    refresh();
}
