#include "action.hh"
#include "RunAction.hh"


MyActionInitialization::MyActionInitialization()
{
}

MyActionInitialization::~MyActionInitialization()
{
}

void MyActionInitialization::Build() const
{
    MyPrimaryGenerator *generator = new MyPrimaryGenerator();
    SetUserAction(generator);

    MyEventAction *event = new MyEventAction();
    SetUserAction(event);

    RunAction * run = new RunAction (event);
    SetUserAction(run);

}