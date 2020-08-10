#include <QtWidgets/QApplication>
#include "config/AppConfig.hpp"
#include "App/AppDependency.hpp"

int main(int argc, char* argv[])
{
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QApplication app(argc, argv);
    config::AppConfig appConfig(app);
    if (appConfig.runOnlyOne())
    {
        return 1;
    }
    App::AppDependency appDependency;
    appDependency.initAppInstance();

    // app.exec();
    appConfig.releaseShareMemory();

    return 0;
}