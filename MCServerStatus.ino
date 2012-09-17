///////////////////////////////
//   MCServerStatus Arduino  //
// THIS IS NEW UNTESTED CODE //
//      by jackwilsdon       //
///////////////////////////////

// Online & Offline LED Pins
int onlineLED = 6;
int offlineLED = 7;

// Incoming data holder
int incomingByte = 0;

void setup() {

	// Set LEDS to output
	pinMode(onlineLED, OUTPUT);
	pinMode(offlineLED, OUTPUT);
	
	// Configure serial
	Serial.begin(9600);
	
	// Set server to offline
	digitalWrite(onlineLED, LOW);
	digitalWrite(offlineLED, HIGH);
}

boolean isOnline(int in) {

	// If input code is 49 (1)
	if (in == 49) {
		return true; // Server is online
	} else {
		return false; // Server is offline
	}
}

void setStatus(int stat) {
	
	// If status is 1 (server is online)
	if (stat == 1) {
		digitalWrite(onlineLED, HIGH); // Turn online LED on
		digitalWrite(offlineLED, LOW); // Turn offline LED off
	} else {
	// The server is offline
		digitalWrite(onlineLED, HIGH); // Turn online LED off
		digitalWrite(offlineLED, LOW); // Turn offline LED on
	}
}

void loop() {
	
	// If data is being sent
	if (Serial.available() > 0) {
		
		// Read the data
		incomingByte = Serial.read();
		
		// Check if server is online
		if (isOnline(incomingByte)) {
			setStatus(1); // Set server status
		} else {
			setStatus(0); // Set server status
		}
	}
}
