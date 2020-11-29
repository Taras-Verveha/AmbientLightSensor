// Include guard
#pragma once

#include <Arduino.h>
#include "HID.h"
#include "HID-Settings.h"
#include "AmbientLightSensorAPI.h"

class AmbientLightSensor_ : public AmbientLightSensorAPI
{
public:
    AmbientLightSensor_(void);

protected: 
    virtual inline void SendReport(void* data, int length) override;
};
extern AmbientLightSensor_ AmbientLightSensor;

