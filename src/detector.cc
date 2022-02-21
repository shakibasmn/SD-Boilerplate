#include "detector.hh"
#include "hit.hh"

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

MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name), fHitsCollection(nullptr), fHCID(-1)

{
    collectionName.insert("DetectorCollection"); // collection name can be an array in case that we have more than one SD
}

MySensitiveDetector::~MySensitiveDetector()
{
}

void MySensitiveDetector::Initialize(G4HCofThisEvent *hce)
{
    fHitsCollection = new DetectorHitsCollection(SensitiveDetectorName, collectionName[0]);

    if (fHCID < 0)
        fHCID = G4SDManager::GetSDMpointer()->GetCollectionID(fHitsCollection); // ID of hit collection

    hce->AddHitsCollection(fHCID, fHitsCollection);

    // fill hits with zero energy deposition
    fHitsCollection->insert(new DetectorHit());
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
        DetectorHit *hit = new DetectorHit();
        G4double Position = aStep->GetPreStepPoint()->GetPosition().z(); //if the particle is neutron
        const G4Track *track = aStep->GetTrack();
        G4double eKin = track->GetKineticEnergy();

        hit->SetEdep(eDeposit);
        hit->SetPos(Position);

        fHitsCollection->insert(hit);//add hit to the hit collection

        // analysisManager->FillH1(0, eKin);
        // analysisManager->FillH2(0, Position, eKin);

        hit->Print();
    }

    return true;
}