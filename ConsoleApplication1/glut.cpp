#include <tuple> 
#include <iostream>
#include <GL/freeglut.h>
using namespace std;

const int WIDTH = 1080;
const int HEIGHT = 680;
GLfloat initialDegree = 0;
void keyboard(unsigned char key, int x, int y);
void keyboard_special(int key, int x, int y);
int delay = 10;
const int CUBESIZE = 8;
const int DIMENSIONS = 3;

double mainPointArr[1][3] = { 0,0,0 };

GLfloat V[CUBESIZE][DIMENSIONS] =
{
	{-0.1,0.1,0.1},	{0.1,0.1,0.1}, {0.1,-0.1,0.1}, {-0.1,-0.1,0.1},
	{-0.1,0.1,-0.1},{0.1,0.1,-0.1},{0.1,-0.1,-0.1},{-0.1,-0.1,-0.1}
};
GLfloat tempMatrix[8][3];

tuple<float,float,float> findCenter(GLfloat V[CUBESIZE][DIMENSIONS]) {
		double sumX = 0;
		double sumY = 0;
	    double sumZ = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 3; j++) {
				if (j == 0) { sumX = sumX + V[i][j]; }
				if (j == 1) { sumY = sumY + V[i][j]; }
				if (j == 2) { sumZ = sumZ + V[i][j]; }
			}
		}
		sumX = float(sumX) / 8.0;
		sumY = float(sumY) / 8.0;
		sumZ = float(sumZ) / 8.0;

		return make_tuple(sumX,sumY,sumZ);
}
void rotationZ(GLfloat V[CUBESIZE][DIMENSIONS], float angle, GLfloat tempMatrix[8][3]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			tempMatrix[i][j] = V[i][j];
		}
	};
	tuple<float, float, float> tuple = findCenter(V);

	
	mainPointArr[0][0] = get<0>(tuple);
	mainPointArr[0][1] = get<1>(tuple);
	mainPointArr[0][2] = get<2>(tuple);
	
	

	for (int i = 0; i < 8; i++) {
		V[i][0] = V[i][0] - float(mainPointArr[0][0]);
		V[i][1] = V[i][1] - float(mainPointArr[0][1]);
		tempMatrix[i][0] = tempMatrix[i][0] - float(mainPointArr[0][0]);
		tempMatrix[i][1] = tempMatrix[i][1] - float(mainPointArr[0][1]);


		V[i][0] = (tempMatrix[i][0] * cos(angle)) - float((tempMatrix[i][1] * sin(angle)));
		V[i][1] = (tempMatrix[i][0] * sin(angle)) + float((cos(angle) * tempMatrix[i][1]));


		V[i][0] = V[i][0] + float(mainPointArr[0][0]);
		V[i][1] = V[i][1] + float( mainPointArr[0][1]);
		tempMatrix[i][0] = tempMatrix[i][0] + float(mainPointArr[0][0]);
		tempMatrix[i][1] = tempMatrix[i][1] + float(mainPointArr[0][1]);

	};
}
void rotationY(GLfloat V[CUBESIZE][DIMENSIONS], float angle, GLfloat tempMatrix[8][3]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			tempMatrix[i][j] = V[i][j];
		}
	}
	tuple<float, float, float> tuple = findCenter(V);


	mainPointArr[0][0] = get<0>(tuple);
	mainPointArr[0][1] = get<1>(tuple);
	mainPointArr[0][2] = get<2>(tuple);


	for (int i = 0; i < 8; i++) {

		V[i][0] = V[i][0] - mainPointArr[0][0];
		V[i][2] = V[i][2] - mainPointArr[0][2];
		tempMatrix[i][0] = tempMatrix[i][0] - float(mainPointArr[0][0]);
		tempMatrix[i][2] = tempMatrix[i][2] - float(mainPointArr[0][2]);

		V[i][0] = (tempMatrix[i][0] * cos(angle)) + (tempMatrix[i][2] * sin(angle));
		V[i][2] = (tempMatrix[i][0] * -sin(angle)) + (cos(angle) * tempMatrix[i][2]);

		V[i][0] = V[i][0] + mainPointArr[0][0];
		V[i][2] = V[i][2] + mainPointArr[0][2];
		tempMatrix[i][0] = tempMatrix[i][0] + float(mainPointArr[0][0]);
		tempMatrix[i][2] = tempMatrix[i][2] + float(mainPointArr[0][2]);
	};
}
void rotationX(GLfloat V[CUBESIZE][DIMENSIONS], float angle, GLfloat tempMatrix[8][3]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			tempMatrix[i][j] = V[i][j];
		}
	}
	tuple<double, double, double> tuple = findCenter(V);

	double mainPointArr[1][3];
	mainPointArr[0][0] = get<0>(tuple);
	mainPointArr[0][1] = get<1>(tuple);
	mainPointArr[0][2] = get<2>(tuple);
	for (int i = 0; i < 8; i++) {
		V[i][1] = V[i][1] - mainPointArr[0][1];
		V[i][2] = V[i][2] - mainPointArr[0][2];
		tempMatrix[i][1] = tempMatrix[i][1] - float(mainPointArr[0][1]);
		tempMatrix[i][2] = tempMatrix[i][2] - float(mainPointArr[0][2]);

		V[i][1] = (tempMatrix[i][1] * cos(angle)) - (tempMatrix[i][2] * sin(angle));
		V[i][2] = (tempMatrix[i][1] * sin(angle)) + (cos(angle) * tempMatrix[i][2]);

		V[i][1] = V[i][1] + mainPointArr[0][1];
		V[i][2] = V[i][2] + mainPointArr[0][2];
		tempMatrix[i][1] = tempMatrix[i][1] + float(mainPointArr[0][1]);
		tempMatrix[i][2] = tempMatrix[i][2] + float(mainPointArr[0][2]);
	};
}


void movement(float x, float y, float z, GLfloat V[CUBESIZE][DIMENSIONS]) {

	for (int i = 0; i < CUBESIZE; i++) {
		V[i][0] = V[i][0] + float(x);
		V[i][1] = V[i][1] + float(y);
		V[i][2] = V[i][2] + float(z);
	};
	
	
}
void scaleUp(double x_scale, double y_scale, double z_scale, GLfloat V[CUBESIZE][DIMENSIONS]) {
	double initialXScale = 1;
	double initialYScale = 1;
	double initialZScale = 1;
	double initialPositionX = 0;
	double initialPositionY = 0;
	double initialPositionZ = 0;

	for (int i = 0; i < CUBESIZE; i++) {
		V[i][0] = V[i][0] - initialPositionX;
		V[i][1] = V[i][1] - initialPositionY;
		V[i][2] = V[i][2] - initialPositionZ;

		V[i][0] = V[i][0] * x_scale;
		V[i][1] = V[i][1] * y_scale;
		V[i][2] = V[i][2] * z_scale;

		V[i][0] = V[i][0] + initialPositionX;
		V[i][1] = V[i][1] + initialPositionY;
		V[i][2] = V[i][2] + initialPositionZ;

	}
}
void scaleDown(double x_scale, double y_scale, double z_scale, GLfloat V[CUBESIZE][DIMENSIONS]) {
	double initialXScale = 1;
	double initialYScale = 1;
	double initialZScale = 1;
	double initialPositionX = 0;
	double initialPositionY = 0;
	double initialPositionZ = 0;

	for (int i = 0; i < CUBESIZE; i++) {
		V[i][0] = V[i][0] - initialPositionX;
		V[i][1] = V[i][1] - initialPositionY;
		V[i][2] = V[i][2] - initialPositionZ;

		V[i][0] = V[i][0] / x_scale;
		V[i][1] = V[i][1] / y_scale;
		V[i][2] = V[i][2] / z_scale;

		V[i][0] = V[i][0] + initialPositionX;
		V[i][1] = V[i][1] + initialPositionY;
		V[i][2] = V[i][2] + initialPositionZ;

	}
}
void keyboard(unsigned char key, int x, int y) {
	std::cout << key;
	switch (key) {
	case 27:
		exit(0);
		break;
	case ' ':
		scaleUp(1.1, 1.1, 1.1, V);
		break;
	case 8:
		scaleDown(1.1, 1.1, 1.1, V);
		break;
	case 'z':
		movement(0, 0, 0.1, V);
		break;
	case 'c':
		movement(0, 0, -0.1, V);
		break;
	case 't':
		rotationZ(V, 0.7, tempMatrix);
		break;
	case 'w':
		rotationY(V, 0.7, tempMatrix);
		break;
	case 's':
		rotationX(V, 0.7, tempMatrix);
		break;
	}


}
void keyboard_special(int key, int x, int y) {

	switch (key) {
	case GLUT_KEY_DOWN:
		movement(0, -0.1, 0, V);
		
		findCenter(V);

		break;

	case GLUT_KEY_UP:
		movement(0, 0.1, 0, V);
		findCenter(V);

		break;

	case GLUT_KEY_RIGHT:
		movement(0.1, 0, 0, V);

		break;

	case GLUT_KEY_LEFT:

	findCenter(V);
		movement(-0.1, 0, 0, V);

		break;

	}
}


void Spin()
{
	rotationX(V, 0.001, tempMatrix);
	rotationY(V, 0.001, tempMatrix);
	rotationZ(V, 0.001, tempMatrix);
	glutPostRedisplay();
}
void MyInit() {
	//BACKGROUND COLOR
	glClearColor(0, 0, 0, 1);
	//WRITING COLOR
	glColor3f(1, 1, 1);
	//TO PREVENT OVERLAPING OF COLOR --> RED FACE WAS MISSING
	glEnable(GL_DEPTH_TEST);
}

void Face(GLfloat A[], GLfloat B[], GLfloat C[], GLfloat D[])
{

	//ARRANGE THE LINES OF THE POLYGON
	glBegin(GL_LINE_LOOP);
	glVertex3f(A[0], A[1], A[2]);
	glVertex3f(B[0], B[1], B[2]);
	glVertex3f(C[0], C[1], C[2]);
	glVertex3f(D[0], D[1], D[2]);
	glEnd();

	

}
void Cube(GLfloat V0[], GLfloat V1[], GLfloat V2[], GLfloat V3[], GLfloat V4[], GLfloat V5[], GLfloat V6[], GLfloat V7[])
{
	glColor3f(1, 1, 1);
	Face(V0, V1, V2, V3);
	Face(V4, V5, V6, V7);
	Face(V0, V3, V7, V4);
	Face(V1, V2, V6, V5);
	Face(V0, V1, V5, V4);
	Face(V3, V2, V6, V7);
}

void Print()
{
	//CLEAR PIXELS
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	Cube(V[0], V[1], V[2], V[3], V[4], V[5], V[6], V[7]);
	//CHANGES WILL BE PUSHED
	glutSwapBuffers();
}


void redraw(int value) {
	glutPostRedisplay();
	glutTimerFunc(delay, redraw, 0);

}




int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	//POSITION AT YOUR DISPLAY
	glutInitWindowPosition(500, 250);
	//SIZE OF THE WINDOW
	glutInitWindowSize(WIDTH, HEIGHT);
	//VALUE OF THE FIRST WILL BE USE FOR "GLUT_SINGLE"
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("My cube");
	MyInit();
	//TO DRAW
	glutDisplayFunc(Print);

	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboard_special);
	glutIdleFunc(Spin);
	//TO STAY OPEN

	glutTimerFunc(10, redraw, 0);
	glutMainLoop();
	return 0;
}


