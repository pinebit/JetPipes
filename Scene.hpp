#ifndef SCENE_HPP
#define SCENE_HPP

#include <QObject>
#include <TubeModel.hpp>
#include <TubeGeometry.hpp>
#include <ObstaclesModel.hpp>

class Scene : public QObject
{
    Q_OBJECT

public:
    explicit Scene(QObject *parent = nullptr);

    static const int MinTubes = 3;
    static const int MaxTubes = 30;
    static const int SceneRadius = 100;
    static const int TubeRadius = 2;
    static const int TubesGap = 0;

public slots:
    bool advance();
    void clear();
    TubeGeometry* getTubeGeometry(int index) const;

signals:
    void updated(int tubesCount);

private:
    QList<TubeModel*> _tubes;
    QList<TubeGeometry*> _geometries;
    QSharedPointer<ObstaclesModel> _obstaclesModel;
};

Q_DECLARE_METATYPE(Scene*);

#endif // SCENE_HPP
