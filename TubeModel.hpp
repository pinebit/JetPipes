#ifndef TUBEMODEL_HPP
#define TUBEMODEL_HPP

#include <QVector3D>
#include <QSharedPointer>

class ObstaclesModel;

class TubeModel
{
public:
    virtual ~TubeModel() {}

    static TubeModel* create(QSharedPointer<ObstaclesModel> obstaclesModel);

    QVector<QVector3D> points() const;

    bool advance();

private:
    TubeModel(const QVector<QVector3D> &points,
              QSharedPointer<ObstaclesModel> obstaclesModel);

    static QVector3D randomVector(int bound);

    QSharedPointer<ObstaclesModel> _obstaclesModel;
    QVector<QVector3D> _points;
};

#endif // TUBEMODEL_HPP
