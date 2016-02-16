// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "LaunchController.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

LaunchController::LaunchController() : Subsystem("LaunchController") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    cimR = RobotMap::launchControllerCimR;
    cimL = RobotMap::launchControllerCimL;
    trigger = RobotMap::launchControllertrigger;
    lowLimit = RobotMap::launchControllerlowLimit;
    wheelsTop = RobotMap::launchControllerWheelsR;
    wheelsBot = RobotMap::launchControllerWheelsL;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

    moves = 0;
    wheelsTop->SetControlMode(CANSpeedController::kSpeed);
    wheelsTop->SetFeedbackDevice(CANTalon::QuadEncoder);
    wheelsTop->SetPID(1.0, 0.0, 0.0);
    wheelsBot->SetControlMode(CANSpeedController::kSpeed);
    wheelsBot->SetFeedbackDevice(CANTalon::QuadEncoder);
    wheelsBot->SetPID(1.0, 0.0, 0.0);
}

void LaunchController::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void LaunchController::spinToRpm() {
	float F;

	F = ((moves * 80) / (60*100)); // 80 moves per rotation, 60 sec per min, 100 10ms increments per sec| RPM to pos change per 10ms

	wheelsBot->Set(F);
	wheelsTop->Set(F);
}

