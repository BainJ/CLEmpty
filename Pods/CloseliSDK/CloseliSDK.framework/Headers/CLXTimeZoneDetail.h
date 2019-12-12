//
//  CLXTimeZoneDetail.h

#import <Foundation/Foundation.h>

@interface CLXTimeZoneDetail : NSObject<NSCopying>

@property (nonatomic, copy) NSString *timeZoneID;
@property (nonatomic, copy) NSString *timeZoneName;
@property (assign) NSInteger timeZoneOffSet;

- (id)init;
 
@end

#ifdef SUPPORT_US_TIMEZONE
@interface CTimeZoneArea : NSObject<NSCopying>

@property (nonatomic, retain) NSString *areaName;
@property (nonatomic, retain) NSMutableArray *areaTimeZoneList;

- (id)init;
 
@end
#endif
