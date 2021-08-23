#include "mainwindow.h"
#include <QGraphicsBlurEffect>
#include <QApplication>

//ТОП 10 БЕСПОЛЕЗНЫХ ПРИЛОЖЕНИЙ @Гриша

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(318, 498);
    w.setWindowTitle("Калькулятор");
    w.setWindowIcon(QIcon("C:/Users/nikli/Documents/Calculator/index.png"));
    w.show();
    return a.exec();
}
