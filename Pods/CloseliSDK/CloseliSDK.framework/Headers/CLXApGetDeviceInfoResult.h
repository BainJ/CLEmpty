//
//  CLXApGetDeviceInfoResult.h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class CLXApDeviceInfo;
@class CLXApDeviceSettings;
@interface CLXApGetDeviceInfoResult : NSObject

@property (nonatomic, strong) CLXApDeviceInfo *deviceInfo;
@property (nonatomic, assign) NSInteger code;
@property (nonatomic, copy) NSString *iv2;
@property (nonatomic, copy) NSString *key2;
@property (nonatomic, assign) NSInteger response;
@property (nonatomic, copy) NSString *sessionid;
@property (nonatomic, strong) CLXApDeviceSettings *setting;     //-> 设备设置项
@property (nonatomic, copy) NSString *time;
@property (nonatomic, strong) NSArray *surport;                 //-> 设备支持能力集

@end


@interface CLXApDeviceInfo : NSObject

@property (nonatomic, copy) NSString *encrypt;
@property (nonatomic, copy) NSString *mac;                      //-> 设备Mac
@property (nonatomic, copy) NSString *ip;
@property (nonatomic, assign) NSInteger port;
@property (nonatomic, copy) NSString *module;                   //-> 设备型号
@property (nonatomic, copy) NSString *productType;              //-> 产品型号
@property (nonatomic, copy) NSString *sn;                       //-> 设备ID
@property (nonatomic, copy) NSString *appver;                   //-> 固件版本
@property (nonatomic, copy) NSString *fwver;                    //-> 嵌入式版本
@property (nonatomic, copy) NSString *wifistatus;               //-> Wi-Fi状态，1：已经设置过热点密码，0：未设置热点密码

@property (nonatomic, copy) NSString *preWifiName;
@property (nonatomic, copy) NSString *wifiName;

@end

@interface CLXApDeviceSettings : NSObject

@property (nonatomic, copy) NSString *HD;                       //-> 高标清, on 高清
@property (nonatomic, copy) NSString *ROTATE;                   //-> 旋转180， 0 180
@property (nonatomic, assign) NSInteger LIGHT;                  //-> 灯开关， 0、1
@property (nonatomic, copy) NSString *RecordMode;               //-> sd卡本地录制模式，1: 不录制; 2: 事件录制; 3: 全录制
@property (nonatomic, copy) NSString *RecordDuration;           //-> sd卡录制时长， 15s，30s，45s，-1(永久)
@property (nonatomic, copy) NSString *PirSensitivity;           //-> pir 检测灵敏度
@property (nonatomic, copy) NSString *MotionSensitivity;        //-> motion 检测灵敏度
@property (nonatomic, copy) NSString *Antiflicker;              //-> 防闪烁参数
@property (nonatomic, copy) NSString *CurrentWifi;              //-> 当前Wi-Fi SSID
@property (nonatomic, copy) NSString *PirStatus;
@property (nonatomic, copy) NSString *Led;
@property (nonatomic, assign) NSInteger BatteryStatus;          //-> 电池状态
@property (nonatomic, assign) NSInteger BatteryPercent;         //-> 电池电量百分比

@end

NS_ASSUME_NONNULL_END
