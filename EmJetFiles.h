#include <map>
#include <utility>

// Define map of files here
const string WJetData         = "/afs/cern.ch/user/y/yoshin/eos/cms/store/group/phys_exotica/EmergingJets/SelectedJetAnalysis-v2/WJetSkimMuon/SingleMuon/SelectedJetAnalysis/160219_021859/output_merged_WJetSkimMuon.root";
const string WJet             = "/afs/cern.ch/user/y/yoshin/eos/cms/store/group/phys_exotica/EmergingJets/Analysis-20160301-v0/WJetsToLNuInclusive/WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/Analysis-20160301/160302_022221/ntuple_merged_WJetsToLNuInclusive.root";
const string ModelA           = "/afs/cern.ch/user/y/yoshin/eos/cms/store/group/phys_exotica/EmergingJets/Analysis-20160325-v0/ModelA/EmergingJets_ModelA_TuneCUETP8M1_13TeV_pythia8Mod/Analysis-20160325/160325_192306/ntuple_merged_ModelA.root";
const string ModelB           = "/afs/cern.ch/user/y/yoshin/eos/cms/store/group/phys_exotica/EmergingJets/Analysis-20160325-v0/ModelB/EmergingJets_ModelB_TuneCUETP8M1_13TeV_pythia8Mod/Analysis-20160325/160325_192325/ntuple_merged_ModelB.root";
const string QCD_HT500to700   = "/afs/cern.ch/user/y/yoshin/eos/cms/store/group/phys_exotica/EmergingJets/Analysis-20160325-v0/QCD_HT500to700/QCD_HT500to700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/Analysis-20160325/160325_192349/ntuple_merged_QCD_HT500to700.root";
const string QCD_HT700to1000  = "/afs/cern.ch/user/y/yoshin/eos/cms/store/group/phys_exotica/EmergingJets/Analysis-20160325-v0/QCD_HT700to1000/QCD_HT700to1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/Analysis-20160325/160325_192409/ntuple_merged_QCD_HT700to1000.root";
const string QCD_HT1000to1500 = "/afs/cern.ch/user/y/yoshin/eos/cms/store/group/phys_exotica/EmergingJets/Analysis-20160325-v0/QCD_HT1000to1500/QCD_HT1000to1500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/Analysis-20160325/160325_192429/ntuple_merged_QCD_HT1000to1500.root";
const string QCD_HT1500to2000 = "/afs/cern.ch/user/y/yoshin/eos/cms/store/group/phys_exotica/EmergingJets/Analysis-20160325-v0/QCD_HT1500to2000/QCD_HT1500to2000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/Analysis-20160325/160325_192450/ntuple_merged_QCD_HT1500to2000.root";
const string QCD_HT2000toInf  = "/afs/cern.ch/user/y/yoshin/eos/cms/store/group/phys_exotica/EmergingJets/Analysis-20160325-v0/QCD_HT2000toInf/QCD_HT2000toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/Analysis-20160325/160325_192508/ntuple_merged_QCD_HT2000toInf.root";
const string Data             = "/afs/cern.ch/user/y/yoshin/eos/cms/store/group/phys_exotica/EmergingJets/Analysis-20160325-v0/DataSkim_Run2015-PRv3/JetHT/Analysis-20160325/160325_192525/ntuple_merged_DataSkim_Run2015-PRv3.root";

const bool MC = false;
const bool DATA = true;

struct File {
  std::string name;
  Sample sample;
  bool isData;
  double xsec; // in pb
  double efficiency;
  double error_efficiency;
  bool isSignal; // Set to true for signal MC. Turns on signal histograms
};
// std::string name("/afs/cern.ch/user/y/yoshin/eos/cms/store/group/phys_exotica/EmergingJets/SelectedJetAnalysis-v0/QCD_HT700to1000/QCD_HT700to1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/SelectedJetAnalysis/160121_151706/output_merged_QCD_HT700to1000.root"   );
// File file = {name , 1.0};
// std::string label = "QCD_HT700to1000";
const std::string samples[] = {"ModelA", "ModelB", "QCD", "Data"};
// const std::string samples[] = {"ModelA"};

static std::multimap<std::string, File> files = {
  /* {"WJet"              ,  { WJet             , Sample::WJET   , MC    , 60290  , 1.027381e-01 , 8.630102e-04 , false } } , */
  /* {"WJetData"          ,  { WJetData         , Sample::WJET   , DATA  , 1.0    , 1.0          , 1.0          , false } } , */
  {"ModelA" ,  { ModelA           , Sample::SIGNAL , MC   , 0.0146 , 1.0          , 0.0          , true  } } ,
  {"ModelB" ,  { ModelB           , Sample::SIGNAL , MC   , 0.0146 , 1.0          , 0.0          , true  } } ,
  { "QCD"   ,  { QCD_HT700to1000  , Sample::QCD    , MC   , 6524   , 4.155094e-03 , 2.008417e-05 , false } } ,
  { "QCD"   ,  { QCD_HT1000to1500 , Sample::QCD    , MC   , 1064   , 1.706836e-01 , 4.733912e-04 , false } } ,
  { "QCD"   ,  { QCD_HT1500to2000 , Sample::QCD    , MC   , 121.5  , 4.209039e-01 , 7.314915e-04 , false } } ,
  { "QCD"   ,  { QCD_HT2000toInf  , Sample::QCD    , MC   , 25.45  , 4.695370e-01 , 8.632537e-04 , false } } ,
  { "Data"  ,  { Data             , Sample::SIGNAL , DATA , 1.0    , 1.0          , 0.0          , false } } ,
};