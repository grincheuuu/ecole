#!/bin/bash
set -e

# Créer l'utilisateur seulement s'il n'existe pas déjà
if ! id ftpuser &>/dev/null; then
    useradd -m ftpuser
    echo "${FTP_USER}:${FTP_PASSWORD}" | chpasswd
fi

# Créer les dossiers FTP s'ils n'existent pas
mkdir -p /home/ftpuser/ftp/files
chown ftpuser:ftpuser /home/ftpuser/ftp/files

exec /usr/sbin/vsftpd /etc/vsftpd.conf
