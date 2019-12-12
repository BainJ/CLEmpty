//
//  CLLogApi.h

#import <Foundation/Foundation.h>

/**
 性能检测公共参数, 统计类标识码段(20000-29999)
 */
@interface CLPerformance : NSObject <NSCopying, NSCoding>
@end

/**
 API检测, 20000
 */
@interface CLApiPerformance : CLPerformance
@property (nonatomic, copy) NSString *url;          //-> 域名
@property (nonatomic, copy) NSString *func;         //-> 函数名
@property (nonatomic, copy) NSString *errorMsg;     //-> 错误信息

/**
 CLApiPerformance工厂类方法

 @return 返回CLApiPerformance
 */
+ (instancetype)infoWithUrl:(NSString *)url
                       func:(NSString *)func
                   errorMsg:(NSString *)errorMsg;
@end

/**
 logon登录检测, 20001
 */
@interface CLLogonPerformance : CLPerformance
@property (nonatomic, assign) int accountType;  //-> 账号类型
@property (nonatomic, copy) NSString *account;      //-> 账号
@property (nonatomic, copy) NSString *macAddress;   //-> mac

+ (instancetype)infoWithAccountType:(int)accountType
                            account:(NSString *)account
                         macAddress:(NSString *)macAddress;
@end

/**
 直播性能监测, 20002
 */
@interface CLLivePerformance : CLPerformance
@property (nonatomic, assign) int type;         //-> 0 ： Relay, 1 ： P2P
@property (nonatomic, copy) NSString *macAddress; //-> 设备唯一标识

+ (instancetype)infoWithType:(int)type macAddress:(NSString *)macAddress;
@end

/**
 添加设备性能监测, 20003
 */
@interface CLAddDevicePerformance : CLPerformance
@property (nonatomic, assign) int type;         //-> 添加类型, 0 ： 有线添加 1 ： 无线添加 2 ： 二维码添加 3 : 更换Wi-Fi
@property (nonatomic, assign) int deviceType;   //-> 设备类型, 0 ： 智能摄像机 1 ： 带网关的智能摄像机 2 ： 独立网关 3 ： 传感器
@property (nonatomic, copy) NSString *content;      //-> 二维码&无线添加时的数据字符串（加密后）

+ (instancetype)infoWithType:(int)type
                  deviceType:(int)deviceType
                     content:(NSString *)content;
@end

/**
 登录性能统计, 20004
 */
@interface CLLoginPerformance : CLPerformance
@property (nonatomic, assign) int type;        //-> 登录类型, 0 ： 账号密码登陆 1 ： 快速登陆

+ (instancetype)infoWithType:(int)type;
@end

/**
 回放性能统计, 20005
 */
@interface CLRePlayPerformance : CLPerformance
@property (nonatomic, assign) int type;        //-> 播放类型, 0 ： Https 1 ： P2P 2 ： Return 3 ： Relay
@property (nonatomic, copy) NSString *macAddress; //-> 设备唯一标识

+ (instancetype)infoWithType:(int)type macAddress:(NSString *)macAddress;
@end

/**
 长链接信令性能统计, 20006
 */
@interface CLRelayMessagePerformance : CLPerformance
@property (nonatomic, copy) NSString *ip;       //-> 链接IP
@property (nonatomic, assign) int port;         //-> 链接Port
@property (nonatomic, assign) int cmd;          //-> 接口命令字
@property (nonatomic, assign) int subcmd;       //-> 接口子命令字
@property (nonatomic, assign) int type;         //-> 长链接类型, 0 ：Logon 1 ：老P2P 2 ：Websocket 3 ：Tcpbuffer（Relay）4 ：新P2P
@property (nonatomic, copy) NSString *macAddress;         //-> 设备唯一标识

+ (instancetype)infoWithIP:(NSString *)ip
                      port:(int)port
                       cmd:(int)cmd
                    subcmd:(int)subcmd
                      type:(int)type
                macAddress:(NSString *)macAddress;
@end

/**
 设备升级性能统计, 20007
 */
@interface CLUpdatePerformance : CLPerformance
@property (nonatomic, assign) int deviceType;         //-> 设备类型
@property (nonatomic, assign) int forceUpdate;        //-> 强制更新
@property (nonatomic, assign) int updateModule;       //-> 升级模块
@property (nonatomic, copy) NSString *currentVersion;     //-> 模块当前版本号
@property (nonatomic, copy) NSString *lastestVersion;         //-> 模块升级版本号
@property (nonatomic, copy) NSString *macAddress;     //-> 设备唯一标识

+ (instancetype)infoWithDeviceType:(int)deviceType
                       forceUpdate:(int)forceUpdate
                      updateModule:(int)updateModule
                    currentVersion:(NSString *)currentVersion
                        newVersion:(NSString *)newVersion
                        macAddress:(NSString *)macAddress;
@end
