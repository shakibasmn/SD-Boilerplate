
#ifndef EventAction_h
#define EventAction_h

#include "G4UserEventAction.hh"
#include "globals.hh"

class MyEventAction : public G4UserEventAction
{
public:
  MyEventAction();
  virtual ~MyEventAction();

  virtual void BeginOfEventAction(const G4Event *);
  virtual void EndOfEventAction(const G4Event *);

  // virtual void Print();

private:
};

#endif
