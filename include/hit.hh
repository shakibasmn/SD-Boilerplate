
#ifndef DetectorHit_h
#define DetectorHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "G4LogicalVolume.hh"
#include "G4Transform3D.hh"
#include "G4RotationMatrix.hh"
#include "G4Threading.hh"



class DetectorHit : public G4VHit
{
  public:
    DetectorHit();
    virtual ~DetectorHit();

     const DetectorHit& operator=(const DetectorHit &right);
     G4bool operator==(const DetectorHit &right) const;
    
    inline void *operator new(size_t);
    inline void operator delete(void *aHit);
    
    virtual void Print();

    void SetEdep(G4double de) { fEdep += de; }
    G4double GetEdep() const { return fEdep; }
    
    void SetPos(G4double z) { fPos = z; }
    G4double GetPos() const { return fPos; }
    
  private:
    G4double fEdep;
    G4double fPos;

};


using DetectorHitsCollection = G4THitsCollection<DetectorHit>; //hit collector definition

extern G4ThreadLocal G4Allocator<DetectorHit>* DetectorHitAllocator;


inline void* DetectorHit::operator new(size_t)
{
  if (!DetectorHitAllocator) {
       DetectorHitAllocator = new G4Allocator<DetectorHit>;
  }
  return (void*)DetectorHitAllocator->MallocSingle();
}

inline void DetectorHit::operator delete(void* aHit)
{
  DetectorHitAllocator->FreeSingle((DetectorHit*) aHit);
}


#endif
