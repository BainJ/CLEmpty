//
//  CLTimelineStorage.h

#import <Foundation/Foundation.h>

/**
 @brief timeline存储
 */
@interface CLTimelineStorage : NSObject

///device ID
@property (nonatomic, copy) NSString *deviceUUID;
///Total storage time for this camera, in seconds
@property (nonatomic, assign) unsigned long long totalStorageTime;
///Used time for this camera
@property (nonatomic, assign) unsigned long long usedStorageTime;

@end
