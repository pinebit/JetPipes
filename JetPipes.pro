QT += 3dcore 3drender 3dinput 3dquick 3dlogic qml quick 3dquickextras
CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        RenderAttributes.cpp \
        Spline.cpp \
        TubeGenerator.cpp \
        TubeGeometry.cpp \
        main.cpp

RESOURCES += qml.qrc \
    resources.qrc

QML_IMPORT_PATH =
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    RenderAttributes.hpp \
    Spline.hpp \
    TubeGenerator.hpp \
    TubeGeometry.hpp
