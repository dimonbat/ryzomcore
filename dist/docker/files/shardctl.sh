#!/bin/sh

# Used to start multiple services in one container
trap "echo TRAPed signal" HUP INT QUIT TERM

echo "starting services in the background"
/usr/sbin/apache2ctl start

echo "[Press Ctrl + c] or run 'docker stop <container'"
tail -f /var/log/apache2/*.log

echo "stopping services"
/usr/sbin/apache2ctl stop

echo "exited $0"
