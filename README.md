# 🧬 efi-bruteforce

Automated brute-force tool for EFI firmware passwords on legacy MacBook models.
Powered by a Teensy microcontroller emulating USB keyboard input.

> **2026 update** — This project shipped in February 2013. Apple eliminated
> the underlying hardware weakness with the T2 chip in 2018 and again with
> Apple Silicon in 2020. The technique here does not work against any
> MacBook from 2018 or later, by design. The repo stays up as a teaching
> artifact and for legitimate forensic / device-recovery work on hardware
> you own that predates the T2.
>
> For the full backstory — the Hackaday post that called it
> "unsuccessful," the rate-limit edges that made it work hours later, and
> the lessons that still apply to cloud-security work — see
> [The Teensy That Failed in Public](https://rivassec.com/teensy-efi-bruteforce-hours-late.html).

---

## ⚙️ Overview

Some MacBook models (primarily pre-2018) allow many EFI password attempts at
boot time before silent rate-limiting kicks in. This project uses a
programmable HID device (Teensy) to simulate a human entering PIN guesses,
automating the process in hardware.

The sketch handles three failure modes the firmware uses against fast input:

1. **USB poll-rate dropping** — the firmware drops keystrokes sent faster
   than its polling interval. Fixed via `delay()` calls between
   `Keyboard.press()` and `Keyboard.release()`.
2. **Per-attempt rate-limiting** — the firmware throttles after each
   submission. Fixed via a longer delay after Enter.
3. **After-N silent ignore** — after a threshold of consecutive incorrect
   attempts, the firmware stops processing input until a power cycle. Fixed
   by power-cycling between batches and persisting the current PIN index
   across reboots.

---

## 🔩 Requirements

- Basic hardware-hacking familiarity
- **Teensy 3.2** or compatible microcontroller (e.g., Teensy LC, Pro Micro
  with Keyboard library — see community ports below)
- Micro USB cable
- Target MacBook with EFI password lock (pre-T2, e.g., 2012-2017)
- [Teensyduino](https://www.pjrc.com/teensy/teensyduino.html) installed and
  configured

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

5. The Teensy will begin simulating EFI password inputs using PIN-style
   sequences.

> Brute-force speed and feasibility vary by device and firmware version.

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
- Personal device recovery on hardware you own

**Unauthorized use is a violation of law.** Only deploy against hardware
you own or are explicitly authorized to access.

---

## 🌐 Background & community

The original 2013 writeup (now via Wayback Machine since `orvtech.com`
lapsed):

- [Atacar EFI PIN MacBook Pro (Spanish)](http://web.archive.org/web/20150623202648/http://orvtech.com/atacar-efi-pin-macbook-pro.html)
- [iCloud variant follow-up](http://web.archive.org/web/20191118170802/https://orvtech.com/ataque-fuerza-bruta-pin-icloud-en.html)

External coverage and downstream community work:

- [Hackaday — Mac EFI PIN Lock Brute Force Attack (unsuccessful)](https://hackaday.com/2013/02/26/mac-efi-pin-lock-brute-force-attack-unsuccessful/) — 82 comments, Feb 2013
- [Hacker News — Automated brute-force attack against the EFI PIN](https://news.ycombinator.com/item?id=7993435) — 67 points, Jul 2014
- [MacRumors — How to unlock System Lock PIN Code](https://forums.macrumors.com/threads/how-to-unlock-system-lock-pin-code.1438822/page-9) — long-running community thread
- [Arduino Forum — Revisiting orvtech's EFI Firmware & iCloud unlock for Macs](https://forum.arduino.cc/t/revisiting-orvtechs-efi-firmware-icloud-unlock-for-macs/313576) — May 2015 Pro Micro port
- [knoy/iCloudHacker](https://github.com/knoy/iCloudHacker) — downstream fork targeting the iCloud Activation Lock prompt (222+ stars)

The 2026 post-mortem with everything I'd do differently:

- [The Teensy That Failed in Public](https://rivassec.com/teensy-efi-bruteforce-hours-late.html)

---

## 🧭 DevSecOps Perspective

While not a traditional software-security project, this repo demonstrates:

- Hardware-based attack automation
- Rate-limit edge analysis
- Cross-domain awareness across firmware, USB HID, and physical security

For modern DevSecOps engineers, low-level tooling insight supports broader
incident-response and security-architecture work. The same instincts —
slow down, instrument, treat layered defenses as observable — port cleanly
into cloud and CI/CD security.

---

## 🔄 Roadmap

This project is feature-complete for its target hardware (pre-T2 MacBooks).
No further development is planned. The repo is preserved for reference and
forensic use cases.

If you fork this for a new hardware target or password-prompt screen,
please link back so the genealogy stays visible.

---

## 📜 License

This project is released under the [MIT License](LICENSE).
