Demo 1

gcc -Iliboqs/build/include -Lliboqs/build/lib demo-liboqs.c -o demo-liboqs -loqs -lcrypto
------------------

Demo 2

docker run -v `pwd`:/ca -it openquantumsafe/curl curl --cacert /ca/CA.crt --curves kyber512 https://test.openquantumsafe.org:6014
-----------------

Demo 3

chrome://flags
#enable-tls13-kyber
https://pq.cloudflareresearch.com
https://test.openquantumsafe.org:6041
https://test.openquantumsafe.org:6084/
----------------
