#ifndef VRWIDGET_H
#define VRWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QTimer>
#include <QMouseEvent>
#include <string>

class VRWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    VRWidget(QWidget *parent = nullptr);
    ~VRWidget();


private :
    QOpenGLBuffer vborequin;
    QOpenGLBuffer vbocube;
    QOpenGLShaderProgram programrequin;
    QOpenGLShaderProgram programcube;
    QOpenGLVertexArrayObject vaorequin;
    QOpenGLVertexArrayObject vaocube;
    float angleY=0;
    float angleX=0;
    float vague=0;
    bool inAnim=false;
    std::string forme = "Cube";
    float fov=45;
    int opacity=100;
    QPointF oldPos;
    QTimer* timer= new QTimer();

private slots:
    void update();

public slots :
    void startAnimation();
    void stopAnimation();
    void changeFov(int);
    void changeOpacity(int);
    void selectRequin();
    void selectCube();

protected :
    void initializeBuffer();
    void initializeShader();
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void cleanupOpenGLResources();

    // QOpenGLWidget interface
protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
};
#endif // VRWIDGET_H
