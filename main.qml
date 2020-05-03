import QtQuick 2.2
import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Extras 2.12

import JetPipes 1.0

Entity {
    id: sceneRoot
    property var colors: [
        "#001f3f", "#0074D9", "#7FDBFF", "#39CCCC",
        "#3D9970", "#2ECC40", "#01FF70", "#FFDC00",
        "#FF851B", "#FF4136", "#85144b", "#F012BE",
        "#B10DC9", "#AAAAAA", "#DDDDDD", "#FFFFFF"
    ]

    Camera {
        id: mainCamera
        projectionType: CameraLens.PerspectiveProjection
        fieldOfView: 30.0
        aspectRatio: _window.width / _window.height
        nearPlane: 1
        farPlane: 500.0
        viewCenter: Qt.vector3d(0.0, 0.0, 0.0)
        upVector: Qt.vector3d(0.0, 1.0, 0.0)
        position: Qt.vector3d(150.0, 150.0, 150.0)
    }

    Timer {
        running: true
        interval: 1
        repeat: true
        onTriggered: {
            let q = mainCamera.rotation(0.05, Qt.vector3d(0, 1, 0))
            mainCamera.rotateAboutViewCenter(q)
        }
    }

    Lights {
    }

    Scene {
        id: scene

        Component.onCompleted: {
            scene.init();
            updateTimer.start()
        }
    }

    Timer {
        id: updateTimer
        repeat: false
        interval: 50
        onTriggered: {
            if (!scene.advance()) {
                scene.clear();
                scene.init();
            }
            updateTimer.start()
        }
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

    NodeInstantiator {
        id: instantiator
        active: true
        model: scene.tubesCount
        delegate: Entity {
            components: [
                GeometryRenderer {
                    primitiveType: GeometryRenderer.Triangles
                    geometry: scene.getTubeGeometry(index)
                },
                PhongMaterial {
                    property color c: sceneRoot.colors[index]
                    diffuse: c
                }

            ]
        }
    }
}
