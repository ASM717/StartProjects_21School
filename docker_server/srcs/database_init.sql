# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    init_database.sql                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amuriel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/12 12:06:42 by amuriel           #+#    #+#              #
#    Updated: 2021/01/12 12:07:22 by amuriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CREATE DATABASE database_server;
CREATE USER 'amuriel'@'localhost' IDENTIFIED BY 'amuriel21';
GRANT ALL PRIVILEGES ON database_server.* TO 'amuriel'@'localhost';
FLUSH PRIVILEGES;
