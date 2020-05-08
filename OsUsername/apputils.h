#ifndef APPUTILS_H
#define APPUTILS_H

#include <QString>
#include <QDir>
#include <QSettings>
#include <QTextStream>

class AppUtils
{
public:
    AppUtils();

    static QString getConfigInfo(QString szConfigIni,
                                                        QString szGroupName,
                                                        QString szKeyName);
    static void setConfigInfo(QString szConfigIni,
                                                  QString szGroupName,
                                                  QString szKey,
                                                  QString szValue);
    static void logInfo( QString szInfo );
};

#endif // APPUTILS_H
