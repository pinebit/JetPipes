#include "ObstaclesModel.hpp"
#include "Config.hpp"

void ObstaclesModel::add(const QVector3D &vertex)
{
    _obstacles.append(vertex);
}

void ObstaclesModel::clear()
{
    _obstacles.clear();
}

bool ObstaclesModel::test(const QVector3D &vertex)
{
    const auto limit = Config::TubeRadius * 2.0 + Config::TubesGap;

    for (const auto &o : _obstacles) {
        if (limit > o.distanceToPoint(vertex)) {
            return false;
        }
    }

    return true;
}
