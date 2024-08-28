#ifndef TTERAILBUILDERMENU_H
#define TTERAILBUILDERMENU_H

#include <QWidget>

namespace Ui {
class TTERailBuilderMenu;
}

class TTERailBuilderMenu : public QWidget
{
    Q_OBJECT

public:
    explicit TTERailBuilderMenu(QWidget *parent = nullptr);
    ~TTERailBuilderMenu();

private:
    Ui::TTERailBuilderMenu *ui;

signals:
    void closeWindow(QWidget *widget);

protected:
    void closeEvent(QCloseEvent *event) override;
};

#endif // TTERAILBUILDERMENU_H
