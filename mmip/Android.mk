MMIP_modules += score

ifeq ($(BOARD_USES_OPENVX),true)
	MMIP_modules += libiva
endif

include $(call all-named-subdir-makefiles,$(MMIP_modules))
