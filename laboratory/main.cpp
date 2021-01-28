#include <QApplication>

#include "grimoire.h"
#include "misfire.h"

int main( int argc, char* argv[] )
{
    QApplication a{ argc, argv };

    Grimoire g{};
    g.showMaximized();
    //Misfire misfire{ "Test" };

    return a.exec();
}
