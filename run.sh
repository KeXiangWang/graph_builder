#!/bin/bash
DEFAULT_CONTROL_FILE_DIRECTORY=./
DEFAULT_DATASET_DIRECTORY=./
DEFAULT_CONTROL_FILE_NAME=/control.txt
DEFAULT_EV_TARGET_DIRECTORY=./
DEFAULT_DICT_TARGET_DIRECTORY=./


control_file=$DEFAULT_CONTROL_FILE_DIRECTORY$DEFAULT_CONTROL_FILE_NAME
ef_directory=$DEFAULT_EV_TARGET_DIRECTORY
dict_dirtectory=$DEFAULT_DICT_TARGET_DIRECTORY
dataset_directory=$DEFAULT_DATASET_DIRECTORY
show_usage="args: [-p , -t ,-c , -o , -d, -D]\
                                  [--control-path=, --control-file-dirctory=, --control-file-name=, --ev-path=, --dict-path=, --dataset-directory=]"

while [ -n "$1" ]
do
        case "$1" in
                -p|--control-path) control_file=$2; shift 2;;
				-t|--control-file-dirctory) control_file=$2$DEFAULT_CONTROL_FILE_NAME; shift 2;;
                -c|--control-file-name) control_file=$DEFAULT_CONTROL_FILE_DIRECTORY$2; shift 2;;
                -o|--ev-path) ef_directory=$2; shift 2;;
                -d|--dict-path) dict_dirtectory=$2; shift 2;;
				-D|--dataset-directory) dataset_directory=$2; shift 2;;
                --) break ;;
                *) echo $1,$2,$show_usage; exit ;
        esac
done

if [ ! -f $control_file ] 
then
	echo "[ERROR]control_file:"$control_file" Not Found!"
	exit
fi



if [ -f CMakeLists.txt ]
then
	echo "[Note]CMakeLists.txt Found"
	if [ -f Makefile ]
	then
		echo "[Note]Makefile Found"
		if [ -f graph_builder ]
		then
			echo "[Note]graph_builder FOUND"
			make
			./graph_builder $control_file $dataset_directory $ef_directory $dict_dirtectory
		else
			make
			./graph_builder $control_file $dataset_directory $ef_directory $dict_dirtectory
		fi
	else
		cmake .
		make
		./graph_builder $control_file $dataset_directory $ef_directory $dict_dirtectory
	fi
else
	echo "CMakeLists.txt Not Found."
fi

# ./run.sh -p ../graph_builder/control_pack.txt -D ../graph_builder -o ./test -d ./test
