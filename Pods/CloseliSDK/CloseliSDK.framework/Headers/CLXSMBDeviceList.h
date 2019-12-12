#import <Foundation/Foundation.h>

@class CLXSMBDeviceIPlist;

@protocol CLXSMBDeviceList <NSObject>
@property (nonatomic, copy) NSString *ID;
@property (nonatomic, copy) NSString *deviceid;
@property (nonatomic, copy) NSString *deviceName;
@property (nonatomic, copy) NSString *region;
@property (nonatomic, copy) NSString *deviceStatus;
@property (nonatomic, copy) NSString *msgProtoType;
@property (nonatomic, copy) NSString *productkey;
@property (nonatomic, copy) NSString *modelId;
@property (nonatomic, copy) NSString *channelNo;
@property (nonatomic, copy) NSString *deviceTag;
@property (nonatomic, copy) NSString *onlineStatus;
@property (nonatomic, copy) NSString *servicename;
@property (nonatomic, copy) NSString *starttime;
@property (nonatomic, copy) NSString *endtime;
@property (nonatomic, copy) NSString *comment;
@property (nonatomic, copy) NSString *star; // 设备收藏状态："0" 表示未收藏 ，"1" 表示已收藏（私有设备才有)
@property (nonatomic, copy) NSString *entryId;
@property (nonatomic, copy) NSString *channelId;
@property (nonatomic, copy) NSString *manufacturer; // 厂商
@property (nonatomic, copy) NSString *parentChannelid; // 设备的父通道ID
@property (nonatomic, assign) int deviceType; //0 私有 1国标
@property (nonatomic, assign) int ptzType; // 1-球机；2-半球；3-固定枪机；4-遥控枪机
@property (nonatomic, assign) unsigned long long createTime;
@property (nonatomic, copy) NSString *modifyTime;
@property (nonatomic, copy) NSString *token;
@property (nonatomic, copy) NSString *name;

@property (nonatomic, assign) int hasPackage; // 0:没有套餐，1：有套餐
@property (nonatomic, copy) NSString *status; // 设备状态：1 正常， 0 异常 正常表示设备在线，其他的情况都属于异常
@property (nonatomic, copy) NSString *model; // 设备型号
@property (nonatomic, copy) NSString *type; // 设备类型: 2 表示该节点的NVR，1 表示该节点有子设备， 0表示本身就是设备


@property (nonatomic, retain) NSArray<CLXSMBDeviceIPlist *> *iplist;

@end

@interface CLXSMBDeviceList : NSObject<CLXSMBDeviceList>


@end

@interface CLXSMBDeviceIPlist : NSObject

@property (nonatomic, copy) NSString *channelname;
@property (nonatomic, copy) NSString *deviceid;
@property (nonatomic, copy) NSString *relayhost;
@property (nonatomic, copy) NSString *relayport;
@property (nonatomic, copy) NSString *uid;

@end
