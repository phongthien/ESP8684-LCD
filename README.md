# ESP8684-MINI-1 + BTG-12864 LCD

This project demonstrates how to use an ESP8684-MINI-1 (ESP32-C2) to drive a 128×64 SPI LCD (BTG-12864PG-FBWB) using the U8g2 library.

## Hardware

| LCD Pin | ESP8684 GPIO |
| ------- | ------------ |
| CS      | GPIO10       |
| RST     | GPIO5        |
| SCK     | GPIO6        |
| MOSI    | GPIO7        |
| BL      | GPIO4        |
| VCC     | 3.3V         |
| GND     | GND          |

## Features

* ESP8684-MINI-1 (ESP32-C2)
* BTG-12864PG-FBWB LCD
* U8g2 graphics library
* GitHub Actions automatic build
* Arduino CLI build environment
* Firmware artifacts (.bin)

## Repository Structure

```text
.github/
└── workflows/
    └── build.yml

ESP8684-ArduinoCLI.ino
README.md
```

## Build on GitHub

1. Upload the project to GitHub.
2. Open the **Actions** tab.
3. Run the **Build ESP8684** workflow.
4. Wait for the workflow to complete.
5. Download the firmware from **Artifacts**.

## Output Files

The build generates firmware files, including:

* firmware.bin
* bootloader.bin
* partitions.bin

## Requirements

* Arduino CLI
* ESP32 Arduino Core
* U8g2 Library

## License

MIT License
