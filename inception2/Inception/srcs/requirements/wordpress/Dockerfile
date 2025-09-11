FROM debian:12.10

 RUN apt update && apt upgrade -y \
 && apt-get install -y wget curl unzip \
 php8.2\
 php8.2-fpm\
 php8.2-mysql\
 mariadb-client
 
 RUN mkdir -p /var/www/html \
 && wget https://fr.wordpress.org/wordpress-6.8-fr_FR.tar.gz -P /tmp \
 && tar -xzf /tmp/wordpress-6.8-fr_FR.tar.gz -C /tmp \
 && mv /tmp/wordpress/* /var/www/html/ \
 && chown -R www-data:www-data /var/www/html \
 && rm -rf /tmp/wordpress /tmp/wordpress-6.8-fr_FR.tar.gz

 RUN PHPVER=$(php -r 'echo PHP_MAJOR_VERSION.".".PHP_MINOR_VERSION;') \
 && sed -i 's|^listen = .*|listen=wordpress:9000|' /etc/php/$PHPVER/fpm/pool.d/www.conf \
 && echo "clear_env = no" >> /etc/php/$PHPVER/fpm/pool.d/www.conf

 RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
 && chmod +x wp-cli.phar \
 && mv wp-cli.phar /usr/local/bin/wp

 RUN apt-get install -y php8.2-redis

 RUN ln -sf /dev/stdout /var/log/php8.2-fpm.log

 COPY conf/www.conf /etc/php/8.2/fpm/pool.d/www.conf
 COPY conf/entrypoint.sh /entrypoint.sh

 RUN chmod u+x /entrypoint.sh

 EXPOSE 9000

 ENTRYPOINT ["/entrypoint.sh"]
