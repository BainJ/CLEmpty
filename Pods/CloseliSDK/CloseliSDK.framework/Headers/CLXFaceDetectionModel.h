//
//  CLXFaceDetectionModel.h

#import <Foundation/Foundation.h>

/**
 人脸列表Item
 */
@interface CLXFDFaceListInfoModel : NSObject

@property (nonatomic, copy) NSString *personId;             //-> 人脸唯一标识
@property (nonatomic, copy) NSString *personName;           //-> 人脸名称，如没有命名，返回为""空字符串，表示陌生人；如果有名称就不是陌生人
@property (nonatomic, copy) NSString *pushStatus;           //-> 推送开关，取值1/0，1表示开启，0表示关闭
@property (nonatomic, assign) long long startTime;          //-> 人脸最新的时间，单位毫秒
@property (nonatomic, assign) long times;                   //-> 人脸出现次数（套餐天数内的人脸数量），陌生人才会出现次数
@property (nonatomic, copy) NSString *headerPicUrl;         //-> 图片下载地址
@property (nonatomic, copy) NSString *isVirtual;            //-> 是否聚类生成的虚拟用户, 1表示是，0或空为否
@property (nonatomic, copy) NSString *label;                //-> 人脸标签
@property (nonatomic, assign) long long modifyTime;         //-> 人脸最近出现时间（单位毫秒）
@property (nonatomic, copy) NSString *personList;           //-> 合并后的所有personId列表，逗号隔开

@end

/**
 人脸列表返回model
 */
@interface CLXFDFaceListModel : NSObject

@property (nonatomic, copy) NSString *deviceId;             //-> 设备id
/**
 返回的人脸列表数据
 先展示已经命名的，已经命名的按照最近出现时间倒序展示;
 再展示未命名的，未命名的按照出现次数倒序排列。
 */
@property (nonatomic, strong) NSArray<CLXFDFaceListInfoModel *> *faceList;
@property (nonatomic, assign) BOOL faceOverMax;             //-> 人脸是否达到最大限制
@property (nonatomic, assign) BOOL faceMergeTimeMax;        //-> 人脸聚合次数是否已到最大限制

@end

@protocol CLXPersonFaceInfo <NSObject>

@property (nonatomic, copy) NSString *score;
@property (nonatomic, copy) NSString *imageUrl;
@property (nonatomic, copy) NSString *sex;
@property (nonatomic, copy) NSString *personId;
@property (nonatomic, copy) NSString *deviceId;
@property (nonatomic, copy) NSString *age;

@end

/**
 person相关数据信息
 */
@interface CLXPersonFaceInfo : NSObject<CLXPersonFaceInfo>

@end
