
#include "hit.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4ios.hh"
#include <fstream>

G4ThreadLocal G4Allocator<DetectorHit> *DetectorHitAllocator;

DetectorHit::DetectorHit() : G4VHit(), fEdep(0.)
{
}

DetectorHit::~DetectorHit()
{
}

const DetectorHit &DetectorHit::operator=(const DetectorHit &right)
{
  fEdep = right.fEdep;
  return *this;
}

G4bool DetectorHit::operator==(const DetectorHit &right) const
{
  return true;
}

void DetectorHit::Print()
{
  std::ofstream file;
  file.open("output.csv"/*, std::ios::app*/);

  file << "z[cm] = , " << fPos / cm << " , E[MeV]= ," << fEdep / MeV << G4endl; // Position/cm <<  << eKin/MeV <<
  file.close();
}
