
#import <Foundation/Foundation.h>
#import "CLCameraExtraSettings.h"
#import "CLCameraUpdateInfo.h"
#import "CLXSMBDeviceList.h"
#define MASK_FISH_EYE        0xF7FF
#define DEVICE_FEATURE_WIFI		0x0001
#define DEVICE_FEATURE_IMAGE_FLIPMIRROR	0x0002
#define DEVICE_FEATURE_IMAGE_ROTATE  0x0004
#define DEVICE_FEATURE_LENS_PAN      	0x0010
#define DEVICE_FEATURE_LENS_TILT      	0x0020
#define DEVICE_FEATURE_LENS_ZOOM      	0x0040
#define DEVICE_FEATURE_LENS_PATROL    0x0080
#define DEVICE_FEATURE_LENS_MAGICZOOM   0x0100
#define DEVICE_FEATURE_NO_MICPHONE   0x00000200L
#define DEVICE_FEATURE_NO_SPEAKER    0x00002000L
#define DEVICE_FEATURE_NO_LED         0x00000400L
#define DEVICE_FEATURE_ANDLINK         0x1000
#define DEVICE_FEATURE_FISHEYE          0x0800

#define MV2_CODEC_TYPE_AAC 1633772320
#define MV2_CODEC_TYPE_G726 926037536
#define MV2_CODEC_TYPE_G711A 925970785
#define MV2_CODEC_TYPE_G711U 925970805

#define AUDIO_TALK_SAMPLE_RATE 48000
#define AUDIO_TALK_SAMPLE_RATE_G726 16000
#define AUDIO_TALK_SAMPLE_RATE_G711A 8000
#define AUDIO_TALK_SAMPLE_RATE_G711U 8000

typedef NS_ENUM(NSInteger, CLXCameraDeviceModel) {
    CLXCameraDeviceModel_Gospell = 1,                      //Default camera, LED will be red and green
    CLXCameraDeviceModel_Camera,                           //LED will be red and green
    CLXCameraDeviceModel_AMBA,                             //LED will be yellow
    CLXCameraDeviceModel_Kenxen,                           //LED will be yellow and green
    CLXCameraDeviceModel_ChiconyH30,                       //LED will be red and blue
    CLXCameraDeviceModel_Chinamobilem2m_Hisi_GosU5880A,    //云台 U5880A
    CLXCameraDeviceModel_Chinamobilem2m_Hisi_GosU5825Y,    //U5825Y
    CLXCameraDeviceModel_Chinamobile_CHGS_P002,            //c20 add by device ID
    CLXCameraDeviceModel_Car,                              //行车记录仪
    CLXCameraDeviceModel_IPC,                              //IPC设备
    CLXCameraDeviceModel_C30,                              //4G 枪机
    CLXCameraDeviceModel_C50,
    CLXAndLinkGateway,                                     //网关
    CLXZigbeeDevice_Sensor                                 //andlink智能硬件
};

typedef NS_ENUM(NSUInteger, CLXCameraImageType) {
    CLXCameraImageTypeDefault,
    CLXCameraImageTypeFishEye180,
    CLXCameraImageTypeFishEye360
};

typedef NS_ENUM(NSUInteger, CLXDeviceType) {
    CLXDeviceType_Dlna    = 0,
    CLXDeviceType_Remote    = 1,
    CLXDeviceType_Friend = 2,
    CLXDeviceType_InLan = 3
};

/**
 *  camera on-off state.
 */
typedef NS_ENUM(NSUInteger, CLXDeviceState) {
    /**
     *  camera on-off setting not initialized
     */
    CLXDeviceState_NotSet,
    /**
     *  camera is on.
     */
    CLXDeviceState_On,
    /**
     *  camera state is automatic.
     */
    CLXDeviceState_Auto,
    /**
     *  camera is turned off by schedule.
     */
    CLXDeviceState_OffbySchedule,
    /**
     *  camera is turned off by manual.
     */
    CLXDeviceState_OffbyManual,
    /**
     *  camera is turned off since update.
     */
    CLXDeviceState_OffbyUpdate,
    /**
     *  camera shutter is off.
     */
    CLXDeviceState_ShutterOff = CLXDeviceState_OffbyUpdate+10,
};

typedef NS_ENUM(NSInteger, CLXDeviceAudioType) {
    CLXDeviceAudio_AAC = 0,
    CLXDeviceAudio_G726 = 1,
    CLXDeviceAudio_G711ALAW = 2,
    CLXDeviceAudio_G711ULAW = 3,
};

typedef NS_ENUM(NSInteger, CLXDeviceUpdateType) {
    CLXDeviceUpdate_Send_Message = 1, //means use send xmpp to camera
    CLXDeviceUpdate_Save_Config = 2,     //means use the configuration in ESD server
};

typedef NS_ENUM(NSInteger, CLXDeviceShareState) {
    CLXDeviceShareState_NotShare = -1,
    CLXDeviceShareState_Own_Private = 0,
    CLXDeviceShareState_Own_Public = 1,
    CLXDeviceShareState_All = 2,
    CLXDeviceShareState_Others = 3,
    CLXDeviceShareState_Subscribed = 4,
};

typedef NS_ENUM(NSInteger, CLXDevicePaymentType) {
    CLXDevicePaymentType_Server_Expire = -1,//"-1":当前服务已经过期
    CLXDevicePaymentType_Server_Trial = 0,//"0": 当前服务是试用服务
    CLXDevicePaymentType_WebPurchase_Paypal = 1,//"1": WebPurchase-paypal 支付
    CLXDevicePaymentType_WebPurchase_Credit = 2,//"2": WebPurchase-信用卡 支付
    CLXDevicePaymentType_InAPPPurchase_GooglePlay = 3,//"3": InAPPPurchase-GooglePlay 支付
    CLXDevicePaymentType_InAPPPurchase_APPStore = 4,//"4": InAPPPurchase-APPStore 支付
    CLXDevicePaymentType_Server_Prepayment = 5,//"5": 预付费服务
    CLXDevicePaymentType_AdminConsole = 6,//"6": adminConsole 开放
    CLXDevicePaymentType_ActivationCode = 7,//"7": 激活码支付
    CLXDevicePaymentType_AliPay = 8,//"8": 支付宝快捷支付(android)
    CLXDevicePaymentType_WebPurchase_AliPay = 9,//"9": WebPurchase-®支付宝支付
};

typedef NS_ENUM(NSInteger, CLXPurchasePayMethod) {
    CLXPurchasePayMethodUnlimited = -1,
    CLXPurchasePayMethodPaypal = 1,
    CLXPurchasePayMethodIAP = 2
};

@class CLXDeviceUpdateInfo;
@interface CLCameraDevice : NSObject<NSCopying>

@property (nonatomic, assign) CLXPurchasePayMethod purchasePayMethod;
///camera device UUID.
@property (nonatomic, copy) NSString *deviceUUID;
///camera mac address.
@property (nonatomic, copy) NSString *macAddressID;
///camera name.
@property (nonatomic, copy) NSString * name;
@property (nonatomic, copy) NSString * iconUrl;
@property (nonatomic, copy) NSString * SourceURL;
///indicates whether camera is connected.
@property (assign,nonatomic) bool bIsConnect;
@property (assign,nonatomic) BOOL bSupportWiFi;
///indicates camera connection type, friend device or device for my own .etc. see more in CLCameraDevice.h.
@property (assign,nonatomic) NSInteger nDeviceType;          //DeviceType
@property (assign,nonatomic) NSInteger nDeviceTypeLocation;  //used for logon
///camera p2p ID, you can get it when received CameraConnectionDidChangedNotification
@property (strong,nonatomic) NSString *  p2pID;
@property (assign,nonatomic) bool isNAS;
///camera create time.
@property (nonatomic,assign) unsigned long long createTime;
@property (nonatomic,assign) NSUInteger cloudID;
///camera purchased service ID.
@property (nonatomic,assign) NSInteger serviceID;
///camera purchase state.  0:no service(no CVR/expired), 1:trial, 2:paid(has CVR)
@property (nonatomic,assign) NSInteger serviceState;
@property (assign,nonatomic) bool isP2pPreviewing;
@property (assign,nonatomic) bool isDefaultConnectState;
@property (nonatomic, strong) CLCameraExtraSettings *extraSettings;
@property (nonatomic, strong) CLCameraUpdateInfo *cameraUpdateInfo;
@property (nonatomic, strong) CLXDeviceUpdateInfo *deviceUpdateInfo;
@property (nonatomic) long long llPTZInformation;
@property (nonatomic, copy) NSString *details;
///indicates camera is on or off. see more in eDeviceState.
@property (nonatomic) NSInteger cameraState;
// -1:no share, 0:self-private, 1:self-public, 2:self-all, 3:others
@property (nonatomic, assign) NSInteger shareStatus;
@property (nonatomic, assign) NSInteger shareToOtherCount; //分享给他人的数量
// private:self device, reveive:others device
@property (nonatomic, copy) NSString *deviceSource;
//camera region url
@property (nonatomic, copy) NSString *regionUrl;
// 设备通道序号
@property (nonatomic, copy) NSString *channelNo;
// 中继设备ID
@property (nonatomic, copy) NSString *relayID;
@property (nonatomic, copy) NSString *hadAddSubRelays; // 中继设备下已添加子设备数量serviceRelayNumbs
@property (nonatomic, copy) NSString *serviceRelayNumbs; // 中继设备套餐路数
@property (nonatomic, copy) NSString *relayNumbs; // 中继设备路数
@property (nonatomic, copy) NSString *nvrChannelCount; // NVR子设备数
@property (nonatomic, copy) NSString *deviceTag;
@property (nonatomic, copy) NSString *modelId;
@property (nonatomic, copy) NSString *msgProtoType;
@property (nonatomic, copy) NSString *servicename;
@property (nonatomic, assign, getter = isStar) BOOL star;
@property (nonatomic, copy) NSString *cameraToken;
@property (nonatomic, copy) NSString *unifiedId;
@property (nonatomic, copy) NSString *username;
@property (nonatomic, copy) NSString *shareToken;
@property (nonatomic, copy) NSString *owernPhone;
@property (nonatomic, copy) NSString *sceneId;
@property (nonatomic, copy) NSString *sceneName;
@property (nonatomic, strong) NSDictionary *sceneSettingValues;
@property (nonatomic, assign) BOOL sceneSettingValues_defence;
@property (nonatomic, copy) NSString *creditCard;
@property (nonatomic, copy) NSString *currentprice;
@property (nonatomic, copy) NSString *downloadserver;
@property (nonatomic, copy) NSString *technicalState;
@property (nonatomic, copy) NSString *thumbnailFileIdList;
@property (nonatomic, copy) NSString *updateCreditCardTime;
@property (nonatomic, copy) NSString *devicePrice;
@property (nonatomic, copy) NSString *limit;
@property (nonatomic, copy) NSString *iDVRDays;
@property (assign, nonatomic) BOOL bSupportP2pToRelay;
@property (assign, nonatomic) BOOL bUseRelayToP2P;
@property (assign, nonatomic) BOOL isNVRDevice;

@property (nonatomic, assign) NSInteger serviceStatus;
@property (nonatomic, assign) NSInteger serviceStatusNew;  //设备套餐情况（1:有套餐、2:即将过期、3:已过期,4:未购买）
@property (nonatomic, assign) NSInteger remainingDaysToBeExpire;
@property (nonatomic, assign) BOOL expireAllowPlayback;
@property (nonatomic, assign) BOOL expireRecordingWhiteList;
@property (nonatomic, assign) NSInteger privView;  //对应分享设备返回的权限，1：直播权限，2：回放（Timeline）权限，3：直播和回放权限
@property (nonatomic, assign) NSInteger privPTZ;   //表示分享设备的云台控制权限，0表示没有云台控制权限，1表示有云台控制权限
@property (nonatomic, assign) BOOL isPTZAutoCruising; //ptz自动巡航状态 true:正在巡航
@property (nonatomic, copy) NSString *serialNumber; //设备序列号
@property (nonatomic, assign) BOOL isGBDevice; // 是否是国标设备
@property (nonatomic, assign) NSInteger cameraFocusStatus;

//service info
@property (nonatomic, assign) double startTime;
@property (nonatomic, assign) double endTime;
@property (nonatomic, assign) double sysDate;
@property (nonatomic, assign) BOOL bExpired;
@property (nonatomic, assign) unsigned int autoPayment;
@property (nonatomic, copy) NSString *serviceName;
@property (nonatomic, assign) NSInteger standby;

@property (nonatomic, copy) NSString *billingAmount;
@property (nonatomic, assign) NSInteger standbyServiceID;
@property (nonatomic, assign) double standByStartTime;
@property (nonatomic, assign) double standByEndTime;
@property (nonatomic, assign) NSInteger serverDays;
@property (nonatomic, assign) NSInteger checkedStatus; //DeviceType 0：不可签到，1：可以签到，2：已签到
@property (strong, nonatomic) NSDictionary* detailInformation;
//camera audio type
@property (assign, nonatomic) CLXDeviceAudioType audioType;
///camera thumbnail server URL, please don't use it directly.
@property (copy, nonatomic) NSString * thumbnailURL;
///Not used for client,it contains camera hardware info.
@property (nonatomic, copy) NSString *comments;
///Camera serial number in purchase server, you can use this ID to get services information from purchase server.
@property (strong, nonatomic) NSString *  purchaseDID;
@property (assign, nonatomic) BOOL  isSupportFullRelay;
@property (assign, nonatomic) BOOL  isSupportSDCard;
@property (assign, nonatomic) BOOL  isUpdating; // 设备正在更新中
@property (assign, nonatomic) BOOL  isDownLoad; // 设备正在下载中
@property (assign, nonatomic) BOOL  isInstall; //  设备正在安装中
@property (nonatomic, strong) NSDictionary *settingValues; // settingValues 设备属性
@property (nonatomic, strong) NSDictionary *supportValues; // supportValues 设备属性
@property (nonatomic, strong) NSDictionary *settingExtends; // settingExtends 设备属性

// 0:无服务,1:试用套餐,2:付费套餐
@property (nonatomic, assign) NSInteger status;
@property (nonatomic, copy) NSString *token;
@property (nonatomic,strong) NSString * apKey;//ap设备key
@property (nonatomic,strong) NSString * apIV;//ap设备IV
@property (nonatomic,strong) NSString * apDeskey;//ap设备deskey
// 离线状态判定方式：onlineStatus 为unavailable，aliveStatus 也为unavailable，此时表示离线配置.
@property (nonatomic, copy) NSString *onlineStatus; // available:在线，unavailable:不在线
@property (nonatomic, copy) NSString *aliveStatus;  // available:休眠，unavailable:非休眠
@property (nonatomic, copy) NSDictionary *deviceAbilities; // battery 表示电池电量，百分比，只显示数字；batteryStatus 取值0 表示取不到电池信息；battery: 1 表示低电量；2 表示正在充电；3 表示电池充满了；4 表示其它正常状态；

@property (nonatomic, copy) NSDictionary *whiteListConfig; // 白名单配置
@property (nonatomic,strong) CLXSMBDeviceList * smbDeviceInfo; // 行业设备完整信息
@property (nonatomic, copy) NSString *deviceAddSource;     // 设备添加的来源

- (id)init;

// 创建 `CLCameraDevice` 对象, 传入参数为摄像头UUID.
- (id)initByDeviceUUID:(NSString *)strDeviceUUID;
// 摄像头打开状态
- (BOOL)isTurnedOn;
- (NSInteger)daysForCurrentCVRService;
// 获取套餐的存储天数，只有过期并且不可回放时才返回0
- (NSInteger)daysForCurrentdvr;
// timeline数据来源 value取值1或者2，1表示从云端获取timeline，2表示从SD卡获取timeline
- (NSInteger)getPlayVideosFrom;
// 修改timeline数据来源
- (void)setPlayVideosFrom:(NSInteger)newValue;
- (NSString *)HWDeviceIDInDetails;
- (NSString *)modelStringInDetails;
- (CLXCameraDeviceModel)modelType;
// mac地址获取
- (NSString *)MACAddressInDetails;
// 是否可以直播
- (BOOL)canBeginLivePreview;
- (BOOL)CanBeginPreview;
- (NSTimeZone *)getRealTimezone;
- (void)setTimeZoneInDetails:(NSString *)strTimezone;
- (NSString *)timeZoneString;
// 音频类型
- (CLXDeviceAudioType)audioType;
// 音频编码类型
- (long)audioEncoderType;
// audioTalk采样率
- (int)audioTalkSampleRate;
// 分享的设备
- (BOOL)isSharedCamera;
// 分享者的UnifiedID
- (NSString *)shareOwnerUnifiedID;
// 分享的ID
- (NSString *)shareID;
- (CLXCameraImageType)cameraImageType;
- (BOOL)isHDVideo;
- (void)setVideoHD:(BOOL)isHD;
- (NSInteger)currentVideoQualityType;
- (BOOL)getESDSupportForKey:(NSString*)supportKey;
- (NSInteger)cameraInstallPos;
- (BOOL)setCameraInstallPos:(NSInteger)type;
- (BOOL)isIOTGateway;
- (NSString *)rateURLInAmazon;
- (BOOL)rateStatusInAmazon;
- (CLXDeviceUpdateType)updateType;
- (NSString *)lastFWDescrptionForUpgrade;
- (BOOL)shouldForceUpdate;
- (NSUInteger)hardwarePrice;
- (void)setRelayServerURL:(NSString *)host withPort:(NSString *)port;
- (NSString *)fullRelayServerIP;
- (NSInteger)fullRelayServerPort;
- (BOOL)isDoorBellDevice;
- (BOOL)isBatteryDevice;
- (BOOL)haveOpenedTurnOnOffSchedule;
- (NSMutableArray *)scheduleArrayWithType:(CLXScheduleType)type;
- (long long)standbyEndTime;
- (BOOL)shouldShowPurchase;
- (NSDictionary*)getDetailDic;
- (NSDictionary *)getDetailDic_sceneDic;
// 获取 `CLCameraDevice` 对象的播放地址
- (NSString *)GetLivePreviewURLWithp2pHandle:(void *)p2pHandle;
- (NSString *)GetSourceURLByType: (NSString *)type addIP:(BOOL)bAdd p2pHandle:(void *)p2pHandle;
// 判断摄像头是否支持 PTZ 设置
- (BOOL)isSupportPTZFeature:(int)nFeatureID;
// 是否支持人脸
- (BOOL)isSupportFaceDetection;
// 是否支持过期录制
- (BOOL)isSupportExpireRecording;
// 是否支持全双工
- (BOOL)isSupportFullDuplexTalk;
- (BOOL)isSupportSetting:(BOOL)bSupportOffline;
- (BOOL)ifSupportOfflineConfig:(BOOL)bSupportOffline;
- (BOOL)isSupportManualRecord;
- (BOOL)isSupportSDCardTimeLine;
- (BOOL)isSupportWebsocket;
- (BOOL)isSupportFullRelay;
- (BOOL)isSupportFeature: (NSInteger)nFeatureID;
- (BOOL)isSupportLiveControl;
- (BOOL)isSupportSwitchPlayVideosFrom;
// 是否支持摄像头长短焦
- (BOOL)isSupportCameraFocus;
// 长焦和短焦画面分别支持的最大放大倍数，用 | 分隔，例如： 2.5|3.5
- (NSString *)cameraFocusZoomRatio;
// 是否支持PTZ 预置位
- (BOOL)isSupportNoPtzPreset;

- (BOOL)isSupport:(NSString *)supportValueKey;
// 获取设备(CLJSONKey.h)内状态值
- (NSObject *)getCameraSupportValue:(NSString *)detailKey;

/**
 * 是否支持客流统计功能
 */
- (BOOL)isSupportPassengerStatistics:(BOOL)bSupportLogOnServer;
//是否支持鱼眼
- (BOOL)isSupportFishEye;
- (long long)endDateForCurrentCVRService;
- (BOOL)haveAnotherCVRServiceStandBy;
- (BOOL)ifSupportSDCard;
- (BOOL)ifSupportWiFiNetwork;
- (BOOL)ifSupportFullDuplexTalk;
- (BOOL)isSupportOpticalZoom;
- (BOOL)isSupportLight;
- (BOOL)isSupportAcoustooptic;
- (NSInteger)opticalZoomValue;
- (CLXDevicePaymentType)autoRenewPaymentType;
- (BOOL)isAutoRenewPayment;
- (long long)systemTimeInServer;
// 是否支持p2p缩略图
- (BOOL)isSupportP2PThumbnail;
// 是否支持摇头
- (BOOL)isSupportPTZ;
- (long long)isSupportAndlink;
// 取detail字段方法 key在 CLJSONKey.h
- (NSObject *)objectInDetailsByKey:(NSString *)key;
// 获取设备连接状态
- (BOOL)getDeviceConnectState;
// 获取是否支持新P2P
- (BOOL)isSupportNewP2P;
// 是否支持人形跟踪
- (BOOL)isSupportAutoTracking;
// 获取deviceType，例如C12
- (NSString *)getCameraModelAlias;
// 是否支持灯光亮度设置
- (BOOL)isSupportLightIntensity;
// 是否支持ptz全景
-(BOOL)isSupportPTZPano;
// 是否支持ptz自动巡航
-(BOOL)isSupportPTZAutoCruise;
// ptz自动巡航开关状态
-(BOOL)PTZAutoCruiseStatus;
// 设置灯光亮度值
- (void)setLightIntensityValue:(NSString *)value;
// 获取灯光亮度值
- (NSString *)getLightIntensityValue;
// 获取支持码流条数及分辨率 (值为字符串格式，码流分辨率之间用“-”分开,分辨率用长x宽表示。x为小写字母)
- (NSString *)getResolutionValue;
// 获取全景支持最大角度 : 分割 width / height
- (NSString *)getDeviceAngle;
// 人形检测开关状态
- (BOOL)getDeviceMotionTrackStatus;
// 返回分享设备数量
- (NSInteger)getSheraOtherCount;
- (void)setSheraOtherCount:(NSInteger)newValue;
// 是否显示播放时间
- (BOOL)isShowPlayTime;
// 是否有对应的服务
- (BOOL)isHaveService:(NSString *)serviceKey;
// 是否支持对应的功能
- (BOOL)isSupportDeviceFeature:(NSString *)supportFeatureKey;
// 是否是第三方设备
- (BOOL)isThirdPartyDevice;
// 是否支持AP模式修改热点密码
- (BOOL)isSupportModifyWiFiStatus;
// 是否支持AP模式修改用户密码
- (BOOL)isSupportModifyPwd;

+ (CLCameraDevice *)transferDeviceFromStoreDevicelist:(CLXSMBDeviceList *)deviceList;

@end

#define kDeviceTypeTag_Camera 90000
#define kDeviceTypeTag_Gateway 1000

typedef NS_ENUM(NSInteger, CLNewDeviceType) {
    //    1：温湿度传感器；2：水浸传感器；3：门窗传感器；4：人体传感器，5：烟雾传感器，6：灯传感器 12:门磁传感器 13:遥控器
    //    4000:网关,
    //    90000:Camera;
    CLNewDeviceTypeTemperatureSensor = 1,
    CLNewDeviceTypeWaterSensor = 2,
    CLNewDeviceTypeDoorSensor = 3,
    CLNewDeviceTypeHumanSensor = 4,
    CLNewDeviceTypeSmokeSensor = 5,
    CLNewDeviceTypeLightSensor = 6,
    CLNewDeviceTypeDoorMagneticSensor = 12,
    CLNewDeviceTypeRemoteController = 13,
    CLNewDeviceTypeGateWay = 1000,
    CLNewDeviceTypeCamera = 90000
};

@interface CLXSmartDeviceInfo : NSObject
@property (nonatomic, copy) NSString *comment;
@property (nonatomic, copy) NSString *devicetype;
@property (nonatomic, copy) NSString *modelid;
@property (nonatomic, copy) NSString *remark;
@property (nonatomic, copy) NSString *smartdevicemac;
@property (nonatomic, copy) NSString *smartdevicename;
@property (nonatomic, copy) NSString *deviceId;
@property (nonatomic) BOOL status;
@end

