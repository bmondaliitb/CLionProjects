from AnaAlgorithm.AlgSequence import AlgSequence
from AnaAlgorithm.DualUseConfig import createAlgorithm

def makeSequence (dataType) :
    algSeq = AlgSequence()

    sysLoader = createAlgorithm('CP::SysListLoaderAlg', 'SysLoaderAlg')
    sysLoader.sigmaRecommended = 1

    algSeq += sysLoader

    # Include, and then set up the pileup analysis sequence:
    from AsgAnalysisAlgorithms.PileupAnalysisSequence import makePileupAnalysisSequence
    pileupSequence = makePileupAnalysisSequence(dataType)
    pileupSequence.configure(inputName='EventInfo', outputName='EventInfo_%SYS%')

    # Add the pileup sequence to the job:
    algSeq += pileupSequence

    # Include, and then set up the muon analysis algorithm sequence:
    from MuonAnalysisAlgorithms.MuonAnalysisSequence import makeMuonAnalysisSequence
    muonSequenceMedium = makeMuonAnalysisSequence(dataType, deepCopyOutput = True, shallowViewOutput = False,
                                                  workingPoint = 'Medium.Iso', postfix = 'medium')
    muonSequenceMedium.configure(inputName='Muons',
                                 outputName='AnalysisMuonsMedium_%SYS%')

    # Add the sequence to the job:
    algSeq += muonSequenceMedium

    muonSequenceTight = makeMuonAnalysisSequence( dataType, deepCopyOutput = True, shallowViewOutput = False,
                                                  workingPoint = 'Tight.Iso', postfix = 'tight' )
    muonSequenceTight.removeStage ("calibration")
    muonSequenceTight.configure( inputName = 'AnalysisMuonsMedium_%SYS%',
                                 outputName = 'AnalysisMuonsTight_%SYS%',
                                 affectingSystematics = muonSequenceMedium.affectingSystematics())

    # Add the sequence to the job:
    algSeq += muonSequenceTight


    return algSeq
