#include <iostream>
#include "glm.h"
#include "materials.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <GLUT/glut.h>
#include<OpenGL/gl.h>
#include<OpenGL/glu.h>


using namespace std;

GLMmodel *dice;

void rollDice (void){

  char* name = "data/Dice.obj";
  glClearColor(0,0,0,1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  dice=glmReadOBJ(name);
  glmUnitize(dice);
  glmFacetNormals(dice);
  glmVertexNormals(dice, 0);

  glmDraw(dice, GLM_SMOOTH);
  glutSwapBuffers();
}







int main(int argc, char **argv){


  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
  glutInitWindowSize(512, 512);
  glutInitWindowPosition(50, 50);
  glutInit(&argc, argv);
    
  glutCreateWindow("Dice");
  glutDisplayFunc(rollDice);

  glutMainLoop();

}
