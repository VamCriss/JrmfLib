//
//  JrmfPaySDK.h
//  JrmfPayKit
//
//  Created by 一路财富 on 16/10/10.
//  Copyright © 2016年 JYang. All rights reserved.
//

#import <Foundation/Foundation.h>


/* 支付状态 */
typedef enum JrmfPayStatus {
    kJrmfStatCancel = 0,     // 取消支付，用户行为
    kJrmfStatSucess = 1,     // 支付成功
    kJrmfStatFail = 2,       // 支付异常
    kJrmfStatUnknow,         // 其他

}JrmfPayStatus;

/* 收款方类型 */
typedef enum JrmfPayTypeStatus {
    kJrmfPayTypeCustomer = 0,     // 个人
    kJrmfPayTypeBusiness = 1,     // 企业
    kJrmfPayTypeLittleBusiness = 2 // 小B用户
}JrmfPayTypeStatus;

/* 付款方类型 */
typedef NS_ENUM(NSUInteger, JrmfPayAccountTypeStatus) {
    kJrmfPayAccountTypeCustomer = 0,    // 个人
    kJrmfPayAccountTypeBusiness = 2     // 企业
};

@protocol JrmfPayDelegate <NSObject>

/**
 支付回调函数

 @param orderNo     支付订单
 @param stat        支付状态
 @param ordrDic     支付异常是参数数据   取消、成功为nil

 ordrDic 默认展示形式
 {
    respmsg = "该订单已支付成功";
    respstat = ER016;
 }
 */
- (void)doJrmfPaySuccessWithOrderNo:(NSString *)orderNo PayStat:(JrmfPayStatus)stat ErrorMsg:(NSDictionary *)ordrDic;

@end

@interface JrmfPaySDK : NSObject

@property (nonatomic, weak) id <JrmfPayDelegate> delegate;

/**
 *  页面'标题'颜色 支持@“#123456”、 @“0X123456”、 @“123456”三种格式
 */
@property (nonatomic, strong) NSString * titleColorRGB;

/**
 主题色 - Nav颜色
 */
@property (nonatomic, strong) NSString * themeNavColor;

/**
 主题色 - 按钮颜色
 */
@property (nonatomic, strong) NSString * themeBtnColor;


/**
 初始化函数--即将废弃
 
 @param partnerId   渠道ID
 @param scheme      支付宝scheme参数【保证格式的正确性】
 @param isOnline    是否正式环境。默认NO，测试环境
 */
+ (void)instanceJrmfPaySDKWithPartnerId:(NSString *)partnerId SchemeUrl:(NSString *)scheme appMothod:(BOOL)isOnline  __deprecated_msg("Use 'instanceJrmfPaySDKWithPartnerId:aliPaySchemeUrl:weChatSchemeUrl:appMothod' func.");

/**
 初始化函数

 @param partnerId 渠道ID
 @param aliPayschemeUrl 支付宝Scheme
 @param weChatSchemeUrl 微信Scheme
 @param isOnline 是否正式环境。默认NO，测试环境
 */
+ (void)instanceJrmfPaySDKWithPartnerId:(NSString *)partnerId
                        aliPaySchemeUrl:(NSString *)aliPayschemeUrl
                        weChatSchemeUrl:(NSString *)weChatSchemeUrl
                              appMothod:(BOOL)isOnline;

/**
 支付接口 - 下一个版本废弃
 
 @param amount      金额（单位为‘分’）
 @param productName 商品名称
 @param orderNumber 商品订单
 @param sendUserId  操作者ID【支付方】
 @param receiveUid  接收者ID【收款方】
 @param sign        Sign 签名
 @param receiveType 收款方类型 (支持类型在底部说明)
  */
- (void)doJrmfPayWithAmount:(int)amount
            WithProductName:(NSString *)productName
                OrderNumber:(NSString *)orderNumber
                 sendUserid:(NSString *)sendUserId
              receiveUserId:(NSString *)receiveUid
                       Sign:(NSString *)sign
         receiveAccountType:(JrmfPayTypeStatus)receiveType __deprecated_msg("Use 'doJrmfPayWithAmount:WithProductName:OrderNumber:sendUserid:receiveUserId:Sign:sendAccountType:receiveAccountType:isFreeze:divideDetail:divide:' func.");

/**
 支付接口 分账明细规则：
 如果只分给了渠道或者个人（包含小B）：渠道和个人（包含小B）不能低于一分钱
 如果渠道和个人都添加了：先分给渠道，剩下的钱分给个人（包含小B），也是不能低于一分钱
 
 @param amount       金额（单位为‘分’）
 @param productName  商品名称
 @param orderNumber  商品订单
 @param sendUserId   操作者ID【支付方】
 @param receiveUid   接收者ID【收款方】
 @param sign         Sign 签名
 @param sendType     付款方类型 (个人或者企业)
 @param receiveType  收款方类型 (个人, 企业, 小B)
 @param isFreeze     是否开启担保交易
 @param divideDetail 分账明细 用户/小B  格式1: custUid1:比例1|custUid2:比例2.. （所有比例和为1）
                                     格式2: custUid1:金额1|custUid2:金额2..   (金额总数为付款金额)
 @param divide      分账明细 渠道      格式:  金额
 */
- (void)doJrmfPayWithAmount:(int)amount
            WithProductName:(NSString *)productName
                OrderNumber:(NSString *)orderNumber
                 sendUserid:(NSString *)sendUserId
              receiveUserId:(NSString *)receiveUid
                       Sign:(NSString *)sign
            sendAccountType:(JrmfPayAccountTypeStatus)sendType
         receiveAccountType:(JrmfPayTypeStatus)receiveType
                   isFreeze:(BOOL)isFreeze
               divideDetail:(NSString *)divideDetail
                     divide:(NSString *)divide;

/**
 支付宝支付成功调用函数
 */
+ (void)doJrmfAlipayDone;

/**
 *  版本号
 *
 *  @return 获取当前版本
 */
+ (NSString *)getCurrentVersion;

@end
