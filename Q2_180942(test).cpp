#include<iostream>
#include "Q2_180942.h"
using namespace std;
int main()
{
	rectangle r1;
	r1.getWidth();
	r1.getLength();
	float l1, w1;
	cout<<"Enter Length to set: "<<endl;
	cin>>l1;
	r1.setLength(l1);
	cout<<"Enter Width to set: "<<endl;
	cin>>w1;
	r1.setLength(l1);
	r1.setWidth(w1);
	r1.getArea();
	r1.draw();
	r1.rotateRectangle();
	r1.draw();
	return 0;
}