#include "panToCenter.h"

panToCenter::panToCenter() :
						PIDCommand(0.1, 0.0, 0.2) // 0.01, .001, 0.2
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::pixyController.get());

}

// Called just before this Command runs the first time
void panToCenter::Initialize()
{
	Robot::pixyController->PixyReset();
	GetPIDController()->Reset();
	PIDCommand::GetPIDController()->Enable();
	PIDCommand::GetPIDController()->SetContinuous(false);
	PIDCommand::GetPIDController()->SetPIDSourceType(PIDSourceType::kDisplacement);
	PIDCommand::GetPIDController()->SetInputRange(0.0, 320.0);
	PIDCommand::GetPIDController()->SetOutputRange(-2.0, 2.0);
	PIDCommand::GetPIDController()->SetPercentTolerance(5);
	PIDCommand::GetPIDController()->SetSetpoint(160.0);

}

// Called repeatedly when this Command is scheduled to run
void panToCenter::Execute()
{
	GetPIDController()->SetSetpoint(160);
}

// Make this return true when this Command no longer needs to run execute()
bool panToCenter::IsFinished()
{
	return GetPIDController()->OnTarget();
}

// Called once after isFinished returns true
void panToCenter::End()
{
	PIDCommand::GetPIDController()->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void panToCenter::Interrupted()
{
	End();
}

double panToCenter::ReturnPIDInput(){
	Robot::pixyController->Update();
	std::cout << "PID Input: " << Robot::pixyController->GetBlockX() << std::endl;
	return Robot::pixyController->GetBlockX();
}

void panToCenter::UsePIDOutput(double output){
	//if(!GetPIDController()->OnTarget()){

		std::cout << "PID Output: " << output << ", " << Robot::pixyController->GetServoPanAngle() << ", " << Robot::pixyController->GetServoPanAngle() - output <<std::endl;
		Robot::pixyController->SetServoPanAngle(Robot::pixyController->GetServoPanAngle() - output);
		std::cout << "On Target = " << GetPIDController()->OnTarget() << std::endl;
		std::cout << "==========" << std::endl;
	//}
}
