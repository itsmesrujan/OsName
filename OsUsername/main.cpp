#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString szUsername;

#if defined(Q_OS_WIN)     // Windows specific code
    DWORD size = UNLEN+1;
    TCHAR name[size]; // To store the username

    // Retrieve username in windows platform
    if (GetUserNameW(name,&size)) {
        for (int var = 0; var < size; ++var) {
            if ( name[var] != '\0' )
                szUsername.append(name[var]);
            else
                break;
        }
    } else {
        szUsername = QString("");
    }
#elif defined(Q_OS_LINUX)     // Linux specific code
    a.setWindowIcon(QIcon("LinuxApp.png"));
    szUsername = qgetenv("USER");
    if (szUsername.isEmpty())
        szUsername = qgetenv("USERNAME");
#else
    // Other than windows and linux platform
#endif

    AppUtils::logInfo(szUsername);

    Widget w(nullptr, szUsername);
    w.show();

    return a.exec();
}
