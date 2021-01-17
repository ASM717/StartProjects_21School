# 21_school_projects | Author name AMURIEL

My own ft_printf 100%
=====================
Makefile compile library libftprintf.a, that include function ft_printf()

Prototype:

int ft_printf(const char *fmt, ...);

Describe:

    Displays to console symbols like printf(stdio.h) (man printf).

    Realise types: %c, %s, %p, %d, %i, %u, %x and %X

    Realise flags: 0 - *(width) .(precision, works with *).
--------------------------------------------------------------------------
get_next_line 115%
=====================
libft - library 115%
=====================
ft_server (docker server) 100%
=========================
Dockerfile that sets up an nginx server. It must run a Wordpress with a MySQL database and and PHPMyAdmin.
How to use it

Make sure Docker Desktop is running and you are in the docker_server directory.

To build the docker image, run :

	docker build -t server .

The image is now created. To start an instance of it, run :

	docker run -p 80:80 -p 443:443 -d server
------------------------------------------------------------
If you want to switch autoindex(on \ off) -> cd etc/nginx/sites-availiable/default (open file with VIM) 
and correct this. Next you should use /nginx -s reload 

[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com) [![forthebadge](https://forthebadge.com/images/badges/built-with-love.svg)](https://forthebadge.com)
