/*
 * Common.h
 *
 * Created: 2/6/2019 5:44:10 PM
 *  Author: AVE-LAP-039
 */ 


#ifndef COMMON_H_
#define COMMON_H_


#include <stdint.h>
extern uint8_t SBOX[256];
#define AES_BLOCK_SIZE      16
#define AES_ROUNDS          10  // 12, 14
#define AES_ROUND_KEY_SIZE  176
extern uint8_t mul2(uint8_t a);

void aes_decrypt_128( uint8_t *roundkeys, uint8_t *ciphertext, uint8_t *plaintext);
extern void aes_key_schedule_128(uint8_t *key, uint8_t *roundkeys);
void aes_encrypt_128(uint8_t *roundkeys, uint8_t *plaintext, uint8_t *ciphertext);


#endif /* COMMON_H_ */