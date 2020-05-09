#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

void logInfo( string szInfo )
{
    string szFileName;
#ifdef _WIN32     // Windows specific code
    szFileName = getConfigInfo("OsNameSettings.ini", "OsNameFolderPaths", "LogsPath");
#endif

#ifdef linux/*(__linux__ | linux | __linux)*/     // Linux specific code
    szFileName = string("/var/log");
#endif

    szFileName.append(linux?"/":"\\");
    szFileName.append("OSUsernameLog.log");

    // Creation of ofstream class object
    ofstream fout;

    fout.open(szFileName, ios::app);

    // Execute a loop If file successfully opened
    if (fout) {
        szInfo.append("\n");

        // To write text, we use operator<<(),
        // which is overloaded to take
        // a string
        fout << szInfo;
    }

    // Close the File
    fout.close();
}

int main()
{
    string szUsername;

#ifdef _WIN32     // Windows specific code
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
#endif

#ifdef linux /*(__linux__ | linux | __linux)*/     // Linux specific code
    szUsername = getenv("USER");
    if (szUsername.empty())
        szUsername = getenv("USERNAME");
#endif

    logInfo(szUsername);

    cout << "Hello " << szUsername << endl;
    return 0;
}
