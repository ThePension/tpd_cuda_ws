#bin/bash

set -e
set -u

#------------------------------------------------------------------------------------
#		tools
#------------------------------------------------------------------------------------

function workspace_delete_symlink_local()
    {
    pushd .>/dev/null
 
    cd ..
    WORKSPACE_ROOT=$(pwd)

    #echo "WORKSPACE_ROOT ="$WORKSPACE_ROOT

    cd ./BUILDER/makefile/private/script/workspace_auto

    ./workspace_symlink_locale_delete.sh $WORKSPACE_ROOT

    cd $WORKSPACE_ROOT/BUILDER

    popd >/dev/null
    }

#------------------------------------------------------------------------------------
#		main
#------------------------------------------------------------------------------------

workspace_delete_symlink_local

#------------------------------------------------------------------------------------
#		end
#------------------------------------------------------------------------------------
