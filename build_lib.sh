gcc -c collision.c -o collision.o
ar -rc libcollision.a collision.o
rm collision.o