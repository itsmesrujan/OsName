#include "apputils.h"

AppUtils::AppUtils()
{
    // To do nothing
}

QString AppUtils::getConfigInfo(QString szConfigIni,
                                                          QString szGroupName,
                                                          QString szKeyName)
{
    QString szKeyValue;
    QString szINIPath = QDir::toNativeSeparators(QDir::currentPath()+QDir::separator()+szConfigIni);
    QSettings settings(szINIPath, QSettings::IniFormat);

    settings.beginGroup(szGroupName);
    if (settings.contains(szKeyName))
        szKeyValue = settings.value(szKeyName).toString();
    settings.endGroup();

    return szKeyValue;
}

void AppUtils::setConfigInfo(QString szConfigIni,
                                                    QString szGroupName,
                                                    QString szKey,
                                                    QString szValue)
{
    QString szINIPath = QDir::toNativeSeparators(QDir::currentPath()+QDir::separator()+szConfigIni);
    QSettings settings(szINIPath, QSettings::IniFormat);

    settings.beginGroup(szGroupName);
    settings.setValue(szKey,szValue);
    settings.endGroup();
}

// Save Online CWA login status
void AppUtils::logInfo( QString szInfo )
{
    QString szFileName = getConfigInfo("OsNameSettings.ini", "OsNameFolderPaths", "LogsPath");

    QString szAppFolderName = szFileName;
    szAppFolderName.append(QDir::separator()).append("app");
    if ( !QDir(szAppFolderName).exists() )
    {
        QDir().mkdir(szAppFolderName);
    }

    szFileName.append(QDir::separator());
    szFileName.append("OSUsernameLog.txt");

    QFile file(szFileName);
    // Trying to open in WriteOnly and Text mode
    if ( !file.open(QFile::WriteOnly |
                           QFile::Text |
                           QIODevice::Append) )
    {
        return;
    }

    szInfo.append("\n");

    // To write text, we use operator<<(),
    // which is overloaded to take
    // a QTextStream on the left
    // and data types (including QString) on the right
    QTextStream outTextStream(&file);
    outTextStream << szInfo;

    file.flush();
    file.close();
}
