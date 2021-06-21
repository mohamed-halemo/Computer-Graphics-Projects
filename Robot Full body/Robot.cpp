#include <GL/glut.h>
#include <stdlib.h>




int moving, startx, starty;
GLfloat angle = 0.0;   
GLfloat angle2 = 0.0;   
static int fingerBase = 0, fingerUp = 0, fingerBase2 = 0, fingerUp2 = 0;
static int allbodyY = 0, allbodyZ = 0;
static int SHOULDERRIGHT = 0, SHOULDERRIGHT2 = 0, SHOULDERRIGHTZROT = 0;
static int SHOULDERLEFT = 0, SHOULDERLEFT2 = 0, SHOULDERLEFTZROT = 0;
static int LEFTLEGUP = 0, LEFTLEG2 = 0, LEFTLEGSIDE = 0;
static int RIGHTLEGUPALL = 0, RIGHTLEG2 = 0, RIGHTLEGSIDE = 0;



void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}



void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix(); // to make all get contained in the body
    glRotatef(angle2, 1.0, 0.0, 0.0);// angels of moving the whole figuer X with mouse
    glRotatef(angle, 0.0, 1.0, 0.0); //angels of moving the whole figuer Y with mouse
    glScalef(1.0, 1.2, 1.0); //scale of whole body we work on

    glTranslatef(0.0, 0.0, allbodyZ);/// MOVE THE BODY FRONT OR BACK (Z)

      //////////////////////////////////////////////////////////////////Head
    glPushMatrix();
    glTranslatef(0.0, 1.0, 0.0);  //translating it to Y up
    glutWireSphere(0.25, 9, 9);  // head is simply a sphere
    glPopMatrix();
    //////////////////////////////////////////////////////////////////Body
    glPushMatrix();
    glScalef(0.5, 0.9, 0.3);  //scale of figuer according to first scale
    glutWireCube(1.5); //cube size
    glPopMatrix();
  
   /////////////////////////////////////////////////////////////////Left Arm
    glPushMatrix();
    glTranslatef(-0.6, 0.55, 0.0); // arm coordinates 1
    glRotatef((GLfloat)SHOULDERLEFT, 0.0, 0.0, 1.0); // rotate in Z
    glTranslatef(0.0, -0.41, 0.0);  // arm coordinates to manage it after rotation
    glRotatef((GLfloat)SHOULDERLEFTZROT, 0.0, 1.0, 0.0); //rotation in y
    glTranslatef(0.63, -0.22, 0.0);
    glPushMatrix();
    glTranslatef(-0.55, 0.43, 0.0);
    glScalef(0.2, 0.5, 0.3);// el dra3 ba2eto el 7etta el tanya
    glutWireCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.0, 0.15, 0.0);
    glRotatef((GLfloat)SHOULDERLEFT2, 1.0, 0.0, 0.0);//x rotation
    glTranslatef(-1.55, -0.22, 0.0);
    glScalef(0.2, 0.5, 0.3);// el dra3 b2eto el 7eta el 2ola ely 3nd el swabe3
    glutWireCube(1.0);
    glRotatef(-90, 0.0, 0.0, 1.0);//to make it point down

    glPushMatrix();
    //Draw finger flang 1
    glTranslatef(0.55, 0.15, 0.25);
    glRotatef((GLfloat)fingerBase2, 0.0, 0.0, 1.0);
    glTranslatef(0.05, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    //Draw finger flang 1
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)fingerUp2, 0.0, 0.0, 1.0);
    glTranslatef(0.05, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix();


    glPushMatrix();
    //Draw finger flang 2
    glTranslatef(0.55, -0.15, -0.35);
    glRotatef((GLfloat)-fingerBase2, 0.0, 0.0, 1.0);
    glTranslatef(0.05, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    //Draw finger flang 2
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)-fingerUp2, 0.0, 0.0, 1.0);
    glTranslatef(0.05, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix();


    glPushMatrix();
    //Draw finger flang 3
    glTranslatef(0.55, -0.15, -0.12);
    glRotatef((GLfloat)-fingerBase2, 0.0, 0.0, 1.0);
    glTranslatef(0.05, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    //Draw finger flang 3
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)-fingerUp2, 0.0, 0.0, 1.0);
    glTranslatef(0.05, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix();


    glPushMatrix();
    //Draw finger flang 4
    glTranslatef(0.55, -0.15, 0.09);
    glRotatef((GLfloat)-fingerBase2, 0.0, 0.0, 1.0);
    glTranslatef(0.05, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    //Draw finger flang 4
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)-fingerUp2, 0.0, 0.0, 1.0);
    glTranslatef(0.05, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    //Draw finger flang 5
    glTranslatef(0.55, -0.15, 0.3);
    glRotatef((GLfloat)-fingerBase2, 0.0, 0.0, 1.0);
    glTranslatef(0.05, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    //Draw finger flang 5
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)-fingerUp2, 0.0, 0.0, 1.0);
    glTranslatef(0.05, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    //////////////////////////////////////////////RIGHT ARM////////////////////////////////////////////////
    glPushMatrix();
    glTranslatef(0.6, 0.55, 0.0);
    glRotatef((GLfloat)SHOULDERRIGHT, 0.0, 0.0, 1.0);
    glTranslatef(0.0, -0.41, 0.0);
    glRotatef((GLfloat)SHOULDERRIGHTZROT, 0.0, 1.0, 0.0);
    glTranslatef(-0.63, -0.22, 0.0);
    glPushMatrix();
    glTranslatef(0.55, 0.43, 0.0);
    glScalef(0.2, 0.5, 0.3);
    glutWireCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1.0, 0.15, 0.0);
    glRotatef((GLfloat)SHOULDERRIGHT2, 1.0, 0.0, 0.0);
    glTranslatef(1.55, -0.22, 0.0);
    glScalef(0.2, 0.5, 0.3);
    glutWireCube(1.0);





    glRotatef(-90, 0.0, 0.0, 1.0);

    glPushMatrix();
    //Draw finger flang 1
    glTranslatef(0.55, -0.15, 0.25);
    glRotatef((GLfloat)fingerBase, 0.0, 0.0, 1.0);
    glTranslatef(0.05, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    //Draw finger flang 1
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)fingerUp, 0.0, 0.0, 1.0);
    glTranslatef(0.05, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix();


    glPushMatrix();
    //Draw finger flang 2
    glTranslatef(0.55, 0.15, -0.35);
    glRotatef((GLfloat)-fingerBase, 0.0, 0.0, 1.0);
    glTranslatef(0.05, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    //Draw finger flang 2
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)-fingerUp, 0.0, 0.0, 1.0);
    glTranslatef(0.05, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix();


    glPushMatrix();
    //Draw finger flang 3
    glTranslatef(0.55, 0.15, -0.12);
    glRotatef((GLfloat)-fingerBase, 0.0, 0.0, 1.0);
    glTranslatef(0.05, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    //Draw finger flang 3
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)-fingerUp, 0.0, 0.0, 1.0);
    glTranslatef(0.05, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix();


    glPushMatrix();
    //Draw finger flang 4 
    glTranslatef(0.55, 0.15, 0.09);
    glRotatef((GLfloat)-fingerBase, 0.0, 0.0, 1.0);
    glTranslatef(0.05, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    //Draw finger flang 4
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)-fingerUp, 0.0, 0.0, 1.0);
    glTranslatef(0.05, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    //Draw finger flang 5
    glTranslatef(0.55, 0.15, 0.3);
    glRotatef((GLfloat)-fingerBase, 0.0, 0.0, 1.0);
    glTranslatef(0.05, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    //Draw finger flang 5
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)-fingerUp, 0.0, 0.0, 1.0);
    glTranslatef(0.05, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();



    //////////////////////////////////////////////RIGHT LEG///////////////////////////////////////////////////
    glPushMatrix();
    glTranslatef(-0.1, -0.8, 0.0);
    glRotatef((GLfloat)RIGHTLEGUPALL, 1.0, 0.0, 0.0);
    glRotatef((GLfloat)RIGHTLEGSIDE, 0.0, 0.0, 1.0);
    glTranslatef(0.1, 0.8, 0.0);
    glPushMatrix();
    glTranslatef(-0.25, -1.02, 0.0);
    glScalef(0.25, 0.7, 0.3);//first part of the leg
    glutWireCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.8, -1.35, 0.0);
    glRotatef((GLfloat)RIGHTLEG2, 1.0, 0.0, 0.0);
    glTranslatef(-0.8, 1.35, 0.0);
    glPushMatrix();
    glTranslatef(-0.25, -1.72, 0.0);
    glScalef(0.25, 0.7, 0.3);//second part of the leg
    glutWireCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.25, -2.0, 0.0);
    glScalef(0.26, 0.2, 0.5);// the leg it's self from down
    glutSolidCube(1.0);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    //////////////////////////////////////////////LEFT LEG///////////////////////////////////////////////////
    glPushMatrix();
    glTranslatef(0.1, -0.8, 0.0);
    glRotatef((GLfloat)LEFTLEGUP, 1.0, 0.0, 0.0);
    glRotatef((GLfloat)LEFTLEGSIDE, 0.0, 0.0, 1.0);
    glTranslatef(-0.1, 0.8, 0.0);
    glPushMatrix();
    glTranslatef(0.25, -1.02, 0.0);
    glScalef(0.23, 0.7, 0.3);
    glutWireCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.8, -1.35, 0.0);
    glRotatef((GLfloat)LEFTLEG2, 1.0, 0.0, 0.0);
    glTranslatef(-0.8, 1.35, 0.0);
    glPushMatrix();
    glTranslatef(0.25, -1.72, 0.0);
    glScalef(0.25, 0.7, 0.3);
    glutWireCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.25, -2.0, 0.0);
    glScalef(0.26, 0.2, 0.5);
    glutSolidCube(1.0);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();




    glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}





void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
        if (SHOULDERRIGHT < 115)
        {
            SHOULDERRIGHT = (SHOULDERRIGHT + 5) % 360;
            glutPostRedisplay();
        }
        if (SHOULDERLEFT > -115)
        {
            SHOULDERLEFT = (SHOULDERLEFT - 5) % 360;
            glutPostRedisplay();
        }
        break;
    case 'A':
        if (SHOULDERRIGHT > 0)
        {
            SHOULDERRIGHT = (SHOULDERRIGHT - 5) % 360;
            glutPostRedisplay();
        }
        if (SHOULDERLEFT < 0)
        {
            SHOULDERLEFT = (SHOULDERLEFT + 5) % 360;
            glutPostRedisplay();
        }
        break;
    case 's':
        if (SHOULDERRIGHTZROT < 90)
        {
            SHOULDERRIGHTZROT = (SHOULDERRIGHTZROT + 5) % 360;
            glutPostRedisplay();
        }
        if (SHOULDERLEFTZROT > -90)
        {
            SHOULDERLEFTZROT = (SHOULDERLEFTZROT - 5) % 360;
            glutPostRedisplay();
        }
        break;
    case 'S':
        if (SHOULDERRIGHTZROT > 0)
        {
            SHOULDERRIGHTZROT = (SHOULDERRIGHTZROT - 5) % 360;
            glutPostRedisplay();
        }
        if (SHOULDERLEFTZROT < 0)
        {
            SHOULDERLEFTZROT = (SHOULDERLEFTZROT + 5) % 360;
            glutPostRedisplay();
        }
        break;
    case 'w':
        if (SHOULDERRIGHT2 > -90)
        {
            SHOULDERRIGHT2 = (SHOULDERRIGHT2 - 5) % 360;
            glutPostRedisplay();
        }
        if (SHOULDERLEFT2 > -90)
        {
            SHOULDERLEFT2 = (SHOULDERLEFT2 - 5) % 360;
            glutPostRedisplay();
        }
        break;
    case 'W':
        if (SHOULDERRIGHT2 < 45)
        {
            SHOULDERRIGHT2 = (SHOULDERRIGHT2 + 5) % 360;
            glutPostRedisplay();
        }
        if (SHOULDERLEFT2 < 45)
        {
            SHOULDERLEFT2 = (SHOULDERLEFT2 + 5) % 360;
            glutPostRedisplay();
        }
        break;
    case 'd':
        if (RIGHTLEGUPALL > -90)
        {
            RIGHTLEGUPALL = (RIGHTLEGUPALL - 5) % 360;
            glutPostRedisplay();
        }
        break;
    case 'D':
        if (LEFTLEGUP > -90)
        {
            LEFTLEGUP = (LEFTLEGUP - 5) % 360;
            glutPostRedisplay();
        }
        break;
    case 'q':
        if (RIGHTLEGUPALL < 65)
        {
            RIGHTLEGUPALL = (RIGHTLEGUPALL + 5) % 360;
            glutPostRedisplay();
        }
        break;
    case 'Q':
        if (LEFTLEGUP < 65)
        {
            LEFTLEGUP = (LEFTLEGUP + 5) % 360;
            glutPostRedisplay();
        }
        break;
    case 'e':
        if (RIGHTLEG2 > -10)
        {
            RIGHTLEG2 = (RIGHTLEG2 - 5) % 360;
            glutPostRedisplay();
        }
        break;
    case 'E':
        if (LEFTLEG2 > -10)
        {
            LEFTLEG2 = (LEFTLEG2 - 5) % 360;
            glutPostRedisplay();
        }
        break;
    case 'r':
        if (RIGHTLEG2 < 90)
        {
            RIGHTLEG2 = (RIGHTLEG2 + 5) % 360;
            glutPostRedisplay();
        }
        break;
    case 'R':
        if (LEFTLEG2 < 90)
        {
            LEFTLEG2 = (LEFTLEG2 + 5) % 360;
            glutPostRedisplay();
        }
        break;
    case 't':
        if (RIGHTLEGSIDE < 10)
        {
            RIGHTLEGSIDE = (RIGHTLEGSIDE + 5) % 360;
            glutPostRedisplay();
        }
        break;
    case 'T':
        if (RIGHTLEGSIDE > -85)
        {
            RIGHTLEGSIDE = (RIGHTLEGSIDE - 5) % 360;
            glutPostRedisplay();
        }
        break;
    case 'y':
        if (LEFTLEGSIDE > -10)
        {
            LEFTLEGSIDE = (LEFTLEGSIDE - 5) % 360;
            glutPostRedisplay();
        }
        break;
    case 'Y':
        if (LEFTLEGSIDE < 85)
        {
            LEFTLEGSIDE = (LEFTLEGSIDE + 5) % 360;
            glutPostRedisplay();
        }
        break;
    case 'f':
        if (allbodyZ > -5)
        {
            allbodyZ = (allbodyZ - 1) % 360;
            glutPostRedisplay();
        }
        break;
    case 'F':
        if (allbodyZ < 2)
        {
            allbodyZ = (allbodyZ + 1) % 360;
            glutPostRedisplay();
        }
        break;
    case 'g':
        fingerBase = (fingerBase + 5);
        if (fingerBase > 90) {
            fingerBase = fingerBase - 5;
            break;
        }
        glutPostRedisplay();
        break;
    case 'G':
        fingerBase = (fingerBase - 5);
        if (fingerBase < -5) {
            fingerBase = fingerBase + 5;
            break;
        }
        glutPostRedisplay();
        break;
    case 'h':
        fingerUp = fingerUp + 5;
        if (fingerUp > 90) {
            fingerUp = fingerUp - 5;
            break;
        }
        glutPostRedisplay();
        break;
    case 'H':
        fingerUp = fingerUp - 5;
        if (fingerUp < -5) {
            fingerUp = fingerUp + 5;
            break;
        }
        glutPostRedisplay();
        break;
    case 'j':
        fingerBase2 = (fingerBase2 - 5);
        if (fingerBase2 < -90) {
            fingerBase2 = fingerBase2 + 5;
            break;
        }
        glutPostRedisplay();
        break;
    case 'J':
        fingerBase2 = (fingerBase2 + 5);
        if (fingerBase2 > 5) {
            fingerBase2 = fingerBase2 - 5;
            break;
        }
        glutPostRedisplay();
        break;
    case 'k':
        fingerUp2 = fingerUp2 - 5;
        if (fingerUp2 < -90) {
            fingerUp2 = fingerUp2 + 5;
            break;
        }
        glutPostRedisplay();
        break;
    case 'K':
        fingerUp2 = fingerUp2 + 5;
        if (fingerUp2 > 5) {
            fingerUp2 = fingerUp2 - 5;
            break;
        }
        glutPostRedisplay();
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

static void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            moving = 1;
            startx = x;
            starty = y;
        }
        if (state == GLUT_UP) {
            moving = 0;
        }
    }
}


static void motion(int x, int y)
{
    if (moving) {
        angle = angle + (x - startx);
        angle2 = angle2 + (y - starty);
        startx = x;
        starty = y;
        glutPostRedisplay();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(2000, 1000);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(argv[0]);
    init();
    glutMotionFunc(motion);
    glutMouseFunc(mouse);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);


    glutMainLoop();
    return 0;
}