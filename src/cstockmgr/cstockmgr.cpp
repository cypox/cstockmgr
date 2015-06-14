#include "main_window.hpp"

#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication main_application(argc, argv);
    MainWindow w;
    w.show();
    return main_application.exec();
}
