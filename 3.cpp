#define NULL 0
#define STAR 1
#define ARROW 2
#define CLOUD 3
#define BREAD 4
#define HEART 5
#define BAGUETTE 6
#define SMILE 7

#include<stdlib.h>
#include<gl/glut.h>
#include<math.h>

void drawStar(int, int);
void drawArrow(int, int);
void drawCloud(int, int);
void drawBread(int, int);
void drawHeart(int, int);
void drawBaguette(int, int);
void drawSmile(int, int);
void mouse(int, int, int, int);
void display(void);
void myReshape(GLsizei, GLsizei);

void myinit(void);

void screen_box(int, int, int);
void right_menu(int);
void middle_menu(int);
void color_menu(int);
void pixel_menu(int);
void fill_menu(int);
int pick(int, int);

GLsizei wh = 500, ww = 500;
GLfloat size = 20.0;
int draw_mode = 0;
int rx, ry;

GLfloat r = 1.0, g = 1.0, b = 1.0;
int fill = 0;


void drawStar(int xp, int yp)
{
	if (fill)glBegin(GL_TRIANGLES);
	else glBegin(GL_LINE_LOOP);
	glVertex2i(xp, yp + size*1.09);
	glVertex2i(xp - size / 4, yp + size*1.7 / 4.0);
	glVertex2i(xp + size / 4, yp + size*1.7 / 4.0);
	glVertex2i(xp + size, yp + size*1.7 / 4.0);
	glVertex2i(xp - size*0.6, yp - size * 0.91);
	glVertex2i(xp - size / 4, yp + size*1.7 / 4.0);
	glVertex2i(xp - size, yp + size*1.7 / 4.0);
	glVertex2i(xp + size * 0.6, yp - size * 0.91);
	glVertex2i(xp + size / 4, yp + size*1.7 / 4.0);
	glEnd();

}
void drawArrow(int xp, int yp)
{
	if (fill)glBegin(GL_POLYGON);
	else glBegin(GL_LINE_LOOP);
	glVertex2i(xp - size, yp + size);
	glVertex2i(xp - size, yp - size);
	glVertex2i(xp - size / 3.0, yp - size / 3.0);
	glVertex2i(xp - 2 / 3 * size, yp - size);
	glVertex2i(xp + size, yp - 2 / 3 * size);
	glVertex2i(xp + size / 3.0, yp + size / 3.0);
	glVertex2i(xp + size, yp + size);
	glEnd();
}

void drawCloud(int xp, int yp)
{
	double rad = size*5/12;

	if (fill) {
		glBegin(GL_POLYGON);
		for (int i = 0; i < 360; i++)
		{
			double angle = i*3.141592 / 180;
			double x = rad*cos(angle);
			double y = rad*sin(angle);
			glVertex2f(xp - (1.7*rad) + x, yp + y);
		}
		glEnd();
		glBegin(GL_POLYGON);
		for (int i = 0; i < 360; i++)
		{
			double angle = i*3.141592 / 180;
			double x = rad*cos(angle);
			double y = rad*sin(angle);
			glVertex2f(xp + x, yp + y);
		}
		glEnd();
		glBegin(GL_POLYGON);
		for (int i = 0; i <= 360; i++)
		{
			double angle = i*3.141592 / 180;
			double x = rad*cos(angle);
			double y = rad*sin(angle);
			glVertex2f(xp + (1.7*rad) + x, yp + y);
		}
		glEnd();
	}
	else
	{
		glBegin(GL_LINE_LOOP);
		for (int i = 30; i < 150; i++)
		{
			double angle = i*3.141592 / 180;
			double x = rad*cos(angle);
			double y = rad*sin(angle);
			glVertex2f(xp + x, yp + y);
		}
		for (int i = 30; i < 330; i++)
		{
			double angle = i*3.141592 / 180;
			double x = rad*cos(angle);
			double y = rad*sin(angle);
			glVertex2f(xp - (1.7*rad) + x, yp + y);
		}
		for (int i = 210; i < 330; i++)
		{
			double angle = i*3.141592 / 180;
			double x = rad*cos(angle);
			double y = rad*sin(angle);
			glVertex2f(xp + x, yp + y);
		}
		for (int i = 210; i < 510; i++)
		{
			double angle = i*3.141592 / 180;
			double x = rad*cos(angle);
			double y = rad*sin(angle);
			glVertex2f(xp + (1.7*rad) + x, yp + y);
		}
		glEnd();
	}
}
void drawBread(int xp, int yp)
{
	double rad = size / 3.0;

	if (fill)
	{
		glBegin(GL_POLYGON);
		for (int i = 0; i <= 180; i++)
		{
			double angle = i*3.141592 / 180;
			double x = rad*cos(angle);
			double y = rad*sin(angle);
			glVertex2f(xp + size * 2 / 3 + x, yp + size / 2 + y);
		}
		glEnd();
		glBegin(GL_POLYGON);
		for (int i = 0; i <= 180; i++)
		{
			double angle = i*3.141592 / 180;
			double x = rad*cos(angle);
			double y = rad*sin(angle);
			glVertex2f(xp + x, yp + size / 2 + y);
		}
		glEnd();
		glBegin(GL_POLYGON);
		for (int i = 0; i <= 180; i++)
		{
			double angle = i*3.141592 / 180;
			double x = rad*cos(angle);
			double y = rad*sin(angle);
			glVertex2f(xp - size * 2 / 3 + x, yp + size / 2 + y);
		}
		glEnd();
		glBegin(GL_POLYGON);
		glVertex2f(xp - size, yp + size / 2);
		glVertex2f(xp - size, yp - size / 2);
		glVertex2f(xp + size, yp - size / 2);
		glVertex2f(xp + size, yp + size / 2);
		glEnd();
	}
	else {
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i <= 180; i++)
		{
			double angle = i*3.141592 / 180;
			double x = rad*cos(angle);
			double y = rad*sin(angle);
			glVertex2f(xp + size * 2 / 3 + x, yp + size / 2 + y);
		}
		for (int i = 0; i <= 180; i++)
		{
			double angle = i*3.141592 / 180;
			double x = rad*cos(angle);
			double y = rad*sin(angle);
			glVertex2f(xp + x, yp + size / 2 + y);
		}
		for (int i = 0; i <= 180; i++)
		{
			double angle = i*3.141592 / 180;
			double x = rad*cos(angle);
			double y = rad*sin(angle);
			glVertex2f(xp - size * 2 / 3 + x, yp + size / 2 + y);
		}
		glVertex2f(xp - size, yp - size / 2);
		glVertex2f(xp + size, yp - size / 2);
		glVertex2f(xp + size, yp + size / 2);
		glEnd();
	}
}

void drawHeart(int xp, int yp)
{
	double rad = size / 2.0;
	if (fill)
	{
		glBegin(GL_POLYGON);
		for (int i = 0; i <= 180; i++)
		{
			double angle = i*3.141592 / 180;
			double x = rad*cos(angle);
			double y = rad*sin(angle);
			glVertex2f(xp + size / 2 + x, yp + 4 * size / 9 + y);
		}
		glEnd();
		glBegin(GL_POLYGON);
		for (int i = 0; i <= 180; i++)
		{
			double angle = i*3.141592 / 180;
			double x = rad*cos(angle);
			double y = rad*sin(angle);
			glVertex2f(xp - size / 2 + x, yp + 4 * size / 9 + y);
		}
		glEnd();
		glBegin(GL_TRIANGLES);
		glVertex2f(xp - size, yp + 4 * size / 9);
		glVertex2f(xp, yp - 8 * size / 9);
		glVertex2f(xp + size, yp + 4 * size / 9);
		glEnd();

	}
	else
	{
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i <= 180; i++)
		{
			double angle = i*3.141592 / 180;
			double x = rad*cos(angle);
			double y = rad*sin(angle);
			glVertex2f(xp + size / 2 + x, yp + 4 * size / 9 + y);
		}
		for (int i = 0; i <= 180; i++)
		{
			double angle = i*3.141592 / 180;
			double x = rad*cos(angle);
			double y = rad*sin(angle);
			glVertex2f(xp - size / 2 + x, yp + 4 * size / 9 + y);
		}
		glVertex2f(xp, yp - 8 * size / 9);
		glVertex2f(xp + size, yp + 4 * size / 9);
		glEnd();
	}
}
void drawBaguette(int xp, int yp)
{
	double a = size,x,y;
	double b = size * 2 / 5;
	if (fill) {
		glBegin(GL_POLYGON);
		for (int i = 0; i < 360; i++)
		{
			double angle = i*3.141592 / 180;
			x = a*cos(angle);
			y = b*sin(angle);
			glVertex2f(xp + x, yp + y);
		}
		glEnd();
		glColor3f(0.96, 0.96, 0.78);
		glBegin(GL_POLYGON);
		glVertex2f(xp, yp + size * 1 / 15);
		for (int i = 78; i <= 102; i++)
		{
			double angle = i*3.141592 / 180;
			x = a*cos(angle);
			y = b*sin(angle);
			glVertex2f(xp + x, yp + y);
		}
		glEnd();
		glBegin(GL_POLYGON);
		glVertex2f(xp + size * 3 / 5, yp + size * 1 / 15);
		for (int i = 37; i <= 66; i++)
		{
			double angle = i*3.141592 / 180;
			x = a*cos(angle);
			y = b*sin(angle);
			glVertex2f(xp + x, yp + y);
		}
		glEnd();
		glBegin(GL_POLYGON);
		glVertex2f(xp - size * 3 / 5, yp + size * 1 / 15);
		for (int i = 114; i <= 143; i++)
		{
			double angle = i*3.141592 / 180;
			x = a*cos(angle);
			y = b*sin(angle);
			glVertex2f(xp + x, yp + y);
		}
		glEnd();
	}
	else
	{
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < 360; i++)
		{
			double angle = i*3.141592 / 180;
			x = a*cos(angle);
			y = b*sin(angle);
			glVertex2f(xp + x, yp + y);
		}
		glEnd();
		glBegin(GL_LINE_LOOP);
		glVertex2f(xp, yp + size * 1 / 15);
		for (int i = 78; i <= 102; i++)
		{
			double angle = i*3.141592 / 180;
			x = a*cos(angle);
			y = b*sin(angle);
			glVertex2f(xp + x, yp + y);
		}
		glEnd();
		glBegin(GL_LINE_LOOP);
		glVertex2f(xp + size * 3 / 5, yp + size * 1 / 15);
		for (int i = 37; i <= 66; i++)
		{
			double angle = i*3.141592 / 180;
			x = a*cos(angle);
			y = b*sin(angle);
			glVertex2f(xp + x, yp + y);
		}
		glEnd();
		glBegin(GL_LINE_LOOP);
		glVertex2f(xp - size * 3 / 5, yp + size * 1 / 15);
		for (int i = 114; i <= 143; i++)
		{
			double angle = i*3.141592 / 180;
			x = a*cos(angle);
			y = b*sin(angle);
			glVertex2f(xp + x, yp + y);
		}
		glEnd();
	}
}
void drawSmile(int xp, int yp)
{
	double rad = size;
	if (fill) {
		glBegin(GL_POLYGON);
		for (int i = 0; i < 360; i++)//face
		{
			double angle = i*3.141592 / 180;
			double x = rad*cos(angle);
			double y = rad*sin(angle);
			glVertex2f(xp + x, yp + y);
		}
		glEnd();
		glColor3f(0.3, 0.2, 0.5);
		glBegin(GL_POLYGON);//lefteye
		for (int i = 0; i < 360; i++)
		{
			double angle = i*3.141592 / 180;
			double x = rad*cos(angle) / 10;
			double y = rad*sin(angle) / 10;
			glVertex2f(xp-rad/3 + x, yp + y);
		}
		glEnd();
		glBegin(GL_POLYGON);//righteye
		for (int i = 0; i < 360; i++)
		{
			double angle = i*3.141592 / 180;
			double x = rad*cos(angle) / 10;
			double y = rad*sin(angle) / 10;
			glVertex2f(xp + rad / 3 + x, yp + y);
		}
		glEnd();
		glBegin(GL_POLYGON);//mouse
		for (int i = 180; i <= 360; i++)
		{
			double angle = i*3.141592 / 180;
			double x = rad*cos(angle)/3;
			double y = rad*sin(angle)/3;
			glVertex2f(xp + x, yp + y - rad / 3);
		}
		glEnd();
	}
	else
	{
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < 360; i++)//face
		{
			double angle = i*3.141592 / 180;
			double x = rad*cos(angle);
			double y = rad*sin(angle);
			glVertex2f(xp + x, yp + y);
		}
		glEnd();
		glBegin(GL_LINE_LOOP);//lefteye
		for (int i = 0; i < 360; i++)
		{
			double angle = i*3.141592 / 180;
			double x = rad*cos(angle) / 10;
			double y = rad*sin(angle) / 10;
			glVertex2f(xp - rad / 3 + x, yp + y);
		}
		glEnd();
		glBegin(GL_LINE_LOOP);//righteye
		for (int i = 0; i < 360; i++)
		{
			double angle = i*3.141592 / 180;
			double x = rad*cos(angle) / 10;
			double y = rad*sin(angle) / 10;
			glVertex2f(xp + rad / 3 + x, yp + y);
		}
		glEnd();
		glBegin(GL_LINE_LOOP);//mouse
		for (int i = 180; i <= 360; i++)
		{
			double angle = i*3.141592 / 180;
			double x = rad*cos(angle)/3 ;
			double y = rad*sin(angle)/3 ;
			glVertex2f(xp + x, yp + y - rad / 3);
		}
		glEnd();
	}
}
void myReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, (GLdouble)w, 0.0, (GLdouble)h, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glViewport(0, 0, w, h);
	glClearColor(0.8, 0.8, 0.8, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	display();
	glFlush();

	ww = w;
	wh = h;
}

void myinit(void)
{
	glViewport(0, 0, ww, wh);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, (GLdouble)ww, 0.0, (GLdouble)wh, -1.0, 1.0);
	glClearColor(0.8, 0.8, 0.8, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void mouse(int btn, int state, int x, int y)
{
	int where;
	static int xp, yp;
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		glPushAttrib(GL_ALL_ATTRIB_BITS);

		where = pick(x, y);
		glColor3f(r, g, b);
		if (where != 0)
		{
			draw_mode = where;
		}
		else switch (draw_mode)
		{
		case(STAR) :
		{
			xp = x;
			yp = wh - y;
			drawStar(xp, yp);
			draw_mode = 0;
		}
				   break;
		case(ARROW) :
		{
			xp = x;
			yp = wh - y;
			drawArrow(xp, yp);
			draw_mode = 0;
		}
					break;
		case(CLOUD) :
		{
			xp = x;
			yp = wh - y;
			drawCloud(xp, yp);
			draw_mode = 0;
		}
					break;
		case(BREAD) :
		{
			xp = x;
			yp = wh - y;
			drawBread(xp, yp);
			draw_mode = 0;
		}
					break;
		case(HEART) :
		{
			xp = x;
			yp = wh - y;
			drawHeart(xp, yp);
			draw_mode = 0;
		}
					break;
		case(BAGUETTE) :
		{
			xp = x;
			yp = wh - y;
			drawBaguette(xp, yp);
			draw_mode = 0;
		}
					  break;
		case(SMILE) :
		{
			xp = x;
			yp = wh - y;
			drawSmile(xp, yp);
			draw_mode = 0;
		}
					break;
		}
		glPopAttrib();
		glFlush();
	}
}

int pick(int x, int y)
{
	y = wh - y;
	if (y < wh - ww / 10)return 0;
	else if (x < ww / 10) return STAR;
	else if (x < ww / 5) return ARROW;
	else if (x < 3 * ww / 10) return CLOUD;
	else if (x < 2 * ww / 5)return BREAD;
	else if (x < ww / 2)return HEART;
	else if (x < 6 * ww / 10) return BAGUETTE;
	else if (x < 7 * ww / 10)return SMILE;
	else return 0;
}
void screen_box(int x, int y, int s)
{
	glBegin(GL_QUADS);
	glVertex2i(x, y);
	glVertex2i(x + s, y);
	glVertex2i(x + s, y + s);
	glVertex2i(x, y + s);
	glEnd();
}

void right_menu(int id)
{
	if (id == 1)exit(0);
	else display();
}

void middle_menu(int id)
{

}

void color_menu(int id)
{
	if (id == 1) { r = 1.0; g = 0.0; b = 0.0; }
	else if (id == 2) { r = 0.0; g = 1.0; b = 0.0; }
	else if (id == 3) { r = 0.0; g = 0.0; b = 1.0; }
	else if (id == 4) { r = 0.0; g = 1.0; b = 1.0; }
	else if (id == 5) { r = 1.0; g = 0.0; b = 1.0; }
	else if (id == 6) { r = 1.0; g = 1.0; b = 0.0; }
	else if (id == 7) { r = 1.0; g = 1.0; b = 1.0; }
	else if (id == 8) { r = 0.0; g = 0.0; b = 0.0; }
	else if (id == 9) { r = 0.58; g = 0.29; b = 0.0; }
}

void pixel_menu(int id)
{
	if (id == 1)size = 2 * size;
	else if (size > 1) size = size / 2;
}

void fill_menu(int id)
{
	if (id == 1) fill = 1;
	else fill = 0;
}

void display(void)
{
	int shift = 0;
	int xp, yp;
	float s;
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glClearColor(0.8, 0.8, 0.8, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.0);
	screen_box(0, wh - ww / 10, ww / 10);
	glColor3f(1.0, 0.0, 0.0);
	screen_box(ww / 10, wh - ww / 10, ww / 10);
	glColor3f(0.0, 0.0, 1.0);
	screen_box(ww / 5, wh - ww / 10, ww / 10);
	glColor3f(0.58, 0.29, 0.0);
	screen_box(3 * ww / 10, wh - ww / 10, ww / 10);
	glColor3f(1.0, 0.0, 1.0);
	screen_box(2 * ww / 5, wh - ww / 10, ww / 10);
	glColor3f(0.96, 0.96, 0.78);
	screen_box(ww / 2, wh - ww / 10, ww / 10);
	glColor3f(0.3, 0.2, 0.5);
	screen_box(6*ww / 10, wh - ww / 10, ww / 10);
	glColor3f(0.0, 0.0, 0.0);
	//star
	xp = ww / 20;
	yp = wh - ww / 10 + ww / 20;
	s = ww / 40;
	glBegin(GL_TRIANGLES);
	glVertex2i(xp, yp + s*1.09);
	glVertex2i(xp - s / 4, yp + s*1.7 / 4.0);
	glVertex2i(xp + s / 4, yp + s*1.7 / 4.0);
	glVertex2i(xp + s, yp + s*1.7 / 4.0);
	glVertex2i(xp - s*0.6, yp - s * 0.91);
	glVertex2i(xp - s / 4, yp + s*1.7 / 4.0);
	glVertex2i(xp - s, yp + s*1.7 / 4.0);
	glVertex2i(xp + s * 0.6, yp - s * 0.91);
	glVertex2i(xp + s / 4, yp + s*1.7 / 4.0);
	glEnd();
	//arrow
	xp = ww / 10 + ww / 20;
	yp = wh - ww / 10 + ww / 20;
	s = ww / 40;
	glBegin(GL_POLYGON);
	glVertex2i(xp - s, yp + s);
	glVertex2i(xp - s, yp - s);
	glVertex2i(xp - s / 3.0, yp - s / 3.0);
	glVertex2i(xp - 2 / 3 * s, yp - s);
	glVertex2i(xp + s, yp - 2 / 3 * s);
	glVertex2i(xp + s / 3.0, yp + s / 3.0);
	glVertex2i(xp + s, yp + s);
	glEnd();
	//cloud
	xp = ww / 5 + ww / 20;
	yp = wh - ww / 10 + ww / 20;
	s = ww / 60;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		double angle = i*3.141592 / 180;
		double x = s*cos(angle);
		double y = s*sin(angle);
		glVertex2f(xp - (1.7*s) + x, yp + y);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		double angle = i*3.141592 / 180;
		double x = s*cos(angle);
		double y = s*sin(angle);
		glVertex2f(xp + x, yp + y);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 360; i++)
	{
		double angle = i*3.141592 / 180;
		double x = s*cos(angle);
		double y = s*sin(angle);
		glVertex2f(xp + (1.7*s) + x, yp + y);
	}
	glEnd();
	//bread
	xp = 3 * ww / 10 + ww / 20;
	yp = wh - ww / 10 + ww / 20;
	s = ww / 30;
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 180; i++)
	{
		double angle = i*3.141592 / 180;
		double x = s*cos(angle) / 3.0;
		double y = s*sin(angle) / 3.0;
		glVertex2f(xp + s * 2 / 3 + x, yp + s / 2 + y);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 180; i++)
	{
		double angle = i*3.141592 / 180;
		double x = s*cos(angle) / 3.0;
		double y = s*sin(angle) / 3.0;
		glVertex2f(xp + x, yp + s / 2 + y);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 180; i++)
	{
		double angle = i*3.141592 / 180;
		double x = s*cos(angle) / 3.0;
		double y = s*sin(angle) / 3.0;
		glVertex2f(xp - s * 2 / 3 + x, yp + s / 2 + y);
	}
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(xp - s, yp + s / 2);
	glVertex2f(xp - s, yp - s / 2);
	glVertex2f(xp + s, yp - s / 2);
	glVertex2f(xp + s, yp + s / 2);
	glEnd();
	//heart
	xp = 2 * ww / 5 + ww / 20;
	yp = wh - ww / 10 + ww / 20;
	s = ww / 30;
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 180; i++)
	{
		double angle = i*3.141592 / 180;
		double x = s / 2 * cos(angle);
		double y = s / 2 * sin(angle);
		glVertex2f(xp + s / 2 + x, yp + 4 * s / 9 + y);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 180; i++)
	{
		double angle = i*3.141592 / 180;
		double x = s / 2 * cos(angle);
		double y = s / 2 * sin(angle);
		glVertex2f(xp - s / 2 + x, yp + 4 * s / 9 + y);
	}
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(xp - s, yp + 4 * s / 9);
	glVertex2f(xp, yp - 8 * s / 9);
	glVertex2f(xp + s, yp + 4 * s / 9);
	glEnd();
	//baguette
	xp = ww / 2 + ww / 20;
	yp = wh - ww / 10 + ww / 20;
	s = ww / 30;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		double angle = i*3.141592 / 180;
		double x = s*cos(angle);
		double y = s*2/5*sin(angle);
		glVertex2f(xp + x, yp + y);
	}
	glEnd();
	glColor3f(0.96, 0.96, 0.78);
	glBegin(GL_POLYGON);
	glVertex2f(xp, yp + s * 1 / 15);
	for (int i = 78; i <= 102; i++)
	{
		double angle = i*3.141592 / 180;
		double x = s*cos(angle);
		double y = s*2/5*sin(angle);
		glVertex2f(xp + x, yp + y);
	}
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(xp + s* 3 / 5, yp + s * 1 / 15);
	for (int i = 37; i <= 66; i++)
	{
		double angle = i*3.141592 / 180;
		double x = s*cos(angle);
		double y = s*2/5*sin(angle);
		glVertex2f(xp + x, yp + y);
	}
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(xp - s * 3 / 5, yp + s * 1 / 15);
	for (int i = 114; i <= 143; i++)
	{
		double angle = i*3.141592 / 180;
		double x = s*cos(angle);
		double y = s*2/5*sin(angle);
		glVertex2f(xp + x, yp + y);
	}
	glEnd();
	//smile
	xp = 6*ww / 10 + ww / 20;
	yp = wh - ww / 10 + ww / 20;
	s = ww / 30;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)//face
	{
		double angle = i*3.141592 / 180;
		double x = s*cos(angle);
		double y = s*sin(angle);
		glVertex2f(xp + x, yp + y);
	}
	glEnd();
	glColor3f(0.3, 0.2, 0.5);
	glBegin(GL_POLYGON);//lefteye
	for (int i = 0; i < 360; i++)
	{
		double angle = i*3.141592 / 180;
		double x = s*cos(angle) / 10;
		double y = s*sin(angle) / 10;
		glVertex2f(xp - s / 3 + x, yp + y);
	}
	glEnd();
	glBegin(GL_POLYGON);//righteye
	for (int i = 0; i < 360; i++)
	{
		double angle = i*3.141592 / 180;
		double x = s*cos(angle) / 10;
		double y = s*sin(angle) / 10;
		glVertex2f(xp + s / 3 + x, yp + y);
	}
	glEnd();
	glBegin(GL_POLYGON);//mouse
	for (int i = 180; i <= 360; i++)
	{
		double angle = i*3.141592 / 180;
		double x = s*cos(angle) / 3;
		double y = s*sin(angle) / 3;
		glVertex2f(xp + x, yp + y - s / 3);
	}
	glEnd();
	glPopAttrib();
	glFlush();
}

int main(int argc, char **argv)
{
	int c_menu, p_menu, f_menu;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("square");
	glutDisplayFunc(display);
	c_menu = glutCreateMenu(color_menu);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 3);
	glutAddMenuEntry("Cyan", 4);
	glutAddMenuEntry("Magenta", 5);
	glutAddMenuEntry("Yellow", 6);
	glutAddMenuEntry("White", 7);
	glutAddMenuEntry("Black", 8);
	glutAddMenuEntry("Brown", 9);
	p_menu = glutCreateMenu(pixel_menu);
	glutAddMenuEntry("increase size", 1);
	glutAddMenuEntry("decrease size", 2);
	f_menu = glutCreateMenu(fill_menu);
	glutAddMenuEntry("fill on", 1);
	glutAddMenuEntry("fill off", 2);
	glutCreateMenu(right_menu);
	glutAddMenuEntry("quit", 1);
	glutAddMenuEntry("clear", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutCreateMenu(middle_menu);
	glutAddSubMenu("Colors", c_menu);
	glutAddSubMenu("Size", p_menu);
	glutAddSubMenu("Fill", f_menu);
	glutAttachMenu(GLUT_MIDDLE_BUTTON);
	myinit();
	glutReshapeFunc(myReshape);
	glutMouseFunc(mouse);
	glutMainLoop();
}