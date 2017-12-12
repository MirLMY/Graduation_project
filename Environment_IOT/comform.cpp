#include "comform.h"
#include "ui_comform.h"
#include <QDebug>

#define BAUD_2400   0
#define BAUD_4800   1
#define BAUD_9600   2
#define BAUD_115200 3

comForm::comForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::comForm)
{
    ui->setupUi(this);
}

comForm::~comForm()
{
    delete ui;
}

void comForm::on_openClose_Button_clicked()
{
    //波特率配置
    switch (ui->baud_Box->currentIndex()) {
    case BAUD_2400:

        break;
    case BAUD_4800:
        break;
    case BAUD_9600:
        break;
    case BAUD_115200:
        break;
    }
    //校验位配置



}
