// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "ElevatorController.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

ElevatorController::ElevatorController() : Subsystem("ElevatorController") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    windowL = RobotMap::elevatorControllerWindowL;
    windowR = RobotMap::elevatorControllerWindowR;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

    //windowL->ConfigPotentiometerTurns(300/360);
    //windowL->SetFeedbackDevice(CANTalon::AnalogPot);
    windowL->SetControlMode(CANSpeedController::kPercentVbus);
    windowL->ConfigLimitMode(CANSpeedController::kLimitMode_SwitchInputsOnly);
    /*windowL->ConfigFwdLimitSwitchNormallyOpen();
    windowL->ConfigRevLimitSwitchNormallyOpen();*/
    windowR->SetControlMode(CANSpeedController::kFollower);
    windowR->Set(LEFTWINDOWMOTORCANID);



}

void ElevatorController::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

// TODO Set Default Command To move elevation to level.
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void ElevatorController::elevateToTarget(float angle) {
	// 0.01666666666666666666666666666667 V per degree
	float v;
	v = angle * 0.016;
	windowL->Set(v);
	lastAngle = angle;
}

float ElevatorController::GetLastAngle() {
	return lastAngle;
}

void ElevatorController::WindowMotorsUp() {
	windowL->Set(0.4);
	//windowR->Set(0.5);
}

void ElevatorController::WindowMotorsDown() {
	windowL->Set(-0.4);
	//windowR->Set(-0.5);
}

void ElevatorController::StopWindowMotors() {
	windowL->Set(0.0);
	//windowR->Set(0.0);
}
