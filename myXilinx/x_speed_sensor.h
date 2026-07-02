#ifndef X_SPEED_SENSOR_H_
#define X_SPEED_SENSOR_H_

#ifdef __cplusplus
  extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the types
//-----------------------------------------------------------------------------

  union XSpeed_Sensor_sell_Sorce_reg {
      unsigned int all;
      struct {
          unsigned int index0:3;
          unsigned int index1:3;
          unsigned int index2:3;
          unsigned int index3:3;
      } chanals;
  };

  union XSpeed_Sensor_inv_Sorce {
      unsigned int all;
      struct{
          unsigned int index0:1;
          unsigned int index1:1;
          unsigned int index2:1;
          unsigned int index3:1;
      } chanals;
  };

  struct XSpeed_Sensor_Block_Config_filtr {
      unsigned int mininum_period_us;  // фильтр не пропустит импульс длительностью меньше (mininum_period_us/2)
      unsigned int hysteresis_percent; // 0 to 49; по умолчанию 10%, т.е. Count от 0 до CountMax*0.1 уровень '0', от CountMax*0.9 до CountMax уровень '1'.
                                       // длЯ 0%                          если Count = 0 уровень '0', если Count = CountMax уровень '1'.
      unsigned int info_precision_ns;       // длЯ информащионных целей; точность в нс.
      unsigned int info_max_period_half_ms; // длЯ информащионных целей; если сигнал не менЯл своё значение больше этого времени, то счетчик переполнитьсЯ.
  };

struct XSpeed_Sensor_Block_Config{
    struct XSpeed_Sensor_Block_Config_filtr Filtr[2]; // Filtr[0] для настройки каналов 0...3; Filtr[1] длz настройки каналов 4...7.
    union  XSpeed_Sensor_sell_Sorce_reg     Sorce;
    union  XSpeed_Sensor_inv_Sorce          SorceInv;
};

struct XSpeed_Sensor_Block {
    // Speed_us[0] - сигнал 0 прошедший через Filtr[0];
    // Speed_us[1] - сигнал 1 прошедший через Filtr[0];
    // Speed_us[2] - сигнал 2 прошедший через Filtr[0];
    // Speed_us[3] - сигнал 3 прошедший через Filtr[0];

    // Speed_us[4] - сигнал 0 прошедший через Filtr[1];
    // Speed_us[5] - сигнал 1 прошедший через Filtr[1];
    // Speed_us[6] - сигнал 2 прошедший через Filtr[1];
    // Speed_us[7] - сигнал 3 прошедший через Filtr[1];
    unsigned long Speed_us[8];

    // Direction[0] - направление м/у сигналами 0 и 1 прошедшими через Filtr[0]: 1 => сигнал 0 опережает сигнал 1; 0 => информациЯ отсутствует или недостоверна; -1 => сигнал 0 отстаёт от сигнала 1.
    // Direction[1] - направление м/у сигналами 1 и 0 прошедшими через Filtr[0]: 1 => сигнал 1 опережает сигнал 0; 0 => информациЯ отсутствует или недостоверна; -1 => сигнал 1 отстаёт от сигнала 0.
    // Direction[2] - направление м/у сигналами 2 и 3 прошедшими через Filtr[0]: 1 => сигнал 2 опережает сигнал 3; 0 => информациЯ отсутствует или недостоверна; -1 => сигнал 2 отстаёт от сигнала 3.
    // Direction[3] - направление м/у сигналами 3 и 2 прошедшими через Filtr[0]: 1 => сигнал 3 опережает сигнал 2; 0 => информациЯ отсутствует или недостоверна; -1 => сигнал 3 отстаёт от сигнала 2.

    // Direction[4] - направление м/у сигналами 0 и 1 прошедшими через Filtr[1]: 1 => сигнал 0 опережает сигнал 1; 0 => информациЯ отсутствует или недостоверна; -1 => сигнал 0 отстаёт от сигнала 1.
    // Direction[5] - направление м/у сигналами 1 и 0 прошедшими через Filtr[1]: 1 => сигнал 1 опережает сигнал 0; 0 => информациЯ отсутствует или недостоверна; -1 => сигнал 1 отстаёт от сигнала 0.
    // Direction[6] - направление м/у сигналами 2 и 3 прошедшими через Filtr[1]: 1 => сигнал 2 опережает сигнал 3; 0 => информациЯ отсутствует или недостоверна; -1 => сигнал 2 отстаёт от сигнала 3.
    // Direction[7] - направление м/у сигналами 3 и 2 прошедшими через Filtr[1]: 1 => сигнал 3 опережает сигнал 2; 0 => информациЯ отсутствует или недостоверна; -1 => сигнал 3 отстаёт от сигнала 2.
    unsigned int  Direction[8];

    //  fifo_is_updated
    // '1' => поЯвились новые данные; счетчик фильтра не переполнен.
    // bit[0] : длЯ сигнал 0, прошедшего через Filtr[0];
    // bit[1] : длЯ сигнал 1, прошедшего через Filtr[0];
    // bit[2] : длЯ сигнал 2, прошедшего через Filtr[0];
    // bit[3] : длЯ сигнал 3, прошедшего через Filtr[0];

    // bit[4] : длЯ сигнал 0, прошедшего через Filtr[1];
    // bit[5] : длЯ сигнал 1, прошедшего через Filtr[1];
    // bit[6] : длЯ сигнал 2, прошедшего через Filtr[1];
    // bit[7] : длЯ сигнал 3, прошедшего через Filtr[1];
    unsigned int  fifo_is_updated;

    // данные не обновлЯлить в течение CountUpdate вызовов функции.
    unsigned int  CountUpdate;
};

typedef volatile struct {
    struct XSpeed_Sensor_Block_Config Config;
    struct XSpeed_Sensor_Block Read;
    unsigned int IsReady:1;
    Xinput_new_uni *Input_new;
} XSpeed_Sensor;

#ifdef __cplusplus
  }
#endif

#endif // end X_SPEED_SENSOR_H_
