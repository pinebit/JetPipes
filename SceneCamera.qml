import QtQuick 2.0
import Qt3D.Render 2.0

Camera {
    projectionType: CameraLens.PerspectiveProjection
    fieldOfView: 30.0
    aspectRatio: _window.width / _window.height
    nearPlane: 1
    farPlane: 500.0
    viewCenter: Qt.vector3d(0.0, 0.0, 0.0)
    upVector: Qt.vector3d(0.0, 1.0, 0.0)
    position: Qt.vector3d(150.0, 150.0, 150.0)
}
