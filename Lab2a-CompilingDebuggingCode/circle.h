#include <math.h>
#ifndef CIRCLE_H
#define CIRCLE_H
using namespace std;
class Circle
{
private:
	double radius;//radius of the circle
	double * area;//area of the circle
	double * circumference;//circumferencee of the circle
	static const double pi=3.1415;// the value of pi
public:
	Circle(){radius=0;area=new double;circumference= new double;}
	void set_rad(double rad){radius = rad;};
	double compute_area()
	{*(area) = (pi*pow(radius,2.0));return * area;};
	double compute_circumference()
	{*(circumference)=2*pi*radius;return *circumference;};
	~Circle();
};
#endif
