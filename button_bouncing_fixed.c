/* button inverts the led state*/

#define LED_PIN 13;
#define BUTTON_PIN 12;

// botton processing variables and CONSTANTS

boolean flagPress = false;
boolean flagClick = false;
byte buttonCount = 0;
#define TIME_BUTTON 12;

boolean ledState;

void setup(){
	pinMode(LED_PIN, OUTPUT);
	pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop(){

	/* button signal processing
	* when button pressed - flagPress=true
	* when button not pressed - flagPress+false
	* when button pressed flagClick+true*/

	if( flagPress == (!digitalRead(BUTTON_PIN))){
		buttonCount = 0;
	}
	else {
		buttonCount++;

		if (buttonCount >= TIME_BUTTON){
			flagPress=!flagPress;
		buttonCount = 0;
		if (flagPress == true) flagClick = true;
		}
	}

	// led controll 

	if (flagClick == true){
		flagClick = false;
		ledState = !ledState;
		digitalWrite(LED_PIN, ledState);

	}
 delay(2);
}
