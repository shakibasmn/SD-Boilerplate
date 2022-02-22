#ifndef DETECTOR_HH
#define DETECTOR_HH

#include "G4VSensitiveDetector.hh"
#include "G4SDManager.hh"

class MySensitiveDetector : public G4VSensitiveDetector
{
public:
    MySensitiveDetector(G4String);
    ~MySensitiveDetector();

    void SetEdep(G4double de) { fEdep += de; }
    void SetPos(G4double z) { fPos = z; }
    void Print (G4double , G4double);
    void Edepout (G4double);


    virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);

    G4double fEdep;
    G4double fPos;
};

#endif
