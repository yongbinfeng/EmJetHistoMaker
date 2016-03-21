// Base class for program to loop over single file and fill histograms with arbitrary weights
#include "BaseClass.h"
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TTree.h>
#include <TStopwatch.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TMath.h>

#include <cassert>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using std::string;

class HistoMakerBase : protected BaseClass
{
  public:
    HistoMakerBase() {};
    ~HistoMakerBase();
    virtual void OpenOutputFile (string ofilename);
    virtual void InitHistograms() = 0;
    virtual void FillHistograms(long eventnumber) = 0;
    virtual void WriteHistograms();
    virtual int SetTree(string ifilename) = 0;
    void LoopOverCurrentTree ();

  protected:
    int reportEvery_ = 10000;
    TFile* ofile_;
    TTree* tree_; // Current tree
    long nentries_; // Number of entries in current tree
    TStopwatch timer_total_;
    TStopwatch timer_;
};

// Copied from BaseClass::Loop()
void HistoMakerBase::LoopOverCurrentTree()
{
  if (fChain == 0) {
    std::cout << "Invalid tree!" << std::endl;
    return;
  }
  nentries_ = fChain->GetEntriesFast();
  if ( nentries_ == 0 ) {
    std::cout << "No entries!" << std::endl;
    return;
  }
  else {
    std::cout << "Number of entries: " << nentries_ << std::endl;
  }

  Long64_t nbytes = 0, nb = 0;
  timer_total_.Start();
  // Loop over all events in TChain
  for (Long64_t jentry = 0; jentry < nentries_; jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;

    // Do stuff with one entry of the TTree
    if ( jentry % reportEvery_ == 0 ) {
      if (jentry!=0) std::cout << "Chunk processing time (s): " << timer_.RealTime() << std::endl;
      timer_.Start();
      std::cout << "Running over global entry: " << jentry << std::endl;
    }
    // Fill histograms
    FillHistograms(jentry);
  }
  double total_time_elapsed = timer_total_.RealTime();
  std::cout << "Total processing time (s): " << total_time_elapsed << std::endl;
  std::cout << std::endl;
}

void HistoMakerBase::OpenOutputFile(string ofilename)
{
  ofile_ = new TFile(ofilename.c_str(), "RECREATE");
  InitHistograms();
}

void HistoMakerBase::WriteHistograms()
{
  ofile_->Write();
}

HistoMakerBase::~HistoMakerBase()
{
  delete ofile_;
}
