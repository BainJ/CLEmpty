//
//  CLWifiInfo.h

#import <Foundation/Foundation.h>

/**
 @brief wifi数据模型
 */
@interface CLXDeviceWifiInfo : NSObject

@property (nonatomic, copy) NSString *bssid;      // bssid
@property (nonatomic, copy) NSString *ssid;       // ssid
@property (nonatomic, copy) NSString *password;   // Wifi密码
@property (nonatomic, copy) NSString *encryption; // 加密方式
@property (assign) NSInteger signal;              // 信号强度，0-5， 数字越大，信号越强
@property (assign) BOOL bConnceted;               // 是否连接

@end
