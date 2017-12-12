#ifndef COMFORM_H
#define COMFORM_H

#include <QWidget>
#include <QSerialPort>

namespace Ui {
class comForm;
}

class comForm : public QWidget
{
    Q_OBJECT

public:
    explicit comForm(QWidget *parent = 0);
    ~comForm();

private slots:
    void on_openClose_Button_clicked();

private:
    Ui::comForm *ui;
    QSerialPort *my_serialport = new QSerialPort();

};

#endif // COMFORM_H
