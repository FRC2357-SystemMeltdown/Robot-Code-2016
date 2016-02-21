#ifndef panToCenter_H
#define panToCenter_H


#include "WPILib.h"
#include "../Robot.h"
#include "Commands/Subsystem.h"

class panToCenter: public PIDCommand
{
public:
	panToCenter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

protected:
	double ReturnPIDInput();
	void UsePIDOutput(double output);


};

#endif
