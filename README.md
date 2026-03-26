# BLE Intercom Prototype (nRF52840 Pro Micro, Arduino IDE)

Прототип прошивки для Bluetooth-интеркома (half-duplex):
- микрофон INMP441 (I2S input)
- усилитель/ЦАП MAX98357A (I2S output)
- автозапуск по акустическому порогу
- uplink/downlink аудио через BLE (каркас)
- подробные отладочные логи в Serial

## Структура
Полностью повторяет запрошенную архитектуру `src/intercom`, `src/audio`, `src/bt`, `src/power`, `src/drivers`, `src/protocol`, `src/config`, `src/utils`.

## Важно
Текущая версия — **POC-каркас**:
- BLE транспорт и I2S драйверы оформлены как заглушки-интерфейсы.
- Для реального железа нужно привязать реализации к конкретному Arduino core/libraries для nRF52840.

## Запуск в Arduino IDE
1. Открыть проект и убедиться, что `src/main.cpp` включается сборкой.
2. Выбрать плату nRF52840 Pro Micro (или совместимую).
3. Скорость Serial: **115200**.
4. Проверить пины в `src/config/pins.h`.

## Отладочные логи
В Serial выводятся:
- переходы state machine (`[STATE]`)
- события триггера (`[TRIG]`)
- BLE события (`[BT]`)
- питание/режимы (`[PWR]`)
- таймаут сессии (`[SESSION]`)
- батарея (`[BAT]`)
