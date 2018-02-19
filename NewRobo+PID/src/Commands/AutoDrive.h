#ifndef AutoDrive_H
#define AutoDrive_H

#include "Robot.h"
#include "Commands/Command.h"
#include "Timer.h"

#include <SmartDashboard/SmartDashboard.h>

class AutoDrive : public Command {
public:
	AutoDrive(double leftMoveValue, double rightMoveValue);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End( )override;
	void Interrupted() override;
private:
	double leftMoveValue;
	double rightMoveValue;

};

#endif  // AutoDrive_H
