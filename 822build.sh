#!/bin/bash -vex

export MAKEFLAGS="-j`nproc`"

if [ ! -f .config ] || ! cmp -s .config config.822; then
  echo "Copying config.822 to .config"
  cp config.822 .config
  make oldconfig
fi

make bzImage
make modules
make modules_install
make install
./kexec-reboot
