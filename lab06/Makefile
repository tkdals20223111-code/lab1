CC = gcc
CFLAGS = -Wall -g -fPIC
LIBDIR = lib

OBJS = $(LIBDIR)/add.o \
       $(LIBDIR)/subtract.o \
       $(LIBDIR)/multiply.o \
       $(LIBDIR)/divide.o

.PHONY: all clean

all: static_app shared_app dynamic_app

$(LIBDIR)/%.o: $(LIBDIR)/%.c $(LIBDIR)/calc.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBDIR)/libcalc.a: $(OBJS)
	ar rcs $@ $(OBJS)

$(LIBDIR)/libcalc.so: $(OBJS)
	$(CC) -shared -o $@ $(OBJS)

static_app: main.c $(LIBDIR)/libcalc.a
	$(CC) $(CFLAGS) main.c $(LIBDIR)/libcalc.a -o $@

shared_app: main.c $(LIBDIR)/libcalc.so
	$(CC) $(CFLAGS) main.c -L./lib -lcalc -Wl,-rpath,'$$ORIGIN/lib' -o $@

dynamic_app: dynamic_main.c $(LIBDIR)/libcalc.so
	$(CC) $(CFLAGS) dynamic_main.c -ldl -o $@

clean:
	rm -f $(LIBDIR)/*.o $(LIBDIR)/*.a $(LIBDIR)/*.so
	rm -f static_app shared_app dynamic_app
