import QtQuick 2.2
import Qt3D.Core 2.0
import Qt3D.Render 2.0

Timer {
    id: root
    property Camera camera
    property real sceneRadius: 150.0
    property real rotationPeriodMs: 30000.0
    property var _lastDate: Date.now()
    property var _elapsed: 0

    function reset() {
        _lastDate = Date.now()
        _elapsed = 0
    }

    running: true
    interval: 1
    repeat: true
    onTriggered: {
        let newDate = Date.now()
        _elapsed += newDate - _lastDate

        let pa = _elapsed * 2.0 * Math.PI / rotationPeriodMs
        let px = sceneRadius * Math.cos(pa)
        let py = sceneRadius + 5 * Math.cos(pa * 8.0)
        let pz = sceneRadius * Math.sin(pa)
        camera.position = Qt.vector3d(px, py, pz)

        _lastDate = newDate
        if (_elapsed > rotationPeriodMs) {
            _elapsed -= rotationPeriodMs
        }
    }
}

