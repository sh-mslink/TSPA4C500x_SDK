#ifndef INB_SDR_H
#define INB_SDR_H

enum {
	SDR_ERR_NO_ERROR = 0x0,
	SDR_ERR_NOT_READY = 0x1,
	SDR_ERR_INVALID_PARAM = 0x2,
	SDR_ERR_NO_RESOURCE = 0x4,
	SDR_ERR_ABORT = 0x8,
	SDR_ERR_TX_NOT_DONE = 0x10,
	SDR_ERR_RX_CRC = 0x20,
	SDR_ERR_RX_FLOW = 0x40,
	SDR_ERR_RX_SYNC = 0x80,
	SDR_ERR_RX_TIMEERR = 0x100,
	SDR_ERR_RX_LENERR = 0x200,
	SDR_ERR_RX_MISC = 0x400,
};

enum sdr_rate
{
	SDR_RATE_1M,
	SDR_RATE_2M,
	SDR_RATE_125K,
	SDR_RATE_500K,
};

typedef struct {
	uint16_t length;
	uint8_t *buffer;
	uint8_t status;	
} sdr_desc_t;

typedef struct {
	uint16_t master;
	uint16_t address;

	uint8_t num_tx_desc;
	sdr_desc_t *tx_desc;

	uint8_t num_rx_desc;
	sdr_desc_t *rx_desc;

} sdr_node_t;


typedef struct {
	uint32_t net_addr;
	int ch_idx;
	int tx_rate;
	int rx_rate;
} sdr_net_t;

int in_sdr_1_to_1_trans(sdr_net_t *net, sdr_node_t *node);
int in_sdr_1_to_m_trans(sdr_net_t *net, sdr_node_t *node, uint16_t dst_addr);
int in_sdr_m_to_1_trans(sdr_net_t *net, sdr_node_t *l_node, int num_m_node, sdr_node_t *m_node);

#endif

