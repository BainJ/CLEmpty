//
//  CLXSmartLinkDefine.h

#ifndef CLXSmartLinkDefine_h
#define CLXSmartLinkDefine_h

#import <Foundation/Foundation.h>

/**
 @remark 自定义错误码

 - CLXSmartLinkValidationErrorInvalidParam: 无效参数
 */
NS_ENUM(NSInteger) {
    CLXSmartLinkValidationErrorInvalidParam = -1,
};

/**
 @remark 添加设备配网Wi-Fi加密type
 
 - CLXSmartLinkWifiTypeHide: wifi隐藏不可见的的安全级别
 - CLXSmartLinkWifiTypeNone: wifi可以搜索的到（默认）
 - CLXSmartLinkWifiTypeWpa: WPA
 - CLXSmartLinkWifiTypeWpa2: WPA2
 - CLXSmartLinkWifiTypeWep: WEP
 - CLXSmartLinkWifiTypeWpaWpa2: WPA/WPA2
 */
typedef NS_ENUM(NSInteger, CLXSmartLinkWifiType) {
    CLXSmartLinkWifiTypeHide = -1,
    CLXSmartLinkWifiTypeNone = 0,
    CLXSmartLinkWifiTypeWpa,
    CLXSmartLinkWifiTypeWpa2,
    CLXSmartLinkWifiTypeWep,
    CLXSmartLinkWifiTypeWpaWpa2,
};

/**
 @remark smartlink添加设备传输消息格式
 
 - CLXSendCastDataTypeNormal: 发送长消息
 - CLXSendCastDataTypeFast: 发送短消息
 */
typedef NS_ENUM(NSInteger, CLXSendCastDataType) {
    CLXSendCastDataTypeNormal = 1,
    CLXSendCastDataTypeFast   = 2,
};

/**
 @remark smartlink添加设备发送消息方式
 
 - CLXSendCastTypeMulti: 组播（现在默认的是组播）
 - CLXSendCastTypeBroad: 广播
 */
typedef NS_ENUM(NSInteger, CLXSendCastType) {
    CLXSendCastTypeMulti  = 1,
    CLXSendCastTypeBroad  = 2,
};

/**
 @remark smartlink添加设备发送消息加密方式
 
 - CLXSendDataEncryptTypeNormal: 正常模式
 - CLXSendDataEncryptTypeSpecial: 特殊模式，Wi-Fi信息相关不加密
 */
typedef NS_ENUM(NSInteger, CLXSendDataEncryptType) {
    CLXSendDataEncryptTypeNormal,
    CLXSendDataEncryptTypeSpecial
};

#endif /* CLXSmartLinkDefine_h */
