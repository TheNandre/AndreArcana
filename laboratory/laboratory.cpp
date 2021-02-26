#include "laboratory.h"

#include <QTest>
#include <QTimer>
#include <QAbstractButton>
#include <QSignalSpy>

#include "grimoire.h"
#include "cover.h"
#include "misfire.h"

Laboratory::Laboratory()
{

}

void Laboratory::initTestCase()
{
    this->grimoire_ = new Grimoire{};

    QVERIFY2( this->grimoire_ != nullptr, "Grimoire is initialized" );

    this->grimoire_->showMaximized();

    QVERIFY2( this->grimoire_->isMaximized(), "Window is Maximized" );
}

void Laboratory::coverTest()
{
    auto bSuccess{ false };
    auto coverDialog = this->grimoire_->findChild<Cover*>( "frontCover" );
    if( coverDialog != nullptr ) {
        QSignalSpy deleteSpy{ coverDialog, &QObject::destroyed };
        auto okButton = coverDialog->button( QMessageBox::StandardButton::Ok );
        if( okButton != nullptr ) {
            okButton->animateClick();
            QTest::qWait( 2000 );
            if( deleteSpy.count() > 0 ) {
                bSuccess = true;
            }
        }
    }

    QVERIFY2( bSuccess, "Front Cover is pressed" );
}

void Laboratory::misfireTest()
{
    Misfire misfire{ "Test" };
    this->grimoire_->onMisfire( misfire );
}

void Laboratory::cleanupTestCase()
{

}
