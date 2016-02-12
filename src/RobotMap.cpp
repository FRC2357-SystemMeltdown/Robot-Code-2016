// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<SpeedController> RobotMap::driveControllerRightSideMotors;
std::shared_ptr<SpeedController> RobotMap::driveControllerLeftSideMotors;
std::shared_ptr<RobotDrive> RobotMap::driveControllerRobotDrive21;
std::shared_ptr<Encoder> RobotMap::launchControllerCimR;
std::shared_ptr<Encoder> RobotMap::launchControllerCimL;
std::shared_ptr<SpeedController> RobotMap::launchControllertrigger;
std::shared_ptr<DigitalInput> RobotMap::launchControllerlowLimit;
std::shared_ptr<CANTalon> RobotMap::launchControllerWheelsTop;
std::shared_ptr<CANTalon> RobotMap::launchControllerWheelsBot;
std::shared_ptr<SpeedController> RobotMap::elevatorControllerElevator;
std::shared_ptr<AnalogPotentiometer> RobotMap::elevatorControllerAnglePot;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    LiveWindow *lw = LiveWindow::GetInstance();

    driveControllerRightSideMotors.reset(new Talon(9));
    lw->AddActuator("DriveController", "RightSideMotors", std::static_pointer_cast<Talon>(driveControllerRightSideMotors));
    
    driveControllerLeftSideMotors.reset(new Talon(8));
    lw->AddActuator("DriveController", "Left Side Motors", std::static_pointer_cast<Talon>(driveControllerLeftSideMotors));
    
    driveControllerRobotDrive21.reset(new RobotDrive(driveControllerLeftSideMotors, driveControllerRightSideMotors));
    
    driveControllerRobotDrive21->SetSafetyEnabled(true);
        driveControllerRobotDrive21->SetExpiration(0.1);
        driveControllerRobotDrive21->SetSensitivity(0.5);
        driveControllerRobotDrive21->SetMaxOutput(1.0);

    launchControllerCimR.reset(new Encoder(0, 1, false, Encoder::k4X));
    lw->AddSensor("LaunchController", "CimR", launchControllerCimR);
    launchControllerCimR->SetDistancePerPulse(0.05);
    launchControllerCimR->SetPIDSourceType(PIDSourceType::kRate);
    launchControllerCimL.reset(new Encoder(2, 3, false, Encoder::k4X));
    lw->AddSensor("LaunchController", "CimL", launchControllerCimL);
    launchControllerCimL->SetDistancePerPulse(0.05);
    launchControllerCimL->SetPIDSourceType(PIDSourceType::kRate);
    launchControllertrigger.reset(new Talon(4));
    lw->AddActuator("LaunchController", "trigger", std::static_pointer_cast<Talon>(launchControllertrigger));
    
    launchControllerlowLimit.reset(new DigitalInput(4));
    lw->AddSensor("LaunchController", "lowLimit", launchControllerlowLimit);
    
    launchControllerWheelsTop.reset(new CANTalon(0));
    lw->AddActuator("LaunchController", "WheelsR", launchControllerWheelsTop);
    
    launchControllerWheelsBot.reset(new CANTalon(1));
    lw->AddActuator("LaunchController", "WheelsL", launchControllerWheelsBot);
    
    elevatorControllerElevator.reset(new TalonSRX(3));
    lw->AddActuator("ElevatorController", "Elevator", std::static_pointer_cast<TalonSRX>(elevatorControllerElevator));
    
    elevatorControllerAnglePot.reset(new AnalogPotentiometer(0, 1.0, 0.0));
    lw->AddSensor("ElevatorController", "AnglePot", elevatorControllerAnglePot);
    


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
