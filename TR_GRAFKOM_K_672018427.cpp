#include <windows.h>
#include <gl/Gl.h>
#include <gl/glut.h>


void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void mouse(int button, int state, int x, int y);
void ukuran(int, int);
void mouseMotion(int x, int y);

float xrot =0.f;
float yrot = 0.f;
float xdiff = 0.f;
float ydiff = 0.f;
bool mouseDown = false;
int is_depth;

int main (int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(250, 50);
	glutCreateWindow("STADE DES ALPES - 672018198, 672018427");
	init();
	glutDisplayFunc(tampil);
	glutKeyboardFunc(keyboard);
	
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	
	glutReshapeFunc(ukuran);
	glutDisplayFunc(tampil);
	glutMainLoop();
	return 0;
}

void init(void)
{
	glClearColor(0.8,1,1,0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	is_depth=1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(3);
	glLineWidth(3);
}

void tampil(void)
{
	glPushMatrix();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	gluLookAt(0,0,3,0,0,0,0,1,0);
	glRotatef(xrot, 1, 0,0);
	glRotatef(yrot, 0,1,0);
	
	//lapangan
	glBegin(GL_QUADS);
	glColor3ub(138, 201, 38);
	glVertex3f(-30, 0, -65);
	glVertex3f(-30,0,65);
	glVertex3f(30,0,65);
	glVertex3f(30,0,-65);
	glEnd();
	//garis lapangan
	//keliling
	glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
	glVertex3f(-25, 0.1, -55);
	glVertex3f(-25,0.1,55);
	
	glVertex3f(-25, 0.1, 55);
	glVertex3f(25,0.1,55);
	
	glVertex3f(25,0.1,55);
	glVertex3f(25,0.1,-55);
	
	glVertex3f(25, 0.1, -55);
	glVertex3f(-25,0.1,-55);
	//tengah
	glVertex3f(25, 0.1, 0);
	glVertex3f(-25,0.1,0);
	//belakang
	//kotak1
	glVertex3f(-15, 0.1, -55);
	glVertex3f(-15,0.1,-35);
	
	glVertex3f(-15, 0.1, -35);
	glVertex3f(15,0.1,-35);
	
	glVertex3f(15, 0.1, -35);
	glVertex3f(15,0.1,-55);
	//kotak2
	glVertex3f(-8, 0.1, -55);
	glVertex3f(-8,0.1,-45);
	
	glVertex3f(-8, 0.1, -45);
	glVertex3f(8,0.1,-45);
	
	glVertex3f(8, 0.1, -55);
	glVertex3f(8,0.1,-45);
	//depan
	//kotak1
	glVertex3f(-15, 0.1, 55);
	glVertex3f(-15,0.1,35);
	
	glVertex3f(-15, 0.1, 35);
	glVertex3f(15,0.1,35);
	
	glVertex3f(15, 0.1, 35);
	glVertex3f(15,0.1,55);
	//kotak2
	glVertex3f(-8, 0.1, 55);
	glVertex3f(-8,0.1,45);
	
	glVertex3f(-8, 0.1, 45);
	glVertex3f(8,0.1,45);
	
	glVertex3f(8, 0.1, 55);
	glVertex3f(8,0.1,45);
	glEnd();
	
	//titik penalti
	glBegin(GL_POINTS);
	glColor3ub(255, 255, 255);
	glVertex3f(0, 0.1, -40);
	glVertex3f(0, 0.1, 40);
	glEnd();
	
	//gawang belakang
	//depan
	//kiri
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-6, 0, -55);
	glVertex3f(-5.5,0,-55);
	glVertex3f(-5.5,5,-55);
	glVertex3f(-6,5,-55);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(6, 0, -55);
	glVertex3f(5.5,0,-55);
	glVertex3f(5.5,5,-55);
	glVertex3f(6,5,-55);
	glEnd();
	//atas
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-6, 5, -55);
	glVertex3f(-5.5,4.5,-55);
	glVertex3f(5.5,4.5,-55);
	glVertex3f(6,5,-55);
	glEnd();
	//belakang
	//kiri
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-6, 0, -55.5);
	glVertex3f(-5.5,0,-55.5);
	glVertex3f(-5.5,5,-55.5);
	glVertex3f(-6,5,-55.5);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(6, 0, -55.5);
	glVertex3f(5.5,0,-55.5);
	glVertex3f(5.5,5,-55.5);
	glVertex3f(6,5,-55.5);
	glEnd();
	//atas
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-6, 5, -55.5);
	glVertex3f(-5.5,4.5,-55.5);
	glVertex3f(5.5,4.5,-55.5);
	glVertex3f(6,5,-55.5);
	glEnd();
	//tutup
	//kiri1
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-6, 0, -55);
	glVertex3f(-6,0,-55.5);
	glVertex3f(-6,5,-55.5);
	glVertex3f(-6,5,-55);
	glEnd();
	//kiri2
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-5.5, 0, -55);
	glVertex3f(-5.5,0,-55.5);
	glVertex3f(-5.5,5,-55.5);
	glVertex3f(-5.5,5,-55);
	glEnd();
	//kanan1
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(6, 0, -55);
	glVertex3f(6,0,-55.5);
	glVertex3f(6,5,-55.5);
	glVertex3f(6,5,-55);
	glEnd();
	//kanan2
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(5.5, 0, -55);
	glVertex3f(5.5,0,-55.5);
	glVertex3f(5.5,5,-55.5);
	glVertex3f(5.5,5,-55);
	glEnd();
	//atas
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-6, 5, -55);
	glVertex3f(-6,5,-55.5);
	glVertex3f(6,5,-55.5);
	glVertex3f(6,5,-55);
	glEnd();
	//bawah
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-6, 4.5, -55);
	glVertex3f(-6,4.5,-55.5);
	glVertex3f(6,4.5,-55.5);
	glVertex3f(6,4.5,-55);
	glEnd();
	
	//gawang depan
	//depan
	//kiri
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-6, 0, 55);
	glVertex3f(-5.5,0,55);
	glVertex3f(-5.5,5,55);
	glVertex3f(-6,5,55);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(6, 0, 55);
	glVertex3f(5.5,0,55);
	glVertex3f(5.5,5,55);
	glVertex3f(6,5,55);
	glEnd();
	//atas
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-6, 5, 55);
	glVertex3f(-5.5,4.5,55);
	glVertex3f(5.5,4.5,55);
	glVertex3f(6,5,55);
	glEnd();
	//belakang
	//kiri
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-6, 0, 55.5);
	glVertex3f(-5.5,0,55.5);
	glVertex3f(-5.5,5,55.5);
	glVertex3f(-6,5,55.5);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(6, 0, 55.5);
	glVertex3f(5.5,0,55.5);
	glVertex3f(5.5,5,55.5);
	glVertex3f(6,5,55.5);
	glEnd();
	//atas
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-6, 5, 55.5);
	glVertex3f(-5.5,4.5,55.5);
	glVertex3f(5.5,4.5,55.5);
	glVertex3f(6,5,55.5);
	glEnd();
	//tutup
	//kiri1
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-6, 0, 55);
	glVertex3f(-6,0,55.5);
	glVertex3f(-6,5,55.5);
	glVertex3f(-6,5,55);
	glEnd();
	//kiri2
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-5.5, 0, 55);
	glVertex3f(-5.5,0,55.5);
	glVertex3f(-5.5,5,55.5);
	glVertex3f(-5.5,5,55);
	glEnd();
	//kanan1
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(6, 0, 55);
	glVertex3f(6,0,55.5);
	glVertex3f(6,5,55.5);
	glVertex3f(6,5,55);
	glEnd();
	//kanan2
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(5.5, 0, 55);
	glVertex3f(5.5,0,55.5);
	glVertex3f(5.5,5,55.5);
	glVertex3f(5.5,5,55);
	glEnd();
	//atas
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-6, 5, 55);
	glVertex3f(-6,5,55.5);
	glVertex3f(6,5,55.5);
	glVertex3f(6,5,55);
	glEnd();
	//bawah
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-6, 4.5, 55);
	glVertex3f(-6,4.5,55.5);
	glVertex3f(6,4.5,55.5);
	glVertex3f(6,4.5,55);
	glEnd();
	
	//tribun
	//dasar tribun + parkir
	glBegin(GL_QUADS);
	glColor3ub(200, 200, 200);
	glVertex3f(-75, -0.1, -105);
	glVertex3f(-75,-0.1,105);
	glVertex3f(75,-0.1,105);
	glVertex3f(75,-0.1,-105);
	glEnd();
	//tembok naik kiri
	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(-35, 0,65);
	glVertex3f(-35,0,5);
	glVertex3f(-35,2,5);
	glVertex3f(-35,2,65);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(-35, 0,-65);
	glVertex3f(-35,0,-5);
	glVertex3f(-35,2,-5);
	glVertex3f(-35,2,-65);
	glEnd();
	//tembok naik kanan
	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(35, 0,65);
	glVertex3f(35,0,5);
	glVertex3f(35,2,5);
	glVertex3f(35,2,65);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(35, 0,-65);
	glVertex3f(35,0,-5);
	glVertex3f(35,2,-5);
	glVertex3f(35,2,-65);
	glEnd();
	//tembok naik depan
	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(-30, 0,70);
	glVertex3f(30,0,70);
	glVertex3f(30,2,70);
	glVertex3f(-30,2,70);
	glEnd();
	//tembok naik belakang
	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(-30, 0,-70);
	glVertex3f(30,0,-70);
	glVertex3f(30,2,-70);
	glVertex3f(-30,2,-70);
	glEnd();
	
	//tribun dasar
	//depan
	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(-30, 2,70);
	glVertex3f(30,2,70);
	glVertex3f(45,10,85);
	glVertex3f(-45,10,85);
	glEnd();
	//belakang
	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(-30, 2,-70);
	glVertex3f(30,2,-70);
	glVertex3f(45,10,-85);
	glVertex3f(-45,10,-85);
	glEnd();
	//kiri
	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(-35, 2,65);
	glVertex3f(-35,2,5);
	glVertex3f(-50,10,5);
	glVertex3f(-50,10,80);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(-35, 2,-65);
	glVertex3f(-35,2,-5);
	glVertex3f(-50,10,-5);
	glVertex3f(-50,10,-80);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(35, 2,65);
	glVertex3f(35,2,5);
	glVertex3f(50,10,5);
	glVertex3f(50,10,80);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(35, 2,-65);
	glVertex3f(35,2,-5);
	glVertex3f(50,10,-5);
	glVertex3f(50,10,-80);
	glEnd();
	
	//sambungan sudut tribun
	//kiri belakang
	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(-45, 10,-85);
	glVertex3f(-50,10,-80);
	glVertex3f(-40,4.6,-70);
	glVertex3f(-35,4.6,-75);
	glEnd();
	//kiri depan
	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(-45, 10,85);
	glVertex3f(-50,10,80);
	glVertex3f(-40,4.6,70);
	glVertex3f(-35,4.6,75);
	glEnd();
	//kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(45, 10,-85);
	glVertex3f(50,10,-80);
	glVertex3f(40,4.6,-70);
	glVertex3f(35,4.6,-75);
	glEnd();
	//kanan depan
	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(45, 10,85);
	glVertex3f(50,10,80);
	glVertex3f(40,4.6,70);
	glVertex3f(35,4.6,75);
	glEnd();
	
	//sambungan tengah
	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(50, 10,-5);
	glVertex3f(50,10,5);
	glVertex3f(40,4.6,5);
	glVertex3f(40,4.6,-5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(-50, 10,-5);
	glVertex3f(-50,10,5);
	glVertex3f(-40,4.6,5);
	glVertex3f(-40,4.6,-5);
	glEnd();
	
	//tembok dalam tengah kiri
	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(-50, 0,-5);
	glVertex3f(-50,10,-5);
	glVertex3f(-35,2,-5);
	glVertex3f(-35,0,-5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(-50, 0,5);
	glVertex3f(-50,10,5);
	glVertex3f(-35,2,5);
	glVertex3f(-35,0,5);
	glEnd();
	//tembok dalam tengah kanan
	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(50, 0,-5);
	glVertex3f(50,10,-5);
	glVertex3f(35,2,-5);
	glVertex3f(35,0,-5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(50, 0,5);
	glVertex3f(50,10,5);
	glVertex3f(35,2,5);
	glVertex3f(35,0,5);
	glEnd();
	//tembok sudut kiri depan
	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(-50, 0,80);
	glVertex3f(-50,10,80);
	glVertex3f(-35,2,65);
	glVertex3f(-35,0,65);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(-45, 0,85);
	glVertex3f(-45,10,85);
	glVertex3f(-30,2,70);
	glVertex3f(-30,0,70);
	glEnd();
	//tembok sudut kanan depan
	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(50, 0,80);
	glVertex3f(50,10,80);
	glVertex3f(35,2,65);
	glVertex3f(35,0,65);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(45, 0,85);
	glVertex3f(45,10,85);
	glVertex3f(30,2,70);
	glVertex3f(30,0,70);
	glEnd();
	//tembok sudut kiri belakang
	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(-50, 0,-80);
	glVertex3f(-50,10,-80);
	glVertex3f(-35,2,-65);
	glVertex3f(-35,0,-65);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(-45, 0,-85);
	glVertex3f(-45,10,-85);
	glVertex3f(-30,2,-70);
	glVertex3f(-30,0,-70);
	glEnd();
	//tembok sudut kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(50, 0,-80);
	glVertex3f(50,10,-80);
	glVertex3f(35,2,-65);
	glVertex3f(35,0,-65);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(220, 220, 220);
	glVertex3f(45, 0,-85);
	glVertex3f(45,10,-85);
	glVertex3f(30,2,-70);
	glVertex3f(30,0,-70);
	glEnd();
	
	//kursi tribun depan
	//kiri segitiga
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 255);
	glVertex3f(-30, 2.1,70);
	glVertex3f(-45,10.1,85);
	glVertex3f(-30,10.1,85);
	glEnd();
	//kanan segitiga
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 255);
	glVertex3f(30, 2.1,70);
	glVertex3f(45,10.1,85);
	glVertex3f(30,10.1,85);
	glEnd();
	//kiri kotak
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-28, 2.1,70);
	glVertex3f(-12,2.1,70);
	glVertex3f(-12,10.1,85);
	glVertex3f(-28,10.1,85);
	glEnd();
	//kanan kotak
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(28, 2.1,70);
	glVertex3f(12,2.1,70);
	glVertex3f(12,10.1,85);
	glVertex3f(28,10.1,85);
	glEnd();
	//tengah kotak
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-10, 2.1,70);
	glVertex3f(10,2.1,70);
	glVertex3f(10,10.1,85);
	glVertex3f(-10,10.1,85);
	glEnd();
	
	//kursi tribun belakang
	//kiri segitiga
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 255);
	glVertex3f(-30, 2.1,-70);
	glVertex3f(-45,10.1,-85);
	glVertex3f(-30,10.1,-85);
	glEnd();
	//kanan segitiga
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 255);
	glVertex3f(30, 2.1,-70);
	glVertex3f(45,10.1,-85);
	glVertex3f(30,10.1,-85);
	glEnd();
	//kiri kotak
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-28, 2.1,-70);
	glVertex3f(-12,2.1,-70);
	glVertex3f(-12,10.1,-85);
	glVertex3f(-28,10.1,-85);
	glEnd();
	//kanan kotak
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(28, 2.1,-70);
	glVertex3f(12,2.1,-70);
	glVertex3f(12,10.1,-85);
	glVertex3f(28,10.1,-85);
	glEnd();
	//tengah kotak
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-10, 2.1,-70);
	glVertex3f(10,2.1,-70);
	glVertex3f(10,10.1,-85);
	glVertex3f(-10,10.1,-85);
	glEnd();
	
	//kursi tribun kiri
	//kiri segitiga
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 255);
	glVertex3f(-35, 2.1,65);
	glVertex3f(-50,10.1,65);
	glVertex3f(-50,10.1,80);
	glEnd();
	//kanan segitiga
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 255);
	glVertex3f(-35, 2.1,-65);
	glVertex3f(-50,10.1,-65);
	glVertex3f(-50,10.1,-80);
	glEnd();
	//kiri kotak 1
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-35, 2.1,63);
	glVertex3f(-35,2.1,40);
	glVertex3f(-50,10.1,40);
	glVertex3f(-50,10.1,63);
	glEnd();
	//kiri kotak 2
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-35, 2.1,38);
	glVertex3f(-35,2.1,15);
	glVertex3f(-50,10.1,15);
	glVertex3f(-50,10.1,38);
	glEnd();
	//kanan kotak 1
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-35,2.1,-63);
	glVertex3f(-35,2.1,-40);
	glVertex3f(-50,10.1,-40);
	glVertex3f(-50,10.1,-63);
	glEnd();
	//kanan kotak 2
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-35,2.1,-38);
	glVertex3f(-35,2.1,-15);
	glVertex3f(-50,10.1,-15);
	glVertex3f(-50,10.1,-38);
	glEnd();
	//tengah kotak1
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-50,10.1,-12);
	glVertex3f(-35,2.1,-12);
	glVertex3f(-35,2.1,-5);
	glVertex3f(-50,10.1,-5);
	glEnd();
	//tengah kotak2
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-50,10.1,12);
	glVertex3f(-35,2.1,12);
	glVertex3f(-35,2.1,5);
	glVertex3f(-50,10.1,5);
	glEnd();
	//tengah kotak1
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-50,10.1,-5);
	glVertex3f(-40,4.7,-5);
	glVertex3f(-40,4.7,5);
	glVertex3f(-50,10.1,5);
	glEnd();
	
	//kursi tribun kanan
	//kiri segitiga
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 255);
	glVertex3f(35, 2.1,65);
	glVertex3f(50,10.1,65);
	glVertex3f(50,10.1,80);
	glEnd();
	//kanan segitiga
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 255);
	glVertex3f(35, 2.1,-65);
	glVertex3f(50,10.1,-65);
	glVertex3f(50,10.1,-80);
	glEnd();
	//kiri kotak 1
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(35, 2.1,63);
	glVertex3f(35,2.1,40);
	glVertex3f(50,10.1,40);
	glVertex3f(50,10.1,63);
	glEnd();
	//kiri kotak 2
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(35, 2.1,38);
	glVertex3f(35,2.1,15);
	glVertex3f(50,10.1,15);
	glVertex3f(50,10.1,38);
	glEnd();
	//kanan kotak 1
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(35,2.1,-63);
	glVertex3f(35,2.1,-40);
	glVertex3f(50,10.1,-40);
	glVertex3f(50,10.1,-63);
	glEnd();
	//kanan kotak 2
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(35,2.1,-38);
	glVertex3f(35,2.1,-15);
	glVertex3f(50,10.1,-15);
	glVertex3f(50,10.1,-38);
	glEnd();
	//tengah kotak1
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(50,10.1,-12);
	glVertex3f(35,2.1,-12);
	glVertex3f(35,2.1,-5);
	glVertex3f(50,10.1,-5);
	glEnd();
	//tengah kotak2
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(50,10.1,12);
	glVertex3f(35,2.1,12);
	glVertex3f(35,2.1,5);
	glVertex3f(50,10.1,5);
	glEnd();
	//tengah kotak1
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(50,10.1,-5);
	glVertex3f(40,4.7,-5);
	glVertex3f(40,4.7,5);
	glVertex3f(50,10.1,5);
	glEnd();
	
	//bagian dinding stadion
	//bagian dalam
	//dalam belakang
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-45,0,-85);
	glVertex3f(-45,30,-85);
	glVertex3f(45,30,-85);
	glVertex3f(45,0,-85);
	glEnd();
	//dalam depan
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-45,0,85);
	glVertex3f(-45,30,85);
	glVertex3f(45,30,85);
	glVertex3f(45,0,85);
	glEnd();
	//dalam kanan 1
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-50,0,-80);
	glVertex3f(-50,30,-80);
	glVertex3f(-50,30,-5);
	glVertex3f(-50,0,-5);
	glEnd();
	//dalam kanan 2
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-50,0,5);
	glVertex3f(-50,30,5);
	glVertex3f(-50,30,80);
	glVertex3f(-50,0,80);
	glEnd();
	//dalam kanan tengah
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-50,10,-5);
	glVertex3f(-50,30,-5);
	glVertex3f(-50,30,5);
	glVertex3f(-50,10,5);
	glEnd();
	//dalam kiri 1
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(50,0,-80);
	glVertex3f(50,30,-80);
	glVertex3f(50,30,-5);
	glVertex3f(50,0,-5);
	glEnd();
	//dalam kiri 2
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(50,0,5);
	glVertex3f(50,30,5);
	glVertex3f(50,30,80);
	glVertex3f(50,0,80);
	glEnd();
	//dalam kiri tengah
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(50,10,-5);
	glVertex3f(50,30,-5);
	glVertex3f(50,30,5);
	glVertex3f(50,10,5);
	glEnd();
	//dalam sudut kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(45,10,-85);
	glVertex3f(45,30,-85);
	glVertex3f(50,30,-80);
	glVertex3f(50,10,-80);
	glEnd();
	//dalam sudut kiri belakang
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-45,10,-85);
	glVertex3f(-45,30,-85);
	glVertex3f(-50,30,-80);
	glVertex3f(-50,10,-80);
	glEnd();
	//dalam sudut kanan depan
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(45,10,85);
	glVertex3f(45,30,85);
	glVertex3f(50,30,80);
	glVertex3f(50,10,80);
	glEnd();
	//dalam sudut kiri depan
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-45,10,85);
	glVertex3f(-45,30,85);
	glVertex3f(-50,30,80);
	glVertex3f(-50,10,80);
	glEnd();

	//bagian luar
	//luar belakang
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(-45,0,-90);
	glVertex3f(-45,40,-90);
	glVertex3f(45,40,-90);
	glVertex3f(45,0,-90);
	glEnd();
	//luar depan
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(-45,0,90);
	glVertex3f(-45,40,90);
	glVertex3f(45,40,90);
	glVertex3f(45,0,90);
	glEnd();
	//luar kanan1
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(-55,0,-80);
	glVertex3f(-55,40,-80);
	glVertex3f(-55,40,-5);
	glVertex3f(-55,0,-5);
	glEnd();
	//luar kanan 2
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(-55,0,80);
	glVertex3f(-55,40,80);
	glVertex3f(-55,40,5);
	glVertex3f(-55,0,5);
	glEnd();
	//luar tengah kanan
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(-55,10,-5);
	glVertex3f(-55,40,-5);
	glVertex3f(-55,40,5);
	glVertex3f(-55,10,5);
	glEnd();
	//luar kiri
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(55,0,-80);
	glVertex3f(55,40,-80);
	glVertex3f(55,40,-5);
	glVertex3f(55,0,-5);
	glEnd();
	//luar kiri 2
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(55,0,5);
	glVertex3f(55,40,5);
	glVertex3f(55,40,80);
	glVertex3f(55,0,80);
	glEnd();
	//luar tengah kiri
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(55,10,-5);
	glVertex3f(55,40,-5);
	glVertex3f(55,40,5);
	glVertex3f(55,10,5);
	glEnd();
	//sudut
	//luar sudut kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(45,10,-90);
	glVertex3f(45,40,-90);
	glVertex3f(55,40,-80);
	glVertex3f(55,10,-80);
	glEnd();
	//luar sudut kiri belakang
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(-45,10,-90);
	glVertex3f(-45,40,-90);
	glVertex3f(-55,40,-80);
	glVertex3f(-55,10,-80);
	glEnd();
	//luar sudut kanan depan
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(45,10,90);
	glVertex3f(45,40,90);
	glVertex3f(55,40,80);
	glVertex3f(55,10,80);
	glEnd();
	//luar sudut kiri depan
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(-45,10,90);
	glVertex3f(-45,40,90);
	glVertex3f(-55,40,80);
	glVertex3f(-55,10,80);
	glEnd();
	
	//lengkung luar atas
	//belakang
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(-45,40,-90);
	glVertex3f(-40,50,-85);
	glVertex3f(40,50,-85);
	glVertex3f(45,40,-90);
	glEnd();
	//depan
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(-45,40,90);
	glVertex3f(-40,50,85);
	glVertex3f(40,50,85);
	glVertex3f(45,40,90);
	glEnd();
	//kiri
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(-55,40,-80);
	glVertex3f(-50,50,-75);
	glVertex3f(-50,50,75);
	glVertex3f(-55,40,80);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(55,40,-80);
	glVertex3f(50,50,-75);
	glVertex3f(50,50,75);
	glVertex3f(55,40,80);
	glEnd();
	//belakang kiri
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(-45,40,-90);
	glVertex3f(-40,50,-85);
	glVertex3f(-50,50,-75);
	glVertex3f(-55,40,-80);
	glEnd();
	//belakang kanan
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(45,40,-90);
	glVertex3f(40,50,-85);
	glVertex3f(50,50,-75);
	glVertex3f(55,40,-80);
	glEnd();
	//depan kiri
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(-45,40,90);
	glVertex3f(-40,50,85);
	glVertex3f(-50,50,75);
	glVertex3f(-55,40,80);
	glEnd();
	//depan kanan
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(45,40,90);
	glVertex3f(40,50,85);
	glVertex3f(50,50,75);
	glVertex3f(55,40,80);
	glEnd();
	
	//atas
	//belakang
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-40,50,-85);
	glVertex3f(-32,53,-72);
	
	glVertex3f(32,53,-72);
	glVertex3f(40,50,-85);
	glEnd();
	//depan
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-40,50,85);
	glVertex3f(-32,53,72);
	
	glVertex3f(32,53,72);
	glVertex3f(40,50,85);
	glEnd();
	//kiri
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,53,67);
	glVertex3f(-50,50,75);
	glVertex3f(-50,50,-75);
	glVertex3f(-37,53,-67);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,53,67);
	glVertex3f(50,50,75);
	glVertex3f(50,50,-75);
	glVertex3f(37,53,-67);
	glEnd();
	
	//sudut kiri depan
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-40,50,85);
	
	glVertex3f(-32,53,72);
	glVertex3f(-37,53,67);
	
	glVertex3f(-50,50,75);
	glEnd();
	//sudut kanan depan
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(40,50,85);
	
	glVertex3f(32,53,72);
	glVertex3f(37,53,67);
	
	glVertex3f(50,50,75);
	glEnd();
	//sudut kiri belakang
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-40,50,-85);
	
	glVertex3f(-32,53,-72);
	glVertex3f(-37,53,-67);
	
	glVertex3f(-50,50,-75);
	glEnd();
	//sudut kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(40,50,-85);
	
	glVertex3f(32,53,-72);
	glVertex3f(37,53,-67);
	
	glVertex3f(50,50,-75);
	glEnd();
	
	//paling luar
	//belakang
	glBegin(GL_QUADS);
	glColor3ub(213, 191, 134);
	glVertex3f(-45,20,-90.1);
	glVertex3f(-45,30,-90.1);
	glVertex3f(45,30,-90.1);
	glVertex3f(45,20,-90.1);
	glEnd();
	//depan
	glBegin(GL_QUADS);
	glColor3ub(213, 191, 134);
	glVertex3f(-45,20,90.1);
	glVertex3f(-45,30,90.1);
	glVertex3f(45,30,90.1);
	glVertex3f(45,20,90.1);
	glEnd();
	//kiri
	glBegin(GL_QUADS);
	glColor3ub(213, 191, 134);
	glVertex3f(-55.1,20,-80.1);
	glVertex3f(-55.1,30,-80.1);
	glVertex3f(-55.1,30,80.1);
	glVertex3f(-55.1,20,80.1);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(213, 191, 134);
	glVertex3f(55.1,20,-80.1);
	glVertex3f(55.1,30,-80.1);
	glVertex3f(55.1,30,80.1);
	glVertex3f(55.1,20,80.1);
	glEnd();
	//belakang kiri
	glBegin(GL_QUADS);
	glColor3ub(213, 191, 134);
	glVertex3f(-45,20,-90.1);
	glVertex3f(-45,30,-90.1);
	glVertex3f(-55,30,-80.1);
	glVertex3f(-55,20,-80.1);
	glEnd();
	//belakang kanan
	glBegin(GL_QUADS);
	glColor3ub(213, 191, 134);
	glVertex3f(45,20,-90.1);
	glVertex3f(45,30,-90.1);
	glVertex3f(55,30,-80.1);
	glVertex3f(55,20,-80.1);
	glEnd();
	//depan kiri
	glBegin(GL_QUADS);
	glColor3ub(213, 191, 134);
	glVertex3f(-45,20,90.1);
	glVertex3f(-45,30,90.1);
	glVertex3f(-55,30,80.1);
	glVertex3f(-55,20,80.1);
	glEnd();
	//depan kanan
	glBegin(GL_QUADS);
	glColor3ub(213, 191, 134);
	glVertex3f(45,20,90.1);
	glVertex3f(45,30,90.1);
	glVertex3f(55,30,80.1);
	glVertex3f(55,20,80.1);
	glEnd();
	
	//papan iklan
	//stad belakang
	//depan
	glBegin(GL_QUADS);
	glColor3ub(157, 209, 241);
	glVertex3f(-30,0,-65);
	glVertex3f(-30,3,-65);
	glVertex3f(30,3,-65);
	glVertex3f(30,0,-65);
	glEnd();
	//belakang
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(-30,0,-66);
	glVertex3f(-30,3,-66);
	glVertex3f(30,3,-66);
	glVertex3f(30,0,-66);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(-30,0,-65);
	glVertex3f(-30,3,-65);
	glVertex3f(-30,3,-66);
	glVertex3f(-30,0,-66);
	glEnd();
	//kiri
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(30,0,-65);
	glVertex3f(30,3,-65);
	glVertex3f(30,3,-66);
	glVertex3f(30,0,-66);
	glEnd();
	//atas
	glBegin(GL_QUADS);
	glColor3ub(157, 209, 241);
	glVertex3f(-30,3,-66);
	glVertex3f(-30,3,-65);
	glVertex3f(30,3,-65);
	glVertex3f(30,3,-66);
	glEnd();
	
	//stad depan
	//depan
	glBegin(GL_QUADS);
	glColor3ub(247, 23, 53);
	glVertex3f(-30,0,65);
	glVertex3f(-30,3,65);
	glVertex3f(30,3,65);
	glVertex3f(30,0,65);
	glEnd();
	//belakang
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(-30,0,66);
	glVertex3f(-30,3,66);
	glVertex3f(30,3,66);
	glVertex3f(30,0,66);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(-30,0,65);
	glVertex3f(-30,3,65);
	glVertex3f(-30,3,66);
	glVertex3f(-30,0,66);
	glEnd();
	//kiri
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(30,0,65);
	glVertex3f(30,3,65);
	glVertex3f(30,3,66);
	glVertex3f(30,0,66);
	glEnd();
	//atas
	glBegin(GL_QUADS);
	glColor3ub(247, 23, 53);
	glVertex3f(-30,3,66);
	glVertex3f(-30,3,65);
	glVertex3f(30,3,65);
	glVertex3f(30,3,66);
	glEnd();
	
	//stad kiri
	//depan
	glBegin(GL_QUADS);
	glColor3ub(247, 23, 53);
	glVertex3f(-30,0,65);
	glVertex3f(-30,3,65);
	glColor3ub(157, 209, 241);
	glVertex3f(-30,3,-65);
	glVertex3f(-30,0,-65);
	glEnd();
	//belakang
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(-31,0,65);
	glVertex3f(-31,3,65);
	glVertex3f(-31,3,-65);
	glVertex3f(-31,0,-65);
	glEnd();
	//atas
	glBegin(GL_QUADS);
	glColor3ub(247, 23, 53);
	glVertex3f(-30,3,65);
	glColor3ub(157, 209, 241);
	glVertex3f(-30,3,-65);
	glColor3ub(157, 209, 241);
	glVertex3f(-31,3,-65);
	glColor3ub(247, 23, 53);
	glVertex3f(-31,3,65);
	glEnd();
	//kiri
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(-31,3,-65);
	glVertex3f(-30,3,-65);
	glVertex3f(-30,0,-65);
	glVertex3f(-31,0,-65);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(-31,3,65);
	glVertex3f(-30,3,65);
	glVertex3f(-30,0,65);
	glVertex3f(-31,0,65);
	glEnd();
	
	//layar papan skor
	//1
	//depan
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(30,40,-90);
	glVertex3f(55,40,-65);
	glVertex3f(55,30,-65);
	glVertex3f(30,30,-90);
	glEnd();
	//layar
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(29.9,38,-90);
	glVertex3f(54.9,38,-64.9);
	glColor3ub(157, 209, 241);
	glVertex3f(54.9,32,-64.9);
	glVertex3f(29.9,32,-90);
	glEnd();
	
	//2
	//depan
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(-30,40,90);
	glVertex3f(-55,40,65);
	glVertex3f(-55,30,65);
	glVertex3f(-30,30,90);
	glEnd();
	//layar
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-29.9,38,90);
	glVertex3f(-54.9,38,64.9);
	glColor3ub(157, 209, 241);
	glVertex3f(-54.9,32,64.9);
	glVertex3f(-29.9,32,90);
	glEnd();
	
	//detail stadion
	//penghubung 1 depan kanan
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(55,0,80);
	glVertex3f(55,40,80);
	glVertex3f(50,40,80);
	glVertex3f(50,0,80);
	glEnd();
	//penghubung 1 depan kiri
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(-55,0,80);
	glVertex3f(-55,40,80);
	glVertex3f(-50,40,80);
	glVertex3f(-50,0,80);
	glEnd();
	//pengubung 2 depan kiri
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(-45,0,85);
	glVertex3f(-45,40,85);
	glVertex3f(-45,40,90);
	glVertex3f(-45,0,90);
	glEnd();
	//pengubung 2 depan kanan
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(45,0,85);
	glVertex3f(45,40,85);
	glVertex3f(45,40,90);
	glVertex3f(45,0,90);
	glEnd();
	
	//penghubung 1 belakang kanan
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(55,0,-80);
	glVertex3f(55,40,-80);
	glVertex3f(50,40,-80);
	glVertex3f(50,0,-80);
	glEnd();
	//penghubung 1 belakang kiri
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(-55,0,-80);
	glVertex3f(-55,40,-80);
	glVertex3f(-50,40,-80);
	glVertex3f(-50,0,-80);
	glEnd();
	//pengubung 2 belakang kiri
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(-45,0,-85);
	glVertex3f(-45,40,-85);
	glVertex3f(-45,40,-90);
	glVertex3f(-45,0,-90);
	glEnd();
	//pengubung 2 belakang kanan
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(45,0,-85);
	glVertex3f(45,40,-85);
	glVertex3f(45,40,-90);
	glVertex3f(45,0,-90);
	glEnd();
	//penghubung kiri tengah 1
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(-55,0,-5);
	glVertex3f(-55,40,-5);
	glVertex3f(-50,40,-5);
	glVertex3f(-50,0,-5);
	glEnd();
	//penghubung kiri tengah 2
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(-55,0,5);
	glVertex3f(-55,40,5);
	glVertex3f(-50,40,5);
	glVertex3f(-50,0,5);
	glEnd();
	//penghubung kanan tengah 1
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(55,0,-5);
	glVertex3f(55,40,-5);
	glVertex3f(50,40,-5);
	glVertex3f(50,0,-5);
	glEnd();
	//penghubung kanan tengah 2
	glBegin(GL_QUADS);
	glColor3ub(233, 236, 239);
	glVertex3f(55,0,5);
	glVertex3f(55,40,5);
	glVertex3f(50,40,5);
	glVertex3f(50,0,5);
	glEnd();
	
	//parkiran
	glBegin(GL_QUADS);
	glColor3ub(33, 37, 41);
	glVertex3f(-125, -0.2, -150);
	glVertex3f(-125,-0.2,150);
	glVertex3f(125,-0.2,150);
	glVertex3f(125,-0.2,-150);
	glEnd();
	//garis parkir kiri
	glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
	glVertex3f(-125, 0.2, -90);
	glVertex3f(-110,0.2,-90);
	
	glVertex3f(-125, 0.2, -80);
	glVertex3f(-110,0.2,-80);
	
	glVertex3f(-125, 0.2, -70);
	glVertex3f(-110,0.2,-70);
	
	glVertex3f(-125, 0.2, -60);
	glVertex3f(-110,0.2,-60);
	
	glVertex3f(-125, 0.2, -50);
	glVertex3f(-110,0.2,-50);
	
	glVertex3f(-125, 0.2, -40);
	glVertex3f(-110,0.2,-40);
	
	glVertex3f(-125, 0.2, -30);
	glVertex3f(-110,0.2,-30);
	
	glVertex3f(-125, 0.2, -20);
	glVertex3f(-110,0.2,-20);
	
	glVertex3f(-125, 0.2, -10);
	glVertex3f(-110,0.2,-10);
	
	glVertex3f(-125, 0.2, 0);
	glVertex3f(-110,0.2,0);
	
	glVertex3f(-125, 0.2, 10);
	glVertex3f(-110,0.2,10);
	
	glVertex3f(-125, 0.2, 20);
	glVertex3f(-110,0.2,20);
	
	glVertex3f(-125, 0.2, 30);
	glVertex3f(-110,0.2,30);
	
	glVertex3f(-125, 0.2, 40);
	glVertex3f(-110,0.2,40);
	
	glVertex3f(-125, 0.2, 50);
	glVertex3f(-110,0.2,50);
	
	glVertex3f(-125, 0.2, 60);
	glVertex3f(-110,0.2,60);
	
	glVertex3f(-125, 0.2, 70);
	glVertex3f(-110,0.2,70);
	
	glVertex3f(-125, 0.2, 80);
	glVertex3f(-110,0.2,80);
	
	glVertex3f(-125, 0.2, 90);
	glVertex3f(-110,0.2,90);
	
	//garis parkir kanan
	glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
	glVertex3f(125, 0.2, -90);
	glVertex3f(110,0.2,-90);
	
	glVertex3f(125, 0.2, -80);
	glVertex3f(110,0.2,-80);
	
	glVertex3f(125, 0.2, -70);
	glVertex3f(110,0.2,-70);
	
	glVertex3f(125, 0.2, -60);
	glVertex3f(110,0.2,-60);
	
	glVertex3f(125, 0.2, -50);
	glVertex3f(110,0.2,-50);
	
	glVertex3f(125, 0.2, -40);
	glVertex3f(110,0.2,-40);
	
	glVertex3f(125, 0.2, -30);
	glVertex3f(110,0.2,-30);
	
	glVertex3f(125, 0.2, -20);
	glVertex3f(110,0.2,-20);
	
	glVertex3f(125, 0.2, -10);
	glVertex3f(110,0.2,-10);
	
	glVertex3f(125, 0.2, 0);
	glVertex3f(110,0.2,0);
	
	glVertex3f(125, 0.2, 10);
	glVertex3f(110,0.2,10);
	
	glVertex3f(125, 0.2, 20);
	glVertex3f(110,0.2,20);
	
	glVertex3f(125, 0.2, 30);
	glVertex3f(110,0.2,30);
	
	glVertex3f(125, 0.2, 40);
	glVertex3f(110,0.2,40);
	
	glVertex3f(125, 0.2, 50);
	glVertex3f(110,0.2,50);
	
	glVertex3f(125, 0.2, 60);
	glVertex3f(110,0.2,60);
	
	glVertex3f(125, 0.2, 70);
	glVertex3f(110,0.2,70);
	
	glVertex3f(125, 0.2, 80);
	glVertex3f(110,0.2,80);
	
	glVertex3f(125, 0.2, 90);
	glVertex3f(110,0.2,90);
	
	glEnd();	
	
	
	//store
	//belakang
	glBegin(GL_QUADS);
	glColor3ub(255, 0, 0);
	glVertex3f(-120,0.2,-150);
	glVertex3f(-120,25,-150);
	glVertex3f(-50,25,-150);
	glVertex3f(-50,0.2,-150);
	glEnd();
	//kiri
	glBegin(GL_QUADS);
	glColor3ub(255, 0, 0);
	glVertex3f(-120,0.2,-150);
	glVertex3f(-120,25,-150);
	glVertex3f(-120,25,-110);
	glVertex3f(-120,0.2,-110);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(255, 0, 0);
	glVertex3f(-50,0.2,-150);
	glVertex3f(-50,25,-150);
	glVertex3f(-50,25,-110);
	glVertex3f(-50,0.2,-110);
	glEnd();
	//depan
	glBegin(GL_QUADS);
	glColor3ub(255, 0, 0);
	glVertex3f(-120,0.2,-110);
	glVertex3f(-120,25,-110);
	glVertex3f(-50,25,-110);
	glVertex3f(-50,0.2,-110);
	glEnd();
	//atas
	glBegin(GL_QUADS);
	glColor3ub(255, 0, 0);
	glVertex3f(-120,25,-150);
	glVertex3f(-50,25,-150);
	glVertex3f(-50,25,-110);
	glVertex3f(-120,25,-110);
	glEnd();
	//pintu
	glBegin(GL_QUADS);
	glColor3ub(183, 183, 164);
	glVertex3f(-98,0.2,-109.9);
	glVertex3f(-98,20,-109.9);
	glVertex3f(-92,20,-109.9);
	glVertex3f(-92,0.2,-109.9);
	glEnd();
	//jendlea
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-85,3,-109.9);
	glVertex3f(-85,20,-109.9);
	glColor3ub(128, 255, 219);
	glVertex3f(-55,20,-109.9);
	glVertex3f(-55,3,-109.9);
	glEnd();
	//detailstore
	//astas
	//baju
	//kotak1
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-95,25,-108);//85 + 10
	glVertex3f(-95,50,-125);
	glVertex3f(-75,50,-125);
	glVertex3f(-75,25,-108);
	glEnd();
	//KANAN
	glBegin(GL_QUADS);
	glColor3ub(160, 196, 255);
	glVertex3f(-75, 50, -125);
	glVertex3f(-70, 45, -120);
	glVertex3f(-72, 35, -115);
	glVertex3f(-75, 40, -118);
	glEnd();
	//KIRI
	glBegin(GL_QUADS);
	glColor3ub(160, 196, 255);
	glVertex3f(-95, 50, -125);
	glVertex3f(-100, 45, -120);
	glVertex3f(-98, 35, -115);
	glVertex3f(-95, 40, -118);
	glEnd();
	//segitiga
	glBegin(GL_TRIANGLES);
	glColor3ub(0, 0, 0);
	glVertex3f(-85, 47,-122.9);
	glVertex3f(-90,50,-124.9);
	glVertex3f(-80,50,-124.9);
	glEnd();
	//tiang sangga
	glBegin(GL_TRIANGLES);
	glColor3ub(0, 0, 0);
	glVertex3f(-85, 37,-116);
	glVertex3f(-90,25,-135);
	glVertex3f(-80,25,-135);
	glEnd();
	//2
	glBegin(GL_TRIANGLES);
	glColor3ub(0, 0, 0);
	glVertex3f(-85, 37,-116);
	glVertex3f(-90,25,-116);
	glVertex3f(-80,25,-116);
	glEnd();
	
	//lampu parkiran
	//depan kiri
	//kiri
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(-75, -0.1, 105);
	glVertex3f(-75, -0.1, 103);
	glVertex3f(-75, 60, 103);
	glVertex3f(-75, 60, 105);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(-73, -0.1, 105);
	glVertex3f(-73, -0.1, 103);
	glVertex3f(-73, 60, 103);
	glVertex3f(-73, 60, 105);
	glEnd();
	//belakang
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(-75, -0.1, 103);
	glVertex3f(-75, 60, 103);
	glVertex3f(-73, 60, 103);
	glVertex3f(-73, -0.1, 103);
	glEnd();
	//depan
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(-75, -0.1, 105);
	glVertex3f(-75, 60, 105);
	glVertex3f(-73, 60, 105);
	glVertex3f(-73, -0.1, 105);
	glEnd();
	//2
	//atas
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(-80, 63, 105);
	glVertex3f(-80, 63, 103);
	glVertex3f(-73, 63, 103);
	glVertex3f(-73, 63, 105);
	glEnd();
	//bawah
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(-80, 60, 105);
	glVertex3f(-80, 60, 103);
	glVertex3f(-73, 60, 103);
	glVertex3f(-73, 60, 105);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(-73, 60, 105);
	glVertex3f(-73, 63, 105);
	glVertex3f(-73, 63, 103);
	glVertex3f(-73, 60, 103);
	glEnd();
	//depan
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(-80, 60, 105);
	glVertex3f(-80, 63, 105);
	glVertex3f(-73, 63, 105);
	glVertex3f(-73, 60, 105);
	glEnd();
	//belakang
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(-80, 60, 103);
	glVertex3f(-80, 63, 103);
	glVertex3f(-73, 63, 103);
	glVertex3f(-73, 60, 103);
	glEnd();
	//3
	//astas
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(-90, 64, 107);
	glVertex3f(-90, 64, 101);
	glVertex3f(-80, 64, 101);
	glVertex3f(-80, 64, 107);
	glEnd();
	//bawah
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-90, 59, 107);
	glVertex3f(-90, 59, 101);
	glVertex3f(-80, 59, 101);
	glVertex3f(-80, 59, 107);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(-80, 64, 107);
	glVertex3f(-80, 64, 101);
	glVertex3f(-80, 59, 101);
	glVertex3f(-80, 59, 107);
	glEnd();
	//kiri
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(-90, 64, 107);
	glVertex3f(-90, 64, 101);
	glVertex3f(-90, 59, 101);
	glVertex3f(-90, 59, 107);
	glEnd();
	//belakang
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(-90, 64, 101);
	glVertex3f(-90, 59, 101);
	glVertex3f(-80, 59, 101);
	glVertex3f(-80, 64, 101);
	glEnd();
	//depan
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(-90, 64, 107);
	glVertex3f(-90, 59, 107);
	glVertex3f(-80, 59, 107);
	glVertex3f(-80, 64, 107);
	glEnd();
	
	
	
	//depan kanan
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(75, -0.1, 105);
	glVertex3f(75, -0.1, 103);
	glVertex3f(75, 60, 103);
	glVertex3f(75, 60, 105);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(73, -0.1, 105);
	glVertex3f(73, -0.1, 103);
	glVertex3f(73, 60, 103);
	glVertex3f(73, 60, 105);
	glEnd();
	//belakang
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(75, -0.1, 103);
	glVertex3f(75, 60, 103);
	glVertex3f(73, 60, 103);
	glVertex3f(73, -0.1, 103);
	glEnd();
	//depan
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(75, -0.1, 105);
	glVertex3f(75, 60, 105);
	glVertex3f(73, 60, 105);
	glVertex3f(73, -0.1, 105);
	glEnd();
	//2
	//atas
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(80, 63, 105);
	glVertex3f(80, 63, 103);
	glVertex3f(73, 63, 103);
	glVertex3f(73, 63, 105);
	glEnd();
	//bawah
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(80, 60, 105);
	glVertex3f(80, 60, 103);
	glVertex3f(73, 60, 103);
	glVertex3f(73, 60, 105);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(73, 60, 105);
	glVertex3f(73, 63, 105);
	glVertex3f(73, 63, 103);
	glVertex3f(73, 60, 103);
	glEnd();
	//depan
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(80, 60, 105);
	glVertex3f(80, 63, 105);
	glVertex3f(73, 63, 105);
	glVertex3f(73, 60, 105);
	glEnd();
	//belakang
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(80, 60, 103);
	glVertex3f(80, 63, 103);
	glVertex3f(73, 63, 103);
	glVertex3f(73, 60, 103);
	glEnd();
	//3
	//astas
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(90, 64, 107);
	glVertex3f(90, 64, 101);
	glVertex3f(80, 64, 101);
	glVertex3f(80, 64, 107);
	glEnd();
	//bawah
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(90, 59, 107);
	glVertex3f(90, 59, 101);
	glVertex3f(80, 59, 101);
	glVertex3f(80, 59, 107);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(80, 64, 107);
	glVertex3f(80, 64, 101);
	glVertex3f(80, 59, 101);
	glVertex3f(80, 59, 107);
	glEnd();
	//kiri
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(90, 64, 107);
	glVertex3f(90, 64, 101);
	glVertex3f(90, 59, 101);
	glVertex3f(90, 59, 107);
	glEnd();
	//belakang
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(90, 64, 101);
	glVertex3f(90, 59, 101);
	glVertex3f(80, 59, 101);
	glVertex3f(80, 64, 101);
	glEnd();
	//depan
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(90, 64, 107);
	glVertex3f(90, 59, 107);
	glVertex3f(80, 59, 107);
	glVertex3f(80, 64, 107);
	glEnd();
	
	//belakang kanan
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(75, -0.1, -105);
	glVertex3f(75, -0.1, -103);
	glVertex3f(75, 60, -103);
	glVertex3f(75, 60, -105);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(73, -0.1, -105);
	glVertex3f(73, -0.1, -103);
	glVertex3f(73, 60, -103);
	glVertex3f(73, 60, -105);
	glEnd();
	//belakang
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(75, -0.1, -103);
	glVertex3f(75, 60, -103);
	glVertex3f(73, 60, -103);
	glVertex3f(73, -0.1, -103);
	glEnd();
	//depan
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(75, -0.1, -105);
	glVertex3f(75, 60, -105);
	glVertex3f(73, 60, -105);
	glVertex3f(73, -0.1, -105);
	glEnd();
	//2
	//atas
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(80, 63, -105);
	glVertex3f(80, 63, -103);
	glVertex3f(73, 63, -103);
	glVertex3f(73, 63, -105);
	glEnd();
	//bawah
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(80, 60, -105);
	glVertex3f(80, 60, -103);
	glVertex3f(73, 60, -103);
	glVertex3f(73, 60, -105);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(73, 60, -105);
	glVertex3f(73, 63, -105);
	glVertex3f(73, 63, -103);
	glVertex3f(73, 60, -103);
	glEnd();
	//depan
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(80, 60, -105);
	glVertex3f(80, 63, -105);
	glVertex3f(73, 63, -105);
	glVertex3f(73, 60, -105);
	glEnd();
	//belakang
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(80, 60, -103);
	glVertex3f(80, 63, -103);
	glVertex3f(73, 63, -103);
	glVertex3f(73, 60, -103);
	glEnd();
	//3
	//astas
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(90, 64, -107);
	glVertex3f(90, 64, -101);
	glVertex3f(80, 64, -101);
	glVertex3f(80, 64, -107);
	glEnd();
	//bawah
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(90, 59, -107);
	glVertex3f(90, 59, -101);
	glVertex3f(80, 59, -101);
	glVertex3f(80, 59, -107);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(80, 64, -107);
	glVertex3f(80, 64, -101);
	glVertex3f(80, 59, -101);
	glVertex3f(80, 59, -107);
	glEnd();
	//kiri
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(90, 64, -107);
	glVertex3f(90, 64, -101);
	glVertex3f(90, 59, -101);
	glVertex3f(90, 59, -107);
	glEnd();
	//belakang
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(90, 64, -101);
	glVertex3f(90, 59, -101);
	glVertex3f(80, 59, -101);
	glVertex3f(80, 64, -101);
	glEnd();
	//depan
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(90, 64, -107);
	glVertex3f(90, 59, -107);
	glVertex3f(80, 59, -107);
	glVertex3f(80, 64, -107);
	glEnd();
	
	//belakang kiri
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(-75, -0.1, -105);
	glVertex3f(-75, -0.1, -103);
	glVertex3f(-75, 60, -103);
	glVertex3f(-75, 60, -105);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(-73, -0.1, -105);
	glVertex3f(-73, -0.1, -103);
	glVertex3f(-73, 60, -103);
	glVertex3f(-73, 60, -105);
	glEnd();
	//belakang
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(-75, -0.1, -103);
	glVertex3f(-75, 60, -103);
	glVertex3f(-73, 60, -103);
	glVertex3f(-73, -0.1, -103);
	glEnd();
	//depan
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(-75, -0.1, -105);
	glVertex3f(-75, 60, -105);
	glVertex3f(-73, 60, -105);
	glVertex3f(-73, -0.1, -105);
	glEnd();
	//2
	//atas
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(-80, 63, -105);
	glVertex3f(-80, 63, -103);
	glVertex3f(-73, 63, -103);
	glVertex3f(-73, 63, -105);
	glEnd();
	//bawah
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(-80, 60, -105);
	glVertex3f(-80, 60, -103);
	glVertex3f(-73, 60, -103);
	glVertex3f(-73, 60, -105);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(-73, 60, -105);
	glVertex3f(-73, 63, -105);
	glVertex3f(-73, 63, -103);
	glVertex3f(-73, 60, -103);
	glEnd();
	//depan
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(-80, 60, -105);
	glVertex3f(-80, 63, -105);
	glVertex3f(-73, 63, -105);
	glVertex3f(-73, 60, -105);
	glEnd();
	//belakang
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(-80, 60, -103);
	glVertex3f(-80, 63, -103);
	glVertex3f(-73, 63, -103);
	glVertex3f(-73, 60, -103);
	glEnd();
	//3
	//astas
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(-90, 64, -107);
	glVertex3f(-90, 64, -101);
	glVertex3f(-80, 64, -101);
	glVertex3f(-80, 64, -107);
	glEnd();
	//bawah
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-90, 59, -107);
	glVertex3f(-90, 59, -101);
	glVertex3f(-80, 59, -101);
	glVertex3f(-80, 59, -107);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(-80, 64, -107);
	glVertex3f(-80, 64, -101);
	glVertex3f(-80, 59, -101);
	glVertex3f(-80, 59, -107);
	glEnd();
	//kiri
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(-90, 64, -107);
	glVertex3f(-90, 64, -101);
	glVertex3f(-90, 59, -101);
	glVertex3f(-90, 59, -107);
	glEnd();
	//belakang
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(-90, 64, -101);
	glVertex3f(-90, 59, -101);
	glVertex3f(-80, 59, -101);
	glVertex3f(-80, 64, -101);
	glEnd();
	//depan
	glBegin(GL_QUADS);
	glColor3ub(216, 226, 220);
	glVertex3f(-90, 64, -107);
	glVertex3f(-90, 59, -107);
	glVertex3f(-80, 59, -107);
	glVertex3f(-80, 64, -107);
	glEnd();
	
	//tiang lampu stadion kiri
	//1
	//tiang vertikal 1
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,53,5);
	glVertex3f(-37,57,5);
	glVertex3f(-37,57,4.5);
	glVertex3f(-37,53,4.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37.5,53,5);
	glVertex3f(-37.5,57,5);
	glVertex3f(-37.5,57,4.5);
	glVertex3f(-37.5,53,4.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,53,5);
	glVertex3f(-37,57,5);
	glVertex3f(-37.5,57,5);
	glVertex3f(-37.5,53,5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,53,4.5);
	glVertex3f(-37,57,4.5);
	glVertex3f(-37.5,57,4.5);
	glVertex3f(-37.5,53,4.5);
	glEnd();
	//tiang vertikal 2
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,53,15);
	glVertex3f(-37,57,15);
	glVertex3f(-37,57,14.5);
	glVertex3f(-37,53,14.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37.5,53,15);
	glVertex3f(-37.5,57,15);
	glVertex3f(-37.5,57,14.5);
	glVertex3f(-37.5,53,14.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,53,15);
	glVertex3f(-37,57,15);
	glVertex3f(-37.5,57,15);
	glVertex3f(-37.5,53,15);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,53,14.5);
	glVertex3f(-37,57,14.5);
	glVertex3f(-37.5,57,14.5);
	glVertex3f(-37.5,53,14.5);
	glEnd();
	//tiang horizontal
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,57,5);
	glVertex3f(-37,57,15);
	glVertex3f(-37.5,57,15);
	glVertex3f(-37.5,57,5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,56.5,5);
	glVertex3f(-37,56.5,15);
	glVertex3f(-37.5,56.5,15);
	glVertex3f(-37.5,56.5,5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,56.5,5);
	glVertex3f(-37,56.5,15);
	glVertex3f(-37,57,15);
	glVertex3f(-37,57,5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37.5,56.5,5);
	glVertex3f(-37.5,56.5,15);
	glVertex3f(-37.5,57,15);
	glVertex3f(-37.5,57,5);
	glEnd();
	
	//2
	//tiang vertikal 1
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,53,30);
	glVertex3f(-37,57,30);
	glVertex3f(-37,57,29.5);
	glVertex3f(-37,53,29.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37.5,53,30);
	glVertex3f(-37.5,57,30);
	glVertex3f(-37.5,57,29.5);
	glVertex3f(-37.5,53,29.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,53,30);
	glVertex3f(-37,57,30);
	glVertex3f(-37.5,57,30);
	glVertex3f(-37.5,53,30);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,53,29.5);
	glVertex3f(-37,57,29.5);
	glVertex3f(-37.5,57,29.5);
	glVertex3f(-37.5,53,29.5);
	glEnd();
	//tiang vertikal 2
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,53,40);
	glVertex3f(-37,57,40);
	glVertex3f(-37,57,39.5);
	glVertex3f(-37,53,39.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37.5,53,40);
	glVertex3f(-37.5,57,40);
	glVertex3f(-37.5,57,39.5);
	glVertex3f(-37.5,53,39.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,53,40);
	glVertex3f(-37,57,40);
	glVertex3f(-37.5,57,40);
	glVertex3f(-37.5,53,40);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,53,39.5);
	glVertex3f(-37,57,39.5);
	glVertex3f(-37.5,57,39.5);
	glVertex3f(-37.5,53,39.5);
	glEnd();
	//tiang horizontal
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,57,30);
	glVertex3f(-37,57,40);
	glVertex3f(-37.5,57,40);
	glVertex3f(-37.5,57,30);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,56.5,30);
	glVertex3f(-37,56.5,40);
	glVertex3f(-37.5,56.5,40);
	glVertex3f(-37.5,56.5,30);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,56.5,30);
	glVertex3f(-37,56.5,40);
	glVertex3f(-37,57,40);
	glVertex3f(-37,57,30);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37.5,56.5,30);
	glVertex3f(-37.5,56.5,40);
	glVertex3f(-37.5,57,40);
	glVertex3f(-37.5,57,30);
	glEnd();
	
	//3
	//tiang vertikal 1
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,53,-5);
	glVertex3f(-37,57,-5);
	glVertex3f(-37,57,-4.5);
	glVertex3f(-37,53,-4.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37.5,53,-5);
	glVertex3f(-37.5,57,-5);
	glVertex3f(-37.5,57,-4.5);
	glVertex3f(-37.5,53,-4.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,53,-5);
	glVertex3f(-37,57,-5);
	glVertex3f(-37.5,57,-5);
	glVertex3f(-37.5,53,-5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,53,-4.5);
	glVertex3f(-37,57,-4.5);
	glVertex3f(-37.5,57,-4.5);
	glVertex3f(-37.5,53,-4.5);
	glEnd();
	//tiang vertikal 2
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,53,-15);
	glVertex3f(-37,57,-15);
	glVertex3f(-37,57,-14.5);
	glVertex3f(-37,53,-14.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37.5,53,-15);
	glVertex3f(-37.5,57,-15);
	glVertex3f(-37.5,57,-14.5);
	glVertex3f(-37.5,53,-14.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,53,-15);
	glVertex3f(-37,57,-15);
	glVertex3f(-37.5,57,-15);
	glVertex3f(-37.5,53,-15);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,53,-14.5);
	glVertex3f(-37,57,-14.5);
	glVertex3f(-37.5,57,-14.5);
	glVertex3f(-37.5,53,-14.5);
	glEnd();
	//tiang horizontal
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,57,-5);
	glVertex3f(-37,57,-15);
	glVertex3f(-37.5,57,-15);
	glVertex3f(-37.5,57,-5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,56.5,-5);
	glVertex3f(-37,56.5,-15);
	glVertex3f(-37.5,56.5,-15);
	glVertex3f(-37.5,56.5,-5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,56.5,-5);
	glVertex3f(-37,56.5,-15);
	glVertex3f(-37,57,-15);
	glVertex3f(-37,57,-5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37.5,56.5,-5);
	glVertex3f(-37.5,56.5,-15);
	glVertex3f(-37.5,57,-15);
	glVertex3f(-37.5,57,-5);
	glEnd();
	
	//4
	//tiang vertikal 1
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,53,-30);
	glVertex3f(-37,57,-30);
	glVertex3f(-37,57,-29.5);
	glVertex3f(-37,53,-29.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37.5,53,-30);
	glVertex3f(-37.5,57,-30);
	glVertex3f(-37.5,57,-29.5);
	glVertex3f(-37.5,53,-29.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,53,-30);
	glVertex3f(-37,57,-30);
	glVertex3f(-37.5,57,-30);
	glVertex3f(-37.5,53,-30);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,53,-29.5);
	glVertex3f(-37,57,-29.5);
	glVertex3f(-37.5,57,-29.5);
	glVertex3f(-37.5,53,-29.5);
	glEnd();
	//tiang vertikal 2
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,53,-40);
	glVertex3f(-37,57,-40);
	glVertex3f(-37,57,-39.5);
	glVertex3f(-37,53,-39.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37.5,53,-40);
	glVertex3f(-37.5,57,-40);
	glVertex3f(-37.5,57,-39.5);
	glVertex3f(-37.5,53,-39.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,53,-40);
	glVertex3f(-37,57,-40);
	glVertex3f(-37.5,57,-40);
	glVertex3f(-37.5,53,-40);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,53,-39.5);
	glVertex3f(-37,57,-39.5);
	glVertex3f(-37.5,57,-39.5);
	glVertex3f(-37.5,53,-39.5);
	glEnd();
	//tiang horizontal
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,57,-30);
	glVertex3f(-37,57,-40);
	glVertex3f(-37.5,57,-40);
	glVertex3f(-37.5,57,-30);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,56.5,-30);
	glVertex3f(-37,56.5,-40);
	glVertex3f(-37.5,56.5,-40);
	glVertex3f(-37.5,56.5,-30);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37,56.5,-30);
	glVertex3f(-37,56.5,-40);
	glVertex3f(-37,57,-40);
	glVertex3f(-37,57,-30);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(-37.5,56.5,-30);
	glVertex3f(-37.5,56.5,-40);
	glVertex3f(-37.5,57,-40);
	glVertex3f(-37.5,57,-30);
	glEnd();
	
	//tiang lampu stadion kanan
	//1
	//tiang vertikal 1
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,53,5);
	glVertex3f(37,57,5);
	glVertex3f(37,57,4.5);
	glVertex3f(37,53,4.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37.5,53,5);
	glVertex3f(37.5,57,5);
	glVertex3f(37.5,57,4.5);
	glVertex3f(37.5,53,4.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,53,5);
	glVertex3f(37,57,5);
	glVertex3f(37.5,57,5);
	glVertex3f(37.5,53,5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,53,4.5);
	glVertex3f(37,57,4.5);
	glVertex3f(37.5,57,4.5);
	glVertex3f(37.5,53,4.5);
	glEnd();
	//tiang vertikal 2
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,53,15);
	glVertex3f(37,57,15);
	glVertex3f(37,57,14.5);
	glVertex3f(37,53,14.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37.5,53,15);
	glVertex3f(37.5,57,15);
	glVertex3f(37.5,57,14.5);
	glVertex3f(37.5,53,14.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,53,15);
	glVertex3f(37,57,15);
	glVertex3f(37.5,57,15);
	glVertex3f(37.5,53,15);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,53,14.5);
	glVertex3f(37,57,14.5);
	glVertex3f(37.5,57,14.5);
	glVertex3f(37.5,53,14.5);
	glEnd();
	//tiang horizontal
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,57,5);
	glVertex3f(37,57,15);
	glVertex3f(37.5,57,15);
	glVertex3f(37.5,57,5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,56.5,5);
	glVertex3f(37,56.5,15);
	glVertex3f(37.5,56.5,15);
	glVertex3f(37.5,56.5,5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,56.5,5);
	glVertex3f(37,56.5,15);
	glVertex3f(37,57,15);
	glVertex3f(37,57,5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37.5,56.5,5);
	glVertex3f(37.5,56.5,15);
	glVertex3f(37.5,57,15);
	glVertex3f(37.5,57,5);
	glEnd();
	
	//2
	//tiang vertikal 1
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,53,30);
	glVertex3f(37,57,30);
	glVertex3f(37,57,29.5);
	glVertex3f(37,53,29.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37.5,53,30);
	glVertex3f(37.5,57,30);
	glVertex3f(37.5,57,29.5);
	glVertex3f(37.5,53,29.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,53,30);
	glVertex3f(37,57,30);
	glVertex3f(37.5,57,30);
	glVertex3f(37.5,53,30);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,53,29.5);
	glVertex3f(37,57,29.5);
	glVertex3f(37.5,57,29.5);
	glVertex3f(37.5,53,29.5);
	glEnd();
	//tiang vertikal 2
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,53,40);
	glVertex3f(37,57,40);
	glVertex3f(37,57,39.5);
	glVertex3f(37,53,39.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37.5,53,40);
	glVertex3f(37.5,57,40);
	glVertex3f(37.5,57,39.5);
	glVertex3f(37.5,53,39.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,53,40);
	glVertex3f(37,57,40);
	glVertex3f(37.5,57,40);
	glVertex3f(37.5,53,40);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,53,39.5);
	glVertex3f(37,57,39.5);
	glVertex3f(37.5,57,39.5);
	glVertex3f(37.5,53,39.5);
	glEnd();
	//tiang horizontal
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,57,30);
	glVertex3f(37,57,40);
	glVertex3f(37.5,57,40);
	glVertex3f(37.5,57,30);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,56.5,30);
	glVertex3f(37,56.5,40);
	glVertex3f(37.5,56.5,40);
	glVertex3f(37.5,56.5,30);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,56.5,30);
	glVertex3f(37,56.5,40);
	glVertex3f(37,57,40);
	glVertex3f(37,57,30);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37.5,56.5,30);
	glVertex3f(37.5,56.5,40);
	glVertex3f(37.5,57,40);
	glVertex3f(37.5,57,30);
	glEnd();
	
	//3
	//tiang vertikal 1
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,53,-5);
	glVertex3f(37,57,-5);
	glVertex3f(37,57,-4.5);
	glVertex3f(37,53,-4.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37.5,53,-5);
	glVertex3f(37.5,57,-5);
	glVertex3f(37.5,57,-4.5);
	glVertex3f(37.5,53,-4.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,53,-5);
	glVertex3f(37,57,-5);
	glVertex3f(37.5,57,-5);
	glVertex3f(37.5,53,-5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,53,-4.5);
	glVertex3f(37,57,-4.5);
	glVertex3f(37.5,57,-4.5);
	glVertex3f(37.5,53,-4.5);
	glEnd();
	//tiang vertikal 2
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,53,-15);
	glVertex3f(37,57,-15);
	glVertex3f(37,57,-14.5);
	glVertex3f(37,53,-14.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37.5,53,-15);
	glVertex3f(37.5,57,-15);
	glVertex3f(37.5,57,-14.5);
	glVertex3f(37.5,53,-14.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,53,-15);
	glVertex3f(37,57,-15);
	glVertex3f(37.5,57,-15);
	glVertex3f(37.5,53,-15);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,53,-14.5);
	glVertex3f(37,57,-14.5);
	glVertex3f(37.5,57,-14.5);
	glVertex3f(37.5,53,-14.5);
	glEnd();
	//tiang horizontal
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,57,-5);
	glVertex3f(37,57,-15);
	glVertex3f(37.5,57,-15);
	glVertex3f(37.5,57,-5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,56.5,-5);
	glVertex3f(37,56.5,-15);
	glVertex3f(37.5,56.5,-15);
	glVertex3f(37.5,56.5,-5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,56.5,-5);
	glVertex3f(37,56.5,-15);
	glVertex3f(37,57,-15);
	glVertex3f(37,57,-5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37.5,56.5,-5);
	glVertex3f(37.5,56.5,-15);
	glVertex3f(37.5,57,-15);
	glVertex3f(37.5,57,-5);
	glEnd();
	
	//4
	//tiang vertikal 1
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,53,-30);
	glVertex3f(37,57,-30);
	glVertex3f(37,57,-29.5);
	glVertex3f(37,53,-29.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37.5,53,-30);
	glVertex3f(37.5,57,-30);
	glVertex3f(37.5,57,-29.5);
	glVertex3f(37.5,53,-29.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,53,-30);
	glVertex3f(37,57,-30);
	glVertex3f(37.5,57,-30);
	glVertex3f(37.5,53,-30);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,53,-29.5);
	glVertex3f(37,57,-29.5);
	glVertex3f(37.5,57,-29.5);
	glVertex3f(37.5,53,-29.5);
	glEnd();
	//tiang vertikal 2
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,53,-40);
	glVertex3f(37,57,-40);
	glVertex3f(37,57,-39.5);
	glVertex3f(37,53,-39.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37.5,53,-40);
	glVertex3f(37.5,57,-40);
	glVertex3f(37.5,57,-39.5);
	glVertex3f(37.5,53,-39.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,53,-40);
	glVertex3f(37,57,-40);
	glVertex3f(37.5,57,-40);
	glVertex3f(37.5,53,-40);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,53,-39.5);
	glVertex3f(37,57,-39.5);
	glVertex3f(37.5,57,-39.5);
	glVertex3f(37.5,53,-39.5);
	glEnd();
	//tiang horizontal
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,57,-30);
	glVertex3f(37,57,-40);
	glVertex3f(37.5,57,-40);
	glVertex3f(37.5,57,-30);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,56.5,-30);
	glVertex3f(37,56.5,-40);
	glVertex3f(37.5,56.5,-40);
	glVertex3f(37.5,56.5,-30);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37,56.5,-30);
	glVertex3f(37,56.5,-40);
	glVertex3f(37,57,-40);
	glVertex3f(37,57,-30);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(222, 226, 230);
	glVertex3f(37.5,56.5,-30);
	glVertex3f(37.5,56.5,-40);
	glVertex3f(37.5,57,-40);
	glVertex3f(37.5,57,-30);
	glEnd();
	
	//lampu atas kanan
	//lampu 1
	//1
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (36.5,57.5,6); 
	glRotatef (270.0, 1.0, -45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//2
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (36.5,57.5,8); 
	glRotatef (270.0, 1.0, -45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//3
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (36.5,57.5,10); 
	glRotatef (270.0, 1.0, -45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//4
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (36.5,57.5,12); 
	glRotatef (270.0, 1.0, -45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//5
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (36.5,57.5,14); 
	glRotatef (270.0, 1.0, -45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	
	//lampu 2
	//1
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (36.5,57.5,31); 
	glRotatef (270.0, 1.0, -45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//2
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (36.5,57.5,33); 
	glRotatef (270.0, 1.0, -45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//3
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (36.5,57.5,35); 
	glRotatef (270.0, 1.0, -45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//4
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (36.5,57.5,37); 
	glRotatef (270.0, 1.0, -45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//5
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (36.5,57.5,39); 
	glRotatef (270.0, 1.0, -45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	
	//lampu 3
	//1
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (36.5,57.5,-6); 
	glRotatef (270.0, 1.0, -45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//2
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (36.5,57.5,-8); 
	glRotatef (270.0, 1.0, -45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//3
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (36.5,57.5,-10); 
	glRotatef (270.0, 1.0, -45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//4
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (36.5,57.5,-12); 
	glRotatef (270.0, 1.0, -45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//5
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (36.5,57.5,-14); 
	glRotatef (270.0, 1.0, -45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	
	//lampu 4
	//1
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (36.5,57.5,-31); 
	glRotatef (270.0, 1.0, -45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//2
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (36.5,57.5,-33); 
	glRotatef (270.0, 1.0, -45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//3
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (36.5,57.5,-35); 
	glRotatef (270.0, 1.0, -45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//4
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (36.5,57.5,-37); 
	glRotatef (270.0, 1.0, -45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//5
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (36.5,57.5,-39); 
	glRotatef (270.0, 1.0, -45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	
	//lampu atas kiri
	//lampu 1
	//1
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (-36.5,57.5,6); 
	glRotatef (270.0, 1.0, 45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//2
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (-36.5,57.5,8); 
	glRotatef (270.0, 1.0, 45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//3
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (-36.5,57.5,10); 
	glRotatef (270.0, 1.0, 45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//4
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (-36.5,57.5,12); 
	glRotatef (270.0, 1.0, 45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//5
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (-36.5,57.5,14); 
	glRotatef (270.0, 1.0, 45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	
	//lampu 2
	//1
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (-36.5,57.5,31); 
	glRotatef (270.0, 1.0, 45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//2
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (-36.5,57.5,33); 
	glRotatef (270.0, 1.0, 45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//3
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (-36.5,57.5,35); 
	glRotatef (270.0, 1.0, 45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//4
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (-36.5,57.5,37); 
	glRotatef (270.0, 1.0, 45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//5
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (-36.5,57.5,39); 
	glRotatef (270.0, 1.0, 45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	
	//lampu 3
	//1
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (-36.5,57.5,-6); 
	glRotatef (270.0, 1.0, 45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//2
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (-36.5,57.5,-8); 
	glRotatef (270.0, 1.0, 45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//3
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (-36.5,57.5,-10); 
	glRotatef (270.0, 1.0, 45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//4
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (-36.5,57.5,-12); 
	glRotatef (270.0, 1.0, 45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//5
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (-36.5,57.5,-14); 
	glRotatef (270.0, 1.0, 45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	
	//lampu 4
	//1
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (-36.5,57.5,-31); 
	glRotatef (270.0, 1.0, 45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//2
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (-36.5,57.5,-33); 
	glRotatef (270.0, 1.0, 45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//3
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (-36.5,57.5,-35); 
	glRotatef (270.0, 1.0, 45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//4
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (-36.5,57.5,-37); 
	glRotatef (270.0, 1.0, 45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	//5
	glPushMatrix ();
	glColor3ub(100,100,100);
	glTranslatef (-36.5,57.5,-39); 
	glRotatef (270.0, 1.0, 45.0, 0.0);
	glutSolidCone (0.8, 2.0, 15, 15);
	glPopMatrix ();
	
	//bola
	//1 tengah
	glPushMatrix ();
	glColor3ub(255,255,255);
	glTranslatef (0,0.7,0); 
	glRotatef (0.0, 0.0, 0.0, 0.0);
	glutSolidSphere (0.6, 50, 50);
	glPopMatrix ();
	
	//2 pojok kanan depan
	glPushMatrix ();
	glColor3ub(255,255,255);
	glTranslatef (32,0.7,63); 
	glRotatef (0.0, 0.0, 0.0, 0.0);
	glutSolidSphere (0.6, 50, 50);
	glPopMatrix ();
	
	//3 pojok kiri depan
	glPushMatrix ();
	glColor3ub(255,255,255);
	glTranslatef (-32,0.7,63); 
	glRotatef (0.0, 0.0, 0.0, 0.0);
	glutSolidSphere (0.6, 50, 50);
	glPopMatrix ();
	
	//4 pojok kanan belakang
	glPushMatrix ();
	glColor3ub(255,255,255);
	glTranslatef (32,0.7,-63); 
	glRotatef (0.0, 0.0, 0.0, 0.0);
	glutSolidSphere (0.6, 50, 50);
	glPopMatrix ();
	
	//5 pojok kiri belakang
	glPushMatrix ();
	glColor3ub(255,255,255);
	glTranslatef (-32,0.7,-63); 
	glRotatef (0.0, 0.0, 0.0, 0.0);
	glutSolidSphere (0.6, 50, 50);
	glPopMatrix ();
	
	//patung bola
	//kotak
	//depan
	glBegin(GL_QUADS);
	glColor3ub(150,150,150);
	glVertex3f(-5,0,105);
	glVertex3f(-5,5,105);
	glVertex3f(5,5,105);
	glVertex3f(5,0,105);
	glEnd();
	//belakakng
	glBegin(GL_QUADS);
	glColor3ub(150,150,150);
	glVertex3f(-5,0,100);
	glVertex3f(-5,5,100);
	glVertex3f(5,5,100);
	glVertex3f(5,0,100);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(150,150,150);
	glVertex3f(5,0,105);
	glVertex3f(5,5,105);
	glVertex3f(5,5,100);
	glVertex3f(5,0,100);
	glEnd();
	//kiri
	glBegin(GL_QUADS);
	glColor3ub(150,150,150);
	glVertex3f(-5,0,105);
	glVertex3f(-5,5,105);
	glVertex3f(-5,5,100);
	glVertex3f(-5,0,100);
	glEnd();
	//atas
	glBegin(GL_QUADS);
	glColor3ub(150,150,150);
	glVertex3f(-5,5,105);
	glVertex3f(5,5,105);
	glVertex3f(5,5,100);
	glVertex3f(-5,5,100);
	glEnd();
	//kerucut
	glPushMatrix ();
	glColor3ub(150,150,150);
	glTranslatef (0,5,102.5); 
	glRotatef (270, 1.0, 0.0, 0.0);
	glutSolidCone (1.8, 5.0, 15, 15);
	glPopMatrix ();
	//bola
	glPushMatrix ();
	glColor3ub(150,150,150);
	glTranslatef (0,9,102.5); 
	glRotatef (270, 1.0, 0.0, 0.0);
	glutSolidSphere (3, 50, 50);
	glPopMatrix ();
	
	//bendera kanan
	//tiang
	//depan
	glBegin(GL_QUADS);
	glColor3ub(150,150,150);
	glVertex3f(8,0,105);
	glVertex3f(8,25,105);
	glVertex3f(8.5,25,105);
	glVertex3f(8.5,0,105);
	glEnd();
	//belakang
	glBegin(GL_QUADS);
	glColor3ub(150,150,150);
	glVertex3f(8,0,104.5);
	glVertex3f(8,25,104.5);
	glVertex3f(8.5,25,104.5);
	glVertex3f(8.5,0,104.5);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(150,150,150);
	glVertex3f(8.5,0,105);
	glVertex3f(8.5,25,105);
	glVertex3f(8.5,25,104.5);
	glVertex3f(8.5,0,104.5);
	glEnd();
	//kiri
	glBegin(GL_QUADS);
	glColor3ub(150,150,150);
	glVertex3f(8,0,105);
	glVertex3f(8,25,105);
	glVertex3f(8,25,104.5);
	glVertex3f(8,0,104.5);
	glEnd();
	//atas
	glBegin(GL_QUADS);
	glColor3ub(150,150,150);
	glVertex3f(8,25,105);
	glVertex3f(8.5,25,105);
	glVertex3f(8.5,25,104.5);
	glVertex3f(8,25,104.5);
	glEnd();
	
	//bendera
	//biru
	glBegin(GL_QUADS);
	glColor3ub(0,0,255);
	glVertex3f(10.5,18,104.7);
	glVertex3f(10.5,25,104.7);
	glVertex3f(8.5,25,104.7);
	glVertex3f(8.5,18,104.7);
	glEnd();
	//putih
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(10.5,18,104.7);
	glVertex3f(10.5,25,104.7);
	glVertex3f(12.5,25,104.7);
	glVertex3f(12.5,18,104.7);
	glEnd();
	//merah
	glBegin(GL_QUADS);
	glColor3ub(255,0,0);
	glVertex3f(14.5,18,104.7);
	glVertex3f(14.5,25,104.7);
	glVertex3f(12.5,25,104.7);
	glVertex3f(12.5,18,104.7);
	glEnd();
	
	//bendera kiri
	//tiang
	//depan
	glBegin(GL_QUADS);
	glColor3ub(150,150,150);
	glVertex3f(-8,0,105);
	glVertex3f(-8,25,105);
	glVertex3f(-8.5,25,105);
	glVertex3f(-8.5,0,105);
	glEnd();
	//belakang
	glBegin(GL_QUADS);
	glColor3ub(150,150,150);
	glVertex3f(-8,0,104.5);
	glVertex3f(-8,25,104.5);
	glVertex3f(-8.5,25,104.5);
	glVertex3f(-8.5,0,104.5);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(150,150,150);
	glVertex3f(-8.5,0,105);
	glVertex3f(-8.5,25,105);
	glVertex3f(-8.5,25,104.5);
	glVertex3f(-8.5,0,104.5);
	glEnd();
	//kiri
	glBegin(GL_QUADS);
	glColor3ub(150,150,150);
	glVertex3f(-8,0,105);
	glVertex3f(-8,25,105);
	glVertex3f(-8,25,104.5);
	glVertex3f(-8,0,104.5);
	glEnd();
	//atas
	glBegin(GL_QUADS);
	glColor3ub(150,150,150);
	glVertex3f(-8,25,105);
	glVertex3f(-8.5,25,105);
	glVertex3f(-8.5,25,104.5);
	glVertex3f(-8,25,104.5);
	glEnd();
	
	//bendera
	//biru
	glBegin(GL_QUADS);
	glColor3ub(0,0,255);
	glVertex3f(-10.5,18,104.7);
	glVertex3f(-10.5,25,104.7);
	glVertex3f(-8.5,25,104.7);
	glVertex3f(-8.5,18,104.7);
	glEnd();
	//putih
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(-10.5,18,104.7);
	glVertex3f(-10.5,25,104.7);
	glVertex3f(-12.5,25,104.7);
	glVertex3f(-12.5,18,104.7);
	glEnd();
	//merah
	glBegin(GL_QUADS);
	glColor3ub(255,0,0);
	glVertex3f(-14.5,18,104.7);
	glVertex3f(-14.5,25,104.7);
	glVertex3f(-12.5,25,104.7);
	glVertex3f(-12.5,18,104.7);
	glEnd();
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	glPopMatrix();
	glutSwapBuffers();
}

void keyboard (unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'w':
		case 'W':
			glTranslatef(0,0,3);
			break;
		case 's':
		case 'S':
			glTranslatef(0,0,-3);
			break;
		case 'd':
		case 'D':
			glTranslatef(3,0,0);
			break;		
		case 'a':
		case 'A':
			glTranslatef(-3,0,0);
			break;	
		case '7':
			glTranslatef(0,3,0);
			break;
		case '9':
			glTranslatef(0,-3,0);
			break;
		case '2':
			glRotatef(2,1,0,0);
			break;
		case '8':
			glRotatef(-2,1,0,0);
			break;
		case '6':
			glRotatef(2,0,1,0);
			break;	
		case '4':
			glRotatef(-2,0,1,0);
			break;
		case '1':
			glRotatef(2,0,0,1);
			break;	
		case '3':
			glRotatef(-2,0,0,1);
			break;
		case '5':
			if(is_depth)
			{
				is_depth = 0;
				glDisable(GL_DEPTH_TEST);
			}
			else
			{
				is_depth = 1;
				glEnable(GL_DEPTH_TEST);
			}
	}
	tampil();
}

void idle(){
	if (!mouseDown){
		xrot += 0.3;
		yrot += 0.4;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
	mouseDown = false;
}

void mouseMotion(int x, int y){
	if(mouseDown){
		yrot = x - xdiff;
		xrot = y + ydiff;
		
		glutPostRedisplay();
	}
}

void ukuran(int lebar, int tinggi){
	if (tinggi ==0) tinggi =1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90,lebar/tinggi, 5, 1000);
	glTranslatef(0,-85,-200);
	glMatrixMode(GL_MODELVIEW);
}
