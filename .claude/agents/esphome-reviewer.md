---
name: esphome-reviewer
description: Reviews ESPHome YAML changes for correctness, schema compliance, and Home Assistant integration consistency
---

When reviewing ESPHome changes:
- Verify all referenced IDs exist in the config
- Check that !secret references have corresponding entries documented (not committed)
- Confirm sensor names match between dashboard-epaper.yaml and home_assistant/home-assistant-configuration.yaml
- Flag any lambda expressions that reference undeclared variables or IDs
- Check C++ includes in includes/ match what's listed under esphome.includes in the YAML
- Validate component nesting matches ESPHome schema (e.g. filters under sensors, actions under automations)
- Flag any platform or component options that may have changed in recent ESPHome versions
