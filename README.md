# riscv_emulator
A RISC-V emulator in C++ using WxWidgets

# Compiling

## WxWidgets
### Linux
Make sure to follow the guidelines in "https://wiki.wxwidgets.org/Installing_and_configuring_under_Ubuntu"
Which is to basically run:
```
sudo apt install libwxgtk3.0-dev
sudo ln -sv /usr/include/wx-3.0/wx /usr/include/wx
```
### Windows:
``¯\_(ツ)_/¯``

## Correct cmake usage
1. Clone the git repository, it will create a folder named "riscv_emulator"
2. Create a build folder next to it named "riscv_emulator-build" (``mkdir riscv_emulator-build``)
3. Go to the build folder ``cd riscv_emulator-build``
4. Run ``cmake ../riscv_emulator/``


