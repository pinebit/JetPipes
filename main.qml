import QtQuick 2.2
import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Extras 2.12

import JetPipes 1.0

Entity {
    id: sceneRoot

    SceneCamera {
        id: mainCamera
    }

    CameraAnimator {
        id: cameraAnimator
        camera: mainCamera
    }

    SceneLightsEntity {
    }

    Scene {
        id: scene

        Component.onCompleted: {
            scene.init();
            updateTimer.start()
        }

        onCleared: {
            cameraAnimator.reset()
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
                clearColor: Qt.rgba(0.2, 0.2, 0.2)
                camera: mainCamera
            }
        },
        InputSettings { }
    ]

    KeyboardDevice {
        id: keyboardDevice
    }

    KeyboardHandler {
        id: keyboardHandler
        focus: true
        sourceDevice: keyboardDevice
        onEscapePressed: {
            _window.close()
        }
        onSpacePressed: {
            if (_window.visibility === Window.FullScreen) {
                _window.visibility = Window.Maximized
            } else {
                _window.visibility = Window.FullScreen
            }
        }
    }

    PipesInstantiator {
        scene: scene
    }
}
