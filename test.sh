#!/bin/bash
gcc -o server server.c ft_bzero.c minitalk.h
gcc -o client client.c minitalk.h