#!/bin/bash
for (( count=0; count<10; count++ ))
do
	echo "ejecución $count:" 
	echo "./main $1 $2 ./ImgDUDE-M-arioSimetrico/Img$3M$1.pgm ./Filters/Img$3M$1_F_$((count+1)).pgm ./Filters/Img$3M$1_F_$count.pgm"
	./main $1 $2 ./ImgDUDE-M-arioSimetrico/Img$3M$1.pgm ./Filters/Img$3M$1_F_$((count+1)).pgm ./Filters/Img$3M$1_F_$count.pgm 
	echo "Iter=$((count+1))" >> ./Filters/PSNR_$3_$1.txt
	./diffpnm ./ImgDUDE-M-arioSimetrico/Img$3.pgm ./Filters/Img$3M$1_F_$((count+1)).pgm >> ./Filters/PSNR_$3_$1.txt
	echo >> ./Filters/PSNR_$3_$1.txt
done