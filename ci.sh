#!/bin/bash

run_ccore_job() {
	echo "CI Job (travis CI): CCORE (C++ code library compilation)"
	
	cd ccore/
	make ccore
	
	if [ $? -eq 0 ] ; then
		echo "ccore library creation... success"
	else
		echo "ccore library creation... fail"
		exit 1
	fi
}

run_utcore_job() {
	echo "CI Job (travis CI): UT CORE (C++ code unit-testing)"
	
	cd ccore/
	make utcore
	
	if [ $? -eq 0 ] ; then
		echo "ccore library creation... success"
	else
		echo "ccore library creation... fail"
		exit 1
	fi
	
	# run unit-tests
	cd utcore/
	./utcore
}

run_python_job() {
	echo "CI Job (travis CI): PYCLUSTERING (Python code unit-testing)"
	cd /

	# set current folder where installed library is located
	library_folder="`python -c \"import os, pyclustering; print(os.path.dirname(pyclustering.__file__))\"`/*";
	cd $library_folder

	# run unit-tests with code coverage
	coverage run pyclustering/ut/__init__.py
	coveralls
}

set -e
set -x

case $PYCLUSTERING_TARGET in
	CCORE) 
		run_ccore_job ;;
		
	UTCORE) 
		run_utcore_job ;;
		
	PYTHON) 
		run_python_job ;;
		
	*)
		echo "CI Job (travis CI): Unknown target $PYCLUSTERING_TARGET"
		exit 1 ;;
esac
