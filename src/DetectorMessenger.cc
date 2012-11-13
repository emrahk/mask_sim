#include "DetectorMessenger.hh"
#include "DetectorConstruction.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithoutParameter.hh"

DetectorMessenger::DetectorMessenger(DetectorConstruction* myDet)
:detector(myDet)
{ 
	dir = new G4UIdirectory("/mask_sim/");
  dir->SetGuidance("UI commands specific to this example.");
	geoDir = new G4UIdirectory("/mask_sim/geom/");
	geoDir->SetGuidance("Geometry commands are here.");	  
  detDir = new G4UIdirectory("/mask_sim/geom/det/");
  detDir->SetGuidance("detector commands.");
	maskDir = new G4UIdirectory("/mask_sim/geom/mask/");
  maskDir->SetGuidance("mask commands.");

	maskHeightCmd = new G4UIcmdWithADoubleAndUnit("/mask_sim/geom/mask/height",this);
  maskHeightCmd->SetGuidance("Set the height of the mask.");
  maskHeightCmd->SetUnitCategory("Length");
  maskHeightCmd->SetParameterName("choice",false);
  maskHeightCmd->AvailableForStates(G4State_PreInit);

	maskPixSizeCmd = new G4UIcmdWithADoubleAndUnit("/mask_sim/geom/mask/pixSize",this);
  maskPixSizeCmd->SetGuidance("Set the height of the mask.");
  maskPixSizeCmd->SetUnitCategory("Length");
  maskPixSizeCmd->SetParameterName("choice",false);
  maskPixSizeCmd->AvailableForStates(G4State_PreInit);

	detDistToMaskCmd = new G4UIcmdWithADoubleAndUnit("/mask_sim/geom/det/distToMask",this);
  detDistToMaskCmd->SetGuidance("Set the height of the mask.");
  detDistToMaskCmd->SetUnitCategory("Length");
  detDistToMaskCmd->SetParameterName("choice",false);
  detDistToMaskCmd->AvailableForStates(G4State_PreInit);

	updateCmd = new G4UIcmdWithoutParameter("/mask_sim/geom/update",this);
  updateCmd->SetGuidance("Updates geometry.");
  updateCmd->AvailableForStates(G4State_Idle);
}

DetectorMessenger::~DetectorMessenger()
{
	delete dir;
	delete geoDir;
	delete detDir;
	delete maskDir;
	delete maskHeightCmd;
}

void DetectorMessenger::SetNewValue(G4UIcommand* cmd, G4String val)
{
	if (cmd == maskHeightCmd)
	{
		detector->SetMaskHeight(maskHeightCmd->GetNewDoubleValue(val));		
	}
	else if (cmd == maskPixSizeCmd)
	{
		detector->SetMaskPixSize(maskPixSizeCmd->GetNewDoubleValue(val));		
	}
	else if (cmd == detDistToMaskCmd)
	{
		detector->SetDetDistToMask(detDistToMaskCmd->GetNewDoubleValue(val));		
	}
	else if (cmd == updateCmd)
	{
		detector->UpdateGeometry();		
	}
}