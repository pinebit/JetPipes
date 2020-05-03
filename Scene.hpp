#ifndef SCENE_HPP
#define SCENE_HPP

#include <QObject>
#include <TubeModel.hpp>
#include <TubeGeometry.hpp>
#include <ObstaclesModel.hpp>

class Scene : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int tubesCount READ tubesCount CONSTANT)

public:
    Scene(QObject *parent = nullptr);

    int tubesCount() const;

public slots:
    void init();
    bool advance();
    void clear();
    TubeGeometry* getTubeGeometry(int index) const;

private:
    QVector<TubeModel*> _tubes;
    QVector<TubeGeometry*> _geometries;
    QSharedPointer<ObstaclesModel> _obstaclesModel;
};

Q_DECLARE_METATYPE(Scene*);

#endif // SCENE_HPP
