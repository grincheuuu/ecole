FROM debian:12.10

 RUN apt-get update && apt-get install -y vsftpd openssl

 COPY /conf/entrypoint.sh /entrypoint.sh
 RUN chmod +x /entrypoint.sh
 ENTRYPOINT ["/entrypoint.sh"]

 RUN useradd -m ftpuser && echo "ftpuser:ftp_password" | chpasswd

 RUN mkdir -p /home/ftpuser/ftp && chown nobody:nogroup /home/ftpuser/ftp && chmod a-w /home/ftpuser/ftp
 RUN mkdir -p /home/ftpuser/ftp/files && chown ftpuser:ftpuser /home/ftpuser/ftp/files

 COPY /conf/vsftpd.conf /etc/vsftpd.conf

 EXPOSE 21
 EXPOSE 40000-40004

 CMD ["/usr/sbin/vsftpd", "/etc/vsftpd.conf"]
