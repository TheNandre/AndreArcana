#include "cover.h"

namespace {
    constexpr auto boxTitle = "Open Grimoire";
    constexpr auto boxText = "Open the book.";
}

Cover::Cover( QPointer<QWidget> parent )
    : QMessageBox( parent )
{
    this->setWindowTitle( boxTitle );
    this->setText( boxText );
}

