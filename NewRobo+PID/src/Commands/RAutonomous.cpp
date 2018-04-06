#include <iostream>
#include <Commands/Drive.h>
#include <Commands/AutoDrive.h>
#include <Commands/RAutonomous.h>
#include <Commands/Spin.h>

/**Note:
* To run multiple commands at the same time,
* use AddParallel()
* e.g. AddParallel(new Command1());
*      AddSequential(new Command2());
* Command1 and Command2 will run in parallel.
* Look into Encoders for counting revolution instead of using time.
  **/

RAutonomous::RAutonomous(double timeCo) :
		frc::CommandGroup("autonomousCommand"){

			//AddSequential(new Drive(0, 0.4, 0, 7));//Run Rught
			AddSequential(new Drive( 1, 0, 0, 2)); //Move forward 5*18.85 inches

			/**AddSequential(new Drive( 0, 0, 1, 0.3)); //Turn Right
			AddSequential(new Drive ( 1, 0 ,0 , 1)); //Drive Forward
			AddSequential(new Drive( 0, 0, -1, 0.3)); //Turn Left
			AddSequential(new Drive( 1, 0, 0, 1)); //Move Forward 2.5*18.85 inches
			//AddSequential(new Spin( -1)); //Spit the box out
			 ***/


		/**In case we need this
		*AddSequential(new Drive( 0.5, -1.0, 1.5*timeCo)); //Turn 180 degrees (right)
		*Engage shooting motor for 2 seconds (ideally 1 ball)
		**/

		/**Leave these incase we need it.
		*AddSequential(new Drive( 0.5, -1.0, 0.07*timeCo)); //Turn 9 degrees (left?)
		*Engage shooting motor for 2 seconds (ideally 1 ball)
		*AddSequential(new AutonomousShooting(1, 2*timeCo));
		**/



}
