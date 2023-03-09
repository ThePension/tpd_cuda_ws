# !/bin/bash

set -e
set -u

##########################################
# Reduction
##########################################

#########
# add
#########

cd ../04_reduction/add/use
./reductionAdd_int_PI.sh
cd -

cd ../04_reduction/add/use
./reductionAdd_int_PII.sh
cd -

#########
# generic
#########

cd ../04_reduction/generic/use
./reduction_int_PI.sh
cd -

cd ../04_reduction/generic/use
./reduction_int_PII.sh
cd -

cd ../04_reduction/generic/use
./reduction_long_PII.sh
cd -

##########################################
# Slice
##########################################

cd ../05_slice/use
./sliceGM_Host.sh
cd -

cd ../05_slice/use
./sliceGM.sh
cd -

cd ../05_slice/use 
./sliceSM.sh
cd -

##########################################
# Montecarlo
##########################################

#########
# mono
#########

cd ../06_montecarlo/use
./montecarlo_int.sh
cd -

cd ../06_montecarlo/use
./montecarlo_long.sh
cd -

#########
# multi
#########

####
#thread
####

cd ../07_montecarloMulti/use/thread
./montecarlo_multi_thread_int.sh
cd -

cd ../07_montecarloMulti/use/thread
./montecarlo_multi_thread_long.sh   
cd -

####
#stream
####

cd ../07_montecarloMulti/use/stream
./montecarlo_multi_stream_int.sh
cd -

cd ../07_montecarloMulti/use/stream
./montecarlo_multi_stream_long.sh   
cd -

##########################################
# AddVector
##########################################

cd ../10_vector_stream/use
./vector_baseline.sh
cd -

cd ../10_vector_stream/use
./vector_bistream.sh
cd -

cd ../10_vector_stream/use
./vector_tristream.sh
cd -

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
