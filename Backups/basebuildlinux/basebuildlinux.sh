#!/bin/bash
while true; do
echo "Security Tools installation"
echo "Select a software to install:"
echo "1. Install McAfee"
echo "2. Install CortexXDR"
echo "3. Install Zscaler"
echo "4. Install USB_Block"
echo "5. Install ManageEngine"
echo "6. Install McAfee ENS"
echo "7. Install GlobalProtect 6"
echo "8. Install GlobalProtect 5"
echo "9. Install GoogleChrome"
echo "10. Install All Security Tools"
echo "11. Exit"


read -p "Enter your choice (1/2/3/4/5/6/7/8/9/10/11): " choice

case $choice in
1)
echo "Installing McAfee..."
sudo apt update
sudo apt upgrade -y
sudo apt autoremove -y
#install Dell laptop wi-fi drivers below cmd
sudo apt install linux-modules-iwlwifi-generic-hwe-20.04 -y

sudo chmod 777 $(pwd)/installdeb.sh
sudo $(pwd)/installdeb.sh -i
;;
2)
echo "Installing Cortex XDR…"
sudo mkdir -p /etc/panw
sudo cp $(pwd)/cortex.conf /etc/panw/
sudo dpkg -i $(pwd)/cortex-8.1.1.112729.deb
sudo /opt/traps/bin/cytool reconnect force 0414bf527934486697bc55a50e5838f4
;;
3)
echo "Installing Zscaler..."
sudo apt install net-tools libqt5dbus5 libqt5core5a libqt5sql5 libqt5sql5-sqlite libqt5webchannel5 libqt5webengine5 libqt5webenginecore5 libqt5webenginewidgets5 libqt5webkit5 libqt5webview5 libqt5widgets5 libnss3-tools libpcap* ca-certificates -y
sudo chmod +x $(pwd)/Zscaler-linux-1.4.0.79-installer.run
echo  y | sudo $(pwd)/Zscaler-linux-1.4.0.79-installer.run  --unattendedmodeui none --strictEnforcement 1 --policyToken 363035333A353A39653834303965662D626537372D343035362D393863612D633731373165313737326231 --cloudName zscalerthree --userDomain kpit.com
;;
4)
echo "Installing USB block script..."
sudo chmod 777 $(pwd)/USB_Block.sh
sudo $(pwd)/USB_Block.sh
;;
5)
echo "Installing ManageEngine..."
sudo chmod 777  $(pwd)/UEMS_LinuxAgent.bin
sudo $(pwd)/UEMS_LinuxAgent.bin
;;
6)
echo "Installing McAfeeENS..."
sudo $(pwd)/install-mfetp.sh
;;
7)
echo "Installing Globalprotect5..."
sudo apt-get update
sudo apt-get install  libqt5webkit5 -y
Sudo chmod 777 $(pwd)/GlobalProtect_UI_deb-5.1.4.0-9.deb
sudo dpkg -i $(pwd)/GlobalProtect_UI_deb-5.1.4.0-9.deb
echo password | globalprotect import-certificate --location $(pwd)/HIPS_Linux.p12
;;
8)
echo "Installing Globalprotect6..."
sudo apt-get update
sudo apt-get install  libqt5webkit5 -y
sudo chmod 777 $(pwd)/GlobalProtect_UI_focal_deb-6.1.0.0-44.deb
sudo dpkg -i $(pwd)/GlobalProtect_UI_focal_deb-6.1.0.0-44.deb
echo password | globalprotect import-certificate --location $(pwd)/HIPS_Linux.p12
;;
9)
echo "Installing GoogleChrome..."
sudo dpkg -i $(pwd)/google-chrome.deb
;;
10)
echo "Installing All Security Tools..."
sudo apt-get update
#install wifi-drivers in dell laptop
sudo apt install linux-modules-iwlwifi-generic-hwe-20.04 -y

sudo chmod 777 $(pwd)/installdeb.sh
sudo $(pwd)/installdeb.sh -i
sudo mkdir -p /etc/panw
sudo cp $(pwd)/cortex.conf /etc/panw/
sudo dpkg -i $(pwd)/cortex-8.1.1.112729.deb
sudo /opt/traps/bin/cytool reconnect force 0414bf527934486697bc55a50e5838f4
sudo apt install net-tools libqt5dbus5 libqt5core5a libqt5sql5 libqt5sql5-sqlite libqt5webchannel5 libqt5webengine5 libqt5webenginecore5 libqt5webenginewidgets5 libqt5webkit5 libqt5webview5 libqt5widgets5 libnss3-tools libpcap* ca-certificates -y
sudo chmod +x $(pwd)/Zscaler-linux-1.4.0.79-installer.run
echo  y | sudo $(pwd)/Zscaler-linux-1.4.0.79-installer.run  --unattendedmodeui none --strictEnforcement 1 --policyToken 363035333A353A39653834303965662D626537372D343035362D393863612D633731373165313737326231 --cloudName zscalerthree --userDomain kpit.com
sudo chmod 777 $(pwd)/USB_Block.sh
sudo $(pwd)/USB_Block.sh
#sudo chmod 777  $(pwd)/UEMS_LinuxAgent.bin
#sudo $(pwd)/UEMS_LinuxAgent.bin
sudo $(pwd)/install-mfetp.sh
#sudo apt-get update
#sudo apt-get install  libqt5webkit5 -y
#sudo chmod 777 $(pwd)/GlobalProtect_UI_deb-5.1.4.0-9.deb
#sudo dpkg -i $(pwd)/GlobalProtect_UI_deb-5.1.4.0-9.deb
#echo password | globalprotect import-certificate --location $(pwd)/HIPS_Linux.p12
#sudo apt-get update
sudo apt-get install  libqt5webkit5 -y
sudo chmod 777 $(pwd)/GlobalProtect_UI_focal_deb-6.1.0.0-44.deb
sudo dpkg -i $(pwd)/GlobalProtect_UI_focal_deb-6.1.0.0-44.deb
echo password | globalprotect import-certificate --location $(pwd)/HIPS_Linux.p12
sudo dpkg -i $(pwd)/google-chrome.deb
sudo snap install teams-for-linux
sudo echo 10.52.214.74 gitlab.kpit.com >> /etc/hosts/
;;
11)
echo "Exiting the script. Goodbye!" 

exit 0 

;;

*)
 echo "Invalid choice. Please enter a number between 1 and 11." continue 

;; 

esac



  read -p "Installation complete. Do you want to install another software? (yes/no): " continue_installation



  if [ "$continue_installation" != "yes" ]; then

    echo "Exiting the script. Goodbye!"

    exit 0

  fi

done
