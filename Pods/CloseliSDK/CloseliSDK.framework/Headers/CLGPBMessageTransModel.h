
#import <Foundation/Foundation.h>

@class RequestAddress;
@class ActionModel;
@class AddressModel;
/**
 @brief 对应MapFieldEntry，其中value为数据对象的JSONString
 */
@interface MapFieldEntryObj : NSObject

@property (nonatomic, copy) NSString *key;
@property (nonatomic, copy) NSString *value;

@end

/**
 @brief 对应DeviceAction，其中propertiesArray可以为多条Entry的数组
 */
@interface DeviceActionObj : NSObject

@property (nonatomic, readwrite) int actiontype;
@property (nonatomic, strong) NSMutableArray<MapFieldEntryObj *> *propertiesArray;

@end

@class DeviceInfo;
/**
 @brief 对应DeviceInfo，提供Device相关的基本信息，该类后续请支持扩展
 */
@interface DeviceInfoObj : NSObject

@property (nonatomic, copy) NSString *devicetype;
@property (nonatomic, copy) NSString *version;
@property (nonatomic, copy) NSString *imei;
@property (nonatomic, readwrite) int ostype;
@property (nonatomic, copy) NSString *osversion;
@property (nonatomic, readwrite) uint32_t channel;

+ (DeviceInfo *)getDeviceInfo;

@end

#pragma mark - Address
/**
 @brief 对应ActionModel
 */
@interface ActionModelObj : NSObject

@property (nonatomic, readwrite, copy) NSString *key;
@property (nonatomic, readwrite, copy) NSString *value;

+ (ActionModel *)transferModel:(ActionModelObj *)obj;
@end

#pragma mark - AddressModel
/**
 @brief 对应AddressModel
 */
@interface AddressModelObj : NSObject

@property (nonatomic, readwrite, copy) NSString *name;
@property (nonatomic, readwrite, copy) NSString *URL;
@property (nonatomic, readwrite) BOOL backup;

+ (AddressModel *)transferModel:(AddressModelObj *)obj;
@end

/**
 @brief 对应RequestAddress
 */
@interface RequestAddressObj : NSObject

@property (nonatomic, readwrite, copy) NSString *productKey;
@property (nonatomic, readwrite, copy) NSString *deviceUnique;
@property (nonatomic, readwrite, strong) NSMutableArray<NSString*> *servicesArray;
@property (nonatomic, readwrite, copy) NSString *version;

+ (RequestAddress *)transferModel:(RequestAddressObj *)obj;
@end

/**
 @brief 对应AckNotice
 */
@interface AckNoticeObj : NSObject

@property (nonatomic, readwrite) int noticeType;
@property (nonatomic, readwrite, strong) NSMutableArray<ActionModelObj *> *actionsArray;
@property (nonatomic, readwrite, strong) NSMutableArray<AddressModelObj *> *addressesArray;

@end

/**
 @brief 对应DNSMessage，提供DNS相关的基本信息
 */
@interface DNSMessageObj : NSObject

@property (nonatomic, readwrite) int messageType;
@property (nonatomic, readwrite, strong) RequestAddressObj *requestAddress;
@property (nonatomic, readwrite, strong) AckNoticeObj *ackNotice;
@property (nonatomic, readwrite, copy) NSString *requestId;
@property (nonatomic, readwrite) uint64_t timestamp;
@property (nonatomic, readwrite, copy) NSString *sign;

/**
 @brief DNSMessageObj转换为 NSData

 @return NSData
 */
- (NSData *)data;

/**
 @brief NSData 转化为对象

 @param data NSData
 @param errorPtr errorPtr
 @return DNSMessageObj对象
 */
+ (instancetype)parseFromData:(NSData *)data error:(NSError **)errorPtr;

@end

