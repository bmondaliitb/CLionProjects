
from AthenaCommon.Configurable import ConfigurableCABehavior

from AthenaConfiguration.ComponentAccumulator import ComponentAccumulator
from AthenaConfiguration.ComponentFactory import CompFactory

def MyAlgCfg(flags):
    acc = ComponentAccumulator()

    # Instantiate your algorithm
    MyAlg = CompFactory.MyAlg

    alg = MyAlg("MyAlg")

    acc.addEventAlgo(alg)

    return acc



with ConfigurableCABehavior():
    from AthenaConfiguration.AllConfigFlags import initConfigFlags
    from AthenaConfiguration.MainServicesConfig import MainServicesCfg
    from AthenaCommon.Logging import logging
    from SGComps.SGInputLoaderConfig import SGInputLoaderCfg
    import sys

    log = logging.getLogger('ClusterTruthAlgJobOptions')

    flags = initConfigFlags()
    flags.Input.Files = [
        "/mnt/nvme0n1p4/Data/Project-W-Z/JetEtMissMC23SpecialSamples/Di-jet-pythia8-JZ-sliced/from_Peter_loch/mc16_13TeV.364702.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ2WithSW.recon.ESD.e7142_e5984_s3170_r12638/ESD.25649579._000588.pool.root.1"
        #"/home/mondal/nfs19_mondal/Data/Project-W-Z/JetEtMissMC23SpecialSamples/Di-jet-pythia8-JZ-sliced/from_Peter_loch/mc16_13TeV.364702.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ2WithSW.recon.ESD.e7142_e5984_s3170_r12638/ESD.25649579._000588.pool.root.1"
        #"/home/mondal/nfs19_mondal/Data/Project-W-Z/JetEtMissMC23SpecialSamples/Di-jet-pythia8-JZ-sliced/mc21_14TeV/AOD.40384773._001171.pool.root.1"
        #"/home/mondal/nfs19_mondal/Data/Project-W-Z/JetEtMissMC23SpecialSamples/Di-jet-pythia8-JZ-sliced/mc23_13p6TeV/ESD.34906728._001288.pool.root.1"
    ]
    flags.Exec.MaxEvents = 10
    flags.lock()

    acc = MainServicesCfg(flags)

    from AthenaPoolCnvSvc.PoolReadConfig import PoolReadCfg

    acc.merge(PoolReadCfg(flags))


    acc.merge( MyAlgCfg(flags) )

    log.info("Starting Athena event loop...")
    status = acc.run()

    if not status.isSuccess():
        log.fatal("Athena job failed.")
        sys.exit(1)

    log.info("Athena job finished successfully.")

