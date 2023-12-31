
# Consider dependencies only in project.
set(CMAKE_DEPENDS_IN_PROJECT_ONLY OFF)

# The set of languages for which implicit dependencies are needed:
set(CMAKE_DEPENDS_LANGUAGES
  "ASM"
  )
# The set of files for implicit dependencies of each language:
set(CMAKE_DEPENDS_CHECK_ASM
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_divider/divider.S" "/Users/jonah/pico/pcbrock/eurorack-RTC/firm-1.2/build/CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_divider/divider.S.obj"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_irq/irq_handler_chain.S" "/Users/jonah/pico/pcbrock/eurorack-RTC/firm-1.2/build/CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_irq/irq_handler_chain.S.obj"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_bit_ops/bit_ops_aeabi.S" "/Users/jonah/pico/pcbrock/eurorack-RTC/firm-1.2/build/CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_bit_ops/bit_ops_aeabi.S.obj"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_divider/divider.S" "/Users/jonah/pico/pcbrock/eurorack-RTC/firm-1.2/build/CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_divider/divider.S.obj"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_double/double_aeabi.S" "/Users/jonah/pico/pcbrock/eurorack-RTC/firm-1.2/build/CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_double/double_aeabi.S.obj"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_double/double_v1_rom_shim.S" "/Users/jonah/pico/pcbrock/eurorack-RTC/firm-1.2/build/CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_double/double_v1_rom_shim.S.obj"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_float/float_aeabi.S" "/Users/jonah/pico/pcbrock/eurorack-RTC/firm-1.2/build/CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_float/float_aeabi.S.obj"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_float/float_v1_rom_shim.S" "/Users/jonah/pico/pcbrock/eurorack-RTC/firm-1.2/build/CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_float/float_v1_rom_shim.S.obj"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_int64_ops/pico_int64_ops_aeabi.S" "/Users/jonah/pico/pcbrock/eurorack-RTC/firm-1.2/build/CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_int64_ops/pico_int64_ops_aeabi.S.obj"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_mem_ops/mem_ops_aeabi.S" "/Users/jonah/pico/pcbrock/eurorack-RTC/firm-1.2/build/CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_mem_ops/mem_ops_aeabi.S.obj"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_standard_link/crt0.S" "/Users/jonah/pico/pcbrock/eurorack-RTC/firm-1.2/build/CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_standard_link/crt0.S.obj"
  )
set(CMAKE_ASM_COMPILER_ID "GNU")

# Preprocessor definitions for this target.
set(CMAKE_TARGET_DEFINITIONS_ASM
  "CFG_TUSB_DEBUG=0"
  "CFG_TUSB_MCU=OPT_MCU_RP2040"
  "CFG_TUSB_OS=OPT_OS_PICO"
  "LIB_PICO_BIT_OPS=1"
  "LIB_PICO_BIT_OPS_PICO=1"
  "LIB_PICO_DIVIDER=1"
  "LIB_PICO_DIVIDER_HARDWARE=1"
  "LIB_PICO_DOUBLE=1"
  "LIB_PICO_DOUBLE_PICO=1"
  "LIB_PICO_FIX_RP2040_USB_DEVICE_ENUMERATION=1"
  "LIB_PICO_FLOAT=1"
  "LIB_PICO_FLOAT_PICO=1"
  "LIB_PICO_INT64_OPS=1"
  "LIB_PICO_INT64_OPS_PICO=1"
  "LIB_PICO_MALLOC=1"
  "LIB_PICO_MEM_OPS=1"
  "LIB_PICO_MEM_OPS_PICO=1"
  "LIB_PICO_PLATFORM=1"
  "LIB_PICO_PRINTF=1"
  "LIB_PICO_PRINTF_PICO=1"
  "LIB_PICO_RUNTIME=1"
  "LIB_PICO_STANDARD_LINK=1"
  "LIB_PICO_STDIO=1"
  "LIB_PICO_STDIO_USB=1"
  "LIB_PICO_STDLIB=1"
  "LIB_PICO_SYNC=1"
  "LIB_PICO_SYNC_CORE=1"
  "LIB_PICO_SYNC_CRITICAL_SECTION=1"
  "LIB_PICO_SYNC_MUTEX=1"
  "LIB_PICO_SYNC_SEM=1"
  "LIB_PICO_TIME=1"
  "LIB_PICO_UNIQUE_ID=1"
  "LIB_PICO_UTIL=1"
  "PICO_BOARD=\"pico\""
  "PICO_BUILD=1"
  "PICO_CMAKE_BUILD_TYPE=\"Release\""
  "PICO_COPY_TO_RAM=0"
  "PICO_CXX_ENABLE_EXCEPTIONS=0"
  "PICO_NO_FLASH=0"
  "PICO_NO_HARDWARE=0"
  "PICO_ON_DEVICE=1"
  "PICO_TARGET_NAME=\"test\""
  "PICO_USE_BLOCKED_RAM=0"
  "PICO_XOSC_STARTUP_DELAY_MULTIPLIER=173"
  )

# The include file search paths:
set(CMAKE_ASM_TARGET_INCLUDE_PATH
  "/Users/jonah/pico/pico-sdk/src/common/pico_stdlib/include"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_gpio/include"
  "/Users/jonah/pico/pico-sdk/src/common/pico_base/include"
  "generated/pico_base"
  "/Users/jonah/pico/pico-sdk/src/boards/include"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_platform/include"
  "/Users/jonah/pico/pico-sdk/src/rp2040/hardware_regs/include"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_base/include"
  "/Users/jonah/pico/pico-sdk/src/rp2040/hardware_structs/include"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_claim/include"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_sync/include"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_irq/include"
  "/Users/jonah/pico/pico-sdk/src/common/pico_sync/include"
  "/Users/jonah/pico/pico-sdk/src/common/pico_time/include"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_timer/include"
  "/Users/jonah/pico/pico-sdk/src/common/pico_util/include"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_uart/include"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_divider/include"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_runtime/include"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_clocks/include"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_resets/include"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_pll/include"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_vreg/include"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_watchdog/include"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_xosc/include"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_printf/include"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_bootrom/include"
  "/Users/jonah/pico/pico-sdk/src/common/pico_bit_ops/include"
  "/Users/jonah/pico/pico-sdk/src/common/pico_divider/include"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_double/include"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_int64_ops/include"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_float/include"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_malloc/include"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/boot_stage2/include"
  "/Users/jonah/pico/pico-sdk/src/common/pico_binary_info/include"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_stdio/include"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_stdio_usb/include"
  "/Users/jonah/pico/pico-sdk/lib/tinyusb/src"
  "/Users/jonah/pico/pico-sdk/lib/tinyusb/src/common"
  "/Users/jonah/pico/pico-sdk/lib/tinyusb/hw"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_fix/rp2040_usb_device_enumeration/include"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_unique_id/include"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_flash/include"
  "/Users/jonah/pico/pico-sdk/src/common/pico_usb_reset_interface/include"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_i2c/include"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_pwm/include"
  "/Users/jonah/pico/pcbrock/eurorack-RTC/firm-1.2/littlefs-lib"
  "/Users/jonah/pico/pcbrock/eurorack-RTC/firm-1.2/stdinit-lib"
  )

# The set of dependency files which are needed:
set(CMAKE_DEPENDS_DEPENDENCY_FILES
  "/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/audio/audio_device.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/audio/audio_device.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/audio/audio_device.c.obj.d"
  "/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/cdc/cdc_device.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/cdc/cdc_device.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/cdc/cdc_device.c.obj.d"
  "/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/dfu/dfu_device.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/dfu/dfu_device.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/dfu/dfu_device.c.obj.d"
  "/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/dfu/dfu_rt_device.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/dfu/dfu_rt_device.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/dfu/dfu_rt_device.c.obj.d"
  "/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/hid/hid_device.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/hid/hid_device.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/hid/hid_device.c.obj.d"
  "/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/midi/midi_device.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/midi/midi_device.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/midi/midi_device.c.obj.d"
  "/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/msc/msc_device.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/msc/msc_device.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/msc/msc_device.c.obj.d"
  "/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/net/ecm_rndis_device.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/net/ecm_rndis_device.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/net/ecm_rndis_device.c.obj.d"
  "/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/net/ncm_device.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/net/ncm_device.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/net/ncm_device.c.obj.d"
  "/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/usbtmc/usbtmc_device.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/usbtmc/usbtmc_device.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/usbtmc/usbtmc_device.c.obj.d"
  "/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/vendor/vendor_device.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/vendor/vendor_device.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/vendor/vendor_device.c.obj.d"
  "/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/video/video_device.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/video/video_device.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/class/video/video_device.c.obj.d"
  "/Users/jonah/pico/pico-sdk/lib/tinyusb/src/common/tusb_fifo.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/common/tusb_fifo.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/common/tusb_fifo.c.obj.d"
  "/Users/jonah/pico/pico-sdk/lib/tinyusb/src/device/usbd.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/device/usbd.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/device/usbd.c.obj.d"
  "/Users/jonah/pico/pico-sdk/lib/tinyusb/src/device/usbd_control.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/device/usbd_control.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/device/usbd_control.c.obj.d"
  "/Users/jonah/pico/pico-sdk/lib/tinyusb/src/portable/raspberrypi/rp2040/dcd_rp2040.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/portable/raspberrypi/rp2040/dcd_rp2040.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/portable/raspberrypi/rp2040/dcd_rp2040.c.obj.d"
  "/Users/jonah/pico/pico-sdk/lib/tinyusb/src/portable/raspberrypi/rp2040/rp2040_usb.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/portable/raspberrypi/rp2040/rp2040_usb.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/portable/raspberrypi/rp2040/rp2040_usb.c.obj.d"
  "/Users/jonah/pico/pico-sdk/lib/tinyusb/src/tusb.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/tusb.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/lib/tinyusb/src/tusb.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/common/pico_sync/critical_section.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/common/pico_sync/critical_section.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/common/pico_sync/critical_section.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/common/pico_sync/lock_core.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/common/pico_sync/lock_core.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/common/pico_sync/lock_core.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/common/pico_sync/mutex.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/common/pico_sync/mutex.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/common/pico_sync/mutex.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/common/pico_sync/sem.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/common/pico_sync/sem.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/common/pico_sync/sem.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/common/pico_time/time.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/common/pico_time/time.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/common/pico_time/time.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/common/pico_time/timeout_helper.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/common/pico_time/timeout_helper.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/common/pico_time/timeout_helper.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/common/pico_util/datetime.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/common/pico_util/datetime.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/common/pico_util/datetime.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/common/pico_util/pheap.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/common/pico_util/pheap.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/common/pico_util/pheap.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/common/pico_util/queue.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/common/pico_util/queue.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/common/pico_util/queue.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_claim/claim.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_claim/claim.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_claim/claim.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_clocks/clocks.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_clocks/clocks.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_clocks/clocks.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_flash/flash.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_flash/flash.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_flash/flash.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_gpio/gpio.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_gpio/gpio.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_gpio/gpio.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_i2c/i2c.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_i2c/i2c.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_i2c/i2c.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_irq/irq.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_irq/irq.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_irq/irq.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_pll/pll.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_pll/pll.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_pll/pll.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_sync/sync.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_sync/sync.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_sync/sync.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_timer/timer.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_timer/timer.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_timer/timer.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_uart/uart.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_uart/uart.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_uart/uart.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_vreg/vreg.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_vreg/vreg.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_vreg/vreg.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_watchdog/watchdog.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_watchdog/watchdog.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_watchdog/watchdog.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_xosc/xosc.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_xosc/xosc.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/hardware_xosc/xosc.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_bootrom/bootrom.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_bootrom/bootrom.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_bootrom/bootrom.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_double/double_init_rom.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_double/double_init_rom.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_double/double_init_rom.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_double/double_math.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_double/double_math.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_double/double_math.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_fix/rp2040_usb_device_enumeration/rp2040_usb_device_enumeration.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_fix/rp2040_usb_device_enumeration/rp2040_usb_device_enumeration.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_fix/rp2040_usb_device_enumeration/rp2040_usb_device_enumeration.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_float/float_init_rom.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_float/float_init_rom.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_float/float_init_rom.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_float/float_math.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_float/float_math.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_float/float_math.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_malloc/pico_malloc.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_malloc/pico_malloc.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_malloc/pico_malloc.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_platform/platform.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_platform/platform.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_platform/platform.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_printf/printf.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_printf/printf.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_printf/printf.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_runtime/runtime.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_runtime/runtime.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_runtime/runtime.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_standard_link/binary_info.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_standard_link/binary_info.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_standard_link/binary_info.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_stdio/stdio.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_stdio/stdio.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_stdio/stdio.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_stdio_usb/reset_interface.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_stdio_usb/reset_interface.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_stdio_usb/reset_interface.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_stdio_usb/stdio_usb.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_stdio_usb/stdio_usb.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_stdio_usb/stdio_usb.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_stdio_usb/stdio_usb_descriptors.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_stdio_usb/stdio_usb_descriptors.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_stdio_usb/stdio_usb_descriptors.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_stdlib/stdlib.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_stdlib/stdlib.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_stdlib/stdlib.c.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_unique_id/unique_id.c" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_unique_id/unique_id.c.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_unique_id/unique_id.c.obj.d"
  "/Users/jonah/pico/pcbrock/eurorack-RTC/firm-1.2/littlefs-lib/lfs.c" "CMakeFiles/test.dir/littlefs-lib/lfs.c.obj" "gcc" "CMakeFiles/test.dir/littlefs-lib/lfs.c.obj.d"
  "/Users/jonah/pico/pcbrock/eurorack-RTC/firm-1.2/littlefs-lib/pico_hal.c" "CMakeFiles/test.dir/littlefs-lib/pico_hal.c.obj" "gcc" "CMakeFiles/test.dir/littlefs-lib/pico_hal.c.obj.d"
  "/Users/jonah/pico/pcbrock/eurorack-RTC/firm-1.2/stdinit-lib/stdinit.c" "CMakeFiles/test.dir/stdinit-lib/stdinit.c.obj" "gcc" "CMakeFiles/test.dir/stdinit-lib/stdinit.c.obj.d"
  "/Users/jonah/pico/pcbrock/eurorack-RTC/firm-1.2/AlgoBlocks.cpp" "CMakeFiles/test.dir/AlgoBlocks.cpp.obj" "gcc" "CMakeFiles/test.dir/AlgoBlocks.cpp.obj.d"
  "/Users/jonah/pico/pcbrock/eurorack-RTC/firm-1.2/AlgoCulture.cpp" "CMakeFiles/test.dir/AlgoCulture.cpp.obj" "gcc" "CMakeFiles/test.dir/AlgoCulture.cpp.obj.d"
  "/Users/jonah/pico/pcbrock/eurorack-RTC/firm-1.2/AlgoOver.cpp" "CMakeFiles/test.dir/AlgoOver.cpp.obj" "gcc" "CMakeFiles/test.dir/AlgoOver.cpp.obj.d"
  "/Users/jonah/pico/pcbrock/eurorack-RTC/firm-1.2/AlgoPlain.cpp" "CMakeFiles/test.dir/AlgoPlain.cpp.obj" "gcc" "CMakeFiles/test.dir/AlgoPlain.cpp.obj.d"
  "/Users/jonah/pico/pcbrock/eurorack-RTC/firm-1.2/AlgoReich.cpp" "CMakeFiles/test.dir/AlgoReich.cpp.obj" "gcc" "CMakeFiles/test.dir/AlgoReich.cpp.obj.d"
  "/Users/jonah/pico/pcbrock/eurorack-RTC/firm-1.2/AlgoSparse.cpp" "CMakeFiles/test.dir/AlgoSparse.cpp.obj" "gcc" "CMakeFiles/test.dir/AlgoSparse.cpp.obj.d"
  "/Users/jonah/pico/pcbrock/eurorack-RTC/firm-1.2/AlgoVari.cpp" "CMakeFiles/test.dir/AlgoVari.cpp.obj" "gcc" "CMakeFiles/test.dir/AlgoVari.cpp.obj.d"
  "/Users/jonah/pico/pcbrock/eurorack-RTC/firm-1.2/AlgoWonk.cpp" "CMakeFiles/test.dir/AlgoWonk.cpp.obj" "gcc" "CMakeFiles/test.dir/AlgoWonk.cpp.obj.d"
  "/Users/jonah/pico/pcbrock/eurorack-RTC/firm-1.2/Clock.cpp" "CMakeFiles/test.dir/Clock.cpp.obj" "gcc" "CMakeFiles/test.dir/Clock.cpp.obj.d"
  "/Users/jonah/pico/pico-sdk/src/rp2_common/pico_standard_link/new_delete.cpp" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_standard_link/new_delete.cpp.obj" "gcc" "CMakeFiles/test.dir/Users/jonah/pico/pico-sdk/src/rp2_common/pico_standard_link/new_delete.cpp.obj.d"
  "/Users/jonah/pico/pcbrock/eurorack-RTC/firm-1.2/jfunc.cpp" "CMakeFiles/test.dir/jfunc.cpp.obj" "gcc" "CMakeFiles/test.dir/jfunc.cpp.obj.d"
  "/Users/jonah/pico/pcbrock/eurorack-RTC/firm-1.2/main.cpp" "CMakeFiles/test.dir/main.cpp.obj" "gcc" "CMakeFiles/test.dir/main.cpp.obj.d"
  )

# Targets to which this target links.
set(CMAKE_TARGET_LINKED_INFO_FILES
  )

# Fortran module output directory.
set(CMAKE_Fortran_TARGET_MODULE_DIR "")
