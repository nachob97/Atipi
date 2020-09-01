#!/bin/bash
for (( count=8; count>=0; count-- ))
do
	echo "ejecución $count:" 
	./main $1 $count ./ImgDUDE-M-arioSimetrico/Img$2M$1.pgm ./Outputs/Img$2M$1_k_$count.pgm
	echo "K=$count" >> ./PSNR/PSNR_$2_$1.txt
	./diffpnm ./ImgDUDE-M-arioSimetrico/Img$2.pgm ./Outputs/Img$2M$1_k_$count.pgm >> ./PSNR/PSNR_$2_$1.txt
	echo >> ./PSNR/PSNR_$2_$1.txt
done