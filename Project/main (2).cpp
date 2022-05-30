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
void circleDraw(float); // Строим окружности (зависит от радиуса)
void planetsDraw(); // Строим планеты (см. функции ниже)

void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //задает значения очистки цветом
}
// RGB Red Green Blue



// По умолчанию тест глубины отключен. Включим его.
void initRendering() { // Рендер
	glEnable(GL_DEPTH_TEST); // Запуск функции из gl. А именно: Тест глубины
}
// Теперь, с включенным тестом глубины OpenGL будет автоматически сохранять значения глубины
// для всех прошедших тест фрагментов и отбрасывать не прошедшие.


void handleResize(int w, int h) {
	glViewport(0, 0, w, h); // Функция задает окно просмотра.
	glMatrixMode(GL_PROJECTION); //Функция указывает, какая матрица является текущей матрицей.
	// Применяет последующие операции с матрицей к стеку матрицы проекции.

	glLoadIdentity(); //Функция заменяет текущую матрицу матрицей идентификаторов.
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0); // Функция настраивает матрицу перспективной проекции.
	// 1. Угол обзора в направлении OY
	// 2. Соотношение X к Y (нужно для пропорций)
	// 3. Последние две переменные отвечают за расстояние от зрителя до плоскостей

}

// Углы просмотра
// .f после числа делает его числом с плавающей запятой.
float mercury_angle = 30.0f; // стартовые углы
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
	float R; // Радиус
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
	float R = 0.492; // Радиус
	float V = 4.82; // Время, за которое планета делает свой полный оборот вокруг солнца
	float S = 3.84; // расстояние до солнца
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
	float R = 0.4755; // Радиус
	float V = 12.3; // Скорость планеты
	float S = 7.23; // расстояние до солнца

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
	float R = 1; // Радиус
	float V = 15; // Скорость планеты
	float S = 10; // расстояние до солнца

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
	float R = 0.4; // Радиус
	float V = 15; // Скорость планеты
	float SSun = 10; // расстояние до солнца
	float S = 1.7; // Расстояние спутника до её планеты

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
	float R = 0.8; // Радиус
	float V = 25.2; // Скорость планеты
	float S = 15.2; // расстояние до солнца

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
	float R = 0.4; // Радиус
	float V = 25.2; // Скорость планеты
	float SSun = 15.0; // расстояние до солнца
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
	float R = 0.3; // Радиус
	float V = 25.2; // Скорость планеты
	float SSun = 15.0; // расстояние до солнца
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
	float R = 2; // Радиус
	float V = 36.5; // Скорость планеты
	float S = 24.0; // расстояние до солнца

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
	float R = 0.3; // Радиус
	float V = 36.5; // Скорость планеты
	float SSun = 24.0; // расстояние до солнца
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
	float R = 0.36; // Радиус
	float V = 36.5; // Скорость планеты
	float SSun = 24.0; // расстояние до солнца
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
	float R = 1.7; // Радиус
	float V = 40.2; // Скорость планеты
	float S = 32.0; // расстояние до солнца

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
	float R = 1.6; // Радиус
	float V = 50.5; // Скорость планеты
	float S = 42.0; // расстояние до солнца

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
	float R = 1.5; // Радиус
	float V = 61.8; // Скорость планеты
	float S = 51.0; // расстояние до солнца

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
	float R = 0.36; // Радиус
	float V = 61.8; // Скорость планеты
	float SSun = 51.1; // расстояние до солнца
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


//Рисует 3д сцену
void sceneDraw() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // очищает указанные буферы, а именно
	// Очистка буфера цвета и 	Очистка буфера глубины.
	glMatrixMode(GL_MODELVIEW); // Применяет последующие матричные операции к стеку матриц представления модели.
	glLoadIdentity(); // заменяет текущую матрицу матрицей идентификаторов.
	glTranslatef(0.0, 0.0, -50.0f); // модифицируем текущую матрицу ( которая в данный момент единичная). (Масштаб)
	glScalef(0.4f, 0.4f, 0.4f); // меняет масштаб

	// Строим орбиты планет (данные взяты из интернета)
	circleDraw(4.62); // Функция
	circleDraw(9);
	circleDraw(12.5);
	circleDraw(18.8);
	circleDraw(30);
	circleDraw(39.5);
	circleDraw(52);
	circleDraw(63);
	
	planetsDraw(); // Строим планеты
	//sputnikDraw();
	glutSwapBuffers(); //После отрисовки мы переставляем (заменяем) буфера

	/*
	Swap Buffers - обмен буферов. Это очень полезно при анимации.
	Мы используем окно с двойной буферизацией, один буфер отображаемый и второй - спрятанный.
	В таком режиме инструкции OpenGL по рисованию изображений всегда применяются к спрятанному буферу.
	Вызов функции glutSwapBuffers обменивает буфера, отображая окно целиком после того, как оно уже сформировано.
	Эта технология обычна в компьютерной анимации, так как не позволяет человеческому глазу видеть, как линия за линией формируется кадр.
	*/

}


void planetsDraw() {

	//Sun
	Sun Su;
	glPushMatrix(); //для сохранения и восстановления текущих координат
	/*
	Сдвигает текущий стек матриц на единицу вниз, дублируя текущую матрицу.
	То есть после вызова glPushMatrix матрица наверху стека идентична матрице под ним.
	*/
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //Она устанавливает опции для отрисовки многоугольника.
	/*
	Второй параметр указывает, как будет рисоваться многоугольник.
	Он принимает значения: GL_POINT(рисуются только точки), GL_LINE(рисуем линии) и GL_FILL(рисуем заполненный многоугольник).
	Первый параметр указывает: к лицевой, тыльной или же к обеим сторонам применяется опция, заданная вторым параметром.
	*/
	glColor3f(0.9, 0.9, 0.0);
	/*
	Следующие строки кода используют команду glColor3f(r, g, b).
	Три ее параметра указывают насыщенность цвета красной, синей и зеленой составляющей.
	Каждый из них может принимать значение от 0.0f до 1.0f.
	*/
	glutSolidSphere(Su.getR(), 50, 50);
	// glutSolidSphere(GLdouble radius, GLint slices, GLint stacks)
	// Строит сферу с радиусом 2.5, 
	/*
	slices Количество делений вокруг оси Z. (широта)
	stacks Количество делений вдоль оси z. (долгота (см. глобус))
	*/
	glEnd(); // мы закончили рисовать приметив
	glPopMatrix(); // извлекает текущий стек матриц, заменяя текущую матрицу той, что находится под ней в стеке.

	// Дальше аналогично

	// Матрица - двумерный массив из вещественных чисел.
	//Меркурий
	Mercury Me;
	glPushMatrix();
	glRotatef(mercury_angle, 0.0f, 0.0f, 1.0f); // Поворот системы координат
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	//glTranslatef(3.84f, 0.0, 0.0f); // Смещение системы координат для меркурия
	glTranslatef(Me.getS(), 0.0, 0.0f); // Смещает планету от центра (от Солнца)
	glutSolidSphere(Me.getR(), 50, 50);
	glPopMatrix();

	//Венера
	Venus Ve;
	// Для вывода изображения используется матрица преобразований (для кручения, движения итд)
	glPushMatrix(); // Сохраняет текущую матрицу в стек. После изменений мы сможем снова её загрузить из стека.
	glRotatef(venus_angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(Ve.getS(), 0.0, 0.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(255.0, 215.0, 0.75);
	glutSolidSphere(Ve.getR(), 50, 50);
	glPopMatrix(); // Извлекает матрицу из стека и устанавливает её в качестве текущей


	//Земля
	Earth Ea;
	glPushMatrix();
	glRotatef(earth_angle, 0.0f, 0.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.137255, 0.137255, 0.556863);
	glTranslatef(Ea.getS(), 0.0, 0.0f);
	glutSolidSphere(Ea.getR(), 50, 50);
	glPopMatrix();


	//Луна
	Moon Mo;
	glPushMatrix();
	glRotatef(moon_angle, 0.0f, 0.0f, 2.0f);
	glTranslatef(Mo.getSSun(), 0.0, 0.0f); // отдаляем от Солнца
	glRotatef(moon_angle, 0.0f, 0.0f, 2.0f);
	glTranslatef(Mo.getS(), 0.0, 0.0f); // расстояние от Земли
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.8f, 0.8f, 0.8f);
	//glTranslatef(11.7f, 0.0, 0.0f); // Расстояние, на которое объект удалён от центра 11.7
	glutSolidSphere(Mo.getR(), 50, 50);
	glPopMatrix();

	//Орбита Луны
	glPushMatrix();
	glRotatef(earth_ring_angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(12.4f, 0.0, 0.0f);
	circleDraw(2); // зависимость от радиуса
	glPopMatrix();

	//Марс
	Mars Ma;
	glPushMatrix();
	glRotatef(mars_angle, 0.0f, 0.0f, 1.0f); // (угол, на который смещается планета в ед. времени, 
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.8, 0.0, 0.0); // кр зел син
	glTranslatef(Ma.getS(), 0.0, 0.0f);
	glutSolidSphere(Ma.getR(), 50, 50);
	glPopMatrix();

	//Орбита Фобоса
	glPushMatrix();
	glRotatef(mars_ring_angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(18.75f, 0.0, 0.0f); // 18.75
	circleDraw(2); // зависимость от радиуса
	glPopMatrix();

	//Орбита Деймоса
	glPushMatrix();
	glRotatef(mars_ring_angle2, 0.0f, 0.0f, 1.0f);
	glTranslatef(18.77f, 0.0, 0.0f); // 18.75
	circleDraw(3.3); // зависимость от радиуса
	glPopMatrix();

	// Спутник Марса (Фобос)
	Fobos Fo;
	glPushMatrix();
	glRotatef(fobos_angle, 0.0f, 0.0f, 2.0f);
	glTranslatef(Fo.getSSun(), 0.0, 0.0f); // вдаль от солнца
	glRotatef(fobos_angle, 0.0f, 0.0f, 2.0f);
	glTranslatef(Fo.getS(), 0.0, 0.0f); // смещение от Марса
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.8f, 0.8f, 0.8f);
	glutSolidSphere(Fo.getR(), 50, 50);
	glPopMatrix();

	// Спутник Марса (Деймос)
	Deimos De;
	glPushMatrix();
	glRotatef(deimos_angle, 0.0f, 0.0f, 2.0f);
	glTranslatef(De.getSSun(), 0.0, 0.0f); // вдаль от солнца
	glRotatef(deimos_angle2, 0.0f, 0.0f, 2.0f);
	glTranslatef(De.getS(), 0.0, 0.0f); // смещение от Марса
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.8f, 0.8f, 0.8f);
	glutSolidSphere(De.getR(), 50, 50);
	glPopMatrix();


	//Юпитер
	Jupiter Ju;
	glPushMatrix();
	glRotatef(jupiter_angle, 0.0f, 0.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.36, 0.25, 0.20);
	glTranslatef(Ju.getS(), 0.0f, 0.0f);
	glutSolidSphere(Ju.getR(), 50, 50);
	glPopMatrix();

	//Орбита Ио
	glPushMatrix();
	glRotatef(io_ring_angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(29.75f, 0.0, 0.0f); // 18.75
	circleDraw(3.1); // зависимость от радиуса
	glPopMatrix();

	// Ио
	Io Io;
	glPushMatrix();
	glRotatef(io_angle, 0.0f, 0.0f, 2.0f);
	glTranslatef(Io.getSSun(), 0.0, 0.0f); // вдаль от солнца
	glRotatef(io_angle, 0.0f, 0.0f, 2.0f);
	glTranslatef(Io.getS(), 0.0, 0.0f); // смещение от Марса
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.8f, 0.8f, 0.0f);
	glutSolidSphere(Io.getR(), 50, 50);
	glPopMatrix();

	//Орбита Европы
	glPushMatrix();
	glRotatef(europa_ring_angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(29.75f, 0.0, 0.0f); // 18.75
	circleDraw(3.9); // зависимость от радиуса
	glPopMatrix();

	// Европа
	Europa Eu;
	glPushMatrix();
	glRotatef(europa_angle, 0.0f, 0.0f, 2.0f);
	glTranslatef(Eu.getSSun(), 0.0, 0.0f); // вдаль от солнца
	glRotatef(europa_angle2, 0.0f, 0.0f, 2.0f);
	glTranslatef(Eu.getS(), 0.0, 0.0f); // смещение от Марса
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1.0f, 0.6f, 0.0f);
	glutSolidSphere(Eu.getR(), 50, 50);
	glPopMatrix();

	//Сатурн
	Saturn Sa;
	glPushMatrix();
	glRotatef(satrun_angle, 0.0f, 0.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glTranslatef(Sa.getS(), 0.0, 0.0f);
	glColor3f(0.8, 0.8, 0.5);
	glutSolidSphere(Sa.getR(), 50, 50);
	glPopMatrix();

	//Кольцо Сатурна
	glPushMatrix();
	glRotatef(satrun_ring_angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(39.73f, 0.0, 0.0f);
	glColor3f(0.8, 0.8, 0.6);
	circleDraw(3);
	glPopMatrix();

	//Уран
	Uranus Ur;
	glPushMatrix();
	glRotatef(uranus_angle, 0.0f, 0.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.5, 0.5, 1);
	glTranslatef(Ur.getS(), 0.0, 0.0f);
	glutSolidSphere(Ur.getR(), 50, 50);
	glPopMatrix();

	//Нептун
	Neptune Ne;
	glPushMatrix();
	glRotatef(neptune_angle, 0.0f, 0.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.35, 0.35, 0.67);
	glTranslatef(Ne.getS(), 0.0, 0.0f);
	glutSolidSphere(Ne.getR(), 50, 50);
	glPopMatrix();

	//Орбита Нептуна
	glPushMatrix();
	glRotatef(neptune_ring_angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(63.2f, 0.0, 0.0f); // 18.75
	circleDraw(3); // зависимость от радиуса
	glPopMatrix();

	// Тритон
	Triton Tr;
	glPushMatrix();
	glRotatef(triton_angle, 0.0f, 0.0f, 2.0f);
	glTranslatef(Tr.getSSun(), 0.0, 0.0f); // вдаль от солнца
	glRotatef(triton_angle, 0.0f, 0.0f, 2.0f);
	glTranslatef(Tr.getS(), 0.0, 0.0f); // смещение от Марса
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.6f, 1.0f, 1.0f);
	glutSolidSphere(Tr.getR(), 50, 50);
	glPopMatrix();
}


void circleDraw(float radius) { // Функция построения окружности с радиусом (радиус - вещественное число)

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

	glColor3f(1.0, 1.0, 1.0); // белый цвет
	glPushMatrix();
	glBegin(GL_LINE_LOOP);
	for (i = min_angle; i <= max_angle; i++) { // цикл от 0 до 360 градусов
		
		theta = 0.0174532925 * float(i); // 1 градус это 0.0174532925 радиан. Мы задаём i-ый итерационный угол, theta - угол в рад (мы перевели угол в градусах в угол в радианах ради косинуса и синуса)
		cir_x_itr = radius * cosf(theta); // координаты для рисования i-ой итерационной точки по х и у
		cir_y_itr = radius * sinf(theta); 

		// x = R*cos(theta) ; (theta в радианах)
		// y = R*sin(theta)

		x = cir_x + cir_x_itr; // x текущее положение x (то есть прошлое + прибавка нынешнего x)
		y = cir_y + cir_y_itr;

		glVertex3f(x, y, -30.0f); // Указывает вершины по координатам.  Z = -30.0 для соблюдения масштаба
	}
	glEnd();
	glPopMatrix();
}


void mercury_update(int value) {
	mercury_angle += 2.0f; // 2 градуса в секунду - скорость планеты
	if (mercury_angle > 360) {
		mercury_angle -= 360;
	}

	Mercury Me;
	glutPostRedisplay(); // помечает активное окно, которое должно быть перерисовано, для вызова основного цикла
	glutTimerFunc(Me.getV(), mercury_update, 0);
	/*
	Эта функция устанавливает таймер.
	Первый параметр millis задает время в миллисекундах, по истечении которых вызывается функция,
	(вторая космическая скорость)
	которая указана как второй параметр.
	Третий параметр value указывает индентификатор таймера,
	т.е. таймеров может быть одновременно запущено несколько.
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

// стартовый угол earth_angle = 30.0f; +=2.0f. Следующая микростадия 32, 34 .....
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
	moon_angle += 2.0f; // Скорость, с которой движется объект по орбите
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
	fobos_angle += 2.0f; // Скорость, с которой движется объект по орбите
	if (fobos_angle > 360) {
		fobos_angle -= 360;
	}

	Fobos Fo;
	glutPostRedisplay();
	glutTimerFunc(Fo.getV(), fobos_update, 0);
}

void deimos_update(int value) {
	deimos_angle += 2.0f; // Скорость, с которой движется объект по орбите
	if (deimos_angle > 360) {
		deimos_angle -= 360;
	}

	Deimos De;
	glutPostRedisplay();
	glutTimerFunc(De.getV(), deimos_update, 0); //15
}

void deimos_update2(int value) {
	deimos_angle2 += 3.0f; // Скорость, с которой движется объект по орбите
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
	io_angle += 2.0f; // Скорость, с которой движется объект по орбите
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
	europa_angle += 2.0f; // Скорость, с которой движется объект по орбите
	if (europa_angle > 360) {
		europa_angle -= 360;
	}

	Europa Eu;
	glutPostRedisplay();
	glutTimerFunc(Eu.getV(), europa_update, 0); //15
}

void europa_update2(int value) {
	europa_angle2 += 1.5f; // Скорость, с которой движется объект по орбите
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
	// argc - количество параметров, передаваемых в функцию main
	// argv[] - массив указателей на строки
	// argc + argv нужны, чтоб заработал glutInit, когда он через командную строку обращается к своей библиотеке glut
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
	argc - это указатель на еще не измененную переменную argc главной функции программы (main).
	После возврата из функции, значение, на которое указывает argcp, может измениться,
	так как glutInit вычленяет все опции командной строки, относящиеся к библиотеке GLUT,
	например, в системе X-Window все опции, относящиеся к управлению окнами, ассоциируются с GLUT.
	argv - это еще не измененная переменная argv главной функции.

	glutInit позаботится об инициализации переменных состояния GLUT
	и откроет сессию с системой управления окнами.
	*/

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	/* Выбор режима окна:
   Одиночный буфер и RGBA палитра */
	glutInitWindowSize(1080, 720);
	/* Установка размеров окна */

	initGL(); // Очистка цвета

	glutCreateWindow("2D Solar System"); // Создание окна
	initRendering(); // Рендер с тестом глубины


	glutDisplayFunc(sceneDraw); // Отрисовка сцены
	glutReshapeFunc(handleResize);


	glutTimerFunc(Me.getV(), mercury_update, 0); // Функция, которая выполняет ( Me.getV() скорее не скорость, а время за которое у нас проходит круг)
	glutTimerFunc(Ve.getV(), venus_update, 0); //  (периодичность выполнения, выполняемая функция, идендификатор таймера )
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



