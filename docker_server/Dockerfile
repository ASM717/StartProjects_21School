# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/12 12:00:27 by amuriel           #+#    #+#              #
#    Updated: 2021/01/12 17:47:03 by amuriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt update -y
RUN apt upgrade -y

RUN apt install wget vim -y

RUN apt install nginx -y

RUN apt install default-mysql-server -y

RUN apt install wordpress -y

RUN apt install php php-mysql php-fpm php-cli php-mbstring php-zip php-gd -y

ADD https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-all-languages.tar.gz phpmyadmin.tar.gz
RUN tar xvzf phpmyadmin.tar.gz && mv phpMyAdmin-5.0.4-all-languages /var/www/html/phpmyadmin

RUN mv /usr/share/wordpress /var/www/html
COPY ./srcs/wp-config.php /var/www/html/wordpress

RUN rm /var/www/html/index.html
COPY ./srcs/default /etc/nginx/sites-available

COPY ./srcs/config.inc.php /var/www/html/phpmyadmin

RUN openssl req -x509 -nodes -days 365 -subj "/C=RU/ST=Moscow/L=Moscow/O=21 SCHOOL/OU=AMURIEL/CN=certificate ssl html"\
	-newkey rsa:2048\
	-keyout /etc/ssl/private/webkey.key\
	-out /etc/ssl/certs/webkey.crt
RUN chmod -R 600 /etc/ssl/*

COPY ./srcs/start.sh .
COPY ./srcs/database_init.sql .

EXPOSE 80 443

RUN service mysql start && mysql < database_init.sql

ENTRYPOINT bash start.sh
