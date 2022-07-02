#include <iostream>
#include "RooStats/HistFactory/Measurement.h"
#include "RooStats/HistFactory/MakeModelAndMeasurementsFast.h"
#include "TFile.h"
#include "TROOT.h"
#include "TSystem.h"
#include "RooStats/HistFactory/Channel.h"
#include "RooStats/HistFactory/Sample.h"

//using namespace RooStats;
//using namespace HistFactory;

void hf001_example() {


    std::string InputFile = "./data/example.root";
    // in case the file is not found
    bool bfile = gSystem->AccessPathName(InputFile.c_str());
    if (bfile) {
        std::cout << "Input file is not found - run prepareHistFactory script " << std::endl;
        gROOT->ProcessLine(".! prepareHistFactory .");
        bfile = gSystem->AccessPathName(InputFile.c_str());
        if (bfile) {
            std::cout << "Still no " << InputFile << ", giving up.\n";
            exit(1);
        }
    }

    // Create the measurement
    RooStats::HistFactory::Measurement meas("meas", "meas");

    meas.SetOutputFilePrefix( "./results/example_UsingC" );
    meas.SetPOI( "SigXsecOverSM" );
    meas.AddConstantParam("alpha_syst1");
    meas.AddConstantParam("Lumi");

    meas.SetLumi( 1.0 );
    meas.SetLumiRelErr( 0.10 );
    meas.SetExportOnly( false );
    meas.SetBinHigh( 2 );

    // Create a channel

    RooStats::HistFactory::Channel chan( "channel1" );
    chan.SetData( "data", InputFile );
    chan.SetStatErrorConfig( 0.05, "Poisson" );


    // Now, create some samples


    // Create the signal sample
    RooStats::HistFactory::Sample signal( "signal", "signal", InputFile );
    signal.AddOverallSys( "syst1",  0.95, 1.05 );
    signal.AddNormFactor( "SigXsecOverSM", 1, 0, 3 );
    chan.AddSample( signal );

    // Background 1
    RooStats::HistFactory::Sample background1( "background1", "background1", InputFile );
    background1.ActivateStatError( "background1_statUncert", InputFile );
    background1.AddOverallSys( "syst2", 0.95, 1.05  );
    chan.AddSample( background1 );


    // Background 1
    RooStats::HistFactory::Sample background2( "background2", "background2", InputFile );
    background2.ActivateStatError();
    background2.AddOverallSys( "syst3", 0.95, 1.05  );
    chan.AddSample( background2 );


    // Done with this channel
    // Add it to the measurement:
    meas.AddChannel( chan );

    // Collect the histograms from their files,
    // print some output,
    meas.CollectHistograms();
    meas.PrintTree();

    // One can print XML code to an
    // output directory:
    // meas.PrintXML( "xmlFromCCode", meas.GetOutputFilePrefix() );

    // Now, do the measurement
    RooStats::HistFactory::MakeModelAndMeasurementFast( meas );
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    hf001_example();
    return 0;
}
