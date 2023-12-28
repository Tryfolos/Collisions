///// A collision detection library written by Filip Hedman ///////////////////////////////////////////////////////////////////////////



///// Data structures ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct POINT {unsigned int x, y;}POINT;

typedef struct LINE {unsigned int x, y, x2, y2;}LINE;

typedef struct BOX {unsigned int x, y, x2, y2;}BOX;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  



///// Function declarations //////////////////////////////////////////////////////////////////////////////////////////////////////////
POINT * create_point(unsigned int x, unsigned int y); //Done.

LINE * create_line(unsigned int x, unsigned int y, unsigned int x2, unsigned int y2); //Done.

BOX * create_box(unsigned int x, unsigned int y, unsigned int x2, unsigned int y2); //Done.

char point_collide_point(POINT * point1, POINT * point2); //Done.

char point_collide_box(POINT * point, BOX * box); //Done.

char line_collide_line(LINE * line1, LINE * line2); //Done.

char line_collide_box(LINE * line, BOX * box); //Done.

char box_collide_box(BOX * box1, BOX * box2); //Done.

char box_contain_box(BOX * box1, BOX * box2); //Done.

char box_contain_line(BOX * box, LINE * line); //Done.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





///// Documentation and function explanations ////////////////////////////////////////////////////////////////////////////////////////
/*
This library is designed for two dimensional collision detection only and is NOT well suited 
towards 3D development of any kind. The library provides functions and data structures that help 
check collisions between boxes, lines and points in 2D space using a X and Y coordinate system.
There are also functions available for determining if a line or a box is fully contained
withing a box with no parts protruding outside its bounding box area.


Caution!
This library has no safety features. This is for the sake of simplicity and performance. 
The three functions that return a struct does not check if the coordinates are outside the 32bit unsigned integer range.
The second set of coordinates in a BOX struct has to be equal to or greater than the first set of coordinates,
otherwise it might not function properly. This library never returns any errors.


POINT * create_point(unsigned int x, unsigned int y) -
takes two "unsigned int" arguments that represent coordinates and returns a POINT structure.

LINE * create_line(unsigned int x, unsigned int y, unsigned int x2, unsigned int y2) -
takes four "unsigned int" arguments that represent the beginning and the end of the LINE structure 
that will be returned from the function.

BOX * create_box(unsigned int x, unsigned int y, unsigned int x2, unsigned int y2) -
takes four "unsigned int" arguments that represent the top left and the bottom right coordinates 
of the BOX structure that will be returned from the function.

int point_collide_point(POINT * point1, POINT * point2) -
takes two "POINT*" arguments and checks if the two points are colliding with each other.
Returns 1 if they are colliding and 0 if they are not.

int line_collide_line(LINE * line1, LINE * line2) - 
Takes two "LINE*" arguments and checks if the two lines are intersecting at any point.
Returns 1 if they are intersecting and 0 if they are not.

int line_collide_box(LINE * line, BOX * box) -
Takes one "LINE*" argument and one "BOX*" argument and checks if the line collides with the box edge at any point.
Returns 1 if they are colliding and 0 if they are not.

int box_collide_box(BOX * box1, BOX * box2) -
Takes two "BOX*" arguments and checks if the boxs are colliding with each other.
Returns 1 if they are colliding and 0 if they are not.

int box_contain_box(BOX * box1, BOX * box2) -
Takes two "BOX*" arguments and checks if the second box is fully contained within the first box.
Returns 1 if contained and 0 if not.

int box_contain_line(BOX * box, LINE * line) -
Takes one "BOX*" argument and one "LINE*" argument and checks if the line is fully contained within the box.
Returns 1 if contained and 0 if not.
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




