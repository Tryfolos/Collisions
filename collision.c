#include <stdlib.h>
#include "collision.h"

//Creating point.
POINT * create_point(unsigned int x, unsigned int y) {

POINT * point = malloc(sizeof(POINT));

point->x = x;
point->y = y;

return point;
};


//Creating line.
LINE * create_line(unsigned int x, unsigned int y, unsigned int x2, unsigned int y2) {

LINE * line = malloc(sizeof(LINE));

line->x = x;
line->y = y;
line->x2 = x2;
line->y2 = y2;

return line;
};

//Creating box.
BOX * create_box(unsigned int x, unsigned int y, unsigned int x2, unsigned int y2) {

BOX * box = malloc(sizeof(BOX));

box->x = x;
box->y = y;
box->x2 = x2;
box->y2 = y2;

return box;
};


//Checking collision between points.
char point_collide_point(POINT * point1, POINT * point2) {

if (point1->x == point2->x && point1->y == point2->y ) {
return 1;
}

return 0;
};


//Checking collision between a point and a box.
char point_collide_box(POINT * point, BOX * box) {

if (point->x >= box->x) {
if (point->x <= box->x2) {
if (point->y >= box->y) {
if (point->y <= box->y2) {
return 1;
}}}}

return 0;
};

//Checking collision between a box and another box.
char box_collide_box(BOX * box1, BOX * box2) {

if (box1->x2 >= box2->x) {
if (box1->x <= box2->x2) {
if (box1->y2 >= box2->y) {
if (box1->y <= box2->y2) {
return 1;
}}}}

return 0;
};

//Checking if a box contains another box.
char box_contain_box(BOX * box1, BOX * box2) {

if (box2->x2 <= box1->x2) {
if (box2->x >= box1->x) {
if (box2->y2 <= box1->y2) {
if (box2->y >= box1->y) {
return 1;
}}}}

return 0;
};


//Checking if a box contains a line.
char box_contain_line(BOX * box, LINE * line) {

if (line->x >= box->x) {
if (line->x <= box->x2) {
if (line->y >= box->y) {
if (line->y <= box->y2) {

if (line->x2 >= box->x) {
if (line->x2 <= box->x2) {
if (line->y2 >= box->y) {
if (line->y2 <= box->y2) {

return 1;
}}}} }}}}


return 0;
}


//Checking if a line collides with the outer edges of a box a box.
char line_collide_box(LINE * line, BOX * box) {

LINE line1;
LINE line2;
LINE line3;
LINE line4;

line1.x = box->x;
line1.x2 = box->x2;
line1.y = box->y;
line1.y2 = box->y;

line2.x = box->x2;
line2.x2 = box->x2;
line2.y = box->y;
line2.y2 = box->y2;

line3.x = box->x;
line3.x2 = box->x2;
line3.y = box->y2;
line3.y2 = box->y2;

line4.x = box->x;
line4.x2 = box->x;
line4.y = box->y;
line4.y2 = box->y2;

if (line_collide_line(line, &line1) == 1) {
return 1;	
}
if (line_collide_line(line, &line2) == 1) {
return 1;	
}
if (line_collide_line(line, &line3) == 1) {
return 1;	
}
if (line_collide_line(line, &line4) == 1) {
return 1;	
}


return 0;
}


//Checking if a line is colliding with another line.
char line_collide_line(LINE * line1, LINE * line2) {


/////Here comes the elegant implementation.
//Variables that will contain both lines positions. 
double line1x, line1y, line1x2, line1y2;
double line2x, line2y, line2x2, line2y2;

line1x = (double)line1->x;
line1y = (double)line1->y;
line1x2 = (double)line1->x2;
line1y2 = (double)line1->y2;

line2x = (double)line2->x;
line2y = (double)line2->y;
line2x2 = (double)line2->x2;
line2y2 = (double)line2->y2;

//Flags that represent a collision or not.
int line1_collidey = 0;
int line2_collidey = 0;

//Values that describe the ratio of elevation between the x and y axis.
double line1x_step, line1y_step;
double line2x_step, line2y_step;
line1x_step = 1.0;
line1y_step = 1.0;
line2x_step = 1.0;
line2y_step = 1.0;

//Calculating if the x or y axis changes more from the first to the second coordinate.
line1y_step = (line1y2 - line1y)/(line1x2 - line1x);
line2y_step = (line2y2 - line2y)/(line2x2 - line2x);

//These are the conditions that have to be met for a collision to occur.
if (line2y <= (line1y + ((line2x-line1x)*line1y_step))) {
if (line2y2 >= (line1y + ((line2x2-line1x)*line1y_step))) {
line2_collidey = 1;
}}
if (line2y >= (line1y + ((line2x-line1x)*line1y_step))) {
if (line2y2 <= (line1y + ((line2x2-line1x)*line1y_step))) {
line2_collidey = 1;
}}


if (line1y <= (line2y + ((line1x-line2x)*line2y_step))) {
if (line1y2 >= (line2y + ((line1x2-line2x)*line2y_step))) {
line1_collidey = 1;
}}
if (line1y >= (line2y + ((line1x-line2x)*line2y_step))) {
if (line1y2 <= (line2y + ((line1x2-line2x)*line2y_step))) {
line1_collidey = 1;
}}


//Returning 1 if both lines are colliding with each other. 
if (line2_collidey == 1 && line1_collidey) {
return 1;
}

return 0;
}

