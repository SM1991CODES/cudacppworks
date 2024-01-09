# a makefile is made up of targets, pre-requisites and recipes or commands
# commands say how to build the targets, generally using the pre-requisites

# general syntax:
# target: req1 req2...
#	<tab>command

# each line of command must begin with a tab
# multiple targets depending on the same pre-req can go on same line as:
# target1 target2: req1 req2...
# pre-req can be sources, headers, libraries etc.
# libraries are specified as -l<libname>
# the first target is the default target but a different target can be passed to make on the command line

# here, a cpp file and a .so library as pre-req
mainApp : main.cpp -lpthread
# -c option stops at making the object file, builds and links using g++ command
	g++ main.cpp -lpthread -o mainApp
