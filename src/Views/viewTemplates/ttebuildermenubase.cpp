#include "ttebuildermenubase.h"

TTEBuilderMenuBase::TTEBuilderMenuBase(QWidget *parent)
    : QWidget{parent}
{
    initWidget();
}

void TTEBuilderMenuBase::initWidget()
{
    setWindowFlags(Qt::Tool | Qt::WindowCloseButtonHint);

    layout = new QHBoxLayout(this);

    buttonH = new QPushButton(this);
    buttonV = new QPushButton(this);

    const QSize baseSize = QSize(50, 50);
    buttonH->setBaseSize(baseSize);
    buttonV->setBaseSize(baseSize);

    layout->addWidget(buttonH);
    layout->addWidget(buttonV);

    setLayout(layout);
}

void TTEBuilderMenuBase::closeEvent(QCloseEvent *event)
{
    QWidget::closeEvent(event);

    emit closeWindow(this);
}

