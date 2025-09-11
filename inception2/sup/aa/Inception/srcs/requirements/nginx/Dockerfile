FROM debian:12.10

 RUN apt update && apt upgrade -y \
    && apt install -y nginx openssl \
    && echo "Mise à jour des paquets terminée"

 RUN mkdir -p /var/www/html
 RUN chown -R www-data:www-data /var/www/html
 RUN chmod -R 755 /var/www/html

 RUN mkdir -p /etc/ssl/private /etc/ssl/certs /etc/nginx/ssl \
    && echo "Répertoires créés avec succès"

# Vérification de l'installation de nginx
 RUN nginx -v

 ADD . /srcs/requirements/nginx
 WORKDIR  /srcs/requirements/nginx

 RUN openssl req -x509 -nodes -newkey rsa:2048 \
    -keyout /etc/ssl/private/selfsigned.key \
    -out /etc/ssl/certs/selfsigned.crt \
    -days 365 \
    -subj "/C=FR/ST=LeHavre/L=LeHavre/O=42/OU=student/CN=gschwart.42.fr"

 COPY conf/nginx.conf /etc/nginx/
 COPY ./tools/index.html /var/www/html/index.html

 RUN ln -sf /dev/stdout /var/log/nginx/access.log && \
 ln -sf /dev/stderr /var/log/nginx/error.log

 EXPOSE 443

 CMD ["nginx", "-g", "daemon off;"]
