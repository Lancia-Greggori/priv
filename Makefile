PREFIX=/usr/local

priv: priv.c
	cc priv.c -o priv
	strip priv
debug: priv.c
	cc -g priv.c -o priv
install: priv
	install -m 4755 priv $(PREFIX)/bin/
clean: 
	rm priv
uninstall:
	rm $(PREFIX)/bin/priv
