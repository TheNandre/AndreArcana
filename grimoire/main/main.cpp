#include <QApplication>
#include "../src/grimoire.h"

int main( int argc, char* argv[] )
{
    QApplication a{ argc, argv };

    Grimoire g;
    g.showMaximized();

    return a.exec();
}
