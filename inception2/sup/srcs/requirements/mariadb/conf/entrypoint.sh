#!/bin/bash

set -e

: "${MYSQL_ROOT_PASSWORD:?Variable MYSQL_ROOT_PASSWORD non définie}"
: "${MYSQL_DATABASE:?Variable MYSQL_DATABASE non définie}"
: "${MYSQL_USER:?Variable MYSQL_USER non définie}"
: "${MYSQL_PASSWORD:?Variable MYSQL_PASSWORD non définie}"

# Initialise la base si nécessaire
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "📦 Initialisation de la base de données..."
    chown -R mysql:mysql /var/lib/mysql
	mysql_install_db --basedir=/usr --datadir=/var/lib/mysql --user=mysql --rpm > /var/log/mysql_install.log 2>&1
fi
    echo "🚀 Démarrage temporaire de MariaDB en mode sans mot de passe..."
    mysqld_safe --skip-grant-tables --user=mysql &
    pid="$!"

    sleep 10

    echo "🔧 Configuration de la base de données..."
    mysql --user=root <<-EOSQL
        FLUSH PRIVILEGES;
        DELETE FROM mysql.user WHERE User='';
        DROP DATABASE IF EXISTS test;
        FLUSH PRIVILEGES;

        ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
        CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
        CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
        GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
        FLUSH PRIVILEGES;
EOSQL

    echo "🛑 Arrêt de MariaDB temporaire..."
    mysqladmin --user=root --password="${MYSQL_ROOT_PASSWORD}" shutdown

echo "✅ Démarrage final de MariaDB..."
exec mysqld_safe --user=mysql
