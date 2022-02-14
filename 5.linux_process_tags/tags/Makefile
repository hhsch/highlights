CC=gcc
CFLAGS=-I.
AR=ar

INSTALL_DIR=/usr/local
LIB_DIR=$(INSTALL_DIR)/lib
INCLUDE_DIR=$(INSTALL_DIR)/include
MAN_DIR=$(INSTALL_DIR)/share/man

all: libtags.a

libtags.a: tags.o
	$(AR) -rcs libtags.a tags.o

tags.o: tags.c tags.h
	$(CC) $(CFLAGS) -c -o tags.o tags.c

clean:
	rm -f *.o libtags.a

install: all install_lib install_include install_man

install_include:
	install -d $(INCLUDE_DIR)
	install -m 644 tags.h $(INCLUDE_DIR)
	install -m 644 harness.h $(INCLUDE_DIR)

install_lib:
	install -d $(LIB_DIR)
	install -m 644 libtags.a $(LIB_DIR)

install_man:
	install -d $(MAN_DIR)/man2
	install -m 644 get_tag.2 $(MAN_DIR)/man2
	ln -f $(MAN_DIR)/man2/get_tag.2 $(MAN_DIR)/man2/set_tag.2
	install -d $(MAN_DIR)/man3
	install -m 644 get_tag.3 $(MAN_DIR)/man3
	ln -f $(MAN_DIR)/man3/get_tag.3 $(MAN_DIR)/man3/set_tag.3
	install -d $(MAN_DIR)/man7
	install -m 644 retrieve_get_tag_params.7 $(MAN_DIR)/man7
	ln -f $(MAN_DIR)/man7/retrieve_get_tag_params.7 $(MAN_DIR)/man7/retrieve_set_tag_params.7
	ln -f $(MAN_DIR)/man7/retrieve_get_tag_params.7 $(MAN_DIR)/man7/interpret_get_tag_result.7
	ln -f $(MAN_DIR)/man7/retrieve_get_tag_params.7 $(MAN_DIR)/man7/interpret_set_tag_result.7

.PHONY: all install
