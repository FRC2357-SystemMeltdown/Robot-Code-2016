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
    lowLimit = RobotMap::launchControllerlowLimit;
    wheelsTop = RobotMap::launchControllerWheelsTop;
    wheelsBot = RobotMap::launchControllerWheelsBot;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS


    wheelsTop->SetControlMode(CANSpeedController::kPercentVbus);
    wheelsTop->SetFeedbackDevice(CANTalon::QuadEncoder);
    wheelsTop->ConfigEncoderCodesPerRev(20);
    wheelsTop->SetSensorDirection(true);
    wheelsBot->SetClosedLoopOutputDirection(true);
    wheelsTop->ConfigNominalOutputVoltage(0.0, 0.0);
    wheelsTop->ConfigPeakOutputVoltage(1.0, -1.0);
    wheelsTop->SelectProfileSlot(0);
    wheelsTop->SetP(0.0);
    wheelsTop->SetI(0.0);
    wheelsTop->SetD(0.0);
    wheelsTop->SetF(1.0);

    wheelsBot->SetControlMode(CANSpeedController::kFollower);
    wheelsBot->SetSensorDirection(true);


    wheelsBot->Set(TOPSHOOTERMOTORCANID);
    wheelsTop->Set(0.0);


}

void LaunchController::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void LaunchController::spinToRpm(float rpm) {
	double d;

	//wheelsTop->SetControlMode(CANSpeedController::kSpeed);
	//wheelsBot->SetControlMode(CANSpeedController::kFollower);


	d = ((rpm) * 80) / 6000;

	wheelsTop->Set(d);
	lastRPM = rpm;

	std::cout << "Launch Controller: Sending " << rpm << " to top shooter wheels." << std::endl;
	std::cout << "Launch Controller: Sensors enabled " << wheelsTop->IsSensorPresent(CANTalon::QuadEncoder) << std::endl;
	//wheelsTop->
}



void LaunchController::SetTopVoltage(float voltage) {
	//wheelsTop->SetControlMode(CANSpeedController::kVoltage);
	wheelsTop->Set(voltage);
	std::cout << "Launch Controller: voltage " << voltage << std::endl;
}

void LaunchController::SetBotVoltage(float voltage) {
	//wheelsBot->SetControlMode(CANSpeedController::kVoltage);
	wheelsBot->Set(voltage);
	std::cout << "Launch Controller: voltage " << voltage << std::endl;
}

void LaunchController::InitForPID() {
	wheelsTop->SetControlMode(CANSpeedController::kSpeed);
	//wheelsTop->SetFeedbackDevice(CANTalon::QuadEncoder);
	//wheelsTop->set
}

float LaunchController::GetLastRPM () {
	return lastRPM;
}

void LaunchController::DisablePID() {
	wheelsTop->SetControlMode(CANSpeedController::kPercentVbus);
}

double LaunchController::GetTopMotorSpeed() {
	return ((wheelsTop->GetSpeed()/80)*600);
}

double LaunchController::GetBotMotorSpeed() {
	return ((wheelsBot->GetSpeed()/80)*600);
}

int LaunchController::GetTopControlMode() {
	return wheelsTop->GetControlMode();
}
