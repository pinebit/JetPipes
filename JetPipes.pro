QT += 3dcore 3drender 3dinput 3dquick 3dlogic qml quick 3dquickextras
CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        ObstaclesModel.cpp \
        RenderAttributes.cpp \
        Scene.cpp \
        Spline.cpp \
        TubeGeometry.cpp \
        TubeModel.cpp \
        main.cpp

RESOURCES += qml.qrc \
    resources.qrc

QML_IMPORT_PATH =
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32: RC_ICONS += favicon.ico

HEADERS += \
    Config.hpp \
    ObstaclesModel.hpp \
    RenderAttributes.hpp \
    Scene.hpp \
    Spline.hpp \
    TubeGeometry.hpp \
    TubeModel.hpp
