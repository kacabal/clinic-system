VPATH = .:db

include db/module.mak

karl:

clean:
	rm -f $(CLEAN_FILES)
