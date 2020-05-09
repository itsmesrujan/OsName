sudo cp $PWD/OsNameTerminal /etc/profile.d/
sudo cp $PWD/displayOsName.sh /etc/profile.d/
sudo chmod 777 /etc/profile.d/OsNameTerminal
sudo chmod 777 /etc/profile.d/displayOsName.sh
sudo chmod a+x /etc/profile.d/OsNameTerminal
sudo chmod a+x /etc/profile.d/displayOsName.sh
sudo touch /var/log/OSUsernameLog.log
sudo chmod 777 /var/log/OSUsernameLog.log
sudo chmod a+x /var/log/OSUsernameLog.log
