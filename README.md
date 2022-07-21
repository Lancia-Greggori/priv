### Description
priv is a setuid program that takes command-line arguments as a command, checks if the command exists in the whitelist-file with its path hardcoded into it (by default it's /etc/priv.commands).

It also checks for the UID of the user, and compares it to a hardcoded UID value, so that only the authorised user will be able to invoke the program and tell it to execute commands.

### Compilation and installation instructions
The only thing you have to change when compiling the program is to change the **DEFAULT_WHITELIST_FILE** macro in *priv.c* to match your users UID.
For installation simply run:
~~~
$ make
# make install
~~~

### Why use this program over what sudo already provides?
priv is a much more simpler alternative to what sudo already provides if you have a single user and do not care about multi-user functionality.
priv also doesn't ask the user for a password.
