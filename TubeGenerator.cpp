#include "TubeGenerator.hpp"
#include <QRandomGenerator>

TubeGenerator::TubeGenerator(QObject *parent)
    : QObject(parent)
{
    qRegisterMetaType<TubeGeometry*>("TubeGeometry*");
}

void TubeGenerator::next(TubeGeometry *geometry)
{
    Q_ASSERT(geometry);

    if (_path.isEmpty()) {
        _path.append(QVector3D(0, 0, 0));
    }

    auto x = QRandomGenerator::global()->bounded(-50, 50);
    auto y = QRandomGenerator::global()->bounded(-50, 50);
    auto z = QRandomGenerator::global()->bounded(-50, 50);
    _path.append(QVector3D(x, y, z));

    geometry->update(_path);
}
