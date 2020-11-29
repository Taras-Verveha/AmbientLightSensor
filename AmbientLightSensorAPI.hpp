// Include guard
#pragma once

#include "HidSensorSpec.h"

AmbientLightSensorAPI::AmbientLightSensorAPI(void){
}

void AmbientLightSensorAPI::begin(void){
}

void AmbientLightSensorAPI::end(void){
}

void AmbientLightSensorAPI::report(int value){
	ALS_INPUT_REPORT report;
	//report.ucReportId = HID_REPORTID_AMBIENTLIGHT_DATA;
	report.ucSensorState = HID_USAGE_SENSOR_STATE_READY_SEL_ENUM;
	report.ucEventType = HID_USAGE_SENSOR_EVENT_DATA_UPDATED_SEL_ENUM;
	report.usIlluminanceValue = value;
	SendReport(&report, sizeof(report));
}
