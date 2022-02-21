#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{
}

MyDetectorConstruction::~MyDetectorConstruction()
{
}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
  G4NistManager *nist = G4NistManager::Instance();

  G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");
  G4Material *boxMat = nist->FindOrBuildMaterial("G4_WATER");

  solidWorld = new G4Box("solidWorld", 0.5 * m, 0.5 * m, 0.5 * m);

  logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");

  physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true);

  solidBox = new G4Box("abox", 10. * cm, 10. * cm, 10. * cm);
  logicBox = new G4LogicalVolume(solidBox, boxMat, "logicbox");
  physBox = new G4PVPlacement(0, G4ThreeVector(0., 0., 20. * cm), logicBox, "physbox", logicWorld, false, 0);

  // soliddet = new G4Box("detBox", 0.5 * cm, 0.5 * cm, 0.5 * cm);
  // logicdet = new G4LogicalVolume(soliddet, boxMat, "logicdet");
  // physdet = new G4PVPlacement(0, G4ThreeVector(-5 * cm + (i + 0.5) * cm, -5 * cm + (j + 0.5) * cm, 30 * cm), logicdet, "physDetector", logicWorld, false, j + i * 10, true);


  return physWorld;
}

void MyDetectorConstruction::ConstructSDandField()
{
  G4SDManager *SDMan = G4SDManager::GetSDMpointer();
  G4VSensitiveDetector *sensDet = new MySensitiveDetector("/Ph_Det");
  SDMan->AddNewDetector(sensDet);
  logicBox->SetSensitiveDetector(sensDet);
}
