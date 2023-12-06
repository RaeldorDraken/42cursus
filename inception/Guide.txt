instalar debian 11 en vmware no poner gnome como interfaz grafica usar
la otra opcion "Xfce"

luego ir a esta web que es una buena guia para instalar docker:

https://dev.to/calvinqc/the-easiest-docker-docker-compose-setup-on-compute-engine-1op1

se ha de cambiar el host en:
/etc/hosts

usar comando:

$>	sudo vim /etc/hosts

para editarlo y anyadir esta linea:

127.0.0.1	eros-gir.42.fr

antes de hacer funcionar hacer "make" para inicar el docker se ha de hacer esto:

sudo usermod -aG docker $USER
newgrp docker
id -nG
sudo service docker restart
