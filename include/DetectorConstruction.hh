/**************************************************************************
* DetectorConstruction.hh (Yigit Dallilar)
*
***************************************************************************/

#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "DetectorMessenger.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4LogicalVolume.hh"
#include "globals.hh"

class SensitiveDetector;
class G4Element;

class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
  
    DetectorConstruction();
   ~DetectorConstruction();
     
    G4VPhysicalVolume* Construct();                 
		void SetMaskHeight(G4double);
		void SetMaskPixSize(G4double);
		void SetDetDistToMask(G4double);
		void SetMaskOn(G4bool);
		void SetDetectorOn(G4bool);
		void SetInclboxOn(G4bool);
		void SetAlBoxCoverOn(G4bool);
		void SetCollimatorType(G4int);
		void SetSourceHolderType(G4int);
		void UpdateGeometry();

		G4double GetWorldSize() {return worldSize;}; 
		G4double GetmaskHeight() {return maskHeight;}; 
		G4double GetmaskPixSize() {return maskPixSize;}; 
		G4double GetdetDistToMask() {return detDistToMask;}; 
		G4bool GetMaskOn() {return maskOn;};
		G4bool GetDetectorOn() {return detectorOn;};
		G4bool GetInclboxOn() {return inclboxOn;};
		G4bool GetAlBoxCoverOn() {return AlBoxCoverOn;};
		G4int GetCollimatorType() {return collimatorType;};
		G4int GetSourceHolderType() {return sourceHolderType;};

  private:
  
		void ConstructAlBoxCover();
		void ConstructInclinedBox();
		void ConstructMask();   
		void ConstructDetector(); 
		void ConstructCollimator(G4int);
		void ConstructSourceHolder(G4int);
		void DefineMaterials();

		G4double detDistToMask;
		G4double maskPixSize;
		G4double maskHeight;   
    G4double worldSize;
		G4bool maskOn;
		G4bool detectorOn;
		G4bool inclboxOn;
		G4bool AlBoxCoverOn;
		G4int collimatorType;
		G4int sourceHolderType;
		
		G4int calls;
		DetectorMessenger* detMess;

		G4RotationMatrix* rotm;

  	G4Material* Air; G4Material* Pb;
  	G4Material* Al;  G4Element* Cd;
  	G4Element* Zn;  G4Element* Te;
  	G4Material* CdZnTe;

		G4LogicalVolume* detect_log;

		G4VPhysicalVolume* mask_phys; 
		G4VPhysicalVolume* detect_phys; 
		G4VPhysicalVolume* inclbox_phys;
		G4VPhysicalVolume* AlBoxCover_phys;

		G4VSolid* World_sol;						G4LogicalVolume* World_log;		
    G4VPhysicalVolume* World_phys;  

		SensitiveDetector* sensDet;
};

#endif

