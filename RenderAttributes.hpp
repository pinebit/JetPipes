#ifndef RENDERATTRIBUTES_HPP
#define RENDERATTRIBUTES_HPP

#include <Qt3DRender/QAttribute>
#include <Qt3DRender/QGeometry>
#include <QVector3D>

namespace RenderAttributes
{
Qt3DRender::QAttribute *create(const QVector<quint32> &indices, Qt3DRender::QGeometry *parent);

Qt3DRender::QAttribute *create(const QVector<QVector3D> &vertices, const QString &name, Qt3DRender::QGeometry *parent);
};

#endif // RENDERATTRIBUTES_HPP
