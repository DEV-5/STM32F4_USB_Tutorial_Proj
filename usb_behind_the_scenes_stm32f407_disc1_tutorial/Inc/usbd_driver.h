/*
 * usbd_driver.h
 *
 *  Created on: Sep 29, 2024
 *      Author: vdev
 */

#ifndef USBD_DRIVER_H_
#define USBD_DRIVER_H_

#include "stm32f4xx.h"

#define USB_OTG_HS_GLOBAL ((USB_OTG_GlobalTypeDef *) (USB_OTG_HS_PERIPH_BASE + USB_OTG_GLOBAL_BASE))
#define USB_OTG_HS_DEVICE ((USB_OTG_DeviceTypeDef *) (USB_OTG_HS_PERIPH_BASE + USB_OTG_DEVICE_BASE))
#define USB_OTG_HS_PCGCCTL ((uint32_t *) (USB_OTG_HS_PERIPH_BASE + USB_OTG_PCGCCTL_BASE))

#endif /* USBD_DRIVER_H_ */
