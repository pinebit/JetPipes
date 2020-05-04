import QtQuick 2.2
import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Extras 2.12

NodeInstantiator {
    property QtObject scene

    active: true
    model: scene.tubesCount
    delegate: Entity {
        components: [
            GeometryRenderer {
                primitiveType: GeometryRenderer.Triangles
                geometry: scene.getTubeGeometry(index)
            },
            PhongMaterial {
                property var colors: [
                    "#001f3f", "#0074D9", "#7FDBFF", "#39CCCC",
                    "#3D9970", "#2ECC40", "#01FF70", "#FFDC00",
                    "#FF851B", "#FF4136", "#85144b", "#F012BE",
                    "#B10DC9", "#AAAAAA", "#DDDDDD", "#FFFFFF"
                ]
                property color qcolor: colors[index % colors.length]
                diffuse: qcolor
            }

        ]
    }
}

