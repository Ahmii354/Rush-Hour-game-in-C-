//============================================================================
// Name        :21i_1758 .cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<fstream>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


int xI = 60, yI = 60;
int x[4]={100,500,200,300};
int y[4]={350,720,100,100};

void drawCar2()
{
	for (int i=0; i<4; i++)
	{
		DrawSquare(x[i], y[i], 25, colors[WHITE]);
	}
}


void drawCar() {
	
	DrawSquare(xI, yI, 30, colors[RED]);
	
	glutPostRedisplay();
}
bool flag=true;
void move_x(int &x)
{
	if ( x> 10 && flag) {
		x -= 10;
		cout << "going left";
		if(x < 100)
			
			flag = false;

	}
	else if ( x< 1010 && !flag) {
		cout << "go right";
		 x+= 10;
		if (x > 900)
			flag = true;}
	
}
void move_y(int &y)
{
	if ( y> 10 && flag) {
		y -= 10;
		cout << "going left";
		if(y < 100)
			
			flag = false;

	}
	else if ( y< 1010 && !flag) {
		cout << "go right";
		 y+= 10;
		if (y > 900)
			flag = true;}
	
}


int score=0;
      int arrayX1[2]={300,470};
      int arrayx2[2]={900,350};
      int arrayX3[2]={970,350};
      int arrayX4[2]={965,650};
      int arrayX5[2]={500,580};
      int arrayX6[2]={440,580};
      int arrayX7[2]={380,580};
      int arrayX8[2]={300,110};
      int arrayX9[2]={100,170};
      int arrayX10[2]={200,470};
      int arrayX11[2]={300,470};
      int arrayX12[2]={10,250};
      int arrayX13[2]={400,10};
      int arrayX14[2]={550, 10};
      int arrayX15[2]={660,10};
      int arrayX16[2]={200,350};
      int arrayX17[2]={935,400};
      int arrayX18[2]={300,20} ;
      int array2[2]={ 300, 598 };
      int arrayc[2]={ xI, yI } ;
void hitting(){
     
    if (arrayc[0]==arrayX1[1] && arrayc[0]==arrayX1[1] 
                              ||
        arrayc[0]==arrayx2[1] && arrayc[0]==arrayx2[1] 
                              ||
        arrayc[0]==arrayX3[1] && arrayc[0]==arrayX3[1] 
                              ||
        arrayc[0]==arrayX4[1] && arrayc[0]==arrayX4[1] 
                              ||
        arrayc[0]==arrayX5[1] && arrayc[0]==arrayX5[1] 
                              ||
        arrayc[0]==arrayX6[1] && arrayc[0]==arrayX6[1] 
                              ||
        arrayc[0]==arrayX7[1] && arrayc[0]==arrayX7[1] 
                              ||
        arrayc[0]==arrayX8[1] && arrayc[0]==arrayX8[1] 
                              ||
        arrayc[0]==arrayX9[1] && arrayc[0]==arrayX9[1] 
                              ||
        arrayc[0]==arrayX10[1] && arrayc[0]==arrayX10[1] 
                              ||
        arrayc[0]==arrayX11[1] && arrayc[0]==arrayX11[1] 
                              ||
        arrayc[0]==arrayX12[1] && arrayc[0]==arrayX12[1] 
                              ||
        arrayc[0]==arrayX13[1] && arrayc[0]==arrayX13[1] 
                              ||
        arrayc[0]==arrayX14[1] && arrayc[0]==arrayX14[1] 
                              ||
        arrayc[0]==arrayX15[1] && arrayc[0]==arrayX15[1] 
                              ||
        arrayc[0]==arrayX16[1] && arrayc[0]==arrayX16[1] 
                              ||
        arrayc[0]==arrayX17[1] && arrayc[0]==arrayX17[1] 
                              ||
        arrayc[0]==arrayX18[1] && arrayc[0]==arrayX18[1])
        {
            score-=2;
        }
 }        
bool flag1 = true;
void moveCar() {
	
	if ( xI> 10 && flag1) {
		xI -= 10;
		cout << "going left";
		if(xI < 100)
			
			flag1 = false;

	}
	else if ( xI< 1010 && !flag1) {
		cout << "go right";
		 xI+= 10;
		if (xI > 900)
			flag1 = true;
	}
}


       //drop off location
void dropoff()
   {       
       int random;
       DrawRectangle((rand()%1000),(rand()%800),51,51,colors[GREEN]);
   }
/*
 * Main Canvas drawing function.
 * */
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//Red Square
	DrawSquare(400, 20, 40, colors[RED]);
	
	//Green Square
	DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	
	//Display Score
	DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	

        int temp=0;
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	for(int i=0; i<21; i++)
	{	
	   DrawLine( temp, 0 ,  temp , 750 , 1, colors[WHITE] );
	   temp+=50;
	}
	
	DrawLine( 0, 750 ,  1020 , 750 , 1, colors[WHITE] );	

        //TREE
	DrawCircle(300,470,10,colors[GREEN]);
	DrawRectangle(300-2,470 - 30,5,25,colors[BROWN]);
	DrawCircle(900,350,10,colors[GREEN]);
	DrawRectangle(900-2,350 - 30,5,25,colors[BROWN]);
	DrawCircle(970,350,10,colors[GREEN]);
	DrawRectangle(970-2,350 - 30,5,25,colors[BROWN]);
	DrawCircle(965,650,10,colors[GREEN]);
	DrawRectangle(965-2,650 - 30,5,25,colors[BROWN]);
	DrawCircle(500,580,10,colors[GREEN]);
	DrawRectangle(500-2,580 - 30,5,25,colors[BROWN]);
	DrawCircle(440,580,10,colors[GREEN]);
	DrawRectangle(440-2,580 - 30,5,25,colors[BROWN]);
	DrawCircle(380,580,10,colors[GREEN]);
	DrawRectangle(380-2,580 - 30,5,25,colors[BROWN]);
	DrawCircle(300,110,10,colors[GREEN]);
	DrawRectangle(300-2,110 - 30,5,25,colors[BROWN]);
	DrawCircle(100,170,10,colors[GREEN]);
	DrawRectangle(100-2,170 - 30,5,25,colors[BROWN]);
	DrawCircle(200,470,10,colors[GREEN]);
	DrawRectangle(200-2,470 - 30,5,25,colors[BROWN]);
	DrawCircle(300,470,10,colors[GREEN]);
	DrawRectangle(300-2,470 - 30,5,25,colors[BROWN]);
	DrawRectangle(10,250,30,25,colors[YELLOW]);
	DrawRectangle(400,10,30,25,colors[YELLOW]);
	DrawRectangle(550,10,30,25,colors[YELLOW]);
	DrawRectangle(660,10,30,25,colors[YELLOW]);
	DrawRectangle(200,350,30,25,colors[YELLOW]);
	DrawRectangle(935,400,30,25,colors[YELLOW]);
	DrawRectangle(300,20,30,25,colors[YELLOW]);
	//TYERS
	DrawCircle(xI+2 ,yI-2,5,colors[BROWN]);
	DrawCircle(xI+28,yI-2,5,colors[BROWN]);
	//PESSANGERS
	DrawCircle(300 ,600-2,6,colors[WHITE]);
	DrawRectangle(300-3,570,7,25,colors[WHITE]);
	//DrawRoundRect(300-3,600-5,5,20,colors[WHITE],10);
	//DrawRoundRect(500,200,50,100,colors[DARK_SEA_GREEN],70);
	//DrawCircle(90,670,10,colors[RED]);	
	//DrawRoundRect(100,200,100,50,colors[DARK_OLIVE_GREEN],20);	
	//DrawRoundRect(100,100,50,100,colors[DARK_OLIVE_GREEN],30);
	//DrawRoundRect(200,100,100,50,colors[LIME_GREEN],40);
	//DrawRoundRect(350,100,100,50,colors[LIME_GREEN],20);
	DrawRectangle(350,250,300,150,colors[BLUE]);
	DrawRectangle(200,200,100,102,colors[GREEN]);
	DrawRectangle(100,250,51,400,colors[WHITE]);
	DrawRectangle(350,650,600,51,colors[GREEN]);
	DrawRectangle(750,450,300,51,colors[WHITE]);
	DrawRectangle(750,200,600,51,colors[WHITE]);
	DrawRectangle(750,200,51,200,colors[WHITE]);
	DrawRectangle(200,500,300,51,colors[BROWN]);
	DrawRectangle(0,0,1100,20,colors[WHITE]);
	drawCar();
	drawCar2();
        

	
	
	glutSwapBuffers(); // do not modify this line..
	
}



/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		xI -= 10;

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		xI += 10;
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		yI += 10;
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		yI -= 10;
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 32) //Key for placing the bomb
			{
		if(arrayc[0] == array2[0] && arrayc[0] == array2[1] )
	{
	DrawCircle(300 ,600-2,6,colors[BLACK]);
	DrawRectangle(300-3,570,7,25,colors[BLACK]);
	dropoff();
	
	}
	}
	glutPostRedisplay();
}



/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	//moveCar();
        for (int i=0; i<4; i++)
        if (i<2)
		move_x(x[i]);  
	else 
	       move_y(y[i]);
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	int width = 1020, height = 840; // i have set my window size to be 1020 x 840
string name;
cout<<"Enter your name";
getline(cin,name);
ofstream myfile;
myfile.open("game_1758.txt");
myfile<<name;
int choice;
cout<< "press(1) for yellow taxi";
        cout<<endl;
cout<< "press(2) for red taxi";
        cin>>choice;
        
 if (choice==1){       
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour by Ahmad Hassan"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();}
	return 1;


}
#endif /* RushHour_CPP_ */
