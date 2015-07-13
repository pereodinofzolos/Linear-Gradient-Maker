#include "lineargradientwidget.h"
#include <QApplication>


//Sweet Idea
//Return the RGB of whatever point over which the mouse is

//Steps
//Use mouseEvent to get mouse position
// Express position in terms of x* and y*
// x* is x rot 45 degrees
//Linear interpolation of gradient from start and end
//Using x
//Return in console or on screen



int main(int argc, char** argv){

    QApplication app(argc,argv);


    LinearGradientWidget *lgw = new LinearGradientWidget;
    lgw->show();;


    return app.exec();

}
