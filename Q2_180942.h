#include<string>
using namespace std;
class rectangle
{
	float width;
	float length;
public:
	void getWidth();
	void getLength();
	void setWidth(float w);
	void setLength(float l);
	void getArea();
	void rotateRectangle();
	void draw();
};