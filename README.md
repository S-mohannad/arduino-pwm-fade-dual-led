# 💡 PWM Fade In — Dual LED Brightness Control

> **Arduino Project #05** — LED يزيد سطوعه تدريجياً حتى أقصى درجة ثم يطفي فجأة ويتوقف 3 ثواني

[![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white)](https://www.arduino.cc/)
[![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Level](https://img.shields.io/badge/Level-Beginner-green?style=for-the-badge)](https://github.com/S-mohannad)

---

## 📋 Description

LEDان على Pin 9 و Pin 10 يزدادان سطوعاً تدريجياً من 0 إلى 255 بخطوات 5، ثم يطفيان فجأة ويتوقفان 3 ثواني قبل أن تبدأ الدورة من جديد. يستخدم **PWM** للتحكم الناعم في السطوع.

---

## 🔌 Circuit

```
Arduino UNO
┌─────────────────┐
│             9 ●─┼──[220Ω]──💡 LED 1 ── GND
│            10 ●─┼──[220Ω]──💡 LED 2 ── GND
│           GND ●─┼──────────────────────GND
└─────────────────┘
```

- 💡 LED 1 على Pin 9 (PWM) مع مقاومة 220Ω
- 💡 LED 2 على Pin 10 (PWM) مع مقاومة 220Ω
- ⚠️ يجب استخدام Pins تدعم PWM (3, 5, 6, 9, 10, 11)

---

## 💡 Concepts Used

- `analogWrite()` — التحكم في السطوع عبر PWM (0-255)
- **PWM (Pulse Width Modulation)** — تقنية التحكم في الجهد الفعّال
- `if / else` — للتحقق من الوصول لأقصى قيمة
- **التزايد التدريجي** — `x = x + 5` لزيادة السطوع بشكل ناعم
- `delay()` — التحكم في توقيت كل خطوة

---

## 📊 Behavior

| المرحلة | قيمة x | السطوع | المدة |
|---------|--------|--------|-------|
| Fade In | 0 → 255 | يزيد تدريجياً | 150ms × 51 خطوة |
| إطفاء فجائي | 255 → 0 | يطفي فوراً | فوري |
| توقف | 0 | مطفي | 3000ms |
| تكرار ∞ | — | — | — |

---

## 🔗 Code

```cpp
int x = 0;

void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  analogWrite(9, x);
  analogWrite(10, x);
  delay(150);

  if (x < 255) {
    x = x + 5;
  } else {
    x = 0;
    delay(300);
    analogWrite(10, x);
    analogWrite(9, x);
    delay(3000);
  }
}
```

## 🔧 How to Run

1. افتح **Arduino IDE**
2. وصّل الدائرة كما في الرسم
3. انسخ الكود والصقه
4. اختر **Board:** Arduino UNO
5. اختر **Port** الصحيح
6. اضغط ⬆️ **Upload**
7. شاهد الـ LEDين يزيد سطوعهما تدريجياً ثم يطفيان فجأة
---

## 👨‍💻 Author

**S-mohannad** — [@S-mohannad](https://github.com/S-mohannad)
