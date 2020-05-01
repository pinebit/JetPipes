import QtQuick 2.2
import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Extras 2.0

import JetPipes 1.0

Entity {
    id: sceneRoot

    Camera {
        id: mainCamera
        projectionType: CameraLens.PerspectiveProjection
        fieldOfView: 30.0
        aspectRatio: _window.width / _window.height
        nearPlane: 0.01
        farPlane: 1000.0
        viewCenter: Qt.vector3d(0.0, 0.0, 0.0)
        upVector: Qt.vector3d(0.0, 1.0, 0.0)
        position: Qt.vector3d(100.0, 100.0, 100.0)
    }

    Lights {
    }

    components: [
        RenderSettings {
            activeFrameGraph: ForwardRenderer {
                clearColor: Qt.rgba(0.05, 0.05, 0.05)
                camera: mainCamera
            }
        },
        InputSettings { }
    ]

    TubeGenerator {
        id: generator
    }

    Timer {
        running: true
        repeat: true
        interval: 1000
        onTriggered: {
            generator.next(tubeGeometry)
        }
    }

    Entity {
        id: root
        property QtObject model

        components: [
            GeometryRenderer {
                primitiveType: GeometryRenderer.Triangles
                geometry: TubeGeometry {
                    id: tubeGeometry
                }
            },
            PhongMaterial {
            },
            Transform {
                id: tubeTransform
                property real userAngle: 0.0
                matrix: {
                    let m = Qt.matrix4x4();
                    m.rotate(userAngle, Qt.vector3d(0, 1, 0));
                    return m;
                }
            }
        ]
    }

    NumberAnimation {
        target: tubeTransform
        property: "userAngle"
        duration: 100000
        from: 0
        to: 360
        loops: Animation.Infinite
        running: true
    }
}
