#ifndef DETECTOR_HH
#define DETECTOR_HH

#include "G4VSensitiveDetector.hh"
#include "Event.hh"
#include "hit.hh"
#include "G4SDManager.hh"


class MySensitiveDetector : public G4VSensitiveDetector
{
public:
    MySensitiveDetector(G4String);
    ~MySensitiveDetector();

private:
    virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);
    virtual void Initialize(G4HCofThisEvent*HCE);

  private:
    DetectorHitsCollection* fHitsCollection;
    G4int fHCID;

};

#endif
