#include "Scene.hpp"
#include "Config.hpp"
#include <QDebug>

Scene::Scene(QObject *parent)
    : QObject(parent)
{
    qRegisterMetaType<TubeGeometry*>("TubeGeometry*");
    _obstaclesModel = QSharedPointer<ObstaclesModel>::create();

    for (int i = 0; i < Config::TubesCount; ++i) {
        _geometries << new TubeGeometry();
    }
}

int Scene::tubesCount() const
{
    return Config::TubesCount;
}

void Scene::init()
{
    while (_tubes.size() < Config::TubesCount) {
        auto tube = TubeModel::create(_obstaclesModel);
        if (tube) {
            if (!tube->advance()) {
                delete tube;
                continue;
            }

            _tubes << tube;
        }
    }

    for (int i = 0; i < Config::TubesCount; ++i) {
        _geometries[i]->update(_tubes[i]->points());
    }
}

bool Scene::advance()
{
    int stuckCount = 0;
    for (int i = 0; i < _tubes.size(); ++i) {
        if (_tubes[i]->advance()) {
            _geometries[i]->update(_tubes[i]->points());
        } else {
            stuckCount++;
        }
    }

    return stuckCount < Config::TubesCount / 2;
}

void Scene::clear()
{
    while (!_tubes.isEmpty()) {
        delete _tubes.takeLast();
    }

    _geometries.clear();

    _obstaclesModel->clear();
}

TubeGeometry *Scene::getTubeGeometry(int index) const
{
    return _geometries.value(index, nullptr);
}
