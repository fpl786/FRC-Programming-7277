#ifndef Drive_H
#define Drive_H

#include "Robot.h"
#include "Commands/Command.h"
#include "Timer.h"

class Drive : public Command {
public:
	Drive(double moveValue, double rotateValue, double timeout);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End( )override;
	void Interrupted() override;
private:
	double moveValue;
	double rotateValue;
	double timeout;
};

#endif  // Drive_H
