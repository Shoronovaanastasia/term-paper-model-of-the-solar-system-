#include <stdio.h>    
#include <string.h>
#include <math.h>
#include <fstream>
#include <time.h>

#include <iostream>
#include <stdlib.h>
#include <GL\glew.h>
#include <GL\freeglut.h>

using namespace std;
void circleDraw(float); // ������ ���������� (������� �� �������)
void planetsDraw(); // ������ ������� (��. ������� ����)

void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //������ �������� ������� ������
}
// RGB Red Green Blue



// �� ��������� ���� ������� ��������. ������� ���.
void initRendering() { // ������
	glEnable(GL_DEPTH_TEST); // ������ ������� �� gl. � ������: ���� �������
}
// ������, � ���������� ������ ������� OpenGL ����� ������������� ��������� �������� �������
// ��� ���� ��������� ���� ���������� � ����������� �� ���������.


void handleResize(int w, int h) {
	glViewport(0, 0, w, h); // ������� ������ ���� ���������.
	glMatrixMode(GL_PROJECTION); //������� ���������, ����� ������� �������� ������� ��������.
	// ��������� ����������� �������� � �������� � ����� ������� ��������.

	glLoadIdentity(); //������� �������� ������� ������� �������� ���������������.
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0); // ������� ����������� ������� ������������� ��������.
	// 1. ���� ������ � ����������� OY
	// 2. ����������� X � Y (����� ��� ���������)
	// 3. ��������� ��� ���������� �������� �� ���������� �� ������� �� ����������

}

// ���� ���������
// .f ����� ����� ������ ��� ������ � ��������� �������.
float mercury_angle = 30.0f; // ��������� ����
float satrun_ring_angle = 30.0f;
float venus_angle = 30.0f;
float earth_angle = 30.0f;
float moon_angle = 30.0f;
float earth_ring_angle = 30.0f;
float mars_angle = 30.0f;
float mars_ring_angle = 30.0f;
float mars_ring_angle2 = 30.0f;
float fobos_angle = 30.0f;
float fobos_angle2 = 30.0f;
float deimos_angle = 30.0f;
float deimos_angle2 = 30.0f;
float jupiter_angle = 30.0f;
float jupiter_angle1 = 30.0f;
float io_ring_angle = 30.0f;
float europa_ring_angle = 30.0f;
float ganimed_ring_angle = 30.0f;
float callisto_ring_angle = 30.0f;
float io_angle = 30.0f;
float europa_angle = 30.0f;
float europa_angle2 = 30.0f;
float satrun_angle = 30.0f;
float uranus_angle = 30.0f;
float uranus_ring_angle = 30.0f;
float neptune_angle = 30.0f;
float neptune_ring_angle = 30.0f;
float triton_angle = 30.0f;

class Sun {
private:
	float R; // ������
public:
	Sun() {
		R = 2.5;
	}
	
	float getR() const {
		return R;
	}
};

class Mercury {
public:
	float R = 0.492; // ������
	float V = 4.82; // �����, �� ������� ������� ������ ���� ������ ������ ������ ������
	float S = 3.84; // ���������� �� ������
	//float M = 500;
	//float G = 0.0000000000667;
	//float V1;

	/*
	float calcV1() const {
		float V1 = sqrt(G * M / R);
		return V1;
	}
	*/
	float getR() const {
		return R;
	}
	float getV() const {
		return V;
	}
	float getS() const {
		return S;
	}
};

class Venus {
public:
	float R = 0.4755; // ������
	float V = 12.3; // �������� �������
	float S = 7.23; // ���������� �� ������

	float getR() const {
		return R;
	}
	float getV() const {
		return V;
	}
	float getS() const {
		return S;
	}
};

class Earth {
public:
	float R = 1; // ������
	float V = 15; // �������� �������
	float S = 10; // ���������� �� ������

	float getR() const {
		return R;
	}
	float getV() const {
		return V;
	}
	float getS() const {
		return S;
	}

};

class Moon {
public:
	float R = 0.4; // ������
	float V = 15; // �������� �������
	float SSun = 10; // ���������� �� ������
	float S = 1.7; // ���������� �������� �� � �������

	float getR() const {
		return R;
	}
	float getV() const {
		return V;
	}
	float getS() const {
		return S;
	}
	float getSSun() const {
		return SSun;
	}

};

class Mars {
public:
	float R = 0.8; // ������
	float V = 25.2; // �������� �������
	float S = 15.2; // ���������� �� ������

	float getR() const {
		return R;
	}
	float getV() const {
		return V;
	}
	float getS() const {
		return S;
	}

};

class Fobos {
public:
	float R = 0.4; // ������
	float V = 25.2; // �������� �������
	float SSun = 15.0; // ���������� �� ������
	float S = 1.6;

	float getR() const {
		return R;
	}
	float getV() const {
		return V;
	}
	float getS() const {
		return S;
	}
	float getSSun() const {
		return SSun;
	}

};

class Deimos {
public:
	float R = 0.3; // ������
	float V = 25.2; // �������� �������
	float SSun = 15.0; // ���������� �� ������
	float S = 2.65;

	float getR() const {
		return R;
	}
	float getV() const {
		return V;
	}
	float getS() const {
		return S;
	}
	float getSSun() const {
		return SSun;
	}

};

class Jupiter {
public:
	float R = 2; // ������
	float V = 36.5; // �������� �������
	float S = 24.0; // ���������� �� ������

	float getR() const {
		return R;
	}
	float getV() const {
		return V;
	}
	float getS() const {
		return S;
	}

};

class Io {
public:
	float R = 0.3; // ������
	float V = 36.5; // �������� �������
	float SSun = 24.0; // ���������� �� ������
	float S = 2.56;

	float getR() const {
		return R;
	}
	float getV() const {
		return V;
	}
	float getS() const {
		return S;
	}
	float getSSun() const {
		return SSun;
	}
};

class Europa {
public:
	float R = 0.36; // ������
	float V = 36.5; // �������� �������
	float SSun = 24.0; // ���������� �� ������
	float S = 3.15;

	float getR() const {
		return R;
	}
	float getV() const {
		return V;
	}
	float getS() const {
		return S;
	}
	float getSSun() const {
		return SSun;
	}
};

class Saturn {
public:
	float R = 1.7; // ������
	float V = 40.2; // �������� �������
	float S = 32.0; // ���������� �� ������

	float getR() const {
		return R;
	}
	float getV() const {
		return V;
	}
	float getS() const {
		return S;
	}

};

class Uranus {
public:
	float R = 1.6; // ������
	float V = 50.5; // �������� �������
	float S = 42.0; // ���������� �� ������

	float getR() const {
		return R;
	}
	float getV() const {
		return V;
	}
	float getS() const {
		return S;
	}

};

class Neptune {
public:
	float R = 1.5; // ������
	float V = 61.8; // �������� �������
	float S = 51.0; // ���������� �� ������

	float getR() const {
		return R;
	}
	float getV() const {
		return V;
	}
	float getS() const {
		return S;
	}

};

class Triton {
public:
	float R = 0.36; // ������
	float V = 61.8; // �������� �������
	float SSun = 51.1; // ���������� �� ������
	float S = 2.4;

	float getR() const {
		return R;
	}
	float getV() const {
		return V;
	}
	float getS() const {
		return S;
	}
	float getSSun() const {
		return SSun;
	}
};


//������ 3� �����
void sceneDraw() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // ������� ��������� ������, � ������
	// ������� ������ ����� � 	������� ������ �������.
	glMatrixMode(GL_MODELVIEW); // ��������� ����������� ��������� �������� � ����� ������ ������������� ������.
	glLoadIdentity(); // �������� ������� ������� �������� ���������������.
	glTranslatef(0.0, 0.0, -50.0f); // ������������ ������� ������� ( ������� � ������ ������ ���������). (�������)
	glScalef(0.4f, 0.4f, 0.4f); // ������ �������

	// ������ ������ ������ (������ ����� �� ���������)
	circleDraw(4.62); // �������
	circleDraw(9);
	circleDraw(12.5);
	circleDraw(18.8);
	circleDraw(30);
	circleDraw(39.5);
	circleDraw(52);
	circleDraw(63);
	
	planetsDraw(); // ������ �������
	//sputnikDraw();
	glutSwapBuffers(); //����� ��������� �� ������������ (��������) ������

	/*
	Swap Buffers - ����� �������. ��� ����� ������� ��� ��������.
	�� ���������� ���� � ������� ������������, ���� ����� ������������ � ������ - ����������.
	� ����� ������ ���������� OpenGL �� ��������� ����������� ������ ����������� � ����������� ������.
	����� ������� glutSwapBuffers ���������� ������, ��������� ���� ������� ����� ����, ��� ��� ��� ������������.
	��� ���������� ������ � ������������ ��������, ��� ��� �� ��������� ������������� ����� ������, ��� ����� �� ������ ����������� ����.
	*/

}


void planetsDraw() {

	//Sun
	Sun Su;
	glPushMatrix(); //��� ���������� � �������������� ������� ���������
	/*
	�������� ������� ���� ������ �� ������� ����, �������� ������� �������.
	�� ���� ����� ������ glPushMatrix ������� ������� ����� ��������� ������� ��� ���.
	*/
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //��� ������������� ����� ��� ��������� ��������������.
	/*
	������ �������� ���������, ��� ����� ���������� �������������.
	�� ��������� ��������: GL_POINT(�������� ������ �����), GL_LINE(������ �����) � GL_FILL(������ ����������� �������������).
	������ �������� ���������: � �������, ������� ��� �� � ����� �������� ����������� �����, �������� ������ ����������.
	*/
	glColor3f(0.9, 0.9, 0.0);
	/*
	��������� ������ ���� ���������� ������� glColor3f(r, g, b).
	��� �� ��������� ��������� ������������ ����� �������, ����� � ������� ������������.
	������ �� ��� ����� ��������� �������� �� 0.0f �� 1.0f.
	*/
	glutSolidSphere(Su.getR(), 50, 50);
	// glutSolidSphere(GLdouble radius, GLint slices, GLint stacks)
	// ������ ����� � �������� 2.5, 
	/*
	slices ���������� ������� ������ ��� Z. (������)
	stacks ���������� ������� ����� ��� z. (������� (��. ������))
	*/
	glEnd(); // �� ��������� �������� ��������
	glPopMatrix(); // ��������� ������� ���� ������, ������� ������� ������� ���, ��� ��������� ��� ��� � �����.

	// ������ ����������

	// ������� - ��������� ������ �� ������������ �����.
	//��������
	Mercury Me;
	glPushMatrix();
	glRotatef(mercury_angle, 0.0f, 0.0f, 1.0f); // ������� ������� ���������
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	//glTranslatef(3.84f, 0.0, 0.0f); // �������� ������� ��������� ��� ��������
	glTranslatef(Me.getS(), 0.0, 0.0f); // ������� ������� �� ������ (�� ������)
	glutSolidSphere(Me.getR(), 50, 50);
	glPopMatrix();

	//������
	Venus Ve;
	// ��� ������ ����������� ������������ ������� �������������� (��� ��������, �������� ���)
	glPushMatrix(); // ��������� ������� ������� � ����. ����� ��������� �� ������ ����� � ��������� �� �����.
	glRotatef(venus_angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(Ve.getS(), 0.0, 0.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(255.0, 215.0, 0.75);
	glutSolidSphere(Ve.getR(), 50, 50);
	glPopMatrix(); // ��������� ������� �� ����� � ������������� � � �������� �������


	//�����
	Earth Ea;
	glPushMatrix();
	glRotatef(earth_angle, 0.0f, 0.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.137255, 0.137255, 0.556863);
	glTranslatef(Ea.getS(), 0.0, 0.0f);
	glutSolidSphere(Ea.getR(), 50, 50);
	glPopMatrix();


	//����
	Moon Mo;
	glPushMatrix();
	glRotatef(moon_angle, 0.0f, 0.0f, 2.0f);
	glTranslatef(Mo.getSSun(), 0.0, 0.0f); // �������� �� ������
	glRotatef(moon_angle, 0.0f, 0.0f, 2.0f);
	glTranslatef(Mo.getS(), 0.0, 0.0f); // ���������� �� �����
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.8f, 0.8f, 0.8f);
	//glTranslatef(11.7f, 0.0, 0.0f); // ����������, �� ������� ������ ����� �� ������ 11.7
	glutSolidSphere(Mo.getR(), 50, 50);
	glPopMatrix();

	//������ ����
	glPushMatrix();
	glRotatef(earth_ring_angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(12.4f, 0.0, 0.0f);
	circleDraw(2); // ����������� �� �������
	glPopMatrix();

	//����
	Mars Ma;
	glPushMatrix();
	glRotatef(mars_angle, 0.0f, 0.0f, 1.0f); // (����, �� ������� ��������� ������� � ��. �������, 
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.8, 0.0, 0.0); // �� ��� ���
	glTranslatef(Ma.getS(), 0.0, 0.0f);
	glutSolidSphere(Ma.getR(), 50, 50);
	glPopMatrix();

	//������ ������
	glPushMatrix();
	glRotatef(mars_ring_angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(18.75f, 0.0, 0.0f); // 18.75
	circleDraw(2); // ����������� �� �������
	glPopMatrix();

	//������ �������
	glPushMatrix();
	glRotatef(mars_ring_angle2, 0.0f, 0.0f, 1.0f);
	glTranslatef(18.77f, 0.0, 0.0f); // 18.75
	circleDraw(3.3); // ����������� �� �������
	glPopMatrix();

	// ������� ����� (�����)
	Fobos Fo;
	glPushMatrix();
	glRotatef(fobos_angle, 0.0f, 0.0f, 2.0f);
	glTranslatef(Fo.getSSun(), 0.0, 0.0f); // ����� �� ������
	glRotatef(fobos_angle, 0.0f, 0.0f, 2.0f);
	glTranslatef(Fo.getS(), 0.0, 0.0f); // �������� �� �����
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.8f, 0.8f, 0.8f);
	glutSolidSphere(Fo.getR(), 50, 50);
	glPopMatrix();

	// ������� ����� (������)
	Deimos De;
	glPushMatrix();
	glRotatef(deimos_angle, 0.0f, 0.0f, 2.0f);
	glTranslatef(De.getSSun(), 0.0, 0.0f); // ����� �� ������
	glRotatef(deimos_angle2, 0.0f, 0.0f, 2.0f);
	glTranslatef(De.getS(), 0.0, 0.0f); // �������� �� �����
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.8f, 0.8f, 0.8f);
	glutSolidSphere(De.getR(), 50, 50);
	glPopMatrix();


	//������
	Jupiter Ju;
	glPushMatrix();
	glRotatef(jupiter_angle, 0.0f, 0.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.36, 0.25, 0.20);
	glTranslatef(Ju.getS(), 0.0f, 0.0f);
	glutSolidSphere(Ju.getR(), 50, 50);
	glPopMatrix();

	//������ ��
	glPushMatrix();
	glRotatef(io_ring_angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(29.75f, 0.0, 0.0f); // 18.75
	circleDraw(3.1); // ����������� �� �������
	glPopMatrix();

	// ��
	Io Io;
	glPushMatrix();
	glRotatef(io_angle, 0.0f, 0.0f, 2.0f);
	glTranslatef(Io.getSSun(), 0.0, 0.0f); // ����� �� ������
	glRotatef(io_angle, 0.0f, 0.0f, 2.0f);
	glTranslatef(Io.getS(), 0.0, 0.0f); // �������� �� �����
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.8f, 0.8f, 0.0f);
	glutSolidSphere(Io.getR(), 50, 50);
	glPopMatrix();

	//������ ������
	glPushMatrix();
	glRotatef(europa_ring_angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(29.75f, 0.0, 0.0f); // 18.75
	circleDraw(3.9); // ����������� �� �������
	glPopMatrix();

	// ������
	Europa Eu;
	glPushMatrix();
	glRotatef(europa_angle, 0.0f, 0.0f, 2.0f);
	glTranslatef(Eu.getSSun(), 0.0, 0.0f); // ����� �� ������
	glRotatef(europa_angle2, 0.0f, 0.0f, 2.0f);
	glTranslatef(Eu.getS(), 0.0, 0.0f); // �������� �� �����
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1.0f, 0.6f, 0.0f);
	glutSolidSphere(Eu.getR(), 50, 50);
	glPopMatrix();

	//������
	Saturn Sa;
	glPushMatrix();
	glRotatef(satrun_angle, 0.0f, 0.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glTranslatef(Sa.getS(), 0.0, 0.0f);
	glColor3f(0.8, 0.8, 0.5);
	glutSolidSphere(Sa.getR(), 50, 50);
	glPopMatrix();

	//������ �������
	glPushMatrix();
	glRotatef(satrun_ring_angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(39.73f, 0.0, 0.0f);
	glColor3f(0.8, 0.8, 0.6);
	circleDraw(3);
	glPopMatrix();

	//����
	Uranus Ur;
	glPushMatrix();
	glRotatef(uranus_angle, 0.0f, 0.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.5, 0.5, 1);
	glTranslatef(Ur.getS(), 0.0, 0.0f);
	glutSolidSphere(Ur.getR(), 50, 50);
	glPopMatrix();

	//������
	Neptune Ne;
	glPushMatrix();
	glRotatef(neptune_angle, 0.0f, 0.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.35, 0.35, 0.67);
	glTranslatef(Ne.getS(), 0.0, 0.0f);
	glutSolidSphere(Ne.getR(), 50, 50);
	glPopMatrix();

	//������ �������
	glPushMatrix();
	glRotatef(neptune_ring_angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(63.2f, 0.0, 0.0f); // 18.75
	circleDraw(3); // ����������� �� �������
	glPopMatrix();

	// ������
	Triton Tr;
	glPushMatrix();
	glRotatef(triton_angle, 0.0f, 0.0f, 2.0f);
	glTranslatef(Tr.getSSun(), 0.0, 0.0f); // ����� �� ������
	glRotatef(triton_angle, 0.0f, 0.0f, 2.0f);
	glTranslatef(Tr.getS(), 0.0, 0.0f); // �������� �� �����
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.6f, 1.0f, 1.0f);
	glutSolidSphere(Tr.getR(), 50, 50);
	glPopMatrix();
}


void circleDraw(float radius) { // ������� ���������� ���������� � �������� (������ - ������������ �����)

	int cir_x = 0;
	int cir_y = 0;
	int min_angle = 0; 
	int max_angle = 360;
	float theta;
	int i;
	float cir_x_itr;
	float cir_y_itr;
	float x;
	float y;

	glColor3f(1.0, 1.0, 1.0); // ����� ����
	glPushMatrix();
	glBegin(GL_LINE_LOOP);
	for (i = min_angle; i <= max_angle; i++) { // ���� �� 0 �� 360 ��������
		
		theta = 0.0174532925 * float(i); // 1 ������ ��� 0.0174532925 ������. �� ����� i-�� ������������ ����, theta - ���� � ��� (�� �������� ���� � �������� � ���� � �������� ���� �������� � ������)
		cir_x_itr = radius * cosf(theta); // ���������� ��� ��������� i-�� ������������ ����� �� � � �
		cir_y_itr = radius * sinf(theta); 

		// x = R*cos(theta) ; (theta � ��������)
		// y = R*sin(theta)

		x = cir_x + cir_x_itr; // x ������� ��������� x (�� ���� ������� + �������� ��������� x)
		y = cir_y + cir_y_itr;

		glVertex3f(x, y, -30.0f); // ��������� ������� �� �����������.  Z = -30.0 ��� ���������� ��������
	}
	glEnd();
	glPopMatrix();
}


void mercury_update(int value) {
	mercury_angle += 2.0f; // 2 ������� � ������� - �������� �������
	if (mercury_angle > 360) {
		mercury_angle -= 360;
	}

	Mercury Me;
	glutPostRedisplay(); // �������� �������� ����, ������� ������ ���� ������������, ��� ������ ��������� �����
	glutTimerFunc(Me.getV(), mercury_update, 0);
	/*
	��� ������� ������������� ������.
	������ �������� millis ������ ����� � �������������, �� ��������� ������� ���������� �������,
	(������ ����������� ��������)
	������� ������� ��� ������ ��������.
	������ �������� value ��������� �������������� �������,
	�.�. �������� ����� ���� ������������ �������� ���������.
	*/
}

void venus_update(int value) {
	venus_angle += 2.0f;
	if (venus_angle > 360) {
		venus_angle -= 360;
	}

	Venus Ve;
	glutPostRedisplay();
	glutTimerFunc(Ve.getV(), venus_update, 0);
}

// ��������� ���� earth_angle = 30.0f; +=2.0f. ��������� ����������� 32, 34 .....
void earth_update(int value) {
	earth_angle += 2.0f;
	if (earth_angle > 360) {
		earth_angle -= 360;
	}

	Earth Ea;
	glutPostRedisplay();
	glutTimerFunc(Ea.getV(), earth_update, 0);
}

void moon_update(int value) {
	moon_angle += 2.0f; // ��������, � ������� �������� ������ �� ������
	if (moon_angle > 360) {
		moon_angle -= 360;
	}

	Moon Mo;
	glutPostRedisplay();
	glutTimerFunc(Mo.getV(), moon_update, 0);
}

void earth_update_ring(int value) {
	earth_ring_angle += 2.0f;
	if (earth_ring_angle > 360) {
		earth_ring_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(15, earth_update_ring, 0);
}

void mars_update(int value) {
	mars_angle += 2.0f;
	if (mars_angle > 360) {
		mars_angle -= 360;
	}

	Mars Ma;
	glutPostRedisplay();
	glutTimerFunc(Ma.getV(), mars_update, 0);
}

void mars_update_ring(int value) {
	mars_ring_angle += 2.0f;
	if (mars_ring_angle > 360) {
		mars_ring_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(25.2, mars_update_ring, 0);
}

void mars_update_ring2(int value) {
	mars_ring_angle2 += 2.0f;
	if (mars_ring_angle2 > 360) {
		mars_ring_angle2 -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(25.2, mars_update_ring2, 0);
}

void fobos_update(int value) {
	fobos_angle += 2.0f; // ��������, � ������� �������� ������ �� ������
	if (fobos_angle > 360) {
		fobos_angle -= 360;
	}

	Fobos Fo;
	glutPostRedisplay();
	glutTimerFunc(Fo.getV(), fobos_update, 0);
}

void deimos_update(int value) {
	deimos_angle += 2.0f; // ��������, � ������� �������� ������ �� ������
	if (deimos_angle > 360) {
		deimos_angle -= 360;
	}

	Deimos De;
	glutPostRedisplay();
	glutTimerFunc(De.getV(), deimos_update, 0); //15
}

void deimos_update2(int value) {
	deimos_angle2 += 3.0f; // ��������, � ������� �������� ������ �� ������
	if (deimos_angle2 > 360) {
		deimos_angle2 -= 360;
	}

	Deimos De;
	glutPostRedisplay();
	glutTimerFunc(De.getV(), deimos_update2, 0); //15
}

void jupiter_update(int value) {
	jupiter_angle += 2.0f;
	if (jupiter_angle > 360) {
		jupiter_angle -= 360;
	}

	Jupiter Ju;
	glutPostRedisplay();
	glutTimerFunc(Ju.getV(), jupiter_update, 0);
}



void io_update(int value) {
	io_angle += 2.0f; // ��������, � ������� �������� ������ �� ������
	if (io_angle > 360) {
		io_angle -= 360;
	}

	Io Io;
	glutPostRedisplay();
	glutTimerFunc(Io.getV(), io_update, 0); //15
}

void io_update_ring(int value) {
	io_ring_angle += 2.0f;
	if (io_ring_angle > 360) {
		io_ring_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(36.5, io_update_ring, 0);
}

void europa_update(int value) {
	europa_angle += 2.0f; // ��������, � ������� �������� ������ �� ������
	if (europa_angle > 360) {
		europa_angle -= 360;
	}

	Europa Eu;
	glutPostRedisplay();
	glutTimerFunc(Eu.getV(), europa_update, 0); //15
}

void europa_update2(int value) {
	europa_angle2 += 1.5f; // ��������, � ������� �������� ������ �� ������
	if (europa_angle2 > 360) {
		europa_angle2 -= 360;
	}

	Europa Eu;
	glutPostRedisplay();
	glutTimerFunc(Eu.getV(), europa_update2, 0); //15
}

void europa_update_ring(int value) {
	europa_ring_angle += 2.0f;
	if (europa_ring_angle > 360) {
		europa_ring_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(36.5, europa_update_ring, 0);
}


void saturn_update(int value) {
	satrun_angle += 2.0f;
	if (satrun_angle > 360) {
		satrun_angle -= 360;
	}

	Saturn Sa;
	glutPostRedisplay();
	glutTimerFunc(Sa.getV(), saturn_update, 0);
}
void saturn_update_ring(int value) {
	satrun_ring_angle += 2.0f;
	if (satrun_ring_angle > 360) {
		satrun_ring_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(40.2, saturn_update_ring, 0);
}


void uranus_update(int value) {
	uranus_angle += 2.0f;
	if (uranus_angle > 360) {
		uranus_angle -= 360;
	}

	Uranus Ur;
	glutPostRedisplay();
	glutTimerFunc(Ur.getV(), uranus_update, 0);
}
void neptune_update(int value) {
	neptune_angle += 2.0f;
	if (neptune_angle > 360) {
		neptune_angle -= 360;
	}

	Neptune Ne;
	glutPostRedisplay();
	glutTimerFunc(Ne.getV(), neptune_update, 0);
}

void neptune_ring_update(int value) {
	neptune_ring_angle += 2.0f;
	if (neptune_ring_angle > 360) {
		neptune_ring_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(61.8, neptune_ring_update, 0);
}

void triton_update(int value) {
	triton_angle += 2.0f;
	if (triton_angle > 360) {
		triton_angle -= 360;
	}

	Triton Tr;
	glutPostRedisplay();
	glutTimerFunc(Tr.getV(), triton_update, 0);
}


int main(int argc, char** argv) {
	// argc - ���������� ����������, ������������ � ������� main
	// argv[] - ������ ���������� �� ������
	// argc + argv �����, ���� ��������� glutInit, ����� �� ����� ��������� ������ ���������� � ����� ���������� glut
	Mercury Me;
	Venus Ve;
	Earth Ea;
	Moon Mo;
	Mars Ma;
	Fobos Fo;
	Deimos De;
	Saturn Sa;
	Jupiter Ju;
	Io Io;
	Europa Eu;
	Uranus Ur;
	Neptune Ne;
	Triton Tr;

	/*
	float VV1 = Me.calcV1();
	int a;

	cout << "Enter some coef:  (for example: 1)" << endl;
	cin >> a;

	if (a == 1) {
		cout << "First cosmos velocity for Mercury: " << VV1 << endl;
	}
	*/
	/*
	  glutInit(int **argcp, char **argv);
	argc - ��� ��������� �� ��� �� ���������� ���������� argc ������� ������� ��������� (main).
	����� �������� �� �������, ��������, �� ������� ��������� argcp, ����� ����������,
	��� ��� glutInit ��������� ��� ����� ��������� ������, ����������� � ���������� GLUT,
	��������, � ������� X-Window ��� �����, ����������� � ���������� ������, ������������� � GLUT.
	argv - ��� ��� �� ���������� ���������� argv ������� �������.

	glutInit ����������� �� ������������� ���������� ��������� GLUT
	� ������� ������ � �������� ���������� ������.
	*/

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	/* ����� ������ ����:
   ��������� ����� � RGBA ������� */
	glutInitWindowSize(1080, 720);
	/* ��������� �������� ���� */

	initGL(); // ������� �����

	glutCreateWindow("2D Solar System"); // �������� ����
	initRendering(); // ������ � ������ �������


	glutDisplayFunc(sceneDraw); // ��������� �����
	glutReshapeFunc(handleResize);


	glutTimerFunc(Me.getV(), mercury_update, 0); // �������, ������� ��������� ( Me.getV() ������ �� ��������, � ����� �� ������� � ��� �������� ����)
	glutTimerFunc(Ve.getV(), venus_update, 0); //  (������������� ����������, ����������� �������, ������������� ������� )
	glutTimerFunc(Ea.getV(), earth_update, 0);
	glutTimerFunc(Ea.getV(), earth_update_ring, 0);
	glutTimerFunc(Mo.getV(), moon_update, 0);
	glutTimerFunc(Ma.getV(), mars_update, 0);
	glutTimerFunc(Ma.getV(), mars_update_ring, 0);
	glutTimerFunc(Ma.getV(), mars_update_ring2, 0);
	glutTimerFunc(Fo.getV(), fobos_update, 0);
	glutTimerFunc(De.getV(), deimos_update, 0);
	glutTimerFunc(De.getV(), deimos_update2, 0);
	glutTimerFunc(Ju.getV(), jupiter_update, 0);
	glutTimerFunc(Io.getV(), io_update_ring, 0);
	glutTimerFunc(Io.getV(), io_update, 0);
	glutTimerFunc(Eu.getV(), europa_update_ring, 0);
	glutTimerFunc(Eu.getV(), europa_update, 0);
	glutTimerFunc(Eu.getV(), europa_update2, 0);
	glutTimerFunc(Sa.getV(), saturn_update, 0);
	glutTimerFunc(Sa.getV(), saturn_update_ring, 0);
	glutTimerFunc(Ur.getV(), uranus_update, 0);
	glutTimerFunc(Ne.getV(), neptune_update, 0);
	glutTimerFunc(Ne.getV(), neptune_ring_update, 0);
	glutTimerFunc(Tr.getV(), triton_update, 0);

	
	glutMainLoop();
	
	return 0;
}



