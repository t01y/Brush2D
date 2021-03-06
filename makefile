BUILDPATH=build
APP=$(BUILDPATH)/Virot.app

CONTNPATH=$(APP)/Contents

all:lib install
	open $(APP)

install:main $(CONTNPATH)/MacOS/SDL2.framework
	cp $< $(CONTNPATH)/MacOS/

$(CONTNPATH)/MacOS/SDL2.framework:
	@echo "Loading Frameworks"
	mkdir -p $(CONTNPATH)/{MacOS,Resources}
	cp -R /Library/Frameworks/SDL2.framework $(CONTNPATH)/MacOS/
	cp -R /Library/Frameworks/SDL2_image.framework $(CONTNPATH)/MacOS/
	cp Info.plist $(CONTNPATH)
	cp -R Resources $(CONTNPATH)


.PHONY: clean lib

lib:
	@echo "Make $@"
	@$(MAKE) -C $@ $@

clean:
	@$(MAKE) -C lib $@
	rm -rf $(BUILDPATH)/*
