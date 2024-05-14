echo blacklist usb_storage >> /etc/modprobe.d/blacklist.conf
echo blacklist uas >> /etc/modprobe.d/blacklist.conf
sed -i '26iGRUB_CMDLINE_LINUX_DEFAULT="quiet splash modprobe.blacklist=nouveau"' /etc/default/grub
update-grub2
update-initramfs -u
