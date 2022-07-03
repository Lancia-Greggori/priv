compile: priv.c
	cc -g priv.c -o priv
install: priv
	install -m 4755 ./priv /usr/local/mbin/priv
clean: priv
	rm priv
