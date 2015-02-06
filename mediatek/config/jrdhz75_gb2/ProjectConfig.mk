AUTO_ADD_GLOBAL_DEFINE_BY_NAME = MTK_LCA_SUPPORT MTK_WAPI_SUPPORT MTK_SENSOR_SUPPORT CUSTOM_KERNEL_ALSPS CUSTOM_KERNEL_MAGNETOMETER CUSTOM_KERNEL_ACCELEROMETER MTK_TVOUT_SUPPORT MTK_BT_SUPPORT MTK_FM_SUPPORT MTK_CAMERA_APP_3DHW_SUPPORT MTK_QVGA_LANDSCAPE_SUPPORT MTK_WLANBT_SINGLEANT MTK_FM_TX_SUPPORT MTK_VT3G324M_SUPPORT MTK_M4U_SUPPORT MTK_MATV_ANALOG_SUPPORT MTK_WLAN_SUPPORT MTK_BT_21_SUPPORT MTK_BT_30_SUPPORT MTK_BT_40_SUPPORT MTK_BT_FM_OVER_BT_VIA_CONTROLLER MTK_BT_PROFILE_OPP MTK_BT_PROFILE_SIMAP MTK_BT_PROFILE_PRXM MTK_BT_PROFILE_PRXR MTK_BT_PROFILE_HIDH MTK_BT_PROFILE_FTP MTK_BT_PROFILE_PBAP MTK_BT_PROFILE_MANAGER MTK_BT_PROFILE_BPP MTK_BT_PROFILE_BIP MTK_BT_PROFILE_DUN MTK_BT_PROFILE_PAN MTK_BT_PROFILE_HFP MTK_BT_PROFILE_A2DP MTK_BT_PROFILE_AVRCP MTK_BT_PROFILE_AVRCP14 MTK_BT_PROFILE_TIMEC MTK_BT_PROFILE_TIMES MTK_BT_PROFILE_MAPS MTK_BT_PROFILE_MAPC MTK_BT_PROFILE_SPP MTK_FM_SHORT_ANTENNA_SUPPORT MTK_DUAL_MIC_SUPPORT MTK_DIGITAL_MIC_SUPPORT MTK_WIFI_HOTSPOT_SUPPORT MTK_CTA_SUPPORT MTK_FM_SUPPORT MTK_GPS_SUPPORT MTK_DSPIRDBG HAVE_XLOG_FEATURE MTK_AUTO_DETECT_MAGNETOMETER MTK_AUTO_DETECT_ACCELEROMETER MTK_MAV_SUPPORT MTK_HDR_SUPPORT MTK_CAMERA_BSP_SUPPORT CUSTOM_KERNEL_GYROSCOPE MTK_AUTORAMA_SUPPORT MTK_IPV6_SUPPORT MTK_MULTI_STORAGE_SUPPORT CUSTOM_KERNEL_OFN MTK_FM_RECORDING_SUPPORT MTK_USES_HD_VIDEO MTK_NFC_SUPPORT MTK_THEMEMANAGER_APP MTK_BRAZIL_CUSTOMIZATION MTK_BRAZIL_CUSTOMIZATION_CLARO MTK_BRAZIL_CUSTOMIZATION_VIVO MTK_RMVB_PLAYBACK_SUPPORT MTK_ASF_PLAYBACK_SUPPORT MTK_EMMC_SUPPORT MTK_HDMI_SUPPORT MTK_2SDCARD_SWAP MTK_FAT_ON_NAND MTK_FAN5405_SUPPORT MTK_COMBO_QUICK_SLEEP_SUPPORT MTK_COMBO_CORE_DUMP_SUPPORT MTK_PRODUCT_INFO_SUPPORT











AUTO_ADD_GLOBAL_DEFINE_BY_VALUE = MTK_PLATFORM MTK_FM_CHIP MTK_BT_CHIP CUSTOM_KERNEL_MAIN_IMGSENSOR CUSTOM_KERNEL_MAIN_BACKUP_IMGSENSOR CUSTOM_KERNEL_SUB_IMGSENSOR CUSTOM_KERNEL_SUB_BACKUP_IMGSENSOR CUSTOM_KERNEL_MAIN_LENS CUSTOM_KERNEL_MAIN_BACKUP_LENS CUSTOM_KERNEL_SUB_LENS CUSTOM_KERNEL_SUB_BACKUP_LENS MTK_FM_AUDIO MTK_ATV_CHIP MTK_GPS_CHIP MTK_WLAN_CHIP MTK_MODEM_SUPPORT CUSTOM_KERNEL_LCM CUSTOM_KERNEL_FLASHLIGHT MTK_COMBO_CHIP










AUTO_ADD_GLOBAL_DEFINE_BY_NAME_VALUE = LCM_WIDTH LCM_HEIGHT MTK_LCM_PHYSICAL_ROTATION MTK_SHARE_MODEM_SUPPORT MTK_SHARE_MODEM_CURRENT EMMC_CHIP












#
# MTK Build System
#
BUILD_KERNEL = yes
	# default settings: yes for target; else no (e.g. emulator)
	# candidate settings: yes; no
	# used for MTK build system

BUILD_PRELOADER = yes
	# default settings: yes for target; else no (e.g. emulator)
	# candidate settings: yes; no
	# used for MTK build system

BUILD_UBOOT = yes
	# default settings: yes for target; else no (e.g. emulator)
	# candidate settings: yes; no
	# used for MTK build system

CUSTOM_MODEM=jrdhz75_hspa
#
# Customize for PRELOADER
#
CUSTOM_PRELOADER_CUSTOM = custom


#
# Customize for UBOOT
#
CUSTOM_UBOOT_LCM = ili9486_6575_dsi
LCM_WIDTH = 320

LCM_HEIGHT = 480
BOOT_LOGO = hvga
#
# Customize for HAL
#
CUSTOM_HAL_AUDIOFLINGER = audio

CUSTOM_HAL_BLUETOOTH = bluetooth

CUSTOM_HAL_CAMERA = camera

CUSTOM_HAL_EEPROM = dummy_eeprom

CUSTOM_HAL_FLASHLIGHT = dummy_flashlight

# temp solution for custom folder
CUSTOM_HAL_IMGSENSOR = hi253_yuv s5k5cagx_yuv 
CUSTOM_KERNEL_IMGSENSOR = hi253_yuv s5k5cagx_yuv 
CUSTOM_HAL_LENS = dummy_lens
CUSTOM_KERNEL_LENS = dummy

CUSTOM_HAL_MAIN_LENS = dummy_lens

CUSTOM_HAL_MAIN_BACKUP_LENS = 

CUSTOM_HAL_SUB_LENS = 

CUSTOM_HAL_SUB_BACKUP_LENS =

CUSTOM_HAL_MAIN_IMGSENSOR = hi253_yuv

CUSTOM_HAL_MAIN_BACKUP_IMGSENSOR = s5k5cagx_yuv

CUSTOM_HAL_SUB_IMGSENSOR = 

CUSTOM_HAL_SUB_BACKUP_IMGSENSOR = 

CUSTOM_HAL_COMBO = mt6628

CUSTOM_HAL_FMRADIO = mt6628

#
# Customize for Kernel
#
CUSTOM_KERNEL_HEADSET = accdet

CUSTOM_KERNEL_FM = mt6628

CUSTOM_KERNEL_CAMERA = camera

CUSTOM_KERNEL_BATTERY = battery

CUSTOM_KERNEL_SOUND = amp_yad

CUSTOM_KERNEL_CORE = src
	# default settings: src
	# candidate settings: src
	# board configuation. .

CUSTOM_KERNEL_DCT = dct

CUSTOM_KERNEL_EEPROM = dummy_eeprom

CUSTOM_KERNEL_FLASHLIGHT = dummy_flashlight

CUSTOM_KERNEL_JOGBALL = 

CUSTOM_KERNEL_KPD = kpd
	# default settings: kpd
	# candidate settings: kpd
	# For Keypad

CUSTOM_KERNEL_LCM = ili9486_6575_dsi

CUSTOM_KERNEL_LEDS = mt65xx

CUSTOM_KERNEL_MAIN_LENS = dummy


CUSTOM_KERNEL_OFN = 

CUSTOM_KERNEL_MAIN_BACKUP_LENS = 

CUSTOM_KERNEL_SUB_LENS = dummy_lens

CUSTOM_KERNEL_SUB_BACKUP_LENS =

CUSTOM_KERNEL_MAIN_IMGSENSOR = hi253_yuv

CUSTOM_KERNEL_MAIN_BACKUP_IMGSENSOR = s5k5cagx_yuv

CUSTOM_KERNEL_SUB_IMGSENSOR = 

CUSTOM_KERNEL_SUB_BACKUP_IMGSENSOR =

#CUSTOM_KERNEL_SOUND = amp_6329pmic_spk

CUSTOM_KERNEL_TOUCHPANEL = msg2133
	# default settings: generic
	# candidate settings: generic;eeti_pcap7200
	# select the panel used by certain project.

CUSTOM_KERNEL_USB = mt6575

CUSTOM_KERNEL_WIFI =

CUSTOM_KERNEL_RTC = rtc
        # default settings: rtc
        # candidate settings: rtc
        # For RTC

# Android sensor device
MTK_SENSOR_SUPPORT = yes

MTK_AUTO_DETECT_ACCELEROMETER = yes

MTK_AUTO_DETECT_MAGNETOMETER = no

CUSTOM_KERNEL_MAGNETOMETER = no

CUSTOM_KERNEL_ACCELEROMETER = kxtj2 bma222e

CUSTOM_KERNEL_ALSPS = tmd2772

CUSTOM_KERNEL_GYROSCOPE = no

CUSTOM_HAL_SENSORS = sensor

#CUSTOM_HAL_MSENSORLIB = yamaha532

#
# Misc
#
EVB = no
	# default settings: yes for evb; else no
	# candidate settings: yes/no
	# For EVB used

GEMINI=yes
	# default settings: no
	# candidate settings: yes/no
	# For gemini;currently no projects is set gemini on

MTK_GEMINI_ENHANCEMENT=yes
	# default settings: no
	# candidate settings: yes/no
	# If project could use gemini modem, this value should be yes

OPTR_SPEC_SEG_DEF = NONE
	# default settings: NONE

#
# MTK Specified Feature
#
HAVE_AEE_FEATURE = yes

HAVE_APPC_FEATURE = no

HAVE_MATV_FEATURE = no

#
# MTK Chip
#
MTK_BT_CHIP = MTK_MT6628
	# candidate settings: MTK_MT6611/MTK_MT6612/MTK_MT6616/MTK_MT6620

MTK_CHIP_VER = S01
	# default settings: S01
	# candidate settings: S01
	# S01 for MT6516

MTK_FM_CHIP = MT6628_FM
	# candidate settings: AR1000_FM/MT6616_E3_FM/MT6620_FM

MTK_ATV_CHIP =

MTK_WLAN_CHIP = MT6628

MTK_COMBO_CHIP = MT6628

#MTK_COMBO_QUICK_SLEEP_SUPPORT = yes

#MTK_COMBO_CORE_DUMP_SUPPORT = yes

MTK_PLATFORM = MT6575
	# default settings: MT6516
	# candidate settings: MT6516
	# MT6516 is available

#
# MTK APP
#
MTK_GALLERY3D_APP = yes

MTK_INPUTMETHOD_PINYINIME_APP = yes

#modified by bing.wang.hz for FR339545 begin
MTK_GALLERY_APP = no
#modified by bing.wang.hz for FR339545 end

MTK_CAMERA_APP = yes

MTK_ENGINEERMODE_APP = yes

MTK_YGPS_APP = yes

MTK_LIVEWALLPAPER_APP = gles20

MTK_DATADIALOG_APP = no

MTK_FMRADIO_APP = yes

MTK_AGPS_APP = yes

MTK_ACWFDIALOG_APP = yes


MTK_LAUNCHERPLUS_APP = yes

MTK_SOUNDRECORDER_APP = no

MTK_DM_APP = no

MTK_ANDROIDFACTORYMODE_APP = yes

MTK_VIDEOWIDGET_APP = yes


#
# MTK SUPPORT
#

MTK_TVOUT_SUPPORT = no

MTK_SNS_SUPPORT = no

MTK_LCA_SUPPORT = no

MTK_WAPI_SUPPORT = yes

MTK_WLAN_SUPPORT = yes

MTK_BT_SUPPORT = yes

MTK_FM_SUPPORT = yes

MTK_FM_TX_SUPPORT = no

MTK_FM_AUDIO = FM_ANALOG_INPUT

MTK_FM_SHORT_ANTENNA_SUPPORT = no

MTK_CAMERA_APP_3DHW_SUPPORT = yes

MTK_SMS_NATIONAL_LANGUAGE_SUPPORT = no

MTK_SMS_TURKISH_TABLE_ALWAYS_SUPPORT = yes

MTK_WAPPUSH_SUPPORT = yes

MTK_WLANBT_SINGLEANT = no

MTK_QVGA_LANDSCAPE_SUPPORT = no

MTK_LCM_PHYSICAL_ROTATION = 0
  # set this value as 90 if the lcm is physically rotated on the device

MTK_SCREEN_OFF_WIFI_OFF = no

#modify by liang.zhang for remove all feature about video call
MTK_VT3G324M_SUPPORT=no

MTK_M4U_SUPPORT = yes

MTK_MT519X_FM_SUPPORT = no

MTK_LOCKSCREEN_TYPE = 3
  # default=1, slide=2, JrdLockScreen=3

MTK_MATV_ANALOG_SUPPORT = no
   # For I2S, use: no
   # For Audio Line-in, use: yes

# add for IME feature
MTK_IME_HANDWRITING_ENGINE = none
MTK_IME_INPUT_ENGINE = none
MTK_IME_SUPPORT = no

MTK_IME_ENGLISH_SUPPORT = yes

MTK_IME_PINYIN_SUPPORT = yes

MTK_IME_STROKE_SUPPORT = yes

MTK_IME_ZHUYIN_SUPPORT = yes

MTK_IME_HANDWRITING_SUPPORT = yes

MTK_HEADSET_ICON_SUPPORT = no

MTK_OMA_DOWNLOAD_SUPPORT = yes

MTK_SMARTSWITCH_SUPPORT = no

MTK_IPO_SUPPORT = yes

MTK_GPS_SUPPORT = yes

RESOURCE_OVERLAY_SUPPORT = 

MTK_OMACP_SUPPORT = yes


MTK_BT_30_HS_SUPPORT = yes

MTK_GPS_CHIP = MTK_GPS_MT6628

MTK_GOOGLEOTA_SUPPORT = no

####config BT feature###########
# please do not modify these options

MTK_BT_21_SUPPORT = yes

MTK_BT_30_SUPPORT = yes

MTK_BT_40_SUPPORT = yes

MTK_BT_FM_OVER_BT_VIA_CONTROLLER = no

MTK_BT_PROFILE_OPP = yes

MTK_BT_PROFILE_SIMAP = yes

MTK_BT_PROFILE_PRXM = yes

MTK_BT_PROFILE_PRXR = yes

MTK_BT_PROFILE_HIDH = yes

MTK_BT_PROFILE_FTP = yes

MTK_BT_PROFILE_PBAP = yes

MTK_BT_PROFILE_MANAGER = yes

MTK_BT_PROFILE_BPP = yes

MTK_BT_PROFILE_BIP = yes

MTK_BT_PROFILE_DUN = yes

MTK_BT_PROFILE_PAN = yes

MTK_BT_PROFILE_HFP = yes

MTK_BT_PROFILE_A2DP = yes

MTK_BT_PROFILE_AVRCP = yes

MTK_BT_PROFILE_AVRCP14 = yes

MTK_BT_PROFILE_TIMEC = no

MTK_BT_PROFILE_TIMES = no

MTK_BT_PROFILE_MAPS = yes

MTK_BT_PROFILE_MAPC = yes

MTK_BT_PROFILE_SPP = yes

####config BT feature end ####

MTK_DM_CU_SERVER_SUPPORT = no

MTK_DM_CMCC_SERVER_SUPPORT = no

MTK_SEARCH_DB_SUPPORT = yes

MTK_DIALER_SEARCH_SUPPORT = yes

MTK_WIFI_P2P_SUPPORT = yes

MTK_MDLOGGER_SUPPORT = yes

MTK_SNS_KAIXIN_APP = no

MTK_SNS_RENREN_APP = no

MTK_SNS_FACEBOOK_APP = no

MTK_SNS_FLICKR_APP = no

MTK_SNS_TWITTER_APP = no

MTK_IME_FRENCH_SUPPORT = no

MTK_IME_GERMAN_SUPPORT = no

MTK_IME_SPANISH_SUPPORT = no

MTK_IME_ITALIAN_SUPPORT = no

MTK_IME_PORTUGUESE_SUPPORT = no

MTK_IME_TURKISH_SUPPORT = no

MTK_IME_MALAY_SUPPORT = no

MTK_IME_HINDI_SUPPORT = no

MTK_IME_ARABIC_SUPPORT = no

MTK_IME_THAI_SUPPORT = no

MTK_IME_VIETNAM_SUPPORT = no

MTK_IME_INDONESIAN_SUPPORT = no

MTK_FILEMANAGER_APP = yes

MTK_TTY_SUPPORT = yes

MTK_NAND_PAGE_SIZE = 4K

# Enable dual mic support
MTK_DUAL_MIC_SUPPORT = no
MTK_DIGITAL_MIC_SUPPORT = no

MTK_WPA2PSK_SUPPORT = no

MTK_APKINSTALLER_APP = no

MTK_WIFI_HOTSPOT_SUPPORT = yes

MTK_CTA_SUPPORT = no

MTK_SMSREG_APP = no


MTK_MFV_MPEG4_EXTRA = no

MTK_VLW_APP = no

MTK_MODEM_SUPPORT=modem_3g

MTK_RESOURCE_OPTIMIZATION = 

MTK_VIDEOPLAYER_APP = no

MTK_INTERNAL = no

MTK_THEMEMANAGER_APP = no

MTK_INTERNAL_LANG_SET = no

MTK_FOTA_RELEASE = no

MTK_DM_RELEASE = no

MTK_EXLOG2MAIL_APP = no

MTK_CALENDAR_IMPORTER_APP = yes

CUSTOM_HAL_ANT = mt6628_ant_m1

MTK_IME_RUSSIAN_SUPPORT = no

MTK_DSPIRDBG = no

MTK_SEC_USBDL = ATTR_SUSBDL_ONLY_ENABLE_ON_SCHIP
MTK_SEC_CHIP_SUPPORT = no

MTK_SEC_BOOT = ATTR_SBOOT_ONLY_ENABLE_ON_SCHIP

MTK_SEC_MODEM_ENCODE = no

MTK_SEC_MODEM_AUTH = no

MTK_FOTA_SUPPORT = no

MTK_PHONE_VT_MM_RINGTONE = no

MTK_PHONE_VT_VOICE_ANSWER = no

MTK_PHONE_VOICE_RECORDING = yes

#fix FR 326557 by long.xie.hz, support lyrics on music player begin
MTK_MUSIC_LRC_SUPPORT = yes
#fix FR 326557 by long.xie.hz, support lyrics on music player end

MTK_FD_SUPPORT=yes

MTK_SNS_SINAWEIBO_TEST = no

MTK_DM_ENTRY_DISPLAY = no


MTK_DRM_APP = yes

HAVE_XLOG_FEATURE = yes


MTK_SMS_FILTER_SUPPORT = yes

MTK_RTP_OVER_RTSP_SUPPORT = yes

MTK_SPECIAL_FACTORY_RESET = no

CUSTOM_HAL_MATV =

CUSTOM_KERNEL_MATV =

MTK_MAV_SUPPORT = yes



MTK_HDR_SUPPORT = yes

MTK_CAMERA_BSP_SUPPORT = yes


MTK_GEMINI_3G_SWITCH=yes

MTK_DITHERING_SUPPORT = no

MTK_WEATHER_PROVIDER_APP = yes

MTK_LOG2SERVER_APP = no

MTK_AUTORAMA_SUPPORT = yes

MTK_PRODUCT_LOCALES = en_US es_ES zh_CN zh_TW ru_RU pt_BR fr_FR de_DE tr_TR it_IT in_ID ms_MY vi_VN ar_EG  th_TH  pt_PT   nl_NL mdpi

MTK_VIDEOPLAYER2_APP = yes


MTK_IPV6_SUPPORT = no


MTK_USES_STAGEFRIGHT_DEFAULT_CODE = no

MTK_WB_SPEECH_SUPPORT = yes

HAVE_AWBENCODE_FEATURE = yes

HAVE_AACENCODE_FEATURE = yes

#zhen.ma modify for 360469
MTK_MULTI_STORAGE_SUPPORT = no


MTK_EMULATOR_SUPPORT = no


MTK_SHARE_MODEM_SUPPORT = 2


MTK_SHARE_MODEM_CURRENT=2





MTK_EAP_SIM_AKA = no

MTK_NFC_SUPPORT = no

MTK_NEW_IPTABLES_SUPPORT = yes

MTK_ASD_SUPPORT = yes


MTK_EMMC_SUPPORT = no
EMMC_CHIP=

MTK_FM_RECORDING_SUPPORT = yes


MTK_USES_HD_VIDEO = yes


MTK_AVI_PLAYBACK_SUPPORT = yes

MTK_AUDIO_APE_SUPPORT = yes

MTK_SIGNATURE_CUSTOMIZATION = no


MTK_WML_SUPPORT = no

MTK_FLV_PLAYBACK_SUPPORT = no


MTK_GPU_CHIP = SGX351_110

MTK_LAUNCHER_ALLAPPSGRID = no

MTK_TB_APP_LANDSCAPE_SUPPORT = no


HAVE_VORBISENC_FEATURE = yes

MTK_BRAZIL_CUSTOMIZATION_TIM = no

MTK_FD_FORCE_REL_SUPPORT=yes


MTK_SNS_SINAWEIBO_APP = no



MTK_BRAZIL_CUSTOMIZATION = no

MTK_BRAZIL_CUSTOMIZATION_CLARO = no


MTK_BRAZIL_CUSTOMIZATION_VIVO = no

MTK_SEND_RR_SUPPORT = yes


MTK_RMVB_PLAYBACK_SUPPORT = no


MTK_ASF_PLAYBACK_SUPPORT = no

MTK_75DISPLAY_ENHANCEMENT_SUPPORT = no


MTK_WEATHER_WIDGET_APP = yes




HAVE_SRSAUDIOEFFECT_FEATURE = no


MTK_HDMI_SUPPORT = no




# MTK_PRODUCT_INFO_SUPPORT = yes


MTK_RELEASE_PACKAGE=rel_customer_basic


MTK_FAN5405_SUPPORT = no


# add by susheng.ye for FR 389329 begin
CUSTOM_DRAM_SIZE=2G
# add by susheng.ye for FR 389329 end
