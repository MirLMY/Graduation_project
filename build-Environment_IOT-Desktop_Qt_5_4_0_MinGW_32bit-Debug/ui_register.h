/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *user_label;
    QLabel *oldPassword_label;
    QLabel *newPassword_label;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *user_Edit;
    QLineEdit *oldPasswordEdit;
    QLineEdit *newPassword_lineEdit;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(400, 300);
        widget = new QWidget(Register);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(70, 90, 199, 76));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        user_label = new QLabel(widget);
        user_label->setObjectName(QStringLiteral("user_label"));

        verticalLayout->addWidget(user_label);

        oldPassword_label = new QLabel(widget);
        oldPassword_label->setObjectName(QStringLiteral("oldPassword_label"));

        verticalLayout->addWidget(oldPassword_label);

        newPassword_label = new QLabel(widget);
        newPassword_label->setObjectName(QStringLiteral("newPassword_label"));

        verticalLayout->addWidget(newPassword_label);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        user_Edit = new QLineEdit(widget);
        user_Edit->setObjectName(QStringLiteral("user_Edit"));

        verticalLayout_2->addWidget(user_Edit);

        oldPasswordEdit = new QLineEdit(widget);
        oldPasswordEdit->setObjectName(QStringLiteral("oldPasswordEdit"));

        verticalLayout_2->addWidget(oldPasswordEdit);

        newPassword_lineEdit = new QLineEdit(widget);
        newPassword_lineEdit->setObjectName(QStringLiteral("newPassword_lineEdit"));

        verticalLayout_2->addWidget(newPassword_lineEdit);


        horizontalLayout->addLayout(verticalLayout_2);

        widget1 = new QWidget(Register);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(200, 260, 179, 25));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setSpacing(27);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget1);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Dialog", 0));
        user_label->setText(QApplication::translate("Register", "\347\224\250\346\210\267\345\220\215", 0));
        oldPassword_label->setText(QApplication::translate("Register", "\346\227\247\345\257\206\347\240\201", 0));
        newPassword_label->setText(QApplication::translate("Register", "\346\226\260\345\257\206\347\240\201", 0));
        pushButton->setText(QApplication::translate("Register", "\347\241\256\350\256\244", 0));
        pushButton_2->setText(QApplication::translate("Register", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
