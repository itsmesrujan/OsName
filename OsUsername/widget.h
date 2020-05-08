#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <iostream>
using namespace std;

#if defined(Q_OS_WIN)
#include <windows.h>
#include <Lmcons.h>
#elif defined(Q_OS_LINUX)
#define CHARLENGTH 256
#endif

#include <QLabel>
#include <QGridLayout>
#include <QDebug>

#include "apputils.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr, QString szUsername = QString(""));
    ~Widget();

private:
    Ui::Widget *ui;
    void showUsername(QString szUsername);
};

#endif // WIDGET_H
