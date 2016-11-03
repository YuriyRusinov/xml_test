CC = g++
LD = g++
CFLAGS = -g -fPIC -Wall -std=c++11
TMPDIR = .tmp
INCPATH = -I$(TMPDIR) -I/usr/include
LDFLAGS = -lm -ltinyxml2
RM = rm
MKDIR = mkdir -p
DESTDIR = ./bin
all: $(DESTDIR)/prog

$(DESTDIR)/prog: $(TMPDIR)/main.o $(TMPDIR)/author.o $(TMPDIR)/article.o $(TMPDIR)/imatrix.o
	$(MKDIR) $(DESTDIR)
	$(LD) $(LDFLAGS) -o $@ $^

$(TMPDIR)/main.o: main.cpp 
	$(MKDIR) $(TMPDIR)
	$(CC) -c $(CFLAGS) $(INCPATH) $< -o $@

$(TMPDIR)/%.o: %.cpp %.h
	$(CC) -c $(CFLAGS) $(INCPATH) $< -o $@

clean:
	$(RM) -f $(DESTDIR)/prog $(TMPDIR)/*.o $(TMPDIR)/moc_*.cpp $(TMPDIR)/ui_*.h $(TMPDIR)/qrc_*.cpp

install:

uninstall:

