/********************************************************************************
** Form generated from reading UI file 'forgetpassword.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORGETPASSWORD_H
#define UI_FORGETPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ForgetPassword
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *user_lable;
    QLabel *firstPassword_label;
    QLabel *twicePassword_label;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *user_Edit;
    QLineEdit *firstPassword_Edit;
    QLineEdit *twicePassword_Edit;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *push_Button;
    QPushButton *cannel_Button;

    void setupUi(QWidget *ForgetPassword)
    {
        if (ForgetPassword->objectName().isEmpty())
            ForgetPassword->setObjectName(QStringLiteral("ForgetPassword"));
        ForgetPassword->resize(400, 300);
        widget = new QWidget(ForgetPassword);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(100, 60, 199, 76));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        user_lable = new QLabel(widget);
        user_lable->setObjectName(QStringLiteral("user_lable"));

        verticalLayout->addWidget(user_lable);

        firstPassword_label = new QLabel(widget);
        firstPassword_label->setObjectName(QStringLiteral("firstPassword_label"));

        verticalLayout->addWidget(firstPassword_label);

        twicePassword_label = new QLabel(widget);
        twicePassword_label->setObjectName(QStringLiteral("twicePassword_label"));

        verticalLayout->addWidget(twicePassword_label);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        user_Edit = new QLineEdit(widget);
        user_Edit->setObjectName(QStringLiteral("user_Edit"));

        verticalLayout_2->addWidget(user_Edit);

        firstPassword_Edit = new QLineEdit(widget);
        firstPassword_Edit->setObjectName(QStringLiteral("firstPassword_Edit"));

        verticalLayout_2->addWidget(firstPassword_Edit);

        twicePassword_Edit = new QLineEdit(widget);
        twicePassword_Edit->setObjectName(QStringLiteral("twicePassword_Edit"));

        verticalLayout_2->addWidget(twicePassword_Edit);


        horizontalLayout->addLayout(verticalLayout_2);

        widget1 = new QWidget(ForgetPassword);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(220, 260, 158, 25));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        push_Button = new QPushButton(widget1);
        push_Button->setObjectName(QStringLiteral("push_Button"));

        horizontalLayout_2->addWidget(push_Button);

        cannel_Button = new QPushButton(widget1);
        cannel_Button->setObjectName(QStringLiteral("cannel_Button"));

        horizontalLayout_2->addWidget(cannel_Button);


        retranslateUi(ForgetPassword);

        QMetaObject::connectSlotsByName(ForgetPassword);
    } // setupUi

    void retranslateUi(QWidget *ForgetPassword)
    {
        ForgetPassword->setWindowTitle(QApplication::translate("ForgetPassword", "Form", 0));
        user_lable->setText(QApplication::translate("ForgetPassword", "\347\224\250\346\210\267\345\220\215", 0));
        firstPassword_label->setText(QApplication::translate("ForgetPassword", "\347\231\273\351\231\206\345\257\206\347\240\201", 0));
        twicePassword_label->setText(QApplication::translate("ForgetPassword", "\345\257\206\347\240\201\347\241\256\350\256\244", 0));
        push_Button->setText(QApplication::translate("ForgetPassword", "\346\217\220\344\272\244", 0));
        cannel_Button->setText(QApplication::translate("ForgetPassword", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class ForgetPassword: public Ui_ForgetPassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORGETPASSWORD_H
