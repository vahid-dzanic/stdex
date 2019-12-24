# stdex
stdex is an extension of the c++-standard library, especially the type traits for standard containers.

stdex type-traits defines a compile-time template-based interface,
to query properties of container-types like std::vector or std::array ...

## installation
### prerequisites
cmake, c++17 capable compiler

### build and install on linux
```bash
git clone https://github.com/vahid-dzanic/stdex.git
mkdir -p stdex/build
cd stdex/build
cmake .. -DCMAKE_BUILD_TYPE=Release -DSTDEX_BUILD_WITH_TESTS=OFF
sudo make install
```

## License
[LGPLv3](https://choosealicense.com/licenses/lgpl-3.0/)
