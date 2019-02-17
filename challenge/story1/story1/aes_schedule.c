/*
 *
 * Chinese Academy of Sciences
 * State Key Laboratory of Information Security
 * Institute of Information Engineering
 *
 * Copyright (C) 2016 Chinese Academy of Sciences
 *
 * LuoPeng, luopeng@iie.ac.cn
 * Updated in Oct 2016
 * Updated in Jan 2017, update muliple function on GF(2^8).
 *
 */
#include "Common.h"
/*
 * round constants
 */
uint8_t RC[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
void aes_key_schedule_128( uint8_t *key, uint8_t *roundkeys) {

    uint8_t temp[4];
    uint8_t *last4bytes; // point to the last 4 bytes of one round
    uint8_t *lastround;
    uint8_t i,j=0;

    for (i = 0; i < 16; ++i) {
        *roundkeys++ = *key++;
    }

    last4bytes = roundkeys-4;
    for (i = 0; i < AES_ROUNDS; ++i) {
        // k0-k3 for next round
        temp[3] = SBOX[*last4bytes++];
        temp[0] = SBOX[*last4bytes++];
        temp[1] = SBOX[*last4bytes++];
        temp[2] = SBOX[*last4bytes++];
        temp[0] ^= RC[i];
        lastround = roundkeys-16;
		while(j<4)
		{*roundkeys++ = temp[j] ^ *lastround++;
			j++;
		}
		j=0;
      while(j<12)
	  {
		  *roundkeys++ = *last4bytes++ ^ *lastround++;
		  j++;
	  }      

    }
}
