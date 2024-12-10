#include "vrwidget.h"
#include <QVector3D>
#include <QMessageBox>
#include <iostream>

VRWidget::VRWidget(QWidget *parent)
    : QOpenGLWidget(parent), QOpenGLFunctions()
{}

VRWidget::~VRWidget() {}

void VRWidget::initializeBuffer()
{

    QVector3D A(0,0,1);
    QVector3D B(1,0,1);
    QVector3D C(1,1,1);
    QVector3D D(0,1,1);
    QVector3D E(0,0,0);
    QVector3D F(1,0,0);
    QVector3D G(1,1,0);
    QVector3D H(0,1,0);

    QVector3D red(1,0,0);
    QVector3D blue(0,0,1);
    QVector3D green(0,1,0);
    QVector3D yellow(1,1,0);
    QVector3D magenta(1,0,1);
    QVector3D cyan(0,1,1);
    QVector3D black(0,0,0);
    QVector3D low_white(0.76,0.76,0.76);
    QVector3D low_grey(0.28,0.28,0.28);

    QVector3D R1(-1,0.4f,0);
    QVector3D R2(-0.5f,0.07f,0);
    QVector3D R3(0,0.3f,0);
    QVector3D R4(-0.05f,0.6f,0);
    QVector3D R5(0.25f,0.19f,0);
    QVector3D R6(0.7,0.01f,0);
    QVector3D R7(0.7,-0.01f,0);
    QVector3D R8(0,-0.3f,0);
    QVector3D R9(-0.5f,-0.07f,0);
    QVector3D R10(-1,-0.4f,0);
    QVector3D R11(-0.7f,0,0);

    QVector3D R12(0.7,0,0);

    QVector3D R13(0.3f,-0.1,0);
    QVector3D R14(-0.3,-0.1,0);
    QVector3D R15(0,-0.3,-0.3);
    QVector3D R16(0,-0.3,0.3);

    QVector3D R17(0,-0.1,0.3);
    QVector3D R18(0,-0.1,-0.3);

    QVector3D R19(0.35,0.1,0.05);
    QVector3D R20(0.32,0.05,0.09);
    QVector3D R21(0.38,0.05,0.07);

    QVector3D R22(0.35,0.1,-0.05);
    QVector3D R23(0.32,0.05,-0.09);
    QVector3D R24(0.38,0.05,-0.07);


    QVector3D vertexCubeData[] = {
            A,B,C,D,
            B,F,G,C,
            F,E,H,G,
            E,H,D,A,
            D,C,G,H,
            E,F,B,A,
            red,red,red,red,
            magenta,magenta,magenta,magenta,
            green,green,green,green,
            yellow,yellow,yellow,yellow,
            blue,blue,blue,blue,
            cyan,cyan,cyan,cyan
        };


    QVector3D vertexRequinData[] = {
        R9,R10,R11,
        R11,R1,R2,
        R11,R3,R17,
        R11,R3,R18,
        R3,R4,R5,

        R3,R6,R17,
        R6,R7,R17,
        R17,R7,R8,

        R3,R6,R18,
        R6,R7,R18,
        R18,R7,R8,

        R3,R12,R17,
        R11,R17,R8,
        R11,R18,R8,

        R13,R14,R15,
        R13,R14,R16,

        R19,R20,R21,
        R22,R23,R24,

        low_grey,low_grey,low_grey,
        low_grey,low_grey,low_grey,
        low_grey,low_grey,low_grey,
        low_grey,low_grey,low_grey,
        low_grey,low_grey,low_grey,

        low_grey,low_grey,low_grey,
        low_grey,low_grey,low_grey,
        low_white,low_white,low_white,

        low_grey,low_grey,low_grey,
        low_grey,low_grey,low_grey,
        low_white,low_white,low_white,

        low_grey,low_grey,low_grey,
        low_white,low_white,low_white,
        low_white,low_white,low_white,

        low_grey,low_grey,low_grey,
        low_grey,low_grey,low_grey,

        black,black,black,
        black,black,black


    };


    //Initialisation du Vertex Buffer Object
    vbocube = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    //Création du VBO
    vbocube.create();
    //Lien du VBO avec le contexte de rendu OpenGL
    vbocube.bind();
    //Allocation des données dans le VBO
    vbocube.allocate(vertexCubeData, sizeof(vertexCubeData));
    vbocube.setUsagePattern(QOpenGLBuffer::StaticDraw);
    //Libération du VBO
    vbocube.release();

    //Initialisation du Vertex Buffer Object
    vborequin = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    //Création du VBO
    vborequin.create();
    //Lien du VBO avec le contexte de rendu OpenGL
    vborequin.bind();
    //Allocation des données dans le VBO
    vborequin.allocate(vertexRequinData, sizeof(vertexRequinData));
    vborequin.setUsagePattern(QOpenGLBuffer::StaticDraw);
    //Libération du VBO
    vborequin.release();
}

void VRWidget::initializeShader()
{



    bool resultatcube;
    programcube.create();
    programcube.bind();

    //Vertex Shader
    resultatcube = programcube.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/VS_simple.vsh");
    if (!resultatcube)     {
        QMessageBox msg;
        msg.setWindowTitle("Vertex shader");
        msg.setText(programcube.log());
        msg.exec();
        exit(EXIT_FAILURE);
    }

    //Fragment Shader
    resultatcube = programcube.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/FS_simple.fsh");
    if (!resultatcube)     {
        QMessageBox msg;
        msg.setWindowTitle("Fragment shader");
        msg.setText(programcube.log());
        msg.exec();
        exit(EXIT_FAILURE);
    }

    //Link
    resultatcube = programcube.link();
    if (!resultatcube)     {
        QMessageBox msg;
        msg.setWindowTitle("Link du shader program");
        msg.setText(programcube.log());
        msg.exec();
        exit(EXIT_FAILURE);
    }

    vaocube.create();
    vaocube.bind();
    vbocube.bind();

    programcube.setAttributeBuffer("rv_Position", GL_FLOAT, 0, 3);
    programcube.enableAttributeArray("rv_Position");

    programcube.setAttributeBuffer("rv_Color", GL_FLOAT, sizeof(QVector3D) * 24, 3);
    programcube.enableAttributeArray("rv_Color");


    //Libération
    vaocube.release();
    programcube.release();





    bool resultatrequin;
    programrequin.create();
    programrequin.bind();

    //Vertex Shader
    resultatrequin = programrequin.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/VS_simple.vsh");
    if (!resultatrequin)     {
        QMessageBox msg;
        msg.setWindowTitle("Vertex shader");
        msg.setText(programrequin.log());
        msg.exec();
        exit(EXIT_FAILURE);
    }

    //Fragment Shader
    resultatrequin = programrequin.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/FS_simple.fsh");
    if (!resultatrequin)     {
        QMessageBox msg;
        msg.setWindowTitle("Fragment shader");
        msg.setText(programrequin.log());
        msg.exec();
        exit(EXIT_FAILURE);
    }

    //Link
    resultatrequin = programrequin.link();
    if (!resultatrequin)     {
        QMessageBox msg;
        msg.setWindowTitle("Link du shader program");
        msg.setText(programrequin.log());
        msg.exec();
        exit(EXIT_FAILURE);
    }

    vaorequin.create();
    vaorequin.bind();
    vborequin.bind();

    programrequin.setAttributeBuffer("rv_Position", GL_FLOAT, 0, 3);
    programrequin.enableAttributeArray("rv_Position");


    programrequin.setAttributeBuffer("rv_Color", GL_FLOAT, sizeof(QVector3D) * 54, 3);
    programrequin.enableAttributeArray("rv_Color");


    //Libération
    vaorequin.release();
    programrequin.release();
}


void VRWidget::initializeGL()
{

    initializeOpenGLFunctions();
    glClearColor(0.0f, 0.566f, 0.867f, 1.0f);

    initializeBuffer();
    initializeShader();

    //connect(timer, SIGNAL(timeout()),this,SLOT(update()));
    //timer->start(30);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void VRWidget::resizeGL(int w, int h)
{
    //transformation de viewport
    glViewport(0, 0, w, h);
}

void VRWidget::startAnimation(){
    if (inAnim){stopAnimation();}
    else{
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(30);
    inAnim=true;
    }
}

void VRWidget::stopAnimation() {
    timer->stop();
    inAnim=false;
    timer= new QTimer();

}

void VRWidget::paintGL()
{
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    QMatrix4x4 model, proj, view, matrix;

    //Définition de la matrice de projetcion
    float wid= width();
    float hei=height();
    proj.perspective(fov, wid/hei, 0.1f, 100.0f);

    //Définiion de la matrice de vue
    view  = QMatrix4x4();

    //Définition de la matrice de placement
    model.translate(0, 0, -3);
    model.rotate(angleX,1,0,0);
    model.rotate(angleY,0,1,0);
    model.translate(-0.5,-0.5,-0.5);
    if (forme=="Requin"){
        model.translate(0,0.5,-0.5);
        model.translate(0,sin(vague*1.5)/2,0);
    }

    //Produit des trois matrices (dans ce sens!)
    matrix = proj * view * model;

    if (forme=="Cube"){
    programcube.bind();
    programcube.setUniformValue("u_ModelViewProjectionMatrix", matrix);

    float opa=opacity;
    programcube.setUniformValue("u_Opacity", opa/100);

    vaocube.bind();
    for (int i = 0; i < 6; ++i) {
        glDrawArrays(GL_TRIANGLE_FAN, i * 4, 4);
        }

    vaocube.release();
    programcube.release();
    }




    if (forme=="Requin"){
        programrequin.bind();
        programrequin.setUniformValue("u_ModelViewProjectionMatrix", matrix);

        float opa=opacity;
        programrequin.setUniformValue("u_Opacity", opa/100);

        vaorequin.bind();
        for (int i = 0; i < 18; ++i) {
            glDrawArrays(GL_TRIANGLE_FAN, i * 3, 3);
        }

        vaorequin.release();
        programrequin.release();
    }

}

void VRWidget::update(){
    angleY=angleY-5;
    vague=vague+0.1;
    QOpenGLWidget::update();
}

void VRWidget::mousePressEvent(QMouseEvent* event){
    oldPos=event->position();
}

void VRWidget::changeFov(int value){
    fov=value;
    QOpenGLWidget::update();
}

void VRWidget::selectRequin(){
    forme="Requin";
    QOpenGLWidget::update();
}
void VRWidget::selectCube(){
    forme="Cube";
    QOpenGLWidget::update();
}

void VRWidget::changeOpacity(int value){
    opacity=value;
    QOpenGLWidget::update();
}
void VRWidget::mouseMoveEvent(QMouseEvent* event){
    float dx,dy;
    dx=(event->position().x()-oldPos.x())/width();
    dy=(event->position().y()-oldPos.y())/height();
    angleX=angleX+180*dy;
    angleY=angleY+180*dx;
    mousePressEvent(event);
    QOpenGLWidget::update();
}

