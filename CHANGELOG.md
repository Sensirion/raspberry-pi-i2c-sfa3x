# CHANGELOG

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased] 

## [1.0.0] - 2025-3-18

### Added

- All commands generated according to data sheet. This introduces breaking changes!

### Breaking changes

- `sfa3x_init(SFA3X_I2C_ADDR_5D)` needs to be called before sending any commands to the sensor
- `sfa3x_read_measured_values_ticks()` is now `sfa3x_read_measured_values_as_integers()`

## [0.1.0] - 2021-3-15

- Initial Release

[Unreleased]: https://github.com/Sensirion/raspberry-pi-i2c-sfa3x/compare/1.0.0...HEAD
[1.0.0]: https://github.com/Sensirion/raspberry-pi-i2c-sfa3x/compare/0.1.0...1.0.0
[0.1.0]: https://github.com/Sensirion/raspberry-pi-i2c-sfa3x/releases/tag/0.1.0