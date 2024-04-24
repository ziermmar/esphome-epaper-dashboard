      |-
      // Show loading screen before data is received.
      if (id(initial_data_received) == false) {
        it.printf(400, 390, id(small), TextAlign::TOP_CENTER, translate["WAITING FOR DATA..."].c_str());
      } else
      {
        // Forecast Boxes
        it.rectangle(550,220,80,80);
        it.rectangle(550,220,160,80);
        it.rectangle(550,220,240,80);
        it.rectangle(550,360,80,80);
        it.rectangle(550,360,160,80);
        it.rectangle(550,360,240,80);

        //Date and Time
        it.printf(400, 10,     id(small),  TextAlign::CENTER_HORIZONTAL, germanTime.c_str());
        //it.strftime(400, 30, id(big),    TextAlign::CENTER_HORIZONTAL, "%H:%M",         id(homeassistant_time).now());
        it.printf(400,60,      id(medium), TextAlign::CENTER_HORIZONTAL, "%s",            getTimeInWords().c_str());

        //Current Weather
        it.printf(400, 160, id(tiny),           TextAlign::CENTER_HORIZONTAL, "%s: %s", translate["currently"].c_str(), translate[id(weather_now).state.c_str()].c_str());
        it.printf(400, 180, id(font_mdi_large), TextAlign::CENTER_HORIZONTAL, "%s",     mdi_icon[id(weather_now).state.c_str()].c_str());
        it.printf(400, 360, id(medium),         TextAlign::CENTER_HORIZONTAL, "%.1f°",  id(temp_now).state);

        //Hourly Forecast
        it.printf(670,160, id(tiny),            TextAlign::CENTER_HORIZONTAL, "%s:",   translate["forecast"].c_str());
        it.printf(670,190, id(tiny),            TextAlign::CENTER_HORIZONTAL, "%s",    translate["hourly"].c_str());
        it.printf(590,225, id(font_mdi_medium), TextAlign::CENTER_HORIZONTAL, "%s",    mdi_icon[id(weather_h1).state.c_str()].c_str());
        it.printf(670,225, id(font_mdi_medium), TextAlign::CENTER_HORIZONTAL, "%s",    mdi_icon[id(weather_h2).state.c_str()].c_str());
        it.printf(750,225, id(font_mdi_medium), TextAlign::CENTER_HORIZONTAL, "%s",    mdi_icon[id(weather_h1).state.c_str()].c_str());
        it.printf(590,265, id(tiny),            TextAlign::CENTER_HORIZONTAL, "%.0f°", id(temp_h1).state);
        it.printf(670,265, id(tiny),            TextAlign::CENTER_HORIZONTAL, "%.0f°", id(temp_h2).state);
        it.printf(750,265, id(tiny),            TextAlign::CENTER_HORIZONTAL, "%.0f°", id(temp_h3).state);

        //Daily Forecast
        it.printf(670,330, id(tiny),            TextAlign::CENTER_HORIZONTAL, "%s",    translate["daily"].c_str());
        it.printf(590,365, id(font_mdi_medium), TextAlign::CENTER_HORIZONTAL, "%s",    mdi_icon[id(weather_d1).state.c_str()].c_str());
        it.printf(670,365, id(font_mdi_medium), TextAlign::CENTER_HORIZONTAL, "%s",    mdi_icon[id(weather_d2).state.c_str()].c_str());
        it.printf(750,365, id(font_mdi_medium), TextAlign::CENTER_HORIZONTAL, "%s",    mdi_icon[id(weather_d1).state.c_str()].c_str());
        it.printf(590,405, id(tiny),            TextAlign::CENTER_HORIZONTAL, "%.0f°", id(temp_d1).state);
        it.printf(670,405, id(tiny),            TextAlign::CENTER_HORIZONTAL, "%.0f°", id(temp_d2).state);
        it.printf(750,405, id(tiny),            TextAlign::CENTER_HORIZONTAL, "%.0f°", id(temp_d3).state);

        //Pool Temperature
        it.printf(20,  160, id(font_mdi_medium), TextAlign::TOP_LEFT,  mdi_icon["pool-temperature"].c_str());

        if (!isnan(id(pooltemperature).state)) {
          it.printf(250, 160, id(small),           TextAlign::TOP_RIGHT, "%.2f °C", id(pooltemperature).state);
        } else {
          it.printf(250, 160, id(small),           TextAlign::TOP_RIGHT, "-");
        }

        //Solar Data
        it.printf(20,  210, id(font_mdi_medium), TextAlign::TOP_LEFT,  mdi_icon["home-lightning-bolt"].c_str());
        it.printf(250, 210, id(small),           TextAlign::TOP_RIGHT, "%.2f W", id(power_comsumption).state);
        it.printf(20,  260, id(font_mdi_medium), TextAlign::TOP_LEFT,  mdi_icon["solar-power-variant"].c_str());
        if (!isnan(id(solar_power).state)) {
          it.printf(250, 260, id(small),           TextAlign::TOP_RIGHT, "%.2f W", id(solar_power).state);
        } else {
          it.printf(250, 260, id(small),           TextAlign::TOP_RIGHT, "-");
        }
        it.printf(20,  306, id(font_mdi_medium), TextAlign::TOP_LEFT,  mdi_icon["cash-multiple"].c_str());
        it.printf(250, 310, id(small),           TextAlign::TOP_RIGHT, "%.2f €", id(gesamtersparnis).state);

        //Energy Graph
        it.graph(20, 360, id(energy_graph));
      }
