/**
  ******************************************************************************
  * @file    usb_desc.c
  * @author  MCD Application Team
  * @version V4.0.0
  * @date    19-August-2014
  * @brief   Descriptors for simple Microphone
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "usb_lib.h"
#include "usb_desc.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants----------------------------------------------------------*/
/* USB Standard Device Descriptor */
const uint8_t Mic_DeviceDescriptor[] =
  {
    MIC_SIZ_DEVICE_DESC,                  /* bLength = 18 */
    USB_DEVICE_DESCRIPTOR_TYPE,           /* bDescriptorType */
    0x00, 0x02,        /* 2.00 */         /* bcdUSB */
    0x00,                                 /* bDeviceClass (0x00 - Defined at Interface level)*/
    0x00,                                 /* bDeviceSubClass (Unused)*/
    0x00,                                 /* bDeviceProtocol */
    0x08,                                 /* bMaxPacketSize = 8 bytes */
    0x83, 0x04,                           /* idVendor = 0x0483 (STMicroelectronics)*/
    0x40, 0x57,                           /* idProduct  = 0x7D0F*/
    0x00, 0x01,        /* 1.00 */         /* bcdDevice */
    1,                                    /* iManufacturer */
    2,                                    /* iProduct */
    3,                                    /* iSerialNumber */
    0x01                                  /* bNumConfigurations */
  };

/* USB Configuration Descriptor */
/* All Descriptors (Configuration, Interface, Endpoint, Class, Vendor */
const uint8_t Mic_ConfigDescriptor[] =
  {
    /* Configuration 1 */
    0x09,                                 /* bLength */
    USB_CONFIGURATION_DESCRIPTOR_TYPE,    /* bDescriptorType */
    0x64, 0x00,                           /* wTotalLength  100 bytes*/
    0x02,                                 /* bNumInterfaces */
    0x01,                                 /* bConfigurationValue (ID of configuration)*/
    0x00,                                 /* iConfiguration (Unused)*/
    0x80,                                 /* bmAttributes (Bus powered, no Remote wakeup)*/
    0x32,                                 /* bMaxPower = 100 mA*/
    /* 09 byte*/

    /* USB AudioControl (AC) Standard interface descriptor */
    AC_SIZ_INTERFACE_DESC_SIZE,           /* bLength */
    USB_INTERFACE_DESCRIPTOR_TYPE,        /* bDescriptorType */
    0x00,                                 /* bInterfaceNumber (Interface index 0)*/
    0x00,                                 /* bAlternateSetting (this setting)*/
    0x00,                                 /* bNumEndpoints (no endpoints)*/
    USB_DEVICE_CLASS_AUDIO,               /* bInterfaceClass */
    AUDIO_SUBCLASS_AUDIOCONTROL,          /* bInterfaceSubClass */
    AUDIO_PROTOCOL_UNDEFINED,             /* bInterfaceProtocol */
    0x00,                                 /* iInterface */
    /* 09 byte*/

    /* USB Mic Class-specific AC Interface Descriptor */
    MIC_SIZ_INTERFACE_DESC_SIZE,          /* bLength */
    AUDIO_INTERFACE_DESCRIPTOR_TYPE,      /* bDescriptorType */
    AUDIO_CONTROL_HEADER,                 /* bDescriptorSubtype */
    0x00, 0x01,         /* 1.00 */        /* bcdADC */
    0x1E, 0x00,                           /* wTotalLength = 30*/
    0x01,                                 /* bInCollection (Number of streaming interfaces)*/
    0x01,                                 /* baInterfaceNr (AudioStreaming interface 1 belongs to this AudioControl interface)*/
    /* 09 byte*/

    /* USB Mic Input Terminal Descriptor */
    AUDIO_INPUT_TERMINAL_DESC_SIZE,       /* bLength (0x0C)*/
    AUDIO_INTERFACE_DESCRIPTOR_TYPE,      /* bDescriptorType */
    AUDIO_CONTROL_INPUT_TERMINAL,         /* bDescriptorSubtype */
    0x01,                                 /* bTerminalID */
    0x01, 0x02,                           /* wTerminalType AUDIO_TERMINAL_USB_MICROPHONE   0x0201 */
    0x00,                                 /* bAssocTerminal (No association)*/
    0x01,                                 /* bNrChannels (One channel)*/
    0x00, 0x00,                           /* wChannelConfig 0x0000 Mono */
    0x00,                                 /* iChannelNames */
    0x00,                                 /* iTerminal */
    /* 12 byte*/

    /*USB Mic Output Terminal Descriptor */
    0x09,                                 /* bLength */
    AUDIO_INTERFACE_DESCRIPTOR_TYPE,      /* bDescriptorType */
    AUDIO_CONTROL_OUTPUT_TERMINAL,        /* bDescriptorSubtype */
    0x02,                                 /* bTerminalID */
    0x01, 0x01,                           /* wTerminalType  0x0101 - USB Streaming*/
    0x00,                                 /* bAssocTerminal */
    0x01,                                 /* bSourceID (Form Input Terminal)*/
    0x00,                                 /* iTerminal */
    /* 09 byte*/

    /* USB Microphone Standard AS Interface Descriptor - Audio Streaming Zero Bandwith */
    /* Interface 1, Alternate Setting 0                                             */
    MIC_SIZ_INTERFACE_DESC_SIZE,          /* bLength */
    USB_INTERFACE_DESCRIPTOR_TYPE,        /* bDescriptorType */
    0x01,                                 /* bInterfaceNumber */
    0x00,                                 /* bAlternateSetting */
    0x00,                                 /* bNumEndpoints */
    USB_DEVICE_CLASS_AUDIO,               /* bInterfaceClass */
    AUDIO_SUBCLASS_AUDIOSTREAMING,        /* bInterfaceSubClass */
    AUDIO_PROTOCOL_UNDEFINED,             /* bInterfaceProtocol */
    0x00,                                 /* iInterface */
    /* 09 byte*/

    /* USB Microphone Standard AS Interface Descriptor - Audio Streaming Operational */
    /* Interface 1, Alternate Setting 1                                           */
    MIC_SIZ_INTERFACE_DESC_SIZE,          /* bLength */
    USB_INTERFACE_DESCRIPTOR_TYPE,        /* bDescriptorType */
    0x01,                                 /* bInterfaceNumber */
    0x01,                                 /* bAlternateSetting */
    0x01,                                 /* bNumEndpoints */
    USB_DEVICE_CLASS_AUDIO,               /* bInterfaceClass */
    AUDIO_SUBCLASS_AUDIOSTREAMING,        /* bInterfaceSubClass */
    AUDIO_PROTOCOL_UNDEFINED,             /* bInterfaceProtocol */
    0x00,                                 /* iInterface */
    /* 09 byte*/

    /* USB Microphone Audio Streaming General Interface Descriptor */
    AUDIO_STREAMING_INTERFACE_DESC_SIZE,  /* bLength */
    AUDIO_INTERFACE_DESCRIPTOR_TYPE,      /* bDescriptorType */
    AUDIO_STREAMING_GENERAL,              /* bDescriptorSubtype */
    0x02,                                 /* bTerminalLink (Unit ID of the Output Terminal)*/
    0x01,                                 /* bDelay */
    0x01, 0x00,                           /* wFormatTag AUDIO_FORMAT_PCM  0x0001*/
    /* 07 byte*/

    /* USB Microphone Audio Type I Format Interface Descriptor */
    0x0B,                                 /* bLength */
    AUDIO_INTERFACE_DESCRIPTOR_TYPE,      /* bDescriptorType */
    AUDIO_STREAMING_FORMAT_TYPE,          /* bDescriptorSubtype */
    AUDIO_FORMAT_TYPE_I,                  /* bFormatType */
    0x01,                                 /* bNrChannels */
    0x01,                                 /* bSubFrameSize */
    0x10,                                 /* bBitResolution (16-bit per sample)*/
    0x01,                                 /* bSamFreqType */
    0x40, 0x1F, 0x00,                     /* tSamFreq 8000Hz = 0x001F40 */
    /* 11 byte*/

    /* Endpoint 1 - Standard Descriptor */
    AUDIO_STANDARD_ENDPOINT_DESC_SIZE,    /* bLength */
    USB_ENDPOINT_DESCRIPTOR_TYPE,         /* bDescriptorType */
    0x81,                                 /* bEndpointAddress IN Endpoint 1*/
    USB_ENDPOINT_TYPE_ISOCHRONOUS,        /* bmAttributes */
    0x10, 0x00,                           /* wMaxPacketSize = 16 bytes*/
    0x01,                                 /* bInterval */
    0x00,                                 /* bRefresh */
    0x00,                                 /* bSynchAddress */
    /* 09 byte*/

    /* Endpoint - Audio Streaming Descriptor*/
    AUDIO_STREAMING_ENDPOINT_DESC_SIZE,   /* bLength */
    AUDIO_ENDPOINT_DESCRIPTOR_TYPE,       /* bDescriptorType */
    AUDIO_ENDPOINT_GENERAL,               /* bDescriptor */
    0x00,                                 /* bmAttributes */
    0x00,                                 /* bLockDelayUnits */
    0x00,                                 /* wLockDelay */
    0x00
    /* 07 byte*/
  };

/* USB String Descriptor (optional) */
const uint8_t Mic_StringLangID[MIC_SIZ_STRING_LANGID] =
  {
    0x04,                                 /* bLength */
    0x03,                                 /* bDescriptorType */
    0x09, 0x04                            /* LangID = 0x0409: U.S. English */
  };

const uint8_t Mic_StringVendor[MIC_SIZ_STRING_VENDOR] =
  {
    MIC_SIZ_STRING_VENDOR, /* Size of manufacturer string */
    USB_STRING_DESCRIPTOR_TYPE,  /* bDescriptorType*/
    /* Manufacturer: "Home made electronics" */
    'H', 0, 'o', 0, 'm', 0, 'e', 0, ' ', 0,
    'm', 0, 'a', 0, 'd', 0, 'e', 0, ' ', 0,
    'e', 0, 'l', 0, 'e', 0, 'c', 0, 't', 0, 'r', 0, 'o', 0, 'n', 0, 'i', 0, 'c', 0, 's', 0
  };

const uint8_t Mic_StringProduct[MIC_SIZ_STRING_PRODUCT] =
  {
    MIC_SIZ_STRING_PRODUCT,  /* bLength */
    USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
    'S', 0, 'T', 0, 'M', 0, '3', 0, '2', 0, ' ', 0,
    'J', 0, 'a', 0, 'r', 0, 'v', 0, 'i', 0, 's', 0
  };

uint8_t Mic_StringSerial[MIC_SIZ_STRING_SERIAL] =
  {
    MIC_SIZ_STRING_SERIAL,          /* bLength */
    USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
    'S', 0, 'T', 0, 'M', 0, '3', 0, '2', 0
  };
/* Extern variables ----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Extern function prototypes ------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
