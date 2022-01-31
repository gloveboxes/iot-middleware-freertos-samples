/* Copyright (c) Microsoft Corporation.
   Licensed under the MIT License. */

#ifndef DEMO_CONFIG_H
#define DEMO_CONFIG_H

#include <stdlib.h>

/*
 * This Model ID is tightly tied to the code implementation in `sample_azure_iot_pnp_simulated_device.c`
 * If you intend to test a different Model ID, please provide the implementation of the model on your application.
 */
#define sampleazureiotMODEL_ID                                "dtmi:com:example:Thermostat;1"


/**************************************************/
/******* DO NOT CHANGE the following order ********/
/**************************************************/

/*
 * Include logging header files and define logging macros in the following order:
 * 1. Include the header file "esp_log.h".
 * 2. Define the LIBRARY_LOG_NAME and LIBRARY_LOG_LEVEL macros depending on
 * the logging configuration for DEMO.
 * 3. Define macros to replace module logging functions by esp logging functions.
 */

#include "esp_log.h"

#ifndef LIBRARY_LOG_NAME
    #define LIBRARY_LOG_NAME    "AzureIoTDemo"
#endif

#define SINGLE_PARENTHESIS_LOGE( x, ... ) ESP_LOGE( LIBRARY_LOG_NAME, x, ##__VA_ARGS__ )
#define LogError( message )               SINGLE_PARENTHESIS_LOGE message

#define SINGLE_PARENTHESIS_LOGI( x, ... ) ESP_LOGI( LIBRARY_LOG_NAME, x, ##__VA_ARGS__ )
#define LogInfo( message )                SINGLE_PARENTHESIS_LOGI message

#define SINGLE_PARENTHESIS_LOGW( x, ... ) ESP_LOGW( LIBRARY_LOG_NAME, x, ##__VA_ARGS__ )
#define LogWarn( message )                SINGLE_PARENTHESIS_LOGW message

#define SINGLE_PARENTHESIS_LOGD( x, ... ) ESP_LOGD( LIBRARY_LOG_NAME, x, ##__VA_ARGS__ )
#define LogDebug( message )               SINGLE_PARENTHESIS_LOGD message

/************ End of logging configuration ****************/

/**
 * @brief Enable Device Provisioning
 *
 * @note To disable Device Provisioning undef this macro
 *
 */

#ifdef CONFIG_ENABLE_DPS_SAMPLE
    #define democonfigENABLE_DPS_SAMPLE
#endif

#ifdef democonfigENABLE_DPS_SAMPLE

/**
 * @brief Provisioning service endpoint.
 *
 * @note https://docs.microsoft.com/azure/iot-dps/concepts-service#service-operations-endpoint
 *
 */
#define democonfigENDPOINT "global.azure-devices-provisioning.net"

/**
 * @brief Id scope of provisioning service.
 *
 * @note https://docs.microsoft.com/azure/iot-dps/concepts-service#id-scope
 *
 */
#define democonfigID_SCOPE CONFIG_AZURE_DPS_ID_SCOPE

/**
 * @brief Registration Id of provisioning service
 *
 * @warning If using X509 authentication, this MUST match the Common Name of the cert.
 *
 *  @note https://docs.microsoft.com/azure/iot-dps/concepts-service#registration-id
 */
#define democonfigREGISTRATION_ID CONFIG_AZURE_DPS_REGISTRATION_ID


#endif // democonfigENABLE_DPS_SAMPLE

/**
 * @brief IoTHub device Id.
 *
 */
#define democonfigDEVICE_ID CONFIG_AZURE_IOT_DEVICE_ID

/**
 * @brief IoTHub module Id.
 *
 * @note This is optional argument for IoTHub
 */
#define democonfigMODULE_ID CONFIG_AZURE_IOT_MODULE_ID

/**
 * @brief IoTHub hostname.
 *
 */
#define democonfigHOSTNAME CONFIG_AZURE_IOT_HUB_FQDN

/**
 * @brief Device symmetric key
 *
 */
#define democonfigDEVICE_SYMMETRIC_KEY CONFIG_AZURE_IOT_DEVICE_SYMMETRIC_KEY

/**
 * @brief Client's X509 Certificate.
 *
 */
// #define democonfigCLIENT_CERTIFICATE_PEM    "<YOUR DEVICE CERT HERE>"

/**
 * @brief Client's private key.
 *
 */
// #define democonfigCLIENT_PRIVATE_KEY_PEM    "<YOUR DEVICE PRIVATE KEY HERE>"

/**
 * @brief Load the required certificates:
 *  - Baltimore Trusted Root CA 
 *  - DigiCert Global Root G2 
 *  - Microsoft RSA Root Certificate Authority 2017
 *
 */
static unsigned char root_cert_array[] = {
    /* Baltimore */
    0x30, 0x82, 0x03, 0x77, 0x30, 0x82, 0x02, 0x5F, 0xA0, 0x03, 
    0x02, 0x01, 0x02, 0x02, 0x04, 0x02, 0x00, 0x00, 0xB9, 0x30, 
    0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 
    0x01, 0x05, 0x05, 0x00, 0x30, 0x5A, 0x31, 0x0B, 0x30, 0x09, 
    0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x49, 0x45, 0x31, 
    0x12, 0x30, 0x10, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x13, 0x09, 
    0x42, 0x61, 0x6C, 0x74, 0x69, 0x6D, 0x6F, 0x72, 0x65, 0x31, 
    0x13, 0x30, 0x11, 0x06, 0x03, 0x55, 0x04, 0x0B, 0x13, 0x0A, 
    0x43, 0x79, 0x62, 0x65, 0x72, 0x54, 0x72, 0x75, 0x73, 0x74, 
    0x31, 0x22, 0x30, 0x20, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 
    0x19, 0x42, 0x61, 0x6C, 0x74, 0x69, 0x6D, 0x6F, 0x72, 0x65, 
    0x20, 0x43, 0x79, 0x62, 0x65, 0x72, 0x54, 0x72, 0x75, 0x73, 
    0x74, 0x20, 0x52, 0x6F, 0x6F, 0x74, 0x30, 0x1E, 0x17, 0x0D, 
    0x30, 0x30, 0x30, 0x35, 0x31, 0x32, 0x31, 0x38, 0x34, 0x36, 
    0x30, 0x30, 0x5A, 0x17, 0x0D, 0x32, 0x35, 0x30, 0x35, 0x31, 
    0x32, 0x32, 0x33, 0x35, 0x39, 0x30, 0x30, 0x5A, 0x30, 0x5A, 
    0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 
    0x02, 0x49, 0x45, 0x31, 0x12, 0x30, 0x10, 0x06, 0x03, 0x55, 
    0x04, 0x0A, 0x13, 0x09, 0x42, 0x61, 0x6C, 0x74, 0x69, 0x6D, 
    0x6F, 0x72, 0x65, 0x31, 0x13, 0x30, 0x11, 0x06, 0x03, 0x55, 
    0x04, 0x0B, 0x13, 0x0A, 0x43, 0x79, 0x62, 0x65, 0x72, 0x54, 
    0x72, 0x75, 0x73, 0x74, 0x31, 0x22, 0x30, 0x20, 0x06, 0x03, 
    0x55, 0x04, 0x03, 0x13, 0x19, 0x42, 0x61, 0x6C, 0x74, 0x69, 
    0x6D, 0x6F, 0x72, 0x65, 0x20, 0x43, 0x79, 0x62, 0x65, 0x72, 
    0x54, 0x72, 0x75, 0x73, 0x74, 0x20, 0x52, 0x6F, 0x6F, 0x74, 
    0x30, 0x82, 0x01, 0x22, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 
    0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x01, 0x05, 0x00, 0x03, 
    0x82, 0x01, 0x0F, 0x00, 0x30, 0x82, 0x01, 0x0A, 0x02, 0x82, 
    0x01, 0x01, 0x00, 0xA3, 0x04, 0xBB, 0x22, 0xAB, 0x98, 0x3D, 
    0x57, 0xE8, 0x26, 0x72, 0x9A, 0xB5, 0x79, 0xD4, 0x29, 0xE2, 
    0xE1, 0xE8, 0x95, 0x80, 0xB1, 0xB0, 0xE3, 0x5B, 0x8E, 0x2B, 
    0x29, 0x9A, 0x64, 0xDF, 0xA1, 0x5D, 0xED, 0xB0, 0x09, 0x05, 
    0x6D, 0xDB, 0x28, 0x2E, 0xCE, 0x62, 0xA2, 0x62, 0xFE, 0xB4, 
    0x88, 0xDA, 0x12, 0xEB, 0x38, 0xEB, 0x21, 0x9D, 0xC0, 0x41, 
    0x2B, 0x01, 0x52, 0x7B, 0x88, 0x77, 0xD3, 0x1C, 0x8F, 0xC7, 
    0xBA, 0xB9, 0x88, 0xB5, 0x6A, 0x09, 0xE7, 0x73, 0xE8, 0x11, 
    0x40, 0xA7, 0xD1, 0xCC, 0xCA, 0x62, 0x8D, 0x2D, 0xE5, 0x8F, 
    0x0B, 0xA6, 0x50, 0xD2, 0xA8, 0x50, 0xC3, 0x28, 0xEA, 0xF5, 
    0xAB, 0x25, 0x87, 0x8A, 0x9A, 0x96, 0x1C, 0xA9, 0x67, 0xB8, 
    0x3F, 0x0C, 0xD5, 0xF7, 0xF9, 0x52, 0x13, 0x2F, 0xC2, 0x1B, 
    0xD5, 0x70, 0x70, 0xF0, 0x8F, 0xC0, 0x12, 0xCA, 0x06, 0xCB, 
    0x9A, 0xE1, 0xD9, 0xCA, 0x33, 0x7A, 0x77, 0xD6, 0xF8, 0xEC, 
    0xB9, 0xF1, 0x68, 0x44, 0x42, 0x48, 0x13, 0xD2, 0xC0, 0xC2, 
    0xA4, 0xAE, 0x5E, 0x60, 0xFE, 0xB6, 0xA6, 0x05, 0xFC, 0xB4, 
    0xDD, 0x07, 0x59, 0x02, 0xD4, 0x59, 0x18, 0x98, 0x63, 0xF5, 
    0xA5, 0x63, 0xE0, 0x90, 0x0C, 0x7D, 0x5D, 0xB2, 0x06, 0x7A, 
    0xF3, 0x85, 0xEA, 0xEB, 0xD4, 0x03, 0xAE, 0x5E, 0x84, 0x3E, 
    0x5F, 0xFF, 0x15, 0xED, 0x69, 0xBC, 0xF9, 0x39, 0x36, 0x72, 
    0x75, 0xCF, 0x77, 0x52, 0x4D, 0xF3, 0xC9, 0x90, 0x2C, 0xB9, 
    0x3D, 0xE5, 0xC9, 0x23, 0x53, 0x3F, 0x1F, 0x24, 0x98, 0x21, 
    0x5C, 0x07, 0x99, 0x29, 0xBD, 0xC6, 0x3A, 0xEC, 0xE7, 0x6E, 
    0x86, 0x3A, 0x6B, 0x97, 0x74, 0x63, 0x33, 0xBD, 0x68, 0x18, 
    0x31, 0xF0, 0x78, 0x8D, 0x76, 0xBF, 0xFC, 0x9E, 0x8E, 0x5D, 
    0x2A, 0x86, 0xA7, 0x4D, 0x90, 0xDC, 0x27, 0x1A, 0x39, 0x02, 
    0x03, 0x01, 0x00, 0x01, 0xA3, 0x45, 0x30, 0x43, 0x30, 0x1D, 
    0x06, 0x03, 0x55, 0x1D, 0x0E, 0x04, 0x16, 0x04, 0x14, 0xE5, 
    0x9D, 0x59, 0x30, 0x82, 0x47, 0x58, 0xCC, 0xAC, 0xFA, 0x08, 
    0x54, 0x36, 0x86, 0x7B, 0x3A, 0xB5, 0x04, 0x4D, 0xF0, 0x30, 
    0x12, 0x06, 0x03, 0x55, 0x1D, 0x13, 0x01, 0x01, 0xFF, 0x04, 
    0x08, 0x30, 0x06, 0x01, 0x01, 0xFF, 0x02, 0x01, 0x03, 0x30, 
    0x0E, 0x06, 0x03, 0x55, 0x1D, 0x0F, 0x01, 0x01, 0xFF, 0x04, 
    0x04, 0x03, 0x02, 0x01, 0x06, 0x30, 0x0D, 0x06, 0x09, 0x2A, 
    0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x05, 0x05, 0x00, 
    0x03, 0x82, 0x01, 0x01, 0x00, 0x85, 0x0C, 0x5D, 0x8E, 0xE4, 
    0x6F, 0x51, 0x68, 0x42, 0x05, 0xA0, 0xDD, 0xBB, 0x4F, 0x27, 
    0x25, 0x84, 0x03, 0xBD, 0xF7, 0x64, 0xFD, 0x2D, 0xD7, 0x30, 
    0xE3, 0xA4, 0x10, 0x17, 0xEB, 0xDA, 0x29, 0x29, 0xB6, 0x79, 
    0x3F, 0x76, 0xF6, 0x19, 0x13, 0x23, 0xB8, 0x10, 0x0A, 0xF9, 
    0x58, 0xA4, 0xD4, 0x61, 0x70, 0xBD, 0x04, 0x61, 0x6A, 0x12, 
    0x8A, 0x17, 0xD5, 0x0A, 0xBD, 0xC5, 0xBC, 0x30, 0x7C, 0xD6, 
    0xE9, 0x0C, 0x25, 0x8D, 0x86, 0x40, 0x4F, 0xEC, 0xCC, 0xA3, 
    0x7E, 0x38, 0xC6, 0x37, 0x11, 0x4F, 0xED, 0xDD, 0x68, 0x31, 
    0x8E, 0x4C, 0xD2, 0xB3, 0x01, 0x74, 0xEE, 0xBE, 0x75, 0x5E, 
    0x07, 0x48, 0x1A, 0x7F, 0x70, 0xFF, 0x16, 0x5C, 0x84, 0xC0, 
    0x79, 0x85, 0xB8, 0x05, 0xFD, 0x7F, 0xBE, 0x65, 0x11, 0xA3, 
    0x0F, 0xC0, 0x02, 0xB4, 0xF8, 0x52, 0x37, 0x39, 0x04, 0xD5, 
    0xA9, 0x31, 0x7A, 0x18, 0xBF, 0xA0, 0x2A, 0xF4, 0x12, 0x99, 
    0xF7, 0xA3, 0x45, 0x82, 0xE3, 0x3C, 0x5E, 0xF5, 0x9D, 0x9E, 
    0xB5, 0xC8, 0x9E, 0x7C, 0x2E, 0xC8, 0xA4, 0x9E, 0x4E, 0x08, 
    0x14, 0x4B, 0x6D, 0xFD, 0x70, 0x6D, 0x6B, 0x1A, 0x63, 0xBD, 
    0x64, 0xE6, 0x1F, 0xB7, 0xCE, 0xF0, 0xF2, 0x9F, 0x2E, 0xBB, 
    0x1B, 0xB7, 0xF2, 0x50, 0x88, 0x73, 0x92, 0xC2, 0xE2, 0xE3, 
    0x16, 0x8D, 0x9A, 0x32, 0x02, 0xAB, 0x8E, 0x18, 0xDD, 0xE9, 
    0x10, 0x11, 0xEE, 0x7E, 0x35, 0xAB, 0x90, 0xAF, 0x3E, 0x30, 
    0x94, 0x7A, 0xD0, 0x33, 0x3D, 0xA7, 0x65, 0x0F, 0xF5, 0xFC, 
    0x8E, 0x9E, 0x62, 0xCF, 0x47, 0x44, 0x2C, 0x01, 0x5D, 0xBB, 
    0x1D, 0xB5, 0x32, 0xD2, 0x47, 0xD2, 0x38, 0x2E, 0xD0, 0xFE, 
    0x81, 0xDC, 0x32, 0x6A, 0x1E, 0xB5, 0xEE, 0x3C, 0xD5, 0xFC, 
    0xE7, 0x81, 0x1D, 0x19, 0xC3, 0x24, 0x42, 0xEA, 0x63, 0x39, 
    0xA9,
    /* Digicert */
    0x30, 0x82, 0x03, 0x8E, 0x30, 0x82, 0x02, 0x76, 0xA0, 0x03,
    0x02, 0x01, 0x02, 0x02, 0x10, 0x03, 0x3A, 0xF1, 0xE6, 0xA7,
    0x11, 0xA9, 0xA0, 0xBB, 0x28, 0x64, 0xB1, 0x1D, 0x09, 0xFA,
    0xE5, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7,
    0x0D, 0x01, 0x01, 0x0B, 0x05, 0x00, 0x30, 0x61, 0x31, 0x0B,
    0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x55,
    0x53, 0x31, 0x15, 0x30, 0x13, 0x06, 0x03, 0x55, 0x04, 0x0A,
    0x13, 0x0C, 0x44, 0x69, 0x67, 0x69, 0x43, 0x65, 0x72, 0x74,
    0x20, 0x49, 0x6E, 0x63, 0x31, 0x19, 0x30, 0x17, 0x06, 0x03,
    0x55, 0x04, 0x0B, 0x13, 0x10, 0x77, 0x77, 0x77, 0x2E, 0x64,
    0x69, 0x67, 0x69, 0x63, 0x65, 0x72, 0x74, 0x2E, 0x63, 0x6F,
    0x6D, 0x31, 0x20, 0x30, 0x1E, 0x06, 0x03, 0x55, 0x04, 0x03,
    0x13, 0x17, 0x44, 0x69, 0x67, 0x69, 0x43, 0x65, 0x72, 0x74,
    0x20, 0x47, 0x6C, 0x6F, 0x62, 0x61, 0x6C, 0x20, 0x52, 0x6F,
    0x6F, 0x74, 0x20, 0x47, 0x32, 0x30, 0x1E, 0x17, 0x0D, 0x31,
    0x33, 0x30, 0x38, 0x30, 0x31, 0x31, 0x32, 0x30, 0x30, 0x30,
    0x30, 0x5A, 0x17, 0x0D, 0x33, 0x38, 0x30, 0x31, 0x31, 0x35,
    0x31, 0x32, 0x30, 0x30, 0x30, 0x30, 0x5A, 0x30, 0x61, 0x31,
    0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02,
    0x55, 0x53, 0x31, 0x15, 0x30, 0x13, 0x06, 0x03, 0x55, 0x04,
    0x0A, 0x13, 0x0C, 0x44, 0x69, 0x67, 0x69, 0x43, 0x65, 0x72,
    0x74, 0x20, 0x49, 0x6E, 0x63, 0x31, 0x19, 0x30, 0x17, 0x06,
    0x03, 0x55, 0x04, 0x0B, 0x13, 0x10, 0x77, 0x77, 0x77, 0x2E,
    0x64, 0x69, 0x67, 0x69, 0x63, 0x65, 0x72, 0x74, 0x2E, 0x63,
    0x6F, 0x6D, 0x31, 0x20, 0x30, 0x1E, 0x06, 0x03, 0x55, 0x04,
    0x03, 0x13, 0x17, 0x44, 0x69, 0x67, 0x69, 0x43, 0x65, 0x72,
    0x74, 0x20, 0x47, 0x6C, 0x6F, 0x62, 0x61, 0x6C, 0x20, 0x52,
    0x6F, 0x6F, 0x74, 0x20, 0x47, 0x32, 0x30, 0x82, 0x01, 0x22,
    0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D,
    0x01, 0x01, 0x01, 0x05, 0x00, 0x03, 0x82, 0x01, 0x0F, 0x00,
    0x30, 0x82, 0x01, 0x0A, 0x02, 0x82, 0x01, 0x01, 0x00, 0xBB,
    0x37, 0xCD, 0x34, 0xDC, 0x7B, 0x6B, 0xC9, 0xB2, 0x68, 0x90,
    0xAD, 0x4A, 0x75, 0xFF, 0x46, 0xBA, 0x21, 0x0A, 0x08, 0x8D,
    0xF5, 0x19, 0x54, 0xC9, 0xFB, 0x88, 0xDB, 0xF3, 0xAE, 0xF2,
    0x3A, 0x89, 0x91, 0x3C, 0x7A, 0xE6, 0xAB, 0x06, 0x1A, 0x6B,
    0xCF, 0xAC, 0x2D, 0xE8, 0x5E, 0x09, 0x24, 0x44, 0xBA, 0x62,
    0x9A, 0x7E, 0xD6, 0xA3, 0xA8, 0x7E, 0xE0, 0x54, 0x75, 0x20,
    0x05, 0xAC, 0x50, 0xB7, 0x9C, 0x63, 0x1A, 0x6C, 0x30, 0xDC,
    0xDA, 0x1F, 0x19, 0xB1, 0xD7, 0x1E, 0xDE, 0xFD, 0xD7, 0xE0,
    0xCB, 0x94, 0x83, 0x37, 0xAE, 0xEC, 0x1F, 0x43, 0x4E, 0xDD,
    0x7B, 0x2C, 0xD2, 0xBD, 0x2E, 0xA5, 0x2F, 0xE4, 0xA9, 0xB8,
    0xAD, 0x3A, 0xD4, 0x99, 0xA4, 0xB6, 0x25, 0xE9, 0x9B, 0x6B,
    0x00, 0x60, 0x92, 0x60, 0xFF, 0x4F, 0x21, 0x49, 0x18, 0xF7,
    0x67, 0x90, 0xAB, 0x61, 0x06, 0x9C, 0x8F, 0xF2, 0xBA, 0xE9,
    0xB4, 0xE9, 0x92, 0x32, 0x6B, 0xB5, 0xF3, 0x57, 0xE8, 0x5D,
    0x1B, 0xCD, 0x8C, 0x1D, 0xAB, 0x95, 0x04, 0x95, 0x49, 0xF3,
    0x35, 0x2D, 0x96, 0xE3, 0x49, 0x6D, 0xDD, 0x77, 0xE3, 0xFB,
    0x49, 0x4B, 0xB4, 0xAC, 0x55, 0x07, 0xA9, 0x8F, 0x95, 0xB3,
    0xB4, 0x23, 0xBB, 0x4C, 0x6D, 0x45, 0xF0, 0xF6, 0xA9, 0xB2,
    0x95, 0x30, 0xB4, 0xFD, 0x4C, 0x55, 0x8C, 0x27, 0x4A, 0x57,
    0x14, 0x7C, 0x82, 0x9D, 0xCD, 0x73, 0x92, 0xD3, 0x16, 0x4A,
    0x06, 0x0C, 0x8C, 0x50, 0xD1, 0x8F, 0x1E, 0x09, 0xBE, 0x17,
    0xA1, 0xE6, 0x21, 0xCA, 0xFD, 0x83, 0xE5, 0x10, 0xBC, 0x83,
    0xA5, 0x0A, 0xC4, 0x67, 0x28, 0xF6, 0x73, 0x14, 0x14, 0x3D,
    0x46, 0x76, 0xC3, 0x87, 0x14, 0x89, 0x21, 0x34, 0x4D, 0xAF,
    0x0F, 0x45, 0x0C, 0xA6, 0x49, 0xA1, 0xBA, 0xBB, 0x9C, 0xC5,
    0xB1, 0x33, 0x83, 0x29, 0x85, 0x02, 0x03, 0x01, 0x00, 0x01,
    0xA3, 0x42, 0x30, 0x40, 0x30, 0x0F, 0x06, 0x03, 0x55, 0x1D,
    0x13, 0x01, 0x01, 0xFF, 0x04, 0x05, 0x30, 0x03, 0x01, 0x01,
    0xFF, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x1D, 0x0F, 0x01, 0x01,
    0xFF, 0x04, 0x04, 0x03, 0x02, 0x01, 0x86, 0x30, 0x1D, 0x06,
    0x03, 0x55, 0x1D, 0x0E, 0x04, 0x16, 0x04, 0x14, 0x4E, 0x22,
    0x54, 0x20, 0x18, 0x95, 0xE6, 0xE3, 0x6E, 0xE6, 0x0F, 0xFA,
    0xFA, 0xB9, 0x12, 0xED, 0x06, 0x17, 0x8F, 0x39, 0x30, 0x0D,
    0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01,
    0x0B, 0x05, 0x00, 0x03, 0x82, 0x01, 0x01, 0x00, 0x60, 0x67,
    0x28, 0x94, 0x6F, 0x0E, 0x48, 0x63, 0xEB, 0x31, 0xDD, 0xEA,
    0x67, 0x18, 0xD5, 0x89, 0x7D, 0x3C, 0xC5, 0x8B, 0x4A, 0x7F,
    0xE9, 0xBE, 0xDB, 0x2B, 0x17, 0xDF, 0xB0, 0x5F, 0x73, 0x77,
    0x2A, 0x32, 0x13, 0x39, 0x81, 0x67, 0x42, 0x84, 0x23, 0xF2,
    0x45, 0x67, 0x35, 0xEC, 0x88, 0xBF, 0xF8, 0x8F, 0xB0, 0x61,
    0x0C, 0x34, 0xA4, 0xAE, 0x20, 0x4C, 0x84, 0xC6, 0xDB, 0xF8,
    0x35, 0xE1, 0x76, 0xD9, 0xDF, 0xA6, 0x42, 0xBB, 0xC7, 0x44,
    0x08, 0x86, 0x7F, 0x36, 0x74, 0x24, 0x5A, 0xDA, 0x6C, 0x0D,
    0x14, 0x59, 0x35, 0xBD, 0xF2, 0x49, 0xDD, 0xB6, 0x1F, 0xC9,
    0xB3, 0x0D, 0x47, 0x2A, 0x3D, 0x99, 0x2F, 0xBB, 0x5C, 0xBB,
    0xB5, 0xD4, 0x20, 0xE1, 0x99, 0x5F, 0x53, 0x46, 0x15, 0xDB,
    0x68, 0x9B, 0xF0, 0xF3, 0x30, 0xD5, 0x3E, 0x31, 0xE2, 0x8D,
    0x84, 0x9E, 0xE3, 0x8A, 0xDA, 0xDA, 0x96, 0x3E, 0x35, 0x13,
    0xA5, 0x5F, 0xF0, 0xF9, 0x70, 0x50, 0x70, 0x47, 0x41, 0x11,
    0x57, 0x19, 0x4E, 0xC0, 0x8F, 0xAE, 0x06, 0xC4, 0x95, 0x13,
    0x17, 0x2F, 0x1B, 0x25, 0x9F, 0x75, 0xF2, 0xB1, 0x8E, 0x99,
    0xA1, 0x6F, 0x13, 0xB1, 0x41, 0x71, 0xFE, 0x88, 0x2A, 0xC8,
    0x4F, 0x10, 0x20, 0x55, 0xD7, 0xF3, 0x14, 0x45, 0xE5, 0xE0,
    0x44, 0xF4, 0xEA, 0x87, 0x95, 0x32, 0x93, 0x0E, 0xFE, 0x53,
    0x46, 0xFA, 0x2C, 0x9D, 0xFF, 0x8B, 0x22, 0xB9, 0x4B, 0xD9,
    0x09, 0x45, 0xA4, 0xDE, 0xA4, 0xB8, 0x9A, 0x58, 0xDD, 0x1B,
    0x7D, 0x52, 0x9F, 0x8E, 0x59, 0x43, 0x88, 0x81, 0xA4, 0x9E,
    0x26, 0xD5, 0x6F, 0xAD, 0xDD, 0x0D, 0xC6, 0x37, 0x7D, 0xED,
    0x03, 0x92, 0x1B, 0xE5, 0x77, 0x5F, 0x76, 0xEE, 0x3C, 0x8D,
    0xC4, 0x5D, 0x56, 0x5B, 0xA2, 0xD9, 0x66, 0x6E, 0xB3, 0x35,
    0x37, 0xE5, 0x32, 0xB6,
    /* MSFT RSA */
    0x30, 0x82, 0x05, 0xA8, 0x30, 0x82, 0x03, 0x90, 0xA0, 0x03,
    0x02, 0x01, 0x02, 0x02, 0x10, 0x1E, 0xD3, 0x97, 0x09, 0x5F,
    0xD8, 0xB4, 0xB3, 0x47, 0x70, 0x1E, 0xAA, 0xBE, 0x7F, 0x45,
    0xB3, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7,
    0x0D, 0x01, 0x01, 0x0C, 0x05, 0x00, 0x30, 0x65, 0x31, 0x0B,
    0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x55,
    0x53, 0x31, 0x1E, 0x30, 0x1C, 0x06, 0x03, 0x55, 0x04, 0x0A,
    0x13, 0x15, 0x4D, 0x69, 0x63, 0x72, 0x6F, 0x73, 0x6F, 0x66,
    0x74, 0x20, 0x43, 0x6F, 0x72, 0x70, 0x6F, 0x72, 0x61, 0x74,
    0x69, 0x6F, 0x6E, 0x31, 0x36, 0x30, 0x34, 0x06, 0x03, 0x55,
    0x04, 0x03, 0x13, 0x2D, 0x4D, 0x69, 0x63, 0x72, 0x6F, 0x73,
    0x6F, 0x66, 0x74, 0x20, 0x52, 0x53, 0x41, 0x20, 0x52, 0x6F,
    0x6F, 0x74, 0x20, 0x43, 0x65, 0x72, 0x74, 0x69, 0x66, 0x69,
    0x63, 0x61, 0x74, 0x65, 0x20, 0x41, 0x75, 0x74, 0x68, 0x6F,
    0x72, 0x69, 0x74, 0x79, 0x20, 0x32, 0x30, 0x31, 0x37, 0x30,
    0x1E, 0x17, 0x0D, 0x31, 0x39, 0x31, 0x32, 0x31, 0x38, 0x32,
    0x32, 0x35, 0x31, 0x32, 0x32, 0x5A, 0x17, 0x0D, 0x34, 0x32,
    0x30, 0x37, 0x31, 0x38, 0x32, 0x33, 0x30, 0x30, 0x32, 0x33,
    0x5A, 0x30, 0x65, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55,
    0x04, 0x06, 0x13, 0x02, 0x55, 0x53, 0x31, 0x1E, 0x30, 0x1C,
    0x06, 0x03, 0x55, 0x04, 0x0A, 0x13, 0x15, 0x4D, 0x69, 0x63,
    0x72, 0x6F, 0x73, 0x6F, 0x66, 0x74, 0x20, 0x43, 0x6F, 0x72,
    0x70, 0x6F, 0x72, 0x61, 0x74, 0x69, 0x6F, 0x6E, 0x31, 0x36,
    0x30, 0x34, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x2D, 0x4D,
    0x69, 0x63, 0x72, 0x6F, 0x73, 0x6F, 0x66, 0x74, 0x20, 0x52,
    0x53, 0x41, 0x20, 0x52, 0x6F, 0x6F, 0x74, 0x20, 0x43, 0x65,
    0x72, 0x74, 0x69, 0x66, 0x69, 0x63, 0x61, 0x74, 0x65, 0x20,
    0x41, 0x75, 0x74, 0x68, 0x6F, 0x72, 0x69, 0x74, 0x79, 0x20,
    0x32, 0x30, 0x31, 0x37, 0x30, 0x82, 0x02, 0x22, 0x30, 0x0D,
    0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01,
    0x01, 0x05, 0x00, 0x03, 0x82, 0x02, 0x0F, 0x00, 0x30, 0x82,
    0x02, 0x0A, 0x02, 0x82, 0x02, 0x01, 0x00, 0xCA, 0x5B, 0xBE,
    0x94, 0x33, 0x8C, 0x29, 0x95, 0x91, 0x16, 0x0A, 0x95, 0xBD,
    0x47, 0x62, 0xC1, 0x89, 0xF3, 0x99, 0x36, 0xDF, 0x46, 0x90,
    0xC9, 0xA5, 0xED, 0x78, 0x6A, 0x6F, 0x47, 0x91, 0x68, 0xF8,
    0x27, 0x67, 0x50, 0x33, 0x1D, 0xA1, 0xA6, 0xFB, 0xE0, 0xE5,
    0x43, 0xA3, 0x84, 0x02, 0x57, 0x01, 0x5D, 0x9C, 0x48, 0x40,
    0x82, 0x53, 0x10, 0xBC, 0xBF, 0xC7, 0x3B, 0x68, 0x90, 0xB6,
    0x82, 0x2D, 0xE5, 0xF4, 0x65, 0xD0, 0xCC, 0x6D, 0x19, 0xCC,
    0x95, 0xF9, 0x7B, 0xAC, 0x4A, 0x94, 0xAD, 0x0E, 0xDE, 0x4B,
    0x43, 0x1D, 0x87, 0x07, 0x92, 0x13, 0x90, 0x80, 0x83, 0x64,
    0x35, 0x39, 0x04, 0xFC, 0xE5, 0xE9, 0x6C, 0xB3, 0xB6, 0x1F,
    0x50, 0x94, 0x38, 0x65, 0x50, 0x5C, 0x17, 0x46, 0xB9, 0xB6,
    0x85, 0xB5, 0x1C, 0xB5, 0x17, 0xE8, 0xD6, 0x45, 0x9D, 0xD8,
    0xB2, 0x26, 0xB0, 0xCA, 0xC4, 0x70, 0x4A, 0xAE, 0x60, 0xA4,
    0xDD, 0xB3, 0xD9, 0xEC, 0xFC, 0x3B, 0xD5, 0x57, 0x72, 0xBC,
    0x3F, 0xC8, 0xC9, 0xB2, 0xDE, 0x4B, 0x6B, 0xF8, 0x23, 0x6C,
    0x03, 0xC0, 0x05, 0xBD, 0x95, 0xC7, 0xCD, 0x73, 0x3B, 0x66,
    0x80, 0x64, 0xE3, 0x1A, 0xAC, 0x2E, 0xF9, 0x47, 0x05, 0xF2,
    0x06, 0xB6, 0x9B, 0x73, 0xF5, 0x78, 0x33, 0x5B, 0xC7, 0xA1,
    0xFB, 0x27, 0x2A, 0xA1, 0xB4, 0x9A, 0x91, 0x8C, 0x91, 0xD3,
    0x3A, 0x82, 0x3E, 0x76, 0x40, 0xB4, 0xCD, 0x52, 0x61, 0x51,
    0x70, 0x28, 0x3F, 0xC5, 0xC5, 0x5A, 0xF2, 0xC9, 0x8C, 0x49,
    0xBB, 0x14, 0x5B, 0x4D, 0xC8, 0xFF, 0x67, 0x4D, 0x4C, 0x12,
    0x96, 0xAD, 0xF5, 0xFE, 0x78, 0xA8, 0x97, 0x87, 0xD7, 0xFD,
    0x5E, 0x20, 0x80, 0xDC, 0xA1, 0x4B, 0x22, 0xFB, 0xD4, 0x89,
    0xAD, 0xBA, 0xCE, 0x47, 0x97, 0x47, 0x55, 0x7B, 0x8F, 0x45,
    0xC8, 0x67, 0x28, 0x84, 0x95, 0x1C, 0x68, 0x30, 0xEF, 0xEF,
    0x49, 0xE0, 0x35, 0x7B, 0x64, 0xE7, 0x98, 0xB0, 0x94, 0xDA,
    0x4D, 0x85, 0x3B, 0x3E, 0x55, 0xC4, 0x28, 0xAF, 0x57, 0xF3,
    0x9E, 0x13, 0xDB, 0x46, 0x27, 0x9F, 0x1E, 0xA2, 0x5E, 0x44,
    0x83, 0xA4, 0xA5, 0xCA, 0xD5, 0x13, 0xB3, 0x4B, 0x3F, 0xC4,
    0xE3, 0xC2, 0xE6, 0x86, 0x61, 0xA4, 0x52, 0x30, 0xB9, 0x7A,
    0x20, 0x4F, 0x6F, 0x0F, 0x38, 0x53, 0xCB, 0x33, 0x0C, 0x13,
    0x2B, 0x8F, 0xD6, 0x9A, 0xBD, 0x2A, 0xC8, 0x2D, 0xB1, 0x1C,
    0x7D, 0x4B, 0x51, 0xCA, 0x47, 0xD1, 0x48, 0x27, 0x72, 0x5D,
    0x87, 0xEB, 0xD5, 0x45, 0xE6, 0x48, 0x65, 0x9D, 0xAF, 0x52,
    0x90, 0xBA, 0x5B, 0xA2, 0x18, 0x65, 0x57, 0x12, 0x9F, 0x68,
    0xB9, 0xD4, 0x15, 0x6B, 0x94, 0xC4, 0x69, 0x22, 0x98, 0xF4,
    0x33, 0xE0, 0xED, 0xF9, 0x51, 0x8E, 0x41, 0x50, 0xC9, 0x34,
    0x4F, 0x76, 0x90, 0xAC, 0xFC, 0x38, 0xC1, 0xD8, 0xE1, 0x7B,
    0xB9, 0xE3, 0xE3, 0x94, 0xE1, 0x46, 0x69, 0xCB, 0x0E, 0x0A,
    0x50, 0x6B, 0x13, 0xBA, 0xAC, 0x0F, 0x37, 0x5A, 0xB7, 0x12,
    0xB5, 0x90, 0x81, 0x1E, 0x56, 0xAE, 0x57, 0x22, 0x86, 0xD9,
    0xC9, 0xD2, 0xD1, 0xD7, 0x51, 0xE3, 0xAB, 0x3B, 0xC6, 0x55,
    0xFD, 0x1E, 0x0E, 0xD3, 0x74, 0x0A, 0xD1, 0xDA, 0xAA, 0xEA,
    0x69, 0xB8, 0x97, 0x28, 0x8F, 0x48, 0xC4, 0x07, 0xF8, 0x52,
    0x43, 0x3A, 0xF4, 0xCA, 0x55, 0x35, 0x2C, 0xB0, 0xA6, 0x6A,
    0xC0, 0x9C, 0xF9, 0xF2, 0x81, 0xE1, 0x12, 0x6A, 0xC0, 0x45,
    0xD9, 0x67, 0xB3, 0xCE, 0xFF, 0x23, 0xA2, 0x89, 0x0A, 0x54,
    0xD4, 0x14, 0xB9, 0x2A, 0xA8, 0xD7, 0xEC, 0xF9, 0xAB, 0xCD,
    0x25, 0x58, 0x32, 0x79, 0x8F, 0x90, 0x5B, 0x98, 0x39, 0xC4,
    0x08, 0x06, 0xC1, 0xAC, 0x7F, 0x0E, 0x3D, 0x00, 0xA5, 0x02,
    0x03, 0x01, 0x00, 0x01, 0xA3, 0x54, 0x30, 0x52, 0x30, 0x0E,
    0x06, 0x03, 0x55, 0x1D, 0x0F, 0x01, 0x01, 0xFF, 0x04, 0x04,
    0x03, 0x02, 0x01, 0x86, 0x30, 0x0F, 0x06, 0x03, 0x55, 0x1D,
    0x13, 0x01, 0x01, 0xFF, 0x04, 0x05, 0x30, 0x03, 0x01, 0x01,
    0xFF, 0x30, 0x1D, 0x06, 0x03, 0x55, 0x1D, 0x0E, 0x04, 0x16,
    0x04, 0x14, 0x09, 0xCB, 0x59, 0x7F, 0x86, 0xB2, 0x70, 0x8F,
    0x1A, 0xC3, 0x39, 0xE3, 0xC0, 0xD9, 0xE9, 0xBF, 0xBB, 0x4D,
    0xB2, 0x23, 0x30, 0x10, 0x06, 0x09, 0x2B, 0x06, 0x01, 0x04,
    0x01, 0x82, 0x37, 0x15, 0x01, 0x04, 0x03, 0x02, 0x01, 0x00,
    0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D,
    0x01, 0x01, 0x0C, 0x05, 0x00, 0x03, 0x82, 0x02, 0x01, 0x00,
    0xAC, 0xAF, 0x3E, 0x5D, 0xC2, 0x11, 0x96, 0x89, 0x8E, 0xA3,
    0xE7, 0x92, 0xD6, 0x97, 0x15, 0xB8, 0x13, 0xA2, 0xA6, 0x42,
    0x2E, 0x02, 0xCD, 0x16, 0x05, 0x59, 0x27, 0xCA, 0x20, 0xE8,
    0xBA, 0xB8, 0xE8, 0x1A, 0xEC, 0x4D, 0xA8, 0x97, 0x56, 0xAE,
    0x65, 0x43, 0xB1, 0x8F, 0x00, 0x9B, 0x52, 0xCD, 0x55, 0xCD,
    0x53, 0x39, 0x6D, 0x62, 0x4C, 0x8B, 0x0D, 0x5B, 0x7C, 0x2E,
    0x44, 0xBF, 0x83, 0x10, 0x8F, 0xF3, 0x53, 0x82, 0x80, 0xC3,
    0x4F, 0x3A, 0xC7, 0x6E, 0x11, 0x3F, 0xE6, 0xE3, 0x16, 0x91,
    0x84, 0xFB, 0x6D, 0x84, 0x7F, 0x34, 0x74, 0xAD, 0x89, 0xA7,
    0xCE, 0xB9, 0xD7, 0xD7, 0x9F, 0x84, 0x64, 0x92, 0xBE, 0x95,
    0xA1, 0xAD, 0x09, 0x53, 0x33, 0xDD, 0xEE, 0x0A, 0xEA, 0x4A,
    0x51, 0x8E, 0x6F, 0x55, 0xAB, 0xBA, 0xB5, 0x94, 0x46, 0xAE,
    0x8C, 0x7F, 0xD8, 0xA2, 0x50, 0x25, 0x65, 0x60, 0x80, 0x46,
    0xDB, 0x33, 0x04, 0xAE, 0x6C, 0xB5, 0x98, 0x74, 0x54, 0x25,
    0xDC, 0x93, 0xE4, 0xF8, 0xE3, 0x55, 0x15, 0x3D, 0xB8, 0x6D,
    0xC3, 0x0A, 0xA4, 0x12, 0xC1, 0x69, 0x85, 0x6E, 0xDF, 0x64,
    0xF1, 0x53, 0x99, 0xE1, 0x4A, 0x75, 0x20, 0x9D, 0x95, 0x0F,
    0xE4, 0xD6, 0xDC, 0x03, 0xF1, 0x59, 0x18, 0xE8, 0x47, 0x89,
    0xB2, 0x57, 0x5A, 0x94, 0xB6, 0xA9, 0xD8, 0x17, 0x2B, 0x17,
    0x49, 0xE5, 0x76, 0xCB, 0xC1, 0x56, 0x99, 0x3A, 0x37, 0xB1,
    0xFF, 0x69, 0x2C, 0x91, 0x91, 0x93, 0xE1, 0xDF, 0x4C, 0xA3,
    0x37, 0x76, 0x4D, 0xA1, 0x9F, 0xF8, 0x6D, 0x1E, 0x1D, 0xD3,
    0xFA, 0xEC, 0xFB, 0xF4, 0x45, 0x1D, 0x13, 0x6D, 0xCF, 0xF7,
    0x59, 0xE5, 0x22, 0x27, 0x72, 0x2B, 0x86, 0xF3, 0x57, 0xBB,
    0x30, 0xED, 0x24, 0x4D, 0xDC, 0x7D, 0x56, 0xBB, 0xA3, 0xB3,
    0xF8, 0x34, 0x79, 0x89, 0xC1, 0xE0, 0xF2, 0x02, 0x61, 0xF7,
    0xA6, 0xFC, 0x0F, 0xBB, 0x1C, 0x17, 0x0B, 0xAE, 0x41, 0xD9,
    0x7C, 0xBD, 0x27, 0xA3, 0xFD, 0x2E, 0x3A, 0xD1, 0x93, 0x94,
    0xB1, 0x73, 0x1D, 0x24, 0x8B, 0xAF, 0x5B, 0x20, 0x89, 0xAD,
    0xB7, 0x67, 0x66, 0x79, 0xF5, 0x3A, 0xC6, 0xA6, 0x96, 0x33,
    0xFE, 0x53, 0x92, 0xC8, 0x46, 0xB1, 0x11, 0x91, 0xC6, 0x99,
    0x7F, 0x8F, 0xC9, 0xD6, 0x66, 0x31, 0x20, 0x41, 0x10, 0x87,
    0x2D, 0x0C, 0xD6, 0xC1, 0xAF, 0x34, 0x98, 0xCA, 0x64, 0x83,
    0xFB, 0x13, 0x57, 0xD1, 0xC1, 0xF0, 0x3C, 0x7A, 0x8C, 0xA5,
    0xC1, 0xFD, 0x95, 0x21, 0xA0, 0x71, 0xC1, 0x93, 0x67, 0x71,
    0x12, 0xEA, 0x8F, 0x88, 0x0A, 0x69, 0x19, 0x64, 0x99, 0x23,
    0x56, 0xFB, 0xAC, 0x2A, 0x2E, 0x70, 0xBE, 0x66, 0xC4, 0x0C,
    0x84, 0xEF, 0xE5, 0x8B, 0xF3, 0x93, 0x01, 0xF8, 0x6A, 0x90,
    0x93, 0x67, 0x4B, 0xB2, 0x68, 0xA3, 0xB5, 0x62, 0x8F, 0xE9,
    0x3F, 0x8C, 0x7A, 0x3B, 0x5E, 0x0F, 0xE7, 0x8C, 0xB8, 0xC6,
    0x7C, 0xEF, 0x37, 0xFD, 0x74, 0xE2, 0xC8, 0x4F, 0x33, 0x72,
    0xE1, 0x94, 0x39, 0x6D, 0xBD, 0x12, 0xAF, 0xBE, 0x0C, 0x4E,
    0x70, 0x7C, 0x1B, 0x6F, 0x8D, 0xB3, 0x32, 0x93, 0x73, 0x44,
    0x16, 0x6D, 0xE8, 0xF4, 0xF7, 0xE0, 0x95, 0x80, 0x8F, 0x96,
    0x5D, 0x38, 0xA4, 0xF4, 0xAB, 0xDE, 0x0A, 0x30, 0x87, 0x93,
    0xD8, 0x4D, 0x00, 0x71, 0x62, 0x45, 0x27, 0x4B, 0x3A, 0x42,
    0x84, 0x5B, 0x7F, 0x65, 0xB7, 0x67, 0x34, 0x52, 0x2D, 0x9C,
    0x16, 0x6B, 0xAA, 0xA8, 0xD8, 0x7B, 0xA3, 0x42, 0x4C, 0x71,
    0xC7, 0x0C, 0xCA, 0x3E, 0x83, 0xE4, 0xA6, 0xEF, 0xB7, 0x01,
    0x30, 0x5E, 0x51, 0xA3, 0x79, 0xF5, 0x70, 0x69, 0xA6, 0x41,
    0x44, 0x0F, 0x86, 0xB0, 0x2C, 0x91, 0xC6, 0x3D, 0xEA, 0xAE,
    0x0F, 0x84
};
#define democonfigROOT_CA_PEM root_cert_array

/**
 * @brief Set the stack size of the main demo task.
 *
 */
#define democonfigDEMO_STACKSIZE CONFIG_AZURE_TASK_STACKSIZE

/**
 * @brief Size of the network buffer for MQTT packets.
 */
#define democonfigNETWORK_BUFFER_SIZE CONFIG_NETWORK_BUFFER_SIZE

/**
 * @brief IoTHub endpoint port.
 */
#define democonfigIOTHUB_PORT 8883

/**
 * @brief Defines configRAND32, used by the common sample modules.
 */
#define configRAND32() (rand()/RAND_MAX)

#endif /* DEMO_CONFIG_H */
