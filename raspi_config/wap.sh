#!/bin/bash
# To be configured on auto boot-up

#checks for root privledges by checking the value of effective UID
#should use "$(id -u)" instead of $EUID since it can be changed by unprivleged user 
if [ "$(id -u)" -ne 0 ]
	then echo "Must be root"
	exit
fi

APPASS="password"
APSSID="SUSI.AI"


apt-get remove --purge hostapd -yqq
apt-get update -yqq
apt-get upgrade -yqq
apt-get install hostapd dnsmasq -yqq

cat > /etc/dnsmasq.conf <<EOF
interface=wlan0
dhcp-range=10.0.0.2,10.0.0.5,255.255.255.0,12h
EOF

cat > /etc/hostapd/hostapd.conf <<EOF
interface=wlan0
hw_mode=g
channel=10
auth_algs=1
wpa=2
wpa_key_mgmt=WPA-PSK
wpa_pairwise=CCMP
rsn_pairwise=CCMP
wpa_passphrase=$APPASS
ssid=$APSSID
ieee80211n=1
wmm_enabled=1
ht_capab=[HT40][SHORT-GI-20][DSSS_CCK-40]
EOF

#replaces "#DAEMON_CONF=" to "DAEMON_CONF=" hence un-commenting it globally
sed -i -- 's/#DAEMON_CONF=""/DAEMON_CONF="\/etc\/hostapd\/hostapd.conf"/g' /etc/default/hostapd

rm -f /etc/network/interfaces.d/wlan-client
cp /etc/network/interfaces.d/wlan.hostap /etc/network/interfaces.d/wlan-hostap

systemctl enable hostapd
systemctl enable dnsmasq

# add server in the auto-boot up list
echo "All done! Rebooting"

sudo reboot
