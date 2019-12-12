#import <Foundation/Foundation.h>

@class CLXSMBStoreList;
@protocol CLXSMBStoreList <NSObject>

@property (nonatomic, assign) NSInteger allChildcount;
@property (nonatomic, strong) NSArray <CLXSMBStoreList *>*child;
@property (nonatomic, assign) NSInteger childcount;
@property (nonatomic, assign) NSInteger deviceOnlineCount;
@property (nonatomic, assign) NSInteger devicecount;
@property (nonatomic, assign) NSInteger eventCount;
@property (nonatomic, assign) BOOL hasChild;
@property (nonatomic, copy) NSString *latitude;
@property (nonatomic, copy) NSString *level;
@property (nonatomic, copy) NSString *location;
@property (nonatomic, copy) NSString *longitude;
@property (nonatomic, copy) NSString *parentId;
@property (nonatomic, copy) NSString *region;
@property (nonatomic, copy) NSString *remark;
@property (nonatomic, copy) NSString *shortToken;
@property (nonatomic, copy) NSString *storeCode;
@property (nonatomic, copy) NSString *storeId;
@property (nonatomic, copy) NSString *storeName;
@property (nonatomic, assign) NSInteger storeOrder;
@property (nonatomic, assign) NSInteger storeStatus;
@property (nonatomic, copy) NSString *storeType;
@property (nonatomic, assign) NSInteger type;
@property (nonatomic, copy) NSString *unifiedId;
@property (nonatomic, copy) NSString *userToken;
@property (nonatomic, copy) NSString *username;

@end

@interface CLXSMBStoreList : NSObject <CLXSMBStoreList>

@end
