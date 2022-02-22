
#include "Event.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4EventManager.hh"
#include "G4HCofThisEvent.hh"
#include "G4VHitsCollection.hh"
#include "G4SDManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4ios.hh"

MyEventAction::MyEventAction()
{
}

MyEventAction::~MyEventAction()
{
}

void MyEventAction::BeginOfEventAction(const G4Event *)
{
}

void MyEventAction::EndOfEventAction(const G4Event *event)
{
  
}
