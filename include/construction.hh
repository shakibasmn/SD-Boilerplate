#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include"detector.hh"
#include "G4SDManager.hh"

class MyDetectorConstruction : public G4VUserDetectorConstruction
{
public:
    MyDetectorConstruction();
    ~MyDetectorConstruction();

    virtual G4VPhysicalVolume *Construct();

private:
    G4Box *solidWorld, *solidBox , *soliddet;
    G4LogicalVolume *logicWorld, *logicBox , *logicdet;
    G4VPhysicalVolume *physWorld, *physBox , *physdet;
    virtual void ConstructSDandField();
};

#endif