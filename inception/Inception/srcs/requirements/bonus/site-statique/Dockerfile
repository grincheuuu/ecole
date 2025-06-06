FROM debian:12.10

 RUN apt update && apt upgrade -y \
    && apt install -y nginx openssl \
    && echo "Mise à jour des paquets terminée"

 RUN nginx -v

 ADD . /srcs/requirements/bonus/site-statique
 WORKDIR  /srcs/requirements/bonus/site-statique

 RUN openssl req -x509 -nodes -newkey rsa:2048 \
    -keyout /etc/ssl/private/selfsigned.key \
    -out /etc/ssl/certs/selfsigned.crt \
    -days 365 \
    -subj "/C=FR/ST=LeHavre/L=LeHavre/O=42/OU=student/CN=gschwart.42.fr"

 COPY conf/nginx.conf /etc/nginx/
 COPY ./tools/index.html /var/www/html/index.html
 COPY ./tools/fichier.css /var/www/html/
 COPY ./tools/pages/ /var/www/html/
 COPY ./tools/images/ /var/www/html/

 RUN ln -sf /dev/stdout /var/log/nginx/access.log && \
 ln -sf /dev/stderr /var/log/nginx/error.log

 EXPOSE 8443

 CMD ["nginx", "-g", "daemon off;"]
