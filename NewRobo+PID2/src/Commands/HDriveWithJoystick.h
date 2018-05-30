#ifndef HDriveWithJoystick_H
#define HDriveWithJoystick_H

#include <Commands/Command.h>


class HDriveWithJoystick : public Command {
public:
	HDriveWithJoystick();
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

};

#endif  // HDriveWithJoystick_H
