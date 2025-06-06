FROM debian:12.10

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get -o Acquire::http::Timeout="10" update && apt-get install -y \
    gnupg2 curl software-properties-common apt-transport-https ca-certificates \
    && curl -fsSL https://apt.grafana.com/gpg.key | gpg --dearmor -o /usr/share/keyrings/grafana.gpg \
    && echo "deb [signed-by=/usr/share/keyrings/grafana.gpg] https://apt.grafana.com stable main" > /etc/apt/sources.list.d/grafana.list \
    && apt-get update \
    && apt-get install -y grafana \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /etc/grafana/ssl && \
    openssl req -x509 -nodes -days 365 \
    -newkey rsa:2048 \
    -keyout /etc/grafana/ssl/grafana.key \
    -out /etc/grafana/ssl/grafana.crt \
    -subj "/CN=grafana.gschwart.42.fr"

COPY conf/grafana.ini /etc/grafana/grafana.ini

#RUN ln -sf /dev/stdout /var/log/grafana/grafana.log \
# && ln -sf /dev/stderr /var/log/grafana/grafana.log

EXPOSE 443

WORKDIR /var/lib/grafana

CMD ["/usr/sbin/grafana-server", "--homepath=/usr/share/grafana", "--config=/etc/grafana/grafana.ini"]
