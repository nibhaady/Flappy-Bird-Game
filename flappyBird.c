#include <stdio.h>
#include <conio.h>
#include <GL/glut.h>
#include <math.h>

float shift = 0;
float xpos=0;
int yaxis,xaxis;
int count=0;
int start=0;
int pipestatus=1;
float pipex=0;
float pipey=0;
int meghStatus = 1;
float meghX = 0;
float meghY = 0;
float sunX = 0;
float sunY = 0;
int sunStatus =  1;
int boatStatus = 1;
int boatStatus1 = 1;
float boatX = 0;
float boatY = 0;
float boatX2 = 0;
float boatY2 = 0;


//---------------------------------------CIRCLE USED FOR CLOUDS,BIRD BODY,SUN----------------------------------
void movepipe()


		{
			if (pipestatus == 1)
			{
				pipey +=.1;
			}
			if (pipex>1500)
			{
				pipex = -200;
			}
			glPushMatrix();
			glTranslatef(pipex, pipey, 0);
			drawpipe();
			glPopMatrix();




		}

void DrawCircle(float cx, float cy, float r, int num_segments){

        glBegin(GL_TRIANGLE_FAN);
		for (int i = 0; i < num_segments; i++)
		{
		float theta = 2.0 * 3.1415926 * i / num_segments;//get the current angle

		float x = 1.5*r * cos(theta);//calculate the x component
		float y = 1.5*r * sin(theta);//calculate the y component

		glVertex2f(x + cx, y + cy);//output vertex

		}
		glEnd();
	}

//------------------------------------------------BIRD BEAK,WINGS-----------------------------------
void beak_wings(int x1,int y1,int x2,int y2,int x3,int y3)
	{
	    glBegin(GL_TRIANGLES);

	    glVertex2d(x1,y1);

	    glVertex2d(x2,y2);

	    glVertex2d(x3,y3);
	    glEnd();

	}
	void triangle(int x1,int y1,int x2,int y2,int x3,int y3)
	{
	    glBegin(GL_TRIANGLES);
        glColor3f(0.439216, 0.858824, 0.576471);
	    glVertex2d(x1,y1);
	    glColor3f(0.309804,0.309804,0.184314);
	    glVertex2d(x2,y2);
	    glColor3f(0.137255,0.556863,0.137255);
	    glVertex2d(x3,y3);
	    glEnd();

	}
	void bird()
{   xaxis=xpos+170;
    yaxis=shift+510;
    glColor3f( 0.71,0.65,0.26);
    beak_wings(100+xpos,490+shift,100+xpos,520+shift,170+xpos,510+shift);

    glColor3f(1,1,0);
    beak_wings(60+xpos,520+shift,60+xpos,480+shift,100+xpos,500+shift);
    glColor3f(1,1,0);
    DrawCircle(100+xpos, 500+shift, 15, 200);
    glColor3f(1,1,0);
    DrawCircle(130+xpos,510+shift,9,100);
    glColor3f(0.0,0.0,0.0);
    DrawCircle(130+xpos,515+shift,2,100);


}


//--------------------------------------------------MORNING-----------------------------------------------------
void drawSun()
	{
		glColor3f(3.0, 1.0, 0.5);
		DrawCircle(400, 1200, 70, 1000);
	}
//SUN SETTING
void moveSun()
	{


		 if(sunStatus == 1)
		  {
				 if (sunY>=350)
				 sunY=350;
				 else
					sunY += .1;
		  }

			  glPushMatrix();

			 glTranslatef(sunX, sunY, 0);

     		 drawSun();
			 glPopMatrix();


	}

		void hills(){


		triangle(0,0,350,500,700,0);
		triangle(600,0,800,300,1000,0);
		triangle(800,0,1200,600,1500,0);

		triangle(1150,0,1700,700,2100,0);
		triangle(1450,0,1600,200,1700,0);


	}
	void pipe(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4 )
	{

	    glBegin(GL_QUADS);
	    glColor3f(1,1,0);

	    glVertex2f(x1,y1);

        glColor3f(0.858824,0.439216,0.858824);
	    glVertex2f(x2,y2);


	    glVertex2f(x3,y3);

	    glVertex2f(x4,y4);
	    glEnd();
	}



	void drawpipe()
	{
	    pipe(600,0,600,600,650,600,650,0);
	    pipe(850,0,850,400,900,400,900,0);
	    pipe(850,1500,850,650,900,650,900,1500);
	    pipe(600,1500,600,900,650,900,650,1500);
	    pipe(1200,1500,1200,1000,1250,1000,1250,1500);
	    pipe(1200,0,1200,600,1250,600,1250,0);
	    pipe(1200,1500,1200,1000,1250,1000,1250,1500);
	    pipe(1200,0,1200,600,1250,600,1250,0);
	    pipe(1500,1500,1500,650,1550,650,1550,1500);
	    pipe(1500,0,1500,450,1550,450,1550,0);
	}



	void clouds(){




	glColor3f(1.0, 1.0, 1.0);
	DrawCircle(100, 1300, 60, 200);//1
	DrawCircle(200,1300, 90, 2000);//2
	DrawCircle(300, 1300, 65, 2000);//3


	DrawCircle(700, 1300, 60, 2000);//1
	DrawCircle(800,1300, 80, 2000);//2
	DrawCircle(900, 1300, 55, 2000);//3

	DrawCircle(1100, 1300, 60, 2000);//1
	DrawCircle(1200,1300, 80, 2000);//2
	DrawCircle(1300, 1300, 55, 2000);//3

	DrawCircle(1700, 1300, 60, 2000);//1
	DrawCircle(1800,1300, 80, 2000);//2
	DrawCircle(1900, 1300, 55, 2000);//3


	}
	void sky(){

	glBegin(GL_POLYGON); //Sky

    glColor3f(0.576471,0.858824,0.439216);
	glVertex2i(0, 1500);

    glColor3f( 0.74902,0.847059,0.847059);
	glVertex2i(2000, 1500);

	glColor3f(0.22,0.69,0.87);
	glVertex2i(2000, 0);
	glColor3f(0.196078,0.6,0.8);
	glVertex2i(0, 0);
	glEnd();



	}



	void movemegh()


		{
			if (meghStatus == 1)
			{
				meghX +=.1;
			}
			if (meghX>1000)
			{
				meghX = -200;
			}
			glPushMatrix();
			glTranslatef(meghX, meghY, 0);
			clouds();
			glPopMatrix();




		}


//--------------------------------------------------EVENING-----------------------------------------------------
void moveboat1(int x)
	{
    glBegin(GL_QUADS); //BOAT BODY

	glColor3f(0.91,0.76,0.65);
	glVertex2i(100,300);
	glVertex2i(300, 300);
	glColor3f(0.65,0.50,0.39);
	glVertex2i(380,400);
	glColor3f(0.36,0.20,0.09);
	glVertex2i(50,400);
	glColor3f(0.52,0.37,0.26);
	glVertex2i(100,300);
    glEnd();

	glBegin(GL_POLYGON); //BOAT HEAD
	glColor3f(1,1,0);
	glVertex2i(120,400);
	glColor3f(0.29,0.46,0.43);
	glVertex2i(200, 400);
	glVertex2i(160,460);
	glEnd();


	}

	void moveboat2(int x)
	{
    glBegin(GL_QUADS); //BOAT BODY

	glColor3f(0.91,0.76,0.65);
	glVertex2i(1000,300);
	glVertex2i(1300, 300);
	glColor3f(0.65,0.50,0.39);
	glVertex2i(1380,400);
	glColor3f(0.36,0.20,0.09);
	glVertex2i(950,400);
	glColor3f(0.52,0.37,0.26);
	glVertex2i(1000,300);
    glEnd();

	glBegin(GL_POLYGON); //BOAT HEAD
	glColor3f(1,1,0);
	glVertex2i(1120,400);
	glColor3f(0.29,0.46,0.43);
	glVertex2i(1200, 400);
	glVertex2i(1160,460);
	glEnd();


	}
	//BOAT MOVING FROM LEFT TO RIGHT
	void boat()
	{
		if (boatStatus == 1)
		{
			boatX +=.1;
		}

		glPushMatrix();
		glTranslatef(boatX, boatY, 0);
		moveboat1(1);
		glPopMatrix();
	}

	//BOAT MOVING FROM RIGHT TO LEFT
	void boat2()
	{
		if (boatStatus1 == 1)
		{
			boatX2 -=.1;
		}

		glPushMatrix();
		glTranslatef(boatX2, boatY2, 0);
		moveboat2(1);
		glPopMatrix();
	}


void eveningsky()
{
    glBegin(GL_POLYGON); //Sky


    glColor3f(1,1,0);
	glVertex2i(0, 1500);

    glColor3f(1,0,0);


	glVertex2i(2000, 1500);


	glVertex2i(2000, 0);

	glColor3f(0.8,0.498039,0.196078);
	glVertex2i(0, 0);
	glEnd();


	glBegin(GL_POLYGON); //Sky


    glColor3f(0.439216,0.576471,0.858824);
	glVertex2i(0, 500);

    glColor3f(0.560784,0.560784,0.737255);


	glVertex2i(0, 0);


	glVertex2i(2000, 0);

	glColor3f( 0.74902,0.847059,0.847059);
	glVertex2i(2000, 500);
	glEnd();


    glBegin(GL_POLYGON); //Sky


    glColor3f(0.560784,0.560784,0.737255);
	glVertex2i(0, 350);

    glColor3f(0.560784,0.560784,0.737255);


	glVertex2i(0, 0);


	glColor3f(0.439216,0.576471,0.858824);
	glVertex2i(2000, 0);

	glColor3f( 0.74902,0.847059,0.847059);
	glVertex2i(2000, 200);
	glEnd();


	glBegin(GL_POLYGON); //Sky


    glColor3f(1,1,1);
	glVertex2i(200, 0);

    glColor3f(0.560784,0.560784,0.737255);


	glVertex2i(400, 0);


	glColor3f(0.439216,0.576471,0.858824);
	glVertex2i(2000, 400);

	glColor3f( 0.74902,0.847059,0.847059);
	glVertex2i(2000, 0);
	glEnd();




     boat();
     boat2();
     drawpipe();
     bird();
     glFlush();




}

void evening()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,1.0f,1.0f);
    //hills();
    eveningsky();


    glFlush();



}

//DRAWING BOATS=>

//-------------------------------------------------NGHT-------------------------------------------------------
void drawMoon()
	{
		glColor3f(0.8f, 0.6f, 0.2f);//golden color
DrawCircle(400, 1100, 100, 360);

glColor3f(0,0,0);
DrawCircle(425, 1110, 90, 360);
	}






void star(float x1, float y1,float distance, float height)
{
    float x2 = x1 + distance, y2 = y1, x3 = x2, y3 = y2 + distance, x4 = x1, y4 = y3;


    glBegin(GL_QUADS);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);

        glVertex2f(x3, y3);
        glVertex2f(x4, y4);
    glEnd();
   glBegin(GL_TRIANGLES);
    //bottom
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x1+(distance/2) , y2-height);
    //right
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glVertex2f(x2+height,y2+(distance/2));
    //top
        glVertex2f(x3,y3);
        glVertex2f(x4,y4);
        glVertex2f(x1+(distance/2), y4+height);
    //left
        glVertex2f(x4,y4);
        glVertex2f(x1,y1);
        glVertex2f(x1-height,y1+(distance/2));
    glEnd();

}




void house()
{


	glBegin(GL_POLYGON); //Middle ground
	glColor3f(0.0, 0.8, 0.0);
	glVertex2i(0, 0);
	glVertex2i(2000,0);
	glVertex2i(2000, 200);
	glVertex2i(1000,0);
	glColor3f(0.1, 0.9, 0.1);
	glVertex2i(0,0);
	glVertex2i(2000, 200);
	glVertex2i(550, 300);
	glVertex2i(0, 500);
	glEnd();


	glBegin(GL_POLYGON); //House front
	glColor3f(0.5, 0.2, 0.1);
	glVertex2i(100, 100);
	glVertex2i(350, 100);
	glVertex2i(350, 250);
	glVertex2i(100, 250);
	glEnd();




	glBegin(GL_POLYGON); //House right base
	glColor3f(1.0, 0.3, 0.2);
	glVertex2i(90, 80);
	glVertex2i(355, 80);
	glVertex2i(350, 100);
	glVertex2i(100, 100);
	glEnd();

	glBegin(GL_POLYGON); //House door
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(200, 100);
	glVertex2i(250, 100);
	glVertex2i(250, 200);
	glVertex2i(200, 200);
	glEnd();


	glBegin(GL_POLYGON); //right roof
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(100, 250);
	glVertex2i(350, 250);
	glVertex2i(300, 400);
	glVertex2i(50, 400);
	glEnd();



	glBegin(GL_POLYGON); //left roof
	glColor3f(0.6, 0.3, 0.1);
	glVertex2i(25, 275);
	glVertex2i(100, 250);
	glVertex2i(50, 400);

	glEnd();




	glBegin(GL_POLYGON); //left wall
	glColor3f(0.9, 0.2, 0.16);
	glVertex2i(25, 150);
	glVertex2i(100, 100);
	glVertex2i(100, 250);
	glVertex2i(25, 275);
	glEnd();




	glBegin(GL_POLYGON); //House base left side
	glColor3f(0.3, 0.3, 0.1);
	glVertex2i(20, 130);
	glVertex2i(90,80 );
	glVertex2i(100, 100);
	glVertex2i(25, 150);
	glEnd();



	glBegin(GL_POLYGON); //1st window
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(50, 210);
	glVertex2i(75, 200);
	glVertex2i(75, 240);
	glVertex2i(50, 250);
	glEnd();




	glBegin(GL_POLYGON); //2nd window
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(125, 200);
	glVertex2i(150, 200);
	glVertex2i(150, 240);
	glVertex2i(125, 240);
	glEnd();

	glBegin(GL_POLYGON); //3rd window
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(300, 200);
	glVertex2i(325, 200);
	glVertex2i(325, 240);
	glVertex2i(300, 240);
	glEnd();

        glBegin(GL_POLYGON); //Grass
	glColor3f(0.0, 0.6, 0.3);
	glVertex2i(495, 110);
	glVertex2i(480, 130);
	glVertex2i(470, 140);
	glVertex2i(490, 130);
	glVertex2i(480, 160);
	glVertex2i(500, 130);
	glVertex2i(505, 180);
	glColor3f(0.8, 0.8, 0.1);
	glVertex2i(510, 140);
	glVertex2i(530, 160);
	glVertex2i(520, 130);
	glVertex2i(540, 140);
	glVertex2i(530, 130);
	glVertex2i(515, 110);
	glEnd();

	glBegin(GL_POLYGON); //Grass
	glColor3f(0.0, 0.6, 0.1);
	glVertex2i(635, 100);
	glVertex2i(620, 120);
	glVertex2i(610, 130);
	glVertex2i(630, 120);
	glVertex2i(620, 150);
	glVertex2i(640, 130);
	glVertex2i(645, 170);
	glColor3f(0.8, 0.8, 0.1);
	glVertex2i(650, 130);
	glVertex2i(670, 150);
	glVertex2i(660, 120);
	glVertex2i(680, 130);
	glVertex2i(670, 120);
	glVertex2i(655, 100);
	glEnd();

}

void nightsky()
{
    glBegin(GL_POLYGON); //Sky

    //glColor3f(0.372549,0.623529,0.623529);

    glColor3f(0,0,0);
	glVertex2i(0, 1500);
    glColor3f(0,0,0);
    //glColor3f(0.258824,0.258824,0.435294);
	glVertex2i(2000, 1500);

	//glColor3f(0.419608,0.137255,0.556863);
	//glColor3f(1,1,1);
	glVertex2i(2000, 0);
	//glColor3f(0.196078,0.6,0.8);
	glColor3f(1,1,1);
	glVertex2i(0, 0);
	glEnd();
    //moon
    drawMoon();

    //stars
    glColor3f(0.85,0.85,0.10);
    star(0,997,10,20);
    star(111,1066,10,20);
    star(215,1290,10,20);
    star(530,1371,10,20);
    star(645,1195,10,20);
    star(760,1075,10,20);
    star(876,965,10,20);
    star(986,1385,10,20);
    star(1020,1267,10,20);
    star(1100,1376,10,20);
    star(1200,1222,10,20);
    star(1300,1116,10,20);
    star(1400,1195,10,20);
    star(1500,1175,10,20);
    star(1600,1165,10,20);
    star(1700,1123,10,20);
    star(1800,1098,10,20);
    star(1900,1157,10,20);
    star(1960,885,10,20);
    house();
    drawpipe();
    bird();



}

void nightMode()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,1.0f,1.0f);

    nightsky();


    glFlush();

}







//---------------------------------------------TO DISPLAY MORNING WINDOW----------------------------
	   void myDisplay(void)
	{


			 sky();

             moveSun();

             hills();
             //movepipe();
             drawpipe();
             movemegh();

             bird();


			 glFlush();
}

//--------------------------------------------------GAME OVER FUNCTION----------------------------------
void gameEnd()
{



    printf("GAME OVER!!\n");
    printf("SCORE:%d",count);

    exit(0);


}
//---------------------------------------------------FRONT WINDOW------------------------------------
void front_display()
{

    glColor3f(0.52,0.39,0.39);
    glBegin(GL_LINES);


    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(600.0,500.0);
    glVertex2f(600.0,1200.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(600.0,1200.0);
    glVertex2f(1200.0,1200.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(1200.0,1200.0);
    glVertex2f(1200.0,500.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(1200.0,500.0);
    glVertex2f(600.0,500.0);
    glEnd();


 char string2[]="FLAPPY BIRD";
  glColor3f( 0.0, 1.0, 1.0);
  glRasterPos2f(780.0,900.0);
  int len, i;
  len = (int)strlen(string2);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string2[i]);
  }

  char string[]="COMPUTER GRAPHICS PROJECT";

  glColor3f( 1.0, 0.0, 1.0);
  glRasterPos2f(650.0,700.0);

  len = (int)strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
  }








  glFlush();









}

//--------------------------------------TO DISPLAY EVENING AND NIGHT MODE-----------------------------

	void myDisplay2()
	{


       if(start<=1000)//start value is used so that front window remains for some time
       {

          front_display();
          start++;
          glutPostRedisplay();
       }









 	    else if(xpos<=2000 && count<=1865)//condition is true till bird reaches the end of morning window
        {
            myDisplay();
            xpos+=1;

             count++;
             //conditions to check if the beak is hitting any of the poles
             if(xaxis==600&& (yaxis<600 || yaxis>900))
             {
                 gameEnd();

             }
             if(xaxis==850&& (yaxis<400 || yaxis>650))
             {
                 gameEnd();

             }
             if(xaxis==1200&& (yaxis<600 || yaxis>1000))
             {
                 gameEnd();

             }
             if(xaxis==1500&& (yaxis<450 || yaxis>650))
             {
                 gameEnd();

             }


            glutPostRedisplay();


        }
        else

        {




            if(count==1866)//count==1866 if you reach the end of morning window
        {
            xpos-=2000;//subtract 2000 from xpos so that your x axis position of the bird is set back to 0(left most end of the screen)
        }

        if(count<4378){//condition true if ur still in the evening window
            xpos+=0.8;
            evening();
            count++;

            if(xaxis==600&& (yaxis<600 || yaxis>900))
             {
                 gameEnd();

             }
             if(xaxis==850&& (yaxis<400 || yaxis>650))
             {
                 gameEnd();

             }
             if(xaxis==1200&& (yaxis<600 || yaxis>1000))
             {
                 gameEnd();

             }
             if(xaxis==1500&& (yaxis<450 || yaxis>650))
             {
                 gameEnd();

             }



            glutPostRedisplay();
        }


       else
       {
              if(count==4378)
        {
            xpos-=2000;
        }

            xpos+=0.8;
            nightMode();
            count++;

            if(xaxis==600&& (yaxis<600 || yaxis>900))
             {
                 gameEnd();

             }
             if(xaxis==850&& (yaxis<400 || yaxis>650))
             {
                 gameEnd();

             }
             if(xaxis==1200&& (yaxis<600 || yaxis>1000))
             {
                 gameEnd();

             }
             if(xaxis==1500&& (yaxis<450 || yaxis>650))
             {
                 gameEnd();

             }
            if(count==6955)//condition becomes true when you reach end of night window
             {
                 printf("CONGRATULATIONS!!\n");
                 printf("YOU WON!!\n");
                 printf("SCORE:%d",count);

                 exit(0);
             }



            glutPostRedisplay();

       }

            }











}


//------------------------------CONTROLLING MOVEMENT OF THE BIRD-----------------------------------------
void key(int key, int x, int y) {
	switch (key)
	{



	case GLUT_KEY_DOWN:
		shift=shift-6;

		glutPostRedisplay();
		break;
	case GLUT_KEY_UP:
		shift=shift+6;

		glutPostRedisplay();
		break;



	}



}



void myInit(void)
{
	glClearColor(0.0, 0.0, 1.0, 0.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 2000.0, 0.0, 1500.0);
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(2000, 1500);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("Flappy bird");

	glutDisplayFunc(myDisplay2);
	myInit();

	glutSpecialFunc(key);


	glutMainLoop();
	return 0;
}
