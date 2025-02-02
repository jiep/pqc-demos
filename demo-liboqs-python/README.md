# Demo LibOQS-Python

This demo implements the following hybrid signature scheme with [`liboqs-python`](https://github.com/open-quantum-safe/liboqs-python).

## How to build

1. Compile `liboqs` (requires shared library).

```bash
make liboqs
```

2. Install and activate virtualenv for Python and set the `LD_LIBRARY_PATH` environment variable to point to the path to `liboqs` library directory.

```bash
make venv
```

3. Install `liboqs-python`.

```bash
make liboqs_python
```

4. Check if `liboqs-python` works properly.

```bash
make check
```

<details>
<summary>View output (click to expand)</summary>

```
liboqs version: 0.12.0
liboqs-python version: 0.12.0
Enabled signature mechanisms:
['Dilithium2', 'Dilithium3', 'Dilithium5', 'ML-DSA-44', 'ML-DSA-65',
 'ML-DSA-87', 'Falcon-512', 'Falcon-1024', 'Falcon-padded-512',
 'Falcon-padded-1024', 'SPHINCS+-SHA2-128f-simple', 'SPHINCS+-SHA2-128s-simple',
 'SPHINCS+-SHA2-192f-simple', 'SPHINCS+-SHA2-192s-simple',
 'SPHINCS+-SHA2-256f-simple', 'SPHINCS+-SHA2-256s-simple',
 'SPHINCS+-SHAKE-128f-simple', 'SPHINCS+-SHAKE-128s-simple',
 'SPHINCS+-SHAKE-192f-simple', 'SPHINCS+-SHAKE-192s-simple',
 'SPHINCS+-SHAKE-256f-simple', 'SPHINCS+-SHAKE-256s-simple', 'MAYO-1', 'MAYO-2',
 'MAYO-3', 'MAYO-5', 'cross-rsdp-128-balanced', 'cross-rsdp-128-fast',
 'cross-rsdp-128-small', 'cross-rsdp-192-balanced', 'cross-rsdp-192-fast',
 'cross-rsdp-192-small', 'cross-rsdp-256-balanced', 'cross-rsdp-256-fast',
 'cross-rsdp-256-small', 'cross-rsdpg-128-balanced', 'cross-rsdpg-128-fast',
 'cross-rsdpg-128-small', 'cross-rsdpg-192-balanced', 'cross-rsdpg-192-fast',
 'cross-rsdpg-192-small', 'cross-rsdpg-256-balanced', 'cross-rsdpg-256-fast',
 'cross-rsdpg-256-small']

Signature details:
{'claimed_nist_level': 2,
 'is_euf_cma': True,
 'length_public_key': 1312,
 'length_secret_key': 2560,
 'length_signature': 2420,
 'name': 'ML-DSA-44',
 'sig_with_ctx_support': True,
 'version': 'FIPS204'}

Valid signature? True
```
</details>

5. Install `requirements.txt`.

```bash
make install_requirements
```

6. Run Python script with hybrid signature scheme.

```bash
make run_hybrid_signature
```

<details>
<summary>View output (click to expand)</summary>

```bash
[KEYGEN] Generating keypairs...
[KEYGEN] Generating keyapir for ML-DSA-87...
[KEYGEN] pkPQC (2592 bytes): 583940f87c3271b7bb722dde0eb9d6e2...795c025b1ccbd7d61ad4f8d15f3f0ebb
[KEYGEN] skPQC (4896 bytes): 583940f87c3271b7bb722dde0eb9d6e2...385e0bd69dfcf1dced67bd1a44bf1184
[KEYGEN] Generating keyapir for Ed448...
[KEYGEN] pkT (57 bytes): e84546ddaf7cc8b1afa5468962e831ecdeea3c34c0413bd32e64aadbdac74b412dc251b5477c0a542f58a2f04cfa0f984be40e974b7c6d0c00
[KEYGEN] skT (57 bytes): dc45bdd038c758807a5af769852b750666c27eabf4c95020d0fa29679c8f60f710d2d0cdbd8ef7e24d1bd547fb4c99b05359ff5a2e4afdca58

[SIGN] Signing message "An important message to sign" with both signature schemes...
[SIGN] Signing message "An important message to sign" with ML-DSA-87...
[SIGN] sigPQC (4627 bytes): 4ddc7dde7d44545446d715f69fa669a1...0000000000000000020c12171c23292f
[SIGN] Signing message "An important message to sign" with Ed448...
[SIGN] sigT (114 bytes): f9be244ffb3a7360693f02d2fc28cade...ab73515355f9ceb47796b519b26b0c00
[SIGN] Hybrid signature is sigPQC || sigT

[VERIFY] Verifying signatures...
[VERIFY] The hybrid signature is valid
[VERIFY] if and only if both signatures are valid
[VERIFY] Verifying signature with ML-DSA-87...
[VERIFY] Is signature valid for ML-DSA-87?: True
[VERIFY] Verifying signature with Ed448...
[VERIFY] Is signature valid for Ed448?: True
[VERIFY] Hybrid signature is valid iff both
[VERIFY] signatures are valid
[VERIFY] Is hybrid signature valid?: True
```
</details>