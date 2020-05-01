#include "RenderAttributes.hpp"
#include <Qt3DRender/QBuffer>

Qt3DRender::QAttribute *RenderAttributes::create(const QVector<quint32> &indices, Qt3DRender::QGeometry *parent)
{
    auto attribute = new Qt3DRender::QAttribute(parent);

    Qt3DRender::QBuffer *dataBuffer = new Qt3DRender::QBuffer(attribute);
    const int rawSize = indices.size() * static_cast<int>(sizeof(uint));
    auto rawData = QByteArray::fromRawData(reinterpret_cast<const char*>(indices.constData()), rawSize);
    rawData.detach();
    dataBuffer->setData(rawData);

    attribute->setAttributeType(Qt3DRender::QAttribute::IndexAttribute);
    attribute->setBuffer(dataBuffer);
    attribute->setVertexBaseType(Qt3DRender::QAttribute::UnsignedInt);
    attribute->setVertexSize(1);
    attribute->setByteOffset(0);
    attribute->setByteStride(sizeof(uint));
    attribute->setCount(static_cast<uint>(indices.size()));

    return attribute;
}

Qt3DRender::QAttribute *RenderAttributes::create(const QVector<QVector3D> &vertices, const QString &name, Qt3DRender::QGeometry *parent)
{
    auto attribute = new Qt3DRender::QAttribute(parent);

    QVector<float> values;
    values.reserve(vertices.size() * 3);

    for (const QVector3D &v : vertices) {
        values << v.x() << v.y() << v.z();
    }

    Qt3DRender::QBuffer *dataBuffer = new Qt3DRender::QBuffer(attribute);
    const int rawSize = values.size() * static_cast<int>(sizeof(float));
    auto rawData = QByteArray::fromRawData(reinterpret_cast<const char*>(values.constData()), rawSize);
    rawData.detach();
    dataBuffer->setData(rawData);

    attribute->setAttributeType(Qt3DRender::QAttribute::VertexAttribute);
    attribute->setBuffer(dataBuffer);
    attribute->setVertexBaseType(Qt3DRender::QAttribute::Float);
    attribute->setVertexSize(3);
    attribute->setByteOffset(0);
    attribute->setByteStride(3 * sizeof(float));
    attribute->setName(name);
    attribute->setCount(static_cast<uint>(vertices.size()));

    return attribute;
}
