#ifndef OBSTACLESMODEL_HPP
#define OBSTACLESMODEL_HPP

#include <QVector3D>
#include <QVector>

class ObstaclesModel
{
public:
    void add(const QVector3D &vertex);
    void clear();
    bool test(const QVector3D &vertex);

private:
    QVector<QVector3D> _obstacles;
};

#endif // OBSTACLESMODEL_HPP
