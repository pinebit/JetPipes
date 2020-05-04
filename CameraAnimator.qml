import QtQuick 2.2
import Qt3D.Core 2.0
import Qt3D.Render 2.0

Timer {
    id: root
    property Camera camera
    property var _lastVector: Qt.vector3d(0, 0, 0)
    property int _frames: 0

    running: true
    interval: 1
    repeat: true
    onTriggered: {
        _frames = _frames + 1

        let q = camera.rotation(Math.random() / 10.0, Qt.vector3d(0, 1, 0))
        camera.rotateAboutViewCenter(q)

        if (_frames % 10 === 0) {
            _lastVector = randomVector()
        }

        camera.position = camera.position.plus(_lastVector)
    }

    function randomVector() {
        let x = Math.random() - 0.5
        let y = Math.random() - 0.5
        let z = Math.random() - 0.5
        return Qt.vector3d(x, y, z).times(0.1)
    }
}

