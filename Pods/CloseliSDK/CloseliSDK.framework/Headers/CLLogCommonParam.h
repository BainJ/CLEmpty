//
//  CLLogCommonParam.h

#import <Foundation/Foundation.h>

@class CLLogDeviceInfo;

/**
 公共参数
 */
@interface CLLogCommonParam : NSObject <NSCopying, NSCoding>

#pragma mark - 全平台公用参数
@property (nonatomic, copy) NSString *ver;              //统计日志自己的版本号
@property (nonatomic, copy) NSString *version;          //应用版本号
@property (nonatomic, copy) NSString *module;           //采集模块
@property (nonatomic, assign) int level;          //日志等级
@property (nonatomic, assign) int64_t eventId;          //日志事件
@property (nonatomic, assign) int mid;            //模块子ID
@property (nonatomic, copy) NSString *uin;              //用户id
@property (nonatomic, strong) NSObject *contents;       //日志内容

#pragma mark - 移动端公用参数
@property (nonatomic, assign) int64_t clackTime;        //单条统计开始时间
@property (nonatomic, copy) NSString *networkType;      //当前网络类型
@property (nonatomic, assign) NSInteger statusCode;     //状态码
@property (nonatomic, copy) NSString *flavors;          //渠道
@property (nonatomic, strong) CLLogDeviceInfo *deviceInfo;    //设备信息

#pragma mark - 性能监测公共参数
@property (nonatomic, assign) int64_t ack;              //-> 服务响应时间 （Socket接口中的ack时间，代表发包成功时间）
@property (nonatomic, assign) int64_t response;         //-> 服务数据返回时间
@property (nonatomic, assign) int64_t ackDiffs;         //-> ack - ClackTime(公共参数里有说明)，响应耗时
@property (nonatomic, assign) int64_t responseDiffs;    //-> response - ClackTime(公共参数里有说明)，总耗时

- (id)initWithEventId:(int64_t)eventId
             contents:(NSObject *)contents
                  ack:(int64_t)ack
             response:(int64_t)response
            clackTime:(int64_t)clackTime
           statusCode:(NSInteger)statusCode
                level:(int)level;
@end

/**
 设备信息
 */
@interface CLLogDeviceInfo : NSObject <NSCoding>

@property (nonatomic, copy) NSString *udid;             //设备唯一标识
@property (nonatomic, copy) NSString *osVersion;        //系统版本
@property (nonatomic, copy) NSString *os;               //设备系统，Android，iOS
@property (nonatomic, copy) NSString *model;            //设备型号， 三星，iPhone6
@property (nonatomic, copy) NSString *local;            //设备地区
@property (nonatomic, copy) NSString *lang;             //设备语言
@property (nonatomic, copy) NSString *country;          //设备国家地域

+ (id)infoWithUDID:(NSString *)UDID
         osVersion:(NSString *)osVersion
                os:(NSString *)os
             model:(NSString *)model
             local:(NSString *)local
              lang:(NSString *)lang
           country:(NSString *)country;
@end
