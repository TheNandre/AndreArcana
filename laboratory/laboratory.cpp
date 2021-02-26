#include "laboratory.h"

#include <QTest>
#include <QTimer>
#include <QAbstractButton>
#include <QSignalSpy>

#include "grimoire.h"
#include "cover.h"
#include "scribe.h"

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

void Laboratory::scribeTest()
{
    Scribe::write( ScribeLevel::Debug, "Lab", "This is a Debug Message" );
    Scribe::write( ScribeLevel::Info, "Lab", "This is an Info Message" );
    Scribe::write( ScribeLevel::Warn, "Lab", "This is a Warn Message" );
    Scribe::write( ScribeLevel::Misfire, "Lab", "This is a Misfire Message" );
}

void Laboratory::cleanupTestCase()
{

}
