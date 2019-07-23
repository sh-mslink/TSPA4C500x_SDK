#ifndef __MSRCU_DEV_BLE_DISCOVERY_H
#define __MSRCU_DEV_BLE_DISCOVERY_H

#include "stdint.h"

//#define UUID128(name, ...)\
//    uint8_t name[16];

#define TPPS_UUID_LEN 16	

typedef enum
{
	EVT_BLE_DISC_IDLE           = 0,
	EVT_BLE_DISC_SVC_CMP     		= 1,
	EVT_BLE_DISC_INCL_SVC_CMP   = 2,
	EVT_BLE_DISC_CHAR_CMP    		= 3,
	EVT_BLE_DISC_CHAR_DESC_CMP  = 4,
}msrcuBleDiscState_t;

enum
{
	DISC_PROP_FIELD_BP_MASK				= 0X01,	//broadcast permitted
	DISC_PROP_FIELD_RD_MASK				= 0x02,	//read permitted
	DISC_PROP_FIELD_WR_NRSP_MASK 	= 0x04,	//write without response permitted
	DISC_PROP_FIELD_WR_MASK 			= 0x08,	//write permitted
	DISC_PROP_FIELD_NTF_MASK    	= 0x10,	//notify permitted
	DISC_PROP_FIELD_IND_MASK    	= 0x20,	//indicate permitted
	DISC_PROP_FIELD_AUTH_MASK   	= 0x40,	//authenticated signed writes permitted	
	DISC_PROP_FIELD_EXT_MASK    	= 0x80, //extend properties permitted
};


typedef struct msrcu_evt_disc_char_desc_ind
{
		/// Connection index
		uint8_t conidx;
    /// database element handle
    uint16_t attr_hdl;
	
    /// UUID length
    uint8_t uuid_len;
    /// Descriptor UUID
    uint8_t uuid[16];
}msrcu_evt_disc_char_desc_ind_t;


typedef struct 
{
	/// database element handle
	uint16_t attr_hdl;
	/// UUID length
	uint8_t uuid_len;
	/// Descriptor UUID
	uint8_t uuid[16];
}DiscCharDesc_t;

typedef struct 
{
	uint8_t char_desc_num;
	DiscCharDesc_t Char[50];
}DiscCharDescInfo_t;

/// Discovery Characteristic Descriptor indication Structure
typedef struct 
{
	/// Connection index
	uint8_t conidx;
	DiscCharDescInfo_t char_info[10];
}msrcuDiscCharDescInfo_t;

 
/// Discovery All Characteristic indication Structure
typedef struct msrcu_evt_disc_char_ind
{
	/// Connection index
	uint8_t conidx;
    /// database element handle
    uint16_t attr_hdl;
    /// pointer attribute handle to UUID
    uint16_t pointer_hdl;
    /// properties
    uint8_t prop;
    /// UUID length
    uint8_t uuid_len;
    /// characteristic UUID
    uint8_t uuid[];
} msrcu_evt_disc_char_ind_t;

/// Discovery All Characteristic indication Structure
typedef struct 
{
	/// Connection index
	uint8_t conidx;
    /// database element handle
    uint16_t attr_hdl;
    /// pointer attribute handle to UUID
    uint16_t pointer_hdl;
    /// properties
    uint8_t prop;
    /// UUID length
    uint8_t uuid_len;
    /// characteristic UUID
    uint8_t uuid[16];
}CharDescInfo_t;

/// Discovery Characteristic Descriptor indication Structure
typedef struct 
{
	uint8_t char_num;
	CharDescInfo_t char_info[50];
}msrcuDiscCharInfo_t;

extern msrcuBleDiscState_t g_tBleDiscSt ;
void msrcu_dev_ble_disc_start(void);

int handle_gatt_discovery_evt(uint16_t eid, void *pv);
int FindHandleForPermitNTF(uint8_t condix, uint16_t* handle , uint8_t *uuid );
int FindHandleForPermitWR(uint8_t condix, uint16_t* handle , uint8_t *uuid);
#endif

