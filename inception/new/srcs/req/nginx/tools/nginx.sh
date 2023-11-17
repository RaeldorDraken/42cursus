#!/bin/sh

if [! -f /etc/ssl/certs/nginx.crt]; then
	echo "No certificate found, generating one..."
	openssl req -x509 -nodes -days 365 -newkey rsa:4096 -keyout /etc/ssl/private/nginx.key -out /etc/ssl/certs/nginx.crt -subj "/C=ES/ST=Barcelona/L=Barcelona/O=wordpress/CN=eros-gir.42.fr";
	echo "Certificate generated."
fi

exec "$@"