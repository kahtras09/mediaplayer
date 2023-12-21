#include <QCoreApplication>
#include <QProcess>
#include <QDebug>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    bool mediaPlayerClicked = true;

    if (mediaPlayerClicked) {
        // Start the agl-app@mediaplayer.service
        QProcess mediaPlayerProcess;
        mediaPlayerProcess.start("systemctl", QStringList() << "start" << "agl-app@mediaplayer.service");

        if (mediaPlayerProcess.waitForStarted() && mediaPlayerProcess.waitForFinished()) {
            if (mediaPlayerProcess.exitCode() == 0) {
                qDebug() << "mediaplayer service started successfully.";
            } else {
                qDebug() << "Error: mediaplayer Process exited with code " << mediaPlayerProcess.exitCode();
            }
        } else {
            qDebug() << "Error:" << mediaPlayerProcess.errorString();
        }

        // Start the agl-app@settings.service
        QProcess settingsProcess;
        settingsProcess.start("systemctl", QStringList() << "start" << "agl-app@settings.service");

        if (settingsProcess.waitForStarted() && settingsProcess.waitForFinished()) {
            if (settingsProcess.exitCode() == 0) {
                qDebug() << "settings service started successfully.";
            } else {
                qDebug() << "Error: settings Process exited with code " << settingsProcess.exitCode();
            }
        } else {
            qDebug() << "Error:" << settingsProcess.errorString();
        }
    }

    return a.exec();
}
