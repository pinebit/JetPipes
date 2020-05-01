#ifndef TUBEGENERATOR_HPP
#define TUBEGENERATOR_HPP

#include <QObject>
#include <TubeGeometry.hpp>
#include <QVector3D>

class TubeGenerator : public QObject
{
    Q_OBJECT

public:
    explicit TubeGenerator(QObject *parent = nullptr);

public slots:
    void next(TubeGeometry *geometry);

private:
    QVector<QVector3D> _path;
};

Q_DECLARE_METATYPE(TubeGenerator*);

#endif // TUBEGENERATOR_HPP
