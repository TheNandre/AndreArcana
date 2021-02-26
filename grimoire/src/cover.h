#ifndef COVER_H
#define COVER_H

#include <QMessageBox>
#include <QPointer>

#ifdef BUILD_LAB
#include "grimoire_global.h"
class GRIMOIRE_EXPORT Cover : public QMessageBox
#else
class Cover : public QMessageBox
#endif
{
    Q_OBJECT
public:
    Cover( QPointer<QWidget> parent = nullptr );
    virtual ~Cover() override = default;
};

#endif // COVER_H
