
#include "Event.hh"
#include "hit.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4EventManager.hh"
#include "G4HCofThisEvent.hh"
#include "G4VHitsCollection.hh"
#include "G4SDManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4ios.hh"

MyEventAction::MyEventAction() : HCid(0)
{
}

MyEventAction::~MyEventAction()
{
}

void MyEventAction::BeginOfEventAction(const G4Event *)
{

  if (HCid == 0)
  {
    G4SDManager *sdManager = G4SDManager::GetSDMpointer();
    HCid = sdManager->GetCollectionID("Ph_Det/DetectorCollection");
  }
}

void MyEventAction::EndOfEventAction(const G4Event *event)
{
  // Get analysis manager

  G4HCofThisEvent *hce = event->GetHCofThisEvent();

  const DetectorHitsCollection *HC_phantom =
      static_cast<const DetectorHitsCollection *>(hce->GetHC(HCid));

  // G4double n_hit = HC_phantom->entries();

  G4double eDep = 0;
  G4double totalEdep = 0;
  G4double pos = 0;

  for (unsigned long i = 0; i < HC_phantom->GetSize(); i++)
  {
    // DetectorHit *
    auto hit = static_cast<DetectorHit *>(HC_phantom->GetHit(i));
    eDep = hit->GetEdep();
    totalEdep += eDep;
    pos = hit->GetPos();
  }

  G4cout << "Final Edep =" << totalEdep << G4endl;
}
