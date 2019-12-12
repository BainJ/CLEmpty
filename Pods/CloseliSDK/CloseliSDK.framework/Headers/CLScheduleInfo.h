//
//  CLScheduleInfo.h

/**
 *  Specifies a schedule repeat type.
 */
typedef NS_ENUM(NSUInteger, CLXScheduleRepeatType) {
    /**
     *  Only once
     */
    CLXDEVICE_SCHEDULE_REPEAT_ONCE = 0,
    /**
     *  Repeat everyday
     */
    CLXDEVICE_SCHEDULE_REPEAT_EVERYDAY,
    /**
     *  Repeat weekly
     */
    CLXDEVICE_SCHEDULE_REPEAT_WEEKLY,
    /**
     *  Repeat monthly
     */
    CLXDEVICE_SCHEDULE_REPEAT_MONTHLY,
};

typedef NS_ENUM(NSInteger, CLXScheduleType) {
    CLXSCHEDULE_RECORD = 1,
    CLXSCHEDULE_CAMERA = 2,
    CLXSCHEDULE_INFRARED,
    CLXSCHEDULE_NIGHT_VISION,
    CLXSCHEDULE_ALERTS,
    CLXSCHEDULE_SOUNDON,
    CLXSCHEDULE_CAMERA_SOUND,
    CLXSCHEDULE_CLOUD_RECORDING,
    CLXSCHEDULE_PERSON_FLOW, // 客流统计
};

typedef NS_ENUM(NSInteger, CLXScheduleStatus) {
    CLXSCHEDULE_OFF_STATE = 0,
    CLXSCHEDULE_ON_STATE,
};

/*!
 * @brief CLScheduleInfo 摄像头执行schedule信息.
 */

@interface CLScheduleInfo : NSObject <NSCopying>

/*! @cond PRIVATE */

@property (nonatomic, copy) NSString *scheduleName;
@property (nonatomic, assign) NSInteger nScheduleDefaultStateON;        // "1":on/off , "0":off/on
///GUID for this schedule
@property (nonatomic, copy) NSString *scheduleGUID;
///Camera deviceUUID (in CLCameraDevice *)
@property (nonatomic, copy) NSString *deviceUUID;
///Schedule begin time,UTC time.
@property (nonatomic, strong) NSDate *beginTime;
///Schedule end time,UTC time.
@property (nonatomic, strong) NSDate *endTime;
///Schedule repeat type
@property (nonatomic, assign) int nRepeatType;
///Repeat days, combine with eScheduleRepeatDayType, something like DEVICE_SCHEDULE_REPEAT_WEEKLY_SUNDAY | DEVICE_SCHEDULE_REPEAT_WEEKLY_MONDAY
@property (nonatomic, assign) int nRepeatly;
///Schedule status, on or off.
@property (nonatomic, assign) BOOL scheduleON;
@property (nonatomic) NSInteger offAllDay;
@property (nonatomic,assign) NSInteger nScheduleType;  //1.camera on/off schedule,
//2.normal schedule.
//3.红外线感应开关
//4.开启Night Vision的schedule的具体列表
//5.发送alerts 的schedule的具体列表


- (NSString *)descriptionString:(NSTimeZone *)timeZone withSupportNewSchedule:(BOOL)isSupportNewSchedule;
- (BOOL)isEqualScheduleInfo:(id)anObject;
- (NSString *)getRepeatStringwithEvery:(BOOL)withEvery withSupportNewSchedule:(BOOL)isSupportNewSchedule;
- (NSInteger)getNRepeatlyFromDate:(NSDate *)date withTimeZone:(NSTimeZone *)timeZone;

+ (CLXScheduleType)scheduleTypeFromConfigurationType:(NSInteger)nType;
+ (void)UTCToLocalWeek: (CLScheduleInfo *)curScheduleInfo withTimeZone:(NSString *)timeZone;
+ (void)LocalToUTCWeek: (CLScheduleInfo *)curScheduleInfo withTimeZone:(NSString *)timeZone;
+ (NSArray *)getAllWeekDayList;

/*! @endcond */

@end
