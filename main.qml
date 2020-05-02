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
        nearPlane: 1
        farPlane: 500.0
        viewCenter: Qt.vector3d(0.0, 0.0, 0.0)
        upVector: Qt.vector3d(0.0, 1.0, 0.0)
        position: Qt.vector3d(100.0, 100.0, 100.0)
    }

    Timer {
        running: true
        interval: 10
        repeat: true
        onTriggered: {
            let q = mainCamera.rotation(0.1, Qt.vector3d(1, 1, 0))
            mainCamera.rotateAboutViewCenter(q)
        }
    }

    Lights {
    }

    Scene {
        id: scene

        onUpdated: {
            instantiator.model = tubesCount
        }
    }

    Timer {
        running: true
        repeat: true
        interval: 1000
        onTriggered: {
            scene.advance();
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
        model: 0
        delegate: Entity {
            components: [
                GeometryRenderer {
                    primitiveType: GeometryRenderer.Triangles
                    geometry: scene.getTubeGeometry(index)
                },
                WireframeMaterial {
                }
            ]
        }
    }
}
