#!/usr/bin/env python

# Read the submission directory as a command line argument. You can
# extend the list of arguments with your private ones later on.
import optparse
parser = optparse.OptionParser()
parser.add_option( '-s', '--submission-dir', dest = 'submission_dir',
                   action = 'store', type = 'string', default = 'submitDir',
                   help = 'Submission directory for EventLoop' )
( options, args ) = parser.parse_args()

# Set up (Py)ROOT.
import ROOT
ROOT.xAOD.Init().ignore()

# Set up the sample handler object. See comments from the C++ macro
# for the details about these lines.
import os
sh = ROOT.SH.SampleHandler()
sh.setMetaString( 'nc_tree', 'CollectionTree' )
inputFilePath = "/cvmfs/atlas.cern.ch/repo/sw/database/GroupData/dev/AnalysisTop/ContinuousIntegration/MC/p4174/mc16_13TeV.410470.PhPy8EG_A14_ttbar_hdamp258p75_nonallhad.deriv.DAOD_TOPQ1.e6337_s3126_r9364_p4174/";
ROOT.SH.ScanDir().filePattern( 'test.pool.root' ).scan( sh, inputFilePath )
sh.printContent()

dataType = "mc"

# Create an EventLoop job.
job = ROOT.EL.Job()
job.sampleHandler( sh )
job.options().setDouble( ROOT.EL.Job.optMaxEvents, 500 )
job.options().setString( ROOT.EL.Job.optSubmitDirMode, 'unique-link')


from MyAnalysis.MyMuonAnalysisAlgorithms import makeSequence
algSeq = makeSequence (dataType)
print algSeq # For debugging
for algMuon in algSeq:
	    job.algsAdd( algMuon )
	    pass


# Create the algorithm's configuration.
from AnaAlgorithm.DualUseConfig import createAlgorithm
alg = createAlgorithm ( 'MyxAODAnalysis', 'AnalysisAlg' )

# later on we'll add some configuration options for our algorithm that go here
#alg.ElectronPtCut = 30000.0
#alg.SampleName = 'Zee'


# Add our algorithm to the job
job.algsAdd( alg )



# Run the job using the direct driver.
driver = ROOT.EL.DirectDriver()
driver.submit( job, options.submission_dir )

# retrieve a histogram from one sample
#sh_hist = ROOT.SH.SampleHandler()
#sh_hist.load (options.submission_dir + '/hist')
#hist = sh_hist.get ('mc16_13TeV.410501.PowhegPythia8EvtGen_A14_ttbar_hdamp258p75_nonallhad.merge.AOD.e5458_s3126_r9364_r9315').readHist('h_jetPt')

# create a canvas, draw the histogram and wait for a
# double click (then continue/end)
#c = ROOT.TCanvas()
#hist.Draw()
#c.Update()
#c.WaitPrimitive()
