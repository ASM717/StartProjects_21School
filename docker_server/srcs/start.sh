# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    start.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/12 12:04:04 by amuriel           #+#    #+#              #
#    Updated: 2021/01/12 17:33:57 by amuriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

chown -R www-data /var/www/*
chmod -R 755 /var/www/*

service php7.3-fpm start
service nginx start
service mysql start

bash
