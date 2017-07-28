TEST = ../../../out/c/test

default:
	g++ -g main.c -I/home/swpcme/file/source/swpcme/hub/include/hub/ \
	-I/home/swpcme/file/source/swpcme/hub/include/gdal/unix \
	-L/home/swpcme/me/usr/lib -lgdal -lcurl -lgsl -lhub -o $(TEST)

run:
	$(TEST)
