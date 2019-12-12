//
//  CLTimeLineView.h

#import "CLTimelineData.h"

@protocol TimelineViewDelegate;
@protocol TimelineViewDataSource;

@interface CLTimeLineView : UIView

@property (nonatomic, weak) id<TimelineViewDelegate> delegate;
@property (nonatomic, weak) id<TimelineViewDataSource> dataSource;
@property (nonatomic, assign) UIInterfaceOrientation mOrietation;

/**
 *  init CLTimeLineView with Frame
 *
 *  @param frame CLTimeLineView Frame
 *
 *  @return CLTimeLineView
 */
- (id)initWithFrame:(CGRect)frame;

/**
 *  refresh UI.when update dataSource or other change(like set event color eg.)
 *
 *  @param endDate the UI will be refreshed before the end Date.
 */
- (void)refresh:(NSDate *)endDate;

/**
 *  CLTimeLineView blue line will scroll to the date
 *
 *  @param date the date when you want to scroll to
 */
- (void)scrollToDate:(NSDate *)date;

/**
 *  CLTimeLineView blue line will scroll to the current date, UI will be refreshed, the center blue mark will be updated .if it is not play timeline ,it will scroll to the end
 *
 *  @param currentDate the player is playing date
 *  @param bTimeline   YES is play timeline, NO is play live video.
 */
- (void)updateCurrentPlayTime:(NSDate *)currentDate isPlayTimeline:(BOOL)bTimeline;

/**
 *  the center blue mark will be updated with date.
 *
 *  @param date the player is playing date.
 */
- (void)updateNowplayingMarkbyDate:(NSDate *)date;

/**
 *  set event color show in CLTimeLineView with event type.
 *
 *  @param colorHexString color Hex string .like white color use 0xFFFFFF.
 *  @param eventType      the type EventType_E.
 */
- (void)eventTypeColor:(NSString *)colorHexString eventType:(CLXEventMode)eventType;

/**
 *  set section color show in CLTimeLineView.
 *
 *  @param colorHexString color Hex string .like white color use 0xFFFFFF.
 */
- (void)sectionColor:(NSString *)colorHexString;

/**
 *  set CLTimeLineView color UI scale
 *
 *  @param scale UI scale.//1 means 24hour/page, 12 means 2hour/page, 18 means 1.5hour/page...
 */
- (void)zoomTo:(NSInteger)scale;

/**
 *  CLTimeLineView max UI Scale
 *
 *  @return max UI Scale. //1 means 24hour/page, 12 means 2hour/page, 18 means 1.5hour/page...
 */
- (NSInteger)maxZoomScale;

/**
 *  CLTimeLineView min UI Scale
 *
 *  @return min UI Scale.//1 means 24hour/page, 12 means 2hour/page, 18 means 1.5hour/page...
 */
- (NSInteger)minZoomScale;

/**
 *  Update CLTimeLineView timeZone
 *  you must call -reflesh: after call this method
 *
 */
- (void)setTimelineOffsetByTimeZone:(NSTimeZone *)cameraTimeZone;

@end

@protocol TimelineViewDelegate

@required
/**
 *  Callback the position time ,where the blue line show in the CLTimeLineView
 *
 *  @param timelineView CLTimeLineView
 *  @param currentDate  the blue line position time
 */
- (void)getCurrentCenterMark:(CLTimeLineView *)timelineView positionTime:(NSDate *)currentDate;

@optional
/**
 *  Callback when CLTimeLineView begin to scroll
 */
- (void)timelineStartScroll;

@end

@protocol TimelineViewDataSource

@required
/**
 *  time length with seconds of CLTimeLineView
 *
 *  @return seconds of user purchase plan time length
 */
- (double)secondsOfTimelineLength;
/**
 *  CLTimelineData which will show in CLTimeLineView
 *
 *  @param timelineView CLTimeLineView
 *
 *  @return CLTimelineData which you get from interface getTimelineWithCamera
 */
- (CLTimelineData *)timelineDataInTimelineView:(CLTimeLineView *)timelineView;

@end
