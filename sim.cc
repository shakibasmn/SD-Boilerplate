#include <iostream>

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "G4VModularPhysicsList.hh"
#include "QGSP_BIC_HP.hh"
#include "construction.hh"
// #include "physics.hh"
#include "action.hh"

int main(int argc, char **argv)
{
    G4RunManager *runManager = new G4RunManager();

    G4VModularPhysicsList *physicsList = new QGSP_BIC_HP;
    physicsList->SetDefaultCutValue(0.1 * mm);
    runManager->SetUserInitialization(physicsList);

    runManager->SetUserInitialization(new MyDetectorConstruction());
    runManager->SetUserInitialization(new MyActionInitialization());

    // runManager->SetUserInitialization(new MyPhysicsList());

    runManager->Initialize();

    G4UIExecutive *ui = 0;
    if (argc == 1) // if the number of command lines are 1 : only executeable file
    // interactive mode : define UI session
    {
        ui = new G4UIExecutive(argc, argv); // we use ui manager (we see graphic)
    }

    G4VisManager *visManager = new G4VisExecutive();
    visManager->Initialize();
    G4UImanager *UImanager = G4UImanager::GetUIpointer();

    if (ui) // if ui exists we create our graphic output
    {
        UImanager->ApplyCommand("/control/execute vis.mac");
        ui->SessionStart();
    }
    else // if ui does not exits ( number of commandlne is large than one ) we want to take this command line arguments
         // as the name of out input script
    {
        // batch mode
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command + fileName);
    }

    // we can write these commands in the vis.mac file
    // UImanager->ApplyCommand("/vis/open OGL");
    // UImanager->ApplyCommand("/vis/viewer/set/viewpointVector 1 1 1");
    // UImanager->ApplyCommand("/vis/drawVolume");
    // UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true");
    // UImanager->ApplyCommand("/vis/scene/add/trajectories smooth");
    // UImanager->ApplyCommand("/vis/scene/endOfEventAction accumulate 1");

    return 0;
}
