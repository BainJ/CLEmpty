
#import "CLXTimeZoneDetail.h"

#define NODE_TIMEZONE @"timezone"
#define NODE_TIMEZONE_ID @"id"

#ifdef SUPPORT_US_TIMEZONE
#define NODE_AREA   @"area"
#define NODE_AREA_NAME    @"name"
#endif

@interface CLXTimeZoneXMLParser : NSObject<NSXMLParserDelegate> {
    @private
    NSMutableArray* timezoneList;
    NSMutableString* currString;
#ifdef SUPPORT_US_TIMEZONE
    BOOL bSupportArea;
#endif
}

@property (nonatomic, copy) NSString *currElementName;

- (NSMutableArray *)getTimeZoneListArray;
#ifdef SUPPORT_US_TIMEZONE
- (NSMutableArray *)getTimeZoneListArrayByArea;
#endif
@end
