// Include guard
#pragma once

#include "HidSensorSpec.h"

AmbientLightSensorAPI::AmbientLightSensorAPI(void)
{
	// Empty
}

void AmbientLightSensorAPI::begin(void)
{
	end();
}

void AmbientLightSensorAPI::end(void)
{
	send(0);
}

void AmbientLightSensorAPI::send(int value)
{
	ALS_INPUT_REPORT report;
	report.ucReportId = 0;
	report.ucSensorState = HID_USAGE_SENSOR_STATE_READY_SEL_ENUM;
	report.ucEventType = HID_USAGE_SENSOR_EVENT_DATA_UPDATED_SEL_ENUM;
	report.usIlluminanceValue = value;
	SendReport(&report, sizeof(report));
}
