#include <iostream>
#include "circle.h"
using namespace std;
int main()
{

double users_radius;// value to store users given radius value;
Circle * first_circle;// define a pointer to a circle
first_circle = new Circle();// allocate memory for the object and call the constructor

cout<<"This Program computes various metrics of a circle"<<endl;//Notify the user of what this program does
cout<<"Please enter the radius of the circle:";//prompt the user for the radius they want to set
cin>>users_radius;

first_circle->set_rad(users_radius);

cout<<"Area of circle is:"<<first_circle->compute_area()<<endl;//calculate the area using comput_area and give results to the user
cout<<"The circumference of the circle is:"<<first_circle->compute_circumference()<<endl;// calculate the circumference and give the results to the user
return 0;
}
