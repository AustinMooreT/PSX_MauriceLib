all:
	del main.exe
	ccpsx -Xm -O3 -Xo$80010000 lib\LIBCD.LIB lib\LIBDS.LIB lib\mmgmnew.obj src\maint.c src\fbuff.c src\otables.c src\cd.c -omain.cpe
	cpe2x /ce main.cpe
	del main.cpe
