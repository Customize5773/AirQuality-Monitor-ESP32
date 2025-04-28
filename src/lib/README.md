# 📚 Libraries

This `lib/` folder contains any **custom libraries** or **manually added external libraries** used in the **AirQuality-Monitor-ESP32** project.

---

## 📦 Folder Structure Example

```
lib/
├── README.md
├── CustomLibrary1/
│   ├── CustomLibrary1.h
│   ├── CustomLibrary1.cpp
│   └── library.json (optional)
└── ExternalLibrary2/
    ├── ExternalLibrary2.h
    ├── ExternalLibrary2.cpp
    └── library.json (optional)
```

---

## 📜 Notes

- Each library should be placed in its **own folder** inside `lib/`.
- If you're using **PlatformIO**, you can also include a `library.json` manifest file for better library management.
- **Custom Libraries** are encouraged if:
  - You create reusable code modules.
  - You want to share standardized features across projects.

---

## 📋 Current Status
🔹 No custom libraries added yet.  
🔹 You can add here later if needed (example: custom Sensor drivers, Alert Systems, etc).

---

> 📢 **Tip:**  
> Keep third-party libraries managed separately using Arduino Library Manager or PlatformIO Registry where possible.  
> Only put custom or manually modified libraries inside `/lib/`.

---
