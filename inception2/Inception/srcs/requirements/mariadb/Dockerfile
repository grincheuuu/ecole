FROM debian:12.10

 RUN apt update && apt upgrade -y \
 && apt install mariadb-server -y

 ADD . /srcs/requirements/mariadb

 WORKDIR  /srcs/requirements/mariadb

 RUN mkdir -p /var/run/mysqld \
 && chown -R mysql:mysql /var/run/mysqld

 COPY conf/50-server.cnf	/etc/mysql/mariadb.conf.d/50-server.cnf
 COPY conf/entrypoint.sh /entrypoint.sh

 RUN chmod +x /entrypoint.sh

 EXPOSE 3306
 VOLUME /var/lib/mysql

 ENTRYPOINT ["/entrypoint.sh"]