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
   ```

2. Open the `.ino` file in the Arduino IDE with Teensyduino enabled.

3. Flash the code to your Teensy 3.2.

4. Plug the Teensy into the locked MacBook and power it on.

5. The Teensy will begin simulating EFI password inputs using PIN-style sequences.

> 🕒 Brute-force speed and feasibility vary by device and firmware version.

---

## 📁 Repo Structure

```
efi-bruteforce/
├── efi_bruteforce.ino       # Main Arduino/Teensy script
├── README.md
└── docs/
    └── wiring_diagram.png   # [Optional] Add your own visual guides here
```

---

## ⚠️ Legal & Ethical Notice

This tool is intended for:
- Security research
- Digital forensics
- Personal device recovery

**Unauthorized use is a violation of law.**  
Only deploy against hardware you own or are explicitly authorized to access.

---

## 🧭 DevSecOps Perspective

While not a traditional software security project, this repo demonstrates:

- Hardware-based attack automation
- Brute-force detection testing methodology
- Cross-domain awareness (firmware, USB HID, and physical security)

For modern DevSecOps engineers, low-level tooling insight supports broader incident response and security architecture awareness.

---

## 🔄 Roadmap (Optional)

- [ ] Add delay tuning to bypass boot timers
- [ ] Modularize input sequence logic
- [ ] Include rotary encoder / display feedback
- [ ] Document MacBook compatibility matrix

---

## 📜 License

This project is released under the [MIT License](LICENSE).

---

## 📸 Demo (Optional)

> Coming soon: a short clip of the Teensy cycling through PINs on a locked MacBook Air.

### 📚 Background

This project was inspired by a real-world recovery scenario involving a locked MacBook Pro. The original research detailed the motivation, hardware decisions, and methodology behind this automation.

It documents:
- Why Teensy was chosen over Arduino
- How firmware behavior influenced delay tuning
- Ethical motivations for use on personally owned hardware

This script emerged from that exploratory work and was refined through open source contributions and testing.



### 📰 Recognition

This project was featured on Hackaday in 2013 for its exploration of EFI PIN brute-force mechanics on locked Apple hardware. While the original goal was personal data recovery, the write-up sparked discussion in the hardware and security research community.
