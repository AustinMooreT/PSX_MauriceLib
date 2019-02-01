all:
	del main.exe
	ccpsx -O3 -Xo$80010000 lib\mmgmnew.obj src\maint.c src\fbuff.c src\otables.c -omain.cpe
	cpe2x /ce main.cpe
	del main.cpe
