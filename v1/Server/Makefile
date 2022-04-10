COMPILER = gcc
EX = .c

OBJdir = bin
HDRdir = include
SRCdir = src

FLAGS = -Wall
LIBPATHES = -L "/opt/homebrew/Cellar/cunit/2.1-3/lib/"
INCPATHES = -I "/opt/homebrew/Cellar/cunit/2.1-3/include/"
LINKERS = -lcunit


obj = $(patsubst $(SRCdir)/%$(EX), $(OBJdir)/%.o, $(wildcard $(SRCdir)/*))
hdr = $(wildcard $(HDRdir)/*)

build: $(OBJdir)/run

run: $(OBJdir)/run
	./$^

clean:
	@if find $(OBJdir) -mindepth 1 -maxdepth 1 | read; then rm $(OBJdir)/*; fi

$(OBJdir)/run: $(obj)
	$(COMPILER) $^ -o $@ $(LINKERS) $(LIBPATHES)

$(OBJdir)/%.o: $(SRCdir)/%$(EX) $(hdr)
	$(COMPILER) -c $< -o $@ -I "$(HDRdir)/" $(FLAGS) $(INCPATHES)

%.run: $(SRCdir)/%$(EX) $(hdr)
	$(COMPILER) $< -o $(OBJdir)/$@ -I "$(HDRdir)/" $(FLAGS) $(INCPATHES) $(LIBPATHES) $(LINKERS)
	./$(OBJdir)/$@
