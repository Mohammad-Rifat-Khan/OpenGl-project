#include<windows.h>
#include<mmsystem.h>
#include<GL/glut.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<cstdio>

using namespace std;
GLfloat coulds_x=10;
GLfloat couldSpeed1=2;
GLfloat man_x=0; //man and bottle
GLfloat man_speed=4;
GLfloat wd1_x=20;
GLfloat wd1_y=25;
GLfloat wd2_x=0;
GLfloat wd2_y=30;
GLfloat wd3_x=20;
GLfloat wd3_y=35;
GLfloat wd_speed=10;
GLfloat f3_y=0;
GLfloat f3_x=700;
//transportation
float x,y,i;
float PI=3.1416;

GLfloat sunPosition1=0;
GLfloat sunSpeed1= 0.5;
GLfloat cloudPosition1=0;
//GLfloat couldSpeed1=1;
GLfloat cloudPosition2=0;
GLfloat couldSpeed2=0.8;
GLfloat policecarPosition=0.0f;
GLfloat policecarSpeed=2.5f;
GLfloat vanPosition2=0;
GLfloat vanspeed2=2;
GLfloat menPosition2=0;
GLfloat menspeed2=0.5;
GLfloat carPosition2=0;
GLfloat carSpeed2=1.8;
GLfloat sunPosition2=0;
GLfloat sunSpeed2= 0.5;
GLfloat cloudPosition3=0;
GLfloat couldSpeed3=1;
GLfloat cloudPosition4=0;
GLfloat couldSpeed4=0.8;
GLfloat carPosition1=0;
GLfloat carSpeed1=2;
GLfloat vanPosition1=0;
GLfloat vanspeed1=2;
GLfloat basketPosition = 0.0f;
GLfloat basketspeed = 0.5f;
GLfloat policecarPosition2=0;
GLfloat policecarSpeed2=2.5;
GLfloat hujurPosition1 = 0.0f;
GLfloat hujurPosition2 = 0.0f;
GLfloat bmenPosition1 = 0.0f;
GLfloat emenPosition1 = 0.0f;
GLfloat lmenPosition1 = 0.0f;
GLfloat hujurspeed1 = 0.5f;
GLfloat MplasticPosi=0.0f;
GLfloat MplasticSpeed=1.5f;
GLfloat MouthSpeed=0.7f;
GLfloat MouthPosition=0.0f;

void drawstring(float x0,float y2,float z,char *string, int f)
{
    char *c;
    glRasterPos3f(x0,y2,z);
    for(c=string;*c!='\0';c++){
        if(f==0)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*c);
        else
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*c);
    }
}


void renderBitmapString(int  x, int  y, int  z, void *font, char *string)
{
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void init(void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}


void reshape(GLint w, GLint h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(h>w)
		gluOrtho2D(0, 500, ((float)h/(float)w)*(0), ((float)h/(float)w)*500);
	else
        gluOrtho2D(((float)w/(float)h)*(0), ((float)w/(float)h)*(520), 0, 500);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

void display1N (void)
{

    glClear(GL_COLOR_BUFFER_BIT);

    //SKY
    glBegin(GL_QUADS);
    glColor3ub(7, 26, 116 );
    glVertex2i(-100,-20);
    glVertex2i(-100,100);
    glVertex2i(100,100);
    glVertex2i(100,-20);
    glEnd();

    //Star
    glPointSize(3.0);
    glBegin(GL_POINTS);
    glColor3f(255, 255, 255 );
    glVertex2i(-90,90);
    glVertex2i(-70,90);
    glVertex2i(-50,90);
    glVertex2i(-30,90);
    glVertex2i(-10,90);
    glVertex2i(10,90);
    glVertex2i(30,90);
    glVertex2i(50,90);
    glVertex2i(70,90);
    glVertex2i(90,90);
    glEnd();

    glPointSize(3.0);
    glBegin(GL_POINTS);
    glColor3f(255, 255, 255 );
    glVertex2i(-90,70);
    glVertex2i(-70,70);
    glVertex2i(-50,70);
    glVertex2i(-30,70);
    glVertex2i(-10,70);
    glVertex2i(10,70);
    glVertex2i(30,70);
    glVertex2i(50,70);
    glVertex2i(70,70);
    glVertex2i(90,70);
    glEnd();

    glPointSize(3.0);
    glBegin(GL_POINTS);
    glColor3f(255, 255, 255 );
    glVertex2i(-90,50);
    glVertex2i(-70,50);
    glVertex2i(-50,50);
    glVertex2i(-30,50);
    glVertex2i(-10,50);
    glVertex2i(10,50);
    glVertex2i(30,50);
    glVertex2i(50,50);
    glVertex2i(70,50);
    glVertex2i(90,50);
    glEnd();

    //Sun Move
    glPushMatrix();
    glTranslatef(sunPosition1,0.0f,0.0f);

    //Sun draw

    float x, y;
    int i;
    GLfloat radius;
    int triangleAmount =40;
    GLfloat twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255);
    x=70;
    y=75;
    radius =10;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    glPopMatrix();

    //cloud1 move
    glPushMatrix();
    glTranslatef(cloudPosition1,0,0);
    //Cloud Draw
    //Cloud-1

    //P-1


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234 );
    x=-75;
    y=92;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();



    //P-2
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234 );
    x=-79;
    y=87;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();


    //P-3
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234 );
    x=-85;
    y=82;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-4
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234 );
    x=-80;
    y=81;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-5
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234 );
    x=-73;
    y=85;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-6
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234  );
    x=-74;
    y=79;
    radius =3;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();
    glPopMatrix();

    //cloud2 move
    glPushMatrix();
    glTranslatef(cloudPosition2,0,0);
    //Cloud-2

    //P-1
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234 );
    x=-35;
    y=78;
    radius =6;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-2
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234 );
    x=-41;
    y=73;
    radius =6;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-3
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234 );
    x=-47;
    y=67;
    radius =6;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-4
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234 );
    x=-40;
    y=66;
    radius =6;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();

    //P-5
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(183, 194, 234 );
    x=-33;
    y=70;
    radius =6;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();
    glPopMatrix();


    //House side background
    glBegin(GL_QUADS);
    glColor3ub(50,205,50);
    glVertex2i(-100,-20);
    glVertex2i(-100,-40);
    glVertex2i(100,-40);
    glVertex2i(100,-20);
    glEnd();


    //Road background
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2i(-100,-40);
    glVertex2i(-100,-100);
    glVertex2i(100,-100);
    glVertex2i(100,-40);
    glEnd();

    //Road Mark
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(253, 254, 254);
    glVertex2i(-100,-70);
    glVertex2i(-80,-70);
    glVertex2i(-70,-70);
    glVertex2i(-50,-70);
    glVertex2i(-60,-70);
    glVertex2i(-40,-70);
    glVertex2i(-30,-70);
    glVertex2i(-10,-70);
    glVertex2i(0,-70);
    glVertex2i(20,-70);
    glVertex2i(30,-70);
    glVertex2i(50,-70);
    glVertex2i(60,-70);
    glVertex2i(80,-70);
    glVertex2i(90,-70);
    glVertex2i(100,-70);
    glEnd();

    //Footpath
    glBegin(GL_QUADS);
    glColor3ub(148, 49, 38);
    glVertex2i(100,-40);
    glVertex2i(100,-35);
    glVertex2i(-100,-35);
    glVertex2i(-100,-40);
    glColor3ub(203, 67, 53  );
    glVertex2i(100,-25);
    glVertex2i(100,-35);
    glVertex2i(-100,-35);
    glVertex2i(-100,-25);
    glEnd();

    //Background House

    // Left 2nd Background
    glBegin(GL_QUADS);
    glColor3ub(23, 32, 42);
    glVertex2i(-101,-20);
    glVertex2i(-101,15);
    glVertex2i(-95,15);
    glVertex2i(-95,-20);
    glEnd();

    // Left 2nd Background
    glBegin(GL_QUADS);
    glColor3ub(23, 32, 42);
    glVertex2i(-55,-20);
    glVertex2i(-55,18);
    glVertex2i(-36,18);
    glVertex2i(-36,-20);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(93, 173, 226 );
    glVertex2i(-52,-5);
    glVertex2i(-52,15);
    glVertex2i(-42,15);
    glVertex2i(-42,-5);
    glEnd();

    //Tree-1 Draw

    //Tree Stand
    glBegin(GL_QUADS);
    glColor3ub(110, 44, 0);
    glVertex2i(-48,-25);
    glVertex2i(-48,-10);
    glVertex2i(-46,-10);
    glVertex2i(-46,-25);
    glEnd();

    //Tree Top-1
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(-55,-12);
    glVertex2i(-47,9);
    glVertex2i(-39,-12);
    glEnd();

    //Tree Top-2
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(-54,-5);
    glVertex2i(-47,15);
    glVertex2i(-40,-5);
    glEnd();

    //Tree Top-3
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(-53,2);
    glVertex2i(-47,22);
    glVertex2i(-41,2);
    glEnd();


    //Mosque Draw

    //Mosque Gombuj
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(94, 31, 125 );
    x=-76;
    y=25;
    radius =13;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();


    //Mosque design
    glBegin(GL_QUADS);
    glColor3ub(159, 164, 236);
    glVertex2i(-98,-22);
    glVertex2i(-98,23);
    glVertex2i(-54,23);
    glVertex2i(-54,-22);
    glEnd();


    //Mosque footer design
    glBegin(GL_QUADS);
    glColor3ub(94, 31, 125 );
    glVertex2i(-98,-22);
    glVertex2i(-99,-25);
    glVertex2i(-53,-25);
    glVertex2i(-54,-22);
    glEnd();



    //Mosque door design
    glBegin(GL_QUADS);
    glColor3ub(94, 31, 125 );
    glVertex2i(-81,-25);
    glVertex2i(-81,-1);
    glVertex2i(-71,-1);
    glVertex2i(-71,-25);
    glEnd();

    //Mosque door top design
    glBegin(GL_POLYGON);
    glColor3ub(94, 31, 125 );
    glVertex2i(-81,-1);
    glVertex2i(-82,1);
    glVertex2i(-76,12);
    glVertex2i(-70,1);
    glVertex2i(-71,-1);
    glEnd();


    //Mosque left 1st window design
    glBegin(GL_QUADS);
    glColor3ub(94, 31, 125 );
    glVertex2i(-89,-25);
    glVertex2i(-89,-6);
    glVertex2i(-83,-6);
    glVertex2i(-83,-25);
    glEnd();

    //Mosque left 1st window top design
    glBegin(GL_POLYGON);
    glColor3ub(94, 31, 125 );
    glVertex2i(-89,-6);
    glVertex2i(-90,-4);
    glVertex2i(-86.5,3);
    glVertex2i(-82,-4);
    glVertex2i(-83,-6);
    glEnd();


    //Mosque left 2nd window design
    glBegin(GL_QUADS);
    glColor3ub(94, 31, 125 );
    glVertex2i(-91,-25);
    glVertex2i(-91,-11);
    glVertex2i(-96,-11);
    glVertex2i(-96,-25);
    glEnd();

    //Mosque left 2nd window top design
    glBegin(GL_POLYGON);
    glColor3ub(94, 31, 125 );
    glVertex2i(-96,-11);
    glVertex2i(-97,-9);
    glVertex2i(-93.99,-1);
    glVertex2i(-90,-9);
    glVertex2i(-91,-11);
    glEnd();


    //Mosque right 1st window design
    glBegin(GL_QUADS);
    glColor3ub(94, 31, 125 );
    glVertex2i(-69,-25);
    glVertex2i(-69,-6);
    glVertex2i(-63,-6);
    glVertex2i(-63,-25);
    glEnd();

    //Mosque right 1st window top design
    glBegin(GL_POLYGON);
    glColor3ub(94, 31, 125 );
    glVertex2i(-69,-6);
    glVertex2i(-70,-4);
    glVertex2i(-66.5,4);
    glVertex2i(-62,-4);
    glVertex2i(-63,-6);
    glEnd();

    //Mosque right 2nd window design
    glBegin(GL_QUADS);
    glColor3ub(94, 31, 125 );
    glVertex2i(-61,-25);
    glVertex2i(-61,-11);
    glVertex2i(-56,-11);
    glVertex2i(-56,-25);
    glEnd();

    //Mosque right 2nd window top design
    glBegin(GL_POLYGON);
    glColor3ub(94, 31, 125 );
    glVertex2i(-61,-11);
    glVertex2i(-62,-9);
    glVertex2i(-58.5,-1);
    glVertex2i(-55,-9);
    glVertex2i(-56,-11);
    glEnd();

    //Mosque Top box design
    glBegin(GL_QUADS);
    glColor3ub(206, 230, 231 );
    glVertex2i(-99,23);
    glVertex2i(-99,20);
    glVertex2i(-53,20);
    glVertex2i(-53,23);
    glEnd();

    //Mosque Laft meaner design
    glBegin(GL_QUADS);
    glColor3ub(206, 230, 231 );
    glVertex2i(-98,60);
    glVertex2i(-98,23);
    glVertex2i(-94,23);
    glVertex2i(-94,60);
    glEnd();

    //Mosque Laft meaner art design
    glBegin(GL_QUADS);
    glColor3ub(94, 31, 125 );
    glVertex2i(-98,43);
    glVertex2i(-98,41);
    glVertex2i(-94,41);
    glVertex2i(-94,43);
    glEnd();

    //Mosque Laft meaner top design
    glBegin(GL_POLYGON);
    glColor3ub(94, 31, 125);
    glVertex2i(-98,60);
    glVertex2i(-99,62);
    glVertex2i(-96.5,70);
    glVertex2i(-93,62);
    glVertex2i(-94,60);

    glEnd();

    //Mosque Right meaner design
    glBegin(GL_QUADS);
    glColor3ub(206, 230, 231 );
    glVertex2i(-54,60);
    glVertex2i(-54,23);
    glVertex2i(-58,23);
    glVertex2i(-58,60);
    glEnd();

    //Mosque Right meaner art design
    glBegin(GL_QUADS);
    glColor3ub(94, 31, 125 );
    glVertex2i(-54,43);
    glVertex2i(-54,41);
    glVertex2i(-58,41);
    glVertex2i(-58,43);
    glEnd();

    //Mosque Laft meaner top design
    glBegin(GL_POLYGON);
    glColor3ub(94, 31, 125);

    glVertex2i(-58,60);
    glVertex2i(-59,62);
    glVertex2i(-56.5,70);
    glVertex2i(-53,62);
    glVertex2i(-54,60);

    glEnd();

    //Background House

    //Middle Right Background
    glBegin(GL_QUADS);
    glColor3ub(77, 86, 86);
    glVertex2i(-5,-20);
    glVertex2i(-5,30);
    glVertex2i(10,30);
    glVertex2i(10,-20);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(110, 178, 236);
    glVertex2i(-4,-10);
    glVertex2i(-4,25);
    glVertex2i(5,25);
    glVertex2i(5,-10);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-4, 20);
    glVertex2i(5, 20);
    glVertex2i(-4, 14);
    glVertex2i(5, 14);
    glVertex2i(-4, 8);
    glVertex2i(5, 8);
    glVertex2i(-4, 2);
    glVertex2i(5, 2);
    glVertex2i(-4, -4);
    glVertex2i(5, -4);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(151, 154, 154 );
    glVertex2i(4,-20);
    glVertex2i(4,25);
    glVertex2i(30,25);
    glVertex2i(30,-20);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(110, 178, 236);
    glVertex2i(6,-10);
    glVertex2i(6,22);
    glVertex2i(15,22);
    glVertex2i(15,-10);
    glEnd();


    //1st HOUSE DESIGN

    //Body Structure
    glBegin(GL_QUADS);
    glColor3ub(125, 206, 160);
    glVertex2i(-40,-22);
    glVertex2i(-40,40);
    glVertex2i(-4,40);
    glVertex2i(-4,-22);
    glEnd();

    //Building down
    glBegin(GL_QUADS);
    glColor3ub(100, 30, 22);
    glVertex2i(-40,-22);
    glVertex2i(-41,-25);
    glVertex2i(-3,-25);
    glVertex2i(-4,-22);
    glEnd();

    //Building top
    glBegin(GL_TRIANGLES);
    glColor3ub(135, 54, 0 );
    glVertex2i(-42,40);
    glVertex2i(-2,40);
    glVertex2i(-22,55);
    glEnd();

    //Building 2nd top
    glBegin(GL_QUADS);
    glColor3ub(135, 54, 0);
    glVertex2i(-42,5);
    glVertex2i(-40,10);
    glVertex2i(-4,10);
    glVertex2i(-2,5);
    glEnd();

    //Left top window
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0);
    glVertex2i(-37,35);
    glVertex2i(-29,35);
    glVertex2i(-29,14);
    glVertex2i(-37,14);
    glEnd();

    //Left top window design
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-33, 35);
    glVertex2i(-33, 14);

    glEnd();

    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-37, 24.5);
    glVertex2i(-29, 24.5);

    glEnd();

    //Middle top window
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0);
    glVertex2i(-26,35);
    glVertex2i(-18,35);
    glVertex2i(-18,14);
    glVertex2i(-26,14);
    glEnd();

    //Middle top window design
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-22, 35);
    glVertex2i(-22, 14);

    glEnd();

    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-26, 24.5);
    glVertex2i(-18, 24.5);

    glEnd();

    //Right top window
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0);
    glVertex2i(-15,35);
    glVertex2i(-7,35);
    glVertex2i(-7,14);
    glVertex2i(-15,14);
    glEnd();

    //Right top window design
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-11, 35);
    glVertex2i(-11, 14);

    glEnd();

    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-15, 24.5);
    glVertex2i(-7, 24.5);

    glEnd();

    //Left down window
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0);
    glVertex2i(-37,-18);
    glVertex2i(-29,-18);
    glVertex2i(-29,2);
    glVertex2i(-37,2);
    glEnd();

    //Left down window design
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-33, -18);
    glVertex2i(-33, 2);

    glEnd();

    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-37, -8);
    glVertex2i(-29, -8);

    glEnd();

    //Right down window
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0);
    glVertex2i(-15,-18);
    glVertex2i(-7,-18);
    glVertex2i(-7,2);
    glVertex2i(-15,2);
    glEnd();

    //Right down window design
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-11, -18);
    glVertex2i(-11, 2);

    glEnd();

    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-15, -8);
    glVertex2i(-7, -8);

    glEnd();

    //Door design
    glBegin(GL_QUADS);
    glColor3ub(46, 134, 193);
    glVertex2i(-26,-22);
    glVertex2i(-18,-22);
    glVertex2i(-18,0);
    glVertex2i(-26,0);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(-22, -22);
    glVertex2i(-22, 0);

    glEnd();


    //Tree 3 Draw

    //Tree Stand
    glBegin(GL_QUADS);
    glColor3ub(110, 44, 0);
    glVertex2i(9,-23);
    glVertex2i(9,-10);
    glVertex2i(11,-10);
    glVertex2i(11,-23);
    glEnd();

    //Tree Top-1
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(3,-11);
    glVertex2i(10,9);
    glVertex2i(17,-11);
    glEnd();

    //Tree Top-2
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(4,-5);
    glVertex2i(10,15);
    glVertex2i(16,-5);
    glEnd();

    //Tree Top-3
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(5,2);
    glVertex2i(10,21);
    glVertex2i(15,2);
    glEnd();


    //Background Right house Draw

    //House Part
    glBegin(GL_QUADS);
    glColor3ub(179, 182, 183 );
    glVertex2i(83,28);
    glVertex2i(83,-20);
    glVertex2i(102,-20);
    glVertex2i(102,28);
    glEnd();

    //House Left window Part
    glBegin(GL_QUADS);
    glColor3ub(23, 32, 42);
    glVertex2i(83,24);
    glVertex2i(83,20);
    glVertex2i(92,20);
    glVertex2i(92,24);
    glEnd();

    //House Right window Part
    glBegin(GL_QUADS);
    glColor3ub(23, 32, 42);
    glVertex2i(95,24);
    glVertex2i(95,20);
    glVertex2i(102,20);
    glVertex2i(102,24);
    glEnd();

    //House Middle window Part
    glBegin(GL_QUADS);
    glColor3ub(247, 249, 249 );
    glVertex2i(83,16);
    glVertex2i(83,12);
    glVertex2i(102,12);
    glVertex2i(102,16);
    glEnd();

    //House Down left  Part
    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107 );
    glVertex2i(86,10);
    glVertex2i(86,-20);
    glVertex2i(88,-20);
    glVertex2i(88,10);
    glEnd();

    //House Middle window Part
    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107 );
    glVertex2i(96,10);
    glVertex2i(96,-20);
    glVertex2i(98,-20);
    glVertex2i(98,10);
    glEnd();


    //Shopping Mall Design

    //Down part
    glBegin(GL_QUADS);
    glColor3ub(104, 35, 31);
    glVertex2i(85,-22);
    glVertex2i(86,-25);
    glVertex2i(14,-25);
    glVertex2i(15,-22);
    glEnd();

    //Left Down->1 part
    glBegin(GL_QUADS);
    glColor3ub(19, 47, 112 );
    glVertex2i(16,-22);
    glVertex2i(16,2);
    glVertex2i(36,2);
    glVertex2i(36,-22);
    glEnd();

    //Left ->2 part
    glBegin(GL_QUADS);
    glColor3ub(245, 103, 16);
    glVertex2i(15,6);
    glVertex2i(15,2);
    glVertex2i(36,2);
    glVertex2i(36,6);
    glEnd();

    //Left ->3 part
    glBegin(GL_QUADS);
    glColor3ub(19, 47, 112 );
    glVertex2i(16,6);
    glVertex2i(16,29);
    glVertex2i(36,29);
    glVertex2i(36,6);
    glEnd();

    //Left ->4 part
    glBegin(GL_QUADS);
    glColor3ub(80, 33, 18);
    glVertex2i(16,31);
    glVertex2i(16,29);
    glVertex2i(36,29);
    glVertex2i(36,31);
    glEnd();

    //Left Top part
    glBegin(GL_QUADS);
    glColor3ub(231, 76, 60);
    glVertex2i(13,39);
    glVertex2i(16,31);
    glVertex2i(36,31);
    glVertex2i(36,36);
    glEnd();

    //Right Down->1 part
    glBegin(GL_QUADS);
    glColor3ub(19, 47, 112 );
    glVertex2i(60,-22);
    glVertex2i(61.99,2);
    glVertex2i(84,2);
    glVertex2i(84,-22);
    glEnd();

    //Right ->2 part
    glBegin(GL_QUADS);
    glColor3ub(245, 103, 16);
    glVertex2i(60,6);
    glVertex2i(60,2);
    glVertex2i(85,2);
    glVertex2i(85,6);
    glEnd();

    //Right ->3 part
    glBegin(GL_QUADS);
    glColor3ub(19, 47, 112 );
    glVertex2i(60,6);
    glVertex2i(60,29);
    glVertex2i(84,29);
    glVertex2i(84,6);
    glEnd();

    //Right ->4 part
    glBegin(GL_QUADS);
    glColor3ub(80, 33, 18);
    glVertex2i(60,31);
    glVertex2i(60,29);
    glVertex2i(84,29);
    glVertex2i(84,31);
    glEnd();

    //Right Top part
    glBegin(GL_QUADS);
    glColor3ub(231, 76, 60);
    glVertex2i(60,36);
    glVertex2i(60,31);
    glVertex2i(84,31);
    glVertex2i(83,35);
    glEnd();


    //Gate body design
    glBegin(GL_QUADS);
    glColor3ub(234, 29, 16);
    glVertex2i(36,-22);
    glVertex2i(36,42);
    glVertex2i(66,49);
    glVertex2i(62,-22);
    glEnd();

    //Gate design
    glBegin(GL_QUADS);
    glColor3ub(19, 47, 112 );
    glVertex2i(43,-22);
    glVertex2i(43,0);
    glVertex2i(54,0);
    glVertex2i(54,-22);
    glEnd();

    //Gate Top box design
    glBegin(GL_QUADS);
    glColor3ub(110, 44, 0);
    glVertex2i(40,35);
    glVertex2i(60,35);
    glVertex2i(60,15);
    glVertex2i(40,15);
    glEnd();
    glColor3f(255,255,0);
    renderBitmapString(43,25,0,GLUT_BITMAP_TIMES_ROMAN_24, "*Aarong*");

    //Art in Market

    //Door Art

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(49, -22);
    glVertex2i(49, 0);

    glEnd();

    //Left Down part Art-1

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(20, -22);
    glVertex2i(20, 2);
    glEnd();

    //Left Down part Art-2

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(33, -22);
    glVertex2i(33, 2);
    glEnd();

    //Left Top part Art-1

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(20, 6);
    glVertex2i(20, 30);
    glEnd();

    //Left Top part Art-2

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(33, 6);
    glVertex2i(33, 30);
    glEnd();

    //Right Down part Art-1

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(66, -22);
    glVertex2i(66, 2);
    glEnd();

    //Left Down part Art-2

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(80, -22);
    glVertex2i(80, 2);
    glEnd();

    //Left Top part Art-1

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(66, 6);
    glVertex2i(66, 30);
    glEnd();

    //Left Top part Art-2

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(23, 32, 42 );
    glVertex2i(80, 6);
    glVertex2i(80, 30);
    glEnd();

    //Tree 2 Draw

    //Tree Stand
    glBegin(GL_QUADS);
    glColor3ub(110, 44, 0);
    glVertex2i(0,-25);
    glVertex2i(0,-10);
    glVertex2i(-2,-10);
    glVertex2i(-2,-25);
    glEnd();

    //Tree Top-1
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(-8,-12);
    glVertex2i(-1,9);
    glVertex2i(6,-12);
    glEnd();

    //Tree Top-2
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(-7,-5);
    glVertex2i(-1,15);
    glVertex2i(5,-5);
    glEnd();

    //Tree Top-3
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(-6,2);
    glVertex2i(-1,22);
    glVertex2i(4,2);
    glEnd();

    //Tree 4 Draw

    //Tree Stand
    glBegin(GL_QUADS);
    glColor3ub(110, 44, 0);
    glVertex2i(91,-25);
    glVertex2i(91,-10);
    glVertex2i(93,-10);
    glVertex2i(93,-25);
    glEnd();

    //Tree Top-1
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(84,-12);
    glVertex2i(92,9);
    glVertex2i(100,-12);
    glEnd();

    //Tree Top-2
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(85,-5);
    glVertex2i(92,15);
    glVertex2i(99,-5);
    glEnd();

    //Tree Top-3
    glBegin(GL_TRIANGLES);
    glColor3ub(53, 141, 11 );
    glVertex2i(86,2);
    glVertex2i(92,22);
    glVertex2i(98,2);
    glEnd();

    //Lamp Draw

    //Lamp 1
    glBegin(GL_QUADS);
    glColor3ub(33, 47, 61);
    glVertex2i(-70,-25);
    glVertex2i(-68,-25);
    glVertex2i(-68,0);
    glVertex2i(-70,0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(33, 47, 61);
    glVertex2f(-72,5);
    glVertex2f(-66,5);
    glVertex2f(-69,8);
    glEnd();


    //Light
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0 );
    glVertex2i(-68,0);
    glVertex2i(-70,0);
    glVertex2i(-71,5);
    glVertex2i(-67,5);
    glEnd();



    //Lamp 2
    glBegin(GL_QUADS);
    glColor3ub(33, 47, 61);
    glVertex2i(72,-25);
    glVertex2i(70,-25);
    glVertex2i(70,0);
    glVertex2i(72,0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(33, 47, 61);
    glVertex2f(74,5);
    glVertex2f(68,5);
    glVertex2f(71,8);
    glEnd();


    //Light
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0 );
    glVertex2i(70,0);
    glVertex2i(72,0);
    glVertex2i(73,5);
    glVertex2i(69,5);
    glEnd();

    //Lamp 3
    glBegin(GL_QUADS);
    glColor3ub(33, 47, 61);
    glVertex2i(-5,-25);
    glVertex2i(-7,-25);
    glVertex2i(-7,0);
    glVertex2i(-5,0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(33, 47, 61);
    glVertex2f(-9,5);
    glVertex2f(-3,5);
    glVertex2f(-6,8);
    glEnd();


    //Light
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0 );
    glVertex2i(-7,0);
    glVertex2i(-5,0);
    glVertex2i(-4,5);
    glVertex2i(-8,5);
    glEnd();

    glPushMatrix();
    glTranslatef(menPosition2,0.0f,0.0f);
//Man 1 fisherMan
    //Left Leg
    glBegin(GL_QUADS);
    glColor3ub(44, 80, 197);
    glVertex2i(-22,-40);
    glVertex2i(-21,-33);
    glVertex2i(-18,-33);
    glVertex2i(-20,-40);

    //Right leg
    glVertex2i(-18,-40);
    glVertex2i(-20,-33);
    glVertex2i(-17,-33);
    glVertex2i(-16,-40);
    glEnd();

    //Body
    glBegin(GL_POLYGON);
    glColor3ub(56, 225, 38 );
    glVertex2i(-21,-33);
    glVertex2i(-21,-26);
    glVertex2i(-19,-27);
    glVertex2i(-17,-26);
    glVertex2i(-17,-33);
    glEnd();

    //Left hand
    glBegin(GL_QUADS);
    glColor3ub(56, 225, 38 );
    glVertex2i(-22,-26);
    glVertex2i(-21,-26);
    glVertex2i(-21,-30);
    glVertex2i(-22,-30);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(-22, -30);
    glVertex2i(-21, -31);
    glEnd();


    //Right hand
    glBegin(GL_QUADS);
    glColor3ub(56, 225, 38 );
    glVertex2i(-17,-26);
    glVertex2i(-16,-26);
    glVertex2i(-16,-30);
    glVertex2i(-17,-30);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(-17, -30);
    glVertex2i(-16, -31);
    glEnd();



    //Shoe
    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(-18,-40);
    glVertex2i(-17,-38);
    glVertex2i(-16,-40);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(-22,-40);
    glVertex2i(-21,-38);
    glVertex2i(-20,-40);
    glEnd();


    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(-19, -27);
    glVertex2i(-19, -24);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250, 222, 157 );
    x=-19;
    y=-23;
    radius =2.5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Hair
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2i(-22,-22);
    glVertex2i(-20,-20);
    glVertex2i(-18,-20);
    glVertex2i(-16,-22);
    glEnd();

    //
    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2i(-8,-30);
    glVertex2i(-8,-32);
    glVertex2i(-10,-40);
    glVertex2i(-14,-40);
    glVertex2i(-16,-30);
    glEnd();
    glColor3f(255,0,0);
    renderBitmapString(-13,-34,0,GLUT_BITMAP_TIMES_ROMAN_10, "Fish");

    glPopMatrix();



//Man 5 guard
    //Left Leg
    glBegin(GL_QUADS);
    glColor3ub(128, 71, 71);
    glVertex2i(41,-25);
    glVertex2i(40,-17);
    glVertex2i(37,-17);
    glVertex2i(39,-25);

    //Right leg
    glVertex2i(37,-25);
    glVertex2i(39,-17);
    glVertex2i(36,-17);
    glVertex2i(35,-25);
    glEnd();

    //Body
    glBegin(GL_POLYGON);
    glColor3ub(128, 71, 71);
    glVertex2i(40,-18);
    glVertex2i(40,-10);
    glVertex2i(38,-11);
    glVertex2i(36,-10);
    glVertex2i(36,-18);
    glEnd();

    //Left hand
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2i(41,-10);
    glVertex2i(40,-10);
    glVertex2i(40,-14);
    glVertex2i(41,-14);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(41, -14);
    glVertex2i(40, -15);
    glEnd();


    //Right hand
    glBegin(GL_QUADS);
    glColor3ub(255,255,255 );
    glVertex2i(36,-10);
    glVertex2i(35,-10);
    glVertex2i(35,-14);
    glVertex2i(36,-14);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(35, -14);
    glVertex2i(36, -15);
    glEnd();

    //Shoe
    glBegin(GL_TRIANGLES);
    glColor3ub(1,0,0);
    glVertex2i(37,-25);
    glVertex2i(36,-23);
    glVertex2i(35,-25);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(41,-25);
    glVertex2i(40,-23);
    glVertex2i(39,-25);
    glEnd();


    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(249, 231, 159);
    glVertex2i(38, -11);
    glVertex2i(38, -8);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(250, 222, 157 );
    x=38;
    y=-7;
    radius =2.5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Hair
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2i(41,-6);
    glVertex2i(39,-4);
    glVertex2i(37,-4);
    glVertex2i(35,-6);
    glEnd();

    glPushMatrix();
    glTranslatef(vanPosition2,0.0f,0.0f);
    // Van body
    glBegin(GL_POLYGON);
    glColor3ub(253, 254, 254);
    glVertex2f(-90, -50);
    glVertex2f(-50, -50);
    glVertex2f(-51, -40);
    glVertex2f(-55, -35);
    glVertex2f(-60, -20);
    glVertex2f(-85, -20);
    glVertex2f(-90, -35);
    glEnd();
    //Fish sign
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0); // Fish Tail
    glVertex2f(-79, -33);
    glVertex2f(-72, -37);
    glVertex2f(-74, -33);
    glVertex2f(-72, -29);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 0, 0); // Fish body color
    glVertex2f(-87, -33);
    glVertex2f(-77, -39);
    glVertex2f(-77, -26);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0); // Fish  wings
    glVertex2f(-83, -33);
    glVertex2f(-81, -34);
    glVertex2f(-81, -32);
    glEnd();
    glPointSize(3.0f);
    glBegin(GL_POINTS);
    glColor3ub(0, 0, 255);//Fish Eye
    glVertex2f(-85,-33);
    glEnd();


    //Van glass
    glBegin(GL_QUADS);
    glColor3ub(52, 152, 219);
    glVertex2i(-61,-23);
    glVertex2i(-56,-35);
    glVertex2i(-66,-35);
    glVertex2i(-66,-23);
    glEnd();
    //Van bumper
    glBegin(GL_QUADS);
    glColor3ub(46, 64, 83);
    glVertex2i(-88,-50);
    glVertex2i(-91,-50);
    glVertex2i(-91,-46);
    glVertex2i(-88,-46);
    glVertex2i(-52,-50);
    glVertex2i(-52,-46);
    glVertex2i(-49,-46);
    glVertex2i(-49,-50);
    glEnd();

    //Van Light
    glBegin(GL_QUADS);
    glColor3ub(236, 67, 34);
    glVertex2i(-90,-35);
    glVertex2i(-89,-35);
    glVertex2i(-89,-40);
    glVertex2i(-90,-40);
    glColor3ub(251, 250, 32);
    glVertex2i(-51,-40);
    glVertex2i(-55,-40);
    glVertex2i(-55,-42);
    glVertex2i(-51,-42);
    glEnd();

    //Night Light
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0 );
    glVertex2i(-50,-43);
    glVertex2i(-50,-41);
    glVertex2i(-15,-45);
    glVertex2i(-30,-48);
    glEnd();


    //Van wheel-1
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=-61;
    y=-50;
    radius =6;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=-61;
    y=-50;
    radius =3;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Van wheel-2
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=-79;
    y=-50;
    radius =6;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=-79;
    y=-50;
    radius =3;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(carPosition2,0.0f,0.0f);
    //car body
    glBegin(GL_QUADS);
    glColor3ub(125, 60, 152);
    glVertex2i(50,-70);
    glVertex2i(85,-70);
    glVertex2i(87,-80);
    glVertex2i(48,-80);
    glVertex2i(58,-70);
    glVertex2i(61,-60);
    glVertex2i(76,-60);
    glVertex2i(78,-70);
    glEnd();

    //car glass
    glBegin(GL_QUADS);
    glColor3ub(52, 152, 219);
    glVertex2i(59,-70);
    glVertex2i(62,-61);
    glVertex2i(75,-61);
    glVertex2i(77,-70);
    glVertex2i(69,-70);
    glVertex2i(69,-61);
    glVertex2i(73,-61);
    glVertex2i(75,-70);
    glEnd();

    //car bumper
    glBegin(GL_QUADS);
    glColor3ub(46, 64, 83);
    glVertex2i(46,-80);
    glVertex2i(53,-80);
    glVertex2i(53,-76);
    glVertex2i(46,-76);
    glVertex2i(88,-80);
    glVertex2i(82,-80);
    glVertex2i(82,-76);
    glVertex2i(88,-76);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2i(69,-80);
    glVertex2i(69,-60);
    glVertex2i(58,-70);
    glVertex2i(78,-70);
    glEnd();

    //car Light
    glBegin(GL_QUADS);
    glColor3ub(236, 67, 34);
    glVertex2i(84,-70);
    glVertex2i(85,-70);
    glVertex2i(85,-75);
    glVertex2i(84,-75);
    glColor3ub(226, 224, 224);
    glVertex2i(51,-70);
    glVertex2i(49,-70);
    glVertex2i(49,-72);
    glVertex2i(51,-72);
    glEnd();

    //Front Light Night
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0 );
    glVertex2i(49,-73);
    glVertex2i(49,-70);
    glVertex2i(14,-76);
    glVertex2i(29,-79);
    glEnd();

    //Car wheel-1
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=60;
    y=-80;
    radius =5;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=60;
    y=-80;
    radius =3;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Car wheel-2
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=75;
    y=-80;
    radius =5;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=75;
    y=-80;
    radius =3;
    twicePi = 2.0f * PI;
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    glPopMatrix();


    glPushMatrix();
    glTranslatef(policecarPosition,0.0f,0.0f);

    //Police Car
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2i(45,-90);
    glVertex2i(48,-78);
    glVertex2i(57,-75);
    glVertex2i(65,-65);
    glVertex2i(83,-65);
    glVertex2i(86,-75);
    glVertex2i(93,-75);
    glVertex2i(95,-90);
    glEnd();

    //Front window
    glBegin(GL_QUADS);
    glColor3ub(35, 148, 186);
    glVertex2i(65,-67);
    glVertex2i(73,-67);
    glVertex2i(73,-74);
    glVertex2i(60,-74);
    glEnd();

    //Back window
    glBegin(GL_QUADS);
    glColor3ub(35, 148, 186);
    glVertex2i(74,-67);
    glVertex2i(82,-67);
    glVertex2i(84,-74);
    glVertex2i(74,-74);
    glEnd();

    //Body Art
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(35, 57, 186);
    glVertex2i(52, -80);
    glVertex2i(88, -80);
    glEnd();

    //Front art
    glBegin(GL_QUADS);
    glColor3ub(40, 55, 71 );
    glVertex2i(44,-90);
    glVertex2i(48,-90);
    glVertex2i(48,-87);
    glVertex2i(44,-87);
    glEnd();

    //Back art
    glBegin(GL_QUADS);
    glColor3ub(40, 55, 71 );
    glVertex2i(92,-90);
    glVertex2i(97,-90);
    glVertex2i(97,-87);
    glVertex2i(92,-87);
    glEnd();

    //Front Light art
    glBegin(GL_QUADS);
    glColor3ub(247, 43, 43 );
    glVertex2i(47,-82);
    glVertex2i(50,-82);
    glVertex2i(50,-79);
    glVertex2i(48,-79);
    glEnd();

    //Back Light art
    glBegin(GL_QUADS);
    glColor3ub(247, 43, 43 );
    glVertex2i(91,-82);
    glVertex2i(94,-82);
    glVertex2i(93,-79);
    glVertex2i(91,-79);
    glEnd();

    //Top Light
    glBegin(GL_QUADS);
    glColor3ub(189, 8, 8 );
    glVertex2i(67,-65);
    glVertex2i(69,-65);
    glVertex2i(69,-63);
    glVertex2i(67,-63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(8, 68, 189 );
    glVertex2i(69,-65);
    glVertex2i(71,-65);
    glVertex2i(71,-63);
    glVertex2i(69,-63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(189, 8, 8 );
    glVertex2i(71,-65);
    glVertex2i(73,-65);
    glVertex2i(73,-63);
    glVertex2i(71,-63);
    glEnd();

    //Front Light Night
    glBegin(GL_QUADS);
    glColor3ub(251, 250, 0 );
    glVertex2i(45,-82);
    glVertex2i(45,-79);
    glVertex2i(10,-84);
    glVertex2i(25,-87);
    glEnd();

    //Front tire
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=60;
    y=-90;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


    //Front Tire middle
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=60;
    y=-90;
    radius =3;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


    //Back Tire
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40, 55, 71 );
    x=80;
    y=-90;
    radius =5;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Back Tire Middle
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(153, 163, 164);
    x=80;
    y=-90;
    radius =3;

    twicePi = 2.0f * PI;


    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    glPopMatrix();



    glFlush();

}

void update(int value)
{
    sunPosition1-=sunSpeed1;
    cloudPosition1+=couldSpeed1;
    cloudPosition2+=couldSpeed2;
    policecarPosition-=policecarSpeed;
    vanPosition2+=vanspeed2;
    carPosition2-=carSpeed2;
    hujurPosition2+=hujurspeed1;
    hujurPosition1-=hujurspeed1;
    bmenPosition1+=hujurspeed1;
    emenPosition1-=hujurspeed1;
    lmenPosition1-=hujurspeed1;
    MplasticPosi -= MplasticSpeed;
    MouthPosition+=MouthSpeed;
    // printf("%f\n",emenPosition1);

    if(hujurPosition1<-18)
        hujurPosition1=200;

    if(hujurPosition2>170)
        hujurPosition2=-30;

    if(bmenPosition1>43)
        bmenPosition1=-180;

    if(emenPosition1<-160)
        emenPosition1=50;

    if(vanPosition2>195)
    {
        vanPosition2=-40;
        menPosition2=0;

    }
    if(vanPosition2>88 && vanPosition2<93)
    {
        vanPosition2-=1.95;//van break

    }
    if(vanPosition2>88)
    {
        menPosition2+=menspeed2;
        if(menPosition2>28)
        {
            menPosition2+=1.5;
        }

//     printf("%f\n",menPosition2);
    }

    if(carPosition2<-180)
        carPosition2=70;




    if(sunPosition1<-180)
    {
        sunPosition1=30;
    }

    if(cloudPosition1>180)
    {
        cloudPosition1=-30;
    }
    if(cloudPosition2>150)
    {
        cloudPosition2=-70;
    }
    if(policecarPosition<-200)
    {
        policecarPosition=50;
    }


    sunPosition2-=sunSpeed2;
    cloudPosition3+=couldSpeed3;
    cloudPosition4+=couldSpeed4;
    carPosition1-=carSpeed1;
    vanPosition1+=vanspeed1;
    basketPosition-=basketspeed;
    policecarPosition2-=policecarSpeed2;


    if(sunPosition2<-180)
        sunPosition2=30;
    if(cloudPosition3>190)
        cloudPosition3=-30;
    if(cloudPosition4>150)
        cloudPosition4=-80;
    if(carPosition1<-180)
        carPosition1=70;
    if(vanPosition1>195)
        vanPosition1=-40;
    if(policecarPosition2<-200)
        policecarPosition2=50;

    if(vanPosition1>96 && vanPosition1<99)
    {
        vanPosition1-=1.95;           //van break
        basketPosition=0;
    }


    if(basketPosition<-23)
        basketPosition=vanPosition1;

    if(MplasticPosi <-70)
        MplasticPosi = -9;
    if(MouthPosition >3)
        MouthPosition = 1;



    glutPostRedisplay();


    glutTimerFunc(100, update, 0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1200, 600);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Fish catching from river to restaurant");
    init();
    glutDisplayFunc(display1N);
    glutTimerFunc(1, update, 0);
    glutPostRedisplay();

    //sndPlaySound("waterdrops.wav",SND_ASYNC);
    glutMainLoop();
    return 0;

}

