//
//  CLXRegionList.h

#import <Foundation/Foundation.h>

@class CLXRegionListItem;
@class CLXGatewayRegionListItem;

@interface CLXRegionList : NSObject
@property (nonatomic, strong) NSArray<CLXRegionListItem *> *regionList;    //-> 设备机房
@property (nonatomic, strong) NSDictionary *regionConfigList;              //-> 所有的机房，通过region别名对应
@property (nonatomic, strong) NSDictionary *regionResourcesList;           //-> 所有的机房，通过region别名以及path对应
@property (nonatomic, readonly, assign) BOOL isValid;                      //数据是否有效
@end

@interface CLXRegionListItem : NSObject
@property (nonatomic, copy) NSString *region;               //-> 设备机房--别名
@property (nonatomic, copy) NSString *cdsUrl;               //-> 设备机房对应的CDS下载地址
@property (nonatomic, copy) NSString *trafficPackage;       //-> 是否支持定向流量包，1支持，0不支持
@property (nonatomic, assign) NSTimeInterval startTime;          //-> 设备region的开始时间（毫秒)
@property (nonatomic, assign) NSTimeInterval endTime;            //-> 设备region的结束时间（毫秒）

+ (instancetype)infoWithRegion:(NSString *)region
                        cdsUrl:(NSString *)cdsUrl
                trafficPackage:(NSString *)trafficPackage
                     startTime:(NSTimeInterval)startTime
                       endTime:(NSTimeInterval)endTime;
@end



@interface CLXGatewayRegionList : NSObject
@property (nonatomic, strong) NSArray<CLXGatewayRegionListItem *> *regionList;    //-> 设备机房
@property (nonatomic, strong) NSDictionary *regionConfigList;              //-> 所有的机房，通过region别名对应
//@property (nonatomic, strong) NSDictionary *regionResourcesList;           //-> 所有的机房，通过region别名以及path对应
@property (nonatomic, readonly, assign) BOOL isValid;                      //数据是否有效
@end


@interface CLXGatewayRegionListItem : NSObject
@property (nonatomic, copy) NSString *region;               //-> 设备机房--别名
@property (nonatomic, copy) NSString *visServer;               //-> 设备机房对应的CDS下载地址
@property (nonatomic, copy) NSString *trafficPackage;       //-> 是否支持定向流量包，1支持，0不支持
@property (nonatomic, assign) NSTimeInterval startTime;          //-> 设备region的开始时间（毫秒)
@property (nonatomic, assign) NSTimeInterval endTime;            //-> 设备region的结束时间（毫秒）

+ (instancetype)infoWithRegion:(NSString *)region
                     visServer:(NSString *)visServer
                trafficPackage:(NSString *)trafficPackage
                     startTime:(NSTimeInterval)startTime
                       endTime:(NSTimeInterval)endTime;
@end
