
#include "RunAction.hh"
#include "Event.hh"

#include "G4Run.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "g4analysis.hh"
//#include "Analysis.hh"


RunAction::RunAction(MyEventAction* eventAction) : G4UserRunAction(),fEventAction(eventAction)
{ 
  // Create the analysis manager using a new factory method.
  // The choice of analysis technology is done via the function argument.
  auto analysisManager = G4Analysis::ManagerInstance("root");
  //G4cout << "Using " << analysisManager->GetType() << G4endl;

  analysisManager->SetVerboseLevel(1);
  analysisManager->SetFileName("Histograms");

 

// Step information
  analysisManager->CreateH1("0","Energy Spectrum",80,0,40.*MeV); 
// analysisManager->CreateH1("1","Total Energy Spectrum",80,0,40.*MeV);
  analysisManager -> CreateH2 ("0","2D Energy Spectrum", 55,-11.*cm,11.*cm,80,0,40.*MeV); 
  
 // Final information 
  // analysisManager -> CreateH2 ("1","2D Total Energy Spectrum", 55,-11.*cm,11.*cm,80,0,40.*MeV);
  // analysisManager -> CreateH2 ("2","2D Total Energy Spectrum",80,-1,39.*MeV, 10, 0., 2.);  

}



RunAction::~RunAction()
{
  delete G4AnalysisManager::Instance();  
}



void RunAction::BeginOfRunAction(const G4Run* /*run*/)
{ 

  
  // Get analysis manager
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

  // Open an output file 
  // The default file name is set in RunAction::RunAction(),
  // it can be overwritten in a macro
  analysisManager->OpenFile();
}



void RunAction::EndOfRunAction(const G4Run* )
{
  // save histograms 
  //
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager->Write();
  analysisManager->CloseFile();

}

