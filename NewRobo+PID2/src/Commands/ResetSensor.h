#ifndef ResetSensor_H
#define ResetSensor_H

#include"Commands/Command.h"

class ResetSensor : public Command {
public:
	ResetSensor();
	void Initialize() override;
	bool IsFinished() override;
	void End() override;
};

#endif  // ResetSensor_H
