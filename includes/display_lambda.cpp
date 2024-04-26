      |-
      // Show loading screen before data is received.
      if (id(initial_data_received) == false) {
        it.printf(400, 390, id(small), TextAlign::TOP_CENTER, translate["WAITING FOR DATA..."].c_str());
      } else
      {

        //Date and Time
        it.printf(400, 10,     id(small),  TextAlign::CENTER_HORIZONTAL, "%s", getGermanDate().c_str());
        //it.strftime(400, 30, id(big),    TextAlign::CENTER_HORIZONTAL, "%H:%M", id(homeassistant_time).now());
        it.printf(400,60,      id(medium), TextAlign::CENTER_HORIZONTAL, "%s", getTimeInWords().c_str());

        //Current Weather
        it.printf(400, 150, id(font_mdi_large), TextAlign::CENTER_HORIZONTAL, "%s",     mdi_icon[id(weather_now).state.c_str()].c_str());
        it.printf(400, 330, id(medium),         TextAlign::CENTER_HORIZONTAL, "%.1f°",  id(temp_now).state);
        it.printf(400, 410, id(tiny),           TextAlign::CENTER_HORIZONTAL, "%s",     translate[id(weather_now).state.c_str()].c_str());

        //Hourly Forecast
        it.rectangle(545,215,80,80);
        it.rectangle(545,215,160,80);
        it.rectangle(545,215,240,80);
        //it.printf(665,160, id(tiny),            TextAlign::CENTER_HORIZONTAL, "%s:",   translate["forecast"].c_str());
        it.printf(665,175, id(tiny),            TextAlign::CENTER_HORIZONTAL, "%s",    translate["hourly"].c_str());
        it.printf(585,220, id(font_mdi_medium), TextAlign::CENTER_HORIZONTAL, "%s",    mdi_icon[id(weather_h1).state.c_str()].c_str());
        it.printf(665,220, id(font_mdi_medium), TextAlign::CENTER_HORIZONTAL, "%s",    mdi_icon[id(weather_h2).state.c_str()].c_str());
        it.printf(745,220, id(font_mdi_medium), TextAlign::CENTER_HORIZONTAL, "%s",    mdi_icon[id(weather_h1).state.c_str()].c_str());
        it.printf(585,260, id(tiny),            TextAlign::CENTER_HORIZONTAL, "%.0f°", id(temp_h1).state);
        it.printf(665,260, id(tiny),            TextAlign::CENTER_HORIZONTAL, "%.0f°", id(temp_h2).state);
        it.printf(745,260, id(tiny),            TextAlign::CENTER_HORIZONTAL, "%.0f°", id(temp_h3).state);

        //Daily Forecast
        it.rectangle(545,360,80,80);
        it.rectangle(545,360,160,80);
        it.rectangle(545,360,240,80);
        it.printf(665,320, id(tiny),            TextAlign::CENTER_HORIZONTAL, "%s",    translate["daily"].c_str());
        it.printf(585,365, id(font_mdi_medium), TextAlign::CENTER_HORIZONTAL, "%s",    mdi_icon[id(weather_d1).state.c_str()].c_str());
        it.printf(665,365, id(font_mdi_medium), TextAlign::CENTER_HORIZONTAL, "%s",    mdi_icon[id(weather_d2).state.c_str()].c_str());
        it.printf(745,365, id(font_mdi_medium), TextAlign::CENTER_HORIZONTAL, "%s",    mdi_icon[id(weather_d1).state.c_str()].c_str());
        it.printf(585,405, id(tiny),            TextAlign::CENTER_HORIZONTAL, "%.0f°", id(temp_d1).state);
        it.printf(665,405, id(tiny),            TextAlign::CENTER_HORIZONTAL, "%.0f°", id(temp_d2).state);
        it.printf(745,405, id(tiny),            TextAlign::CENTER_HORIZONTAL, "%.0f°", id(temp_d3).state);

        //Pool Temperature
        it.printf(20,  175, id(font_mdi_medium), TextAlign::TOP_LEFT,  mdi_icon["pool-temperature"].c_str());

        if (!isnan(id(pooltemperature).state)) {
          it.printf(250, 175, id(small),           TextAlign::TOP_RIGHT, "%.2f °C", id(pooltemperature).state);
        } else {
          it.printf(250, 175, id(small),           TextAlign::TOP_RIGHT, "-");
        }

        //Solar Data
        it.printf(20,  220, id(font_mdi_medium), TextAlign::TOP_LEFT,  mdi_icon["home-lightning-bolt"].c_str());
        it.printf(250, 220, id(small),           TextAlign::TOP_RIGHT, "%.0f W", id(power_comsumption).state);

        it.printf(20,  265, id(font_mdi_medium), TextAlign::TOP_LEFT,  mdi_icon["solar-power-variant"].c_str());
        if (!isnan(id(solar_power).state)) {
          it.printf(250, 265, id(small),           TextAlign::TOP_RIGHT, "%.0f W", id(solar_power).state);
        } else {
          it.printf(250, 265, id(small),           TextAlign::TOP_RIGHT, "-");
        }

        it.printf(20,  306, id(font_mdi_medium), TextAlign::TOP_LEFT,  mdi_icon["cash-multiple"].c_str());
        it.printf(250, 310, id(small),           TextAlign::TOP_RIGHT, "%.2f €", id(gesamtersparnis).state);

        //Energy Graph
        it.graph(20, 360, id(energy_graph));
      }
