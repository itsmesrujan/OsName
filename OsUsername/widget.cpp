#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent, QString szUsername) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    if (!szUsername.isEmpty())
        showUsername(szUsername);
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showUsername(QString szUsername)
{
    qDebug() << "szUsername: " << szUsername << endl;
    QString szLbl = szUsername;
    szLbl.prepend("Hi ");

    QGridLayout *userNameGLayout = new QGridLayout(this);
    userNameGLayout->setAlignment(Qt::AlignCenter|Qt::AlignHCenter|Qt::AlignVCenter);
    QLabel *userNameLbl = new QLabel(this);
    userNameLbl->setText(szLbl);
    userNameGLayout->addWidget(userNameLbl);
    this->setLayout(userNameGLayout);
}
