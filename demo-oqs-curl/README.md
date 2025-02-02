# Demo OQS-Curl

This demo connects `curl` to [Open Quantum Safe test server](https://test.openquantumsafe.org).

> [!NOTE]
> This demo requires [Docker](https://www.docker.com/).

```bash
# ML-KEM-768
docker run -v `pwd`:/ca -it openquantumsafe/curl curl --cacert /ca/CA.crt --curves mlkem768 https://test.openquantumsafe.org:6020
```

<details>
<summary>View output (click to expand)</summary>

```html
<!DOCTYPE html>
<html>
<head>
<title>Open Quantum Safe interop test server for quantum-safe cryptography</title>
</head>
<body>
<h1 align=center>
Successfully connected using
ecdsap256-mlkem768!
</h1>

Client-side KEM algorithm(s) indicated:
mlkem768
</body>
</html>
```
</details>

```bash
# X25519-ML-KEM-768
docker run -v `pwd`:/ca -it openquantumsafe/curl curl --cacert /ca/CA.crt --curves X25519MLKEM768 https://test.openquantumsafe.org:6002
```

<details>
<summary>View output (click to expand)</summary>

```html
<!DOCTYPE html>
<html>
<head>
<title>Open Quantum Safe interop test server for quantum-safe cryptography</title>
</head>
<body>
<h1 align=center>
Successfully connected using
ecdsap256-X25519MLKEM768!
</h1>

Client-side KEM algorithm(s) indicated:
X25519MLKEM768
</body>
</html>
```
</details>

```bash
# SecP256r1-MLKEM-768
docker run -v `pwd`:/ca -it openquantumsafe/curl curl --cacert /ca/CA.crt --curves SecP256r1MLKEM768 https://test.openquantumsafe.org:6001
```

<details>
<summary>View output (click to expand)</summary>

```bash
<!DOCTYPE html>
<html>
<head>
<title>Open Quantum Safe interop test server for quantum-safe cryptography</title>
</head>
<body>
<h1 align=center>
Successfully connected using
ecdsap256-SecP256r1MLKEM768!
</h1>

Client-side KEM algorithm(s) indicated:
SecP256r1MLKEM768
</body>
</html>
```
</details>

```bash
# KEM
docker run -it openquantumsafe/curl openssl speed -seconds 2 mlkem512 X25519
```

<details>
<summary>View output (click to expand)</summary>

```bash
Doing X25519 keygen ops for 2s: 85292 X25519 KEM keygen ops in 3.63s
Doing X25519 encaps ops for 2s: 14214 X25519 KEM encaps ops in 2.00s
Doing X25519 decaps ops for 2s: 27242 X25519 KEM decaps ops in 2.00s
Doing mlkem512 keygen ops for 2s: 38469 mlkem512 KEM keygen ops in 1.99s
Doing mlkem512 encaps ops for 2s: 29718 mlkem512 KEM encaps ops in 1.95s
Doing mlkem512 decaps ops for 2s: 26682 mlkem512 KEM decaps ops in 2.00s
version: 3.4.0
built on: Fri Jan 24 06:12:02 2025 UTC
options: bn(64,64)
compiler: gcc -fPIC -pthread -m64 -Wa,--noexecstack -Wall -O3 -DOPENSSL_USE_NODELETE -DL_ENDIAN -DOPENSSL_PIC -DOPENSSL_BUILDING_OPENSSL -DNDEBUG
CPUINFO: OPENSSL_ia32cap=0xc2da2203478bffff:0x842509
                               keygen    encaps    decaps keygens/s  encaps/s  decaps/s
                     X25519 0.000043s 0.000141s 0.000073s   23496.4    7107.0   13621.0
                   mlkem512 0.000052s 0.000066s 0.000075s   19331.2   15240.0   13341.0
```
</details>

```bash
# Signature
docker run -it openquantumsafe/curl openssl speed -seconds 2 mldsa44 ed25519
```

<details>
<summary>View output (click to expand)</summary>

```bash
Doing 253 bits sign Ed25519 ops for 2s: 38442 253 bits Ed25519 sign ops in 2.00s 
Doing 253 bits verify Ed25519 ops for 2s: 14925 253 bits Ed25519 verify ops in 2.10s
Doing mldsa44 keygen ops for 2s: 11860 mldsa44 signature keygen ops in 1.87s
Doing mldsa44 signs ops for 2s: 2584 mldsa44 signature sign ops in 1.94s
Doing mldsa44 verify ops for 2s: 11537 mldsa44 signature verify ops in 2.00s
version: 3.4.0
built on: Fri Jan 24 06:12:02 2025 UTC
options: bn(64,64)
compiler: gcc -fPIC -pthread -m64 -Wa,--noexecstack -Wall -O3 -DOPENSSL_USE_NODELETE -DL_ENDIAN -DOPENSSL_PIC -DOPENSSL_BUILDING_OPENSSL -DNDEBUG
CPUINFO: OPENSSL_ia32cap=0xc2da2203478bffff:0x842509
                              sign    verify    sign/s verify/s
 253 bits EdDSA (Ed25519)   0.0001s   0.0001s  19221.0   7107.1
                               keygen     signs    verify keygens/s    sign/s  verify/s
                    mldsa44 0.000158s 0.000751s 0.000173s    6342.2    1332.0    5768.5

```
</details>

```bash
# All algorithms
docker run -it openquantumsafe/curl openssl speed -seconds 2
```

<details>
<summary>View output (click to expand)</summary>

```bash
Doing md5 ops for 2s on 16 size blocks: 4919193 md5 ops in 1.97s
Doing md5 ops for 2s on 64 size blocks: 4152708 md5 ops in 1.94s
Doing md5 ops for 2s on 256 size blocks: 2405900 md5 ops in 1.95s
Doing md5 ops for 2s on 1024 size blocks: 941174 md5 ops in 1.99s
Doing md5 ops for 2s on 8192 size blocks: 140139 md5 ops in 2.01s
Doing md5 ops for 2s on 16384 size blocks: 69508 md5 ops in 2.00s
Doing sha1 ops for 2s on 16 size blocks: 7135829 sha1 ops in 2.95s
Doing sha1 ops for 2s on 64 size blocks: 4063279 sha1 ops in 1.91s
Doing sha1 ops for 2s on 256 size blocks: 3859722 sha1 ops in 2.88s
Doing sha1 ops for 2s on 1024 size blocks: 1051380 sha1 ops in 1.94s
Doing sha1 ops for 2s on 8192 size blocks: 264627 sha1 ops in 2.91s
Doing sha1 ops for 2s on 16384 size blocks: 126784 sha1 ops in 2.93s
Doing sha256 ops for 2s on 16 size blocks: 6188527 sha256 ops in 2.92s
Doing sha256 ops for 2s on 64 size blocks: 4615534 sha256 ops in 2.91s
Doing sha256 ops for 2s on 256 size blocks: 1631658 sha256 ops in 2.02s
Doing sha256 ops for 2s on 1024 size blocks: 553927 sha256 ops in 2.00s
Doing sha256 ops for 2s on 8192 size blocks: 76437 sha256 ops in 2.00s
Doing sha256 ops for 2s on 16384 size blocks: 39776 sha256 ops in 2.00s
Doing sha512 ops for 2s on 16 size blocks: 2974113 sha512 ops in 2.00s
Doing sha512 ops for 2s on 64 size blocks: 2896517 sha512 ops in 2.00s
Doing sha512 ops for 2s on 256 size blocks: 1522813 sha512 ops in 2.00s
Doing sha512 ops for 2s on 1024 size blocks: 629400 sha512 ops in 2.00s
Doing sha512 ops for 2s on 8192 size blocks: 96248 sha512 ops in 2.00s
Doing sha512 ops for 2s on 16384 size blocks: 49117 sha512 ops in 2.00s
Doing rmd160 ops for 2s on 16 size blocks: 3345234 rmd160 ops in 2.01s
Doing rmd160 ops for 2s on 64 size blocks: 2245458 rmd160 ops in 2.00s
Doing rmd160 ops for 2s on 256 size blocks: 1151973 rmd160 ops in 2.00s
Doing rmd160 ops for 2s on 1024 size blocks: 384441 rmd160 ops in 2.01s
Doing rmd160 ops for 2s on 8192 size blocks: 55092 rmd160 ops in 2.00s
Doing rmd160 ops for 2s on 16384 size blocks: 28069 rmd160 ops in 2.00s
Doing hmac(sha256) ops for 2s on 16 size blocks: 2739593 hmac(sha256) ops in 2.00s
Doing hmac(sha256) ops for 2s on 64 size blocks: 2153632 hmac(sha256) ops in 2.00s
Doing hmac(sha256) ops for 2s on 256 size blocks: 1300655 hmac(sha256) ops in 2.00s
Doing hmac(sha256) ops for 2s on 1024 size blocks: 529642 hmac(sha256) ops in 2.01s
Doing hmac(sha256) ops for 2s on 8192 size blocks: 78636 hmac(sha256) ops in 2.00s
Doing hmac(sha256) ops for 2s on 16384 size blocks: 38892 hmac(sha256) ops in 2.00s
Doing des-ede3 ops for 2s on 16 size blocks: 2995189 des-ede3 ops in 2.01s
Doing des-ede3 ops for 2s on 64 size blocks: 1129602 des-ede3 ops in 2.91s
Doing des-ede3 ops for 2s on 256 size blocks: 306211 des-ede3 ops in 2.99s
Doing des-ede3 ops for 2s on 1024 size blocks: 75196 des-ede3 ops in 3.00s
Doing des-ede3 ops for 2s on 8192 size blocks: 5894 des-ede3 ops in 2.00s
Doing des-ede3 ops for 2s on 16384 size blocks: 4736 des-ede3 ops in 3.00s
Doing aes-128-cbc ops for 2s on 16 size blocks: 173999164 aes-128-cbc ops in 2.99s
Doing aes-128-cbc ops for 2s on 64 size blocks: 35026540 aes-128-cbc ops in 2.00s
Doing aes-128-cbc ops for 2s on 256 size blocks: 9227869 aes-128-cbc ops in 2.03s
Doing aes-128-cbc ops for 2s on 1024 size blocks: 3385944 aes-128-cbc ops in 2.97s
Doing aes-128-cbc ops for 2s on 8192 size blocks: 287570 aes-128-cbc ops in 2.00s
Doing aes-128-cbc ops for 2s on 16384 size blocks: 215015 aes-128-cbc ops in 3.00s
Doing aes-192-cbc ops for 2s on 16 size blocks: 106181891 aes-192-cbc ops in 2.00s
Doing aes-192-cbc ops for 2s on 64 size blocks: 45039697 aes-192-cbc ops in 3.00s
Doing aes-192-cbc ops for 2s on 256 size blocks: 7695521 aes-192-cbc ops in 2.00s
Doing aes-192-cbc ops for 2s on 1024 size blocks: 1916280 aes-192-cbc ops in 2.01s
Doing aes-192-cbc ops for 2s on 8192 size blocks: 356428 aes-192-cbc ops in 2.99s
Doing aes-192-cbc ops for 2s on 16384 size blocks: 175443 aes-192-cbc ops in 3.00s
Doing aes-256-cbc ops for 2s on 16 size blocks: 96266149 aes-256-cbc ops in 2.00s
Doing aes-256-cbc ops for 2s on 64 size blocks: 26114342 aes-256-cbc ops in 2.01s
Doing aes-256-cbc ops for 2s on 256 size blocks: 9925271 aes-256-cbc ops in 2.99s
Doing aes-256-cbc ops for 2s on 1024 size blocks: 2495030 aes-256-cbc ops in 3.00s
Doing aes-256-cbc ops for 2s on 8192 size blocks: 209346 aes-256-cbc ops in 2.00s
Doing aes-256-cbc ops for 2s on 16384 size blocks: 102233 aes-256-cbc ops in 2.00s
Doing camellia-128-cbc ops for 2s on 16 size blocks: 12791753 camellia-128-cbc ops in 2.01s
Doing camellia-128-cbc ops for 2s on 64 size blocks: 7196996 camellia-128-cbc ops in 2.99s
Doing camellia-128-cbc ops for 2s on 256 size blocks: 1387372 camellia-128-cbc ops in 2.00s
Doing camellia-128-cbc ops for 2s on 1024 size blocks: 364112 camellia-128-cbc ops in 1.99s
Doing camellia-128-cbc ops for 2s on 8192 size blocks: 67341 camellia-128-cbc ops in 2.96s
Doing camellia-128-cbc ops for 2s on 16384 size blocks: 22689 camellia-128-cbc ops in 1.99s
Doing camellia-192-cbc ops for 2s on 16 size blocks: 10233859 camellia-192-cbc ops in 1.99s
Doing camellia-192-cbc ops for 2s on 64 size blocks: 5594927 camellia-192-cbc ops in 2.98s
Doing camellia-192-cbc ops for 2s on 256 size blocks: 1034541 camellia-192-cbc ops in 1.99s
Doing camellia-192-cbc ops for 2s on 1024 size blocks: 260730 camellia-192-cbc ops in 2.02s
Doing camellia-192-cbc ops for 2s on 8192 size blocks: 31582 camellia-192-cbc ops in 2.00s
Doing camellia-192-cbc ops for 2s on 16384 size blocks: 15697 camellia-192-cbc ops in 2.00s
Doing camellia-256-cbc ops for 2s on 16 size blocks: 9902237 camellia-256-cbc ops in 2.01s
Doing camellia-256-cbc ops for 2s on 64 size blocks: 3459057 camellia-256-cbc ops in 2.00s
Doing camellia-256-cbc ops for 2s on 256 size blocks: 982561 camellia-256-cbc ops in 2.00s
Doing camellia-256-cbc ops for 2s on 1024 size blocks: 252538 camellia-256-cbc ops in 2.00s
Doing camellia-256-cbc ops for 2s on 8192 size blocks: 29145 camellia-256-cbc ops in 2.00s
Doing camellia-256-cbc ops for 2s on 16384 size blocks: 15253 camellia-256-cbc ops in 2.00s
Doing ghash ops for 2s on 16 size blocks: 91943998 ghash ops in 2.01s
Doing ghash ops for 2s on 64 size blocks: 65707685 ghash ops in 2.00s
Doing ghash ops for 2s on 256 size blocks: 21753367 ghash ops in 2.00s
Doing ghash ops for 2s on 1024 size blocks: 5310817 ghash ops in 2.01s
Doing ghash ops for 2s on 8192 size blocks: 750269 ghash ops in 2.00s
Doing ghash ops for 2s on 16384 size blocks: 384288 ghash ops in 2.00s
Doing rand ops for 2s on 16 size blocks: 1873140 rand ops in 1.41s
Doing rand ops for 2s on 64 size blocks: 1846752 rand ops in 1.22s
Doing rand ops for 2s on 256 size blocks: 1761870 rand ops in 1.23s
Doing rand ops for 2s on 1024 size blocks: 1442240 rand ops in 1.31s
Doing rand ops for 2s on 8192 size blocks: 521110 rand ops in 1.82s
Doing rand ops for 2s on 16384 size blocks: 316240 rand ops in 1.94s
Doing kmac128 ops for 2s on 16 size blocks: 1115766 kmac128 ops in 2.00s
Doing kmac128 ops for 2s on 64 size blocks: 1148035 kmac128 ops in 2.01s
Doing kmac128 ops for 2s on 256 size blocks: 901546 kmac128 ops in 2.00s
Doing kmac128 ops for 2s on 1024 size blocks: 451209 kmac128 ops in 2.00s
Doing kmac128 ops for 2s on 8192 size blocks: 86294 kmac128 ops in 2.00s
Doing kmac128 ops for 2s on 16384 size blocks: 44640 kmac128 ops in 2.00s
Doing kmac256 ops for 2s on 16 size blocks: 1103210 kmac256 ops in 2.01s
Doing kmac256 ops for 2s on 64 size blocks: 1164326 kmac256 ops in 2.00s
Doing kmac256 ops for 2s on 256 size blocks: 920865 kmac256 ops in 2.01s
Doing kmac256 ops for 2s on 1024 size blocks: 419240 kmac256 ops in 2.00s
Doing kmac256 ops for 2s on 8192 size blocks: 71145 kmac256 ops in 2.00s
Doing kmac256 ops for 2s on 16384 size blocks: 36017 kmac256 ops in 2.00s
Doing 512 bits private rsa sign ops for 2s: 40818 512 bits private RSA sign ops in 2.01s
Doing 512 bits public rsa verify ops for 2s: 551974 512 bits public RSA verify ops in 2.00s
Doing 512 bits public rsa encrypt ops for 2s: 407983 512 bits public RSA encrypt ops in 2.00s
Doing 512 bits private rsa decrypt ops for 2s: 31174 512 bits private RSA decrypt ops in 2.00s
Doing 1024 bits private rsa sign ops for 2s: 14001 1024 bits private RSA sign ops in 2.01s
Doing 1024 bits public rsa verify ops for 2s: 209661 1024 bits public RSA verify ops in 2.00s
Doing 1024 bits public rsa encrypt ops for 2s: 176065 1024 bits public RSA encrypt ops in 2.00s
Doing 1024 bits private rsa decrypt ops for 2s: 10161 1024 bits private RSA decrypt ops in 2.00s
Doing 2048 bits private rsa sign ops for 2s: 1320 2048 bits private RSA sign ops in 2.01s
Doing 2048 bits public rsa verify ops for 2s: 46087 2048 bits public RSA verify ops in 2.00s
Doing 2048 bits public rsa encrypt ops for 2s: 44645 2048 bits public RSA encrypt ops in 2.00s
Doing 2048 bits private rsa decrypt ops for 2s: 1236 2048 bits private RSA decrypt ops in 2.00s
Doing 3072 bits private rsa sign ops for 2s: 442 3072 bits private RSA sign ops in 2.00s
Doing 3072 bits public rsa verify ops for 2s: 27877 3072 bits public RSA verify ops in 2.01s
Doing 3072 bits public rsa encrypt ops for 2s: 28398 3072 bits public RSA encrypt ops in 2.00s
Doing 3072 bits private rsa decrypt ops for 2s: 585 3072 bits private RSA decrypt ops in 2.01s
Doing 4096 bits private rsa sign ops for 2s: 258 4096 bits private RSA sign ops in 2.00s
Doing 4096 bits public rsa verify ops for 2s: 17232 4096 bits public RSA verify ops in 2.00s
Doing 4096 bits public rsa encrypt ops for 2s: 16597 4096 bits public RSA encrypt ops in 2.00s
Doing 4096 bits private rsa decrypt ops for 2s: 264 4096 bits private RSA decrypt ops in 2.01s
Doing 7680 bits private rsa sign ops for 2s: 32 7680 bits private RSA sign ops in 2.04s
Doing 7680 bits public rsa verify ops for 2s: 5000 7680 bits public RSA verify ops in 2.00s
Doing 7680 bits public rsa encrypt ops for 2s: 4808 7680 bits public RSA encrypt ops in 2.00s
Doing 7680 bits private rsa decrypt ops for 2s: 28 7680 bits private RSA decrypt ops in 2.01s
Doing 15360 bits private rsa sign ops for 2s: 6 15360 bits private RSA sign ops in 2.30s
Doing 15360 bits public rsa verify ops for 2s: 1277 15360 bits public RSA verify ops in 2.01s
Doing 15360 bits public rsa encrypt ops for 2s: 1219 15360 bits public RSA encrypt ops in 2.00s
Doing 15360 bits private rsa decrypt ops for 2s: 6 15360 bits private RSA decrypt ops in 2.30s
Doing 1024 bits sign dsa ops for 2s: 12810 1024 bits DSA sign ops in 2.00s
Doing 1024 bits verify dsa ops for 2s: 15598 1024 bits DSA verify ops in 2.01s
Doing 2048 bits sign dsa ops for 2s: 4460 2048 bits DSA sign ops in 2.00s
Doing 2048 bits verify dsa ops for 2s: 4962 2048 bits DSA verify ops in 2.00s
Doing 160 bits sign ecdsa ops for 2s: 8326 160 bits ECDSA sign ops in 2.03s
Doing 160 bits verify ecdsa ops for 2s: 8491 160 bits ECDSA verify ops in 2.00s
Doing 192 bits sign ecdsa ops for 2s: 6956 192 bits ECDSA sign ops in 2.00s
Doing 192 bits verify ecdsa ops for 2s: 7224 192 bits ECDSA verify ops in 2.01s
Doing 224 bits sign ecdsa ops for 2s: 4570 224 bits ECDSA sign ops in 2.00s
Doing 224 bits verify ecdsa ops for 2s: 4911 224 bits ECDSA verify ops in 2.00s
Doing 256 bits sign ecdsa ops for 2s: 61421 256 bits ECDSA sign ops in 1.97s
Doing 256 bits verify ecdsa ops for 2s: 21731 256 bits ECDSA verify ops in 2.00s
Doing 384 bits sign ecdsa ops for 2s: 1826 384 bits ECDSA sign ops in 2.00s
Doing 384 bits verify ecdsa ops for 2s: 2202 384 bits ECDSA verify ops in 2.00s
Doing 521 bits sign ecdsa ops for 2s: 766 521 bits ECDSA sign ops in 2.01s
Doing 521 bits verify ecdsa ops for 2s: 979 521 bits ECDSA verify ops in 1.99s
Doing 163 bits sign ecdsa ops for 2s: 7347 163 bits ECDSA sign ops in 2.00s
Doing 163 bits verify ecdsa ops for 2s: 3323 163 bits ECDSA verify ops in 1.99s
Doing 233 bits sign ecdsa ops for 2s: 5033 233 bits ECDSA sign ops in 1.98s
Doing 233 bits verify ecdsa ops for 2s: 2751 233 bits ECDSA verify ops in 2.00s
Doing 283 bits sign ecdsa ops for 2s: 3212 283 bits ECDSA sign ops in 2.00s
Doing 283 bits verify ecdsa ops for 2s: 1610 283 bits ECDSA verify ops in 2.00s
Doing 409 bits sign ecdsa ops for 2s: 1653 409 bits ECDSA sign ops in 2.00s
Doing 409 bits verify ecdsa ops for 2s: 957 409 bits ECDSA verify ops in 2.01s
Doing 571 bits sign ecdsa ops for 2s: 854 571 bits ECDSA sign ops in 2.01s
Doing 571 bits verify ecdsa ops for 2s: 461 571 bits ECDSA verify ops in 2.01s
Doing 163 bits sign ecdsa ops for 2s: 7103 163 bits ECDSA sign ops in 2.00s
Doing 163 bits verify ecdsa ops for 2s: 3722 163 bits ECDSA verify ops in 1.99s
Doing 233 bits sign ecdsa ops for 2s: 5203 233 bits ECDSA sign ops in 2.00s
Doing 233 bits verify ecdsa ops for 2s: 2694 233 bits ECDSA verify ops in 1.99s
Doing 283 bits sign ecdsa ops for 2s: 3110 283 bits ECDSA sign ops in 2.00s
Doing 283 bits verify ecdsa ops for 2s: 1534 283 bits ECDSA verify ops in 1.96s
Doing 409 bits sign ecdsa ops for 2s: 1818 409 bits ECDSA sign ops in 2.00s
Doing 409 bits verify ecdsa ops for 2s: 947 409 bits ECDSA verify ops in 2.00s
Doing 571 bits sign ecdsa ops for 2s: 836 571 bits ECDSA sign ops in 2.01s
Doing 571 bits verify ecdsa ops for 2s: 430 571 bits ECDSA verify ops in 2.01s
Doing 256 bits sign ecdsa ops for 2s: 4295 256 bits ECDSA sign ops in 2.00s
Doing 256 bits verify ecdsa ops for 2s: 4132 256 bits ECDSA verify ops in 2.01s
Doing 256 bits sign ecdsa ops for 2s: 4093 256 bits ECDSA sign ops in 2.00s
Doing 256 bits verify ecdsa ops for 2s: 4553 256 bits ECDSA verify ops in 2.00s
Doing 384 bits sign ecdsa ops for 2s: 1909 384 bits ECDSA sign ops in 1.97s
Doing 384 bits verify ecdsa ops for 2s: 2073 384 bits ECDSA verify ops in 2.00s
Doing 384 bits sign ecdsa ops for 2s: 1818 384 bits ECDSA sign ops in 2.00s
Doing 384 bits verify ecdsa ops for 2s: 2170 384 bits ECDSA verify ops in 2.00s
Doing 512 bits sign ecdsa ops for 2s: 1058 512 bits ECDSA sign ops in 2.00s
Doing 512 bits verify ecdsa ops for 2s: 1258 512 bits ECDSA verify ops in 2.00s
Doing 512 bits sign ecdsa ops for 2s: 1068 512 bits ECDSA sign ops in 2.01s
Doing 512 bits verify ecdsa ops for 2s: 1288 512 bits ECDSA verify ops in 2.00s
Doing 160 bits  ecdh ops for 2s: 9020 160-bits ECDH ops in 2.01s
Doing 192 bits  ecdh ops for 2s: 7309 192-bits ECDH ops in 2.00s
Doing 224 bits  ecdh ops for 2s: 5054 224-bits ECDH ops in 2.00s
Doing 256 bits  ecdh ops for 2s: 29581 256-bits ECDH ops in 2.01s
Doing 384 bits  ecdh ops for 2s: 1796 384-bits ECDH ops in 2.00s
Doing 521 bits  ecdh ops for 2s: 763 521-bits ECDH ops in 2.00s
Doing 163 bits  ecdh ops for 2s: 8001 163-bits ECDH ops in 2.00s
Doing 233 bits  ecdh ops for 2s: 5763 233-bits ECDH ops in 2.01s
Doing 283 bits  ecdh ops for 2s: 3449 283-bits ECDH ops in 1.99s
Doing 409 bits  ecdh ops for 2s: 2079 409-bits ECDH ops in 2.00s
Doing 571 bits  ecdh ops for 2s: 966 571-bits ECDH ops in 2.00s
Doing 163 bits  ecdh ops for 2s: 7631 163-bits ECDH ops in 1.98s
Doing 233 bits  ecdh ops for 2s: 5642 233-bits ECDH ops in 1.99s
Doing 283 bits  ecdh ops for 2s: 3244 283-bits ECDH ops in 2.00s
Doing 409 bits  ecdh ops for 2s: 1963 409-bits ECDH ops in 2.00s
Doing 571 bits  ecdh ops for 2s: 887 571-bits ECDH ops in 1.99s
Doing 256 bits  ecdh ops for 2s: 4612 256-bits ECDH ops in 2.01s
Doing 256 bits  ecdh ops for 2s: 4642 256-bits ECDH ops in 2.00s
Doing 384 bits  ecdh ops for 2s: 1951 384-bits ECDH ops in 2.00s
Doing 384 bits  ecdh ops for 2s: 1927 384-bits ECDH ops in 2.01s
Doing 512 bits  ecdh ops for 2s: 1036 512-bits ECDH ops in 2.01s
Doing 512 bits  ecdh ops for 2s: 1097 512-bits ECDH ops in 2.00s
Doing 253 bits  ecdh ops for 2s: 39725 253-bits ECDH ops in 2.00s
Doing 448 bits  ecdh ops for 2s: 9842 448-bits ECDH ops in 2.00s
Doing 253 bits sign Ed25519 ops for 2s: 47134 253 bits Ed25519 sign ops in 2.00s 
Doing 253 bits verify Ed25519 ops for 2s: 14727 253 bits Ed25519 verify ops in 2.01s
Doing 456 bits sign Ed448 ops for 2s: 7565 456 bits Ed448 sign ops in 2.00s 
Doing 456 bits verify Ed448 ops for 2s: 8177 456 bits Ed448 verify ops in 2.00s
Doing 256 bits sign CurveSM2 ops for 2s: 4270 256 bits CurveSM2 sign ops in 2.01s 
Doing 256 bits verify CurveSM2 ops for 2s: 4602 256 bits CurveSM2 verify ops in 2.00s
Doing 2048 bits  ffdh ops for 2s: 3885 2048-bits FFDH ops in 2.00s
Doing 3072 bits  ffdh ops for 2s: 1484 3072-bits FFDH ops in 2.00s
Doing 4096 bits  ffdh ops for 2s: 726 4096-bits FFDH ops in 2.01s
Doing 6144 bits  ffdh ops for 2s: 325 6144-bits FFDH ops in 2.01s
Doing 8192 bits  ffdh ops for 2s: 153 8192-bits FFDH ops in 2.01s
Doing rsa512 keygen ops for 2s: 453 rsa512 KEM keygen ops in 2.01s
Doing rsa512 encaps ops for 2s: 340342 rsa512 KEM encaps ops in 1.86s
Doing rsa512 decaps ops for 2s: 40330 rsa512 KEM decaps ops in 2.01s
Doing rsa1024 keygen ops for 2s: 143 rsa1024 KEM keygen ops in 1.95s
Doing rsa1024 encaps ops for 2s: 170926 rsa1024 KEM encaps ops in 1.92s
Doing rsa1024 decaps ops for 2s: 14018 rsa1024 KEM decaps ops in 2.01s
Doing rsa2048 keygen ops for 2s: 26 rsa2048 KEM keygen ops in 2.07s
Doing rsa2048 encaps ops for 2s: 57647 rsa2048 KEM encaps ops in 1.97s
Doing rsa2048 decaps ops for 2s: 1941 rsa2048 KEM decaps ops in 2.00s
Doing rsa3072 keygen ops for 2s: 9 rsa3072 KEM keygen ops in 2.06s
Doing rsa3072 encaps ops for 2s: 28272 rsa3072 KEM encaps ops in 1.98s
Doing rsa3072 decaps ops for 2s: 619 rsa3072 KEM decaps ops in 2.00s
Doing rsa4096 keygen ops for 2s: 3 rsa4096 KEM keygen ops in 2.36s
Doing rsa4096 encaps ops for 2s: 16645 rsa4096 KEM encaps ops in 2.01s
Doing rsa4096 decaps ops for 2s: 263 rsa4096 KEM decaps ops in 2.00s
Doing rsa7680 keygen ops for 2s: 1 rsa7680 KEM keygen ops in 2.11s
Doing rsa7680 encaps ops for 2s: 4958 rsa7680 KEM encaps ops in 2.00s
Doing rsa7680 decaps ops for 2s: 32 rsa7680 KEM decaps ops in 2.02s
Doing rsa15360 keygen ops for 2s: 1 rsa15360 KEM keygen ops in 19.17s
Doing rsa15360 encaps ops for 2s: 2053 rsa15360 KEM encaps ops in 3.05s
Doing rsa15360 decaps ops for 2s: 9 rsa15360 KEM decaps ops in 3.11s
Doing ECP-256 keygen ops for 2s: 103744 ECP-256 KEM keygen ops in 2.00s
Doing ECP-256 encaps ops for 2s: 13172 ECP-256 KEM encaps ops in 2.00s
Doing ECP-256 decaps ops for 2s: 20250 ECP-256 KEM decaps ops in 2.00s
Doing ECP-384 keygen ops for 2s: 1888 ECP-384 KEM keygen ops in 2.00s
Doing ECP-384 encaps ops for 2s: 940 ECP-384 KEM encaps ops in 2.00s
Doing ECP-384 decaps ops for 2s: 1852 ECP-384 KEM decaps ops in 2.00s
Doing ECP-521 keygen ops for 2s: 787 ECP-521 KEM keygen ops in 2.01s
Doing ECP-521 encaps ops for 2s: 388 ECP-521 KEM encaps ops in 2.00s
Doing ECP-521 decaps ops for 2s: 797 ECP-521 KEM decaps ops in 2.00s
Doing X25519 keygen ops for 2s: 46105 X25519 KEM keygen ops in 2.01s
Doing X25519 encaps ops for 2s: 18495 X25519 KEM encaps ops in 2.00s
Doing X25519 decaps ops for 2s: 33940 X25519 KEM decaps ops in 2.00s
Doing X448 keygen ops for 2s: 7472 X448 KEM keygen ops in 2.00s
Doing X448 encaps ops for 2s: 4072 X448 KEM encaps ops in 2.01s
Doing X448 decaps ops for 2s: 9336 X448 KEM decaps ops in 2.00s
Doing frodo640aes keygen ops for 2s: 3633 frodo640aes KEM keygen ops in 2.00s
Doing frodo640aes encaps ops for 2s: 2242 frodo640aes KEM encaps ops in 2.00s
Doing frodo640aes decaps ops for 2s: 2340 frodo640aes KEM decaps ops in 2.01s
Doing p256_frodo640aes keygen ops for 2s: 1459 p256_frodo640aes KEM keygen ops in 2.00s
Doing p256_frodo640aes encaps ops for 2s: 2033 p256_frodo640aes KEM encaps ops in 2.00s
Doing p256_frodo640aes decaps ops for 2s: 1709 p256_frodo640aes KEM decaps ops in 2.00s
Doing x25519_frodo640aes keygen ops for 2s: 3301 x25519_frodo640aes KEM keygen ops in 2.00s
Doing x25519_frodo640aes encaps ops for 2s: 2054 x25519_frodo640aes KEM encaps ops in 1.99s
Doing x25519_frodo640aes decaps ops for 2s: 2123 x25519_frodo640aes KEM decaps ops in 2.00s
Doing frodo640shake keygen ops for 2s: 609 frodo640shake KEM keygen ops in 1.99s
Doing frodo640shake encaps ops for 2s: 567 frodo640shake KEM encaps ops in 2.01s
Doing frodo640shake decaps ops for 2s: 568 frodo640shake KEM decaps ops in 2.00s
Doing p256_frodo640shake keygen ops for 2s: 469 p256_frodo640shake KEM keygen ops in 2.01s
Doing p256_frodo640shake encaps ops for 2s: 542 p256_frodo640shake KEM encaps ops in 2.01s
Doing p256_frodo640shake decaps ops for 2s: 519 p256_frodo640shake KEM decaps ops in 2.00s
Doing x25519_frodo640shake keygen ops for 2s: 592 x25519_frodo640shake KEM keygen ops in 2.00s
Doing x25519_frodo640shake encaps ops for 2s: 547 x25519_frodo640shake KEM encaps ops in 2.00s
Doing x25519_frodo640shake decaps ops for 2s: 508 x25519_frodo640shake KEM decaps ops in 2.00s
Doing frodo976aes keygen ops for 2s: 1674 frodo976aes KEM keygen ops in 1.97s
Doing frodo976aes encaps ops for 2s: 1151 frodo976aes KEM encaps ops in 2.00s
Doing frodo976aes decaps ops for 2s: 1184 frodo976aes KEM decaps ops in 2.00s
Doing p384_frodo976aes keygen ops for 2s: 648 p384_frodo976aes KEM keygen ops in 1.97s
Doing p384_frodo976aes encaps ops for 2s: 516 p384_frodo976aes KEM encaps ops in 2.00s
Doing p384_frodo976aes decaps ops for 2s: 659 p384_frodo976aes KEM decaps ops in 1.98s
Doing x448_frodo976aes keygen ops for 2s: 1356 x448_frodo976aes KEM keygen ops in 1.93s
Doing x448_frodo976aes encaps ops for 2s: 910 x448_frodo976aes KEM encaps ops in 2.00s
Doing x448_frodo976aes decaps ops for 2s: 938 x448_frodo976aes KEM decaps ops in 2.00s
Doing frodo976shake keygen ops for 2s: 267 frodo976shake KEM keygen ops in 1.99s
Doing frodo976shake encaps ops for 2s: 257 frodo976shake KEM encaps ops in 2.00s
Doing frodo976shake decaps ops for 2s: 255 frodo976shake KEM decaps ops in 2.00s
Doing p384_frodo976shake keygen ops for 2s: 216 p384_frodo976shake KEM keygen ops in 2.00s
Doing p384_frodo976shake encaps ops for 2s: 202 p384_frodo976shake KEM encaps ops in 1.99s
Doing p384_frodo976shake decaps ops for 2s: 204 p384_frodo976shake KEM decaps ops in 2.01s
Doing x448_frodo976shake keygen ops for 2s: 256 x448_frodo976shake KEM keygen ops in 2.00s
Doing x448_frodo976shake encaps ops for 2s: 240 x448_frodo976shake KEM encaps ops in 2.01s
Doing x448_frodo976shake decaps ops for 2s: 241 x448_frodo976shake KEM decaps ops in 2.00s
Doing frodo1344aes keygen ops for 2s: 1010 frodo1344aes KEM keygen ops in 1.97s
Doing frodo1344aes encaps ops for 2s: 668 frodo1344aes KEM encaps ops in 2.01s
Doing frodo1344aes decaps ops for 2s: 680 frodo1344aes KEM decaps ops in 2.00s
Doing p521_frodo1344aes keygen ops for 2s: 369 p521_frodo1344aes KEM keygen ops in 2.00s
Doing p521_frodo1344aes encaps ops for 2s: 249 p521_frodo1344aes KEM encaps ops in 2.00s
Doing p521_frodo1344aes decaps ops for 2s: 350 p521_frodo1344aes KEM decaps ops in 2.01s
Doing frodo1344shake keygen ops for 2s: 177 frodo1344shake KEM keygen ops in 2.32s
Doing frodo1344shake encaps ops for 2s: 143 frodo1344shake KEM encaps ops in 1.97s
Doing frodo1344shake decaps ops for 2s: 147 frodo1344shake KEM decaps ops in 1.98s
Doing p521_frodo1344shake keygen ops for 2s: 121 p521_frodo1344shake KEM keygen ops in 2.01s
Doing p521_frodo1344shake encaps ops for 2s: 102 p521_frodo1344shake KEM encaps ops in 1.99s
Doing p521_frodo1344shake decaps ops for 2s: 112 p521_frodo1344shake KEM decaps ops in 2.00s
Doing kyber512 keygen ops for 2s: 39655 kyber512 KEM keygen ops in 1.92s
Doing kyber512 encaps ops for 2s: 35019 kyber512 KEM encaps ops in 1.96s
Doing kyber512 decaps ops for 2s: 30608 kyber512 KEM decaps ops in 2.00s
Doing p256_kyber512 keygen ops for 2s: 2242 p256_kyber512 KEM keygen ops in 1.92s
Doing p256_kyber512 encaps ops for 2s: 10144 p256_kyber512 KEM encaps ops in 1.79s
Doing p256_kyber512 decaps ops for 2s: 8080 p256_kyber512 KEM decaps ops in 2.86s
Doing x25519_kyber512 keygen ops for 2s: 21579 x25519_kyber512 KEM keygen ops in 1.95s
Doing x25519_kyber512 encaps ops for 2s: 12090 x25519_kyber512 KEM encaps ops in 1.94s
Doing x25519_kyber512 decaps ops for 2s: 11978 x25519_kyber512 KEM decaps ops in 1.99s
Doing kyber768 keygen ops for 2s: 24837 kyber768 KEM keygen ops in 1.95s
Doing kyber768 encaps ops for 2s: 34787 kyber768 KEM encaps ops in 2.91s
Doing kyber768 decaps ops for 2s: 21338 kyber768 KEM decaps ops in 1.97s
Doing p384_kyber768 keygen ops for 2s: 1053 p384_kyber768 KEM keygen ops in 1.98s
Doing p384_kyber768 encaps ops for 2s: 2360 p384_kyber768 KEM encaps ops in 5.00s
Doing p384_kyber768 decaps ops for 2s: 1442 p384_kyber768 KEM decaps ops in 2.04s
Doing x448_kyber768 keygen ops for 2s: 5578 x448_kyber768 KEM keygen ops in 1.91s
Doing x448_kyber768 encaps ops for 2s: 6881 x448_kyber768 KEM encaps ops in 3.75s
Doing x448_kyber768 decaps ops for 2s: 3732 x448_kyber768 KEM decaps ops in 2.06s
Doing x25519_kyber768 keygen ops for 2s: 15904 x25519_kyber768 KEM keygen ops in 1.96s
Doing x25519_kyber768 encaps ops for 2s: 10476 x25519_kyber768 KEM encaps ops in 1.94s
Doing x25519_kyber768 decaps ops for 2s: 9959 x25519_kyber768 KEM decaps ops in 1.98s
Doing p256_kyber768 keygen ops for 2s: 3148 p256_kyber768 KEM keygen ops in 2.83s
Doing p256_kyber768 encaps ops for 2s: 10373 p256_kyber768 KEM encaps ops in 1.98s
Doing p256_kyber768 decaps ops for 2s: 4753 p256_kyber768 KEM decaps ops in 1.93s
Doing kyber1024 keygen ops for 2s: 27034 kyber1024 KEM keygen ops in 2.92s
Doing kyber1024 encaps ops for 2s: 16836 kyber1024 KEM encaps ops in 1.98s
Doing kyber1024 decaps ops for 2s: 21717 kyber1024 KEM decaps ops in 2.98s
Doing p521_kyber1024 keygen ops for 2s: 941 p521_kyber1024 KEM keygen ops in 2.96s
Doing p521_kyber1024 encaps ops for 2s: 424 p521_kyber1024 KEM encaps ops in 1.98s
Doing p521_kyber1024 decaps ops for 2s: 707 p521_kyber1024 KEM decaps ops in 2.00s
Doing mlkem512 keygen ops for 2s: 43741 mlkem512 KEM keygen ops in 1.95s
Doing mlkem512 encaps ops for 2s: 39945 mlkem512 KEM encaps ops in 1.94s
Doing mlkem512 decaps ops for 2s: 31537 mlkem512 KEM decaps ops in 2.00s
Doing p256_mlkem512 keygen ops for 2s: 2268 p256_mlkem512 KEM keygen ops in 1.96s
Doing p256_mlkem512 encaps ops for 2s: 10761 p256_mlkem512 KEM encaps ops in 1.84s
Doing p256_mlkem512 decaps ops for 2s: 5388 p256_mlkem512 KEM decaps ops in 2.00s
Doing x25519_mlkem512 keygen ops for 2s: 21195 x25519_mlkem512 KEM keygen ops in 1.94s
Doing x25519_mlkem512 encaps ops for 2s: 13203 x25519_mlkem512 KEM encaps ops in 1.96s
Doing x25519_mlkem512 decaps ops for 2s: 12421 x25519_mlkem512 KEM decaps ops in 1.99s
Doing mlkem768 keygen ops for 2s: 27378 mlkem768 KEM keygen ops in 2.05s
Doing mlkem768 encaps ops for 2s: 23230 mlkem768 KEM encaps ops in 1.96s
Doing mlkem768 decaps ops for 2s: 19444 mlkem768 KEM decaps ops in 1.99s
Doing p384_mlkem768 keygen ops for 2s: 1031 p384_mlkem768 KEM keygen ops in 2.01s
Doing p384_mlkem768 encaps ops for 2s: 891 p384_mlkem768 KEM encaps ops in 2.00s
Doing p384_mlkem768 decaps ops for 2s: 1390 p384_mlkem768 KEM decaps ops in 2.01s
Doing x448_mlkem768 keygen ops for 2s: 5717 x448_mlkem768 KEM keygen ops in 1.99s
Doing x448_mlkem768 encaps ops for 2s: 3559 x448_mlkem768 KEM encaps ops in 1.98s
Doing x448_mlkem768 decaps ops for 2s: 3465 x448_mlkem768 KEM decaps ops in 2.00s
Doing X25519MLKEM768 keygen ops for 2s: 16204 X25519MLKEM768 KEM keygen ops in 1.93s
Doing X25519MLKEM768 encaps ops for 2s: 10589 X25519MLKEM768 KEM encaps ops in 1.96s
Doing X25519MLKEM768 decaps ops for 2s: 10147 X25519MLKEM768 KEM decaps ops in 2.00s
Doing SecP256r1MLKEM768 keygen ops for 2s: 2249 SecP256r1MLKEM768 KEM keygen ops in 1.99s
Doing SecP256r1MLKEM768 encaps ops for 2s: 9997 SecP256r1MLKEM768 KEM encaps ops in 1.98s
Doing SecP256r1MLKEM768 decaps ops for 2s: 4759 SecP256r1MLKEM768 KEM decaps ops in 2.00s
Doing mlkem1024 keygen ops for 2s: 16051 mlkem1024 KEM keygen ops in 1.96s
Doing mlkem1024 encaps ops for 2s: 15922 mlkem1024 KEM encaps ops in 1.96s
Doing mlkem1024 decaps ops for 2s: 13972 mlkem1024 KEM decaps ops in 2.01s
Doing p521_mlkem1024 keygen ops for 2s: 580 p521_mlkem1024 KEM keygen ops in 1.99s
Doing p521_mlkem1024 encaps ops for 2s: 402 p521_mlkem1024 KEM encaps ops in 2.01s
Doing p521_mlkem1024 decaps ops for 2s: 704 p521_mlkem1024 KEM decaps ops in 2.00s
Doing p384_mlkem1024 keygen ops for 2s: 1017 p384_mlkem1024 KEM keygen ops in 1.99s
Doing p384_mlkem1024 encaps ops for 2s: 892 p384_mlkem1024 KEM encaps ops in 2.01s
Doing p384_mlkem1024 decaps ops for 2s: 1370 p384_mlkem1024 KEM decaps ops in 1.99s
Doing bikel1 keygen ops for 2s: 4633 bikel1 KEM keygen ops in 1.99s
Doing bikel1 encaps ops for 2s: 17592 bikel1 KEM encaps ops in 2.14s
Doing bikel1 decaps ops for 2s: 1074 bikel1 KEM decaps ops in 2.53s
Doing p256_bikel1 keygen ops for 2s: 1771 p256_bikel1 KEM keygen ops in 1.98s
Doing p256_bikel1 encaps ops for 2s: 8576 p256_bikel1 KEM encaps ops in 1.99s
Doing p256_bikel1 decaps ops for 2s: 1112 p256_bikel1 KEM decaps ops in 2.95s
Doing x25519_bikel1 keygen ops for 2s: 6764 x25519_bikel1 KEM keygen ops in 2.96s
Doing x25519_bikel1 encaps ops for 2s: 8893 x25519_bikel1 KEM encaps ops in 1.97s
Doing x25519_bikel1 decaps ops for 2s: 768 x25519_bikel1 KEM decaps ops in 2.00s
Doing bikel3 keygen ops for 2s: 1537 bikel3 KEM keygen ops in 2.00s
Doing bikel3 encaps ops for 2s: 6116 bikel3 KEM encaps ops in 2.00s
Doing bikel3 decaps ops for 2s: 267 bikel3 KEM decaps ops in 2.00s
Doing p384_bikel3 keygen ops for 2s: 632 p384_bikel3 KEM keygen ops in 2.00s
Doing p384_bikel3 encaps ops for 2s: 812 p384_bikel3 KEM encaps ops in 1.99s
Doing p384_bikel3 decaps ops for 2s: 225 p384_bikel3 KEM decaps ops in 2.01s
Doing x448_bikel3 keygen ops for 2s: 1225 x448_bikel3 KEM keygen ops in 2.00s
Doing x448_bikel3 encaps ops for 2s: 2466 x448_bikel3 KEM encaps ops in 2.00s
Doing x448_bikel3 decaps ops for 2s: 239 x448_bikel3 KEM decaps ops in 2.01s
Doing bikel5 keygen ops for 2s: 601 bikel5 KEM keygen ops in 2.00s
Doing bikel5 encaps ops for 2s: 9214 bikel5 KEM encaps ops in 6.87s
Doing bikel5 decaps ops for 2s: 174 bikel5 KEM decaps ops in 2.92s
Doing p521_bikel5 keygen ops for 2s: 320 p521_bikel5 KEM keygen ops in 2.00s
Doing p521_bikel5 encaps ops for 2s: 350 p521_bikel5 KEM encaps ops in 1.99s
Doing p521_bikel5 decaps ops for 2s: 95 p521_bikel5 KEM decaps ops in 1.95s
Doing hqc128 keygen ops for 2s: 896 hqc128 KEM keygen ops in 2.00s
Doing hqc128 encaps ops for 2s: 450 hqc128 KEM encaps ops in 2.00s
Doing hqc128 decaps ops for 2s: 280 hqc128 KEM decaps ops in 2.01s
Doing p256_hqc128 keygen ops for 2s: 651 p256_hqc128 KEM keygen ops in 2.00s
Doing p256_hqc128 encaps ops for 2s: 431 p256_hqc128 KEM encaps ops in 2.00s
Doing p256_hqc128 decaps ops for 2s: 260 p256_hqc128 KEM decaps ops in 1.99s
Doing x25519_hqc128 keygen ops for 2s: 790 x25519_hqc128 KEM keygen ops in 2.00s
Doing x25519_hqc128 encaps ops for 2s: 417 x25519_hqc128 KEM encaps ops in 2.01s
Doing x25519_hqc128 decaps ops for 2s: 269 x25519_hqc128 KEM decaps ops in 2.00s
Doing hqc192 keygen ops for 2s: 287 hqc192 KEM keygen ops in 2.00s
Doing hqc192 encaps ops for 2s: 146 hqc192 KEM encaps ops in 2.01s
Doing hqc192 decaps ops for 2s: 96 hqc192 KEM decaps ops in 2.02s
Doing p384_hqc192 keygen ops for 2s: 229 p384_hqc192 KEM keygen ops in 2.01s
Doing p384_hqc192 encaps ops for 2s: 127 p384_hqc192 KEM encaps ops in 2.01s
Doing p384_hqc192 decaps ops for 2s: 90 p384_hqc192 KEM decaps ops in 2.02s
Doing x448_hqc192 keygen ops for 2s: 286 x448_hqc192 KEM keygen ops in 1.99s
Doing x448_hqc192 encaps ops for 2s: 143 x448_hqc192 KEM encaps ops in 2.01s
Doing x448_hqc192 decaps ops for 2s: 94 x448_hqc192 KEM decaps ops in 2.01s
Doing hqc256 keygen ops for 2s: 156 hqc256 KEM keygen ops in 2.00s
Doing hqc256 encaps ops for 2s: 81 hqc256 KEM encaps ops in 2.02s
Doing hqc256 decaps ops for 2s: 51 hqc256 KEM decaps ops in 2.00s
Doing p521_hqc256 keygen ops for 2s: 120 p521_hqc256 KEM keygen ops in 2.00s
Doing p521_hqc256 encaps ops for 2s: 66 p521_hqc256 KEM encaps ops in 2.02s
Doing p521_hqc256 decaps ops for 2s: 49 p521_hqc256 KEM decaps ops in 2.03s
Doing rsa512 keygen ops for 2s: 484 rsa512 signature keygen ops in 1.92s
Doing rsa512 signs ops for 2s: 41600 rsa512 signature sign ops in 1.99s
Doing rsa512 verify ops for 2s: 555706 rsa512 signature verify ops in 2.01s
Doing rsa1024 keygen ops for 2s: 149 rsa1024 signature keygen ops in 1.98s
Doing rsa1024 signs ops for 2s: 13611 rsa1024 signature sign ops in 2.00s
Doing rsa1024 verify ops for 2s: 199806 rsa1024 signature verify ops in 2.00s
Doing rsa2048 keygen ops for 2s: 22 rsa2048 signature keygen ops in 2.04s
Doing rsa2048 signs ops for 2s: 1950 rsa2048 signature sign ops in 2.00s
Doing rsa2048 verify ops for 2s: 64804 rsa2048 signature verify ops in 2.00s
Doing rsa3072 keygen ops for 2s: 9 rsa3072 signature keygen ops in 2.20s
Doing rsa3072 signs ops for 2s: 628 rsa3072 signature sign ops in 2.00s
Doing rsa3072 verify ops for 2s: 30428 rsa3072 signature verify ops in 2.00s
Doing rsa4096 keygen ops for 2s: 3 rsa4096 signature keygen ops in 2.41s
Doing rsa4096 signs ops for 2s: 268 rsa4096 signature sign ops in 2.01s
Doing rsa4096 verify ops for 2s: 17217 rsa4096 signature verify ops in 2.00s
Doing rsa7680 keygen ops for 2s: 1 rsa7680 signature keygen ops in 13.21s
Doing rsa7680 signs ops for 2s: 32 rsa7680 signature sign ops in 2.05s
Doing rsa7680 verify ops for 2s: 5073 rsa7680 signature verify ops in 2.00s
Doing rsa15360 keygen ops for 2s: 1 rsa15360 signature keygen ops in 13.17s
Doing rsa15360 signs ops for 2s: 6 rsa15360 signature sign ops in 2.24s
Doing rsa15360 verify ops for 2s: 1259 rsa15360 signature verify ops in 2.00s
Doing dsa1024 keygen ops for 2s: 7092 dsa1024 signature keygen ops in 2.01s
Doing dsa1024 signs ops for 2s: 9681 dsa1024 signature sign ops in 2.00s
Doing dsa1024 verify ops for 2s: 15150 dsa1024 signature verify ops in 2.00s
Doing dsa2048 keygen ops for 2s: 1959 dsa2048 signature keygen ops in 2.00s
Doing dsa2048 signs ops for 2s: 3250 dsa2048 signature sign ops in 2.00s
Doing dsa2048 verify ops for 2s: 4483 dsa2048 signature verify ops in 2.01s
Error initializing keygen ctx for DSA-SHA1.
286B721FD37F0000:error:0308010C:digital envelope routines:inner_evp_generic_fetch:unsupported:crypto/evp/evp_fetch.c:355:Global default library context, Algorithm (DSA-SHA1 : 109), Properties (<null>)
version: 3.4.0
built on: Fri Jan 24 06:12:02 2025 UTC
options: bn(64,64)
compiler: gcc -fPIC -pthread -m64 -Wa,--noexecstack -Wall -O3 -DOPENSSL_USE_NODELETE -DL_ENDIAN -DOPENSSL_PIC -DOPENSSL_BUILDING_OPENSSL -DNDEBUG
CPUINFO: OPENSSL_ia32cap=0xc2da2203478bffff:0x842509
The 'numbers' are in 1000s of bytes per second processed.
type             16 bytes     64 bytes    256 bytes   1024 bytes   8192 bytes  16384 bytes
md5              39952.84k   136996.55k   315851.49k   484302.60k   571153.58k   569409.54k
sha1             38702.80k   136151.76k   343086.40k   554955.22k   744956.83k   708951.90k
rmd160           26628.73k    71854.66k   147452.54k   195854.52k   225656.83k   229941.25k
sha256           33909.74k   101510.03k   206784.38k   283610.62k   313085.95k   325844.99k
sha512           23792.90k    92688.54k   194920.06k   322252.80k   394231.81k   402366.46k
hmac(sha256)     21916.74k    68916.22k   166483.84k   269827.57k   322093.06k   318603.26k
des-ede3         23842.30k    24843.48k    26217.40k    25666.90k    24141.82k    25864.87k
aes-128-cbc     931099.21k  1120849.28k  1163711.56k  1167409.65k  1177886.72k  1174268.59k
aes-192-cbc     849455.13k   960846.87k   985026.69k   976254.09k   976541.20k   958152.70k
aes-256-cbc     770129.19k   831501.44k   849789.09k   851636.91k   857481.22k   837492.74k
camellia-128-cbc   101824.90k   154049.41k   177583.62k   187362.15k   186370.77k   186802.30k
camellia-192-cbc    82282.28k   120159.51k   133086.68k   132172.04k   129359.87k   128589.82k
camellia-256-cbc    78823.78k   110689.82k   125767.81k   129299.46k   119377.92k   124952.58k
ghash           731892.52k  2102645.92k  2784430.98k  2705610.25k  3073101.82k  3148087.30k
rand             21255.49k    96878.79k   366698.15k  1127369.28k  2345567.65k  2670760.91k
kmac128           8926.13k    36554.35k   115397.89k   231019.01k   353460.22k   365690.88k
kmac256           8781.77k    37258.43k   117284.30k   214650.88k   291409.92k   295051.26k
                   sign    verify    encrypt   decrypt   sign/s verify/s  encr./s  decr./s
rsa   512 bits 0.000049s 0.000004s 0.000005s 0.000064s  20307.5 275987.0 203991.5  15587.0
rsa  1024 bits 0.000144s 0.000010s 0.000011s 0.000197s   6965.7 104830.5  88032.5   5080.5
rsa  2048 bits 0.001523s 0.000043s 0.000045s 0.001618s    656.7  23043.5  22322.5    618.0
rsa  3072 bits 0.004525s 0.000072s 0.000070s 0.003436s    221.0  13869.2  14199.0    291.0
rsa  4096 bits 0.007752s 0.000116s 0.000121s 0.007614s    129.0   8616.0   8298.5    131.3
rsa  7680 bits 0.063750s 0.000400s 0.000416s 0.071786s     15.7   2500.0   2404.0     13.9
rsa 15360 bits 0.383333s 0.001574s 0.001641s 0.383333s      2.6    635.3    609.5      2.6
                  sign    verify    sign/s verify/s
dsa 1024 bits 0.000156s 0.000129s   6405.0   7760.2
dsa 2048 bits 0.000448s 0.000403s   2230.0   2481.0
                              sign    verify    sign/s verify/s
 160 bits ecdsa (secp160r1)   0.0002s   0.0002s   4101.5   4245.5
 192 bits ecdsa (nistp192)   0.0003s   0.0003s   3478.0   3594.0
 224 bits ecdsa (nistp224)   0.0004s   0.0004s   2285.0   2455.5
 256 bits ecdsa (nistp256)   0.0000s   0.0001s  31178.2  10865.5
 384 bits ecdsa (nistp384)   0.0011s   0.0009s    913.0   1101.0
 521 bits ecdsa (nistp521)   0.0026s   0.0020s    381.1    492.0
 163 bits ecdsa (nistk163)   0.0003s   0.0006s   3673.5   1669.8
 233 bits ecdsa (nistk233)   0.0004s   0.0007s   2541.9   1375.5
 283 bits ecdsa (nistk283)   0.0006s   0.0012s   1606.0    805.0
 409 bits ecdsa (nistk409)   0.0012s   0.0021s    826.5    476.1
 571 bits ecdsa (nistk571)   0.0024s   0.0044s    424.9    229.4
 163 bits ecdsa (nistb163)   0.0003s   0.0005s   3551.5   1870.4
 233 bits ecdsa (nistb233)   0.0004s   0.0007s   2601.5   1353.8
 283 bits ecdsa (nistb283)   0.0006s   0.0013s   1555.0    782.7
 409 bits ecdsa (nistb409)   0.0011s   0.0021s    909.0    473.5
 571 bits ecdsa (nistb571)   0.0024s   0.0047s    415.9    213.9
 256 bits ecdsa (brainpoolP256r1)   0.0005s   0.0005s   2147.5   2055.7
 256 bits ecdsa (brainpoolP256t1)   0.0005s   0.0004s   2046.5   2276.5
 384 bits ecdsa (brainpoolP384r1)   0.0010s   0.0010s    969.0   1036.5
 384 bits ecdsa (brainpoolP384t1)   0.0011s   0.0009s    909.0   1085.0
 512 bits ecdsa (brainpoolP512r1)   0.0019s   0.0016s    529.0    629.0
 512 bits ecdsa (brainpoolP512t1)   0.0019s   0.0016s    531.3    644.0
                              op      op/s
 160 bits ecdh (secp160r1)   0.0002s   4487.6
 192 bits ecdh (nistp192)   0.0003s   3654.5
 224 bits ecdh (nistp224)   0.0004s   2527.0
 256 bits ecdh (nistp256)   0.0001s  14716.9
 384 bits ecdh (nistp384)   0.0011s    898.0
 521 bits ecdh (nistp521)   0.0026s    381.5
 163 bits ecdh (nistk163)   0.0002s   4000.5
 233 bits ecdh (nistk233)   0.0003s   2867.2
 283 bits ecdh (nistk283)   0.0006s   1733.2
 409 bits ecdh (nistk409)   0.0010s   1039.5
 571 bits ecdh (nistk571)   0.0021s    483.0
 163 bits ecdh (nistb163)   0.0003s   3854.0
 233 bits ecdh (nistb233)   0.0004s   2835.2
 283 bits ecdh (nistb283)   0.0006s   1622.0
 409 bits ecdh (nistb409)   0.0010s    981.5
 571 bits ecdh (nistb571)   0.0022s    445.7
 256 bits ecdh (brainpoolP256r1)   0.0004s   2294.5
 256 bits ecdh (brainpoolP256t1)   0.0004s   2321.0
 384 bits ecdh (brainpoolP384r1)   0.0010s    975.5
 384 bits ecdh (brainpoolP384t1)   0.0010s    958.7
 512 bits ecdh (brainpoolP512r1)   0.0019s    515.4
 512 bits ecdh (brainpoolP512t1)   0.0018s    548.5
 253 bits ecdh (X25519)   0.0001s  19862.5
 448 bits ecdh (X448)   0.0002s   4921.0
                              sign    verify    sign/s verify/s
 253 bits EdDSA (Ed25519)   0.0000s   0.0001s  23567.0   7326.9
 456 bits EdDSA (Ed448)   0.0003s   0.0002s   3782.5   4088.5
                              sign    verify    sign/s verify/s
 256 bits SM2 (CurveSM2)   0.0005s   0.0004s   2124.4   2301.0
                       op     op/s
2048 bits ffdh   0.0005s   1942.5
3072 bits ffdh   0.0013s    742.0
4096 bits ffdh   0.0028s    361.2
6144 bits ffdh   0.0062s    161.7
8192 bits ffdh   0.0131s     76.1
                               keygen    encaps    decaps keygens/s  encaps/s  decaps/s
                     rsa512 0.004437s 0.000005s 0.000050s     225.4  182979.6   20064.7
                    rsa1024 0.013636s 0.000011s 0.000143s      73.3   89024.0    6974.1
                    rsa2048 0.079615s 0.000034s 0.001030s      12.6   29262.4     970.5
                    rsa3072 0.228889s 0.000070s 0.003231s       4.4   14278.8     309.5
                    rsa4096 0.786667s 0.000121s 0.007605s       1.3    8281.1     131.5
                    rsa7680 2.110000s 0.000403s 0.063125s       0.5    2479.0      15.8
                   rsa15360 19.170000s 0.001486s 0.345556s       0.1     673.1       2.9
                    ECP-256 0.000019s 0.000152s 0.000099s   51872.0    6586.0   10125.0
                    ECP-384 0.001059s 0.002128s 0.001080s     944.0     470.0     926.0
                    ECP-521 0.002554s 0.005155s 0.002509s     391.5     194.0     398.5
                     X25519 0.000044s 0.000108s 0.000059s   22937.8    9247.5   16970.0
                       X448 0.000268s 0.000494s 0.000214s    3736.0    2025.9    4668.0
                frodo640aes 0.000551s 0.000892s 0.000859s    1816.5    1121.0    1164.2
           p256_frodo640aes 0.001371s 0.000984s 0.001170s     729.5    1016.5     854.5
         x25519_frodo640aes 0.000606s 0.000969s 0.000942s    1650.5    1032.2    1061.5
              frodo640shake 0.003268s 0.003545s 0.003521s     306.0     282.1     284.0
         p256_frodo640shake 0.004286s 0.003708s 0.003854s     233.3     269.7     259.5
       x25519_frodo640shake 0.003378s 0.003656s 0.003937s     296.0     273.5     254.0
                frodo976aes 0.001177s 0.001738s 0.001689s     849.7     575.5     592.0
           p384_frodo976aes 0.003040s 0.003876s 0.003005s     328.9     258.0     332.8
           x448_frodo976aes 0.001423s 0.002198s 0.002132s     702.6     455.0     469.0
              frodo976shake 0.007453s 0.007782s 0.007843s     134.2     128.5     127.5
         p384_frodo976shake 0.009259s 0.009851s 0.009853s     108.0     101.5     101.5
         x448_frodo976shake 0.007812s 0.008375s 0.008299s     128.0     119.4     120.5
               frodo1344aes 0.001950s 0.003009s 0.002941s     512.7     332.3     340.0
          p521_frodo1344aes 0.005420s 0.008032s 0.005743s     184.5     124.5     174.1
             frodo1344shake 0.013107s 0.013776s 0.013469s      76.3      72.6      74.2
        p521_frodo1344shake 0.016612s 0.019510s 0.017857s      60.2      51.3      56.0
                   kyber512 0.000048s 0.000056s 0.000065s   20653.6   17866.8   15304.0
              p256_kyber512 0.000856s 0.000176s 0.000354s    1167.7    5667.0    2825.2
            x25519_kyber512 0.000090s 0.000160s 0.000166s   11066.2    6232.0    6019.1
                   kyber768 0.000079s 0.000084s 0.000092s   12736.9   11954.3   10831.5
              p384_kyber768 0.001880s 0.002119s 0.001415s     531.8     472.0     706.9
              x448_kyber768 0.000342s 0.000545s 0.000552s    2920.4    1834.9    1811.7
            x25519_kyber768 0.000123s 0.000185s 0.000199s    8114.3    5400.0    5029.8
              p256_kyber768 0.000899s 0.000191s 0.000406s    1112.4    5238.9    2462.7
                  kyber1024 0.000108s 0.000118s 0.000137s    9258.2    8503.0    7287.6
             p521_kyber1024 0.003146s 0.004670s 0.002829s     317.9     214.1     353.5
                   mlkem512 0.000045s 0.000049s 0.000063s   22431.3   20590.2   15768.5
              p256_mlkem512 0.000864s 0.000171s 0.000371s    1157.1    5848.4    2694.0
            x25519_mlkem512 0.000092s 0.000148s 0.000160s   10925.3    6736.2    6241.7
                   mlkem768 0.000075s 0.000084s 0.000102s   13355.1   11852.0    9770.9
              p384_mlkem768 0.001950s 0.002245s 0.001446s     512.9     445.5     691.5
              x448_mlkem768 0.000348s 0.000556s 0.000577s    2872.9    1797.5    1732.5
             X25519MLKEM768 0.000119s 0.000185s 0.000197s    8395.9    5402.6    5073.5
          SecP256r1MLKEM768 0.000885s 0.000198s 0.000420s    1130.2    5049.0    2379.5
                  mlkem1024 0.000122s 0.000123s 0.000144s    8189.3    8123.5    6951.2
             p521_mlkem1024 0.003431s 0.005000s 0.002841s     291.5     200.0     352.0
             p384_mlkem1024 0.001957s 0.002253s 0.001453s     511.1     443.8     688.4
                     bikel1 0.000430s 0.000122s 0.002356s    2328.1    8220.6     424.5
                p256_bikel1 0.001118s 0.000232s 0.002653s     894.4    4309.5     376.9
              x25519_bikel1 0.000438s 0.000222s 0.002604s    2285.1    4514.2     384.0
                     bikel3 0.001301s 0.000327s 0.007491s     768.5    3058.0     133.5
                p384_bikel3 0.003165s 0.002451s 0.008933s     316.0     408.0     111.9
                x448_bikel3 0.001633s 0.000811s 0.008410s     612.5    1233.0     118.9
                     bikel5 0.003328s 0.000746s 0.016782s     300.5    1341.2      59.6
                p521_bikel5 0.006250s 0.005686s 0.020526s     160.0     175.9      48.7
                     hqc128 0.002232s 0.004444s 0.007179s     448.0     225.0     139.3
                p256_hqc128 0.003072s 0.004640s 0.007654s     325.5     215.5     130.7
              x25519_hqc128 0.002532s 0.004820s 0.007435s     395.0     207.5     134.5
                     hqc192 0.006969s 0.013767s 0.021042s     143.5      72.6      47.5
                p384_hqc192 0.008777s 0.015827s 0.022444s     113.9      63.2      44.6
                x448_hqc192 0.006958s 0.014056s 0.021383s     143.7      71.1      46.8
                     hqc256 0.012821s 0.024938s 0.039216s      78.0      40.1      25.5
                p521_hqc256 0.016667s 0.030606s 0.041429s      60.0      32.7      24.1
                               keygen     signs    verify keygens/s    sign/s  verify/s
                     rsa512 0.003967s 0.000048s 0.000004s     252.1   20904.5  276470.6
                    rsa1024 0.013289s 0.000147s 0.000010s      75.3    6805.5   99903.0
                    rsa2048 0.092727s 0.001026s 0.000031s      10.8     975.0   32402.0
                    rsa3072 0.244444s 0.003185s 0.000066s       4.1     314.0   15214.0
                    rsa4096 0.803333s 0.007500s 0.000116s       1.2     133.3    8608.5
                    rsa7680 13.210000s 0.064062s 0.000394s       0.1      15.6    2536.5
                   rsa15360 13.170000s 0.373333s 0.001589s       0.1       2.7     629.5
                    dsa1024 0.000283s 0.000207s 0.000132s    3528.4    4840.5    7575.0
                    dsa2048 0.001021s 0.000615s 0.000448s     979.5    1625.0    2230.3
```
</details>
