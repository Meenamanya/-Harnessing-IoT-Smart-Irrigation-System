# -Harnessing-IoT-Smart-Irrigation-System
IoT based automatic irrigation system using NodeMCU ESP8266

# 📌About The Project
An IoT-based automatic irrigation system that monitors 
soil moisture in real-time and automatically controls 
a water pump using NodeMCU ESP8266 and the Blynk mobile app.
Agriculture contributes 16% of India's GDP. Water wastage 
in irrigation is a major problem. This system solves it 
by automating irrigation based on actual soil conditions.


## ⚙️ How It Works
1. Soil moisture sensor continuously reads moisture level
2. If moisture is below 30% → Water pump turns ON automatically
3. If moisture is between 30–60% → Pump stays OFF (Medium)
4. If moisture is above 60% → Pump stays OFF (High)
5. All data is sent to Blynk app for remote monitoring

## 🛠️ Components Used
| Component | Purpose |
|---|---|
| NodeMCU ESP8266 | Main controller + WiFi |
| Soil Moisture Sensor | Reads soil water content |
| Relay Module | Controls the water pump |
| Water Pump | Supplies water to soil |
| LCD Display | Shows moisture status |
| Jumper Wires | Connects components |

## 💻 Software Used
- Arduino IDE
- Blynk Mobile App
- Blynk Cloud

---

## 📊 Results
The system successfully:
- ✅ Monitors soil moisture in real-time
- ✅ Automatically turns pump ON/OFF
- ✅ Displays data on Blynk mobile app
- ✅ Sends alerts when moisture is low
- ✅ Prevents over-irrigation

---

## 🚀 Future Improvements
- Solar power integration
- AI based predictive irrigation
- pH and nutrient level monitoring
- Weather API integration
- WhatsApp/Telegram alerts

  ---

## 📚 References
- IEEE IoT Journal 2021
- Agricultural Engineering Review 2022
- Journal of IoT in Agriculture 2023

