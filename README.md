# IoT Stack Tutorial and Microservices IoT Project

## Project Overview
This project contains two main parts:
- `IoT-Stack-tutorial-main/`: A Docker-based setup for IoT services including Grafana, Node-RED, Mosquitto, and InfluxDB.
- `microservices-iot/`: Code for managing IoT microservices using PlatformIO.

## Prerequisites
- Docker & Docker Compose
- PlatformIO for microservices development

## Usage
1. Navigate to `IoT-Stack-tutorial-main/` and run the IoT stack using Docker Compose:

   ```bash
   docker-compose up
   
2. PlatformIO microservices code is available in `microservices-iot/` .

## Important Configuration Notes
1. Replace "YOUR_SSID" and "YOUR_PASSWORD" with your actual Wi-Fi network details :
   
   ```bash
   const char* ssid = "YOUR_SSID";
   const char* password = "YOUR_PASSWORD";
   
2. Make sure to update the IP address for any networked services .

   
