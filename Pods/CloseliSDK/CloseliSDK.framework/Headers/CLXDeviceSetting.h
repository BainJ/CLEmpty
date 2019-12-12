//
//  CLXDeviceSetting.h

#import <Foundation/Foundation.h>

@class CLXAlert;
@class CLXGeneral;

/**
 @brief 每个Setting项都是CLBaseSetting作为基类，getSetting时text为值，而且saveSetting也是取的此字断的值上传。
        support以及supportKey是功能集（是否支持，支持范围)，只能get，不能set。
 */
@interface CLXBaseSetting : NSObject
@property (nonatomic, copy) NSString *text;             //-> 设置项值
@property (nonatomic, copy) NSString *support;          //-> 是否有此设置项功能
@property (nonatomic, copy) NSString *supportKey;       //-> 有些设置项可能返回此参数，设置区间
@end

/**
 @brief Schedule计划基础类
 */
@interface CLXScheduleValue : NSObject
@property (nonatomic, assign) NSTimeInterval start;
@property (nonatomic, assign) NSTimeInterval end;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, assign) NSInteger repeat;         // -> SUN:0x0001, MON:0x0002, TUE:0x0004, WED:0x0008, THU:0x0010, FRI:0x0020, SATU:0x0040
@property (nonatomic, assign) NSInteger repeatType;     // -> ONCE:0x0000, EVERYDAY:0x0001, WEEKLY:0x0002, MONTHLY:0x0003
@property (nonatomic, copy) NSString *status;
@end

/**
 @brief Schedule计划基础。 目前只有 CLXCruiseSchedules 用新的格式，其他数据用 CLXScheduleValue，只有部分字段不一样
 */
@interface CLXNewScheduleValue : NSObject
@property (nonatomic, copy) NSString *valueId;
@property (nonatomic, assign) NSTimeInterval startTime;       // -> 开始时间, 单位：秒
@property (nonatomic, assign) NSTimeInterval endTime;         // -> 结束时间, 单位：秒
@property (nonatomic, assign) NSInteger repeat;               // -> 是否重复
@property (nonatomic, assign) NSInteger repeatType;           // -> 重复周期
@property (nonatomic, assign) NSTimeInterval activeStartTime; // -> 单位：秒
@property (nonatomic, assign) NSTimeInterval activeEndTime;   // -> 单位：秒
@property (nonatomic, copy) NSString *status;                 // -> On、Off
@end

@interface CLXBaseSchedule : NSObject
@property (nonatomic, strong) NSObject *schedules;       // -> schedules属性类型应该是NSArray<CLXScheduleValue> *
@property (nonatomic, copy) NSString *status;            // -> 0 关 1 开
@property (nonatomic, copy) NSString *support;
@end

#pragma mark - General
/**
 @brief:套餐计划
 */
@interface CLXDVRPlan : CLXBaseSetting
@end
/**
 @brief:高标清（切换HD(720P)/SD(VGA)/Auto）
 path:profile/general/HDVideo
 */
@interface CLXHDVideo : CLXBaseSetting
@end
/**
 @brief:蜂鸣器
 path:profile/general/alarmBuzz
 */
@interface CLXAlarmBuzz : NSObject
@property (nonatomic, copy) NSString *buzzTime;         //-> 表示蜂鸣的时长，单位：秒
@property (nonatomic, copy) NSString *status;           //-> 表示开关，取值：On、Off，默认关闭
@property (nonatomic, copy) NSString *support;          //-> 是否有此设置项功能
@end
/**
 @brief:防闪烁
 path:profile/general/antiFlicker
 param: CLXDeviceSettingTextFlickerFrequency_50HZ、CLXDeviceSettingTextFlickerFrequency_60HZ
 */
@interface CLXAntiFlicker : CLXBaseSetting
@end
/**
 @brief:画面旋转180度
 path:profile/general/cameraImageRotate
 param:"0"、"180"
 */
@interface CLXCameraImageRotate : CLXBaseSetting
@end

/**
 @brief:摄像头麦克风
 path:profile/general/cameraSound
 param:"On":开/关："Off"
 (已废弃，用CLXVolumeMute设置)
 */
@interface CLXCameraSound : CLXBaseSetting
@end
@interface CLXCloudRecord : CLXBaseSetting
@end

@interface CLXDescriptions : CLXBaseSetting
@end
@interface CLXDeviceId : CLXBaseSetting
@end


@interface CLXDeviceLensPTZ : NSObject
@property (nonatomic, copy) NSString *pan;
@property (nonatomic, copy) NSString *reserved1;
@property (nonatomic, copy) NSString *reserved2;
@property (nonatomic, copy) NSString *status;
@property (nonatomic, copy) NSString *tilt;
@property (nonatomic, copy) NSString *time;
@property (nonatomic, copy) NSString *value;
@property (nonatomic, copy) NSString *zoom;
@end

/**
 @brief:邮件通知开关
 path:profile/general/emailNotification
 param:"On":开/关："Off"
 */
@interface CLXEmailNotification : CLXBaseSetting
@end
@interface CLXExtOSD : CLXBaseSetting
@end

/**
 @brief:人脸检测开关
 path:profile/general/faceDetection
 param:"On":开/"OffByManual":"关"
 */
@interface CLXFaceDetection : CLXBaseSetting
@end

/**
 @brief:相应设备采集到的图像类型(0,1,2)
 path:profile/general/imageType
 param: 0:缺省IMAGE_TYPE_DEFAULT
        1:180度鱼眼设备IMAGE_TYPE_FISHEYE_180
        2:360度鱼眼设备IMAGE_TYPE_FISHEYE_360
 */
@interface CLXImageType : CLXBaseSetting
@end

/**
 @brief:定时截图开关（默认关闭）
 path:profile/general/image
 param: On:打开 / Off:关闭
 */
@interface CLXImage : CLXBaseSetting
@end

/**
 @brief:定时截图当前设置的频率{1,2,3,4}
 path:profile/general/image
 param: On:打开 / Off:关闭
 */
@interface CLXImageTimingLevel : CLXBaseSetting
@end
@interface CLXImageTimingLevels : CLXBaseSetting
@end

/**
 @brief:定时截图开关schedule
 */
@interface CLXImageTimingSchedule : CLXBaseSchedule
@end

/**
 @brief:红外线开关,目前APP废弃
 */
@interface CLXInfraredLight : CLXBaseSetting
@end

/**
 @brief:灯光亮度调节
 path:profile/general/lightIntensity
 param: （0-100）
 */
@interface CLXLightIntensity : CLXBaseSetting
@end

/**
 @brief:是否支持观看设备直播，只有support
 */
@interface CLXLiveCtrl : CLXBaseSetting
@end

/**
 @brief:设备mac地址
 */
@interface CLXMacAddress : CLXBaseSetting
@end

/**
 @brief:放大镜，目前APP已废弃
 */
@interface CLXMagicZoom : NSObject
@property (nonatomic, copy) NSString *ratio;
@property (nonatomic, copy) NSString *xOffset;
@property (nonatomic, copy) NSString *yOffset;
@property (nonatomic, copy) NSString *support;          //-> 是否有此设置项功能
@end
@interface CLXModel : CLXBaseSetting

@end


/**
 motionRegion值
 */
@interface CLXMotionRegionValue : NSObject
@property (nonatomic, assign) NSInteger id;
@property (nonatomic, assign) NSInteger left;
@property (nonatomic, assign) NSInteger top;
@property (nonatomic, assign) NSInteger right;
@property (nonatomic, assign) NSInteger bottom;
@property (nonatomic, assign) NSInteger sensitivity;
@property (nonatomic, assign) BOOL enable;
@end

/**
 @brief:运动检测开关
 path:profile/general/motionDetection
 param: On:打开 / Off:关闭
 */
@interface CLXMotionDetection : CLXBaseSetting
@end

/**
 @brief:motion区域设置
 path:profile/general/motionRegions
 param: 3*5x5x25
 */
@interface CLXMotionRegions : CLXBaseSetting
@property (nonatomic, strong) NSObject *motionRegion;
- (NSString *)xmlString;
@end

/**
 @brief:运动检测灵敏度
 path:profile/general/motionSensitivity
 param:30、50、80、90、100
 */
@interface CLXMotionSensitivity : CLXBaseSetting
@end


/**
 @brief:WIFI网络信号强度
 path:profile/general/networkQuality
 param:（0-100）
 */
@interface CLXNetworkQuality : CLXBaseSetting
@end

/**
 @brief:夜视模式开关
 path:profile/general/nightVision
 param:（0，1，2）
 */
@interface CLXNightVision : CLXBaseSetting
@end

/**
 @brief:夜视模式灵敏度
 path:profile/general/nightVisionSensitivity
 param:（open、close）
 */
@interface CLXNightVisionSensitivity : NSObject
@property (nonatomic, copy) NSString *close;
@property (nonatomic, copy) NSString *open;
@property (nonatomic, copy) NSString *support;          //-> 是否有此设置项功能
@end


/**
 @brief:通知频率；
 path:profile/general/notificationInterval
 param:（10）
 */
@interface CLXNotificationInterval : CLXBaseSetting
@end
@interface CLXOfflineConfig : CLXBaseSetting
@end

/**
 @brief:客流统计开关设置
 path:profile/general/personStatus
 param:"On":开/"OffByManual":"关" （默认：OffByManual）
 */
@interface CLXPersonStatus : CLXBaseSetting
@end

@interface CLXPersonScheduleValue : NSObject
@property (nonatomic, assign) NSTimeInterval start;
@property (nonatomic, assign) NSTimeInterval end;
@property (nonatomic, copy) NSString *activeStart;
@property (nonatomic, copy) NSString *activeEnd;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, assign) NSInteger type;
@property (nonatomic, assign) NSInteger repeat;
@property (nonatomic, assign) NSInteger repeatType;
@property (nonatomic, copy) NSString *status;
@end


/**
 @brief:客流统计时间点设置
 path:profile/general/personSchedules
 */
@interface CLXPersonSchedules : CLXBaseSchedule

@end

/**
 @brief:客流统计时间点设置
 path:profile/general/personDirection
 */
@interface CLXPersonDirection : CLXBaseSetting
@end

@interface CLXPersonRegions : CLXBaseSetting

@property (nonatomic, strong) NSObject *regions;

- (NSString *)xmlString;

@end

@interface CLXPersonRegion : NSObject

@property (nonatomic, assign) int x;
@property (nonatomic, assign) int y;
@property (nonatomic, assign) int width;
@property (nonatomic, assign) int height;

@end

@interface CLXPhoneNotification : CLXBaseSetting
@end

/**
 @brief:重启设备
 path:profile/general/personStatus
 param:"On":开/"OffByManual":"关" （默认：OffByManual）
 */
@interface CLXReboot : CLXBaseSetting
@end
@interface CLXRecordTo : CLXBaseSetting
@end

/**
 @brief:定时计划云录制
 */
@interface CLXScheduleCloudRecord : CLXBaseSchedule
@end

/**
 @brief:定时计划静音
 */
@interface CLXScheduleMute : CLXBaseSchedule
@end

/**
 @brief:定时计划关闭
 */
@interface CLXScheduleTurnOff : CLXBaseSchedule
@end
/**
 @brief:SD卡录像功能
 path：profile/general/sdCard
 */
@interface CLXSdCard : NSObject
// 表示存储卡状态，取值：1、2、3，分别表示：无存储卡、存储卡异常、正常，默认无存储卡（1）
@property (nonatomic, copy) NSString *status;
// 表示录像模式，取值：1、2、3，分别表示：支持无录像、事件录像、连续录像功能，默认事件录像（2）
@property (nonatomic, copy) NSString *recordModel;
// 能力集是否支持
@property (nonatomic, copy) NSString *support;
@end
/**
 @brief:是否支持SD卡格式化
 path：profile/general/sdcardFeature
 */
@interface CLXSdcardFeature : CLXBaseSetting
@end
/**
 @brief:自定义profile参数
 path：profile/general/selfDefine
 param:  base64Str（内容为base64加密，具体内容由camera和app进行协商）
 */
@interface CLXSelfDefine : CLXBaseSetting
@end

/**
 @brief:声音检测开关
 path:profile/general/soundDetection
 param:"On":开/"Off":"关" （默认：Off）
 */
@interface CLXSoundDetection : CLXBaseSetting
@end

/**
 @brief:声音灵敏度设置
 path:profile/general/soundSensitivity
 param: 80、85、90、95、100
 */
@interface CLXSoundSensitivity : CLXBaseSetting
@end

/**
 @brief:本地语言识别开关
 path:profile/general/offlineSpeechRecongize
 param:"On":开/"Off":"关" （默认：Off）
 */
@interface CLXOfflineSpeechRecongize : CLXBaseSetting
@end
@interface CLXStatus : CLXBaseSetting
@end


/**
 @brief:指示灯状态
 */
@interface CLXStatusLight : CLXBaseSetting
@end


/**
 @brief:遮挡检测
 */
@interface CLXTamperDetection : CLXBaseSetting
@end


/**
 @brief:OSD开关状态
 */
@interface CLXTimeOSD : CLXBaseSetting
@end


/**
 @brief:时区
 path:profile/general/timeZone
 param:  eg:Asia/Shanghai
 */
@interface CLXTimeZone : CLXBaseSetting
@end


/**
 @brief:设备名字
 */
@interface CLXTitle : CLXBaseSetting
@end

/**
 @brief:视频清晰度
 path:profile/general/videoQuality
 param: {high,medium,low}
 */
@interface CLXVideoQuality : CLXBaseSetting
@end

/**
 @brief:timeline读取云端数据还是SD卡数据的入口
 path:profile/general/viewTimeline
 param: 1:从云端获取timeline / 2:从SD卡获取timeline
 */
@interface CLXViewTimeline : CLXBaseSetting
@end

/**
 @brief:静音
 */
@interface CLXVolumeMute : CLXBaseSetting
@end

/**
 @brief:是否支持websocket
 */
@interface CLXWebSocket : CLXBaseSetting
@end

/**
 @brief:Wi-Fi网络SSID
 */
@interface CLXWifiNetWork : CLXBaseSetting
@end

/**
 @brief:Wi-Fi质量
 */
@interface CLXWifiQuality : CLXBaseSetting
@end

/**
 @brief:是否支持4G网络
 */
@interface CLXG4NetWork: CLXBaseSetting
@end

/**
 @brief:4G卡基站定位开关
 path：profile/general/g4Location
 support:1
 value:On | Off
 */
@interface CLXG4Location: CLXBaseSetting
@end

/**
 @brief:表示语音视频能力，仅支持是否在app上展示
 */
@interface CLXAudioVideo : CLXBaseSetting
@end

/**
 @brief:响铃开关
 path:profile/general/bellRing
 param:"On":开/"OffByManual":"关" （默认：OffByManual）
 */
@interface CLXBellRing : CLXBaseSetting
@end


/**
 @brief:表示在听声辨位或者唤醒辨位的模式下，多少秒无动检或声音后回到原来位置
 path:profile/general/idLocBackTime
 param: 单位：秒 (默认30)
 */
@interface CLXIdLocBackTime : CLXBaseSetting
@end

/**
 @brief:运动跟踪开关
 path:profile/general/motionTrack
 param:"On":开/"OffByManual":"关" （默认：On）
 */
@interface CLXMotionTrack : CLXBaseSetting
@end

/**
 @brief:运动追踪归位时长设置
 path:profile/general/motionTrackBackTime
 param: {15,30,45s}
 */
@interface CLXMotionTrackBackTime : CLXBaseSetting
@end

/**
 @brief:运动跟踪灵敏度
 path:profile/general/motionTrackSensitivity
 param: (0-100)
 */
@interface CLXMotionTrackSensitivity : CLXBaseSetting
@end


/**
 @brief:人形检测能力集
 */
@interface CLXPeopleDetection : CLXBaseSetting
@end

/**
 @brief:人形检测通知开关
 path:profile/general/peopleDetectionNotify
 param:"On":开/"OffByManual":"关" （默认：OffByManual）
 */
@interface CLXPeopleDetectionNotify : CLXBaseSetting
@end

/**
 @brief:PIR灵敏度调节
 path:profile/general/PIRSensitivity
 param:（0-100）（默认：0）
 */
@interface CLXPIRSensitivity : CLXBaseSetting
@end

/**
 @brief:PIR灵敏度开关
 path:profile/general/PIRStatus
 param:"On":开/"OffByManual":"关" （默认：On）
 */
@interface CLXPIRStatus : CLXBaseSetting
@end

/**
 @brief:PIR检测推送开关
 path:profile/general/PIRDetection
 param:"On":开/"OffByManual":"关" （默认：On）
 */
@interface CLXPIRDetection : CLXBaseSetting
@end

/**
 @brief:录制模式
 path:profile/general/recordModel
 param: 0：表示智能模式/1：表示省电模式 （默认：0）
 */
@interface CLXRecordModel : CLXBaseSetting
@end

/**
 @brief:基础录像时长
 path:profile/general/recordTime
 param:{0,15,30,45s} （默认15s）
 */
@interface CLXRecordTime : CLXBaseSetting
@end

/**
 @brief:听声辨位开关
 path:profile/general/soundIDLoc
 param:On:打开 / Off:关闭
 */
@interface CLXSoundIDLoc : CLXBaseSetting

@end

/**
 @brief:听声辨位模式下声音持续时间
 path:profile/general/soundIDLocDuration
 param:单位：秒；（默认3秒）
 */
@interface CLXSoundIDLocDuration : CLXBaseSetting

@end

/**
 @brief:听声辩位声音分贝阈值
 path:profile/general/soundIDLocVolume
 param: （0-100）（默认：75）
 */
@interface CLXSoundIDLocVolume : CLXBaseSetting
@end

/**
 @brief:对讲音量调节
 path:profile/general/talkVolume
 param: （0-100）（默认100）
 */
@interface CLXTalkVolume : CLXBaseSetting
@end

/**
 @brief:andlink功能
 */
@interface CLXAndlink : CLXBaseSetting
@end

/**
 @brief:人形跟踪开关（默认关闭）
 path:profile/general/autoTracking
 param: On:打开 / Off:关闭
 */
@interface CLXAutoTracking : CLXBaseSetting
@end

/**
 @brief:富文本推送开关（默认关闭）
 path:profile/general/richText
 param: On:打开 / OffByManual:关闭
 */
@interface CLXRichText : CLXBaseSetting
@end


@interface CLXPTZAutoCurise : CLXBaseSetting
@end
/**
 @brief:PTZ 预置位
 */
@interface CLXNoPtzPreset : CLXBaseSetting
@end

/**
 @brief:摄像头长短焦
 path:profile/general/cameraFocus
 param: 0:长焦 / 1:短焦 默认为0；
 */
@interface CLXCameraFocus : CLXBaseSetting
@end

/**
 @brief:摄像头长短焦支持最大倍数
 长焦和短焦画面分别支持的最大放大倍数，用 | 分隔，例如： 2.5|3.5 表示：
 长焦画面支持的最大放大倍数为2.5倍，如果超过2.5，客户端需要发送命令切换为短焦模式
 短焦画面支持的最大放大倍数暂时没有用处。
 此参数值camera上报，上报之后不再修改。
 */
@interface CLXZoomRatio : CLXBaseSetting
@end

/**
 @brief:光学变倍,表示变动的倍数，取值1~100 默认值：依设备上报的情况为准
 */
@interface CLXOpticalZoom : CLXBaseSetting
@end
/**
 @brief:鱼眼顶装／壁装
 path：profile/general/fisheyeInstallPos
 param: 1/2
 */
@interface CLXfisheyeInstallPos : CLXBaseSetting
@end
@interface CLXP2pthumb : CLXBaseSetting
@end
/**
 @brief:双工语音
 */
@interface CLXFullDuplexTalk : CLXBaseSetting
@end
/**
 @brief:时光相册开关
 path：profile/general/hlStatus
 param: 取值On、OffByManual
 */
@interface CLXHlStatus : CLXBaseSetting
@end
/**
 @brief:时光相册浓缩周期
 path：profile/general/hlPeroid
 param: 1，2，3，4
 1表示一天周期；
 2表示一周周期；
 3表示一个月周期；
 4表示三个月周期；
 */
@interface CLXHlPeroid : CLXBaseSetting
@end
/**
 @brief:表示相册的浓缩频率，单位为分钟
 profile/general/hlFrequency
 param: 30
 */
@interface CLXHlFrequency : CLXBaseSetting
@end
/**
 @brief:机械快门开关
 */
@interface CLXMechicalShutter : CLXBaseSetting
@end
/**
 @brief:开机欢迎词开关
 path：profile/general/bootSound
 value: On/Off
 */
@interface CLXBootSound : CLXBaseSetting
@end
/**
 @brief:本地录制
 path：profile/general/localRecording
 */
@interface CLXLocalRecording : CLXBaseSetting
@end
/**
 @brief:截图支持水印功能开关
 path：profile/general/screenshotWatermark
 param: On,Off
 */
@interface CLXScreenshotWatermark : CLXBaseSetting
@end
/**
 @brief:视频收藏录像时长设置
 path：profile/general/videoRecordTime
 param: 300
 表示视频收藏录像时长，取值15-600 ,单位分秒;默认300秒
 */
@interface CLXVideoRecordTime : CLXBaseSetting
@end
/**
 @brief:灯光控制
 path：profile/general/light
 param: 0：关 1：开 2：自动
 */
@interface CLXLight : CLXBaseSetting
@end
/**
 @brief:灯光控制能力Feature
 path：profile/general/lightFeature
 param: 6
 如110 对应的十进制6，表示有关和开的能力，没有自动的能力。
 */
@interface CLXLightFeature : CLXBaseSetting
@end
/**
 @brief:声光控制配置
 path：profile/general/acoustoOptic
 param: 取值0，1、2
 表示声光控制开关，取值0，1、2，0：关 1：开 2：自动
 */
@interface CLXAcoustoOptic : CLXBaseSetting
@end
/**
 @brief:声光控制能力Feature, 非设置项
 path：profile/general/acoustoOpticFeature
 param: 7
 从高位到低位依次表示关、开、自动。
 如 111 对应的十进制7，表示有关、开和自动的能力。
 */
@interface CLXAcoustoOpticFeature : CLXBaseSetting
@end
/**
 @brief:声光报警能力Feature, 非设置项
 path：profile/general/acoustoOpticAlarmFeature
 param: 3
 表示声光控制能力集，目前使用两位二进制码表示然后转成对应的十进制数值
 从高位到低位依次表示声音、闪灯报警能力
 如 11 对应的十进制3，表示有声音报警和闪灯报警的能力。
 */
@interface CLXAcoustoOpticAlarmFeature : CLXBaseSetting
@end
/**
 @brief:ptz全景拼接
 profile/general/ptzPano
 support: 1/0
 */
@interface CLXPtzPano : CLXBaseSetting
@end
/**
 @brief:自动巡航开关
 profile/general/autoCruise
 param: 取值On、OffByManual
 表示云台设备自动巡航开关状态，取值On、OffByManual，默认OffByManual
 */
@interface CLXAutoCruise : CLXBaseSetting
@end
/**
 @brief:设置IPC自动巡航模式
 path：profile/general/cruiseMode
 param: 0：360度模式，1：点位模式， 默认值：0
 */
@interface CLXCruiseMode : CLXBaseSetting
@end

/**
 @brief:自动巡航开关
 path：profile/general/cruiseSpeed
 param: 巡航虚度，0：慢，1：中，2：快， 默认值：1
 */
@interface CLXCruiseSpeed : CLXBaseSetting
@end
/**
 @brief:设置IPC自动巡航点位value，传入CLXCruisePoint的points属性
 */
@interface CLXCruisePointValue : NSObject
@property (nonatomic, assign) NSInteger id;           // -> 不重复序列号
@property (nonatomic, assign) NSInteger tilt;         // -> PTZ 的tilt
@property (nonatomic, assign) NSInteger pan;          // -> PTZ 的pan
@end
/**
 @brief:设置IPC自动巡航点位
 param：profile/general/cruisePoint
 */
@interface CLXCruisePoint : NSObject
@property (nonatomic, copy) NSString *support;
@property (nonatomic, copy) NSString *pst;          // -> 更新时间，时间戳（秒）, utc 时间, 用来区分更新点
@property (nonatomic, strong) NSObject *points;     // -> 点位信息，赋值CLXCruisePointValue数组
@end

/**
 @brief:设置IPC自动巡航时间
 path：profile/general/cruiseSchedules
 param: 设置定时钟， 设置参考 @see CLXBaseSchedule
 */
@interface CLXCruiseSchedules : CLXBaseSchedule
@end
/**
 @brief:SD卡录像时长
 profile/general/sdCardRecordDuration
 param: -1
 表示支持 SD卡录制配置，15s，30s，45s，-1(永久)； 默认：15
 */
@interface CLXSdCardRecordDuration : CLXBaseSetting
@end

/**
 @brief:设备是否有双目能力
 profile/general/binoCam
 param: 0:不支持 / 1:支持
 */
@interface CLXBinoCam : CLXBaseSetting
@end
/**
 @brief:双目设备字节
 profile/general/binoParam
 support: 600字节码
 */
@interface CLXBinoParam : CLXBaseSetting
@end
/**
 @brief:定时关闭通知计划
 profile/alerts/scheduleNotSendAlerts
 */
@interface CLXScheduleNotSendAlerts : CLXBaseSchedule
@end
/**
 @brief:设备类型
 profile/general/deviceType
 */
@interface CLXDeviceTypeModel : CLXBaseSetting
@end
/**
 @brief:声光报警时长配置
 path: profile/general/acoustoOpticAlarmDur
 param: 15 (default)
 */
@interface CLXAcoustoOpticAlarmDur : CLXBaseSetting
@end
/**
 @brief:视频上传开关
 path: profile/general/videoRecord
 param: On、OffByManual
 On：录制视频(default) OffByManual：停止录制视频
 */
@interface CLXVideoRecord : CLXBaseSetting
@end

/**
 @brief: 设置画面隐私遮蔽区域信息数据
 */
@interface CLXPrivacyRegionList : NSObject
@property (nonatomic, copy) NSString *id;         // -> 区域编号
@property (nonatomic, copy) NSString *left;       // -> 距离左边的距离
@property (nonatomic, copy) NSString *top;        // -> 距离上面的距离
@property (nonatomic, copy) NSString *width;      // -> 区域的宽度
@property (nonatomic, copy) NSString *height;     // -> 区域的高度
@property (nonatomic, copy) NSString *a;          // -> 区域的透明度（暂不支持）
@property (nonatomic, copy) NSString *r;          // -> 区域颜色，rgb中的红色的值，默认值：0
@property (nonatomic, copy) NSString *g;          // -> 区域颜色，rgb中的绿色的值，默认值：0
@property (nonatomic, copy) NSString *b;          // -> 区域颜色，rgb中的蓝色的值，默认值：0
@end

/**
 @brief:设置画面隐私遮蔽区域
 path: profile/general/privacyRegion
 param: @see CLXPrivacyRegionList
 */
@interface CLXPrivacyRegion : NSObject
// Value ： CLXPrivacyRegionList
@property (nonatomic, strong) NSObject *privacyRegionList;
@property (nonatomic, copy) NSString *support;
@end

/**
 @brief:画面畸变矫正开关
 path: profile/general/videoAdjust
 param: 畸变矫正开关，取值On，OffByManual
 */
@interface CLXVideoAdjust : CLXBaseSetting
@end

/**
 @brief:画面畸变矫正配置数据
 path: profile/general/videoAdjustData
 param: 畸变矫正数据，0.111,2.09,1.002...
 */
@interface CLXVideoAdjustData : CLXBaseSetting
@end

/**
 @brief:子设备是否支持PTZ;
 path:profile/general/ptz
 */
@interface CLXSubDevicePTZ : CLXBaseSetting
@end

/**
 @brief:子设备是否支持麦克风;
 path:profile/general/mic
 */
@interface CLXSubDeviceMic : CLXBaseSetting
@end

/**
 @brief:子设备是否支持扬声器;
 path:profile/general/speaker
 */
@interface CLXSubDeviceSpeaker : CLXBaseSetting
@end

/**
 @brief:人脸识别参数;
 path:profile/general/faceRecognitionArgs
 */
@interface CLXFaceRecognitionArgsValue : NSObject
@property (nonatomic, strong) NSString *on; // 人脸检测功能开关
@property (nonatomic, assign) NSInteger maxNum; // 最大支持的人脸数
@property (nonatomic, assign) NSInteger fdThre; // 人脸阈值 0-1000
@property (nonatomic, assign) NSInteger genderThre; // 性别阈值 0-1000
@property (nonatomic, assign) NSInteger clarityThre; // 清晰度阈值 0-1000
@property (nonatomic, assign) NSInteger angleThre; // 角度阈值 0-1000
@property (nonatomic, assign) NSInteger imgQualityThre; // 图片质量 0-1000
@property (nonatomic, assign) NSInteger minSize; // 最小支持人脸尺寸
@property (nonatomic, assign) NSInteger maxSize; // 最大支持人脸尺寸
@property (nonatomic, assign) NSInteger reSizeLen; // 尺寸80-600之间整数,isResize必须设置为"1"才生效
@property (nonatomic, strong) NSString *isResize; // 是否扣取Resize以后的图@"0"/@"1"
@property (nonatomic, assign) NSInteger imgScale; // 人脸往外扩展的尺度,范围1000-2000,越大扩展的越大
@end

@interface CLXFaceRecognitionArgs : NSObject
@property (nonatomic, strong) NSString *support;
@property (nonatomic, strong) NSObject *args;
@end

/**
 @brief:动态范围图像开关
 path:profile/general/HDR
 param:On/Off 开启关闭
 */
@interface CLXHDR : CLXBaseSetting
@end

/**
 @brief:强拆告警开关
 表示强拆门铃告警开关，由camera上报，由App更新，值变更需要通知Camera
 path:profile/general/forceDestroyAlert
 value:On|Off
 On： 开启告警
 Off：关闭告警
 */
@interface CLXForceDestroyAlert : CLXBaseSetting
@end

/**
 @brief:低电量模式开关
 path:profile/general/subStatusLight
 value:On|Off
 */
@interface CLXLowPowerMode : CLXBaseSetting
@end

/**
 @brief:子设备告警指示灯开关
 path:profile/general/subStatusLight
 value:On|Off
 */
@interface CLXSubStatusLight : CLXBaseSetting
@end

/**
 @brief:低电量模式PIR检测间隔
 path：profile/general/lowPowerPirDetectInterval
 value: On|Off
 */
@interface CLXLowPowerPirDetectInterval : CLXBaseSetting
@end

/**
 @brief:低电量模式录制时长
 path: profile/general/lowPowerRecordDuration
 value: On|Off
 */
@interface CLXLowPowerRecordDuration : CLXBaseSetting
@end

@interface CLXGeneral : NSObject
@property (nonatomic, strong) CLXDVRPlan *DVRPlan;
@property (nonatomic, strong) CLXHDVideo *HDVideo;
@property (nonatomic, strong) CLXAntiFlicker *antiFlicker;
@property (nonatomic, strong) CLXAlarmBuzz *alarmBuzz;
@property (nonatomic, strong) CLXCameraImageRotate *cameraImageRotate;
@property (nonatomic, strong) CLXCameraSound *cameraSound;
@property (nonatomic, strong) CLXCloudRecord *cloudRecord;
@property (nonatomic, strong) CLXDescriptions *descriptions;
@property (nonatomic, strong) CLXDeviceId *deviceId;
@property (nonatomic, strong) CLXDeviceTypeModel *deviceType;
@property (nonatomic, strong) CLXEmailNotification *emailNotification;
@property (nonatomic, strong) CLXFaceDetection *faceDetection;
@property (nonatomic, strong) CLXImage *image;
@property (nonatomic, strong) CLXImageType *imageType;
@property (nonatomic, strong) CLXImageTimingLevel *imageTimingLevel;
@property (nonatomic, strong) CLXImageTimingLevels *imageTimingLevels;
@property (nonatomic, strong) CLXImageTimingSchedule *imageTimingSchedule;
@property (nonatomic, strong) CLXInfraredLight *infraredLight;
@property (nonatomic, strong) CLXMacAddress *macAddress;
@property (nonatomic, strong) CLXMagicZoom *magicZoom;
@property (nonatomic, strong) CLXModel *model;
@property (nonatomic, strong) CLXMotionRegions *motionRegions;
@property (nonatomic, strong) CLXMotionDetection *motionDetection;
@property (nonatomic, strong) CLXMotionSensitivity *motionSensitivity;
@property (nonatomic, strong) CLXNetworkQuality *networkQuality;
@property (nonatomic, strong) CLXNightVision *nightVision;
@property (nonatomic, strong) CLXNightVisionSensitivity *nightVisionSensitivity;
@property (nonatomic, strong) CLXNotificationInterval *notificationInterval;
@property (nonatomic, strong) CLXOfflineConfig *offlineConfig;
@property (nonatomic, strong) CLXPhoneNotification *phoneNotification;
@property (nonatomic, strong) CLXReboot *reboot;
@property (nonatomic, strong) CLXRecordTo *recordTo;
@property (nonatomic, strong) CLXSelfDefine *selfDefine;
@property (nonatomic, strong) CLXSdCard *sdCard;
@property (nonatomic, strong) CLXSdcardFeature *sdcardFeature;
@property (nonatomic, strong) CLXScheduleCloudRecord *scheduleCloudRecord;
@property (nonatomic, strong) CLXScheduleMute *scheduleMute;
@property (nonatomic, strong) CLXScheduleTurnOff *scheduleTurnOff;
@property (nonatomic, strong) CLXSoundDetection *soundDetection;
@property (nonatomic, strong) CLXSoundSensitivity *soundSensitivity;
@property (nonatomic, strong) CLXStatus *status;
@property (nonatomic, strong) CLXStatusLight *statusLight;
@property (nonatomic, strong) CLXTamperDetection *tamperDetection;
@property (nonatomic, strong) CLXTimeZone *timeZone;
@property (nonatomic, strong) CLXTimeOSD *timeOSD;
@property (nonatomic, strong) CLXTitle *title;
@property (nonatomic, strong) CLXVideoQuality *videoQuality;
@property (nonatomic, strong) CLXVolumeMute *volumeMute;
@property (nonatomic, strong) CLXWebSocket *webSocket;
@property (nonatomic, strong) CLXWifiNetWork *wifiNetWork;
@property (nonatomic, strong) CLXWifiQuality *wifiQuality;
@property (nonatomic, strong) CLXLightIntensity *lightIntensity;
@property (nonatomic, strong) CLXG4NetWork *g4NetWork;
@property (nonatomic, strong) CLXG4Location *g4Location;
@property (nonatomic, strong) CLXRichText *richText;
@property (nonatomic, strong) CLXAudioVideo *audioVideo;
@property (nonatomic, strong) CLXPIRSensitivity *PIRSensitivity;
@property (nonatomic, strong) CLXPIRStatus *PIRStatus;
@property (nonatomic, strong) CLXPIRDetection *PIRDetection;
@property (nonatomic, strong) CLXBellRing *bellRing;
@property (nonatomic, strong) CLXPeopleDetectionNotify *peopleDetectionNotify;
@property (nonatomic, strong) CLXPeopleDetection *peopleDetection;
@property (nonatomic, strong) CLXRecordTime *recordTime;
@property (nonatomic, strong) CLXTalkVolume *talkVolume;
@property (nonatomic, strong) CLXMotionTrack *motionTrack;
@property (nonatomic, strong) CLXMotionTrackBackTime *motionTrackBackTime;
@property (nonatomic, strong) CLXMotionTrackSensitivity *motionTrackSensitivity;
@property (nonatomic, strong) CLXSoundIDLoc *soundIDLoc;
@property (nonatomic, strong) CLXSoundIDLocDuration *soundIDLocDuration;
@property (nonatomic, strong) CLXSoundIDLocVolume *soundIDLocVolume;
@property (nonatomic, strong) CLXIdLocBackTime *idLocBackTime;
@property (nonatomic, strong) CLXAndlink *andlink;
@property (nonatomic, strong) CLXDeviceLensPTZ *deviceLensPTZ;
@property (nonatomic, strong) CLXOfflineSpeechRecongize *offlineSpeechRecongize;
@property (nonatomic, strong) CLXPTZAutoCurise *ptzAutoCurise;
@property (nonatomic, strong) CLXCameraFocus *cameraFocus;
@property (nonatomic, strong) CLXNoPtzPreset *noPtzPreset;
@property (nonatomic, strong) CLXZoomRatio *zoomRatio;
@property (nonatomic, strong) CLXOpticalZoom *opticalZoom;
@property (nonatomic, strong) CLXViewTimeline *viewTimeline;
@property (nonatomic, strong) CLXExtOSD *extOSD;
@property (nonatomic, strong) CLXP2pthumb *p2pthumb;
@property (nonatomic, strong) CLXLiveCtrl *liveCtrl;
@property (nonatomic, strong) CLXFullDuplexTalk *fullDuplexTalk;
@property (nonatomic, strong) CLXHlStatus *hlStatus;
@property (nonatomic, strong) CLXHlPeroid *hlPeroid;
@property (nonatomic, strong) CLXHlFrequency *hlFrequency;
@property (nonatomic, strong) CLXMechicalShutter *mechicalShutter;
@property (nonatomic, strong) CLXBootSound *bootSound;
@property (nonatomic, strong) CLXLocalRecording *localRecording;
@property (nonatomic, strong) CLXScreenshotWatermark *screenshotWatermark;
@property (nonatomic, strong) CLXVideoRecordTime *videoRecordTime;
@property (nonatomic, strong) CLXLight *light;
@property (nonatomic, strong) CLXLightFeature *lightFeature;
@property (nonatomic, strong) CLXAcoustoOptic *acoustoOptic;
@property (nonatomic, strong) CLXAcoustoOpticFeature *acoustoOpticFeature;
@property (nonatomic, strong) CLXRecordModel *recordModel;
@property (nonatomic, strong) CLXAutoTracking *autoTracking;
@property (nonatomic, strong) CLXPtzPano *ptzPano;
@property (nonatomic, strong) CLXAutoCruise *autoCruise;
@property (nonatomic, strong) CLXCruiseSpeed *cruiseSpeed;
@property (nonatomic, strong) CLXCruisePoint *cruisePoint;
@property (nonatomic, strong) CLXCruiseMode *cruiseMode;
@property (nonatomic, strong) CLXSdCardRecordDuration *sdCardRecordDuration;
@property (nonatomic, strong) CLXBinoCam *binoCam;
@property (nonatomic, strong) CLXBinoParam *binoParam;
@property (nonatomic, strong) CLXCruiseSchedules *cruiseSchedules;
@property (nonatomic, strong) CLXVideoAdjust *videoAdjust;
@property (nonatomic, strong) CLXVideoAdjustData *videoAdjustData;
@property (nonatomic, strong) CLXVideoRecord *videoRecord;
@property (nonatomic, strong) CLXPrivacyRegion *privacyRegion;
@property (nonatomic, strong) CLXAcoustoOpticAlarmDur *acoustoOpticAlarmDur;
@property (nonatomic, strong) CLXAcoustoOpticAlarmFeature *acoustoOpticAlarmFeature;
@property (nonatomic, strong) CLXSubDevicePTZ *ptz;
@property (nonatomic, strong) CLXSubDeviceMic *mic;
@property (nonatomic, strong) CLXSubDeviceSpeaker *speaker;
@property (nonatomic, strong) CLXPersonStatus *personStatus;
@property (nonatomic, strong) CLXPersonRegions *personRegion;
@property (nonatomic, strong) CLXPersonSchedules *personSchedules;
@property (nonatomic, strong) CLXPersonDirection *personDirection;
@property (nonatomic, strong) CLXFaceRecognitionArgs *faceRecognitionArgs;
@property (nonatomic, strong) CLXHDR *HDR;
@property (nonatomic, strong) CLXForceDestroyAlert *forceDestroyAlert;
@property (nonatomic, strong) CLXLowPowerMode *lowPowerMode;
@property (nonatomic, strong) CLXSubStatusLight *subStatusLight;
@property (nonatomic, strong) CLXLowPowerPirDetectInterval *lowPowerPirDetectInterval;
@property (nonatomic, strong) CLXLowPowerRecordDuration *lowPowerRecordDuration;
@end

#pragma mark - Alert
@interface CLXAlert : NSObject
@property (nonatomic, strong) CLXScheduleNotSendAlerts *scheduleNotSendAlerts;
@property (nonatomic, strong) CLXBaseSetting *sendAlerts;
@property (nonatomic, strong) CLXBaseSetting *sendMotionAlerts;
@property (nonatomic, strong) CLXBaseSetting *sendOfflineAlerts;
@property (nonatomic, strong) CLXBaseSetting *sendSoundAlerts;
@end

#pragma mark - Setting 最外层
@interface CLXDeviceSetting : NSObject
@property (nonatomic, strong) CLXAlert *alerts;
@property (nonatomic, strong) CLXGeneral *general;
@end
