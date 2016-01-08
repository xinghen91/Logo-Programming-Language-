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

#include "Main.h"
#include "Structs.h"

int main()
{
    //ncurses initialization
    initscr();
    cbreak();
    noecho();
    start_color();
    refresh();
    
    //Color Pairs
    init_pair (1, blue, blue);
    init_pair (2, blue, black);
    init_pair (3, red, red);
    init_pair (4, green, green);
    init_pair (5, black, black);
    init_pair (6, yellow, yellow);
    init_pair (7, blue, black);
    
    output();
    
    refresh();
    endwin();
    return 0;
}
