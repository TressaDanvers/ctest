rm ./installer.zip
mkdir ./installer

# CTest Installer
cp ./build/ctest ./installer/
echo sudo cp ./ctest /bin/> ./installer/install\ ctest.sh

# CAssert Installer
cp ./source/assertions.h ./installer/
cp ./build/libassert.so ./installer/
echo sudo cp ./assertions.h /usr/include > ./installer/install\ cassert.sh
echo sudo cp ./libassert.so /usr/lib >> ./installer/install\ cassert.sh
echo sudo /sbin/ldconfig >> ./installer/install\ cassert.sh

# Zip
zip -r ./installer.zip ./installer
rm -fr ./installer
