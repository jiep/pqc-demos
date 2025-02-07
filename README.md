# PQC Demos

## How to clone this repo

```
git clone --recurse-submodules https://github.com/jiep/pqc-demos.git
```

## Requirements

* C compiler like `gcc`.
* Python 3 and virtual environment.
* Docker.
* An updated browser like Google Chrome or Firefox.

## Demos

### LibOQS

This demo implements the following key-exchange protocol with [`liboqs`](https://github.com/open-quantum-safe/liboqs).

See [demo-liboqs-c](./demo-liboqs-c/) for more details.

### LibOQS-Python

This demo implements the following hybrid signature scheme with [`liboqs-python`](https://github.com/open-quantum-safe/liboqs).

See [demo-liboqs-python](./demo-liboqs-python/) for more details.

### OQS-Curl

This demo connects `oqs-curl` to [Open Quantum Safe test server](https://test.openquantumsafe.org).

See [demo-oqs-curl](./demo-oqs-curl/) for more details.

### OQS-Wireshark

This demo shows how to use [OQS-Wireshark](https://github.com/open-quantum-safe/oqs-demos/blob/main/wireshark/README.md).

See [demo-oqs-wireshark](./demo-oqs-wireshark/) for more details.

### Demo TLS 1.3

This demo shows how to visualize if post-quantum TLS is used by browser.

See [demo-tls13](./demo-tls13/) for more details.

### Demo Stateful Hash-Based Signatures with Botan

This demo shows how private key changes its state after each signature generation.

See [demo-shbs](./demo-shbs/) for more details.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
