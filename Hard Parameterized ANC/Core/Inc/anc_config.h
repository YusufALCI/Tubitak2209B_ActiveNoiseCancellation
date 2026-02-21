/*
 * anc_config.h
 * Description: Temel sistem ve algoritma ayarları - DENGELENMİŞ VERSİYON
 */

#ifndef ANC_CONFIG_H_
#define ANC_CONFIG_H_

// --- KRİTİK KÜTÜPHANELER ---
#include <stdint.h>
#include "arm_math.h"
#include <math.h>
#include <stdlib.h>

// ==========================================
// 1. TEMEL SİSTEM AYARLARI
// ==========================================
#define SAMPLING_RATE           48000
#define NUM_SAMPLES             32
#define BLOCK_SIZE              NUM_SAMPLES
#define I2S_BUFFER_SIZE         (NUM_SAMPLES * 2 * 2)

// ==========================================
// 2. MATEMATİKSEL SABİTLER
// ==========================================
#define INV_MAX_24BIT           1.1920928955078125e-7f

// ==========================================
// 3. DSP VE SES İŞLEME AYARLARI
// ==========================================
#define DC_ALPHA                0.9995f
#define TARGET_PEAK             0.9f
#define MAX_GAIN                20.0f
#define MIN_SIGNAL              0.00001f

// ==========================================
// 4. İSTİHBARAT (FFT) AYARLARI
// ==========================================
#define FFT_LENGTH              4096
#define SILENCE_THRESH          0.001f

// ==========================================
// 5. SENTEZLEYİCİ AYARLARI
// ==========================================
#define NUM_HARMONICS           3
#define TEST_VOLUME             0.1f

// ==========================================
// 6. İKİNCİL YOL (SECONDARY PATH) AYARLARI
// ==========================================
#define SEC_PATH_LENGTH         64

// [DÜZELTME 1] Patlamayı önlemek için bunu düşürdük.
// 0.02 çok büyüktü, 0.0005 güvenlidir.
#define SEC_PATH_STEP           0.005f

// [DÜZELTME 2] Mikrofonu doyuma sokmamak için sesi biraz kıstık.
#define CALIB_NOISE_VOL         0.40f

// [DÜZELTME 3] Latency 64 makul görünüyor, dokunmuyoruz.
#define SYSTEM_LATENCY          64
#define HISTORY_SIZE            256
#define HISTORY_MASK            (HISTORY_SIZE - 1)

// Durumlar
#define ANC_STATE_IDLE          0
#define ANC_STATE_CALIBRATION   1
#define ANC_STATE_RUNNING       2

// Mikrofon kazancı
#define MIC_SOFTWARE_GAIN       4.0f

// ==========================================
// 8. ANC (FxLMS) MOTOR AYARLARI
// ==========================================
#define ANC_FILTER_LENGTH       32

// [DÜZELTME 4 - KRİTİK] ANC Motorunu Uyandırıyoruz!
// 0.000000001 (1e-9) yerine 0.0001 (1e-4) yapıyoruz.
// Artık W katsayıları 0 kalmayacak.
#define ANC_STEP_SIZE           0.00002f

// [DÜZELTME 5] Leakage'ı kapattık (1.0f yaptık).
// 0.990 çok agresifti, katsayıları sürekli siliyordu.
// Şimdilik öğrenmeyi görmek için 1.0f (Leakage Yok) yapalım.
#define ANC_LEAKAGE             0.9995f

#endif /* ANC_CONFIG_H_ */
