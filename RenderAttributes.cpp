#include "RenderAttributes.hpp"
#include <Qt3DCore/QBuffer>

Qt3DCore::QAttribute *RenderAttributes::create(const QVector<quint32> &indices, Qt3DCore::QGeometry *parent)
{
    auto attribute = new Qt3DCore::QAttribute(parent);

    Qt3DCore::QBuffer *dataBuffer = new Qt3DCore::QBuffer(attribute);
    const int rawSize = indices.size() * static_cast<int>(sizeof(uint));
    auto rawData = QByteArray::fromRawData(reinterpret_cast<const char*>(indices.constData()), rawSize);
    rawData.detach();
    dataBuffer->setData(rawData);

    attribute->setAttributeType(Qt3DCore::QAttribute::IndexAttribute);
    attribute->setBuffer(dataBuffer);
    attribute->setVertexBaseType(Qt3DCore::QAttribute::UnsignedInt);
    attribute->setVertexSize(1);
    attribute->setByteOffset(0);
    attribute->setByteStride(sizeof(uint));
    attribute->setCount(static_cast<uint>(indices.size()));

    return attribute;
}

Qt3DCore::QAttribute *RenderAttributes::create(const QVector<QVector3D> &vertices, const QString &name, Qt3DCore::QGeometry *parent)
{
    auto attribute = new Qt3DCore::QAttribute(parent);

    QVector<float> values;
    values.reserve(vertices.size() * 3);

    for (const QVector3D &v : vertices) {
        values << v.x() << v.y() << v.z();
    }

    Qt3DCore::QBuffer *dataBuffer = new Qt3DCore::QBuffer(attribute);
    const int rawSize = values.size() * static_cast<int>(sizeof(float));
    auto rawData = QByteArray::fromRawData(reinterpret_cast<const char*>(values.constData()), rawSize);
    rawData.detach();
    dataBuffer->setData(rawData);

    attribute->setAttributeType(Qt3DCore::QAttribute::VertexAttribute);
    attribute->setBuffer(dataBuffer);
    attribute->setVertexBaseType(Qt3DCore::QAttribute::Float);
    attribute->setVertexSize(3);
    attribute->setByteOffset(0);
    attribute->setByteStride(3 * sizeof(float));
    attribute->setName(name);
    attribute->setCount(static_cast<uint>(vertices.size()));

    return attribute;
}
