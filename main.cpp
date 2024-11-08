#include "dicegame.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DiceGame w;
    w.show();
    return a.exec();
}
