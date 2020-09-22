#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_play_clicked()
{
    QMessageBox::information(this, "Thông báo", "Chào Thế giới");
}

void MainWindow::on_bai1_clicked()
{

}

void MainWindow::on_bai2_clicked()
{

}

void MainWindow::on_bai3_clicked()
{

}

void MainWindow::on_bai4_clicked()
{

}
