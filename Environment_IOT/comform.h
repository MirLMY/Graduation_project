#ifndef COMFORM_H
#define COMFORM_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>

namespace Ui {
class comForm;
}

class comForm : public QWidget
{
    Q_OBJECT

public:
    explicit comForm(QWidget *parent = 0);
    ~comForm();
    QSerialPort *my_serialport;

private slots:
    void on_openClose_Button_clicked();

private:
    Ui::comForm *ui;



};

#endif // COMFORM_H
