# xdrlcio
# Xdr serialization for lcio data format

## INSTALL:

Requires :
* [lcio](lcio.desy.de) (major version > 2).
* [xdrstream](https://github.com/rete/xdrstream).
* [Doxygen](www.doxygen.org) (optionnal) to build code documentation.  

The install procedure is managed by [CMake](http://cmake.org)

In the root directory :

```bash
mkdir build
cd build
cmake [ -DINSTALL_DOC=ON -DLCIO_DIR=... -Dxdrstream_DIR=... ] ..
make
```

### Bug report

You can send emails to <remi.ete@gmail.com>
or use the [github issues interface](https://github.Com/rete/xdrlcio/issues)
