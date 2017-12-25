/********************************************************************************
** Form generated from reading UI file 'comform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMFORM_H
#define UI_COMFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_comForm
{
public:
    QPushButton *openClose_Button;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *com_label;
    QLabel *baud_label;
    QLabel *parity_label;
    QLabel *data_label;
    QLabel *stop_label;
    QVBoxLayout *verticalLayout_2;
    QComboBox *com_Box;
    QComboBox *baud_Box;
    QComboBox *parity_Box;
    QComboBox *data_Box;
    QComboBox *stop_Box;

    void setupUi(QWidget *comForm)
    {
        if (comForm->objectName().isEmpty())
            comForm->setObjectName(QStringLiteral("comForm"));
        comForm->resize(400, 300);
        openClose_Button = new QPushButton(comForm);
        openClose_Button->setObjectName(QStringLiteral("openClose_Button"));
        openClose_Button->setGeometry(QRect(130, 210, 75, 23));
        layoutWidget = new QWidget(comForm);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 30, 135, 128));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        com_label = new QLabel(layoutWidget);
        com_label->setObjectName(QStringLiteral("com_label"));

        verticalLayout->addWidget(com_label);

        baud_label = new QLabel(layoutWidget);
        baud_label->setObjectName(QStringLiteral("baud_label"));

        verticalLayout->addWidget(baud_label);

        parity_label = new QLabel(layoutWidget);
        parity_label->setObjectName(QStringLiteral("parity_label"));

        verticalLayout->addWidget(parity_label);

        data_label = new QLabel(layoutWidget);
        data_label->setObjectName(QStringLiteral("data_label"));

        verticalLayout->addWidget(data_label);

        stop_label = new QLabel(layoutWidget);
        stop_label->setObjectName(QStringLiteral("stop_label"));

        verticalLayout->addWidget(stop_label);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        com_Box = new QComboBox(layoutWidget);
        com_Box->setObjectName(QStringLiteral("com_Box"));

        verticalLayout_2->addWidget(com_Box);

        baud_Box = new QComboBox(layoutWidget);
        baud_Box->setObjectName(QStringLiteral("baud_Box"));

        verticalLayout_2->addWidget(baud_Box);

        parity_Box = new QComboBox(layoutWidget);
        parity_Box->setObjectName(QStringLiteral("parity_Box"));

        verticalLayout_2->addWidget(parity_Box);

        data_Box = new QComboBox(layoutWidget);
        data_Box->setObjectName(QStringLiteral("data_Box"));

        verticalLayout_2->addWidget(data_Box);

        stop_Box = new QComboBox(layoutWidget);
        stop_Box->setObjectName(QStringLiteral("stop_Box"));

        verticalLayout_2->addWidget(stop_Box);


        horizontalLayout->addLayout(verticalLayout_2);

        layoutWidget->raise();
        openClose_Button->raise();

        retranslateUi(comForm);

        QMetaObject::connectSlotsByName(comForm);
    } // setupUi

    void retranslateUi(QWidget *comForm)
    {
        comForm->setWindowTitle(QApplication::translate("comForm", "Form", 0));
        openClose_Button->setText(QApplication::translate("comForm", "\346\211\223\345\274\200", 0));
        com_label->setText(QApplication::translate("comForm", "\344\270\262\345\217\243", 0));
        baud_label->setText(QApplication::translate("comForm", "\346\263\242\347\211\271\347\216\207", 0));
        parity_label->setText(QApplication::translate("comForm", "\346\240\241\351\252\214\344\275\215", 0));
        data_label->setText(QApplication::translate("comForm", "\346\225\260\346\215\256\344\275\215", 0));
        stop_label->setText(QApplication::translate("comForm", "\345\201\234\346\255\242\344\275\215", 0));
        baud_Box->clear();
        baud_Box->insertItems(0, QStringList()
         << QApplication::translate("comForm", "2400", 0)
         << QApplication::translate("comForm", "4800", 0)
         << QApplication::translate("comForm", "9600", 0)
         << QApplication::translate("comForm", "115200", 0)
        );
        parity_Box->clear();
        parity_Box->insertItems(0, QStringList()
         << QApplication::translate("comForm", "NONE", 0)
         << QApplication::translate("comForm", "ODD", 0)
         << QApplication::translate("comForm", "EVEN", 0)
         << QApplication::translate("comForm", "MARK", 0)
         << QApplication::translate("comForm", "SPACE", 0)
        );
        data_Box->clear();
        data_Box->insertItems(0, QStringList()
         << QApplication::translate("comForm", "8", 0)
         << QApplication::translate("comForm", "7", 0)
         << QApplication::translate("comForm", "6", 0)
         << QApplication::translate("comForm", "5", 0)
        );
        stop_Box->clear();
        stop_Box->insertItems(0, QStringList()
         << QApplication::translate("comForm", "1", 0)
         << QApplication::translate("comForm", "2", 0)
         << QApplication::translate("comForm", "1.5", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class comForm: public Ui_comForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMFORM_H
