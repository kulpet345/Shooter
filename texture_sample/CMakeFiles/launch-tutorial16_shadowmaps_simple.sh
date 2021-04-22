#!/bin/sh
bindir=$(pwd)
cd /home/kulpet345/comp_gr/ogl-master/tutorial16_shadowmaps/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "xYES" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		/usr/bin/gdb -batch -command=$bindir/gdbscript --return-child-result /home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube/tutorial16_shadowmaps_simple 
	else
		"/home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube/tutorial16_shadowmaps_simple"  
	fi
else
	"/home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube/tutorial16_shadowmaps_simple"  
fi