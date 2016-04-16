//
//  LengthViewController.h
//  Coverter
//
//  Created by iMac on 16.04.16.
//  Copyright © 2016 MilNik. All rights reserved.
//

#import <UIKit/UIKit.h>


#pragma mark - ConverterLengthProtocol

@protocol ConverterLengthProtocol <NSObject>

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

// Возвращает строковое имя типа на русском.
- (NSString*) returnStringWithType:(ConverterTypeLength) type;

// Принимает число, тип этого числа и тип, в который нужно это число конвертировать. Возвращает конвертированное число.
- (double) convertValue:(double) value fromType:(ConverterTypeLength) type_1 inType:(ConverterTypeLength) type_2;

@end



@interface LengthViewController : UIViewController <UIPickerViewDelegate, UIPickerViewDataSource>

@property (weak, nonatomic) IBOutlet UILabel *valueLabel;
@property (weak, nonatomic) IBOutlet UILabel *convertValueLabel;

@property (strong, nonatomic) IBOutletCollection(UIButton) NSArray *numberButton;

- (IBAction)actionNumberButton:(UIButton *)sender;
- (IBAction)actionAddFractionButton:(UIButton *)sender;
- (IBAction)actionAllClearButton:(UIButton *)sender;







@end
