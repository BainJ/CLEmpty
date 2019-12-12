//
//  CLJSONKey.h

#import <Foundation/Foundation.h>

extern NSString *const DETAIL_JSON_KEY_AUDIOTYPE;
extern NSString *const DETAIL_JSON_KEY_UPDATETYPE;
extern NSString *const DETAIL_JSON_KEY_SDCARD;
extern NSString *const DETAIL_JSON_KEY_WIFINETWORK;
extern NSString *const DETAIL_JSON_KEY_WEBSOCKET;
extern NSString *const DETAIL_JSON_KEY_DVRDAY;
extern NSString *const DETAIL_JSON_KEY_SYSTIME;
extern NSString *const DETAIL_JSON_KEY_CVR_ENDDATE;
extern NSString *const DETAIL_JSON_KEY_FISHEYE;
extern NSString *const DETAIL_JSON_KEY_SHAREID;
extern NSString *const DETAIL_JSON_KEY_STOREINFO;
extern NSString *const DETAIL_JSON_KEY_COMPANYID;
extern NSString *const DETAIL_JSONG_FEATURE;
extern NSString *const DETAIL_JSONG_KEY_TIMEZONE;
extern NSString *const DETAIL_JSON_KEY_HDVIDEO;
extern NSString *const DETAIL_JSON_KEY_OWNERUNIFIEDID;
extern NSString *const DETAIL_JSON_KEY_REALPRICE;
extern NSString *const DETAIL_JSON_KEY_PAYMENTTYPE;
extern NSString *const DETAIL_JSON_KEY_RATESTATUS;
extern NSString *const DETAIL_JSON_KEY_RATEURL;
extern NSString *const DETAIL_JSON_KEY_DEVICEPRICE;
extern NSString *const DETAIL_JSON_KEY_STANDBYSERVICEID;
extern NSString *const DETAIL_JSON_KEY_STANDBYSTARTTIME;
extern NSString *const DETAIL_JSON_KEY_STANDBYENDTIME;
extern NSString *const DETAIL_JSON_KEY_AUTOPAYMENT;
extern NSString *const DETAIL_JSON_KEY_STANDBY;
extern NSString *const DETAIL_JSON_KEY_PURCHASESTATUS;
extern NSString *const DETAIL_JSON_KEY_FULLDUPLEXTALK;
extern NSString *const DETAIL_JSON_KEY_PRIVVIEW;
extern NSString *const DETAIL_JSON_KEY_PRIVPTZ;
extern NSString *const DETAIL_JSON_KEY_DEVICE;
extern NSString *const DETAIL_JSON_KEY_SCENE;
// 灯光控制开关，取值0，1、2，0：关 1：开 2：自动
extern NSString *const DETAIL_JSON_KEY_LIGHT;
extern NSString *const DETAIL_JSON_KEY_LIGHTFEATURE;
extern NSString *const DETAIL_JSON_KEY_SUPPORTLIGHT;
// 声光控制开关，取值0，1、2，0：关 1：开 2：自动
extern NSString *const DETAIL_JSON_KEY_ACOUSTOOPTIC;
extern NSString *const DETAIL_JSON_KEY_ACOUSTOOPTICFEATURE;
extern NSString *const DETAIL_JSON_KEY_SUPPORTACOUSTOOPTIC;
 // 是否支持p2p缩略图 1支持 0不支持
extern NSString *const DETAIL_JSON_KEY_P2PTHUMB;

extern NSString *const DETAIL_JSON_KEY_SOUNDETECTION;
extern NSString *const DETAIL_JSON_KEY_FisheyeInstallPos;
extern NSString *const DETAIL_JSON_KEY_ImageType;
extern NSString *const DETAIL_JSON_KEY_PF_Statistics;
extern NSString *const DETAIL_JSON_KEY_LIVE_CONTROL;
extern NSString *const DETAIL_JSON_KEY_SERVICESTATUS;
extern NSString *const DETAIL_JSON_KEY_STATUS;
extern NSString *const DETAIL_JSON_KEY_TOKEN;
extern NSString *const DETAIL_JSON_KEY_IDVRDAYS;
extern NSString *const DETAIL_JSON_KEY_REAMININGDAYSTOBEEXPIRE;
extern NSString *const DETAIL_JSON_KEY_EXPIREALLOWPLAYBACK;
extern NSString *const DETAIL_JSON_KEY_EXPIRERECORDINGWHITELIST;
extern NSString *const DETAIL_JSON_KEY_SHERAOTHERCOUNT;
//白名单配置
extern NSString *const DETAIL_JSON_KEY_WHITELISTCONFIG;
//whiteListConfig里属性，过期录制
extern NSString *const DETAIL_JSON_KEY_EXPIRERECORDING;
//whiteListConfig里属性，人脸套餐
extern NSString *const DETAIL_JSON_KEY_FACEDETECTION;
extern NSString *const DETAIL_JSON_KEY_FACERECOGNITION;
extern NSString *const DETAIL_JSON_KEY_IF_SUPPORT_OPTICALZOOM;
extern NSString *const DETAIL_JSON_KEY_OPTICALZOOM_VALUE;
extern NSString *const DETAIL_JSON_KEY_VIEW_TIMELINE;
//timeline数据来源 value取值1或者2，1表示从云端获取timeline，2表示从SD卡获取timeline
extern NSString *const DETAIL_JSON_KEY_PLAY_VIDEOS_FROM;
//是否支持云卡切换
extern NSString *const DETAIL_JSON_KEY_SUPPORT_SWITCH_PLAY_VIDEOS_FROM;
//设备更新消息
extern NSString *const UPDATE_JSON_KEY_URL;
extern NSString *const UPDATE_JSON_KEY_SERVICE_TYPE;
extern NSString *const UPDATE_JSON_KEY_CHECKSUM;
extern NSString *const UPDATE_JSON_KEY_NEW_SERVICE_VERSION;
// 升级子设备，升级的时候需带上channelNo参数
extern NSString *const UPDATE_JSON_KEY_CHANNELNO;
extern NSString *const UPDATE_JSON_KEY_RELAY_CONNECT;
// 支持新P2P
extern NSString *const DETAIL_JSON_KEY_NEWP2P;
// 人形跟踪
extern NSString *const DETAIL_JSON_KEY_AUTOTRACKING;
// 是否支持显示屏幕内置时间
extern NSString *const DETAIL_JSON_KEY_SUPPORT_TIMEOSD;
// 屏幕内置时间是否显示
extern NSString *const DETAIL_JSON_KEY_SETTING_TIMEOSD;
// 是否支持灯光亮度设置
extern NSString *const DETAIL_JSON_KEY_SUPPORT_LIGHTINTENSITY;
// 灯光亮度值
extern NSString *const DETAIL_JSON_KEY_SETTING_LIGHTINTENSITY;
// 人形检测
extern NSString *const DETAIL_JSON_KEY_PEOPLEDETECTION;
// 动作检测
extern NSString *const DETAIL_JSON_KEY_MOTIONDETECTION;
// 动作跟踪
extern NSString *const DETAIL_JSON_KEY_MOTIONTRACK;
// 是否支持全景ptz
extern NSString *const DETAIL_JSON_KEY_PTZPANO;

extern NSString *const DETAIL_JSON_KEY_RESOLUTION;

extern NSString *const DETAIL_JSON_KEY_DEVICEANGLE;

extern NSString *const DETAIL_JSON_KEY_PTZAUTOCRUISE;

extern NSString *const DETAIL_JSON_KEY_SETTING_PTZAUTOCRUISE;

// 是否支持摄像头长短焦
extern NSString *const DETAIL_JSON_KEY_SUPPORT_CAMERAFOCUS;
extern NSString *const DETAIL_JSON_KEY_ZOOMRATIO;
// 摄像头长短焦
extern NSString *const DETAIL_JSON_KEY_CAMERAFOCUS;
// 是否支持PTZ 预置位
extern NSString *const DETAIL_JSON_KEY_NOPTZPRESET;
// 是否支持人体感应
extern NSString *const DETAIL_JSON_KEY_PIRDETECTION;
/**
 @brief 服务器返回数据,Json解析时对应的Key
 */
@interface CLJSONKey : NSObject

@end
