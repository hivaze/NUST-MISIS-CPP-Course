#include <QtCore/QStandardPaths>
#include <QtCore/QDir>
#include <QtCore/QJsonArray>
#include <QtGui/QFontDatabase>
#include <QtWidgets/QApplication>
#include "MainWindow.h"
#include "../lib/DatamuseAPI.h"
#include "../lib/SettingsWrapper.hpp"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    QApplication::setOrganizationDomain("bratchikov_s_s.coursework");
    QApplication::setApplicationName("Synonymizer");
    QApplication::setWindowIcon(QIcon(":/images/icon.png"));

    QFontDatabase::addApplicationFont(":/fonts/FuturaPT-Bold.ttf");
    QFontDatabase::addApplicationFont(":/fonts/FuturaPT-Medium.ttf");

    const QString APP_DATA_FOLDER = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);

    if (APP_DATA_FOLDER.isEmpty())
        qFatal("Cannot determine settings storage location");

    const QDir appDataDir(APP_DATA_FOLDER);

    if (!appDataDir.mkpath(appDataDir.absolutePath()) || !QDir::setCurrent(appDataDir.absolutePath()))
        qFatal("Couldn't setup appDataDir!");

    qDebug() << "Application data folder: " << APP_DATA_FOLDER;

    auto * settings = new SettingsWrapper(appDataDir);
    qDebug() << "Settings file location: " << settings->getFileName();

    auto * datamuseAPI = new DatamuseAPI();

    MainWindow window(settings, datamuseAPI);
    window.setupWindowSettings();
    window.show();

    return app.exec();
}