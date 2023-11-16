FROM	debian:bullseye

RUN		apt-get update
RUN		apt-get install -y nginx openssl

RUN mkdir /etc/nginx/ssl
RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
       -out /etc/nginx/ssl/eros-gir.crt \
       -keyout /etc/nginx/ssl/eros-gir.key \
       -subj "/C=ES/ST=Barcelona/L=Barcelona/O=42 School/OU=eros-gir/CN=eros-gir.42.fr/"

COPY ./conf/nginx.conf /etc/nginx/conf.d

RUN mkdir -p /run/nginx

EXPOSE	443

CMD ["nginx", "-g", "daemon off;"]