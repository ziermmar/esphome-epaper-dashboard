# ESPhome E-Ink Dashboard

[![Build and Publish ESPHome firmware](https://github.com/ziermmar/esphome-epaper-dashboard/actions/workflows/push.yml/badge.svg)](https://github.com/ziermmar/esphome-epaper-dashboard/actions/workflows/push.yml)

![Screen capture of an e-ink display](https://raw.githubusercontent.com/ziermmar/esphome-epaper-dashboard/main/images/screen-capture.jpeg)

## Features

* ESPHome Dashboard on Waveshare E-Paper
* Displays sensor outputs
* Material Design Icons
* Ability to translate sensor output (example in german)
* Wordclock (german)
* Fits in IKEA Ribba Picture Frame

## Hardware

* [Waveshare 7.5 inch E-Ink Display with ESP32 driver board](https://amzn.to/3JBRzas) 72 €
* [Logilink Flat USB Power supply](https://amzn.to/3JD4Gbe) 8 €
* [4.5 m micro USB cable](https://amzn.to/44jEufC) 9 €

  *(Amazon.de Affiliate links)*

## Download

A prebuilt binary for the hardware listed above can be downloaded from github.com: [dashboard-epaper-esp32.bin](https://ziermmar.github.io/esphome-epaper-dashboard/dashboard-epaper-esp32/dashboard-epaper-esp32.bin)

## Instructions

1. Follow [ESPhome](https://esphome.io) documentation

2. Create secrets.yml and add your own values

    ```yaml
    api_key: "your-api-key"
    ota_password: "your-ota-password"
    wifi_ssid: "your-ssid"
    wifi_password: "your-wifi-password"
    fallback_ssid: "Dashboard-Epaper"
    fallback_password: "your-fallback-wifi-password"
    ```

3. Integrate contents of ```home-assistant-configuration.yaml``` into your Homeassistant ```configuration.yaml```

4. Download Material Design Fonts (links below)

    Copy fonts into ```fonts/``` directory

5. Upload dashboard-epaper.yaml to your ESP32

   ```shell
   esphome run dashboard-epaper.yaml
   ```

## Links and Acknowledgements

* Material Design Icons: <https://github.com/google/material-design-icons/tree/master/font>
* Material Design Icons: <https://github.com/Templarian/MaterialDesign-Webfont/blob/master/fonts/materialdesignicons-webfont.ttf>
* Lookup UTF IDs in MDI Font: <https://pictogrammers.com/library/mdi/>
* Inspired by this Project: <https://github.com/Madelena/esphome-weatherman-dashboard>
* Inspired by this Project: <https://github.com/techdregs/E-Paper-DashBoard>
* Semantic git commit messages: <https://www.conventionalcommits.org/en/v1.0.0/#summary>
