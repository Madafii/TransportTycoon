#ifndef TTEBUILDERMENUBASE_H
#define TTEBUILDERMENUBASE_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>

namespace Ui {
class TTEBuilderMenuBase;
}

class TTEBuilderMenuBase : public QWidget
{
    Q_OBJECT
public:
    explicit TTEBuilderMenuBase(QWidget *parent = nullptr);

private:
    void initWidget();

signals:
    void closeWindow(QWidget *widget);

protected:
    QHBoxLayout *layout;

    QPushButton *buttonWO, *buttonSN, *buttonSW_NO, *buttonSO_NW, *buttonDelete;

    void closeEvent(QCloseEvent *event) override;

    // could lead to undefined behavior when calling in constructor of derived class so disabled for now
    //virtual void initButtonIcons() = 0 ;
};

#endif // TTEBUILDERMENUBASE_H
