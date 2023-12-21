#include <QCoreApplication>
#include <QProcess>
#include <QDebug>
#include <QPushButton>
#include <QVBoxLayout>
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Service Control App");

    QVBoxLayout layout(&window);

    QPushButton mediaPlayerButton("MediaPlayer");
    QPushButton settingsButton("Settings");

    layout.addWidget(&mediaPlayerButton);
    layout.addWidget(&settingsButton);

    QProcess systemctlProcess;

    // Connect the buttons to start the corresponding services
    QObject::connect(&mediaPlayerButton, &QPushButton::clicked, [&systemctlProcess](){
        systemctlProcess.start("systemctl", QStringList() << "start" << "agl-app@mediaplayer.service");
        systemctlProcess.waitForStarted();
        systemctlProcess.waitForFinished();
    });

    QObject::connect(&settingsButton, &QPushButton::clicked, [&systemctlProcess](){
        systemctlProcess.start("systemctl", QStringList() << "start" << "agl-app@settings.service");
        systemctlProcess.waitForStarted();
        systemctlProcess.waitForFinished();
    });

    window.show();

    return app.exec();
}


//int main(int argc, char *argv[]) {
//    QCoreApplication a(argc, argv);

//    //ls  code

//    QProcess lsProcess;
//    lsProcess.setWorkingDirectory("/home/srg-sarthak");
//    lsProcess.start("ls", QStringList() << "-l");

//    if (lsProcess.waitForStarted() && lsProcess.waitForFinished()) {
//        if (lsProcess.exitCode() == 0) {
//            QByteArray lsResult = lsProcess.readAllStandardOutput();

//            QStringList lsLines = QString(lsResult).split("\n", QString::SkipEmptyParts);

//            qDebug() << "File List:";
//            for (const QString& line : lsLines) {
//                QStringList parts = line.split(QRegExp("\\s+"), QString::SkipEmptyParts);
//                if (parts.size() >= 9) {
//                    QString permissions = parts[0];
//                    QString size = parts[4];
//                    QString fileName = parts[parts.size() - 1];
//                    qDebug() << "Permissions:" << permissions << "Size:" << size << "File:" << fileName;
//                }
//            }
//        } else {
//            qDebug() << "Error: ls Process exited with code " << lsProcess.exitCode();
//        }
//    } else {
//        qDebug() << "Error:" << lsProcess.errorString();
//    }
//}
