#  Digital Rain Animation(A.K.A Matrix Effect) for ESP32 Displays

<div align="center">

[![Matrix Prism](./misc/matrix_prism.gif)](https://youtu.be/49H7vtQmagQ)
</div>

Bring the iconic Matrix-style digital rain animation to life on your ESP32-powered display!
This library supports popular graphics drivers like **TFT_eSPI**, **LovyanGFX**, and **Arduino_GFX** (Adafruit GFX), making it easy to integrate with a wide range of displays.

---

## Demo Videos

Click the thumbnails below to see the animation in action:

[![v2.0 demo](https://github.com/0015/TP_Arduino_DigitalRain_Anim/blob/main/misc/v2.0.jpg)](https://youtu.be/1qTgspF4SPc)

[![video preview](https://github.com/0015/TP_Arduino_DigitalRain_Anim/blob/main/misc/image.jpg)](https://youtu.be/i6gGK4L4Yv8)

[![TTGO demo](https://github.com/0015/TP_Arduino_DigitalRain_Anim/blob/main/misc/ttgo.jpg)](https://youtu.be/uexWyEWtVzg)

---

## Features

- Matrix-style rain effect on various displays
- Supports:
  - **TFT_eSPI**
  - **LovyanGFX**
  - **Arduino_GFX (Adafruit GFX)**
- Customizable:
  - Text and background colors
  - Character size
  - Falling speed and effect intensity
- Random key generation with color-switching animation
- Minimal resource usage for smooth rendering

---

## Installation

### From Arduino Library Manager
1. Open **Arduino IDE**
2. Go to **Sketch → Include Library → Manage Libraries…**
3. Search for **Digital Rain Animation**
4. Click **Install**

### Manual Installation
```bash
git clone https://github.com/0015/TP_Arduino_DigitalRain_Anim.git
```

## Update Log
- v2.0.2
   * Fixed bug where one more line would be displayed

- v2.0.1
   * Added support for TFT_eSPI, LovyanGFX, Arduino_GFX
   * Example added for Japanese characters

- v1.2.1
   * Added color customization:
      * Background
      * Text
      * Header character

- v1.1.x
   * Added random key generator
   * Red animation mode when key is active
   * Examples added for key features


## License
This project is licensed under the MIT License. See the [LICENSE](./LICENSE) file for more information.