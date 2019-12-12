
//两路开关，status：On - Off - OffByManual
FOUNDATION_EXPORT NSString *const CLXDeviceSettingTextDoubleSwitchStatusOn;
FOUNDATION_EXPORT NSString *const CLXDeviceSettingTextDoubleSwitchStatusOff;
FOUNDATION_EXPORT NSString *const CLXDeviceSettingTextDoubleSwitchStatusOffByManual;

//三路开关，status：On - Off - OffByManual - Auto
FOUNDATION_EXPORT NSString *const CLXDeviceSettingTextTrinomialSwitchStatusOn;
FOUNDATION_EXPORT NSString *const CLXDeviceSettingTextTrinomialSwitchStatusOff;
FOUNDATION_EXPORT NSString *const CLXDeviceSettingTextTrinomialSwitchStatusOffByManual;
FOUNDATION_EXPORT NSString *const CLXDeviceSettingTextTrinomialSwitchStatusAuto;

//闪烁频率，value（HZ）：50HZ - 60HZ
FOUNDATION_EXPORT NSString *const CLXDeviceSettingTextFlickerFrequency_50HZ;
FOUNDATION_EXPORT NSString *const CLXDeviceSettingTextFlickerFrequency_60HZ;

//定时间隔，value(分钟)：30min - 60min - 120min - 240min
FOUNDATION_EXPORT NSString *const CLXDeviceSettingTextTimerIntervel_30m;
FOUNDATION_EXPORT NSString *const CLXDeviceSettingTextTimerIntervel_60m;
FOUNDATION_EXPORT NSString *const CLXDeviceSettingTextTimerIntervel_120m;
FOUNDATION_EXPORT NSString *const CLXDeviceSettingTextTimerIntervel_240m;

//通知频率，value(分钟)：0min - 10min - 30min - 60min
FOUNDATION_EXPORT NSString *const CLXDeviceSettingTextNotificationIntervel_0HZ;
FOUNDATION_EXPORT NSString *const CLXDeviceSettingTextNotificationIntervel_10HZ;
FOUNDATION_EXPORT NSString *const CLXDeviceSettingTextNotificationIntervel_30HZ;
FOUNDATION_EXPORT NSString *const CLXDeviceSettingTextNotificationIntervel_60HZ;

/**
 @remark setting传值为int类型的数据

 - CLXDeviceSettingIntTypeOff: 关
 - CLXDeviceSettingIntTypeOn: 开
 - CLXDeviceSettingIntTypeAuto: 自动
 */
typedef NS_ENUM(NSInteger, CLXDeviceSettingIntType) {
    CLXDeviceSettingIntTypeOff,
    CLXDeviceSettingIntTypeOn,
    CLXDeviceSettingIntTypeAuto
};
