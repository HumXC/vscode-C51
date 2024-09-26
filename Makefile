CC = sdcc
cname = $(target)
$(cname).hex : $(cname).ihx
	packihx tmp/$(cname).ihx > output/$(cname).hex

$(cname).ihx : src/$(cname).c
	$(CC) src/$(cname).c -o tmp/$(cname).ihx

.PHONY : clean
clean :
	rm tmp/*.asm
	rm tmp/*.ihx
	rm tmp/*.lk
	rm tmp/*.lst
	rm tmp/*.map
	rm tmp/*.mem
	rm tmp/*.rel
	rm tmp/*.rst
	rm tmp/*.sym

flash: 
	echo "Flashing to port $(port)..."; \
	python3 ./stcflash.py -p $(port) output/$(cname).hex ; \
 

port ?= COM3