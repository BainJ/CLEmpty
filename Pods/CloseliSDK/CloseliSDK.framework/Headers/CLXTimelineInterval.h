//
//  CLXTimelineInterval.h

#ifndef CLXTimelineInterval_h
#define CLXTimelineInterval_h

#define HOUR_INTERVAL 3600 * 1000

//单位为毫秒
typedef NS_ENUM (NSInteger, CLXTimelineInterval) {
    CLTimeline_Interval_12H = 12 * HOUR_INTERVAL,          //0 (Default, 开始时间+12小时)
    CLTimeline_Interval_Foward = -24 * HOUR_INTERVAL,      //1 (获取最新数据)，时间间隔不能超过1天
    CLTimeline_Interval_1H = 1 * HOUR_INTERVAL,            //2 (开始时间+1小时)
    CLTimeline_Interval_6H = 6 * HOUR_INTERVAL,            //3 (开始时间+6小时)
    CLTimeline_Interval_24H = 24 * HOUR_INTERVAL,          //4 (开始时间+24小时)
    CLTimeline_Interval_48H = 48 * HOUR_INTERVAL,          //5 (开始时间+48小时)
    CLTimeline_Interval_7D = 7 * 24 * HOUR_INTERVAL,       //6 (开始时间+7天)
};

#endif /* CLXTimelineInterval_h */
