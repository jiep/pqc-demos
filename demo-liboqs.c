/* 
Compile with
gcc -Iliboqs/build/include -Lliboqs/build/lib demo-liboqs.c -o demo-liboqs -loqs -lcrypto

Algorithms names: 
  - KEM: https://github.com/open-quantum-safe/liboqs/blob/main/src/kem/kem.h
  - Sig: https://github.com/open-quantum-safe/liboqs/blob/main/src/sig/sig.h
*/

#include <stdio.h>
#include <string.h>
#include <oqs/oqs.h>
#include <openssl/evp.h>

#define MAX 16

void sha3_256(uint8_t *output, const uint8_t *input, size_t input_len) {
    EVP_MD_CTX *mdctx = NULL;

    if ((mdctx = EVP_MD_CTX_new()) == NULL) {
        fprintf(stderr, "Error creating hash context\n");
        return;
    }

    if (EVP_DigestInit_ex(mdctx, EVP_sha3_256(), NULL) != 1) {
        fprintf(stderr, "Error initializing SHA3-256 context\n");
        EVP_MD_CTX_free(mdctx);
        return;
    }

    if (EVP_DigestUpdate(mdctx, input, input_len) != 1) {
        fprintf(stderr, "Error updating hash\n");
        EVP_MD_CTX_free(mdctx);
        return;
    }

    unsigned int output_len;
    if (EVP_DigestFinal_ex(mdctx, output, &output_len) != 1) {
        fprintf(stderr, "Error finalizing hash\n");
        EVP_MD_CTX_free(mdctx);
        return;
    }

    EVP_MD_CTX_free(mdctx);
}


void print_hex(const uint8_t *bytes, size_t length) {
  for(size_t i = 0; i < length; i++){
    printf("%02x", bytes[i]);
  }
  printf("\n");
}

void print_hex_short(const uint8_t *bytes, size_t length) {
  for(size_t i = 0; i < MAX; i++){
    printf("%02x", bytes[i]);
  }
  printf("...");
  for(size_t i = length - MAX; i < length; i++){
    printf("%02x", bytes[i]);
  }
  printf("\n");
}

void concat_keys(const uint8_t *key1, const uint8_t *key2, const uint8_t *key3,
                 size_t length, uint8_t *out) {
  memcpy(out, key1, length);
  memcpy(out + length, key2, length);
  memcpy(out + 2*length, key3, length);
}

int main(void) {

  OQS_KEM *kem = OQS_KEM_new(OQS_KEM_alg_ml_kem_1024);
  printf("[--] Selected KEM: ML-KEM-1024\n");

  // Static keys for P1
  uint8_t *pk1 = malloc(kem->length_public_key);
  uint8_t *sk1 = malloc(kem->length_secret_key);
  OQS_KEM_keypair(kem, pk1, sk1);

  printf("\n[P1] Generating static keys...\n");
  printf("[P1] pk1 (%ld bytes): ", kem->length_public_key);
  print_hex_short(pk1, kem->length_public_key);
  printf("[P1] sk1 (%ld bytes): ", kem->length_secret_key);
  print_hex_short(sk1, kem->length_secret_key);

  // Static keys for P2
  uint8_t *pk2 = malloc(kem->length_public_key);
  uint8_t *sk2 = malloc(kem->length_secret_key);
  OQS_KEM_keypair(kem, pk2, sk2);

  printf("\n[P2] Generating static keys...\n");
  printf("[P2] pk2 (%ld bytes): ", kem->length_public_key);
  print_hex_short(pk2, kem->length_public_key);
  printf("[P2] sk2 (%ld bytes): ", kem->length_secret_key);
  print_hex_short(sk2, kem->length_secret_key);

  // -----------------------------------------------

  uint8_t *pk = malloc(kem->length_public_key);
  uint8_t *sk = malloc(kem->length_secret_key);
  OQS_KEM_keypair(kem, pk, sk);

  printf("\n[P1] Generating ephemeral pk and sk...\n");
  printf("[P1] pk (%ld bytes): ", kem->length_public_key);
  print_hex_short(pk, kem->length_public_key);
  printf("[P1] sk (%ld bytes): ", kem->length_secret_key);
  print_hex_short(sk, kem->length_secret_key);

  uint8_t *c2 = malloc(kem->length_ciphertext);
  uint8_t *k2 = malloc(kem->length_shared_secret);
  OQS_KEM_encaps(kem, c2, k2, pk2);

  printf("[P1] Generating encapsulation...\n");
  printf("[P1] c2 (%ld bytes): ", kem->length_ciphertext);
  print_hex_short(c2, kem->length_ciphertext);
  printf("[P1] k2 (%ld bytes): ", kem->length_shared_secret);
  print_hex(k2, kem->length_shared_secret);
  printf("[P1] Sending pk and c2 to P2...\n");

  // P1 sends pk and c2 to P2

  uint8_t *c = malloc(kem->length_ciphertext);
  uint8_t *k = malloc(kem->length_shared_secret);
  OQS_KEM_encaps(kem, c, k, pk);

  printf("\n[P2] Generating encapsulation...\n");
  printf("[P2] c (%ld bytes): ", kem->length_ciphertext);
  print_hex_short(c, kem->length_ciphertext);
  printf("[P2] k (%ld bytes): ", kem->length_shared_secret);
  print_hex(k, kem->length_shared_secret);

  uint8_t *c1 = malloc(kem->length_ciphertext);
  uint8_t *k1 = malloc(kem->length_shared_secret);
  OQS_KEM_encaps(kem, c1, k1, pk1);

  printf("[P2] Generating encapsulation...\n");
  printf("[P2] c1 (%ld bytes): ", kem->length_ciphertext);
  print_hex_short(c1, kem->length_ciphertext);
  printf("[P2] k1 (%ld bytes): ", kem->length_shared_secret);
  print_hex(k1, kem->length_shared_secret);

  uint8_t *k2_prime = malloc(kem->length_shared_secret);
  OQS_KEM_decaps(kem, k2_prime, c2, sk2);

  printf("[P2] Generating decapsulation...\n");
  printf("[P2] k2_prime (%ld bytes): ", kem->length_shared_secret);
  print_hex(k2_prime, kem->length_shared_secret);
  printf("[P2] Sending c and c1 to P1...\n");

  // P2 sends c and c1 to P1

  uint8_t *k_prime = malloc(kem->length_shared_secret);
  OQS_KEM_decaps(kem, k_prime, c, sk);

  printf("\n[P1] Generating decapsulation...\n");
  printf("[P1] k_prime (%ld bytes): ", kem->length_shared_secret);
  print_hex(k_prime, kem->length_shared_secret);

  uint8_t *k1_prime = malloc(kem->length_shared_secret);
  OQS_KEM_decaps(kem, k1_prime, c1, sk1);

  printf("[P1] Generating decapsulation...\n");
  printf("[P1] k1_prime (%ld bytes): ", kem->length_shared_secret);
  print_hex(k1_prime, kem->length_shared_secret);

  // P1 generates a secret key from k_prime, k1_prime, and k2
  uint8_t *concat_keys1 = malloc(3*kem->length_shared_secret);
  uint8_t *key1 = malloc(kem->length_shared_secret);
  concat_keys(k_prime, k1_prime, k2, kem->length_shared_secret, concat_keys1);
  sha3_256(key1, concat_keys1, 3*kem->length_shared_secret);

  // P2 generates a secret key from k, k1, and k2_prime
  uint8_t *concat_keys2 = malloc(3*kem->length_shared_secret);
  uint8_t *key2 = malloc(kem->length_shared_secret);
  concat_keys(k, k1, k2_prime, kem->length_shared_secret, concat_keys2);
  sha3_256(key2, concat_keys2, 3*kem->length_shared_secret);

  printf("\n[P1] shared key: ");
  print_hex(key1, kem->length_shared_secret);

  printf("[P2] shared key: ");
  print_hex(key2, kem->length_shared_secret);

  if(memcmp(key1, key2, kem->length_shared_secret) != 0){
    printf("[--] Key exchange error!\n");
    return OQS_ERROR;
  }

  printf("[--] Key exchange successful!\n");

  //  Secret variables are zeroized and freed
  OQS_MEM_secure_free(sk1, kem->length_secret_key);
  OQS_MEM_secure_free(sk2, kem->length_secret_key);
  OQS_MEM_secure_free(sk, kem->length_secret_key);
  OQS_MEM_secure_free(k2, kem->length_shared_secret);
  OQS_MEM_secure_free(k, kem->length_shared_secret);
  OQS_MEM_secure_free(k1, kem->length_shared_secret);
  OQS_MEM_secure_free(k2_prime, kem->length_shared_secret);
  OQS_MEM_secure_free(k_prime, kem->length_shared_secret);
  OQS_MEM_secure_free(k1_prime, kem->length_shared_secret);
  OQS_MEM_secure_free(concat_keys1, 3*kem->length_shared_secret);
  OQS_MEM_secure_free(key1, kem->length_shared_secret);
  OQS_MEM_secure_free(concat_keys2, 3*kem->length_shared_secret);
  OQS_MEM_secure_free(key2, kem->length_shared_secret);

  // Public variables are freed 
  OQS_MEM_insecure_free(pk1);
  OQS_MEM_insecure_free(pk2);
  OQS_MEM_insecure_free(pk);
  OQS_MEM_insecure_free(c2);
  OQS_MEM_insecure_free(c);
  OQS_MEM_insecure_free(c1);
  OQS_KEM_free(kem);

  return OQS_SUCCESS;
}

