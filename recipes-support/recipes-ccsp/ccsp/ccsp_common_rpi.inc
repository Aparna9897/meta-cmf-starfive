SUMMARY = "common inc for Raspberry Pi"

# It is assumed that all recipes including this inc file have
# included meta-rdk/recipes-ccsp/ccsp/ccsp_common.inc

#require meta-rdk/recipes-ccsp/ccsp/ccsp_common.inc

CFLAGS_append += "-U_COSA_SIM_ -fno-exceptions -ffunction-sections -fdata-sections -fomit-frame-pointer -fno-strict-aliasing \
           -D_ANSC_LINUX -D_ANSC_USER -D_ANSC_LITTLE_ENDIAN_ -D_CCSP_CWMP_TCP_CONNREQ_HANDLER \
           -D_DSLH_STUN_ -D_NO_PKI_KB5_SUPPORT -D_BBHM_SSE_FILE_IO -D_ANSC_USE_OPENSSL_ -DENABLE_SA_KEY \
           -D_ANSC_AES_USED_ -D_COSA_INTEL_USG_ARM_ -D_COSA_FOR_COMCAST_ -D_NO_EXECINFO_H_ -DFEATURE_SUPPORT_SYSLOG \
           -DBUILD_WEB -D_NO_ANSC_ZLIB_ -D_DEBUG -U_ANSC_IPV6_COMPATIBLE_ -D_COSA_BCM_ARM_ -DUSE_NOTIFY_COMPONENT \
           -D_PLATFORM_RASPBERRYPI_ -DENABLE_SD_NOTIFY -UPARODUS_ENABLE  -U_INCLUDE_BREAKPAD \
	   -DCONFIG_VENDOR_CUSTOMER_COMCAST -DHAVE_ERR_GET_ERROR_ALL"

CFLAGS_append += "${@bb.utils.contains('DISTRO_FEATURES', 'rdkb_wan_manager', ' -DFEATURE_RDKB_WAN_MANAGER ', '', d)}"	   
CFLAGS_append += "${@bb.utils.contains('DISTRO_FEATURES', 'meshwifi', ' -DENABLE_FEATURE_MESHWIFI ', '', d)}"	   
CFLAGS_append_aarch64 = " -D_64BIT_ARCH_SUPPORT_ "


LDFLAGS_append = " -lpthread -lcrypto"
LDFLAGS_append = "${@bb.utils.contains('DISTRO_FEATURES', 'dunfell', ' -lsafec-3.5.1',' -lsafec',d)}"

#CFLAGS_append = " -DFEATURE_SUPPORT_RDKLOG"
CFLAGS_append = " -UINCLUDE_BREAKPAD"
