// temperature.cpp


#include <iostream>
#include <iomanip>

#include "temperature.h"

using namespace std;


// constructor
// must be a valid temp (above absolute 0) 
// and a valid scale (K, k, C, c, F, f)
Temperature::Temperature(double tempC, char scaleC) 
{
	// sets default format
	SetFormat('D');
	
	// will set the object's values if valid 
	// (checked and set in the Set function)
	bool validTemp = Set(tempC, scaleC);

	// if the inputted values are invalid, the set function returns false
	// so the if statement sets scale and temp to 0 Celsius
	if (!validTemp)
	{
		// sets to default 0 Celsius due to invalid temp
		Set(0, 'C');
	}
}

// prompts user for temp
void Temperature::Input()
{
	double degI;
	char scaleI;

	cout << "Please input a temperature and a scale\n";
	cin >> degI;
	cin >> scaleI;
	
	while (!Set(degI, scaleI))
	{
		cout << "Invalid Temperature. Try again:\n";
		cin >> degI >> scaleI;
	}
}

// outputs temperature to the screen
void Temperature::Show()
{
	// sets appropriate string for the scale
	string scaleText;
	if (scale == 'K')
	{
		scaleText = "Kelvin";
	}
	else if (scale == 'C')
	{
		scaleText = "Celsius";
	}
	else if (scale == 'F')
	{
		scaleText = "Fahrenheit";
	}

	// outputs appropriate format
	if (format == 'D')
	{
		cout << temp << " " << scaleText[0] << "\n";		
	}
	else if (format == 'P')
	{
		// saves old precision settings and sets decimal to round to 1
		int oldPrecision = cout.precision();
		ios_base::fmtflags oldFlags = cout.flags();
		cout << setprecision(1) << fixed;

		cout << temp << " " << scaleText[0] << "\n";

		// returns to old precision
		cout.precision(oldPrecision);
		cout.flags(oldFlags);
	}
	else if (format == 'L')
	{
		cout << temp << " " << scaleText << "\n";	
	}
}

// sets temperature. Returns false if temperature is invalid
bool Temperature::Set(double deg, char s)
{
	s = toupper(s);
	bool validScale = s == 'K' || s == 'C' || s == 'F';

	bool validTemp = (ConvertToK(deg, s) >= 0); 
	
	// sets temp & scale if both are valid
	if (validTemp && validScale)
	{
		temp = deg;
		scale = s;
		return true;
	}
	else
	{
		return false;
	}
}

// getters
double Temperature::GetDegrees()
{
	return temp;
}

char Temperature::GetScale()
{
	return scale;
}

// sets format ('f'). Returns false if invalid input
//'D' = Default, 'P' = Precision-1, 'L' = Long	
bool Temperature::SetFormat (char f)
{
	f = toupper(f);
	if (f == 'D' || f == 'P' || f == 'L')
	{
		format = f;	
		return true;
	}
	else
	{
		return false;
	}
}
	
// converts temp to new scale ('sc')
// if invalid input, returns false and doesn't change anything
// assumes converting to its own scale is valid
bool Temperature::Convert (char sc)
{
	sc = toupper(sc);

	double newDeg = temp;

	// this if statement will skip anything else if the function
	// was called to convert to itself
	if (scale == sc)
	{
	}
	else if (sc == 'K')
	{
		newDeg = ConvertToK(temp, scale);
	}
	else if (sc == 'C')
	{
		newDeg = ConvertToK(temp, scale) - 273.15;	
	}
	else if (sc == 'F')
	{
		// converts from K to C if applicable
		if (scale == 'K')
		{
			newDeg = newDeg - 273.15;
		}

		// converts from C to F
		newDeg = newDeg * 9 / 5 + 32;
	}
			
	return Set(newDeg, sc);
}

// compares two Temperature objects
// returns -1 if calling obj is lower 
// returns 0 if objects represent same temp
// returns 1 if paramater object has lower temp
int Temperature::Compare(const Temperature& d)
{
	double objKelvin = ConvertToK(temp, scale);
	double parameterKelvin = ConvertToK(d.temp, d.scale);

	if (objKelvin < parameterKelvin)
	{
		return -1;
	}
	else if (parameterKelvin < objKelvin)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// increments temperature by the specified degrees in the 'sc' scale
// note: the scale of the object is unchanged
void Temperature::Increment(int deg, char sc)
{
	sc = toupper(sc);

	char oldScale = scale;

	// if scale is invalid the Convert function will do nothing and return false
	if (Convert(sc))
	{
		Set(temp + deg, sc);
		Convert(oldScale);
	}
}	

// private function converts inputted deg/scale to kelvin for convienence of 
// other classes
// note: an invalid scale is acceptable input because it is a private function
double Temperature::ConvertToK(double deg, char sc)
{
	if (sc == 'K')
	{
		return deg;
	}
	else if (sc == 'C')
	{
		return (deg + 273.15);
	}
	else if (sc == 'F')
	{
		return ((deg - 32) * 5 / 9 + 273.15);	
	}
	else
	{
		return -9999;
	}
}
