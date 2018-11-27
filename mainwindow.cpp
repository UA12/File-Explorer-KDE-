#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDir dir;

    foreach(QFileInfo file, dir.drives()){

        ui->listWidget->addItem(file.absoluteFilePath());

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QString filepath =  item->text();
    ui->listWidget->clear();


    QDir filedir(filepath);

    foreach(QFileInfo file, filedir.entryInfoList()){

        ui->listWidget->addItem(file.absoluteFilePath());

    }
}
