## Demo OQS-Wireshark

This demo shows how to use [OQS-Wireshark](https://github.com/open-quantum-safe/oqs-demos/blob/main/wireshark/README.md).

> [!NOTE]
> This demo requires [Docker](https://www.docker.com/).

1. Allow Docker to access the display.

```bash
xhost +
export DISPLAY=:0
```

2. Run OQS-Wireshark with Docker.

```bash
docker run --rm -it --net=host -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix -v `pwd`:/root/captures openquantumsafe/wireshark
```

3. Open file `handshake_tls13_kyber1024.pcapng`.

4. Filter by `tls.handshake`.

5. Expand package `Client Hello`.

6. Search for `Extension: key_share`.

![Wireshark TLS 1.3 capture](./docs/images/capture-kyber1024.png)

7. Repeat with `handshake_tls13_x25519mlkem768.pcapng`.

![Wireshark hybrid TLS 1.3 capture](./docs/images/capture-x25519mlkem768.png)

## Demo 5 (`5-demo-tls13`)

This demo shows how to visualize if post-quantum TLS is used by browser.

1. Open Google Chrome (it also works with Firefox).

2. Go to https://pq.cloudflareresearch.com

3. Open DevTools.

4. Go to Security tab.

5. Look for `X25519MLKEM768`.

![pq.cloudflareresearch.com screenshot](./docs/images/pq-cloudflare-research.png)

6. Repeat with https://test.openquantumsafe.org:6056/

![https://test.openquantumsafe.org:6056/ screenshot](./docs/images/test-6056.png)

7. Repeat with https://test.openquantumsafe.org:6002.

![https://test.openquantumsafe.org:6002/ screenshot](./docs/images/test-6002.png)
