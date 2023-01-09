MCU_LDSCRIPT = jumploader_SN32F240B
PLATFORMSRC += $(CHIBIOS)/os/hal/ports/common/ARMCMx/nvic.c $(CHIBIOS_CONTRIB)/os/hal/ports/SN32/SN32F240B/hal_lld.c
PLATFORMINC += $(CHIBIOS)/os/hal/ports/common/ARMCMx ${CHIBIOS_CONTRIB}/os/hal/ports/SN32/LLD/SN32F2xx $(CHIBIOS_CONTRIB)/os/hal/ports/SN32/SN32F240B