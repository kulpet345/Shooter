#!/bin/sh
bindir=$(pwd)
cd /home/kulpet345/comp_gr/ogl-master/tutorial12_extensions/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "xYES" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		/usr/bin/gdb -batch -command=$bindir/gdbscript --return-child-result /home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube/tutorial12_extensions 
	else
		"/home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube/tutorial12_extensions"  
	fi
else
	"/home/kulpet345/comp_gr/ogl-master/tutorial05_textured_cube/tutorial12_extensions"  
fi
