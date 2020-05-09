# OsName

Print OS username as a startup program

# Windows

GUI Source code: master/OsUsername

Installer: master/installers/1.0/windows

installationSetup: master/installationSetup/windows

Note: Installation setup files can be run through bitrock installation setup
Simply run the installer which is in master/installers/1.0/windows/.

Troubleshooting: If face any issue on creating shortcut link in startup program then you need to set environment variables properly.

# Linux

GUI Source code: master/OsUsername
Terminal Source code: master/OsUsernameTerminal/OsNameTerminal

Run the bash script install.sh which is in installationSetup/Linux/GUI - for GUI

Run the bash script install.sh which is in installationSetup/Linux/terminal - for terminal

Troubleshooting: If face any issue on fetching results then you may need to install the dependent packages in your linux pc if not available.

Please note that windows source code compiled with Qt 5.11(mingw compiler) in windows 10 platform and linux source code compiled with Qt 5.10(gcc compiler) in ubuntu 14.04 platform.
