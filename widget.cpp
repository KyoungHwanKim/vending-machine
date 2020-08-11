#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <string.h>

using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::change_money(int diff) {
    Widget::money += diff;
    ui->lcdNumber->display(Widget::money);

    if (Widget::money >= 100) ui->pbCoffee->setEnabled(true);
    else ui->pbCoffee->setEnabled(false);

    if (Widget::money >= 150) ui->pbTea->setEnabled(true);
    else ui->pbTea->setEnabled(false);

    if (Widget::money >= 200) ui->pbMilk->setEnabled(true);
    else ui->pbMilk->setEnabled(false);
}

void Widget::on_pb10_clicked() {
    change_money(10);
}

void Widget::on_pb50_clicked() {
    change_money(50);
}

void Widget::on_pb100_clicked() {
    change_money(100);
}

void Widget::on_pb500_clicked() {
    change_money(500);
}

void Widget::on_pbCoffee_clicked() {
    change_money(-100);
}

void Widget::on_pbTea_clicked() {
    change_money(-150);
}

void Widget::on_pbMilk_clicked() {
    change_money(-200);
}


void Widget::on_pbReset_clicked() {
    QMessageBox m;
    QString result = "";
    int table[4] = {500, 100, 50, 10};
    int cursor = 0;
    int cnt[4] = {0, 0, 0, 0};
    while (Widget::money) {
        if (Widget::money < table[cursor]) {
            cursor++;
        } else {
            cnt[cursor]++;
            Widget::money -= table[cursor];
        }
    }
    result.append(QString::fromStdString("10원 : " + to_string(cnt[3]) + "\n"));
    result.append(QString::fromStdString("50원 : " + to_string(cnt[2]) + "\n"));
    result.append(QString::fromStdString("100원 : " + to_string(cnt[1]) + "\n"));
    result.append(QString::fromStdString("500원 : " + to_string(cnt[0]) + "\n"));
    m.information(nullptr, "Result", result);
    Widget::change_money(-Widget::money);
}
