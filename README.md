# 🧬 efi-bruteforce

Automated brute-force tool for EFI firmware passwords on legacy MacBook models.  
Powered by a Teensy microcontroller emulating USB keyboard input.

---

## ⚙️ Overview

Some MacBook models (primarily pre-2018) allow unlimited EFI password attempts at boot time. This project uses a programmable HID device (Teensy) to simulate a human entering PIN guesses, automating the process in hardware.

---

## 🔩 Requirements

- 🧠 **Basic hardware hacking familiarity**
- 🧱 **Teensy 3.2** or compatible microcontroller (e.g., Teensy LC)
- 🔌 **Micro USB cable**
- 💻 Target MacBook with EFI password lock (pre-T2 chip, e.g., 2012–2017)
- 🧰 [Teensyduino](https://www.pjrc.com/teensy/teensyduino.html) installed and configured

---

## 🚀 Setup

1. Clone this repo:
   ```bash
   git clone https://github.com/rivassec/efi-bruteforce
   cd efi-bruteforce
