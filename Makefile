PREFIX=/usr/local

compile: priv.c
	cc -g priv.c -o priv
install: priv
	install -m 4755 ./priv $(PREFIX)/bin/priv
clean: priv
	rm priv
