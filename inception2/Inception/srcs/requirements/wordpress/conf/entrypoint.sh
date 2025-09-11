#!/bin/bash
set -e

sleep 10
echo "⏳ Attente de MariaDB ..."

cd /var/www/html

if [ ! -f wp-load.php ]; then
    echo "📥 Téléchargement de WordPress..."
    wp core download --locale=fr_FR --allow-root
fi

# ✅ Vérifie si WordPress est déjà installé
if [ ! -f wp-config.php ]; then
    echo "🛠️ Création du fichier wp-config.php..."

    wp config create \
        --dbname="${MYSQL_DATABASE}" \
        --dbuser="${MYSQL_USER}" \
        --dbpass="${MYSQL_PASSWORD}" \
        --dbhost="${MYSQL_HOST}" \
        --path="/var/www/html" \
        --allow-root

    echo "⚙️ Installation de WordPress..."

    wp core install \
        --url="${WP_URL}" \
        --title="${WP_TITLE}" \
        --admin_user="${WP_ADMIN}" \
        --admin_password="${WP_ADMIN_PASSWORD}" \
        --admin_email="${WP_ADMIN_EMAIL}" \
        --path="/var/www/html" \
        --allow-root

	wp user create "${WP_USER}" "${WP_USER_EMAIL}" \
					--allow-root \
					--role=author \
					--user_pass="${WP_USER_PASS}"

else
    echo "✅ WordPress est déjà configuré, on ne refait rien."
fi

echo "📦 Installation et configuration du plugin Redis..."

wp plugin install redis-cache --activate --allow-root
wp config set WP_REDIS_HOST redis --type=constant --allow-root
wp config set WP_REDIS_PORT 6379 --raw --type=constant --allow-root
wp config set WP_REDIS_TIMEOUT 3 --raw --type=constant --allow-root
wp config set WP_REDIS_READ_TIMEOUT 3 --raw --type=constant --allow-root
wp config set WP_REDIS_DATABASE 0 --raw --type=constant --allow-root

wp redis enable --allow-root


echo "🚀 Lancement de PHP-FPM..."
exec php-fpm8.2 -F
