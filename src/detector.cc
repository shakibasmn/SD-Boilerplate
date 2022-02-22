#include "detector.hh"
#include "RunAction.hh"

#include "G4SystemOfUnits.hh"
#include "G4Track.hh"
#include "G4HCofThisEvent.hh"
#include "G4TouchableHistory.hh"
#include "G4Track.hh"
#include "G4Step.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"
#include "G4Neutron.hh"
#include "G4Proton.hh"
#include "G4Gamma.hh"
#include "g4analysis.hh"

MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name)

{
}

MySensitiveDetector::~MySensitiveDetector()
{
}

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{
    G4StepPoint *point1 = aStep->GetPreStepPoint();
    G4TouchableHandle touch1 = point1->GetTouchableHandle();
    G4VPhysicalVolume *volume = touch1->GetVolume();
    G4String volname = volume->GetName();
    G4double steplength = aStep->GetStepLength();
    G4double eDeposit = aStep->GetTotalEnergyDeposit();
    G4ThreeVector displace = aStep->GetDeltaPosition();
    G4double tof = aStep->GetDeltaTime();

    // if (G4Neutron::NeutronDefinition() == aStep->GetTrack()->GetDefinition())
    {
        G4double Position = aStep->GetPreStepPoint()->GetPosition().z();
        const G4Track *track = aStep->GetTrack();
        G4double eKin = track->GetKineticEnergy();

        G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();

        analysisManager->FillH1(0, eKin);
        analysisManager->FillH2(0, Position, eKin);

    }

    return true;
}
