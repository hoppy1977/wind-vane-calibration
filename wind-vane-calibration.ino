//#include <Wire.h> //I2C needed for sensors

// analog I/O pins
const byte WDIR = A0;

void setup()
{
	Serial.begin(9600);

	pinMode(WDIR, INPUT);

	Serial.println("Weather vane calibration online!");
}

void loop()
{
	get_wind_direction();

	delay(100); //Update every 100ms. No need to go any faster.
}

int get_wind_direction()
// read the wind direction sensor, return heading in degrees
{
	unsigned int adc;

	adc = averageAnalogRead(WDIR); // get the current reading from the sensor

	Serial.println();
	Serial.print("WindDirectionVoltage: ");
	Serial.println(adc);

	// The following table is ADC readings for the wind direction sensor output, sorted from low to high.
	// Each threshold is the midpoint between adjacent headings. The output is degrees for that ADC reading.
	// Note that these are not in compass degree order! See Weather Meters datasheet for more information.

	int windDirection = -1;

	if (adc < 380)
	{
		windDirection = 113;
		return (windDirection);
	}
	if (adc < 393)
	{
		windDirection = 68;
		return (windDirection);
	}
	if (adc < 414)
	{
		windDirection = 90;
		return (windDirection);
	}
	if (adc < 456)
	{
		windDirection = 158;
		return (windDirection);
	}
	if (adc < 508)
	{
		windDirection = 135;
		return (windDirection);
	}
	if (adc < 551)
	{
		windDirection = 203;
		return (windDirection);
	}
	if (adc < 615)
	{
		windDirection = 180;
		return (windDirection);
	}
	if (adc < 680)
	{
		windDirection = 23;
		return (windDirection);
	}
	if (adc < 746)
	{
		windDirection = 45;
		return (windDirection);
	}
	if (adc < 801)
	{
		windDirection = 248;
		return (windDirection);
	}
	if (adc < 833)
	{
		windDirection = 225;
		return (windDirection);
	}
	if (adc < 878)
	{
		windDirection = 338;
		return (windDirection);
	}
	if (adc < 913)
	{
		windDirection = 0;
		return (windDirection);
	}
	if (adc < 940)
	{
		windDirection = 293;
		return (windDirection);
	}
	if (adc < 967)
	{
		windDirection = 315;
		return (windDirection);
	}
	if (adc < 990)
	{
		windDirection = 270;
		return (windDirection);
	}

	windDirection = -1; // error, disconnected?

	Serial.println();
	Serial.print("WindDirection: ");
	Serial.println(windDirection);

	return windDirection;
}

//Takes an average of readings on a given pin
//Returns the average
int averageAnalogRead(int pinToRead)
{
	byte numberOfReadings = 8;
	unsigned int runningValue = 0;

	for(int x = 0 ; x < numberOfReadings ; x++)
		runningValue += analogRead(pinToRead);
	runningValue /= numberOfReadings;

	return(runningValue);
}
