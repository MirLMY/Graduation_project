#ifndef SHOWMAINWINDOW_H
#define SHOWMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class ShowMainWindow;
}

class ShowMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ShowMainWindow(QWidget *parent = 0);
    ~ShowMainWindow();

private:
    Ui::ShowMainWindow *ui;

private slots:
    void checkedLibAction();
    void checkedLibAction1();

};

#endif // SHOWMAINWINDOW_H
