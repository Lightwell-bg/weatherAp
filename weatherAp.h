#ifndef weatherAP_h
#define weatherAP_h
#include <Arduino.h>
#ifdef ESP32
  #include <WiFi.h>
#else
  #include <ESP8266WiFi.h>
#endif
#include <ArduinoJson.h>        //https://github.com/bblanchon/ArduinoJson.git

/*typedef struct weatherDataStruct {
    float coord_lon; // 27.47
    float coord_lat; // 42.51
    String wMain;
    String wDescription;
    String wIcon;
    float temp;
    float feels_like;
    uint8_t humidity;  
    uint16_t pressure;
    float pressure_mm;
    float temp_min;
    float temp_max;
    float wSpeed;
    uint16_t wDeg;
    uint8_t clouds;
    uint32_t sunrise;
    uint32_t sunset;
    uint32_t lastUpdate;
};*/


class weatherAP {
    public:
        weatherAP(WiFiClient *client);
        void setWeatherServer(const char *wURL, const char *wAPI, const char *wCityID);
        bool getWeather(const uint8_t* lang);
        bool getWForecast(const uint8_t* lang);
        bool getSeaTemp(const char* seaID);
        //weatherDataStruct getWeatherData(void);
        float coord_lon; // 27.47
        float coord_lat; // 42.51
        String wMain;
        String wDescription;
        String wIcon;
        float temp;
        float feels_like;
        uint8_t humidity;  
        uint16_t pressure;
        float pressure_mm;
        float temp_min;
        float temp_max;
        float wSpeed;
        uint16_t wDeg;
        uint8_t clouds;
        uint32_t sunrise;
        uint32_t sunset;
        uint32_t lastUpdate;
        //Sea
        String seaTemp;
        uint32_t lastSeaUpdate;
        //Forecast
        String wfIcon;
        String wfDescription;
        float fTemp;
        float fFeels_like;
        float tempfMin;
        float tempfMax;
        uint8_t fHumidity;
        uint16_t fPressure;
        float fPressure_mm;
        float fwSpeed;
        uint16_t fwDeg;
        uint32_t fLastUpdate;

        
    private:
        WiFiClient* _client;
        const char* _wURL;
        const char* _wAPI;
        const char* _wCityID;
        const char* _seaURL = "worldseatemp.com";
        //weatherDataStruct _wData;
};




#endif