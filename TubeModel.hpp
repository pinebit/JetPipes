#ifndef TUBEMODEL_HPP
#define TUBEMODEL_HPP

#include <QVector3D>
#include <QSharedPointer>

class ObstaclesModel;

class TubeModel
{
public:
    virtual ~TubeModel() {}

    static const int MaxAttempts = 10;
    static const int MaxLength = 100;

    static TubeModel* create(int sceneRadius,
                             QSharedPointer<ObstaclesModel> obstaclesModel);

    QVector<QVector3D> points() const;

    bool advance();

private:
    TubeModel(const QVector<QVector3D> &points,
              int sceneRadius,
              QSharedPointer<ObstaclesModel> obstaclesModel);

    static QVector3D randomVector(int bound);

    int _sceneRadius;
    QSharedPointer<ObstaclesModel> _obstaclesModel;
    QVector<QVector3D> _points;
};

#endif // TUBEMODEL_HPP
