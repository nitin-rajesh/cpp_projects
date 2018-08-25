//
//  main.cpp
//  graphik
//
//  Created by Nitin Rajesh on 08/06/18.
//  Copyright © 2018 ITGuy. All rights reserved.
//

#include<iostream>
#include<GLUT/GLUT.h>
#include<OpenGL/OpenGL.h>
using namespace std;
int lenght=50;
int width=50;
int height=50;
void init(){
    glPointSize(60.0);
}

void render(){
    glColor4f(1,1, 1, 0.5);
    glBegin(GL_POINTS);
    glVertex2i(GL_POINTS, GL_POINTS);
    glEnd();
    //glutSwapBuffers();
}
void resize(int w, int h){
    glClear(GL_COLOR);
    width=w;
    height=h;
}
int main(int argc, const char * argv[]) {
    init();
    render();
    resize(100, 100);
    cout<<"Did something";
    return 0;
}
