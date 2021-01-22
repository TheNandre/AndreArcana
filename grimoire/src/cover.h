#ifndef COVER_H
#define COVER_H

#include <QMessageBox>
#include <QPointer>

class Cover : public QMessageBox
{
    Q_OBJECT
public:
    Cover( QPointer<QWidget> parent = nullptr );
    virtual ~Cover() override = default;
};

#endif // COVER_H
