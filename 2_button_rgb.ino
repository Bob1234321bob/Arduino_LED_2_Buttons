const byte PIN_GREEN = 9;
const byte PIN_BLUE = 10;
const byte PIN_RED = 11;

const byte BUTTON_A = 5;
const byte BUTTON_B = 4;

const int PWM_STEPS = 256;
const int PWM_MAX = PWM_STEPS - 1;

const int stepDelay = 100;

bool button_press = false;

void fadeBetween (byte pinFrom, byte pinTo, int fadeDelay) { 
	for (int i = 0; i < PWM_STEPS; i++) {
		analogWrite (pinFrom, PWM_MAX - i);
		analogWrite (pinTo, i);
		if (digitalRead(BUTTON_A) == LOW) {
			button_press = false;
			break;
		delay (fadeDelay);
	}
}

void setup () {
	pinMode (PIN_RED, OUTPUT);
	pinMode (PIN_BLUE, OUTPUT);
	pinMode (PIN_GREEN, OUTPUT);
	pinMode (BUTTON_A, INPUT_PULLUP);
	pinMode (BUTTON_B, INPUT_PULLUP);
}

void loop () {
	if (digitalRead(BUTTON_A) == LOW) {
		button_press = false;
	}
	else if (digitalRead(BUTTON_B) == LOW) {
		button_press = true;
	}
	if (button_press) {
		fadeBetween (PIN_RED, PIN_BLUE, stepDelay);
		fadeBetween (PIN_BLUE, PIN_GREEN, stepDelay);
		fadeBetween (PIN_GREEN, PIN_RED, stepDelay);
	}
	else {
		analogWrite (PIN_RED, 0);
		analogWrite (PIN_BLUE, 0);
		analogWrite (PIN_GREEN, 0);
	}
}