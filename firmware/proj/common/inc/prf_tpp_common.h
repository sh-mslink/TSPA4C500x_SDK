#ifndef __PRF_TPP_COMMON_H__
#define __PRF_TPP_COMMON_H__


#define TPP_SERCICE_UUID_LEN    (2)
#define TPP_SERCICE_UUID        "\xFF\xFF"


enum
{
    TPP_IDX_SVC,
    
    TPP_IDX_WR_DATA_CHAR,
    TPP_IDX_WR_DATA_VAL,
    TPP_IDX_WR_DATA_USER_DESP,

    TPP_IDX_NTF_VAL_CHAR,
    TPP_IDX_NTF_VAL,
    TPP_IDX_NTF_VAL_CFG,

    TPP_IDX_NB,
};

#endif
