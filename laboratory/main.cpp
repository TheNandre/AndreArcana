#include <QApplication>
#include <QTest>
#include "laboratory.h"

int main( int argc, char* argv[] )
{
    QApplication a{ argc, argv };

    Laboratory lab{};

    return QTest::qExec( &lab, argc, argv );
}
