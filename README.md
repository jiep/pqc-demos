# PQC Demos

## Demo 1

1. Compile `liboqs`.

```bashshell
cd liboqs && mkdir -p build && cd build
cmake -GNinja .. -DOQS_USE_SHA3_OPENSSL=ON
ninja
cd ../..
```

2. Compile `demo-liboqs.c`.

```bashshell
gcc -Iliboqs/build/include -Lliboqs/build/lib demo-liboqs.c -o demo-liboqs -loqs -lcrypto -pthread
```

## Demo 2

```bashshell
docker run -v `pwd`:/ca -it openquantumsafe/curl curl --cacert /ca/CA.crt --curves kyber512 https://test.openquantumsafe.org:6014
```

## Demo 3

```bashshell
chrome://flags
#enable-tls13-kyber
https://pq.cloudflareresearch.com
https://test.openquantumsafe.org:6041
https://test.openquantumsafe.org:6084/
```
