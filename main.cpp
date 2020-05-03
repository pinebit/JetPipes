#include <Qt3DQuick/QQmlAspectEngine>
#include <QGuiApplication>
#include <QtQml>
#include <Qt3DQuickExtras/qt3dquickwindow.h>
#include <QOpenGLContext>
#include <QIcon>
#include <TubeGeometry.hpp>
#include <Scene.hpp>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    Qt3DExtras::Quick::Qt3DQuickWindow view;
    view.resize(1280, 700);
    app.setWindowIcon(QIcon(":/favicon.ico"));

    QSurfaceFormat format;
    format.setDepthBufferSize(32);
    format.setSamples(8);
    format.setSwapBehavior(QSurfaceFormat::DoubleBuffer);
    format.setVersion(4, 4);
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);

    qmlRegisterType<Scene>("JetPipes", 1, 0, "Scene");

    auto engine = view.engine()->qmlEngine();
    engine->addImportPath("qrc:/");
    engine->rootContext()->setContextProperty("_window", &view);
    view.setSource(QUrl("qrc:/main.qml"));
    view.show();
    view.setVisibility(QWindow::FullScreen);

    return app.exec();
}
