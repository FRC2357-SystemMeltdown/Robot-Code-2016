// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef LAUNCHCONTROLLER_H
#define LAUNCHCONTROLLER_H
#define TOPSHOOTERMOTORCANID 0
#define BOTSHOOTERMOTORCANID 1
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class LaunchController: public Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<DigitalInput> lowLimit;
	std::shared_ptr<CANTalon> wheelsTop;
	std::shared_ptr<CANTalon> wheelsBot;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	float lastRPM = 0.0;

public:
	LaunchController();
	void InitDefaultCommand();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
	void spinToRpm(float rpm);
	void SetTopVoltage(float voltage);
	void SetBotVoltage(float voltage);
	void InitForPID();
	float GetLastRPM();
	void DisablePID();
	double GetTopMotorSpeed();
	double GetBotMotorSpeed();
	int GetTopControlMode();


	//float moves;
};

#endif
