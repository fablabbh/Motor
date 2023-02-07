/*  This Library Is Brough To You By FABLAB Bahrain <team@fablab.bh>
 *  Written & Maintained By : Ghassan Yusuf <ghassan.yousif.83@gmail.com>
 *  The Library Is Built To Be Used With Hbridge Module L298
 */

// Include The Motor Library
#include <Motor.h>

// Example - Define The Pins That Controls Steering Motor
#define	MOTOR_ENABLE_PIN		6		// Should Be One Of PWM Capable Pin Like ( 3, 5, 6, 9, 10, 11 )
#define	MOTOR_INPUT1_PIN		7		// Can Be Any Digital Pin
#define	MOTOR_INPUT2_PIN		8		// Can Be Any Digital Pin

// Creating The Instance Of Motor Library To Be Used
Motor myMotor(MOTOR_ENABLE_PIN, MOTOR_INPUT1_PIN, MOTOR_INPUT2_PIN);

void setup() {

	Serial.begin(9600);		// Starting Serial Communication

	/*  
	 *  Uncomment The Below Function If you Want To Use The Command Line 
	 *	To Try To Find the Values For The Motor For Min Speed & Max Speed 
	 *  By Typing Numbers And Pressing Enter In the Serial Terminal, the Motor PWM will
	 *  Change As Per The Number You Entered, If You Want To Stop Command Line Typer
	 *  Exit Or EXIT or exit
	 */

	// Assign Tested Values From Command Line For Min And Max
	// myMotor.setMin(myMotor.command(Serial));		// To Set the Minimum Value Of PWM By Trial & Last Value Entered Before Exit Will Be Set
	// myMotor.setMax(myMotor.command(Serial));		// To Set the Maximum Value Of PWM By Trial & Last Value Entered Before Exit Will Be Set

	/*  
	 *  Setting Motor Perameters Before Starting The Motor Operations
	 *	Example : Manually set Value For minimum & maximim motor PWM values
	 */

	// Assign Fixed Values From Command Line For Min And Max
	myMotor.setMin(150);	// Set Min Motor PWM "Min Speed" - Default 0
	myMotor.setMax(225);	// Set Max Motor PWM "Full Speed" - Default 255

	/*  
	 *  Uncomment The Below Function If you Want To Invert The Rotation Of  
	 *	The Motor To Avoid Rewiring The Motor, Software Can Fix It :D 
	 */

	// myMotor.invert();

	// Start Steering Motor Operation
	myMotor.begin();

}

void loop() {
	
	myMotor.forward();		// Set The Direction Of Rotation : Forward

	myMotor.goMax();		// Will drive the Motor With Full Speed

	delay(3000);			// Delay Time Between Previous Command And the Next Command

	myMotor.goMin();		// Will drive the Motor With Full Speed

	delay(3000);			// Delay Time Between Previous Command And the Next Command

	myMotor.goSpeed(195);	// Will drive the Motor With PWM 195 Value

	delay(3000);			// Delay Time Between Previous Command And the Next Command

	myMotor.stop();			// Stop Motor Movement

	delay(3000);			// Delay Time Between Previous Command And the Next Command

	myMotor.backward();		// Set The Direction Of Rotation : Reverse

	myMotor.goMax();		// Will drive the Motor With Full Speed

	delay(3000);			// Delay Time Between Previous Command And the Next Command

	myMotor.goMin();		// Will drive the Motor With Full Speed

	delay(3000);			// Delay Time Between Previous Command And the Next Command

	myMotor.goSpeed(195);	// Will drive the Motor With PWM 195 Value

	delay(3000);			// Delay Time Between Previous Command And the Next Command

	myMotor.stop();			// Stop Motor Movement

	delay(3000);			// Delay Time Between Previous Command And the Next Command

}