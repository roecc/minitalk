#!/bin/bash
gcc -o server server.c ft_bzero.c ft_itoa.c ft_strdup.c ft_strlen.c minitalk.h
gcc -o client client.c minitalk.h