#ifndef Autonomous_H
#define Autonomous_H

#include <Commands/CommandGroup.h>

class Autonomous : public CommandGroup {
public:
	Autonomous(double timeCo);
};

#endif  // Autonomous_H
