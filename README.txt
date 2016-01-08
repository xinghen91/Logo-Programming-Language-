****************************************************
Nick Major		0879292
CIS2500		Assignment 2 / Logo
02/13/15
****************************************************
This is an interpreter for a small subset of the Logo Programming Language. The interpreter takes user input one line at a time and produces correct output. This program provides logo-style error messages if the user provides incorrect input.
	

************
Compilation
************
make (this makes the Makefile)


***********************
Running the program(s)
***********************
- cd Directory bin/
- ./runMe

*****************
Known Limitations
*****************
- negative moves
- user input length
- only 50 commands per use
- saving


*****************
Commands
*****************
Command number description 
fd      move   - moves in the positive x or y direction depending on the angle
bk      move   - moves in the negative x or y direction depending on the angle
rt      angle  - rotates current angle clockwise around the unit circle
lt      angle  - moves current angle counter-clockwise around the unit circle
pu      (n/a)  - turtle doesn’t draw behind it
pd      (n/a)  - turtle draws behind it
ht      (n/a)  - the turtle is no longer drawn
st      (n/a)  - the turtle is drawn
home    (n/a)  - resets the turtles position to the starting position
setpencolor color - pen can change to blue, red, green, or yellow
clean   (n/a)  - erases all of the pen lines
print   ____   - prints whatever is in the blank space less than 15 characters
new     (n/a)  - resets the program


