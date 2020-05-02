#include "Scene.hpp"
#include <QDebug>

Scene::Scene(QObject *parent)
    : QObject(parent)
{
    qRegisterMetaType<QList<TubeGeometry*>>("QList<TubeGeometry*>");
    _obstaclesModel = QSharedPointer<ObstaclesModel>::create(TubeRadius, TubesGap);
}

bool Scene::advance()
{
    qDebug() << Q_FUNC_INFO << _tubes.size();

    if (_tubes.size() >= MaxTubes) {
        return false;
    }

    while (_tubes.size() < MinTubes) {
        auto tube = TubeModel::create(SceneRadius, _obstaclesModel);
        if (!tube || !tube->advance()) {
            return false;
        }
        _tubes << tube;
        _geometries << TubeGeometry::create(tube->points(), TubeRadius);
    }

    bool ok = false;
    int index = 0;
    for (auto tube : _tubes) {
        if (tube->advance()) {
            _geometries[index] = TubeGeometry::create(tube->points(), TubeRadius);
            ok = true;
        } else {
            qDebug() << "could not advance tube" << index;
        }
        index++;
    }

    emit updated(_geometries.size());
    return ok;
}

void Scene::clear()
{
    qDebug() << Q_FUNC_INFO;

    while (!_tubes.isEmpty()) {
        delete _tubes.takeLast();
    }

    _geometries.clear();

    emit updated(0);
}

TubeGeometry *Scene::getTubeGeometry(int index) const
{
    return _geometries.value(index, nullptr);
}
