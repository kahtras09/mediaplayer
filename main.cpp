#include <QCoreApplication>
#include <QProcess>
#include <QDebug>

//int main(int argc, char *argv[]) {
//    QCoreApplication a(argc, argv);

//    //ls  code
//    /*
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
//*/

//    // Restart Bluetooth service using systemctl
//    /*
//    QProcess systemctlProcess;
//    systemctlProcess.start("systemctl", QStringList() << "restart" << "bluetooth");

//    if (systemctlProcess.waitForStarted() && systemctlProcess.waitForFinished()) {
//        if (systemctlProcess.exitCode() == 0) {
//            qDebug() << "Bluetooth service restarted successfully.";
//        } else {
//            qDebug() << "Error: systemctl Process exited with code " << systemctlProcess.exitCode();
//        }
//    } else {
//        qDebug() << "Error:" << systemctlProcess.errorString();
//    }

//    return a.exec();
//}
//*/





//    // Start the service using systemctl
//    QProcess systemctlProcess;
//    systemctlProcess.start("systemctl", QStringList() << "start" << "agl-app@settings.service");

//    if (systemctlProcess.waitForStarted() && systemctlProcess.waitForFinished()) {
//        if (systemctlProcess.exitCode() == 0) {
//            qDebug() << "Service started successfully.";
//        } else {
//            qDebug() << "Error: systemctl Process exited with code " << systemctlProcess.exitCode();
//        }
//    } else {
//        qDebug() << "Error:" << systemctlProcess.errorString();
//    }

//    return a.exec();
//}


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    bool mediaPlayerClicked = true;

    if (mediaPlayerClicked) {
        // Start the agl-app@settings.service when the event occurs
        QProcess systemctlProcess;
        systemctlProcess.start("systemctl", QStringList() << "start" << "agl-app@settings.service");

        if (systemctlProcess.waitForStarted() && systemctlProcess.waitForFinished()) {
            if (systemctlProcess.exitCode() == 0) {
                qDebug() << "Service started successfully.";
            } else {
                qDebug() << "Error: systemctl Process exited with code " << systemctlProcess.exitCode();
            }
        } else {
            qDebug() << "Error:" << systemctlProcess.errorString();
        }
    }

    return a.exec();
}

