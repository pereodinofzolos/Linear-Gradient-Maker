#ifndef LINEARGRADIENTWIDGET_H
#define LINEARGRADIENTWIDGET_H

#include <QWidget>
#include <QLinearGradient>
#include <QSlider>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPaintEvent>

/*This class uses sliders to control the RGB of
* the start and endpoints of a linear gradient which
* is displayed on its surface
*/



class LinearGradientWidget : public QWidget
{
    Q_OBJECT
public:
    LinearGradientWidget();

    QLinearGradient *windowGradient;

    int startR;
    int startG;
    int startB;

    int endR;
    int endG;
    int endB;

    QSlider *startR_Slider;
    QSlider *startG_Slider;
    QSlider *startB_Slider;

    QSlider *endR_Slider;
    QSlider *endG_Slider;
    QSlider *endB_Slider;

    QHBoxLayout *startLayout;
    QHBoxLayout *endLayout;
    QVBoxLayout *mainLayout;

    void paintEvent(QPaintEvent *event);


public slots:

    void updateGradient(); // makes all RGB components the value of their corresponding slider

};
#endif // LINEARGRADIENTWIDGET_H
