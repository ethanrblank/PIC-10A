//#include "ccc_win.h"
#include <time.h>
#include <cmath>

void pause(int x)
{
    clock_t goal = x + clock();
    while (goal > clock());
}

void drawTarget(Point center, double scale)
{
    Point p1 = center;
    Circle inner(p1, scale);
    Circle middle(p1, scale*2);
    Circle outer(p1, scale*3);
    cwin << inner << middle << outer;
}

void drawArrow(Point center, double scale)
{
    Point topArrow = center;
    topArrow.move(0, scale*2);
    
    Point bottomArrow = topArrow;
    bottomArrow.move(0, -scale*4);
    
    Point headLeft = topArrow;
    headLeft.move(-scale / 2, -scale / 2);
    
    Point headRight = topArrow;
    headRight.move(scale / 2, -scale / 2);
    
    Point tail1top = bottomArrow;
    tail1top.move(0, scale / 2);
    Point tailbottom1 = tail1top;
    tailbottom1.move(scale / 3, -scale / 3);
    
    Point tailbottom2 = tail1top;
    tailbottom2.move(-scale / 3, -scale / 3);
    
    Point tail2top = tail1top;
    tail2top.move(0, scale/3);
    
    Point tailbottom3 = tail2top;
    tailbottom3.move(scale / 3, -scale / 3);
    
    Point tailbottom4 = tail2top;
    tailbottom4.move(-scale / 3, -scale / 3);
    
    
    Line stick(topArrow, bottomArrow);
    Line head1(topArrow, headLeft);
    Line head2(topArrow, headRight);
    Line tailRight1(tail1top, tailbottom1);
    Line tailLeft1(tail1top, tailbottom2);
    Line tailRight2(tail2top, tailbottom3);
    Line tailLeft2(tail2top, tailbottom4);
    
    cwin << stick << head1 << head2 << tailRight1 << tailLeft1 << tailRight2 << tailLeft2;
}

double distance_function(Point a, Point b)
{
    double aX, aY, bX, bY, xSubtract, ySubtract, distance;
    aX = a.get_x();
    aY = a.get_y();
    bX = b.get_x();
    bY = b.get_y();
    xSubtract = bX - aX;
    ySubtract = bY - aY;
    
    distance = sqrt(pow(xSubtract, 2) + pow(ySubtract, 2));
    return distance;
}

double slope_function (Point a, Point b)
{
    double slope = (b.get_y()-a.get_y())/(b.get_x()-a.get_x());
    return slope;
}

double getSlopeX (Point a, Point b)
{
    double slopeX;
    slopeX = (b.get_x() - a.get_x());
    return slopeX;
}

double getSlopeY (Point a, Point b)
{
    double slopeY;
    slopeyY = (b.get_y() - a.get_y());
    return slopeY;
}




int ccc_win_main()
{
    cwin.coord(0, 20, 20, 0);
    
    Point placeTarget = cwin.get_mouse("Please place a target at the top of the screen.");
    for (double t = .1; t <= 1; t = t + .08)
    {
        drawTarget(placeTarget, t);
        pause(50);
        cwin.clear();
    }
    
    drawTarget(placeTarget, 1);
    Point placeArrow = cwin.get_mouse("Please place an arrow at the bottom of the screen.");
    for (double a = .1; a <= 1; a = a + .1)
    {
        drawTarget(placeTarget, 1);
        drawArrow(placeArrow, a);
        pause(20);
        cwin.clear();
    }
    
    drawTarget(placeTarget, 1);
    drawArrow(placeArrow, 1);
    
    /*******************************************************
     HERE IS WHERE I AM HAVING TROUBLE
     ******************************************************/
    
    Point shootArrow = cwin.get_mouse("Shoot your arrow at the target!");
    
    double distance = distance_function(placeArrow, shootArrow);
    double slope = slope_function(placeArrow, shootArrow);
    double slopeX = getSlopeX(placeArrow, shootArrow);
    double slopeY = getSlopeY(placeArrow, shootArrow);
    
    while (distance != 0)
    {
        placeArrow.move(placeArrow.get_x() + slopeX, placeArrow.get_y() + slopeY);
        drawArrow(placeArrow, 1);
        drawTarget(placeTarget,1);
        pause(50);
        cwin.clear();
        distance = distance_function(placeArrow, shootArrow);
    }
    
/*
    
    double targetX = placeTarget.get_x();
    double targetY = placeTarget.get_y();
    double moveX = (targetX - arrowX)-i;
    double moveY = (targetY - arrowY)-i;
    Point newPoint = Point(moveX, moveY);
    placeArrow = newPoint;
    
    double x, y;
    Point i(x, y);
    
    for (Point i = placeArrow; i = shootArrow; i = i.move(x++,y++)) {
        drawTarget(placeTarget, 1);
        placeArrow.move((i/(2*steps)), (i/(2*steps)));
        
        drawArrow(placeArrow, 1);
        pause(100);
        cwin.clear();
    }
    drawArrow(placeArrow, 1);
    drawTarget(placeTarget, 1);
    
    
    /*for (double trip = 0; trip <= distance_between; trip = trip + .1) {
     cwin.clear();
     drawArrow(placeArrow + Point(1, 0), 1);
     pause(20);
     }
     Message M(Point(0, 0), distance_between);
     cwin << M;

    

     
     movey = target.y - arrow.y / (number of steps)
     movex = target.x - arrow.x / (number of steps)
     
     bool hitTarget = false
     int i = 1
     while(!hitTarget)
     {
     newxcoord = i * movex
     newycoord = i * movey
     newpoint = Point(newxcoord, newycoord)
     drawArrow(newpoint, scale)
     pause
     
     if(arrow.x == target.x && arrow.y == target.y)
     hitTarget = true
     
     clear
     i++;
     }
    
*/
    return 0;
}