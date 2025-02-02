# Demo LibOQS

This demo implements the following key-exchange protocol with [`liboqs`](https://github.com/open-quantum-safe/liboqs).

![Key exchange protocol](./docs/images/key-exchange-protocol.PNG)

## How to build

1. Compile `liboqs`.

```bash
make liboqs
```

2. Compile `demo-liboqs.c`.

```bash
make demo
```

3. Run `demo-liboqs`.

```bash
make run
```
<details>
<summary>View example (click to expand)</summary>

```
[--] Selected KEM: ML-KEM-1024

[P1] Generating static keys...
[P1] pk1 (1568 bytes): 4d70765d4b3802288c46a49b2f6047c0...8a6c9a892d07efa9ab87b07a7544f1ca
[P1] sk1 (3168 bytes): 5189acae586bcd47a9dc46891cd2894b...07b9ac2186b4bb38656de633f44fd68b

[P2] Generating static keys...
[P2] pk2 (1568 bytes): ea50173c43587736b4b760aa4c0bcbdc...f2231573959382913e77bfcedbf73729
[P2] sk2 (3168 bytes): 3d0ac831a76aaec24594773fc3b6828c...b0167d388aeed9ca4bb9835f850c2e25

[P1] Generating ephemeral pk and sk...
[P1] pk (1568 bytes): 13da9dd0b96aaafab6e4020fc141578e...6a774c6fbe46dba891a783ff00a4e50d
[P1] sk (3168 bytes): 32a4488f51869e6258802871aa388757...3488dd6d84b242e22b6c34f88583d131
[P1] Generating encapsulation...
[P1] c2 (1568 bytes): 7c7b667fb9145a692dd6cf44d54a0e8d...a1911153190a9e4d20ca89f0adc6f51b
[P1] k2 (32 bytes): 512b9d7d264d8f69da5f40d9766c50f81b07ed9a6ff890c34baa459c60e082eb
[P1] Sending pk and c2 to P2...

[P2] Generating encapsulation...
[P2] c (1568 bytes): ae384d6317bb175a09c025f1cd8514cb...0830133c20cd4bc8ef2b2fb73c668c30
[P2] k (32 bytes): f50f307c99f7aa119b601105882ea285b4da50aec6823ca4f863d63843694cc6
[P2] Generating encapsulation...
[P2] c1 (1568 bytes): 390e2d8fe16e5240a7f89e28a6395d28...555e6716f186d67514a9fcc471158d9d
[P2] k1 (32 bytes): 317fe0cec8bcd21ec2dc04f40b841a53bbcd58a91c9d48892b89df0eca750cb3
[P2] Generating decapsulation...
[P2] k2_prime (32 bytes): 512b9d7d264d8f69da5f40d9766c50f81b07ed9a6ff890c34baa459c60e082eb
[P2] Sending c and c1 to P1...

[P1] Generating decapsulation...
[P1] k_prime (32 bytes): f50f307c99f7aa119b601105882ea285b4da50aec6823ca4f863d63843694cc6
[P1] Generating decapsulation...
[P1] k1_prime (32 bytes): 317fe0cec8bcd21ec2dc04f40b841a53bbcd58a91c9d48892b89df0eca750cb3

[P1] shared key: ceafc8c0b82344e1fc203ab956862fc090e56e178b1b987dab4213fa3d0d9eab
[P2] shared key: ceafc8c0b82344e1fc203ab956862fc090e56e178b1b987dab4213fa3d0d9eab
[--] Key exchange successful!
```    
</details>