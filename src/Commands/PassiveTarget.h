#ifndef PassiveTarget_H
#define PassiveTarget_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class PassiveTarget: public Command
{
public:
	PassiveTarget();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
