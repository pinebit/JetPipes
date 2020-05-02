#ifndef TUBEGEOMETRY_HPP
#define TUBEGEOMETRY_HPP

#include <Qt3DRender/QGeometry>

class TubeGeometry : public Qt3DRender::QGeometry
{
public:
    static const int CircleSegments = 16;

    static TubeGeometry* create(const QVector<QVector3D> &points,
                                double radius,
                                Qt3DCore::QNode *parent = nullptr);

private:
    TubeGeometry(const QVector<QVector3D> &vertices,
                 const QVector<QVector3D> &normals,
                 const QVector<quint32> &indices,
                 Qt3DCore::QNode *parent = nullptr);
};

Q_DECLARE_METATYPE(TubeGeometry*)

#endif // TUBEGEOMETRY_HPP
