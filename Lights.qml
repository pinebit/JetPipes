import QtQuick 2.1
import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Extras 2.0

Entity {
    Entity {
        components: [
            DirectionalLight {
                worldDirection: Qt.vector3d(1.0, 1.0, 1.0).normalized()
                color: "white"
                intensity: 0.8
            }
        ]
    }
    Entity {
        components: [
            DirectionalLight {
                worldDirection: Qt.vector3d(-1, -1, -1).normalized()
                color: "white"
                intensity: 0.8
            }
        ]
    }
}
