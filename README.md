priv is a setuid program that takes a single argument as a command, checks if the given command argument exists in the config-file with its path hardcoded into it (by default it's /etc/priv.commands).

It also checks for the UID of the user, and compares it to a hardcoded UID value specified at compile time, so that only the authorised user will be able to invoke the program and tell it to execute commands.

The only thing you have to change when compiling the program is to change the DEFAULT_UID macro to match your users UID.
