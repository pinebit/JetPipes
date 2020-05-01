#include <Qt3DQuick/QQmlAspectEngine>
#include <QGuiApplication>
#include <QtQml>
#include <Qt3DQuickExtras/qt3dquickwindow.h>
#include <QOpenGLContext>
#include <TubeGeometry.hpp>
#include <TubeGenerator.hpp>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    Qt3DExtras::Quick::Qt3DQuickWindow view;

    QSurfaceFormat format;
    format.setDepthBufferSize(32);
    format.setSamples(8);
    format.setSwapBehavior(QSurfaceFormat::DoubleBuffer);
    format.setVersion(4, 4);
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);

    qmlRegisterType<TubeGeometry>("JetPipes", 1, 0, "TubeGeometry");
    qmlRegisterType<TubeGenerator>("JetPipes", 1, 0, "TubeGenerator");

    auto engine = view.engine()->qmlEngine();
    engine->addImportPath("qrc:/");
    engine->rootContext()->setContextProperty("_window", &view);
    view.setSource(QUrl("qrc:/main.qml"));
    view.show();

    return app.exec();
}
