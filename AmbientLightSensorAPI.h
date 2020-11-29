// Include guard
#pragma once

#include <Arduino.h>
#include "HID-Settings.h"
#include "Types.h"

typedef struct _ALS_FEATURE_REPORT
{
	//common properties
	//HID_UCHAR ucReportId;
	HID_UCHAR ucConnectionType;
	HID_UCHAR ucReportingState;
	HID_UCHAR ucPowerState;
	HID_UCHAR ucSensorState;
	HID_ULONG ulReportInterval;

	//properties specific to this sensor
	HID_USHORT usIlluminanceChangeSensitivity;
	HID_USHORT usIlluminanceMaximum;
	HID_USHORT usIlluminanceMinimum;

	// //add this definition if required by the specific application
	// HID_USHORT usResponseCurve[5][2]; //10 elements matches descriptor

} ALS_FEATURE_REPORT, *PALS_FEATURE_REPORT;

typedef struct _ALS_INPUT_REPORT
{
	//common values
	//HID_UCHAR ucReportId;
	HID_UCHAR ucSensorState;
	HID_UCHAR ucEventType;

	//values specific to this sensor
	HID_USHORT usIlluminanceValue;
	// HID_USHORT  usColorTempValue;
	// HID_USHORT  usChromaticityXValue;
	// HID_USHORT  usChromaticityYValue;

} ALS_INPUT_REPORT, *PALS_INPUT_REPORT;

class AmbientLightSensorAPI
{
public:
	inline AmbientLightSensorAPI(void);
	inline void begin(void);
	inline void end(void);

	inline void report(int value);

	// Sending is public in the base class for advanced users.
	virtual void SendReport(void* data, int length) = 0;
};

// Implementation is inline
#include "AmbientLightSensorAPI.hpp"
