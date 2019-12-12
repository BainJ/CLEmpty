//
//  CLCameraExtraSettings.h

#import "CLScheduleInfo.h"

#define KEY_CAMERA_TITLE                   @"keyCameraTitle"
#define KEY_CAMERA_DESCRIPTION             @"keyCameraDescription"
#define KEY_CAMERA_STATUS                  @"keyCameraStatus"
#define KEY_VOLUME_MUTE                    @"keyVolumeMute"
#define KEY_SCHEDULE_TURNOFF               @"keyScheduleTurnOff"
#define KEY_SCHEDULE_NOTUPLOAD             @"keyScheduleNotUpload"
#define KEY_SCHEDULE_MUTE                  @"keyScheduleMute"
#define KEY_DVRPLAN                        @"keyDVRPlan"
#define KEY_MOTION_DETECTION               @"keyMotionDetection"
#define KEY_MOTION_SENSITIVITY             @"keyMotionSensitivity"
#define KEY_MOTION_SENSITIVITY_SUPPORT_KEY     @"keyMotionSensitivitySupportKey"
#define KEY_SOUND_DETECTION                @"keySoundDetection"
#define KEY_SOUND_SENSITIVITY              @"keySoundSensitivity"
#define KEY_FACE_DETECTION                 @"keyFaceDetection"
#define KEY_FACE_SENSITIVITY               @"keyFaceSensitivity"
#define KEY_PEOPLE_Detection               @"keyPeopleDetection"
#define KEY_RECORD_TO                      @"keyRecordTo"
#define KEY_INFRARED_LIGHT                 @"keyInfraredLight"
#define KEY_SCHEDULE_INFRARED_LIGHT        @"keyScheduleInfraredLight"
#define KEY_NIGHT_VISION                   @"keyNightVision"
#define KEY_SCHEDULE_NIGHT_VISION          @"keyScheduleNightVision"
#define KEY_CLOUD_RECORD                   @"keyCloudRecord"
#define KEY_SCHEDULE_CLOUD_RECORD          @"keyScheduleCloudRecord"
#define KEY_STATUS_LIGHT                   @"keyStatusLight"
#define KEY_HDVIDEO                        @"keyHDVideo"
#define KEY_HDVIDEOAUTO                    @"keyHDVideoType"
#define KEY_BK_AUDIOSTREAMING              @"keyBKAudioStreaming"
#define KEY_TIMEZONE                       @"keyTimeZone"
#define KEY_WIFI_NETWORK                   @"keyWifiNetwork"
#define KEY_DEVICEID                       @"keyDeviceID"
#define KEY_MACADDRESS                     @"keyMacAddress"
#define KEY_DEVICE_TYPE                    @"keyDeviceType"
#define KEY_VIDEO_QUALITY                  @"keyVideoQuality"
#define KEY_ZOOMSCALE                      @"keyZoomScale"
#define KEY_CAMERA_SOUND                   @"keyCameraSound"
#define KEY_ANTIFLICKER                    @"keyAntiFlicker"
#define KEY_CAMERA_IMAGE_ROTATE            @"keyCame11raImageRotate"
#define KEY_CAMERA_IMAGE_ROTATE_SUPPORT_KEY            @"keyCameraImageRotateSupportKey"
#define KEY_MOTION_REGIONS                 @"keyMotionRegions"
#define KEY_MOTION_REGIONS_SUPPORT_KEY     @"keyMotionRegionsSupportKey"
#define KEY_NOTIFICATION_INTERVAL          @"keyNotificationInterval"
#define KEY_SEND_ALERTS                    @"keySendAlerts"
#define KEY_SEND_MOTION_ALERTS             @"keySendMotionAlerts"
#define KEY_SEND_SOUND_ALERTS              @"keySendSoundAlerts"
#define KEY_SEND_OFFLINE_ALERTS            @"keySendOfflineAlerts"
#define KEY_SCHEDULE_NOT_SEND_ALERTS       @"keyScheduleNotSendAlerts"
#define KEY_MAGICZOOM                      @"keyMagicZoom"
#define KEY_EMAIL_NOTIFICATION             @"keyEmailNotification"
#define KEY_PHONE_NOTIFICATION             @"keyPhoneNotification"
#define KEY_NIGHT_SENSITIVITY              @"keyNightSensitivity"
#define KEY_OFFLINECONFIG                  @"keyOfflineConfig"
#define KEY_TEMPERATURE                    @"keyTemperature"
#define KEY_FISHEYE                       @"FISHEYE"
#define KEY_FISHEYE_InstallPos            @"keyFisheyeInstallPos"
#define KEY_ALARMBUZZ                     @"keyAlarmbuzz"
#define KEY_DEVICELENSPTZ                 @"keyDeviceLensPTZ"
#define KEY_SDCARD                        @"keySdcard"
#define KEY_VIEW_TIMELINE                 @"keyViewTimeLine"
#define KEY_REBOOT                        @"keyReboot"
#define KEY_TIMEOSD                       @"timeOSD"

typedef NS_ENUM(NSUInteger, AS_ProfileStatus) {
    Profile_Status_Off,
    Profile_Status_On,
    Profile_Status_Auto,
    Profile_Status_OffBySchedule,
    Profile_Status_OffByManual,
    Profile_Status_OffUpdate,
    Profile_Status_OffByLBS
};

typedef NS_ENUM(NSUInteger, CLXVideoQualityType) {
    CLXVideoQuality_SD,
    CLXVideoQuality_HD,
    CLXVideoQuality_AUTO,
};

typedef NS_ENUM(NSUInteger, CLXNIGHTMODE_TYPE) {
    CLXNIGHTMODE_OFF,
    CLXNIGHTMODE_ON,
    CLXNIGHTMODE_AUTO,
};

typedef NS_ENUM(NSUInteger, CLXROTATEIMAGE_TYPE) {
    CLXROTATEIMAGE_NONE = 0,
    CLXROTATEIMAGE_90 = 90,
    CLXROTATEIMAGE_180 = 180,
    CLXROTATEIMAGE_270 = 270,
};

/**
 *  @brief CLCameraExtraSettings 包含摄像头的一些特殊信息，比如摄像头名字，是否支持运动、声音检测，清晰度等等
 */
@interface CLCameraExtraSettings : NSObject

/*! @cond PRIVATE */

///Camera name
@property (nonatomic, copy) NSString *name;
///Camera Turn on/off
@property (nonatomic, assign) BOOL bTurnOn;
///Camera status
@property (nonatomic, assign) int status;

///If support motion detection notification, it just mean not to send notification, but detect still take effect.
@property (nonatomic, assign) BOOL bMotionDetect;
//FaceDetection
@property (nonatomic, assign) BOOL bFaceDetection;
///Sensitive for motion detection, should between 0 to 100
@property (nonatomic, assign) int nMotionSensitive;

///If support sound detection notification, it just mean not to send notification, but detect still take effect.
@property (nonatomic, assign) BOOL bSoundDetect;
///Sensitive for sound detection, should between 0 to 100
@property (nonatomic, assign) int nSoundSensitive;
@property (nonatomic, strong) NSArray * nSoundSensitiveAndLevel;
///If support micro phone of camera
@property (nonatomic, assign) BOOL cameraMicrophone;
///If support email alerts
@property (nonatomic, assign) BOOL emailAlerts;
///camera night mode, 0-off, 1-on, 2-auto
@property (nonatomic, assign) int nightMode;
///If led of camera on or off
@property (nonatomic, assign) BOOL ledLight;

///Switch between HD(720P)/SD(VGA), 0-off(SD), 1-on(HD), 2-auto
@property (nonatomic, assign) int HDVideo;
///Video quality, value:VIDEO_QUALITY_LOW(qvga)=1, VIDEO_QUALITY_MEDIUM(vga)=2, VIDEO_QUALITY_HIGH(720p)=3(default) or VIDEO_QUALITY_VHIGH(1080p)=4.
///NOTICE: UNAVAILABLE FOR MYFOX
@property (nonatomic, assign) long videoQuality;

/// Specifies a type that setting camera's timezone. Param should be
///     [NSTimeZone description];
/// Since you get full descritiopn @"Europe/Paris (GMT+1) offset 3600"
///     please pass @"Europe/Paris" or Abbreviation presentation(@"CEST") as the time zone value.
/// Get all available abbreviations, call [NSTimeZone abbreviationDictionary].
@property (nonatomic, copy) NSString *cameraTimeZone;
///Anti Flicker Frequency, 50 or 60HZ
@property (nonatomic, assign) int nFrequency;
///0 or 180 degree
@property (nonatomic, assign) int rotateDegree;

///If support cloud record
@property (nonatomic, assign) BOOL cloudRecord;
///Schedule to record on cloud, CLScheduleInfo * in it
@property (nonatomic, strong) NSArray *scheduleCloudRecord;

///Schedule to turn camera off, CLScheduleInfo * in it
@property (nonatomic, strong) NSArray *scheduleTurnOff;
///Schedule to turn motion dectection notification off, CLScheduleInfo * in it
@property (nonatomic, strong) NSArray *scheduleStopNotification;
///Schedule to mute camera, CLScheduleInfo * in it
@property (nonatomic, strong) NSArray *scheduleMute;
@property (nonatomic, strong) NSArray *scheduleInfraredLight;
@property (nonatomic, strong) NSArray *scheduleNightVisionOn;
@property (nonatomic, strong) NSArray *scheduleNotSendAlerts;
///Array to set motion region, CLMotionRegion * in it
///     if enable in CLMotionRegion is 0, valid motion region capacity is 3, else 4.
@property (nonatomic, strong) NSArray *motionRegions;

///zoom ratio for the camera to set. 1000<=value<=4000(default:1000), you must set magicZoomXOffset and magicZoomYOffset simultaneously
@property (nonatomic, assign) int magicZoomRatio;
///X offset of zoom of the camera(origin top left). value:0-1000(default:0), you must set magicZoomRatio and magicZoomYOffset simultaneously
@property (nonatomic, assign) int magicZoomXOffset;
///Y offset of zoom of the camera(origin top left). value:0-1000(default:0), you must set magicZoomRatio and magicZoomXOffset simultaneously
@property (nonatomic, assign) int magicZoomYOffset;

///Is mechanical shutter of the camera on, YES-Cover is opened, NO-Cover is closed.
@property (nonatomic, assign) BOOL mechanicalShutter;
///If send pir notification,
@property (nonatomic, assign) BOOL pirDetection;
///Is the power of camera is off, and the camere in battery mode.
@property (nonatomic, assign) BOOL batteryMode;
///If send tamper detection notification,
@property (nonatomic, assign) BOOL tamperDetection;
///wifi quality of the camera. value:0-100, The signal value is fetched from "nmcli dev wifi list"
@property (nonatomic, assign) int wifiQuality;
///Wifi SSID of the camera
@property (nonatomic, copy) NSString *cameraSSID;
///SelfDefine value.
@property (nonatomic, strong) NSData *userDefinedData;
//If the rich text push on/off, default off.
@property (nonatomic, assign) BOOL richText;

@property (nonatomic, copy) NSString *deviceType;//Camera model type
@property (nonatomic, assign,getter=isBuzzerOn) BOOL buzzerON;
@property (nonatomic, assign) NSInteger buzzTime;
@property (nonatomic, assign) NSInteger recordMode; //表示录像模式，取值：1、2、3，分别表示：支持无录像、事件录像、连续录像功能，默认事件录像（2）
@property (nonatomic, assign) NSInteger sdCardStatus;

@property (nonatomic, assign) AS_ProfileStatus PFSState;//客流统计开关状态
@property (nonatomic, copy) NSString *PFSRegion;


@property bool bLED;
@property NSInteger nNightMode;//on /off /auto
@property bool bInfrared;
@property(nonatomic,copy)NSString *camDescription;//camera description string.
@property (nonatomic, assign) bool bSoundDetection;//Camera声音检测开关
@property (nonatomic, assign) NSInteger nSoundLevel;
@property (nonatomic, assign) NSInteger nMotionLevel;

@property (nonatomic, assign) bool bSendAlerts;//Camera是否发送alerts的开关
@property (nonatomic, assign) bool bMotionAlerts;//Camera是否发送motion alerts的开关
@property (nonatomic, assign) bool bSoundAlerts;//Camera是否发送sound alerts的开关
@property (nonatomic, assign) bool bOfflineAlerts;//Camera是否发送offline alerts的开关
@property (nonatomic, copy) NSString *videoRecordToWhere;//同一时间只有一个？Cloud or SDCard

@property (nonatomic, assign) NSInteger nHDVideo;////eu_Status_Auto / eu_Status_On / eu_Status_Off
@property (nonatomic, copy) NSString *cameraWifi;//Camera当前连接的路由器名称
@property (nonatomic, assign) bool bCameraSoundOn;//camera sound on/off
@property (nonatomic, assign) NSInteger cameraRotateDegree;//0 or 180 degree
@property (nonatomic, assign) NSInteger nVideoQuality;
@property (nonatomic, strong) id regionArray;
@property (nonatomic, assign) bool bCloudRecording;
@property (nonatomic, assign) NSInteger nNotiFrequency;//notification frequency.value:0,10,30,60.
@property (nonatomic, copy) NSString *supportValue;

@property (nonatomic, assign) bool phoneNotification;      //Camera是否发送phoneNotification的开关
@property (nonatomic, assign) bool emailNotification;      //Camera是否发送emailNotification的开关
@property (nonatomic, assign) NSInteger nNightVisionOpenSensitivity;
@property (nonatomic, assign) NSInteger nNightVisionCloseSensitivity;
@property (nonatomic, assign) NSInteger nNightVisionLevel;
@property (nonatomic, strong) id cameraOffSchedules;//use local time zone
@property (nonatomic, strong) id alertSchedules;//use local time zone
@property (nonatomic, assign) NSInteger nCurrentTemperature;
@property (nonatomic, assign) NSInteger isImageOn;         //定时截图开关, 0 off, 1 on
@property (nonatomic, copy) NSString *imageTimingLevel;  //定时截图频率, 详细参数对应关系见imageTimingLevels, 单位分钟
@property (nonatomic, copy) NSString *imageTimingLevels; //类似@"1=30,2=60,3=120,4=240"

@property (nonatomic, assign) BOOL playVideoInWWAN;
@property (nonatomic, assign) NSInteger fishEyeInstallPos;
@property (nonatomic, assign) NSInteger chooseTime;
@property (nonatomic, assign, getter=isFullDuplexTalkOn) NSInteger fullDuplexTalk;
@property (nonatomic, assign) BOOL supportReboot;
@property (nonatomic, copy) NSString *SDKVersion;
@property (nonatomic, assign) NSInteger viewTimeline;
@property (nonatomic, copy) NSString *mstrAutomaticCruise;
@property (nonatomic, assign) float opticalZoom; // 光学变焦
@property (nonatomic, assign) NSInteger scheduleCaptureTiming;
@property (nonatomic, assign) BOOL isTrackingOn; // 智能跟踪开关
@property (nonatomic, assign) BOOL peopleDetectionNotify; //人形检测通知开关
@property (nonatomic, copy) NSString *peopleDetection; //人形检测
@property (nonatomic, assign) BOOL timeOSD; //timeOSD开关
@property (nonatomic, assign) NSInteger acoustoOptic; //声光
@property (nonatomic, assign) NSInteger light;//灯光
/**
 * 客流统计时间表
 */
@property (nonatomic, strong) id PFSSchedules;



/*! @endcond */

+ (void)setSupport:(NSString *)supportString forProperty:(NSString *)propertyString;
- (BOOL)checkSupportForValue:(id)value supportString:(NSString *)supportString;

- (BOOL)isCameraImageRotated;
- (NSString *)getNightModeString;
- (bool)getIfSupport:(NSString *)settingType;

- (NSString *)videoTypeDisplayString;
- (void)setVideoQualityByString:(NSString *)videoQuality;
+ (NSString *)videoQualityStringByValue: (int)nValue;
- (NSString *)getMotionRegionValue;

// 和目定时截图
- (NSDictionary *)getScheduleCaptureInfoDic;

@end
