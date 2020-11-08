// Include guard
#pragma once

#include <Arduino.h>
#include "HID.h"
#include "HID-Settings.h"
#include "AmbientLightSensorAPI.h"

class AmbientLightSensor_ : public PluggableUSBModule, public AmbientLightSensorAPI
{
public:
    AmbientLightSensor_(void);
    uint8_t getLeds(void);
    uint8_t getProtocol(void);

protected:
    // Implementation of the PUSBListNode
    int getInterface(uint8_t *interfaceCount);
    int getDescriptor(USBSetup &setup);
    bool setup(USBSetup &setup);

    EPTYPE_DESCRIPTOR_SIZE epType[1];
    uint8_t protocol;
    uint8_t idle;

    virtual inline void SendReport(void *data, int length) override;
};
extern AmbientLightSensor_ AmbientLightSensor;
