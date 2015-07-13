#include "lineargradientwidget.h"
#include <QPainter>
#include <QBrush>

LinearGradientWidget::LinearGradientWidget()
{
    startR = 0;
    startG = 0;
    startB = 0;

    endR = 255;
    endG = 255;
    endB = 255;

    windowGradient = new QLinearGradient(QPoint(0,0), QPoint(this->width(), this->height()) );
    windowGradient->setColorAt(0.0,QColor(startR,startG,startB));
    windowGradient->setColorAt(1.0,QColor(endR,endG,endB) );


    startR_Slider = new QSlider;
    startR_Slider->setMinimum(0);
    startR_Slider->setMaximum(255);


    startG_Slider = new QSlider;
    startG_Slider->setMinimum(0);
    startG_Slider->setMaximum(255);

    startB_Slider = new QSlider;
    startB_Slider->setMinimum(0);
    startB_Slider->setMaximum(255);

    endR_Slider = new QSlider;
    endR_Slider->setMinimum(0);
    endR_Slider->setMaximum(255);

    endG_Slider = new QSlider;
    endG_Slider->setMinimum(0);
    endG_Slider->setMaximum(255);

    endB_Slider = new QSlider;
    endB_Slider->setMinimum(0);
    endB_Slider->setMaximum(255);


    startLayout = new QHBoxLayout;
    startLayout->addWidget(startR_Slider);
    startLayout->addWidget(startG_Slider);
    startLayout->addWidget(startB_Slider);

    endLayout = new QHBoxLayout;
    endLayout->addWidget(endR_Slider);
    endLayout->addWidget(endG_Slider);
    endLayout->addWidget(endB_Slider);

    mainLayout = new QVBoxLayout;
    mainLayout->addSpacing(  ((this->height()/2)* 3)  );
    mainLayout->addLayout(startLayout);
    mainLayout->addLayout(endLayout);

    setLayout(mainLayout);

    connect(startR_Slider, SIGNAL(valueChanged(int)), this, SLOT(updateGradient()) );
    connect(startG_Slider, SIGNAL(valueChanged(int)), this, SLOT(updateGradient()) );
    connect(startB_Slider, SIGNAL(valueChanged(int)), this, SLOT(updateGradient()) );

    connect(endR_Slider, SIGNAL(valueChanged(int)), this, SLOT(updateGradient()) );
    connect(endG_Slider, SIGNAL(valueChanged(int)), this, SLOT(updateGradient()) );
    connect(endB_Slider, SIGNAL(valueChanged(int)), this, SLOT(updateGradient()) );

}

void LinearGradientWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    QBrush gradientBrush(*windowGradient);

    painter.begin(this);
    painter.fillRect(event->rect(), gradientBrush);
    painter.end();
}

void LinearGradientWidget::updateGradient()
{
    if(startR_Slider->value() != startR)
        startR = startR_Slider->value();

    if(startG_Slider->value() != startG)
        startG = startG_Slider->value();

    if(startB_Slider->value() != startB)
        startB = startB_Slider->value();

    if(endR_Slider->value() != endR)
        endR = endR_Slider->value();

    if(endG_Slider->value() != endG)
        endG = endG_Slider->value();

    if(endB_Slider->value() != endB)
        endB = endB_Slider->value();


    windowGradient->setColorAt(0.0,QColor(startR,startG,startB));
    windowGradient->setColorAt(1.0,QColor(endR,endG,endB) );
    update();
}

