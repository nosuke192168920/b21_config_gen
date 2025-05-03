CC = gcc
CFLAGS = -O2 -Wall -Wno-unused-result -g
CPPFLAGS = -I.
LDFLAGS =

TARGET = b21_config_gen

OBJS = b21_config_gen.o

all: $(TARGET)

.c.o:
	$(CC) $(CPPFLAGS) $(CFLAGS) $(FLAGS) -c $<


b21_config_gen: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

b21_config_gen.o: title_sjis.txt title_utf8.txt

title_sjis.txt: title_utf8.txt
	iconv -f UTF-8 -t SJIS $< > $@


clean:
	rm -f *.o *~ $(TARGET) title_sjis.txt


