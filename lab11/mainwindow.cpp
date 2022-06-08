#include "mainwindow.h"
#include "./ui_mainwindow.h"
#define OUTPUT_PATH "/Users/cyber/university_c++/output.txt"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
//    delete filepath;
}

void MainWindow::on_pushButton_clicked()
{
    filepath = "";
    readFileToBuffer();
    printBuffer();
    ui->label->setText(filepath);
}

void MainWindow::on_pushButton_2_clicked()
{
    readFileToBuffer();
    loadBuffer();
    if (buffer != "") {
        buffer.replace("\n", "!\n");
        buffer.replace('\0', "!\0");
    }
    printBuffer();
    saveBufferToOUTPUT_PATH();
}


void MainWindow::on_pushButton_3_clicked()
{
    loadBuffer();
    saveBufferToOUTPUT_PATH();
}

int MainWindow::saveBufferToOUTPUT_PATH() {
    buffer.toUtf8();

    int result = 0;
    QFile file(OUTPUT_PATH);
    if(file.open(QIODevice::WriteOnly | QFile::Text)){
        setWindowTitle(OUTPUT_PATH);
        QTextStream fileStream(&file);
//        QMessageBox::warning(this, "Waarning", buffer);
        fileStream << buffer;
        result = 1;
        ui->label->setText(OUTPUT_PATH);
        file.close();
    } else {
        QMessageBox::warning(this, "Waarning", "Cannot save to file");
    }

    return result;
}

void MainWindow::printBuffer() {
    ui->plainTextEdit->setPlainText(buffer);
}

void MainWindow::loadBuffer() {
    buffer = ui->plainTextEdit->toPlainText();
}

int MainWindow::readFileToBuffer(){
    int result = 0;
    if (filepath == "") {
        filepath = QFileDialog::getOpenFileName();
    }
    QFile file(filepath);
    if(file.open(QFile::ReadOnly | QFile::Text)){
        QByteArray data;
        data = file.readAll();
        buffer = QString(data);
    } else {
        buffer = "";
        QMessageBox::warning(this, "Waarning", "Cannot read file");
    }
    return result;
}
