#include "TubeModel.hpp"
#include "ObstaclesModel.hpp"
#include "Config.hpp"
#include <QRandomGenerator>
#include <QDebug>
#include <math.h>

TubeModel::TubeModel(const QVector<QVector3D> &points,
                     QSharedPointer<ObstaclesModel> obstaclesModel)
    : _obstaclesModel(obstaclesModel)
    , _points(points)
{
}

TubeModel* TubeModel::create(QSharedPointer<ObstaclesModel> obstaclesModel)
{
    int attempts = Config::MaxRandomAttempts;
    while (attempts-- > 0) {
        QVector3D candidate = randomVector(Config::SceneRadius / 5);
        if (obstaclesModel->test(candidate)) {
            obstaclesModel->add(candidate);
            QVector<QVector3D> points = { candidate };
            return new TubeModel(points, obstaclesModel);
        }
    }

    return nullptr;
}

QVector<QVector3D> TubeModel::points() const
{
    return _points;
}

bool TubeModel::advance()
{
    if (_points.size() == Config::MaxTubeLength) {
        return false;
    }

    int attempts = Config::MaxRandomAttempts;
    while (attempts-- > 0) {
        auto lastDirection = _points.last();
        if (_points.size() > 1) {
            lastDirection = lastDirection - _points[_points.size() - 2];
        }
        const auto direction = (lastDirection.normalized() + randomVector(100).normalized() / 2.0).normalized();
        const auto candidate = _points.last() + direction * (Config::TubeRadius * 2.0 + Config::TubesGap);
        if (abs(candidate.x()) > Config::SceneRadius &&
            abs(candidate.y()) > Config::SceneRadius &&
            abs(candidate.z()) > Config::SceneRadius) {
            return false;
        }

        if (_obstaclesModel->test(candidate)) {
            _obstaclesModel->add(candidate);
            _points.append(candidate);
            return true;
        }
    }

    return false;
}

QVector3D TubeModel::randomVector(int bound)
{
    auto gen = QRandomGenerator::global();
    const int x = gen->bounded(-bound, bound);
    const int y = gen->bounded(-bound, bound);
    const int z = gen->bounded(-bound, bound);
    return QVector3D(x, y, z);
}
