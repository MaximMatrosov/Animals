#include "widget.h"
#include "ui_widget.h"
#include "cat.h"
#include <QDateTime>
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <sstream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->groupBox->hide();
    ui->groupBox_3->hide();
}

list<Cat> readFromBase()
{
        list<Cat> Cats;
        ifstream File;
        File.open("cats.txt", ios::in);
        string Record;
        while (getline(File, Record))
        {
            istringstream Rec(Record);
            Cat cat;
            string member;
            vector<string> members;
            while(getline(Rec,member,','))
            {
                members.push_back(member);
            }
            cat.Moniker = members[0];
            cat.BirthYear = QDate::fromString(QString::fromStdString(members[1]),"dd.MM.yyyy");
            cat.Color = members[2];
            Cats.push_back(cat);
        }
        return Cats;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_3_clicked()
{
    QApplication::quit();
}

void Widget::on_pushButton_clicked()
{
    ui->groupBox->show();
    ui->groupBox_2->hide();
}

void Widget::on_pushButton_4_clicked()
{
    string moniker = ui->lineEdit->text().toLocal8Bit().constData();
    QDate year = ui->dateEdit->date();
    string color = ui->lineEdit_3->text().toLocal8Bit().constData();

    if(moniker.empty() || year.isNull() || color.empty())
    {
        QMessageBox::information(0, "Ошибка", "Одно из полей пустое или содержит некорректные данные!");

    }
    else{
    Cat cat;
    cat.BirthYear = year;
    cat.Color = color;
    cat.Moniker = moniker;
    bool success = cat.writeToBase();

    if(success){
        ui->lineEdit->clear();
        ui->lineEdit_3->clear();
        ui->dateEdit->setDate(QDate(2000,1,1));
        QMessageBox::information(0, "Информация", "Запись успешно добавлена!");
    }
    else{
        QMessageBox::information(0, "Ошибка", "Во время записи в базу произошла ошибка!");
    }
    }
}

void Widget::on_pushButton_5_clicked()
{
    ui->groupBox->hide();
    ui->groupBox_2->show();
}

void Widget::on_pushButton_2_clicked()
{
    ui->groupBox_3->show();
    ui->groupBox_2->hide();
    list<Cat> CatsArray = readFromBase();
    foreach(Cat c, CatsArray)
    {
        int lastRow = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(lastRow);
        ui->tableWidget->setItem(lastRow,0,new QTableWidgetItem(QString::fromLocal8Bit(c.Moniker.data())));
        ui->tableWidget->setItem(lastRow,1,new QTableWidgetItem(c.BirthYear.toString("dd.MM.yyyy")));
        ui->tableWidget->setItem(lastRow,2,new QTableWidgetItem(QString::fromLocal8Bit(c.Color.data())));
    }
}

void Widget::on_pushButton_6_clicked()
{
    ui->groupBox_3->hide();
    ui->groupBox_2->show();
}
