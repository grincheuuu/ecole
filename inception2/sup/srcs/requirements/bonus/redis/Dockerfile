FROM debian:12.10

 RUN apt-get update && apt-get upgrade -y && \
    apt-get install -y lsb-release curl gnupg && \
    curl -fsSL https://packages.redis.io/gpg | gpg --dearmor -o /usr/share/keyrings/redis-archive-keyring.gpg && \
    chmod 644 /usr/share/keyrings/redis-archive-keyring.gpg && \
    echo "deb [signed-by=/usr/share/keyrings/redis-archive-keyring.gpg] https://packages.redis.io/deb $(lsb_release -cs) main" \
        | tee /etc/apt/sources.list.d/redis.list && \
    apt-get update && \
    apt-get install -y redis && \
    apt-get clean && rm -rf /var/lib/apt/lists/* && \
    echo "✅ Redis installé avec succès !"

 COPY /conf/redis.conf /etc/redis/redis.conf

 EXPOSE 6379

 CMD ["redis-server", "/etc/redis/redis.conf"]