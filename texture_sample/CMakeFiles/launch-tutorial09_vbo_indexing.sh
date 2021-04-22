#!/bin/sh
bindir=$(pwd)
cd /home/kulpet345/comp_gr/ogl-master/tutorial09_vbo_indexing/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "xYES" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		/usr/bin/gdb -batch -command=$bindir/gdbscript --return-child-result /home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube/tutorial09_vbo_indexing 
	else
		"/home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube/tutorial09_vbo_indexing"  
	fi
else
	"/home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube/tutorial09_vbo_indexing"  
fi
