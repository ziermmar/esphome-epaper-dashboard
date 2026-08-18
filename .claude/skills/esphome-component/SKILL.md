---
name: esphome-component
description: Add a new ESPHome sensor or component to dashboard-epaper.yaml following project conventions
---

When adding a component:
1. Read the current dashboard-epaper.yaml to understand existing patterns and component structure
2. Follow the existing naming convention (snake_case IDs)
3. Use !secret for any credentials or sensitive values
4. Add any required Home Assistant sensors to home_assistant/home-assistant-configuration.yaml
5. Place C++ helper logic in includes/ as a .h file with include guard (#ifndef / #define / #endif)
6. Register any new .h files under esphome.includes in dashboard-epaper.yaml
7. Verify all referenced IDs exist before using them in lambdas or automations
