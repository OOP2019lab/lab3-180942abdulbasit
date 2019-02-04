#include <iostream>
#include "Q2_180942.h"
using namespace std;


void rectangle:: getWidth()  //show width
{
	cout<<"Width: "<<width<<endl;
}
void  rectangle:: getLength() //show length
{
	cout<<"Length: "<<length<<endl;
}
void rectangle:: setWidth(float w) //takes input of width
{
	if (w>0)
		width=w;
	else
		width=0;
}
void rectangle:: setLength(float l) //takes input of length
{
	if (l>0)
		length=l;
	else
		length=0;
}
void rectangle:: getArea() //prints area
{
	cout<<"Area: "<<length*width<<endl;
}
void rectangle:: rotateRectangle() // changes length into width and vice versa
{
	float temp;
	temp=length;
	length=width;
	width=temp;
}
void rectangle:: draw()  //draw rectangle
{
	cout<<endl;
	for(int i=0; i<length;i++)
	{
		for(int j=0; j<width; j++)
			cout<<"*";
	cout<<endl;
	}
}