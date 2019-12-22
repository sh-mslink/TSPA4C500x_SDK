/**
 ****************************************************************************************
 *
 * @file inb_att.h
 *
 * @brief BLE Attribute 
 *
 * Copyright (C) Shanghai Tropos Microelectronics Co., Ltd. 2018~2020
 *
 ****************************************************************************************
 */

#ifndef INB_ATT_H
#define INB_ATT_H

/**
 ****************************************************************************************
 * @defgroup INB_ATT BLE Attribute Protocol  
 * @ingroup BLE
 * @brief  BLE ATT
 * @{
 ****************************************************************************************
 */

#include <stdint.h>

/*
 * DEFINES
 ****************************************************************************************
 */
#define INB_ATT_UUID_16(uuid)                          (uuid)

/// Length, number, offset defines
#define INB_SVC_VALUE_MAX_LEN             0x0030
#define INB_CHAR_NAME_MAX_LEN             0x0030
#define INB_UUID_16_LEN                         0x0002
#define INB_UUID_32_LEN                         0x0004
#define INB_UUID_128_LEN                        0x0010

/*
 * Enumerations
 ****************************************************************************************
 */

/**
 * Attributes properties
 *
 * Bit [0-1]  : Read Permission         (0 = NO_AUTH, 1 = UNAUTH, 2 = AUTH, 3 = SEC_CON)
 * Bit [2-3]  : Write Permission        (0 = NO_AUTH, 1 = UNAUTH, 2 = AUTH, 3 = SEC_CON)
 * Bit [4-5]  : Indication Permission   (0 = NO_AUTH, 1 = UNAUTH, 2 = AUTH, 3 = SEC_CON)
 * Bit [6-7]  : Notification Permission (0 = NO_AUTH, 1 = UNAUTH, 2 = AUTH, 3 = SEC_CON)
 *
 * Bit [8]     : Broadcast permission        (only relevant for a characteristic value)
 * Bit [9]     : Read Request accepted
 * Bit [10]   : Write Command accepted
 * Bit [11]   : Write Request accepted
 * Bit [12]   : Notification support
 * Bit [13]   : Indication support
 * Bit [14]   : Write Signed accepted
 * Bit [15]   : Extended properties present (only relevant for a characteristic value)
 */

enum inb_att_perm
{
	ATT_PERM_NO_AUTH,
	ATT_PERM_UNAUTH,
	ATT_PERM_AUTH,
	ATT_PERM_SEC_CON,
};

enum inb_att_perm_prop
{
	/// Read Permission Mask
	ATT_PERM_READ_MASK             = 0x0003,
	ATT_PERM_READ_SHIFT              = 0,
	/// Write Permission Mask
	ATT_PERM_WRITE_MASK            = 0x000C,
	ATT_PERM_WRITE_SHIFT             = 2,
	/// Indication Access Mask
	ATT_PERM_IND_MASK            = 0x0030,
	ATT_PERM_IND_SHIFT             = 4,
	/// Notification Access Mask
	ATT_PERM_NTF_MASK           = 0x00C0,
	ATT_PERM_NTF_SHIFT             = 6,
};

enum inb_att_char_prop
{
	/// Broadcast descriptor present
	ATT_CHAR_PROP_BROADCAST     = 0x0100,
	/// Read Access Mask
	ATT_CHAR_PROP_READ            = 0x0200,
	/// Write Command Enabled attribute Mask
	ATT_CHAR_PROP_WRITE_NO_RSP = 0x0400,
	/// Write Request Enabled attribute Mask
	ATT_CHAR_PROP_WRITE     = 0x0800,
	/// Notification Access Mask
	ATT_CHAR_PROP_NOTIFY           = 0x1000,
	/// Indication Access Mask
	ATT_CHAR_PROP_INDICATE           = 0x2000,
	/// Write Signed Enabled attribute Mask
	ATT_CHAR_PROP_WRITE_SIGNED  = 0x4000,
	/// Extended properties descriptor present
	ATT_CHAR_PROP_EXT           = 0x8000,
};


/**
 * Extended properties bit field
 *
 * Bit [0-11] : Maximum Attribute Length or Value Offset pointer
 * Bit [12]   : Encryption key Size must be 16 bytes
 * Bit [14-13]: UUID Length             (0 = 16 bits, 1 = 32 bits, 2 = 128 bits, 3 = RFU)
 * Bit [15]   : Trigger Read Indication (0 = Value present in Database, 1 = Value not present in Database)
 */
enum inb_att_ext_prop
{
	/// Maximum Attribute Length
	ATT_EXT_PROP_MAX_LEN     = 0x0FFF,
	ATT_EXT_PROP_MAX_LEN_SHIFT      = 0,
	/// Attribute value Offset
	ATT_EXT_PROP_VAL_OFFSET  = 0x0FFF,
	ATT_EXT_PROP_VAL_OFFSET_SHIFT   = 0,
	/// Check Encryption key size Mask
	ATT_EXT_PROP_EKS         = 0x1000,
	ATT_EXT_PROP_EKS_SHIFT          = 12,
	/// UUID Length
	ATT_EXT_PROP_UUID_LEN    = 0x6000,
	ATT_EXT_PROP_UUID_LEN_SHIFT     = 13,
	/// Read trigger Indication
	ATT_EXT_PROP_RI          = 0x8000,
	ATT_EXT_PROP_RI_SHIFT           = 15,
};

/**
 * Service properties
 *
 * Bit [1]  : Encryption key Size must be 16 bytes
 * Bit [2-3]: Service Permission      (0 = NO_AUTH, 1 = UNAUTH, 2 = AUTH, 3 = Secure Connect)
 * Bit [4]  : Disable the service
 * Bit [5-6]: UUID Length             (0 = 16 bits, 1 = 32 bits, 2 = 128 bits, 3 = RFU)
 * Bit [7]  : Secondary Service       (0 = Primary Service, 1 = Secondary Service)
 */
enum inb_att_svc_prop
{
    /// Check Encryption key size for service Access
    ATT_SVC_PROP_EKS       = 0x02,
    ATT_SVC_PROP_EKS_SHIFT        = 1,
    /// Service Permission authentication
    ATT_SVC_PROP_AUTH      = 0x0C,
    ATT_SVC_PROP_AUTH_SHIFT       = 2,
    /// Disable the service
    ATT_SVC_PROP_DIS       = 0x10,
    ATT_SVC_PROP_DIS_SHIFT        = 4,
    /// Service UUID Length
    ATT_SVC_PROP_UUID_LEN  = 0x60,
    ATT_SVC_PROP_UUID_LEN_SHIFT   = 5,
    /// Service type Secondary
    ATT_SVC_PROP_SECONDARY = 0x80,
    ATT_SVC_PROP_SECONDARY_SHIFT  = 7,
};

/// Common 16-bit Universal Unique Identifier
enum inb_common_uuid {
    INB_ATT_INVALID_UUID                            = INB_ATT_UUID_16(0x0000),
    /*----------------- SERVICES ---------------------*/
    /// Generic Access Profile
    INB_ATT_SVC_GENERIC_ACCESS                      = INB_ATT_UUID_16(0x1800),
    /// Attribute Profile
    INB_ATT_SVC_GENERIC_ATTRIBUTE                   = INB_ATT_UUID_16(0x1801),
    /// Immediate alert Service
    INB_ATT_SVC_IMMEDIATE_ALERT                     = INB_ATT_UUID_16(0x1802),
    /// Link Loss Service
    INB_ATT_SVC_LINK_LOSS                           = INB_ATT_UUID_16(0x1803),
    /// Tx Power Service
    INB_ATT_SVC_TX_POWER                            = INB_ATT_UUID_16(0x1804),
    /// Current Time Service Service
    INB_ATT_SVC_CURRENT_TIME                        = INB_ATT_UUID_16(0x1805),
    /// Reference Time Update Service
    INB_ATT_SVC_REF_TIME_UPDATE                     = INB_ATT_UUID_16(0x1806),
    /// Next DST Change Service
    INB_ATT_SVC_NEXT_DST_CHANGE                     = INB_ATT_UUID_16(0x1807),
    /// Glucose Service
    INB_ATT_SVC_GLUCOSE                             = INB_ATT_UUID_16(0x1808),
    /// Health Thermometer Service
    INB_ATT_SVC_HEALTH_THERMOM                      = INB_ATT_UUID_16(0x1809),
    /// Device Information Service
    INB_ATT_SVC_DEVICE_INFO                         = INB_ATT_UUID_16(0x180A),
    /// Heart Rate Service
    INB_ATT_SVC_HEART_RATE                          = INB_ATT_UUID_16(0x180D),
    /// Phone Alert Status Service
    INB_ATT_SVC_PHONE_ALERT_STATUS                  = INB_ATT_UUID_16(0x180E),
    /// Battery Service
    INB_ATT_SVC_BATTERY_SERVICE                     = INB_ATT_UUID_16(0x180F),
    /// Blood Pressure Service
    INB_ATT_SVC_BLOOD_PRESSURE                      = INB_ATT_UUID_16(0x1810),
    /// Alert Notification Service
    INB_ATT_SVC_ALERT_NTF                           = INB_ATT_UUID_16(0x1811),
    /// HID Service
    INB_ATT_SVC_HID                                 = INB_ATT_UUID_16(0x1812),
    /// Scan Parameters Service
    INB_ATT_SVC_SCAN_PARAMETERS                     = INB_ATT_UUID_16(0x1813),
    /// Running Speed and Cadence Service
    INB_ATT_SVC_RUNNING_SPEED_CADENCE               = INB_ATT_UUID_16(0x1814),
    /// Cycling Speed and Cadence Service
    INB_ATT_SVC_CYCLING_SPEED_CADENCE               = INB_ATT_UUID_16(0x1816),
    /// Cycling Power Service
    INB_ATT_SVC_CYCLING_POWER                       = INB_ATT_UUID_16(0x1818),
    /// Location and Navigation Service
    INB_ATT_SVC_LOCATION_AND_NAVIGATION             = INB_ATT_UUID_16(0x1819),
    /// Environmental Sensing Service
    INB_ATT_SVC_ENVIRONMENTAL_SENSING               = INB_ATT_UUID_16(0x181A),
    /// Body Composition Service
    INB_ATT_SVC_BODY_COMPOSITION                    = INB_ATT_UUID_16(0x181B),
    /// User Data Service
    INB_ATT_SVC_USER_DATA                           = INB_ATT_UUID_16(0x181C),
    /// Weight Scale Service
    INB_ATT_SVC_WEIGHT_SCALE                        = INB_ATT_UUID_16(0x181D),
    /// Bond Management Service
    INB_ATT_SVC_BOND_MANAGEMENT                     = INB_ATT_UUID_16(0x181E),
    /// Continuous Glucose Monitoring Service
    INB_ATT_SVC_CONTINUOUS_GLUCOSE_MONITORING       = INB_ATT_UUID_16(0x181F),
    /// Internet Protocol Support Service
    INB_ATT_SVC_IP_SUPPORT                          = INB_ATT_UUID_16(0x1820),
    /// Indoor Positioning Service
    INB_ATT_SVC_INDOOR_POSITIONING                  = INB_ATT_UUID_16(0x1821),
    /// Pulse Oximeter Service
    INB_ATT_SVC_PULSE_OXIMETER                      = INB_ATT_UUID_16(0x1822),
    /// HTTP Proxy Service
    INB_ATT_SVC_HTTP_PROXY                          = INB_ATT_UUID_16(0x1823),
    /// Transport Discovery Service
    INB_ATT_SVC_TRANSPORT_DISCOVERY                 = INB_ATT_UUID_16(0x1824),
    /// Object Transfer Service
    INB_ATT_SVC_OBJECT_TRANSFER                     = INB_ATT_UUID_16(0x1825),

    /// Mesh Provisioning Service
    INB_ATT_SVC_MESH_PROVISIONING                   = INB_ATT_UUID_16(0x1827),
    /// Mesh Proxy Service
    INB_ATT_SVC_MESH_PROXY                          = INB_ATT_UUID_16(0x1828),

    /*------------------- UNITS ---------------------*/
    /// No defined unit
    INB_ATT_UNIT_UNITLESS                           = INB_ATT_UUID_16(0x2700),
    /// Length Unit - Metre
    INB_ATT_UNIT_METRE                              = INB_ATT_UUID_16(0x2701),
    ///Mass unit - Kilogram
    INB_ATT_UNIT_KG                                 = INB_ATT_UUID_16(0x2702),
    ///Time unit - second
    INB_ATT_UNIT_SECOND                             = INB_ATT_UUID_16(0x2703),
    ///Electric current unit - Ampere
    INB_ATT_UNIT_AMPERE                             = INB_ATT_UUID_16(0x2704),
    ///Thermodynamic Temperature unit - Kelvin
    INB_ATT_UNIT_KELVIN                             = INB_ATT_UUID_16(0x2705),
    /// Amount of substance unit - mole
    INB_ATT_UNIT_MOLE                               = INB_ATT_UUID_16(0x2706),
    ///Luminous intensity unit - candela
    INB_ATT_UNIT_CANDELA                            = INB_ATT_UUID_16(0x2707),
    ///Area unit - square metres
    INB_ATT_UNIT_SQ_METRE                           = INB_ATT_UUID_16(0x2710),
    ///Colume unit - cubic metres
    INB_ATT_UNIT_CUBIC_METRE                        = INB_ATT_UUID_16(0x2710),
    ///Velocity unit - metres per second
    INB_ATT_UNIT_METRE_PER_SECOND                   = INB_ATT_UUID_16(0x2711),
    ///Acceleration unit - metres per second squared
    INB_ATT_UNIT_METRES_PER_SEC_SQ                  = INB_ATT_UUID_16(0x2712),
    ///Wavenumber unit - reciprocal metre
    INB_ATT_UNIT_RECIPROCAL_METRE                   = INB_ATT_UUID_16(0x2713),
    ///Density unit - kilogram per cubic metre
    INB_ATT_UNIT_DENS_KG_PER_CUBIC_METRE            = INB_ATT_UUID_16(0x2714),
    ///Surface density unit - kilogram per square metre
    INB_ATT_UNIT_KG_PER_SQ_METRE                    = INB_ATT_UUID_16(0x2715),
    ///Specific volume unit - cubic metre per kilogram
    INB_ATT_UNIT_CUBIC_METRE_PER_KG                 = INB_ATT_UUID_16(0x2716),
    ///Current density unit - ampere per square metre
    INB_ATT_UNIT_AMPERE_PER_SQ_METRE                = INB_ATT_UUID_16(0x2717),
    ///Magnetic field strength unit - Ampere per metre
    INB_ATT_UNIT_AMPERE_PER_METRE                   = INB_ATT_UUID_16(0x2718),
    ///Amount concentration unit - mole per cubic metre
    INB_ATT_UNIT_MOLE_PER_CUBIC_METRE               = INB_ATT_UUID_16(0x2719),
    ///Mass Concentration unit - kilogram per cubic metre
    INB_ATT_UNIT_MASS_KG_PER_CUBIC_METRE            = INB_ATT_UUID_16(0x271A),
    ///Luminance unit - candela per square metre
    INB_ATT_UNIT_CANDELA_PER_SQ_METRE               = INB_ATT_UUID_16(0x271B),
    ///Refractive index unit
    INB_ATT_UNIT_REFRACTIVE_INDEX                   = INB_ATT_UUID_16(0x271C),
    ///Relative permeability unit
    INB_ATT_UNIT_RELATIVE_PERMEABILITY              = INB_ATT_UUID_16(0x271D),
    ///Plane angle unit - radian
    INB_ATT_UNIT_RADIAN                             = INB_ATT_UUID_16(0x2720),
    ///Solid angle unit - steradian
    INB_ATT_UNIT_STERADIAN                          = INB_ATT_UUID_16(0x2721),
    ///Frequency unit - Hertz
    INB_ATT_UNIT_HERTZ                              = INB_ATT_UUID_16(0x2722),
    ///Force unit - Newton
    INB_ATT_UNIT_NEWTON                             = INB_ATT_UUID_16(0x2723),
    ///Pressure unit - Pascal
    INB_ATT_UNIT_PASCAL                             = INB_ATT_UUID_16(0x2724),
    ///Energy unit - Joule
    INB_ATT_UNIT_JOULE                              = INB_ATT_UUID_16(0x2725),
    ///Power unit - Watt
    INB_ATT_UNIT_WATT                               = INB_ATT_UUID_16(0x2726),
    ///electric Charge unit - Coulomb
    INB_ATT_UNIT_COULOMB                            = INB_ATT_UUID_16(0x2727),
    ///Electric potential difference - Volt
    INB_ATT_UNIT_VOLT                               = INB_ATT_UUID_16(0x2728),
    ///Capacitance unit - Farad
    INB_ATT_UNIT_FARAD                              = INB_ATT_UUID_16(0x2729),
    ///electric resistance unit - Ohm
    INB_ATT_UNIT_OHM                                = INB_ATT_UUID_16(0x272A),
    ///Electric conductance - Siemens
    INB_ATT_UNIT_SIEMENS                            = INB_ATT_UUID_16(0x272B),
    ///Magnetic flux unit - Weber
    INB_ATT_UNIT_WEBER                              = INB_ATT_UUID_16(0x272C),
    ///Magnetic flux density unit - Tesla
    INB_ATT_UNIT_TESLA                              = INB_ATT_UUID_16(0x272D),
    ///Inductance unit - Henry
    INB_ATT_UNIT_HENRY                              = INB_ATT_UUID_16(0x272E),
    ///Temperature unit - degree Celsius
    INB_ATT_UNIT_CELSIUS                            = INB_ATT_UUID_16(0x272F),
    ///Luminous flux unit - lumen
    INB_ATT_UNIT_LUMEN                              = INB_ATT_UUID_16(0x2730),
    ///Illuminance unit - lux
    INB_ATT_UNIT_LUX                                = INB_ATT_UUID_16(0x2731),
    ///Activity referred to a radionuclide unit - becquerel
    INB_ATT_UNIT_BECQUEREL                          = INB_ATT_UUID_16(0x2732),
    ///Absorbed dose unit - Gray
    INB_ATT_UNIT_GRAY                               = INB_ATT_UUID_16(0x2733),
    ///Dose equivalent unit - Sievert
    INB_ATT_UNIT_SIEVERT                            = INB_ATT_UUID_16(0x2734),
    ///Catalytic activity unit - Katal
    INB_ATT_UNIT_KATAL                              = INB_ATT_UUID_16(0x2735),
    ///Synamic viscosity unit - Pascal second
    INB_ATT_UNIT_PASCAL_SECOND                      = INB_ATT_UUID_16(0x2740),
    ///Moment of force unit - Newton metre
    INB_ATT_UNIT_NEWTON_METRE                       = INB_ATT_UUID_16(0x2741),
    ///surface tension unit - Newton per metre
    INB_ATT_UNIT_NEWTON_PER_METRE                   = INB_ATT_UUID_16(0x2742),
    ///Angular velocity unit - radian per second
    INB_ATT_UNIT_RADIAN_PER_SECOND                  = INB_ATT_UUID_16(0x2743),
    ///Angular acceleration unit - radian per second squared
    INB_ATT_UNIT_RADIAN_PER_SECOND_SQ               = INB_ATT_UUID_16(0x2744),
    ///Heat flux density unit - Watt per square metre
    INB_ATT_UNIT_WATT_PER_SQ_METRE                  = INB_ATT_UUID_16(0x2745),
    ///HEat capacity unit - Joule per Kelvin
    INB_ATT_UNIT_JOULE_PER_KELVIN                   = INB_ATT_UUID_16(0x2746),
    ///Specific heat capacity unit - Joule per kilogram kelvin
    INB_ATT_UNIT_JOULE_PER_KG_KELVIN                = INB_ATT_UUID_16(0x2747),
    ///Specific Energy unit - Joule per kilogram
    INB_ATT_UNIT_JOULE_PER_KG                       = INB_ATT_UUID_16(0x2748),
    ///Thermal conductivity - Watt per metre Kelvin
    INB_ATT_UNIT_WATT_PER_METRE_KELVIN              = INB_ATT_UUID_16(0x2749),
    ///Energy Density unit - joule per cubic metre
    INB_ATT_UNIT_JOULE_PER_CUBIC_METRE              = INB_ATT_UUID_16(0x274A),
    ///Electric field strength unit - volt per metre
    INB_ATT_UNIT_VOLT_PER_METRE                     = INB_ATT_UUID_16(0x274B),
    ///Electric charge density unit - coulomb per cubic metre
    INB_ATT_UNIT_COULOMB_PER_CUBIC_METRE            = INB_ATT_UUID_16(0x274C),
    ///Surface charge density unit - coulomb per square metre
    INB_ATT_UNIT_SURF_COULOMB_PER_SQ_METRE          = INB_ATT_UUID_16(0x274D),
    ///Electric flux density unit - coulomb per square metre
    INB_ATT_UNIT_FLUX_COULOMB_PER_SQ_METRE          = INB_ATT_UUID_16(0x274E),
    ///Permittivity unit - farad per metre
    INB_ATT_UNIT_FARAD_PER_METRE                    = INB_ATT_UUID_16(0x274F),
    ///Permeability unit - henry per metre
    INB_ATT_UNIT_HENRY_PER_METRE                    = INB_ATT_UUID_16(0x2750),
    ///Molar energy unit - joule per mole
    INB_ATT_UNIT_JOULE_PER_MOLE                     = INB_ATT_UUID_16(0x2751),
    ///Molar entropy unit - joule per mole kelvin
    INB_ATT_UNIT_JOULE_PER_MOLE_KELVIN              = INB_ATT_UUID_16(0x2752),
    ///Exposure unit - coulomb per kilogram
    INB_ATT_UNIT_COULOMB_PER_KG                     = INB_ATT_UUID_16(0x2753),
    ///Absorbed dose rate unit - gray per second
    INB_ATT_UNIT_GRAY_PER_SECOND                    = INB_ATT_UUID_16(0x2754),
    ///Radiant intensity unit - watt per steradian
    INB_ATT_UNIT_WATT_PER_STERADIAN                 = INB_ATT_UUID_16(0x2755),
    ///Radiance unit - watt per square meter steradian
    INB_ATT_UNIT_WATT_PER_SQ_METRE_STERADIAN        = INB_ATT_UUID_16(0x2756),
    ///Catalytic activity concentration unit - katal per cubic metre
    INB_ATT_UNIT_KATAL_PER_CUBIC_METRE              = INB_ATT_UUID_16(0x2757),
    ///Time unit - minute
    INB_ATT_UNIT_MINUTE                             = INB_ATT_UUID_16(0x2760),
    ///Time unit - hour
    INB_ATT_UNIT_HOUR                               = INB_ATT_UUID_16(0x2761),
    ///Time unit - day
    INB_ATT_UNIT_DAY                                = INB_ATT_UUID_16(0x2762),
    ///Plane angle unit - degree
    INB_ATT_UNIT_ANGLE_DEGREE                       = INB_ATT_UUID_16(0x2763),
    ///Plane angle unit - minute
    INB_ATT_UNIT_ANGLE_MINUTE                       = INB_ATT_UUID_16(0x2764),
    ///Plane angle unit - second
    INB_ATT_UNIT_ANGLE_SECOND                       = INB_ATT_UUID_16(0x2765),
    ///Area unit - hectare
    INB_ATT_UNIT_HECTARE                            = INB_ATT_UUID_16(0x2766),
    ///Volume unit - litre
    INB_ATT_UNIT_LITRE                              = INB_ATT_UUID_16(0x2767),
    ///Mass unit - tonne
    INB_ATT_UNIT_TONNE                              = INB_ATT_UUID_16(0x2768),
    ///Pressure unit - bar
    INB_ATT_UNIT_BAR                                = INB_ATT_UUID_16(0x2780),
    ///Pressure unit - millimetre of mercury
    INB_ATT_UNIT_MM_MERCURY                         = INB_ATT_UUID_16(0x2781),
    ///Length unit - angstrom
    INB_ATT_UNIT_ANGSTROM                           = INB_ATT_UUID_16(0x2782),
    ///Length unit - nautical mile
    INB_ATT_UNIT_NAUTICAL_MILE                      = INB_ATT_UUID_16(0x2783),
    ///Area unit - barn
    INB_ATT_UNIT_BARN                               = INB_ATT_UUID_16(0x2784),
    ///Velocity unit - knot
    INB_ATT_UNIT_KNOT                               = INB_ATT_UUID_16(0x2785),
    ///Logarithmic radio quantity unit - neper
    INB_ATT_UNIT_NEPER                              = INB_ATT_UUID_16(0x2786),
    ///Logarithmic radio quantity unit - bel
    INB_ATT_UNIT_BEL                                = INB_ATT_UUID_16(0x2787),
    ///Length unit - yard
    INB_ATT_UNIT_YARD                               = INB_ATT_UUID_16(0x27A0),
    ///Length unit - parsec
    INB_ATT_UNIT_PARSEC                             = INB_ATT_UUID_16(0x27A1),
    ///length unit - inch
    INB_ATT_UNIT_INCH                               = INB_ATT_UUID_16(0x27A2),
    ///length unit - foot
    INB_ATT_UNIT_FOOT                               = INB_ATT_UUID_16(0x27A3),
    ///length unit - mile
    INB_ATT_UNIT_MILE                               = INB_ATT_UUID_16(0x27A4),
    ///pressure unit - pound-force per square inch
    INB_ATT_UNIT_POUND_FORCE_PER_SQ_INCH            = INB_ATT_UUID_16(0x27A5),
    ///velocity unit - kilometre per hour
    INB_ATT_UNIT_KM_PER_HOUR                        = INB_ATT_UUID_16(0x27A6),
    ///velocity unit - mile per hour
    INB_ATT_UNIT_MILE_PER_HOUR                      = INB_ATT_UUID_16(0x27A7),
    ///angular velocity unit - revolution per minute
    INB_ATT_UNIT_REVOLUTION_PER_MINUTE              = INB_ATT_UUID_16(0x27A8),
    ///energy unit - gram calorie
    INB_ATT_UNIT_GRAM_CALORIE                       = INB_ATT_UUID_16(0x27A9),
    ///energy unit - kilogram calorie
    INB_ATT_UNIT_KG_CALORIE                         = INB_ATT_UUID_16(0x27AA),
    /// energy unit - kilowatt hour
    INB_ATT_UNIT_KILOWATT_HOUR                      = INB_ATT_UUID_16(0x27AB),
    ///thermodynamic temperature unit - degree Fahrenheit
    INB_ATT_UNIT_FAHRENHEIT                         = INB_ATT_UUID_16(0x27AC),
    ///percentage
    INB_ATT_UNIT_PERCENTAGE                         = INB_ATT_UUID_16(0x27AD),
    ///per mille
    INB_ATT_UNIT_PER_MILLE                          = INB_ATT_UUID_16(0x27AE),
    ///period unit - beats per minute)
    INB_ATT_UNIT_BEATS_PER_MINUTE                   = INB_ATT_UUID_16(0x27AF),
    ///electric charge unit - ampere hours
    INB_ATT_UNIT_AMPERE_HOURS                       = INB_ATT_UUID_16(0x27B0),
    ///mass density unit - milligram per decilitre
    INB_ATT_UNIT_MILLIGRAM_PER_DECILITRE            = INB_ATT_UUID_16(0x27B1),
    ///mass density unit - millimole per litre
    INB_ATT_UNIT_MILLIMOLE_PER_LITRE                = INB_ATT_UUID_16(0x27B2),
    ///time unit - year
    INB_ATT_UNIT_YEAR                               = INB_ATT_UUID_16(0x27B3),
    ////time unit - month
    INB_ATT_UNIT_MONTH                              = INB_ATT_UUID_16(0x27B4),


    /*---------------- DECLARATIONS -----------------*/
    /// Primary service Declaration
    INB_ATT_DECL_PRIMARY_SERVICE                     = INB_ATT_UUID_16(0x2800),
    /// Secondary service Declaration
    INB_ATT_DECL_SECONDARY_SERVICE                   = INB_ATT_UUID_16(0x2801),
    /// Include Declaration
    INB_ATT_DECL_INCLUDE                             = INB_ATT_UUID_16(0x2802),
    /// Characteristic Declaration
    INB_ATT_DECL_CHARACTERISTIC                      = INB_ATT_UUID_16(0x2803),


    /*----------------- DESCRIPTORS -----------------*/
    /// Characteristic extended properties
    INB_ATT_DESC_CHAR_EXT_PROPERTIES                 = INB_ATT_UUID_16(0x2900),
    /// Characteristic user description
    INB_ATT_DESC_CHAR_USER_DESCRIPTION               = INB_ATT_UUID_16(0x2901),
    /// Client characteristic configuration
    INB_ATT_DESC_CLIENT_CHAR_CFG                     = INB_ATT_UUID_16(0x2902),
    /// Server characteristic configuration
    INB_ATT_DESC_SERVER_CHAR_CFG                     = INB_ATT_UUID_16(0x2903),
    /// Characteristic Presentation Format
    INB_ATT_DESC_CHAR_PRES_FORMAT                    = INB_ATT_UUID_16(0x2904),
    /// Characteristic Aggregate Format
    INB_ATT_DESC_CHAR_AGGREGATE_FORMAT               = INB_ATT_UUID_16(0x2905),
    /// Valid Range
    INB_ATT_DESC_VALID_RANGE                         = INB_ATT_UUID_16(0x2906),
    /// External Report Reference
    INB_ATT_DESC_EXT_REPORT_REF                      = INB_ATT_UUID_16(0x2907),
    /// Report Reference
    INB_ATT_DESC_REPORT_REF                          = INB_ATT_UUID_16(0x2908),
    /// Environmental Sensing Configuration
    INB_ATT_DESC_ES_CONFIGURATION                    = INB_ATT_UUID_16(0x290B),
    /// Environmental Sensing Measurement
    INB_ATT_DESC_ES_MEASUREMENT                      = INB_ATT_UUID_16(0x290C),
    /// Environmental Sensing Trigger Setting
    INB_ATT_DESC_ES_TRIGGER_SETTING                  = INB_ATT_UUID_16(0x290D),


    /*--------------- CHARACTERISTICS ---------------*/
    /// Device name
    INB_ATT_CHAR_DEVICE_NAME                        = INB_ATT_UUID_16(0x2A00),
    /// Appearance
    INB_ATT_CHAR_APPEARANCE                         = INB_ATT_UUID_16(0x2A01),
    /// Privacy flag
    INB_ATT_CHAR_PRIVACY_FLAG                       = INB_ATT_UUID_16(0x2A02),
    /// Reconnection address
    INB_ATT_CHAR_RECONNECTION_ADDR                  = INB_ATT_UUID_16(0x2A03),
    /// Peripheral preferred connection parameters
    INB_ATT_CHAR_PERIPH_PREF_CON_PARAM              = INB_ATT_UUID_16(0x2A04),
    /// Service handles changed
    INB_ATT_CHAR_SERVICE_CHANGED                    = INB_ATT_UUID_16(0x2A05),
    /// Alert Level characteristic
    INB_ATT_CHAR_ALERT_LEVEL                        = INB_ATT_UUID_16(0x2A06),
    /// Tx Power Level
    INB_ATT_CHAR_TX_POWER_LEVEL                     = INB_ATT_UUID_16(0x2A07),
    /// Date Time
    INB_ATT_CHAR_DATE_TIME                          = INB_ATT_UUID_16(0x2A08),
    /// Day of Week
    INB_ATT_CHAR_DAY_WEEK                           = INB_ATT_UUID_16(0x2A09),
    /// Day Date Time
    INB_ATT_CHAR_DAY_DATE_TIME                      = INB_ATT_UUID_16(0x2A0A),
    /// Exact time 256
    INB_ATT_CHAR_EXACT_TIME_256                     = INB_ATT_UUID_16(0x2A0C),
    /// DST Offset
    INB_ATT_CHAR_DST_OFFSET                         = INB_ATT_UUID_16(0x2A0D),
    /// Time zone
    INB_ATT_CHAR_TIME_ZONE                          = INB_ATT_UUID_16(0x2A0E),
    /// Local time Information
    INB_ATT_CHAR_LOCAL_TIME_INFO                    = INB_ATT_UUID_16(0x2A0F),
    /// Time with DST
    INB_ATT_CHAR_TIME_WITH_DST                      = INB_ATT_UUID_16(0x2A11),
    /// Time Accuracy
    INB_ATT_CHAR_TIME_ACCURACY                      = INB_ATT_UUID_16(0x2A12),
    ///Time Source
    INB_ATT_CHAR_TIME_SOURCE                        = INB_ATT_UUID_16(0x2A13),
    /// Reference Time Information
    INB_ATT_CHAR_REFERENCE_TIME_INFO                = INB_ATT_UUID_16(0x2A14),
    /// Time Update Control Point
    INB_ATT_CHAR_TIME_UPDATE_CNTL_POINT             = INB_ATT_UUID_16(0x2A16),
    /// Time Update State
    INB_ATT_CHAR_TIME_UPDATE_STATE                  = INB_ATT_UUID_16(0x2A17),
    /// Glucose Measurement
    INB_ATT_CHAR_GLUCOSE_MEAS                       = INB_ATT_UUID_16(0x2A18),
    /// Battery Level
    INB_ATT_CHAR_BATTERY_LEVEL                      = INB_ATT_UUID_16(0x2A19),
    /// Temperature Measurement
    INB_ATT_CHAR_TEMPERATURE_MEAS                   = INB_ATT_UUID_16(0x2A1C),
    /// Temperature Type
    INB_ATT_CHAR_TEMPERATURE_TYPE                   = INB_ATT_UUID_16(0x2A1D),
    /// Intermediate Temperature
    INB_ATT_CHAR_INTERMED_TEMPERATURE               = INB_ATT_UUID_16(0x2A1E),
    /// Measurement Interval
    INB_ATT_CHAR_MEAS_INTERVAL                      = INB_ATT_UUID_16(0x2A21),
    /// Boot Keyboard Input Report
    INB_ATT_CHAR_BOOT_KB_IN_REPORT                  = INB_ATT_UUID_16(0x2A22),
    /// System ID
    INB_ATT_CHAR_SYS_ID                             = INB_ATT_UUID_16(0x2A23),
    /// Model Number String
    INB_ATT_CHAR_MODEL_NB                           = INB_ATT_UUID_16(0x2A24),
    /// Serial Number String
    INB_ATT_CHAR_SERIAL_NB                          = INB_ATT_UUID_16(0x2A25),
    /// Firmware Revision String
    INB_ATT_CHAR_FW_REV                             = INB_ATT_UUID_16(0x2A26),
    /// Hardware revision String
    INB_ATT_CHAR_HW_REV                             = INB_ATT_UUID_16(0x2A27),
    /// Software Revision String
    INB_ATT_CHAR_SW_REV                             = INB_ATT_UUID_16(0x2A28),
    /// Manufacturer Name String
    INB_ATT_CHAR_MANUF_NAME                         = INB_ATT_UUID_16(0x2A29),
    /// IEEE Regulatory Certification Data List
    INB_ATT_CHAR_IEEE_CERTIF                        = INB_ATT_UUID_16(0x2A2A),
    /// CT Time
    INB_ATT_CHAR_CT_TIME                            = INB_ATT_UUID_16(0x2A2B),
    /// Magnetic Declination
    INB_ATT_CHAR_MAGN_DECLINE                       = INB_ATT_UUID_16(0x2A2C),
    /// Scan Refresh
    INB_ATT_CHAR_SCAN_REFRESH                       = INB_ATT_UUID_16(0x2A31),
    /// Boot Keyboard Output Report
    INB_ATT_CHAR_BOOT_KB_OUT_REPORT                 = INB_ATT_UUID_16(0x2A32),
    /// Boot Mouse Input Report
    INB_ATT_CHAR_BOOT_MOUSE_IN_REPORT               = INB_ATT_UUID_16(0x2A33),
    /// Glucose Measurement Context
    INB_ATT_CHAR_GLUCOSE_MEAS_CTX                   = INB_ATT_UUID_16(0x2A34),
    /// Blood Pressure Measurement
    INB_ATT_CHAR_BLOOD_PRESSURE_MEAS                = INB_ATT_UUID_16(0x2A35),
    /// Intermediate Cuff Pressure
    INB_ATT_CHAR_INTERMEDIATE_CUFF_PRESSURE         = INB_ATT_UUID_16(0x2A36),
    /// Heart Rate Measurement
    INB_ATT_CHAR_HEART_RATE_MEAS                    = INB_ATT_UUID_16(0x2A37),
    /// Body Sensor Location
    INB_ATT_CHAR_BODY_SENSOR_LOCATION               = INB_ATT_UUID_16(0x2A38),
    /// Heart Rate Control Point
    INB_ATT_CHAR_HEART_RATE_CNTL_POINT              = INB_ATT_UUID_16(0x2A39),
    /// Alert Status
    INB_ATT_CHAR_ALERT_STATUS                       = INB_ATT_UUID_16(0x2A3F),
    /// Ringer Control Point
    INB_ATT_CHAR_RINGER_CNTL_POINT                  = INB_ATT_UUID_16(0x2A40),
    /// Ringer Setting
    INB_ATT_CHAR_RINGER_SETTING                     = INB_ATT_UUID_16(0x2A41),
    /// Alert Category ID Bit Mask
    INB_ATT_CHAR_ALERT_CAT_ID_BIT_MASK              = INB_ATT_UUID_16(0x2A42),
    /// Alert Category ID
    INB_ATT_CHAR_ALERT_CAT_ID                       = INB_ATT_UUID_16(0x2A43),
    /// Alert Notification Control Point
    INB_ATT_CHAR_ALERT_NTF_CTNL_PT                  = INB_ATT_UUID_16(0x2A44),
    /// Unread Alert Status
    INB_ATT_CHAR_UNREAD_ALERT_STATUS                = INB_ATT_UUID_16(0x2A45),
    /// New Alert
    INB_ATT_CHAR_NEW_ALERT                          = INB_ATT_UUID_16(0x2A46),
    /// Supported New Alert Category
    INB_ATT_CHAR_SUP_NEW_ALERT_CAT                  = INB_ATT_UUID_16(0x2A47),
    /// Supported Unread Alert Category
    INB_ATT_CHAR_SUP_UNREAD_ALERT_CAT               = INB_ATT_UUID_16(0x2A48),
    /// Blood Pressure Feature
    INB_ATT_CHAR_BLOOD_PRESSURE_FEATURE             = INB_ATT_UUID_16(0x2A49),
    /// HID Information
    INB_ATT_CHAR_HID_INFO                           = INB_ATT_UUID_16(0x2A4A),
    /// Report Map
    INB_ATT_CHAR_REPORT_MAP                         = INB_ATT_UUID_16(0x2A4B),
    /// HID Control Point
    INB_ATT_CHAR_HID_CTNL_PT                        = INB_ATT_UUID_16(0x2A4C),
    /// Report
    INB_ATT_CHAR_REPORT                             = INB_ATT_UUID_16(0x2A4D),
    /// Protocol Mode
    INB_ATT_CHAR_PROTOCOL_MODE                      = INB_ATT_UUID_16(0x2A4E),
    /// Scan Interval Window
    INB_ATT_CHAR_SCAN_INTV_WD                       = INB_ATT_UUID_16(0x2A4F),
    /// PnP ID
    INB_ATT_CHAR_PNP_ID                             = INB_ATT_UUID_16(0x2A50),
    /// Glucose Feature
    INB_ATT_CHAR_GLUCOSE_FEATURE                    = INB_ATT_UUID_16(0x2A51),
    /// Record access control point
    INB_ATT_CHAR_REC_ACCESS_CTRL_PT                 = INB_ATT_UUID_16(0x2A52),
    /// RSC Measurement
    INB_ATT_CHAR_RSC_MEAS                           = INB_ATT_UUID_16(0x2A53),
    /// RSC Feature
    INB_ATT_CHAR_RSC_FEAT                           = INB_ATT_UUID_16(0x2A54),
    /// SC Control Point
    INB_ATT_CHAR_SC_CNTL_PT                         = INB_ATT_UUID_16(0x2A55),
    /// CSC Measurement
    INB_ATT_CHAR_CSC_MEAS                           = INB_ATT_UUID_16(0x2A5B),
    /// CSC Feature
    INB_ATT_CHAR_CSC_FEAT                           = INB_ATT_UUID_16(0x2A5C),
    /// Sensor Location
    INB_ATT_CHAR_SENSOR_LOC                         = INB_ATT_UUID_16(0x2A5D),
    /// PLX Spot-Check Measurement
    INB_ATT_CHAR_PLX_SPOT_CHECK_MEASUREMENT_LOC     = INB_ATT_UUID_16(0x2A5E),
    /// PLX Continuous Measurement
    INB_ATT_CHAR_PLX_CONTINUOUS_MEASUREMENT_LOC     = INB_ATT_UUID_16(0x2A5F),
    /// PLX Features
    INB_ATT_CHAR_PLX_FEATURES_LOC                   = INB_ATT_UUID_16(0x2A60),
    /// CP Measurement
    INB_ATT_CHAR_CP_MEAS                            = INB_ATT_UUID_16(0x2A63),
    /// CP Vector
    INB_ATT_CHAR_CP_VECTOR                          = INB_ATT_UUID_16(0x2A64),
    /// CP Feature
    INB_ATT_CHAR_CP_FEAT                            = INB_ATT_UUID_16(0x2A65),
    /// CP Control Point
    INB_ATT_CHAR_CP_CNTL_PT                         = INB_ATT_UUID_16(0x2A66),
    /// Location and Speed
    INB_ATT_CHAR_LOC_SPEED                          = INB_ATT_UUID_16(0x2A67),
    /// Navigation
    INB_ATT_CHAR_NAVIGATION                         = INB_ATT_UUID_16(0x2A68),
    /// Position Quality
    INB_ATT_CHAR_POS_QUALITY                        = INB_ATT_UUID_16(0x2A69),
    /// LN Feature
    INB_ATT_CHAR_LN_FEAT                            = INB_ATT_UUID_16(0x2A6A),
    /// LN Control Point
    INB_ATT_CHAR_LN_CNTL_PT                         = INB_ATT_UUID_16(0x2A6B),
    /// Elevation
    INB_ATT_CHAR_ELEVATION                          = INB_ATT_UUID_16(0x2A6C),
    /// Pressure
    INB_ATT_CHAR_PRESSURE                           = INB_ATT_UUID_16(0x2A6D),
    /// Temperature
    INB_ATT_CHAR_TEMPERATURE                        = INB_ATT_UUID_16(0x2A6E),
    /// Humidity
    INB_ATT_CHAR_HUMIDITY                           = INB_ATT_UUID_16(0x2A6F),
    /// True Wind Speed
    INB_ATT_CHAR_TRUE_WIND_SPEED                    = INB_ATT_UUID_16(0x2A70),
    /// True Wind Direction
    INB_ATT_CHAR_TRUE_WIND_DIR                      = INB_ATT_UUID_16(0x2A71),
    /// Apparent Wind Speed
    INB_ATT_CHAR_APRNT_WIND_SPEED                   = INB_ATT_UUID_16(0x2A72),
    /// Apparent Wind Direction
    INB_ATT_CHAR_APRNT_WIND_DIRECTION               = INB_ATT_UUID_16(0x2A73),
    /// Gust Factor
    INB_ATT_CHAR_GUST_FACTOR                        = INB_ATT_UUID_16(0x2A74),
    /// Pollen Concentration
    INB_ATT_CHAR_POLLEN_CONC                        = INB_ATT_UUID_16(0x2A75),
    /// UV Index
    INB_ATT_CHAR_UV_INDEX                           = INB_ATT_UUID_16(0x2A76),
    /// Irradiance
    INB_ATT_CHAR_IRRADIANCE                         = INB_ATT_UUID_16(0x2A77),
    /// Rainfall
    INB_ATT_CHAR_RAINFALL                           = INB_ATT_UUID_16(0x2A78),
    /// Wind Chill
    INB_ATT_CHAR_WIND_CHILL                         = INB_ATT_UUID_16(0x2A79),
    /// Heat Index
    INB_ATT_CHAR_HEAT_INDEX                         = INB_ATT_UUID_16(0x2A7A),
    /// Dew Point
    INB_ATT_CHAR_DEW_POINT                          = INB_ATT_UUID_16(0x2A7B),
    /// Descriptor Value Changed
    INB_ATT_CHAR_DESCRIPTOR_VALUE_CHANGED           = INB_ATT_UUID_16(0x2A7D),
    /// Aerobic Heart Rate Lower Limit
    INB_ATT_CHAR_AEROBIC_HEART_RATE_LOWER_LIMIT     = INB_ATT_UUID_16(0x2A7E),
    /// Aerobic Threshhold
    INB_ATT_CHAR_AEROBIC_THRESHHOLD                 = INB_ATT_UUID_16(0x2A7F),
    /// Age
    INB_ATT_CHAR_AGE                                = INB_ATT_UUID_16(0x2A80),
    /// Anaerobic Heart Rate Lower Limit
    INB_ATT_CHAR_ANAEROBIC_HEART_RATE_LOWER_LIMIT   = INB_ATT_UUID_16(0x2A81),
    /// Anaerobic Heart Rate Upper Limit
    INB_ATT_CHAR_ANAEROBIC_HEART_RATE_UPPER_LIMIT   = INB_ATT_UUID_16(0x2A82),
    /// Anaerobic Threshhold
    INB_ATT_CHAR_ANAEROBIC_THRESHHOLD               = INB_ATT_UUID_16(0x2A83),
    /// Aerobic Heart Rate Upper Limit
    INB_ATT_CHAR_AEROBIC_HEART_RATE_UPPER_LIMIT     = INB_ATT_UUID_16(0x2A84),
    /// Date Of Birth
    INB_ATT_CHAR_DATE_OF_BIRTH                      = INB_ATT_UUID_16(0x2A85),
    /// Date Of Threshold Assessment
    INB_ATT_CHAR_DATE_OF_THRESHOLD_ASSESSMENT       = INB_ATT_UUID_16(0x2A86),
    /// Email Address
    INB_ATT_CHAR_EMAIL_ADDRESS                      = INB_ATT_UUID_16(0x2A87),
    /// Fat Burn Heart Rate Lower Limit
    INB_ATT_CHAR_FAT_BURN_HEART_RATE_LOWER_LIMIT    = INB_ATT_UUID_16(0x2A88),
    /// Fat Burn Heart Rate Upper Limit
    INB_ATT_CHAR_FAT_BURN_HEART_RATE_UPPER_LIMIT    = INB_ATT_UUID_16(0x2A89),
    /// First Name
    INB_ATT_CHAR_FIRST_NAME                         = INB_ATT_UUID_16(0x2A8A),
    /// Five Zone Heart Rate Limits
    INB_ATT_CHAR_FIVE_ZONE_HEART_RATE_LIMITS        = INB_ATT_UUID_16(0x2A8B),
    /// Gender
    INB_ATT_CHAR_GENDER                             = INB_ATT_UUID_16(0x2A8C),
    /// Max Heart Rate
    INB_ATT_CHAR_MAX_HEART_RATE                     = INB_ATT_UUID_16(0x2A8D),
    /// Height
    INB_ATT_CHAR_HEIGHT                             = INB_ATT_UUID_16(0x2A8E),
    /// Hip Circumference
    INB_ATT_CHAR_HIP_CIRCUMFERENCE                  = INB_ATT_UUID_16(0x2A8F),
    /// Last Name 
    INB_ATT_CHAR_LAST_NAME                          = INB_ATT_UUID_16(0x2A90),
    /// Maximum Recommended Heart Rate
    INB_ATT_CHAR_MAXIMUM_RECOMMENDED_HEART_RATE     = INB_ATT_UUID_16(0x2A91),
    /// Resting Heart Rate
    INB_ATT_CHAR_RESTING_HEART_RATE                 = INB_ATT_UUID_16(0x2A92),
    /// Sport Type For Aerobic And Anaerobic Thresholds
    INB_ATT_CHAR_SPORT_TYPE_FOR_AEROBIC_AND_ANAEROBIC_THRESHOLDS = INB_ATT_UUID_16(0x2A93),
    /// Three Zone Heart Rate Limits
    INB_ATT_CHAR_THREE_ZONE_HEART_RATE_LIMITS       = INB_ATT_UUID_16(0x2A94),
    /// Two Zone Heart Rate Limit
    INB_ATT_CHAR_TWO_ZONE_HEART_RATE_LIMIT          = INB_ATT_UUID_16(0x2A95),
    /// Vo2 Max
    INB_ATT_CHAR_VO2_MAX                            = INB_ATT_UUID_16(0x2A96),
    /// Waist Circumference
    INB_ATT_CHAR_WAIST_CIRCUMFERENCE                = INB_ATT_UUID_16(0x2A97),
    /// Weight
    INB_ATT_CHAR_WEIGHT                             = INB_ATT_UUID_16(0x2A98),
    /// Database Change Increment
    INB_ATT_CHAR_DATABASE_CHANGE_INCREMENT          = INB_ATT_UUID_16(0x2A99),
    /// User Index 
    INB_ATT_CHAR_USER_INDEX                         = INB_ATT_UUID_16(0x2A9A),
    /// Body Composition Feature
    INB_ATT_CHAR_BODY_COMPOSITION_FEATURE           = INB_ATT_UUID_16(0x2A9B),
    /// Body Composition Measurement
    INB_ATT_CHAR_BODY_COMPOSITION_MEASUREMENT       = INB_ATT_UUID_16(0x2A9C),
    /// Weight Measurement
    INB_ATT_CHAR_WEIGHT_MEASUREMENT                 = INB_ATT_UUID_16(0x2A9D),
    /// Weight Scale Feature
    INB_ATT_CHAR_WEIGHT_SCALE_FEATURE               = INB_ATT_UUID_16(0x2A9E),
    /// User Control Point
    INB_ATT_CHAR_USER_CONTROL_POINT                 = INB_ATT_UUID_16(0x2A9F),
    /// Flux Density - 2D
    INB_ATT_CHAR_MAGN_FLUX_2D                       = INB_ATT_UUID_16(0x2AA0),
    /// Magnetic Flux Density - 3D
    INB_ATT_CHAR_MAGN_FLUX_3D                       = INB_ATT_UUID_16(0x2AA1),
    /// Language string
    INB_ATT_CHAR_LANGUAGE                           = INB_ATT_UUID_16(0x2AA2),
    /// Barometric Pressure Trend
    INB_ATT_CHAR_BAR_PRES_TREND                     = INB_ATT_UUID_16(0x2AA3),
    /// Central Address Resolution Support
    INB_ATT_CHAR_CTL_ADDR_RESOL_SUPP                = INB_ATT_UUID_16(0x2AA6),
    /// CGM Measurement
    INB_ATT_CHAR_CGM_MEASUREMENT                    = INB_ATT_UUID_16(0x2AA7),
    /// CGM Features
    INB_ATT_CHAR_CGM_FEATURES                       = INB_ATT_UUID_16(0x2AA8),
    /// CGM Status
    INB_ATT_CHAR_CGM_STATUS                         = INB_ATT_UUID_16(0x2AA9),
    /// CGM Session Start
    INB_ATT_CHAR_CGM_SESSION_START                  = INB_ATT_UUID_16(0x2AAA),
    /// CGM Session Run
    INB_ATT_CHAR_CGM_SESSION_RUN                    = INB_ATT_UUID_16(0x2AAB),
    /// CGM Specific Ops Control Point
    INB_ATT_CHAR_CGM_SPECIFIC_OPS_CTRL_PT           = INB_ATT_UUID_16(0x2AAC),
    /// Resolvable Private Address only
    INB_ATT_CHAR_RSLV_PRIV_ADDR_ONLY                = INB_ATT_UUID_16(0x2AC9),

    /// Mesh Provisioning Data In
    INB_ATT_CHAR_MESH_PROV_DATA_IN                  = INB_ATT_UUID_16(0x2ADB),
    /// Mesh Provisioning Data Out
    INB_ATT_CHAR_MESH_PROV_DATA_OUT                 = INB_ATT_UUID_16(0x2ADC),
    /// Mesh Proxy Data In
    INB_ATT_CHAR_MESH_PROXY_DATA_IN                 = INB_ATT_UUID_16(0x2ADD),
    /// Mesh Proxy Data Out
    INB_ATT_CHAR_MESH_PROXY_DATA_OUT                = INB_ATT_UUID_16(0x2ADE),
};

/// Format for Characteristic Presentation
enum inb_pres_fmt {
    /// unsigned 1-bit: true or false
    INB_ATT_FORMAT_BOOL     = 0x01,
    /// unsigned 2-bit integer
    INB_ATT_FORMAT_2BIT,
    /// unsigned 4-bit integer
    INB_ATT_FORMAT_NIBBLE,
    /// unsigned 8-bit integer
    INB_ATT_FORMAT_UINT8,
    /// unsigned 12-bit integer
    INB_ATT_FORMAT_UINT12,
    /// unsigned 16-bit integer
    INB_ATT_FORMAT_UINT16,
    /// unsigned 24-bit integer
    INB_ATT_FORMAT_UINT24,
    /// unsigned 32-bit integer
    INB_ATT_FORMAT_UINT32,
    /// unsigned 48-bit integer
    INB_ATT_FORMAT_UINT48,
    /// unsigned 64-bit integer
    INB_ATT_FORMAT_UINT64,
    /// unsigned 128-bit integer
    INB_ATT_FORMAT_UINT128,
    /// signed 8-bit integer
    INB_ATT_FORMAT_SINT8,
    /// signed 12-bit integer
    INB_ATT_FORMAT_SINT12,
    /// signed 16-bit integer
    INB_ATT_FORMAT_SINT16,
    /// signed 24-bit integer
    INB_ATT_FORMAT_SINT24,
    /// signed 32-bit integer
    INB_ATT_FORMAT_SINT32,
    /// signed 48-bit integer
    INB_ATT_FORMAT_SINT48,
    /// signed 64-bit integer
    INB_ATT_FORMAT_SINT64,
    /// signed 128-bit integer
    INB_ATT_FORMAT_SINT128,
    /// IEEE-754 32-bit floating point
    INB_ATT_FORMAT_FLOAT32,
    /// IEEE-754 64-bit floating point
    INB_ATT_FORMAT_FLOAT64,
    /// IEEE-11073 16-bit SFLOAT
    INB_ATT_FORMAT_SFLOAT,
    /// IEEE-11073 32-bit FLOAT
    INB_ATT_FORMAT_FLOAT,
    /// IEEE-20601 format
    INB_ATT_FORMAT_DUINT16,
    /// UTF-8 string
    INB_ATT_FORMAT_UTF8S,
    /// UTF-16 string
    INB_ATT_FORMAT_UTF16S,
    /// Opaque structure
    INB_ATT_FORMAT_STRUCT,
    /// Last format
    INB_ATT_FORMAT_LAST
};

/// @} INB_ATT

#endif	/* INB_ATT_H */

