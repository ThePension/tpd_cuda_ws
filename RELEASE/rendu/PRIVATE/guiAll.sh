# !/bin/bash

set -e
set -u

##########################################
# Rippling
##########################################

cd ../01_rippling/use
./rippling.sh &
cd -

##########################################
# Mandelbrot
##########################################

cd ../02_mandelbrot/use
./mandelbrot_float.sh &
cd -

cd ../02_mandelbrot/use
./mandelbrot_double.sh &
cd -

cd ../02_mandelbrot/use
./mandelbrot_half.sh &
cd -

##########################################
# Raytracing
##########################################

cd ../03_raytracing/use
./raytracingGM.sh &
cd -

cd ../03_raytracing/use
./raytracingGM2SM.sh &
cd -

cd ../03_raytracing/use
./raytracingCM.sh &
cd -

cd ../03_raytracing/use
./raytracingCM2SM.sh &
cd -

##########################################
# DemoCube3D
##########################################

cd ../09_demoCube3D
./demo_cube3D.sh &
cd -

#cd ../09_demoCube3D
#./demo_cube3D_video.sh &
#cd -

##########################################
# Mandelbrot
##########################################

cd ../08_mandelbrot3D
./mandelbrot3D.sh &
cd -

##########################################
# Video
##########################################

cd ../11_video/use
./video_gm.sh &
cd -

cd ../11_video/use
./video_texture_gm.sh &
cd -

cd ../11_video/use
./video_texture_cuarray.sh &
cd -

cd ../11_video/use
./video_surface.sh &
cd -

##########################################
# Convolution
##########################################

#cd ../12_convolution/use
#./convolution_base.sh &
#cd -

#cd ../12_convolution/use
#./convolution_texture_cuArray.sh &
#cd -

##########################################
# end
##########################################

echo ""
echo "Finsihed!"
echo ""
