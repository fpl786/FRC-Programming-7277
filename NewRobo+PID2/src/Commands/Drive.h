#ifndef Drive_H
#define Drive_H

#include "Robot.h"
#include "Commands/Command.h"
#include "Timer.h"

#include <SmartDashboard/SmartDashboard.h>

class Drive : public Command {
public:
	Drive(double yMoveValue, double xMoveValue, double rotateValue, double timeout);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End( )override;
	void Interrupted() override;
private:
	double yMoveValue;
	double rotateValue;
	double xMoveValue;
	double timeout;
};

#endif  // Drive_H
