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
#include "Output.h"

void output()
{
    //Declarations and initializations
    FILE * file;
    FILE * ofile;
    turtleProperties turtle;
    
    int maxX;
    int maxY;
    int homexpos;
    int homeypos;
    int i = 0;
    int k = 0;
    
    char command[150];
    char input[150];
    char buffer[150];
    char commandArray[150][100];
    char inputArray[150][100];
    char * token;
    
    turtle.theta = M_PI/2;
    turtle.move = 0;
    moving direction = up;
    boolean penDown = True;
    boolean showTurtle = True;
    color colorPen;
    getmaxyx(stdscr, maxY, maxX);
    maxY --;
    maxX --;
    homexpos = maxX/2;
    homeypos = maxY/2;
    turtle.xpos = homexpos;
    turtle.ypos = homeypos;
    boolean playing = True;
    colorPen = 1;
    
    drawBoarder();
    
    cbreak();
    echo();
    
    drawTurtle(&turtle, &direction);
    
    //Returns if the user's window size is too small
    if (maxX < 20 || maxY < 20)
    {
        mvprintw(1, 0, "**You should consider resizing your window**");
    }
    
    //Loop for the program
    while (playing == True && k < 100)
    {
        mvprintw(3, maxX - 25, "Current Angle: %0.2f", turtle.theta * 180 / M_PI);  //converts to degress
        
        //gets user input
        mvprintw(0, 0, "Command:");
        move (0,9);
        scanw("%s %s", &command, &input);
        
        //creates an array for the commands and input
        if ((command[0] != 'o' && command[1] != 'p' && command[2] != 'e' && command[3] != 'n') || (command[0] != 's' && command[1] != 'a' && command[2] != 'v' && command[3] != 'e') || (command[0] != 'n' && command[1] != 'e' && command[2] != 'w'))
        {
            strcpy(commandArray[k], command);
            strcpy(inputArray[k], input);
        }
        
        commands(command, input, &turtle, &direction, &penDown, &showTurtle, &colorPen);
        
        //Resets the program
        if (command[0] == 'n' && command[1] == 'e' && command[2] == 'w')
        {
            clearTurtle();
            clean();
            showTurtle = True;
            penDown = True;
            turtle.xpos = homexpos;
            turtle.ypos = homeypos;
            turtle.theta = M_PI / 2;
            turtle.move = 0;
            colorPen = 1;
            direction = up;
            
            drawTurtle (&turtle, &direction);
            
            for (i = 0; i < k; i ++)
            {
                for (int j = 0; j < 150; j ++)
                {
                    commandArray[j][i] = '\0';
                    inputArray[j][i] = '\0';
                }
            }
            k = 0;
        }
        //Quits the program
        else if (command[0] == 'q')
        {
            playing = False;
            break;
        }
        //Save to file
        else if (command[0] == 's' && command[1] == 'a' && command[2] == 'v' && command[3] == 'e')
        {
            file = fopen(input, "w");
            for (i = 0; i < k; i ++)
            {
                fprintf(file, "%s %s\n", commandArray[i], inputArray[i]);
            }
            fclose(file);
        }
        //Open file
        else if (command[0] == 'o' && command[1] == 'p' && command[2] == 'e' && command[3] == 'n')
        {
            clearTurtle();
            clean();
            showTurtle = True;
            penDown = True;
            turtle.xpos = homexpos;
            turtle.ypos = homeypos;
            turtle.theta = M_PI / 2;
            turtle.move = 0;
            colorPen = 1;
            direction = up;
            
            ofile = fopen(input, "r");
            while (fgets(buffer, sizeof buffer, ofile) != NULL)
            {
                token = strtok(buffer, " ");
                strcpy(command, token);
                token = strtok(NULL, " ");
                strcpy(input, token);
            
                commands(command, input, &turtle, &direction, &penDown, &showTurtle, &colorPen);
            }
        fclose(ofile);
        }
        
        for (i = 0; i < 150; i ++)
        {
            command[i] = '\0';
            input[i] = '\0';
        }
        
        turtle.move = 0;
        clearInput();
        k ++;
        refresh();
    }
}

void commands(char command[150], char input[150], turtleProperties * turtle, moving * direction, boolean * penDown, boolean * showTurtle, color * colorPen)
{
    int maxX;
    int maxY;
    int homexpos;
    int homeypos;

    getmaxyx(stdscr, maxY, maxX);
    maxY --;
    maxX --;
    homexpos = maxX/2;
    homeypos = maxY/2;
    
    //Moves the turtle forward with various conditions
    if (command[0] == 'f' && command[1] == 'd')
    {
        turtle->move = atoi(input);
    
        if (turtle->move > 0)
        {
            forward(&*turtle, &*direction);
        }
        else if (turtle->move < 0)
        {
            mvprintw(1, 0, "No negative moves please");
        }
    
        if (*penDown == True)
        {
            pen(&*turtle, &*direction, *colorPen);
            clearInput();
        }
        
        if (*showTurtle == True)
        {
            drawTurtle (&*turtle, &*direction);
        }
        else if (*showTurtle == False)
        {
            drawTurtle (&*turtle, &*direction);
            clearTurtle();
        }
    }
    //Moves the turtle backward with various conditions
    else if (command[0] == 'b' && command[1] == 'k')
    {
        turtle->move = atoi(input);
    
        if (turtle->move > 0)
        {
            backward(&*turtle, &*direction);
        }
        else if (turtle->move < 0)
        {
            mvprintw(1, 0,"No negative moves please");
        }
    
        if (*penDown == True)
        {
            pen(&*turtle, &*direction, *colorPen);
        }
        if (*showTurtle == True)
        {
            drawTurtle (&*turtle, &*direction);
        }
        else if (*showTurtle == False)
        {
            drawTurtle (&*turtle, &*direction);
            clearTurtle();
        }

    }
    //Changes the current angle clockwise
    else if (command[0] == 'r' && command[1] == 't')
    {
        turtle->theta = turtle->theta - (atoi(input)) * M_PI / 180;
        turtle->theta = turtle->theta * 180 / M_PI;
        Right(&turtle->theta);
    }
    //Changes the current angle counter-clockwise
    else if (command[0] == 'l' && command[1] == 't')
    {
        turtle->theta = turtle->theta + (atoi(input)) * M_PI / 180;
        turtle->theta = turtle->theta*180/M_PI;
        Left(&turtle->theta);
    }
    //The turtle's lines are no longer drawn
    else if (command[0] == 'p' && command[1] == 'u')
    {
        *penDown = False;
    }
    //Turtle lines are drawn
    else if (command[0] == 'p' && command[1] == 'd')
    {
        *penDown = True;
    }
    //Draws the turtle
    else if (command[0] == 's' && command[1] == 't')
    {
        drawTurtle(&*turtle, &*direction);
        *showTurtle = True;
    }
    //Erases the turtle
    else if (command[0] == 'h' && command[1] == 't')
    {
        clearTurtle();
        *showTurtle = False;
    }
    //Resets the turtle's postion
    else if (command[0] == 'h' && command[1] == 'o' && command[2] == 'm' && command[3] == 'e')
    {
        turtle->xpos = homexpos;
        turtle->ypos = homeypos;
        
        if (*showTurtle == True)
        {
            drawTurtle(&*turtle, &*direction);
        }
    }
    //Prints whatever the user enters below 11 character
    else if (command[0] == 'p' && command[1] == 'r' && command[2] == 'i' && command[3] == 'n' && command[4] == 't')
    {
        attron (COLOR_PAIR (7));
        mvprintw(turtle->ypos - 2, turtle->xpos - 2, "%s", input);
        attroff (COLOR_PAIR (7));
    }
    //Erases all of the lines drawn
    else if (command[0] == 'c' && command[1] == 'l' && command[2] == 'e' && command[3] == 'a' && command[4] == 'n')
    {
        clean();
        if (*showTurtle == True)
        {
            drawTurtle (&*turtle, &*direction);
        }
    }
    //Sets the color of the lines from the turtle
    else if (command[0] == 's' && command[1] == 'e' && command[2] == 't' && command[3] == 'p' && command[4] == 'e' && command[5] == 'n' && command[6] == 'c' && command[7] == 'o' && command[8] == 'l' && command[9] == 'o' && command[10] == 'r')
    {
        if (input[0] == 'b' && input[1] == 'l' && input[2] == 'u' && input[3] == 'e')
        {
            *colorPen = 1;
        }
        else if (input[0] == 'g' && input[1] == 'r' && input[2] == 'e' && input[3] == 'e' && input[4] == 'n')
        {
            *colorPen = 4;
        }
        else if (input[0] == 'y' && input[1] == 'e' && input[2] == 'l' && input[3] == 'l' && input[4] == 'o' && input[5] == 'w')
        {
            *colorPen = 6;
        }
        else if (input[0] == 'r' && input[1] == 'e' && input[2] == 'd')
        {
            *colorPen = 3;
        }
        
        turtle->move = 0;
    }
}
