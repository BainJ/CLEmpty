//
//  CLTimelineConst.h

#ifndef CLTimelineConst_h
#define CLTimelineConst_h

/**
 告警事件类型

 - CLXEventModeMotion: 移动事件
 - CLXEventModeSound: 声音事件
 - CLXEventModeFace: 人脸事件
 - CLXEventModePeople: 人形事件
 - CLXEventModePrivateFR: 自定义人脸识别事件
 - CLXEventModeManualTrunOff: 手动关闭事件
 - CLXEventModeScheduleTrunOff: 计划关闭事件
 - CLXEventModeScheduleTrunOffList: 计划关闭列表事件
 - CLXEventModeTamper: 干预事件
 - CLXEventModeBatteryMode: 电池模式事件
 - CLXEventModePIR: PIR
 - CLXEventModeNormalSound: normal sound
 - CLXEventModeLive: 直播，没有发生门铃事件
 - CLXEventModeCall: 门铃事件
 - CLXEventModeManualRecord: 手动录制事件
 - CLXEventModeManualDoorbellHasBeenRead 门铃已读状态
 - CLXEventModeManualDoorbellUnread 门铃未读状态
 - CLXEventModeHamper: hamper
 - CLXEventModeCheckIn: checkin
 - CLXEventModePirMode: pir mode
 - CLXEventModeEventStart: 事件开始
 - CLXEventModeEventEnd: 事件结束
 - CLXEventModeEventWander: 徘徊事件
 - CLXEventModeEventForceDestroy: 强拆事件
 - CLXEventModeShutterOpen: open
 - CLXEventModeShutterClose: close
 - CLXEventModePowerMode: 电源
 - CLXEventModeBatteryQuantity: Battery Quantity
 - CLXEventModeSelfDelete: self delete
 - CLXEventModeUpgrading: 设备更新事件
 - CLXEventModePIRMotion: PIR与Motion结合
 - CLXEventModeGBMotion : 国标视频异动
 - CLXEventModeAndLinkEvent: Andlink事件
 - CLXEventModePir: PIR
 - CLXEventModeDoorWindow: 门窗感应事件
 - CLXEventModeOtherSensor: other sensor
 - CLXEventModeCommon: 占位字段
 */
typedef NS_ENUM(NSInteger, CLXEventMode) {
    CLXEventModeNull = -1,
    CLXEventModeMotion = 1,
    CLXEventModeSound,
    CLXEventModeFace,
    CLXEventModePeople,
    CLXEventModePrivateFR = 6,
    CLXEventModeManualTrunOff,
    CLXEventModeScheduleTrunOff,
    CLXEventModeScheduleTrunOffList,
    CLXEventModeTamper = 11,
    CLXEventModeBatteryMode = 12,
    CLXEventModePIR = 13,
    CLXEventModeNormalSound = 14,
    CLXEventModeLive = 15,
    CLXEventModeCall = 16,
    CLXEventModeManualRecord = 17,
    CLXEventModeManualDoorbellHasBeenRead = 18,
    CLXEventModeManualDoorbellUnread = 19,
    CLXEventModeHamper = 20,
    CLXEventModeCheckIn = 21,
    CLXEventModePirMode = 22,
    CLXEventModeEventUnAnswerd = 28,
    CLXEventModeEventStart = 36,
    CLXEventModeEventEnd = 37,
    CLXEventModeEventAnswerd = 38,
    CLXEventModeEventWander = 55,
    CLXEventModeEventForceDestroy = 56,
    CLXEventModeBodyInduction = 58,
    CLXEventModeShutterOpen = 100,
    CLXEventModeShutterClose = 101,
    CLXEventModePowerMode = 102,
    CLXEventModeBatteryQuantity = 103,
    CLXEventModeSelfDelete = 120,
    CLXEventModeUpgrading = 121,
    CLXEventModePIRMotion = 131,
    CLXEventModeGBMotion = 1502,
    CLXEventModeAndLinkEvent = 2000,
    CLXEventModePir = 2001,
    CLXEventModeDoorWindow = 2002,
    CLXEventModeOtherSensor = 2003,
    CLXEventModeCommon
};

/**
 timeline event事件类型

 - CLXEVENT_STATUS_STARTTIME_ADD: add starttime
 - CLXEVENT_STATUS_ENDTIME_ADD: add endtime
 - CLXEVENT_STATUS_HANDLING: 处理中
 - CLXEVENT_STATUS_FAILED: 失败
 - CLXEVENT_STATUS_SUCESSFUL: 成功
 - CLXEVENT_STATUS_FAILED_GEN_TN: 生成失败
 - CLXEVENT_STATUS_FAILED_SAVE_TN: 保存失败
 - CLXEVENT_STATUS_FAILED_NO_SECTION_OR_RAW: 失败，没有section
 - CLXEVENT_STATUS_DELETED: 删除
 */
typedef NS_ENUM(NSUInteger, CLXEventStatus) {
    CLXEVENT_STATUS_STARTTIME_ADD,
    CLXEVENT_STATUS_ENDTIME_ADD,
    CLXEVENT_STATUS_HANDLING,
    CLXEVENT_STATUS_FAILED,
    CLXEVENT_STATUS_SUCESSFUL,
    CLXEVENT_STATUS_FAILED_GEN_TN = 6,
    CLXEVENT_STATUS_FAILED_SAVE_TN,
    CLXEVENT_STATUS_FAILED_NO_SECTION_OR_RAW,
    CLXEVENT_STATUS_DELETED,
};

/**
 timeline获取源

 - CLXTimelineSourceCloud: 来自cloud平台
 - CLXTimelineSourceSDCard: 来自SD卡
 */
typedef NS_ENUM(NSUInteger, CLXTimelineSource) {
    CLXTimelineSourceCloud = 1,
    CLXTimelineSourceSDCard,
};

/**
 timeline类型，可以用"|"获取两者

 - CLXTIMELINE_SECTIONS: section，切片片段
 - CLXTIMELINE_EVENTS: event，事件片段
 */
typedef NS_ENUM(NSUInteger, CLXTimelineType) {
    CLXTIMELINE_SECTIONS = 0x0001,
    CLXTIMELINE_EVENTS = 0x0002
};


#endif /* CLTimelineConst_h */
