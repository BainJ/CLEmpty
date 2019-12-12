//
//  CLXDeviceUpdateInfo.h

#import <Foundation/Foundation.h>
#import "CLCameraUpdateInfo.h"

@protocol CLXDeviceUpdateInfo <NSObject>

@property (nonatomic, copy) NSString *deviceId;                         //设备ID
@property (nonatomic, assign) NSInteger serviceType;                    //服务类型
@property (nonatomic, copy) NSString *updateServiceVersion;             //需要更新服务的最新版本
@property (nonatomic, strong) NSDictionary *currentServiceVersion;      //当前所有服务的版本
@property (nonatomic, copy) NSString *checksum;                         //校验码
@property (nonatomic, copy) NSString *url;                              //更新url
@property (nonatomic, assign) NSInteger updateType;                      //更新类型，0:无、1:有更新、2:强制更新
@property (nonatomic, copy) NSString *deviceDesc;                       //描述

@end

@interface CLXDeviceUpdateInfo : NSObject<CLXDeviceUpdateInfo>

//临时新老model转换
+ (CLCameraUpdateInfo *)transferUpdateInfoFromNewModel:(CLXDeviceUpdateInfo *)updateInfo;

@end
