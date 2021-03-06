// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<Joystick> controller;
	std::shared_ptr<JoystickButton> b;
	std::shared_ptr<JoystickButton> x;
	std::shared_ptr<JoystickButton> btnDecreaseRPM;
	std::shared_ptr<JoystickButton> btnIncreaseRPM;
	std::shared_ptr<JoystickButton> fireButton;
	std::shared_ptr<Joystick> stickRight;
	std::shared_ptr<Joystick> stickLeft;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:
	OI();

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES

	std::shared_ptr<Joystick> getstickLeft();
	std::shared_ptr<Joystick> getstickRight();
	std::shared_ptr<Joystick> getcontroller();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES
	float getstickLeftY();
	float getstickRightY();
	float getControllerLeftX();
	float getControllerLeftY();

	bool getControllerButton(uint32_t i);

	//double targetRPM;
	//double targetElevation;

	//NetworkTable *netTable;

};

#endif
