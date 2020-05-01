#include "TubeModel.hpp"
#include "ObstaclesModel.hpp"
#include <QRandomGenerator>

TubeModel::TubeModel(int sceneRadius,
                     QSharedPointer<ObstaclesModel> obstaclesModel)
    : _sceneRadius(sceneRadius)
    , _obstaclesModel(obstaclesModel)
{
    int attempts = MaxAttempts;
    while (attempts-- > 0) {
        QVector3D candidate = randomVector(_sceneRadius);
        if (_obstaclesModel->test(candidate)) {
            _obstaclesModel->add(candidate);
            _points.append(candidate);
            break;
        }
    }

    _finished = _points.isEmpty();
}

bool TubeModel::advance()
{
    if (_points.size() == MaxLength) {
        _finished = true;
    }

    if (_finished) {
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

QVector3D TubeModel::randomVector(int bound) const
{
    auto gen = QRandomGenerator::global();
    const int x = gen->bounded(-bound, bound);
    const int y = gen->bounded(-bound, bound);
    const int z = gen->bounded(-bound, bound);
    return QVector3D(x, y, z);
}
