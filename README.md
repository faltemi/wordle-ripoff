This is my attempt at a Wordle ripoff written in C with raylib.

**Dependencies**
Raylib
X11
Ninja
CMake

**Linux Build**
# 1) Install a compiler + cmake + ninja
sudo apt update
sudo apt install -y build-essential cmake ninja-build pkg-config

# 2) Install X11
sudo apt install -y libx11-dev libxi-dev libxrandr-dev libxinerama-dev \
  libxcursor-dev libgl1-mesa-dev libasound2-dev libpulse-dev


# 2) Configure & build
cmake -S . -B build -G Ninja
cmake --build build

**Windows Build**
TBD
