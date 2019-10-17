#include<GL/glut.h>
#include<math.h>


float flag_colors[3][3]={
0.0313f,0.396f,0.133f,
0.972f,0.094f,0.580f,
1.0,0.76f,0.0f
};


void timer(int  a);

double rotation_angle = 0.0;


void draw_spokes(double x1, double y1, double radius,int number)
{ 
	const float PI = 3.14156;
	double angle;

	glBegin(GL_LINES);
        for(int i=0; i<number;++i)
        {
                        angle = 2*PI/number *i;
			
                        glVertex2d(x1,y1);
                        glVertex2d(x1+radius*cos(angle),y1+ radius*sin(angle));


                        //draw_spokes(xc,yc,xc+radius*cos(angle), yc+radius*sin(angle));
         }
       	 glEnd();

	
}

void draw_transparent_wheel(double xc, double yc,double radius)
{
	 //float radius = 8.0;
        const float PI= 3.14156;

        double angle;

        glBegin(GL_LINE_LOOP);
        for(int i=0; i<32;++i)
        {
                        angle = 2*PI/32 *i;
                        glVertex2d(xc+ radius*cos(angle),yc+radius*sin(angle));

                        //draw_spokes(xc,yc,xc+radius*cos(angle), yc+radius*sin(angle));
        }
        glEnd();

}

void draw_wheel(double xc, double yc,double radius)
{
        //float radius = 8.0;
        const float PI= 3.14156;

        double angle;

        glBegin(GL_POLYGON);
        for(int i=0; i<32;++i)
        {
                        angle = 2*PI/32 *i;
                        glVertex2d(xc+ radius*cos(angle),yc+radius*sin(angle));

			//draw_spokes(xc,yc,xc+radius*cos(angle), yc+radius*sin(angle));
        }
        glEnd();

}



void draw_flags(double x, double y,  double width,double height,int color)
{
	

        glColor3f(0.396,0.262,0.129);
	
	glBegin(GL_QUADS);
       
	glVertex2d(x,y);
	glVertex2d(x+width,y);
	glVertex2d(x+width,y+height);
	glVertex2d(x,y+height);

        glEnd();

	
	glColor3f(flag_colors[color][0],flag_colors[color][1],flag_colors[color][2]);
	glBegin(GL_TRIANGLES);
		glVertex2d(x+width,y+height);
		glVertex2d(x+width , y+height*0.7);
		glVertex2d(x+width*4.0 , y+height);
	glEnd();

}



void draw_seat(double xc,double yc,double radius)
{

	const float PI = 3.14156;
        double angle;

	double x,y;
	  for(int i=0; i<14;++i)
        {
                        angle = 2*PI/14 *i;
                        //glVertex2d(x1,y1);
                        //glVertex2d(x1+radius*cos(angle),y1+ radius*sin(angle));

			x = xc+radius*cos(angle+rotation_angle);
			y = yc+ radius*sin(angle+rotation_angle);
			  glBegin(GL_LINES);
				glColor3f(flag_colors[i%3][0],flag_colors[i%3][1],flag_colors[i%3][2]);


        			glVertex2d(x,y);
        			glVertex2d(x,y-0.3);
        		  glEnd();
        		  glBegin(GL_TRIANGLES);
        			glVertex2d(x,y-0.3);
        			glVertex2d(x-0.6,y-0.9);

        			glVertex2d(x+0.6,y-0.9);


        		glEnd();

			glLineWidth(1.0);
			glColor3f(0.0,0.0,0.0);
			glBegin(GL_LINE_LOOP);
                                glVertex2d(x,y-0.3);
                                glVertex2d(x-0.6,y-0.9);

                                glVertex2d(x+0.6,y-0.9);


                        glEnd();


                        //draw_spokes(xc,yc,xc+radius*cos(angle), yc+radius*sin(angle));
         }


	

}




void draw_stand(double xc,double yc, double x,double y ,int left)
{
	

	double increment = 0.05;
	glBegin(GL_LINES);
		
		glColor3f(0.396,0.262,0.129);
		for(int i=0;i<8;++i)
		{
			if(left)
			{
				glVertex2d(xc- i*increment,yc);
				glVertex2d(x- i*increment,y);
			}
			else
			{
				 glVertex2d(xc +  i*increment,yc);
                                 glVertex2d(x + i*increment,y);

			}

		}
	
	glEnd();

}



void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.529,0.807,0.921,0.0);
	glLoadIdentity();
	
	float gwx = 20.0;
	float gwy= 17.0;


	glBegin(GL_QUADS);
		glColor3f(0.60f,0.46f,0.32f);
		glVertex2f(0.0f,0.0f);
		glVertex2f(0.0f,5.0f);
		glVertex2f(40.0f,5.0f);
		glVertex2f(40.0f,0.0f);

	glEnd();

	 glBegin(GL_QUADS);
                glColor3f(0.141f,0.376f,0.141f);
                glVertex2f(0.0f,5.0f);
                glVertex2f(0.0f,5.5f);
                glVertex2f(40.0f,5.5f);
                glVertex2f(40.0f,5.0f);

        glEnd();




	//draw_stand(20.0,17.0,15.0f,5.5f,1);
        //draw_stand(20.0,17.0,25.0f,5.5f,1);

	glColor3f(0.66f,0.66f,0.66f);
	draw_wheel(gwx,gwy,8.0);
	glColor3f(0.529,0.807,0.921);
	draw_wheel(gwx,gwy,7.5);
	
       
	
	draw_seat(gwx,gwy,8.0);

	glColor3f(0.55f,0.55f,0.55f);
	glLineWidth(3.0);
	draw_spokes(gwx,gwy,7.5,32);

	glLineWidth(1.0);

	glColor3f(0.70f,0.72f,0.694f);
        draw_wheel(gwx,gwy,4.0);
	glColor3f(0.0f,0.0f,0.0f);
	glLineWidth(1.3);
	draw_transparent_wheel(gwx,gwy,4.0);

	glColor3f(0.529,0.807,0.921);
	draw_wheel(gwx,gwy,2.0);

	glColor3f(0.0f,0.0f,0.0f);
        glLineWidth(1.0);
        draw_transparent_wheel(gwx,gwy,2.0);


	glColor3f(0.55f,0.55f,0.55f);
	glLineWidth(3.0);
        draw_spokes(gwx,gwy,2.0,16);
	glLineWidth(1.0);
	//draw_transparent_wheel(20.0,17.0,4.0);
	//draw_transparent_wheel(20.0,17.0,2.0);
	glColor3f(1.0f,1.0f,1.0f);



	draw_flags(10.0f,5.5f,0.4f,4.0f,2);
	draw_flags(5.0f,5.5f,0.4f,4.0f,1);
	draw_flags(30.0f,5.5f,0.4f,4.0f,0);

	draw_flags(35.0f,5.5f,0.4f,4.0f,1);

	
	draw_stand(gwx,gwy,15.0f,5.5f,1);
	draw_stand(gwx,gwy,25.0f,5.5f,1);
	
	
	glColor3f(flag_colors[2][0],flag_colors[2][1],flag_colors[2][2]);
	draw_wheel(37.0, 37.0 ,5.0 );
	glLineWidth(4.0);	
	draw_spokes(37.0,37.0,7.0,30);

	glutSwapBuffers();
}

void reshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        //origin at centre
        gluOrtho2D(0,40,0,40);

        glMatrixMode(GL_MODELVIEW);



}


int main( int argc , char **argv  )
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutInitWindowPosition(200,100);
	glutInitWindowSize(500,500);

	glutCreateWindow("Giant Wheel");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0,timer,0);
	
	glutMainLoop();
}


void timer(int a)
{
	 glutPostRedisplay(); // Display fucntion called when having chance
 	 glutTimerFunc(1000/7,timer,0); //calling itself 60fps
       

	 rotation_angle = rotation_angle + 0.1;
	 if(rotation_angle==6.2)
		 rotation_angle = 0.0;
}

