#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <calculator.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //重写paintEvent事件，画背景
    void paintEvent(QPaintEvent *);

    int flag = 0;
    bool isValid();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
