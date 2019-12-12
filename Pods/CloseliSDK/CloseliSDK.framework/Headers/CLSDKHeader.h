//
//  CLSDKHeader.h

#ifndef CLSDKHeader_h
#define CLSDKHeader_h

#pragma mark - Notification
/*
 设备连接状态变更通知：
 当设备离线或者上线时，SDK会发送该通知，对APP有用的信息放在NSNotification的userInfo中，如
 CLCameraDevice*  changeServer= [[notification userInfo] objectForKey:NSLocalizedDescriptionKey];
 该通知仅仅针对CLCameraDevice类中deviceUUID, bIsConnect and p2pID三个属性进行赋值，告知APP端的变化，其他信息不在此通知的传值范围内
 */

extern NSString *const CameraConnectionDidChangedNotification;

/*
 在通知中获取camera的deviceUUID的key，
 NSString* deviceUuid=userInfo[LogonXMPPDeviceNotificationKeyDeviceId];
 详细使用参见工程demo
 
 */
extern NSString *const LogonXMPPDeviceNotificationKeyDeviceId;

/*
 camera关闭和开启的通知
 LogonXMPPDeviceNotificationCameraTurnedOnOff 通知名称
 通知UserInfo返回结构如下
 message =     {
     msgCategory = camera;
     msgContent =  {
     msgVersion = 1;
     request = 1816;
     requestParams =  {
     value = 1;
     };
     subRequest = "-1";
     };
     msgSequence = 0;
     msgSession = 99999999;
     msgTimeStamp = 99999999;
  };
 scrId = "xxxxS_xxxxx"; (设备DeviceId)
 */
extern NSString *const LogonXMPPDeviceNotificationCameraTurnedOnOff;

/*
 人脸注册通知，userInfo中包含返回消息
 */
extern NSString *const LogonXMPPFaceRegisterStateNotification;

/*
 添加设备的通知。
 若添加成功，UserInfo消息结构如下
 message = {
     action = insert; // 添加成功 action返回insert，失败返回：insert_error
     deviceid = "xxxxS_xxxxxxxxx"; // 设备DeviceId
     did = 99999;
     imei = imeiValue;
     product = temp;
     server = temp;
 };
 scrID = "xxxxS_xxxxxx";（该字段不是可靠DeviceID，请用message结构中的）
 */
extern NSString *const CLXLogonXMPPDeviceInsertNotification;//添加设备通知

/*
 删除设备通知。
 app可以从通知中获取哪个设备被删除了。
 UserInfo消息结构如下
 message = {
    action = delete;
    deviceid = "xxxxS_xxxxxxxx"; // 设备DeviceId
    did = 999999;
    product = temp;
    server = temp;
  };
 scrID = "xxxxS_xxxxxxx";该字段不是可靠DeviceID，请用message结构中的）

 */
extern NSString *const LogonXMPPDeviceRemoveNotification;//删除设备通知

/*
 TcpbufferCommend xmpp消息通知
 */
extern NSString *const CLXLogonXMPPTCPBufferStateNotification;

/*
websocket onlin/offline message
 */
extern NSString *const WebsocketOnlineOrOfflineMessageNotification;

/*
 websocket 设备状态
 */
extern NSString *const CLCameraWebsocketTypeStatusNotification;


/*
  全景图片生成通知/ 返回图片
 */
extern NSString *const CLXCameraReceiveGetPictureInfomationNotification;


/////////////
/**
 Notification for upgrade device result.
 NOTICE: The notification may not be sent by CLSDK, so please fill parameter with sender to nil when adding observer
 param userInfo,
 value for key LogonXMPPDeviceNotificationKeyDeviceId is a NSString, which is deviceUUID of class CLCameraDevice.
 value for key LogonXMPPDeviceUpgradeNotificationKeyServiceId is a NSNumber, which is service id.
 */
extern NSString *const LogonXMPPDeviceUpgradeNotification;  //套餐变更通知
extern NSString *const LogonXMPPDeviceUpgradeNotificationKeyServiceId;//套餐id，可以根据这个id获取套餐详细信息

extern NSString *const LogonXMPPDeviceP2PIsPlayingNotification;//p2p播放的通知，当用户camera以p2p的形式播放之后，其他以该账户登录的APP会收到这个通知
extern NSString *const CameraReceiveGetConfigurationNotification;
extern NSString *const CameraReceiveSetConfigurationNotification;
extern NSString *const CameraMessageEventNotification;
extern NSString *const CameraDeviceChangeNotification;
extern NSString *const CameraPTZInformationNotification;//当前PTZ信息
// 格式化SD卡会收到成功失败的通知 nret=0 代表成功 其他失败，内部超时设定为180s，没有收到消息可以按超时处理 获取SD卡信息刷新UI
extern NSString *const CameraDeviceFormatSdCardNotification;
// 正在更新设备中的通知 @"srcID":scrID,@"curSize":@(curSize),@"totalSize":@(totalSize)
extern NSString *const CameraDeviceUpgradePropressInformationNotification;
// 更新设备成功或失败的通知 @"srcID":scrID,@"updateState":@(0) updateState为0代表成功 1代表失败
extern NSString *const CameraDeviceUpgradeStateInformationNotification;

/* camera状态变化的通知 EuCallbackType CALLBACKDOWNLOAD CALLBACKUPLOAD CALLBACKWIFIPOOR CALLBACK_P2P_CLIENT_REACH_TO_MAX等  */
extern NSString *const CLCameraUpdateCameraStatusNotification;

/**
 Notification for camera shutter changed, you must observe the notification while change shutter, and call disposeNotification:forCamera: to update the state for camera device.
 NOTICE: The notification may not be sent by CLSDK, so please fill parameter with sender to nil when adding observer
 
 param userInfo
 value for key LogonXMPPDeviceNotificationKeyDeviceId is a NSString, which is deviceUUID of class CLCameraDevice.
 value for key LogonXMPPDeviceNotificationShutterChangedKeyValue is a NSNumber, 0-for off, others for on.
 
 */
extern NSString *const LogonXMPPDeviceNotificationShutterChanged;   //废弃
extern NSString *const LogonXMPPDeviceNotificationShutterChangedKeyValue;  //废弃
/**
 Notification for camera entering battery mode.
 NOTICE: The notification may not be sent by CLSDK, so please fill parameter with sender to nil when adding observer
 param userInfo
 value for key LogonXMPPDeviceNotificationKeyDeviceId is a NSString, which is deviceUUID of class CLCameraDevice.
 value for key LogonXMPPDeviceNotificationBatteryChangedKeyMode is a NSNumber, 0-not in battery mode, 1-battery mode.
 value for key LogonXMPPDeviceNotificationBatteryChangedKeyValue is a NSNumber, 0-100, current power of battery.
 
 */
extern NSString *const LogonXMPPDeviceNotificationBatteryChanged;    //废弃
extern NSString *const LogonXMPPDeviceNotificationBatteryChangedKeyMode;//废弃
extern NSString *const LogonXMPPDeviceNotificationBatteryChangedKeyValue; //废弃
extern NSString *const CLRequestAPINotificationTokenInvalid; //token invalid 通知
extern NSString *const CLCameraPlayerAudioTalkNotification;  //当前语音通话状态

/**
 指定设置camera的哪个部分的属性
 *  Specifies a setting type used in function:setCameraSettingsWithCamera.
 */
typedef NS_ENUM(NSUInteger, CLCameraSetting_E) {
    CLCAMERA_SETTINGS_NAME = 1,         //-> 修改名字
    CLCAMERA_SETTINGS_DESCRIPTION,      //-> 修改描述
    CLCAMERA_SETTINGS_MOTION,           //-> motion检测开关
    CLCAMERA_SETTINGS_MOTION_SENSITITY, //-> motion敏感度设置
    /**
     *  Specifies a type that setting camera motion detection's notification schedule. camera推送消息的定时开关
     */
    CLCAMERA_SETTINGS_STOP_NOTIFICATION_SCHEDULE,
    /**
     *  Specifies a type that setting camera sound detection on-off. 声音检测
     */
    CLCAMERA_SETTINGS_SOUNDDETECT,
    /**
     *  Specifies a type that setting camera sound detection's sensitivity.声音检测敏感度
     */
    CLCAMERA_SETTINGS_SOUNDDETECT_SENSITITY,
    /**
     *  Specifies a type that setting camera micro phone on-off.麦克风开关
     */
    CLCAMERA_SETTINGS_CAMERA_MICROPHONE,
    /**
     *  Specifies a type that setting camera night mode on-off.夜视开关
     */
    CLCAMERA_SETTINGS_NIGHTMODE,
    /**
     *  Specifies a type that setting camera led light on-off.   LED开关
     */
    CLCAMERA_SETTINGS_LED_LIGHT,
    /** Specifies a type that setting camera's timezone. Param should be
     
     [NSTimeZone description];
     
     Since you get full descritiopn @"Europe/Paris (GMT+1) offset 3600"
     please pass @"Europe/Paris" or Abbreviation presentation(@"CEST") as the time zone value.
     Get all available abbreviations, call [NSTimeZone abbreviationDictionary].
     */                                                      //      时区
    CLCAMERA_SETTINGS_TIMEZONE,
    /**
     *  Specifies a type that setting camera video's quality.
     For CLCAMERA_SETTINGS_HDVIDEO and CLCAMERA_SETTINGS_VIDEO_QUALITY, only one option is valid, depend on the camera.
     
     Check CLCameraExtraSettings for setting detail     //高清标清，设置0 sd，1 hd
     */
    CLCAMERA_SETTINGS_HDVIDEO,
    /**
     *  Specifies a type that setting camera video's quality.
     For CLCAMERA_SETTINGS_HDVIDEO and CLCAMERA_SETTINGS_VIDEO_QUALITY, only one option is valid, depend on the camera.
     
     Check CLCameraExtraSettings for setting detail
     */
    CLCAMERA_SETTINGS_VIDEO_QUALITY,     //废弃
    /**
     *  Specifies a type that setting camera frequency.
     */
    CLCAMERA_SETTINGS_ANTIFLICKER,
    
    /**
     *  Specifies a type that setting camera cloud record light on-off.云录制
     */
    CLCAMERA_SETTINGS_CLOUDRECORD,
    /**
     *  Specifies a type that setting camera schedule of cloud record.云录制的定时开关
     */
    CLCAMERA_SETTINGS_CLOUDRECORD_SCHEDULE,
    /**
     *  Specifies a type that setting camera on-off.  指定camera开关
     */
    CLCAMERA_SETTINGS_TURNON,
    /**
     *  Specifies a type that setting camera schedule of turnning off.指定camera开关的定时开关时刻表
     */
    CLCAMERA_SETTINGS_TURNOFF_SCHEDULE,
    /**
     *  Specifies a type that setting camera schedule of mute.静音时刻表
     */
    CLCAMERA_SETTINGS_MUTE_SCHEDULE,
    /**
     *  Specifies a type that setting camera image orientation. camera旋转180度
     */
    CLCAMERA_SETTINGS_ROTATE180,
    /**
     *  Specifies a type that setting camera motion region.   motion区域设置
     */
    CLCAMERA_SETTINGS_MOTIONREGION,
    /**
     *  Notify camera to zoom and offset.  光学变焦
     */
    CLCAMERA_SETTINGS_MAGIC_ZOOM,//废弃
    CLCAMERA_SETTINGS_OPTICAL_ZOOM,
    /**
     *  Notify camera to turn on-off the mechanical shutter. You must register notification LogonXMPPDeviceNotificationShutterChanged and call disposeNotification:forCamera: firstly;
     */
    CLCAMERA_SETTINGS_MECHANICAL_SHUTTER,//废弃
    /**
     *  Notify camera to turn on-off pir.   //人体红外检测
     */
    CLCAMERA_SETTINGS_PIRDETECTION,
    /**
     *  Set self define data to camera.预留的自定义数据段
     */
    CLCAMERA_SETTINGS_SELFDEFINE,
    /**
     *  Turn email alerts on or off.  邮件提醒
     */
    CLCAMERA_SETTINGS_EMAIL_ALERTS,
    /**
     *  Turn tamper detection notification on or off.
     */
    CLCAMERA_SETTINGS_TAMPER_DETECTION , //废弃
    CLCAMERA_SETTINGS_BUZZER,    //蜂鸣器
    CLCAMERA_SETTINGS_RECORDMODE, // 录像模式
    CLCAMERA_SETTINGS_FaceDetection, //人脸识别开关
    CLCAMERA_SETTINGS_RICHTEXT, //富文本推送开关
    CLCAMERA_SETTINGS_VIEWTIMELINE,  //view timeline方向
    CLCAMERA_SETTINGS_FISHEYEINSTALLTAION, // 鱼眼安装方式
    CLCAMERA_SETTINGS_AUTOMATICCRUISE, // 自动巡航
    CLCAMERA_SETTINGS_SCAPTURE, // 定时截图
    CLCAMERA_SETTINGS_MOTIONTRACK,  // 设置智能跟踪开关
    CLCAMERA_SRTTINGS_NOTIFICATION_INTERVAL, // 通知周期频率
    CLCAMERA_SETTINGS_PEOPLEDECTION, // 人形检测开关
    CLCAMERA_SETTINGS_WIFI_ACCOUNT,  //wifi
    CLCAMERA_SETTINGS_PFS_SCHEDULE, //PFS 计划
    CLCAMERA_SETTINGS_PFS_TURN_ONOFF, //PFS 开关
    CLCAMERA_SETTINGS_PFS_REGION,     //PFS region
    CLCAMERA_SETTINGS_SOUNDLIGHT, //声光
    CLCAMERA_SETTINGS_LIGHT, //灯光
    CLCAMERA_SETTINGS_NIGHT_VISION_SENSITIVITY, //夜视
    CLCAMERA_SETTINGS_PHONE_NOTIFICATION, //手机通知
};

typedef NS_OPTIONS(NSUInteger, Base_API_Type) {
    Base_API_Type_Esd         = 1,
    Base_API_Type_Cloud       = 1 << 1,
    Base_API_Type_UPNS        = 1 << 2,
    Base_API_Type_IOT         = 1 << 3,
    Base_API_Type_Update      = 1 << 4,
    Base_API_Type_CloudOauth  = 1 << 5,
    Base_API_Type_File        = 1 << 6,
    Base_API_Type_Mqtt        = 1 << 7,
    Base_API_Type_Andlink     = 1 << 8,
    Base_API_Type_Smb         = 1 << 9,
    Base_API_Type_Passport    = 1 << 10,
    Base_API_Type_Pay         = 1 << 11,
    Base_API_Type_ALG         = 1 << 12,
    Base_API_Type_ADS         = 1 << 13,
    Base_API_Type_Argus       = 1 << 14,
    Base_API_Type_Xmpp        = 1 << 15,
    Base_API_Type_DNS         = 1 << 16,
    Base_API_Type_GB          = 1 << 17,
    Base_API_Type_GW          = 1 << 18,
    Base_API_Type_H5          = 1 << 19,
    Base_API_Type_STUN        = 1 << 20,
    Base_API_Type_TURN        = 1 << 21,
    Base_API_Type_IAP         = 1 << 22,
    Base_API_Type_OPERATE     = 1 << 23,

};

typedef NS_OPTIONS(NSUInteger, debugFlag_E) {
    DebugFlag_default   = 0,
    DebugFlag_tcpBuffer = 1 << 0,                //tcpbuffer相关的log
    DebugFlag_logon     = 1 << 1,                //p2p相关log
    DebugFlag_player    = 1 << 2,                //player相关log
    DebugFlag_http      = 1 << 3,                //http api log
    DebugFlag_linklog   = 1 << 4,                //全链路日志 log
    DebugFlag_all       = DebugFlag_tcpBuffer | DebugFlag_logon | DebugFlag_player | DebugFlag_http
};

typedef NS_ENUM(NSInteger, CLXServerEnv) {
    CLXServerEnvPro,          //国内pro
    CLXServerEnvStg,          //国内stg
    CLXServerEnvProInt,       //国外pro
    CLXServerEnvStgInt,       //国外stg
};

#endif /* CLSDKHeader_h */
