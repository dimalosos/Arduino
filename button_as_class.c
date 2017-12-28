// button code implemented as a class

#define LED_PIN 13
#define BUTTON_PIN 12

class Button{
 public:
 	boolean flagPress;
 	boolean flagClick;
 	void scanState();
 	void setPinTime(byte pin, byte timeButton);

 private:
 	byte _buttonCount;
 	byte _timeButton;
 	byte _pin;
};

boolean ledState;

Button button1;

void setup(){
	pinMode(LED_PIN, OUTPUT);
	button1.setPinTime(BUTTON_PIN, 15);
}

void loop(){
	
	button1.scanState();

	if(button1.flagClick == true){
		button1.flagClick = false;
		ledState = !ledState;
		digitalWrite(LED_PIN, ledState);
	}
	delay(2);
}

void Button::scanState(){
	if (flagPress == (!digitalRead(_pin))){
		_buttonCount = 0;
	}
	else{
		_buttonCount++;

		if (_buttonCount >= _timeButton){
			flagPress = !flagPress;
			_buttonCount = 0;

		if (flagPress == true) flagClick = true;
		}
	}
}

void Button::setPinTime(byte pin, byte timeButton){

	_pin = pin;
	_timeButton = timeButton;
	pinMode(_pin, INPUT_PULLUP);
}
