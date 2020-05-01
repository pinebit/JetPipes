#ifndef TUBEMODEL_HPP
#define TUBEMODEL_HPP

#include <QVector3D>
#include <QSharedPointer>

class ObstaclesModel;

class TubeModel
{
public:
    TubeModel(int sceneRadius,
              QSharedPointer<ObstaclesModel> obstaclesModel);
    virtual ~TubeModel() {}

    static const int MaxAttempts = 3;
    static const int MaxLength = 100;

    bool advance();

private:
    QVector3D randomVector(int bound) const;

    int _sceneRadius;
    QSharedPointer<ObstaclesModel> _obstaclesModel;
    QVector<QVector3D> _points;
    bool _finished { false };
};

#endif // TUBEMODEL_HPP
