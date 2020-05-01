#include "ObstaclesModel.hpp"

ObstaclesModel::ObstaclesModel(double radius, double gap)
    : _radius(radius)
    , _gap(gap)
{
}

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
    const auto limit = _radius * 2.0 + _gap;

    for (const auto &o : _obstacles) {
        if (limit > o.distanceToPoint(vertex)) {
            return false;
        }
    }

    return true;
}
