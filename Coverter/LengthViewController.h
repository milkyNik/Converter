//
//  LengthViewController.h
//  Coverter
//
//  Created by iMac on 16.04.16.
//  Copyright © 2016 MilNik. All rights reserved.
//

#import <UIKit/UIKit.h>

#pragma mark - ConverterLengthProtocol
typedef enum {
    ConverterTypeLengthMM,            //мм
    ConverterTypeLengthCM,            //см
    ConverterTypeLengthDM,            //дм
    ConverterTypeLengthM,             //м
    ConverterTypeLengthKM,            //км
    ConverterTypeLengthInch,          //дюйм
    ConverterTypeLengthFoot,          //фут
    ConverterTypeLengthYard,          //ярд
    ConverterTypeLengthInchesMile     //миля
} ConverterTypeLength;

@protocol ConverterLengthProtocol <NSObject>

@property (assign, nonatomic) ConverterTypeLength typeLength_1; // Исходный тип.
@property (assign, nonatomic) ConverterTypeLength typeLength_2; // Тип, в который необходимо конвертировать.

// Возвращает строковое имя типа на русском.
- (NSString*) returnStringWithType:(ConverterTypeLength) type;

// Принимает число, тип этого числа и тип, в который нужно это число конвертировать. Возвращает конвертированное число.
- (double) convertValue:(double) value fromType:(ConverterTypeLength) type_1 inType:(ConverterTypeLength) type_2;

@end



@interface LengthViewController : UIViewController <UIPickerViewDelegate, UIPickerViewDataSource>

@property (weak, nonatomic) IBOutlet UILabel *valueLabel;
@property (weak, nonatomic) IBOutlet UILabel *convertValueLabel;
@property (strong, nonatomic) id <ConverterLengthProtocol> delegate;

@property (strong, nonatomic) IBOutletCollection(UIButton) NSArray *numberButton;


@end
