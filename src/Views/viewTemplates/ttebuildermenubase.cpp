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

    buttonWO = new QPushButton(this);
    buttonSN = new QPushButton(this);
    buttonSW_NO = new QPushButton(this);
    buttonSO_NW = new QPushButton(this);
    buttonDelete = new QPushButton(this);

    const QSize baseSize = QSize(50, 50);
    buttonWO->setFixedSize(baseSize);
    buttonSN->setFixedSize(baseSize);
    buttonSW_NO->setFixedSize(baseSize);
    buttonSO_NW->setFixedSize(baseSize);
    buttonDelete->setFixedSize(baseSize);

    buttonWO->setIconSize(baseSize);
    buttonSN->setIconSize(baseSize);
    buttonSW_NO->setIconSize(baseSize);
    buttonSO_NW->setIconSize(baseSize);
    buttonDelete->setIconSize(baseSize);
    
    layout->addWidget(buttonWO);
    layout->addWidget(buttonSN);
    layout->addWidget(buttonSW_NO);
    layout->addWidget(buttonSO_NW);
    layout->addWidget(buttonDelete);

    setLayout(layout);

    adjustSize();
}

void TTEBuilderMenuBase::closeEvent(QCloseEvent *event)
{
    QWidget::closeEvent(event);

    emit closeWindow(this);
}
