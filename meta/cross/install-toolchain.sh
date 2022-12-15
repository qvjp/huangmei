set -e

binutils_repo=https://github.com/qvjp/binutils-gdb.git
gcc_repo=https://github.com/qvjp/gcc.git

# Set some default values.
[ -z "${PREFIX+x}" ] && PREFIX="$HOME/huangmei-toolchain"
[ -z "$SRCDIR" ] && SRCDIR="$HOME/src"
[ -z "$BUILDDIR" ] && BUILDDIR="$SRCDIR"
[ -z "$ARCH" ] && ARCH=i686
[ -z "$TARGET" ] && TARGET=$ARCH-elf

export PATH="$PREFIX/bin:$PATH"

rm -rf "$SRCDIR/huangmei-binutils" "$SRCDIR/huangmei-gcc"
rm -rf "$BUILDDIR/build-binutils" "$BUILDDIR/build-gcc"

echo Downloading sources...
mkdir -p "$SRCDIR"
cd "$SRCDIR"
git clone --depth 1 $binutils_repo huangmei-binutils
git clone --depth 1 $gcc_repo huangmei-gcc

echo Building binutils...
mkdir -p "$BUILDDIR/build-binutils"
cd "$BUILDDIR/build-binutils"
"$SRCDIR/huangmei-binutils/configure" --target=$TARGET --prefix="$PREFIX" --with-sysroot \
        --disable-nls --disable-werror
make
make install

echo Building gcc...
mkdir -p "$BUILDDIR/build-gcc"
cd "$BUILDDIR/build-gcc"
"$SRCDIR/huangmei-gcc/configure" --target=$TARGET --prefix="$PREFIX" --disable-nls \
        --enable-languages=c,c++ --without-headers
make all-gcc all-target-libgcc
make install-gcc install-target-libgcc

echo Installation completed.
