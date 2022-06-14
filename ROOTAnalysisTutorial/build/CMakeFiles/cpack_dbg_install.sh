#!/usr/bin/bash
#
# Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
#
# Script used for installing a project for CPack. Hiding any build errors
# from the package generator.
#

# Turn off error reporting:
set +e

# Set the output directory:
OUTDIR=${DESTDIR}/usr/UserAnalysis/1.0.0/InstallArea/x86_64-centos7-gcc8-opt

# Create the bin and lib directories:
/home/bmondal/local_software/clion-2020.2.3/bin/cmake/linux/bin/cmake -E make_directory ${OUTDIR}/bin
/home/bmondal/local_software/clion-2020.2.3/bin/cmake/linux/bin/cmake -E make_directory ${OUTDIR}/lib

# Copy the debug files into the place CPack expects to find them:
/home/bmondal/local_software/clion-2020.2.3/bin/cmake/linux/bin/cmake -E copy /home/bmondal/CLionProjects/ROOTAnalysisTutorial/build/x86_64-centos7-gcc8-opt/bin/*.dbg \
    ${OUTDIR}/bin/
/home/bmondal/local_software/clion-2020.2.3/bin/cmake/linux/bin/cmake -E copy /home/bmondal/CLionProjects/ROOTAnalysisTutorial/build/x86_64-centos7-gcc8-opt/lib/*.dbg \
    ${OUTDIR}/lib/

# Exit gracefully:
exit 0
