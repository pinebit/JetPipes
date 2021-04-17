#ifndef TUBEGEOMETRY_HPP
#define TUBEGEOMETRY_HPP

#include <Qt3DCore/QGeometry>

class TubeGeometry : public Qt3DCore::QGeometry
{
public:
    TubeGeometry(Qt3DCore::QNode *parent = nullptr);

    void update(const QVector<QVector3D> &points);

private:
    void updateGeometry(const QVector<QVector3D> &vertices,
                        const QVector<QVector3D> &normals,
                        const QVector<quint32> &indices);
};

Q_DECLARE_METATYPE(TubeGeometry*)

#endif // TUBEGEOMETRY_HPP
