# !/bin/bash

#set -e
set -u

##########################################
# Reduction
##########################################

#########
# add
#########

cd ../04_reduction/add/test
./testReductionAdd_int_PI.sh
cd -

cd ../04_reduction/add/test
./testReductionAdd_int_PII.sh
cd -

#########
# generic
#########

cd ../04_reduction/generic/test
./testReduction_int_PI.sh
cd -

cd ../04_reduction/generic/test
./testReduction_int_PII.sh
cd -

cd ../04_reduction/generic/test
./testReduction_long_PII.sh
cd -

##########################################
# Slice
##########################################


cd ../05_slice/test
./testSliceGM_Host.sh
cd -

cd ../05_slice/test
./testSliceGM.sh
cd -

cd ../05_slice/test
./testSliceSM.sh
cd -

##########################################
# Montecarlo
##########################################

#########
# mono
#########

cd ../06_montecarlo/test
./testMontecarlo_int.sh
cd -

cd ../06_montecarlo/test
./testMontecarlo_long.sh
cd -

#########
# multi
#########

####
#thread
####

cd ../07_montecarloMulti/test/thread
./testMontecarlo_multi_thread_int.sh
cd -

cd ../07_montecarloMulti/test/thread
./testMontecarlo_multi_thread_long.sh
cd -

####
#stream
####

cd ../07_montecarloMulti/test/stream
./testMontecarlo_multi_stream_int.sh
cd -

cd ../07_montecarloMulti/test/stream
./testMontecarlo_multi_stream_long.sh
cd -

##########################################
# AddVector
##########################################

cd ../10_vector_stream/test
./testVector_baseline.sh
cd -

cd ../10_vector_stream/test
./testVector_bistream.sh
cd -

cd ../10_vector_stream/test
./testVector_tristream.sh
cd -

##########################################
# Image
##########################################

#########
# Rippling
#########

cd ../01_rippling/test
./testRippling.sh
cd -

#########
# Mandelbrot
#########

cd ../02_mandelbrot/test
./testMandelbrot_double.sh
cd -

cd ../02_mandelbrot/test
./testMandelbrot_float.sh
cd -

cd ../02_mandelbrot/test
./testMandelbrot_half.sh
cd -

#########
# Raytracing
#########

cd ../03_raytracing/test
./testRaytracing_GM.sh
cd -

cd ../03_raytracing/test
./testRaytracing_CM.sh
cd -

cd ../03_raytracing/test
./testRaytracing_SM.sh
cd -

cd ../03_raytracing/test
./testRaytracing_CM2SM.sh
cd -

#########
# Video
#########

cd ../11_video/test
./test_video_gm.sh
cd -

cd ../11_video/test
./test_video_texture_gm.sh
cd -

cd ../11_video/test
./test_video_texture_cuarray.sh
cd -

cd ../11_video/test
./test_video_surface.sh
cd -

#########
# Convolution
#########

#cd ../12_convolution/test
#./testConvolution_base.sh
#cd -

#cd ../12_convolution/test
#./testConvolution_texture_cuArray.sh
#cd -

##########################################
# sleep
##########################################

sleep 59m

##########################################
# end
##########################################

echo ""
echo "Finsihed!"
echo ""
