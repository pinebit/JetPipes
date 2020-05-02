#include "TubeModel.hpp"
#include "ObstaclesModel.hpp"
#include <QRandomGenerator>
#include <QDebug>

TubeModel::TubeModel(const QVector<QVector3D> &points,
                     int sceneRadius,
                     QSharedPointer<ObstaclesModel> obstaclesModel)
    : _sceneRadius(sceneRadius)
    , _obstaclesModel(obstaclesModel)
    , _points(points)
{
}

TubeModel* TubeModel::create(int sceneRadius,
                             QSharedPointer<ObstaclesModel> obstaclesModel)
{
    int attempts = MaxAttempts;
    while (attempts-- > 0) {
        QVector3D candidate = randomVector(sceneRadius);
        if (obstaclesModel->test(candidate)) {
            obstaclesModel->add(candidate);
            QVector<QVector3D> points = { candidate };
            return new TubeModel(points, sceneRadius, obstaclesModel);
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
    if (_points.size() == MaxLength) {
        return false;
    }

    int attempts = MaxAttempts;
    while (attempts-- > 0) {
        const auto direction = randomVector(100).normalized();
        const auto candidate = _points.last() + direction * _obstaclesModel->radius() * 2.0;
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
