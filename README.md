### Description
priv is a setuid program that takes command-line arguments as a command, checks if the command exists in the config-file with its path hardcoded into it (by default it's /etc/priv.commands).

It also checks for the UID of the user, and compares it to a hardcoded UID value specified at compile time, so that only the authorised user will be able to invoke the program and tell it to execute commands.

### Compilation and installation instructions
The only thing you have to change when compiling the program is to change the DEFAULT_UID macro to match your users UID.
For installations simply run as root:
~~~
# make install
~~~

### Why use this program over what sudo already provides?
priv is a much more simpler alternative to what sudo already provides if you have a single user and do not care about multi-user functionality.
It also doesn't ask the user for a password.
