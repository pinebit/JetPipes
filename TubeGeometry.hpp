#ifndef TUBEGEOMETRY_HPP
#define TUBEGEOMETRY_HPP

#include <Qt3DRender/QGeometry>

class TubeGeometry : public Qt3DRender::QGeometry
{
    Q_OBJECT

public:
    TubeGeometry(Qt3DCore::QNode *parent = nullptr);

    static const int CircleSegments = 16;
    static constexpr double TubeRadius = 2.0;

    void update(const QVector<QVector3D> &path);
};

Q_DECLARE_METATYPE(TubeGeometry*)

#endif // TUBEGEOMETRY_HPP
