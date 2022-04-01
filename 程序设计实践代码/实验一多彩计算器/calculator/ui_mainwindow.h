/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QGridLayout *keyboard;
    QPushButton *pushButton_backspace;
    QPushButton *pushButton_5;
    QPushButton *pushButton_0;
    QPushButton *pushButton_e;
    QPushButton *pushButton_ClosingParenthesis;
    QPushButton *pushButton_2;
    QPushButton *pushButton_addition;
    QPushButton *pushButton_z8;
    QPushButton *pushButton_3;
    QPushButton *pushButton_percent;
    QPushButton *pushButton_9;
    QPushButton *pushButton_z4;
    QPushButton *pushButton_8;
    QPushButton *pushButton_multiplication;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_pow;
    QPushButton *pushButton_division;
    QPushButton *pushButton_equal;
    QPushButton *pushButton_1;
    QPushButton *pushButton_6;
    QPushButton *pushButton_p;
    QPushButton *pushButton_4;
    QPushButton *pushButton_7;
    QPushButton *pushButton_root;
    QPushButton *pushButton_subtraction;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_z2;
    QPushButton *pushButton_LeftParenthesis;
    QPushButton *pushButton_fraction;
    QPushButton *pushButton_z16;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(518, 522);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(517, 522));
        MainWindow->setMaximumSize(QSize(1000, 1000));
        MainWindow->setStyleSheet(QString::fromUtf8("/*\346\235\216\346\230\245\351\230\263\345\210\266\344\275\234\n"
"*/"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 521, 521));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setBaseSize(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(39);
        font.setBold(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        font.setKerning(true);
        font.setStyleStrategy(QFont::PreferDefault);
        lineEdit->setFont(font);
        lineEdit->setCursor(QCursor(Qt::ArrowCursor));
        lineEdit->setStyleSheet(QString::fromUtf8("border:0px groove rgb(243,243,243);\n"
"background-color:rgb(245,245,245);"));
        lineEdit->setFrame(true);
        lineEdit->setCursorPosition(4);
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit->setReadOnly(true);
        lineEdit->setCursorMoveStyle(Qt::VisualMoveStyle);

        verticalLayout->addWidget(lineEdit);

        keyboard = new QGridLayout();
        keyboard->setSpacing(2);
        keyboard->setObjectName(QString::fromUtf8("keyboard"));
        keyboard->setSizeConstraint(QLayout::SetDefaultConstraint);
        keyboard->setContentsMargins(5, 0, 5, -1);
        pushButton_backspace = new QPushButton(layoutWidget);
        pushButton_backspace->setObjectName(QString::fromUtf8("pushButton_backspace"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_backspace->sizePolicy().hasHeightForWidth());
        pushButton_backspace->setSizePolicy(sizePolicy2);
        pushButton_backspace->setMinimumSize(QSize(0, 0));
        pushButton_backspace->setBaseSize(QSize(0, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setWeight(50);
        pushButton_backspace->setFont(font1);
        pushButton_backspace->setFocusPolicy(Qt::StrongFocus);
        pushButton_backspace->setAutoFillBackground(false);
        pushButton_backspace->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"	background-color:rgb(222,222,222);\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(170, 85, 0)\n"
"}"));

        keyboard->addWidget(pushButton_backspace, 3, 0, 1, 1);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy2.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy2);
        pushButton_5->setMinimumSize(QSize(0, 0));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Nirmala UI"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_5->setFont(font2);
        pushButton_5->setFocusPolicy(Qt::StrongFocus);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"    background-color:rgb(243,243,243)\n"
"\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(85, 255, 0)\n"
"}"));

        keyboard->addWidget(pushButton_5, 4, 2, 1, 1);

        pushButton_0 = new QPushButton(layoutWidget);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setEnabled(true);
        sizePolicy2.setHeightForWidth(pushButton_0->sizePolicy().hasHeightForWidth());
        pushButton_0->setSizePolicy(sizePolicy2);
        pushButton_0->setMinimumSize(QSize(0, 0));
        pushButton_0->setFont(font2);
        pushButton_0->setFocusPolicy(Qt::StrongFocus);
        pushButton_0->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"    background-color:rgb(243,243,243)\n"
"\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(255, 170, 127);\n"
"}"));

        keyboard->addWidget(pushButton_0, 7, 2, 1, 1);

        pushButton_e = new QPushButton(layoutWidget);
        pushButton_e->setObjectName(QString::fromUtf8("pushButton_e"));
        sizePolicy2.setHeightForWidth(pushButton_e->sizePolicy().hasHeightForWidth());
        pushButton_e->setSizePolicy(sizePolicy2);
        pushButton_e->setMinimumSize(QSize(0, 0));
        pushButton_e->setBaseSize(QSize(0, 0));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setUnderline(false);
        font3.setWeight(50);
        font3.setStrikeOut(false);
        pushButton_e->setFont(font3);
        pushButton_e->setFocusPolicy(Qt::StrongFocus);
        pushButton_e->setAutoFillBackground(false);
        pushButton_e->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"	background-color:rgb(222,222,222);\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(200, 150, 255)\n"
"}"));

        keyboard->addWidget(pushButton_e, 7, 0, 1, 1);

        pushButton_ClosingParenthesis = new QPushButton(layoutWidget);
        pushButton_ClosingParenthesis->setObjectName(QString::fromUtf8("pushButton_ClosingParenthesis"));
        sizePolicy2.setHeightForWidth(pushButton_ClosingParenthesis->sizePolicy().hasHeightForWidth());
        pushButton_ClosingParenthesis->setSizePolicy(sizePolicy2);
        pushButton_ClosingParenthesis->setMinimumSize(QSize(0, 0));
        pushButton_ClosingParenthesis->setBaseSize(QSize(0, 0));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(11);
        font4.setBold(false);
        font4.setWeight(50);
        pushButton_ClosingParenthesis->setFont(font4);
        pushButton_ClosingParenthesis->setFocusPolicy(Qt::StrongFocus);
        pushButton_ClosingParenthesis->setAutoFillBackground(false);
        pushButton_ClosingParenthesis->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"	background-color:rgb(222,222,222);\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(85, 85, 127)\n"
"}"));

        keyboard->addWidget(pushButton_ClosingParenthesis, 1, 2, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy2.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy2);
        pushButton_2->setMinimumSize(QSize(0, 0));
        pushButton_2->setFont(font2);
        pushButton_2->setFocusPolicy(Qt::StrongFocus);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"    background-color:rgb(243,243,243)\n"
"\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(255, 85, 0)\n"
"}"));

        keyboard->addWidget(pushButton_2, 6, 2, 1, 1);

        pushButton_addition = new QPushButton(layoutWidget);
        pushButton_addition->setObjectName(QString::fromUtf8("pushButton_addition"));
        sizePolicy2.setHeightForWidth(pushButton_addition->sizePolicy().hasHeightForWidth());
        pushButton_addition->setSizePolicy(sizePolicy2);
        pushButton_addition->setMinimumSize(QSize(0, 0));
        pushButton_addition->setBaseSize(QSize(0, 0));
        pushButton_addition->setFont(font4);
        pushButton_addition->setFocusPolicy(Qt::StrongFocus);
        pushButton_addition->setAutoFillBackground(false);
        pushButton_addition->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"	background-color:rgb(222,222,222);\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(0, 233, 254)\n"
"}"));

        keyboard->addWidget(pushButton_addition, 4, 4, 1, 1);

        pushButton_z8 = new QPushButton(layoutWidget);
        pushButton_z8->setObjectName(QString::fromUtf8("pushButton_z8"));
        sizePolicy2.setHeightForWidth(pushButton_z8->sizePolicy().hasHeightForWidth());
        pushButton_z8->setSizePolicy(sizePolicy2);
        pushButton_z8->setMinimumSize(QSize(0, 0));
        pushButton_z8->setBaseSize(QSize(0, 0));
        pushButton_z8->setFont(font3);
        pushButton_z8->setFocusPolicy(Qt::StrongFocus);
        pushButton_z8->setAutoFillBackground(false);
        pushButton_z8->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"	background-color:rgb(222,222,222);\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(85, 0, 127)\n"
"}"));

        keyboard->addWidget(pushButton_z8, 8, 3, 1, 1);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy2.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy2);
        pushButton_3->setMinimumSize(QSize(0, 0));
        pushButton_3->setFont(font2);
        pushButton_3->setFocusPolicy(Qt::StrongFocus);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"    background-color:rgb(243,243,243)\n"
"\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(255, 0, 127)\n"
"}"));

        keyboard->addWidget(pushButton_3, 6, 3, 1, 1);

        pushButton_percent = new QPushButton(layoutWidget);
        pushButton_percent->setObjectName(QString::fromUtf8("pushButton_percent"));
        sizePolicy2.setHeightForWidth(pushButton_percent->sizePolicy().hasHeightForWidth());
        pushButton_percent->setSizePolicy(sizePolicy2);
        pushButton_percent->setMinimumSize(QSize(0, 0));
        pushButton_percent->setBaseSize(QSize(0, 0));
        pushButton_percent->setFont(font4);
        pushButton_percent->setFocusPolicy(Qt::StrongFocus);
        pushButton_percent->setAutoFillBackground(false);
        pushButton_percent->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"	background-color:rgb(222,222,222);\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(255, 26, 225)\n"
"}"));

        keyboard->addWidget(pushButton_percent, 7, 1, 1, 1);

        pushButton_9 = new QPushButton(layoutWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        sizePolicy2.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy2);
        pushButton_9->setMinimumSize(QSize(0, 0));
        pushButton_9->setFont(font2);
        pushButton_9->setFocusPolicy(Qt::StrongFocus);
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"    background-color:rgb(243,243,243)\n"
"\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(255, 85, 255)\n"
"}"));

        keyboard->addWidget(pushButton_9, 3, 3, 1, 1);

        pushButton_z4 = new QPushButton(layoutWidget);
        pushButton_z4->setObjectName(QString::fromUtf8("pushButton_z4"));
        sizePolicy2.setHeightForWidth(pushButton_z4->sizePolicy().hasHeightForWidth());
        pushButton_z4->setSizePolicy(sizePolicy2);
        pushButton_z4->setMinimumSize(QSize(0, 0));
        pushButton_z4->setBaseSize(QSize(0, 0));
        pushButton_z4->setFont(font3);
        pushButton_z4->setFocusPolicy(Qt::StrongFocus);
        pushButton_z4->setAutoFillBackground(false);
        pushButton_z4->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"	background-color:rgb(222,222,222);\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(0, 170, 127)\n"
"}"));

        keyboard->addWidget(pushButton_z4, 8, 2, 1, 1);

        pushButton_8 = new QPushButton(layoutWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        sizePolicy2.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy2);
        pushButton_8->setMinimumSize(QSize(0, 0));
        pushButton_8->setFont(font2);
        pushButton_8->setFocusPolicy(Qt::StrongFocus);
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"    background-color:rgb(243,243,243)\n"
"\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(85, 255, 255);\n"
"}"));

        keyboard->addWidget(pushButton_8, 3, 2, 1, 1);

        pushButton_multiplication = new QPushButton(layoutWidget);
        pushButton_multiplication->setObjectName(QString::fromUtf8("pushButton_multiplication"));
        sizePolicy2.setHeightForWidth(pushButton_multiplication->sizePolicy().hasHeightForWidth());
        pushButton_multiplication->setSizePolicy(sizePolicy2);
        pushButton_multiplication->setMinimumSize(QSize(0, 0));
        pushButton_multiplication->setBaseSize(QSize(0, 0));
        pushButton_multiplication->setFont(font4);
        pushButton_multiplication->setFocusPolicy(Qt::StrongFocus);
        pushButton_multiplication->setAutoFillBackground(false);
        pushButton_multiplication->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"	background-color:rgb(222,222,222);\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(25, 125, 25)\n"
"}"));

        keyboard->addWidget(pushButton_multiplication, 3, 4, 1, 1);

        pushButton_dot = new QPushButton(layoutWidget);
        pushButton_dot->setObjectName(QString::fromUtf8("pushButton_dot"));
        sizePolicy2.setHeightForWidth(pushButton_dot->sizePolicy().hasHeightForWidth());
        pushButton_dot->setSizePolicy(sizePolicy2);
        pushButton_dot->setMinimumSize(QSize(0, 0));
        pushButton_dot->setBaseSize(QSize(0, 0));
        pushButton_dot->setFont(font4);
        pushButton_dot->setFocusPolicy(Qt::StrongFocus);
        pushButton_dot->setAutoFillBackground(false);
        pushButton_dot->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"	background-color:rgb(222,222,222);\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(25, 255, 215)\n"
"}"));

        keyboard->addWidget(pushButton_dot, 7, 3, 1, 1);

        pushButton_pow = new QPushButton(layoutWidget);
        pushButton_pow->setObjectName(QString::fromUtf8("pushButton_pow"));
        sizePolicy2.setHeightForWidth(pushButton_pow->sizePolicy().hasHeightForWidth());
        pushButton_pow->setSizePolicy(sizePolicy2);
        pushButton_pow->setMinimumSize(QSize(0, 0));
        pushButton_pow->setBaseSize(QSize(0, 0));
        pushButton_pow->setFont(font4);
        pushButton_pow->setFocusPolicy(Qt::StrongFocus);
        pushButton_pow->setAutoFillBackground(false);
        pushButton_pow->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"	background-color:rgb(222,222,222);\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(255, 0, 127)\n"
"}"));

        keyboard->addWidget(pushButton_pow, 1, 3, 1, 1);

        pushButton_division = new QPushButton(layoutWidget);
        pushButton_division->setObjectName(QString::fromUtf8("pushButton_division"));
        sizePolicy2.setHeightForWidth(pushButton_division->sizePolicy().hasHeightForWidth());
        pushButton_division->setSizePolicy(sizePolicy2);
        pushButton_division->setMinimumSize(QSize(0, 0));
        pushButton_division->setBaseSize(QSize(0, 0));
        pushButton_division->setFont(font4);
        pushButton_division->setFocusPolicy(Qt::StrongFocus);
        pushButton_division->setAutoFillBackground(false);
        pushButton_division->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"	background-color:rgb(222,222,222);\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(85, 170, 0)\n"
"}"));

        keyboard->addWidget(pushButton_division, 1, 4, 1, 1);

        pushButton_equal = new QPushButton(layoutWidget);
        pushButton_equal->setObjectName(QString::fromUtf8("pushButton_equal"));
        sizePolicy2.setHeightForWidth(pushButton_equal->sizePolicy().hasHeightForWidth());
        pushButton_equal->setSizePolicy(sizePolicy2);
        pushButton_equal->setMinimumSize(QSize(0, 0));
        pushButton_equal->setBaseSize(QSize(0, 0));
        pushButton_equal->setFont(font4);
        pushButton_equal->setFocusPolicy(Qt::StrongFocus);
        pushButton_equal->setAutoFillBackground(false);
        pushButton_equal->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"	background-color:rgb(222,222,222);\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(170, 255, 0)\n"
"}"));

        keyboard->addWidget(pushButton_equal, 7, 4, 1, 1);

        pushButton_1 = new QPushButton(layoutWidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        sizePolicy2.setHeightForWidth(pushButton_1->sizePolicy().hasHeightForWidth());
        pushButton_1->setSizePolicy(sizePolicy2);
        pushButton_1->setMinimumSize(QSize(0, 0));
        pushButton_1->setFont(font2);
        pushButton_1->setFocusPolicy(Qt::StrongFocus);
        pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"    background-color:rgb(243,243,243)\n"
"\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(170, 170, 127)\n"
"}"));

        keyboard->addWidget(pushButton_1, 6, 1, 1, 1);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy2.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy2);
        pushButton_6->setMinimumSize(QSize(0, 0));
        pushButton_6->setFont(font2);
        pushButton_6->setFocusPolicy(Qt::StrongFocus);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"    background-color:rgb(243,243,243)\n"
"\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(255, 255, 0)\n"
"}"));

        keyboard->addWidget(pushButton_6, 4, 3, 1, 1);

        pushButton_p = new QPushButton(layoutWidget);
        pushButton_p->setObjectName(QString::fromUtf8("pushButton_p"));
        sizePolicy2.setHeightForWidth(pushButton_p->sizePolicy().hasHeightForWidth());
        pushButton_p->setSizePolicy(sizePolicy2);
        pushButton_p->setMinimumSize(QSize(0, 0));
        pushButton_p->setBaseSize(QSize(0, 0));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Roboto Black"));
        font5.setPointSize(10);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setUnderline(false);
        font5.setWeight(50);
        font5.setStrikeOut(false);
        pushButton_p->setFont(font5);
        pushButton_p->setFocusPolicy(Qt::StrongFocus);
        pushButton_p->setAutoFillBackground(false);
        pushButton_p->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"	background-color:rgb(222,222,222);\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(255, 255, 127)\n"
"}"));

        keyboard->addWidget(pushButton_p, 8, 0, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy2.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy2);
        pushButton_4->setMinimumSize(QSize(0, 0));
        pushButton_4->setFont(font2);
        pushButton_4->setFocusPolicy(Qt::StrongFocus);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"    background-color:rgb(243,243,243)\n"
"\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(0, 170, 255)\n"
"}"));

        keyboard->addWidget(pushButton_4, 4, 1, 1, 1);

        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        sizePolicy2.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy2);
        pushButton_7->setMinimumSize(QSize(0, 0));
        pushButton_7->setFont(font2);
        pushButton_7->setFocusPolicy(Qt::ClickFocus);
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"    background-color:rgb(243,243,243)\n"
"\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(170, 170, 255);\n"
"}"));

        keyboard->addWidget(pushButton_7, 3, 1, 1, 1);

        pushButton_root = new QPushButton(layoutWidget);
        pushButton_root->setObjectName(QString::fromUtf8("pushButton_root"));
        sizePolicy2.setHeightForWidth(pushButton_root->sizePolicy().hasHeightForWidth());
        pushButton_root->setSizePolicy(sizePolicy2);
        pushButton_root->setMinimumSize(QSize(0, 0));
        pushButton_root->setBaseSize(QSize(0, 0));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Segoe UI"));
        font6.setPointSize(11);
        font6.setBold(false);
        font6.setUnderline(false);
        font6.setWeight(50);
        pushButton_root->setFont(font6);
        pushButton_root->setFocusPolicy(Qt::StrongFocus);
        pushButton_root->setAutoFillBackground(false);
        pushButton_root->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"	background-color:rgb(222,222,222);\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(0, 85, 127)\n"
"}"));

        keyboard->addWidget(pushButton_root, 4, 0, 1, 1);

        pushButton_subtraction = new QPushButton(layoutWidget);
        pushButton_subtraction->setObjectName(QString::fromUtf8("pushButton_subtraction"));
        sizePolicy2.setHeightForWidth(pushButton_subtraction->sizePolicy().hasHeightForWidth());
        pushButton_subtraction->setSizePolicy(sizePolicy2);
        pushButton_subtraction->setMinimumSize(QSize(0, 0));
        pushButton_subtraction->setBaseSize(QSize(0, 0));
        pushButton_subtraction->setFont(font4);
        pushButton_subtraction->setFocusPolicy(Qt::StrongFocus);
        pushButton_subtraction->setAutoFillBackground(false);
        pushButton_subtraction->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"	background-color:rgb(222,222,222);\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(255, 26, 29)\n"
"}"));

        keyboard->addWidget(pushButton_subtraction, 6, 4, 1, 1);

        pushButton_clear = new QPushButton(layoutWidget);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        sizePolicy2.setHeightForWidth(pushButton_clear->sizePolicy().hasHeightForWidth());
        pushButton_clear->setSizePolicy(sizePolicy2);
        pushButton_clear->setMinimumSize(QSize(0, 0));
        pushButton_clear->setBaseSize(QSize(0, 0));
        pushButton_clear->setFont(font1);
        pushButton_clear->setFocusPolicy(Qt::StrongFocus);
        pushButton_clear->setAutoFillBackground(false);
        pushButton_clear->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"	background-color:rgb(222,222,222);\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(85, 0, 255)\n"
"}"));

        keyboard->addWidget(pushButton_clear, 1, 0, 1, 1);

        pushButton_z2 = new QPushButton(layoutWidget);
        pushButton_z2->setObjectName(QString::fromUtf8("pushButton_z2"));
        sizePolicy2.setHeightForWidth(pushButton_z2->sizePolicy().hasHeightForWidth());
        pushButton_z2->setSizePolicy(sizePolicy2);
        pushButton_z2->setMinimumSize(QSize(0, 0));
        pushButton_z2->setBaseSize(QSize(0, 0));
        pushButton_z2->setFont(font3);
        pushButton_z2->setFocusPolicy(Qt::StrongFocus);
        pushButton_z2->setAutoFillBackground(false);
        pushButton_z2->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"	background-color:rgb(222,222,222);\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(255, 0, 0)\n"
"}"));

        keyboard->addWidget(pushButton_z2, 8, 1, 1, 1);

        pushButton_LeftParenthesis = new QPushButton(layoutWidget);
        pushButton_LeftParenthesis->setObjectName(QString::fromUtf8("pushButton_LeftParenthesis"));
        sizePolicy2.setHeightForWidth(pushButton_LeftParenthesis->sizePolicy().hasHeightForWidth());
        pushButton_LeftParenthesis->setSizePolicy(sizePolicy2);
        pushButton_LeftParenthesis->setMinimumSize(QSize(0, 0));
        pushButton_LeftParenthesis->setBaseSize(QSize(0, 0));
        QFont font7;
        font7.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font7.setPointSize(10);
        font7.setBold(false);
        font7.setWeight(50);
        pushButton_LeftParenthesis->setFont(font7);
        pushButton_LeftParenthesis->setFocusPolicy(Qt::StrongFocus);
        pushButton_LeftParenthesis->setAutoFillBackground(false);
        pushButton_LeftParenthesis->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"	background-color:rgb(222,222,222);\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(255, 0, 255)\n"
"}"));

        keyboard->addWidget(pushButton_LeftParenthesis, 1, 1, 1, 1);

        pushButton_fraction = new QPushButton(layoutWidget);
        pushButton_fraction->setObjectName(QString::fromUtf8("pushButton_fraction"));
        sizePolicy2.setHeightForWidth(pushButton_fraction->sizePolicy().hasHeightForWidth());
        pushButton_fraction->setSizePolicy(sizePolicy2);
        pushButton_fraction->setMinimumSize(QSize(0, 0));
        pushButton_fraction->setBaseSize(QSize(0, 0));
        QFont font8;
        font8.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font8.setPointSize(10);
        font8.setBold(false);
        font8.setUnderline(false);
        font8.setWeight(50);
        pushButton_fraction->setFont(font8);
        pushButton_fraction->setFocusPolicy(Qt::StrongFocus);
        pushButton_fraction->setAutoFillBackground(false);
        pushButton_fraction->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"	background-color:rgb(222,222,222);\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(60, 85, 127)\n"
"}"));

        keyboard->addWidget(pushButton_fraction, 6, 0, 1, 1);

        pushButton_z16 = new QPushButton(layoutWidget);
        pushButton_z16->setObjectName(QString::fromUtf8("pushButton_z16"));
        sizePolicy2.setHeightForWidth(pushButton_z16->sizePolicy().hasHeightForWidth());
        pushButton_z16->setSizePolicy(sizePolicy2);
        pushButton_z16->setMinimumSize(QSize(0, 0));
        pushButton_z16->setBaseSize(QSize(0, 0));
        pushButton_z16->setFont(font3);
        pushButton_z16->setFocusPolicy(Qt::StrongFocus);
        pushButton_z16->setAutoFillBackground(false);
        pushButton_z16->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:1px groove rgb(220,220,220);\n"
"	background-color:rgb(222,222,222);\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color:rgb(85, 85, 255)\n"
"}"));

        keyboard->addWidget(pushButton_z16, 8, 4, 1, 1);


        verticalLayout->addLayout(keyboard);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\350\256\241\347\256\227\345\231\250", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        MainWindow->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        lineEdit->setText(QApplication::translate("MainWindow", "0.00", nullptr));
        lineEdit->setPlaceholderText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_backspace->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_backspace->setText(QApplication::translate("MainWindow", "C", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "5", nullptr));
        pushButton_0->setText(QApplication::translate("MainWindow", "0", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_e->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_e->setText(QApplication::translate("MainWindow", "e", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_ClosingParenthesis->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_ClosingParenthesis->setText(QApplication::translate("MainWindow", ")", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "2", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_addition->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_addition->setText(QApplication::translate("MainWindow", "+", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_z8->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_z8->setText(QApplication::translate("MainWindow", "\350\275\2548\350\277\233\345\210\266", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "3", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_percent->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_percent->setText(QApplication::translate("MainWindow", "%", nullptr));
        pushButton_9->setText(QApplication::translate("MainWindow", "9", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_z4->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_z4->setText(QApplication::translate("MainWindow", "\350\275\2544\350\277\233\345\210\266", nullptr));
        pushButton_8->setText(QApplication::translate("MainWindow", "8", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_multiplication->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_multiplication->setText(QApplication::translate("MainWindow", "\303\227", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_dot->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_dot->setText(QApplication::translate("MainWindow", ".", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_pow->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_pow->setText(QApplication::translate("MainWindow", "^", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_division->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_division->setText(QApplication::translate("MainWindow", "/", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_equal->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_equal->setText(QApplication::translate("MainWindow", "=", nullptr));
        pushButton_1->setText(QApplication::translate("MainWindow", "1", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "6", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_p->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_p->setText(QApplication::translate("MainWindow", "\317\200", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "4", nullptr));
        pushButton_7->setText(QApplication::translate("MainWindow", "7", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_root->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_root->setText(QApplication::translate("MainWindow", "\342\210\232", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_subtraction->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_subtraction->setText(QApplication::translate("MainWindow", "-", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_clear->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_clear->setText(QApplication::translate("MainWindow", "AC", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_z2->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_z2->setText(QApplication::translate("MainWindow", "\350\275\2542\350\277\233\345\210\266", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_LeftParenthesis->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_LeftParenthesis->setText(QApplication::translate("MainWindow", "(", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_fraction->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_fraction->setText(QApplication::translate("MainWindow", "1/x", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_z16->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_z16->setText(QApplication::translate("MainWindow", "\350\275\25416\350\277\233\345\210\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
