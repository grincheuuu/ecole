FROM debian:12.10

 RUN apt update && apt upgrade -y \
 && apt install -y php php-mysqli wget

 RUN mkdir -p /var/www/html \
 && wget "https://www.adminer.org/latest.php" -O /var/www/html/index.php

 EXPOSE 8080

CMD ["php", "-S", "0.0.0.0:8080", "-t", "/var/www/html"]
