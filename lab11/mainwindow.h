#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString filepath = "";
    QString buffer = "";
    void setBuffer();
    int saveBufferToOUTPUT_PATH();
    void printBuffer();
    int readFileToBuffer();
    void loadBuffer();
//    bool isFileLoaded = false;

};
#endif // MAINWINDOW_H
